#include "DistortionCurveComponent.h"

DistortionCurveComponent::DistortionCurveComponent(juce::AudioProcessorValueTreeState& apvts)
    : valueTreeState(apvts)
{
    // Registrarse como listener de los parámetros
    valueTreeState.addParameterListener("d_MODE", this);
    valueTreeState.addParameterListener("b_DRIVE", this);
    valueTreeState.addParameterListener("c_DC", this);
    valueTreeState.addParameterListener("e_CEILING", this);
    valueTreeState.addParameterListener("i_TILT", this);
    
    // Obtener valores iniciales
    updateFromParameters();
}

DistortionCurveComponent::~DistortionCurveComponent()
{
    valueTreeState.removeParameterListener("d_MODE", this);
    valueTreeState.removeParameterListener("b_DRIVE", this);
    valueTreeState.removeParameterListener("c_DC", this);
    valueTreeState.removeParameterListener("e_CEILING", this);
    valueTreeState.removeParameterListener("i_TILT", this);
}

void DistortionCurveComponent::parameterChanged(const juce::String& parameterID, float newValue)
{
    if (parameterID == "d_MODE")
        currentMode = newValue;
    else if (parameterID == "b_DRIVE")
        currentDrive = newValue;
    else if (parameterID == "c_DC")
        currentDC = newValue;
    else if (parameterID == "e_CEILING")
        currentCeiling = juce::Decibels::decibelsToGain(newValue);
    else if (parameterID == "i_TILT")
        currentTilt = newValue;
    
    repaint();
}

void DistortionCurveComponent::updateFromParameters()
{
    if (auto* param = valueTreeState.getRawParameterValue("d_MODE"))
        currentMode = param->load();
    if (auto* param = valueTreeState.getRawParameterValue("b_DRIVE"))
        currentDrive = param->load();
    if (auto* param = valueTreeState.getRawParameterValue("c_DC"))
        currentDC = param->load();
    if (auto* param = valueTreeState.getRawParameterValue("e_CEILING"))
        currentCeiling = juce::Decibels::decibelsToGain(param->load());
    if (auto* param = valueTreeState.getRawParameterValue("i_TILT"))
        currentTilt = param->load();
}

void DistortionCurveComponent::paint(juce::Graphics& g)
{
    auto bounds = getLocalBounds().toFloat();
    
    // Calcular color de fondo basado en TILT
    juce::Colour backgroundColour = juce::Colour(0xff1a1a1a); // Negro base
    
    if (std::abs(currentTilt) > 0.1f) // Solo aplicar efecto si TILT es significativo
    {
        if (currentTilt < 0.0f) // Graves - rojizo
        {
            float intensity = juce::jlimit(0.0f, 1.0f, std::abs(currentTilt) / 6.0f); // Normalizar -6dB a 1.0
            juce::Colour redTint = juce::Colour(0xff4a1a1a); // Rojo oscuro
            backgroundColour = backgroundColour.interpolatedWith(redTint, intensity * 0.3f);
        }
        else // Agudos - violeta
        {
            float intensity = juce::jlimit(0.0f, 1.0f, currentTilt / 6.0f); // Normalizar +6dB a 1.0
            juce::Colour purpleTint = juce::Colour(0xff2a1a4a); // Violeta oscuro
            backgroundColour = backgroundColour.interpolatedWith(purpleTint, intensity * 0.3f);
        }
    }
    
    g.fillAll(backgroundColour);
    
    // Área de dibujo (simétrica, sin reservar espacio para título)
    bounds.reduce(10, 10);
    
    // Dibujar grilla
    drawGrid(g, bounds);
    
    // Dibujar línea de referencia (y = x)
    g.setColour(juce::Colours::grey.withAlpha(0.5f));
    g.drawLine(bounds.getX(), bounds.getBottom(),
               bounds.getRight(), bounds.getY(), 1.0f);
    
    // Dibujar curva
    drawDistortionCurve(g, bounds);
    
    // Dibujar nombre del modo en esquina superior izquierda
    g.setColour(juce::Colours::white.withAlpha(0.9f));
    g.setFont(16.0f);
    auto textBounds = getLocalBounds().toFloat();
    auto textArea = textBounds.removeFromTop(25).removeFromLeft(200);
    g.drawText(getModeName(), textArea, juce::Justification::centredLeft);
}

