![JCBDistortion Interface](Assets/screenshot.png)

Plugin distorsionador desarrollado en gen~, exportado con [gen~ Plugin Export](https://github.com/Cycling74/gen-plugin-export) y finalizado con el framework C++ [JUCE](https://github.com/juce-framework/JUCE). Este plugin forma parte de un conjunto de herramientas didácticas que utilizo en la asignatura de Técnicas de Grabación y Masterización para Música Electroacústica del [MCE](https://katarinagurska.com/curso-of/master-de-composicion-electroacustica-mce/). Originalmente creado con JUCE 6 hace unos años, el proyecto ha evolucionado significativamente en su interfaz gráfica y funcionalidad gracias al desarrollo con Claude Code durante junio de 2025. Para más detalles técnicos, consulta [NOTAS.md](NOTAS.md).

## Instalación macOS
1. Descarga el archivo DMG desde la página de [Releases](https://github.com/cjitter/JCBDistortion/releases)
2. Abre el DMG y ejecuta el instalador
3. El instalador colocará automáticamente los tipos de plugins seleccionados en las ubicaciones correctas del sistema:
   - VST3: `/Library/Audio/Plug-Ins/VST3/`
   - AU: `/Library/Audio/Plug-Ins/Components/`
   - AAX: `/Library/Application Support/Avid/Audio/Plug-Ins/`

*Nota: El DMG está firmado y notarizado para macOS.*

## Requisitos del sistema

- macOS 10.12 o posterior
- Procesador Intel o Apple Silicon
- DAW compatible con VST3, AU o AAX
- Probado en: Pro Tools, Reaper, Logic, Ableton Live y Bitwig

## Compilación desde código fuente

### Requisitos previos
- Git, [CMake](https://cmake.org) 3.20 o posterior, compilador Apple Clang compatible con C++20 (incluido en Xcode 13 o superior).
- [JUCE](https://github.com/juce-framework/JUCE) 8.0.8 (se descarga automáticamente via FetchContent)
- **AAX SDK**, solo requerido para compilar formato AAX - disponible desde cuenta de desarrollador Avid, etc.

### Instrucciones de compilación

1. Clona el repositorio:
```bash
git clone https://github.com/cjitter/JCBDistortion.git
cd JCBDistortion
```

2. **Configuración del proyecto**:
```bash
# Configurar proyecto Debug (VST3 y AU)
cmake -B build-debug -DCMAKE_BUILD_TYPE=Debug

# Configurar proyecto Release (VST3 y AU)
cmake -B build-release -DCMAKE_BUILD_TYPE=Release

# Configurar proyecto Debug/Release con AAX (requiere AAX SDK y Pro Tools Developer instalado)
cmake -B build-debug -DCMAKE_BUILD_TYPE=Debug -DJUCE_BUILD_AAX=ON
```

**Nota sobre generadores**: Por defecto, CMake usa Unix Makefiles en macOS. También puedes especificar otros generadores:
- **Ninja** (más rápido): `cmake -B build -G Ninja`
- **Xcode** (IDE nativo): `cmake -B build -G Xcode`

**Nota sobre AAX**: Si configuras con la opción AAX habilitada, cuando compiles el plugin se instalará automáticamente en `/Applications/Pro Tools Developer/Plug-Ins/` para testing con Pro Tools Developer.

3. **Compilación**:
```bash
# Compilar el proyecto configurado
cmake --build build-debug    # Para Debug
cmake --build build-release   # Para Release
```

## Características principales

	•	Distorsionador multimodal con 8 algoritmos seleccionables (MODE 0–7): Soft Clipping, Sigmoid, Full/Half Wave Rectifier, Fuzz Exponential, Hyperbolic Tangent, Arctangent, Hard Clip.
	•	Control de ganancia de entrada (DRIVE) de 1 a 50× para modular la intensidad de distorsión.
	•	Control de asimetría (EVEN) ahora basado en skew dependiente de polaridad (no inyección directa de DC), para armónicos pares más musicales y sin picos DC.
	•	Ruta Tilt conmutables Pre/Post la distorsión y morph continuo entre ambas (p_TILTPOS): ajusta el carácter antes o después de saturar.
	•	Crossover LR4 de 3 bandas (Linkwitz–Riley 4º orden) con puntos de cruce ajustables (XLow 20–1000 Hz, XHigh 1–20 kHz).
	•	Compensación de fase en el dry mediante all-pass equivalentes al LR4, manteniendo coherencia cuando el crossover está activo/inactivo.
	•	Selector de banda (BAND) con pesos continuos y Solo de banda que deja escuchar esa banda a través del procesador (wet), manteniendo el dry full-range.
	•	Filtro Tilt ±6 dB (RBJ shelves complementarios con normalización en pivote) para balance espectral.
	•	Bit Crusher mejorado (3–16 bits) con:
	•	cuantización por round (no ceil) para menos sesgo,
	•	dcblock post-quantización y mezcla conmutada (BITSON).
	•	Downsampler/Decimador con phasor y latch por flanco, reinicio limpio al activar y decimación 1…100 (sin zipper noise).
	•	Control de techo (CEILING) de −20 a +6 dB y limitador de seguridad opcional con ceiling fijo −0.1 dB para prevenir overs.
	•	Trim de salida ±12 dB y Control Dry/Wet 0–100 % (mezcla paralela post-procesado).
	•	Smoothing de parámetros crítico (incl. MODE) y fixdenorm en todos los biquads para estabilidad numérica.
	•	Bypass verdadero con botón dedicado.
	•	Analizador FFT 2048-pt con líneas de crossover arrastrables (FFT/CURVES).
	•	Visualizador de curvas de distorsión en tiempo real.
	•	Medidores In/Out con RMS/Peak.
	•	Procesamiento estéreo con parámetros unificados.
	•	Tooltips bilingües (ES/EN) conmutables.
	•	Diagrama de bloques interactivo con acceso a GenExpr para estudio en Max.

## Cambios recientes v0.9.2

	•	EVEN refinado: asimetría por pendiente (skew) con normalización y tanh-shaping → armónicos pares más “finos” y controlables, sin golpes DC incluso a altos drives.
	•	Ruta Pre/Post Tilt con morph: mismo juego de coeficientes y normalización al pivote para que Pre y Post se combinen sin saltos.
	•	Dry all-pass compensation: el dry recorre dos etapas all-pass (loF/hiF) que replican el group delay del LR4; suma en fase y pasa el null test.
	•	Bit Crusher: cuantización por round, dcblock a la salida y mezcla conmutada → crush agresivo pero sin artefactos ni “choking”.
	•	Downsampling: latch por flanco con reset al activar y fase estable; sin “rate zipper” al mover el parámetro.
	•	Modularización real del pipeline: InputStage → CrossoverStage → DistortionCore → EffectsChain → OutputStage; cada módulo es intercambiable y fácil de depurar.
	•	Gestión de banda: Band Solo encaminado por el core (solo la banda seleccionada en wet, dry full-range), más útil para diseño de sonido y A/B.
	•	Robustez numérica: fixdenorm() en todos los estados de biquads y smoothing afinado (incl. MODE con factor específico) para evitar clicks/zipper.

![Diagrama de Bloques](Assets/screenshotDiagram.png)

## Recursos

### Bibliografía técnica
- [Graham Wakefield & Gregory Taylor - *Generating Sound and Organizing Time*](https://cycling74.com/books/go)
- [Will C. Pirkle - *Designing Audio Effect Plugins in C++*](https://www.willpirkle.com)
- [Matthijs Hollemans - *The Complete Beginner's Guide to Audio Plug-in Development*](https://www.theaudioprogrammer.com/books/beginners-plugin-book)

## Testing con pluginval

Este proyecto incluye tests automáticos con [pluginval](https://github.com/Tracktion/pluginval) para validar el plugin.

### Configuración

- **Detección automática**: Si tienes pluginval instalado, CMake lo detectará automáticamente
- **Descarga automática**: Si no está instalado, se descargará automáticamente en la carpeta `tools/`
- Para desactivar la descarga automática:
  ```bash
  cmake -B build -DPLUGINVAL_AUTO_DOWNLOAD=OFF
  ```

### Ejecutar los tests

```bash
# Entra al directorio de build (el mismo nombre que usaste después de -B al configurar)
# Por ejemplo: si usaste "cmake -B build", entonces:
cd build

# Ejecutar todos los tests de pluginval con salida detallada
# Usa -C Release o -C Debug según cómo compilaste el plugin
# Nota: Los tests completos pueden tardar varios minutos
ctest -C Release -R pluginval -V
```

Los tests validan los formatos VST3 y AU del plugin.

## Por hacer

- Añadir oversampling opcional para evitar aliasing en modos extremos.
- Crear versión simplificada para Max for Live.
- Portar el modelo a SuperCollider como UGen personalizado.

---

*© 2025 Juan Carlos Blancas – JCBDistortion v0.9.2 beta*

