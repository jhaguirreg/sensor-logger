# Reflexión sobre la interacción con la IA

Durante el desarrollo del proyecto *sensor-logger* en C, mi interacción con la IA se centró en planificación, codificación, depuración y documentación. Realicé preguntas iterativas para aclarar aspectos conceptuales y prácticos del desarrollo y la integración del sistema.

## Qué pregunté

Comencé solicitando un mapa de cómo abordar el proyecto, incluyendo la secuencia de tareas y la configuración inicial. A medida que avanzaba, pregunté sobre el uso de Git, modularización del código, errores de compilación y linker, diferencias entre importar archivos `.c` y `.h`, manejo de argumentos para variar intervalos de lectura, pruebas unitarias, manejo de señales para cierre correcto, gestión de archivos de log, declaración de servicios, recomendaciones de Makefile y ejecución en WSL. Cada consulta respondía a un obstáculo o incertidumbre específica.

## Por qué iteré

Iteré porque cada solución generaba nuevas preguntas. Por ejemplo, después de resolver la diferencia entre headers y fuentes, surgió la necesidad de manejar argumentos y logs correctamente. Tras implementar la gestión de señales, surgió la pregunta sobre cómo cerrar procesos con `kill`. Las explicaciones de la IA frecuentemente requerían aclaraciones o adaptaciones, generando un ciclo de prueba, ajuste y validación.

## Qué acepté o rechacé

Acepté las explicaciones estructuradas de la IA sobre modularización, compilación y manejo de señales, así como las recomendaciones sobre parsing de argumentos y gestión de logs. Rechacé o modifiqué indicaciones cuando no se adaptaban a mi entorno, como el uso de servicios `systemd` en WSL, y ajusté sugerencias genéricas a la estructura de carpetas y convenciones de mi proyecto.

## Cómo validé los resultados

Validé las respuestas compilando el código, ejecutando el programa con distintos argumentos y verificando los logs. Se utilizaron pruebas unitarias para confirmar el comportamiento del módulo de sensores y del `main`. Los archivos de servicio y reglas del Makefile se probaron incrementalmente, corrigiendo errores según los mensajes del compilador y documentación oficial.

## Qué cambié manualmente

Modifiqué rutas de archivos en los comandos de compilación, ajusté los manejadores de señales para múltiples señales de terminación, adaptando operaciones de logs y ajustando el Makefile a mi estructura de carpetas. También adapté el contenido del archivo de servicio para entornos sin `systemd`. La IA proporcionó la guía conceptual, mientras que la implementación exacta se realizó manualmente según el contexto del proyecto.

---

En resumen, la IA funcionó como tutor y asistente de depuración. Usé su guía de manera iterativa para planear, codificar y probar el sistema *sensor-logger*, validando cada paso y adaptando los resultados a mi entorno, fortaleciendo así mi comprensión de programación modular en C, compilación y linking, gestión de procesos y documentación.# Reflexión sobre la interacción con la IA

Durante el desarrollo del proyecto *sensor-logger* en C, mi interacción con la IA se centró en planificación, codificación, depuración y documentación. Realicé preguntas iterativas para aclarar aspectos conceptuales y prácticos del desarrollo y la integración del sistema.

## Qué pregunté

Comencé solicitando un mapa de cómo abordar el proyecto, incluyendo la secuencia de tareas y la configuración inicial. A medida que avanzaba, pregunté sobre el uso de Git, modularización del código, errores de compilación y linker, diferencias entre importar archivos `.c` y `.h`, manejo de argumentos para variar intervalos de lectura, pruebas unitarias, manejo de señales para cierre correcto, gestión de archivos de log, declaración de servicios, recomendaciones de Makefile y ejecución en WSL. Cada consulta respondía a un obstáculo o incertidumbre específica.

## Por qué iteré

Iteré porque cada solución generaba nuevas preguntas. Por ejemplo, después de resolver la diferencia entre headers y fuentes, surgió la necesidad de manejar argumentos y logs correctamente. Tras implementar la gestión de señales, surgió la pregunta sobre cómo cerrar procesos con `kill`. Las explicaciones de la IA frecuentemente requerían aclaraciones o adaptaciones, generando un ciclo de prueba, ajuste y validación.

## Qué acepté o rechacé

Acepté las explicaciones estructuradas de la IA sobre modularización, compilación y manejo de señales, así como las recomendaciones sobre parsing de argumentos y gestión de logs. Rechacé o modifiqué indicaciones cuando no se adaptaban a mi entorno, como el uso de servicios `systemd` en WSL, y ajusté sugerencias genéricas a la estructura de carpetas y convenciones de mi proyecto.

## Cómo validé los resultados

Validé las respuestas compilando el código, ejecutando el programa con distintos argumentos y verificando los logs. Se utilizaron pruebas unitarias para confirmar el comportamiento del módulo de sensores y del `main`. Los archivos de servicio y reglas del Makefile se probaron incrementalmente, corrigiendo errores según los mensajes del compilador y documentación oficial.

## Qué cambié manualmente

Modifiqué rutas de archivos en los comandos de compilación, ajusté los manejadores de señales para múltiples señales de terminación, adaptando operaciones de logs y ajustando el Makefile a mi estructura de carpetas. También adapté el contenido del archivo de servicio para entornos sin `systemd`. La IA proporcionó la guía conceptual, mientras que la implementación exacta se realizó manualmente según el contexto del proyecto.

---

En resumen, la IA funcionó como tutor y asistente de depuración. Usé su guía de manera iterativa para planear, codificar y probar el sistema *sensor-logger*, validando cada paso y adaptando los resultados a mi entorno, fortaleciendo así mi comprensión de programación modular en C, compilación y linking, gestión de procesos y documentación.