void DistortionCurveComponent::drawGrid(juce::Graphics& g, juce::Rectangle<float> bounds)
{
    g.setColour(juce::Colours::grey.withAlpha(0.2f));
    
    // Líneas verticales
    for (int i = 1; i < 4; ++i)
    {
        float x = bounds.getX() + (bounds.getWidth() / 4.0f) * i;
        g.drawLine(x, bounds.getY(), x, bounds.getBottom(), 0.5f);
    }
    
    // Líneas horizontales
    for (int i = 1; i < 4; ++i)
    {
        float y = bounds.getY() + (bounds.getHeight() / 4.0f) * i;
        g.drawLine(bounds.getX(), y, bounds.getRight(), y, 0.5f);
    }
    
    // Ejes principales
    g.setColour(juce::Colours::grey.withAlpha(0.5f));
    float centerX = bounds.getCentreX();
    float centerY = bounds.getCentreY();
    
    g.drawLine(bounds.getX(), centerY, bounds.getRight(), centerY, 1.0f);
    g.drawLine(centerX, bounds.getY(), centerX, bounds.getBottom(), 1.0f);
}

void DistortionCurveComponent::drawDistortionCurve(juce::Graphics& g, juce::Rectangle<float> bounds)
{
    juce::Path curve;
    const int numPoints = 256;
    
    for (int i = 0; i <= numPoints; ++i)
    {
        float x = (float)i / (float)numPoints;
        float inputValue = (x * 2.0f) - 1.0f; // -1 a 1
        float outputValue = processDistortion(inputValue);
        
        // Mapear a coordenadas de pantalla
        float screenX = bounds.getX() + x * bounds.getWidth();
        float screenY = bounds.getBottom() - ((outputValue + 1.0f) * 0.5f * bounds.getHeight());
        
        if (i == 0)
            curve.startNewSubPath(screenX, screenY);
        else
            curve.lineTo(screenX, screenY);
    }
    
    g.setColour(getColorForMode());
    g.strokePath(curve, juce::PathStrokeType(2.0f));
}

float DistortionCurveComponent::processDistortion(float input)
{
    int mode = (int)std::floor(currentMode);
    float morph = currentMode - mode;
    
    // Procesar modo actual
    float output1 = 0.0f;
    switch (mode)
    {
        case 0: output1 = softClip(input); break;
        case 1: output1 = sigmoid(input); break;
        case 2: output1 = rectFull(input); break;
        case 3: output1 = fuzzExp(input); break;
        case 4: output1 = tanhDist(input); break;
        case 5: output1 = rectHalf(input); break;
        case 6: output1 = arctanDist(input); break;
        case 7: output1 = hardClip(input); break;
    }
    
    // Si hay morphing, procesar siguiente modo
    if (morph > 0.001f)
    {
        float output2 = 0.0f;
        int nextMode = (mode + 1) % 8;
        
        switch (nextMode)
        {
            case 0: output2 = softClip(input); break;
            case 1: output2 = sigmoid(input); break;
            case 2: output2 = rectFull(input); break;
            case 3: output2 = fuzzExp(input); break;
            case 4: output2 = tanhDist(input); break;
            case 5: output2 = rectHalf(input); break;
            case 6: output2 = arctanDist(input); break;
            case 7: output2 = hardClip(input); break;
        }
        
        return output1 * (1.0f - morph) + output2 * morph;
    }
    
    return output1;
}

