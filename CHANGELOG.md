# Changelog

Todas las versiones de este proyecto siguen [Semantic Versioning](https://semver.org/).

## [1.0.1] - 2025-11-22
### Added
- Caché de parámetros Gen y helpers APVTS ↔ Gen para sincronización segura (rebuildGenParameterLookup, enqueueAllParametersForAudioThread, pushGenParamByName).

### Changed
- Restauración de estado ahora reencola todos los parámetros vía enqueueAllParametersForAudioThread() en lugar de iteraciones manuales.
- La carga de presets sincroniza con Gen a través de pushGenParamByName (sin accesos directos al estado Gen).
- Sin cambios en sonido, presets o interfaz; actualización centrada en estabilidad de estado/presets.

### Removed
- Código heredado de otros plugins (clamps ATK/REL) que no pertenecía a JCBDistortion.
- Referencias a parámetros no usados (ATK/REL, y_SCTRIM) eliminadas del código.

## 1.0.0
- Versión inicial.