// Implementación de algoritmos de distorsión
float DistortionCurveComponent::softClip(float input)
{
    float driveFactor = currentDrive + currentDC * 0.9f;
    float xNorm = (input * driveFactor) / currentCeiling;
    float cubic = xNorm - (xNorm * xNorm * xNorm) / 3.0f;
    float limited = (xNorm > 0 ? 1.0f : -1.0f) * (2.0f / 3.0f);
    float result = (std::abs(xNorm) <= 1.0f) ? cubic : limited;
    return result * currentCeiling;
}

float DistortionCurveComponent::sigmoid(float input)
{
    float dcFactor = currentDC * currentDrive * 0.9f;
    float factor = -(currentDrive + dcFactor);
    float y = 2.0f * (1.0f / (1.0f + std::exp(factor * input))) - 1.0f;
    return juce::jlimit(-currentCeiling, currentCeiling, y * currentCeiling);
}

float DistortionCurveComponent::rectFull(float input)
{
    float y = (input >= 0 ? 1.0f : -1.0f) * std::abs(input * currentDrive) * 0.707f;
    return juce::jlimit(-currentCeiling, currentCeiling, y);
}

float DistortionCurveComponent::fuzzExp(float input)
{
    float dcFactor = currentDC * currentDrive * 0.9f;
    float xScaled = std::abs(input * currentDrive + dcFactor * 0.01f);
    float y = (input >= 0 ? 1.0f : -1.0f) * (1.0f - std::exp(-xScaled));
    return juce::jlimit(-currentCeiling, currentCeiling, y);
}

float DistortionCurveComponent::tanhDist(float input)
{
    float dcFactor = currentDC * currentDrive * 0.9f;
    float xScaled = juce::jlimit(-currentCeiling, currentCeiling, 
                                 (input * currentDrive) + (dcFactor * 0.01f));
    return std::tanh(xScaled) / std::tanh(currentDrive);
}

float DistortionCurveComponent::rectHalf(float input)
{
    float xPositive = std::max(input, 0.0f);
    float y = (xPositive * currentDrive) * 0.5f;
    return juce::jlimit(-currentCeiling, currentCeiling, y);
}

float DistortionCurveComponent::arctanDist(float input)
{
    float dcFactor = currentDC * currentDrive * 0.9f;
    float xScaled = (input * currentDrive + dcFactor * 0.01f) * 2.0f;
    return (2.0f / juce::MathConstants<float>::pi) * std::atan(xScaled) * currentCeiling;
}

float DistortionCurveComponent::hardClip(float input)
{
    float threshold = currentCeiling / currentDrive;
    float dcReduced = currentDC * 0.01f;
    float xOffset = input + dcReduced;
    
    if (xOffset > threshold) return threshold;
    if (xOffset < -threshold) return -threshold;
    return xOffset;
}

juce::Colour DistortionCurveComponent::getColorForMode()
{
    int mode = (int)std::floor(currentMode);
    
    switch (mode)
    {
        case 0: return juce::Colours::cyan;
        case 1: return juce::Colours::magenta;
        case 2: return juce::Colours::yellow;
        case 3: return juce::Colours::orange;
        case 4: return juce::Colours::lightgreen;
        case 5: return juce::Colours::red;
        case 6: return juce::Colours::mediumpurple;
        case 7: return juce::Colours::white;
        default: return juce::Colours::grey;
    }
}

juce::String DistortionCurveComponent::getModeName()
{
    int mode = (int)std::floor(currentMode);
    
    switch (mode)
    {
        case 0: return "Soft Clipping";
        case 1: return "Sigmoid";
        case 2: return "Rectifier Full Wave";
        case 3: return "Fuzz Exponential";
        case 4: return "Hyperbolic Tangent";
        case 5: return "Rectifier Half Wave";
        case 6: return "Arctangent";
        case 7: return "Hard Clip";
        default: return "Unknown";
    }
}