# Registro de interacción con la IA: Desarrollo de sensor-logger en C

Este documento resume la interacción con la IA durante el desarrollo de un proyecto de simulación de sensor en C, incluyendo la creación de la estructura de proyecto, compilación, tests, manejo de señales, logs y servicios.

---

## 1. Planificación inicial

Se solicitó a la IA un mapa de cómo abordar el proyecto y en qué orden realizar las tareas. La recomendación fue:

1. Crear el repositorio Git.
2. Desarrollar el código fuente (`src`) del sensor y un `main` para la ejecución.
3. Crear tests unitarios para cada módulo.
4. Formalizar el servicio con un archivo `.service`.
5. Preparar el `Makefile`.
6. Documentar el proyecto.

---

## 2. Problemas iniciales con Git

- **Error de conexión a Git:** Se proporcionó explicación de cómo usar Git desde la terminal.
- **Advertencia sobre rama `master`:** La IA explicó que versiones recientes usan `main` como rama inicial por defecto y dio tres opciones:
  1. Cambiar globalmente el nombre por defecto:
     ```bash
     git config --global init.defaultBranch main
     ```
  2. Cambiar solo en el repo actual:
     ```bash
     git branch -m main
     ```
  3. Dejar la rama como `master`.

---

## 3. Modularización del código

Se discutieron las ventajas de modularizar el código:

- Mejora el **orden** y la **legibilidad**.
- Facilita **tests unitarios**.
- Permite **reutilizar código**.

Se aclaró la diferencia entre `.h` y `.c`:

| Archivo | Contenido | Función |
|---------|-----------|---------|
| `.h`    | Declaraciones de funciones, structs, macros | Permite al compilador saber qué funciones existen |
| `.c`    | Implementaciones de funciones | Contiene el código real que el linker necesita |

**Importante:** al compilar, siempre se debe incluir tanto el `main.c` como los `.c` de los módulos usados, por ejemplo:

```bash
gcc -Wall -Wextra -std=c11 -o main src/main.c src/sensor/sensor.c
```

4. Manejo de errores de compilación
Error típico: undefined reference durante el linkeo.

Causa: el compilador encuentra el header pero no la implementación.

Solución: incluir el .c correspondiente al módulo durante la compilación.

5. Parámetros de ejecución
Permitir variar el tiempo entre lecturas del sensor usando argumentos de línea de comandos:

```c
for (int i = 1; i < argc; i++) {
    if (strcmp(argv[i], "--interval") == 0 && i + 1 < argc) {
        interval = atoi(argv[++i]);
    } else if (strcmp(argv[i], "--logfile") == 0 && i + 1 < argc) {
        logfile = argv[++i];
    }
}
```
6. Tests
Se proporcionaron ejemplos de tests para:

El módulo sensor.

El main del programa.

Se indicó la ubicación correcta de los tests dentro de la estructura de carpetas del proyecto.

7. Manejo de señales y cierre del programa
Para permitir que el programa se cierre correctamente con Ctrl+C y otras señales:

```c
// Registrar varias señales que pueden "cerrar" el programa
signal(SIGINT, handle_sigterm);   // Ctrl+C
signal(SIGTERM, handle_sigterm);  // kill PID
signal(SIGQUIT, handle_sigterm);  // Ctrl+\
signal(SIGHUP, handle_sigterm);   // cierre de terminal
Se explicó cómo acceder a subprocesos, finalizarlos y leer alertas desde el código.
```

8. Manejo de logs
Se discutió cómo borrar o vaciar el archivo de log /tmp/assignment_sensor.log:

Vaciar contenido sin borrar el archivo:

```bash
> /tmp/assignment_sensor.log
```
Eliminar el archivo completo:

```bash
rm /tmp/assignment_sensor.log
```
Verificar estado del archivo:

```bash
ls -lh /tmp/assignment_sensor.log
cat /tmp/assignment_sensor.log
```
9. Archivos de servicio
Se pidió orientación sobre cómo declarar el archivo .service. Ejemplo básico de sensor-logger.service:

```ini
[Unit]
Description=Mock sensor logger service
After=network.target

[Service]
ExecStart=/usr/local/bin/sensor-logger --interval 5 --logfile /tmp/assignment_sensor.log
Restart=always

[Install]
WantedBy=multi-user.target
```

10. Makefile
Se discutieron recomendaciones para estructurar el Makefile:

- Separar compilación de tests y main.

- Incluir reglas de limpieza (clean) y compilación (all).

- Usar variables para binarios y rutas.

11. WSL y servicios
Problema: WSL no permite definir servicios systemd de forma nativa.

Solución: usar scripts de inicio alternativos, ejecutar manualmente o habilitar systemd en WSL2 con configuraciones recientes.

12. Ejecución en carpetas diversas
Discusión sobre cómo ejecutar códigos en diferentes carpetas y la implicación del uso de & al correr procesos en segundo plano.

13. Borrado de archivos .c
Problema: borrar accidentalmente un .c.

Recomendación: siempre mantener respaldo y usar Git para recuperar versiones.

14. Esquema de la documentación final (README.md)
Se sugirió incluir:

- Objetivo del proyecto.

- Estructura de carpetas.

- Instrucciones de compilación y ejecución.

- Parámetros de ejecución y logs.

- Tests unitarios y cómo correrlos.

- Manejo de señales y cierre del programa.

- Servicios (.service) y Makefile.

- Notas sobre WSL y compatibilidad.

- Errores comunes y soluciones.

Este registro refleja paso a paso la interacción con la IA, mostrando cómo se resolvieron dudas de compilación, modularización, tests, manejo de argumentos, señales, logs y servicios.# Registro de interacción con la IA: Desarrollo de sensor-logger en C

Este documento resume la interacción con la IA durante el desarrollo de un proyecto de simulación de sensor en C, incluyendo la creación de la estructura de proyecto, compilación, tests, manejo de señales, logs y servicios.

---

## 1. Planificación inicial

Se solicitó a la IA un mapa de cómo abordar el proyecto y en qué orden realizar las tareas. La recomendación fue:

1. Crear el repositorio Git.
2. Desarrollar el código fuente (`src`) del sensor y un `main` para la ejecución.
3. Crear tests unitarios para cada módulo.
4. Formalizar el servicio con un archivo `.service`.
5. Preparar el `Makefile`.
6. Documentar el proyecto.

---

## 2. Problemas iniciales con Git

- **Error de conexión a Git:** Se proporcionó explicación de cómo usar Git desde la terminal.
- **Advertencia sobre rama `master`:** La IA explicó que versiones recientes usan `main` como rama inicial por defecto y dio tres opciones:
  1. Cambiar globalmente el nombre por defecto:
     ```bash
     git config --global init.defaultBranch main
     ```
  2. Cambiar solo en el repo actual:
     ```bash
     git branch -m main
     ```
  3. Dejar la rama como `master`.

---

## 3. Modularización del código

Se discutieron las ventajas de modularizar el código:

- Mejora el **orden** y la **legibilidad**.
- Facilita **tests unitarios**.
- Permite **reutilizar código**.

Se aclaró la diferencia entre `.h` y `.c`:

| Archivo | Contenido | Función |
|---------|-----------|---------|
| `.h`    | Declaraciones de funciones, structs, macros | Permite al compilador saber qué funciones existen |
| `.c`    | Implementaciones de funciones | Contiene el código real que el linker necesita |

**Importante:** al compilar, siempre se debe incluir tanto el `main.c` como los `.c` de los módulos usados, por ejemplo:

```bash
gcc -Wall -Wextra -std=c11 -o main src/main.c src/sensor/sensor.c
```

4. Manejo de errores de compilación
Error típico: undefined reference durante el linkeo.

Causa: el compilador encuentra el header pero no la implementación.

Solución: incluir el .c correspondiente al módulo durante la compilación.

5. Parámetros de ejecución
Permitir variar el tiempo entre lecturas del sensor usando argumentos de línea de comandos:

```c
for (int i = 1; i < argc; i++) {
    if (strcmp(argv[i], "--interval") == 0 && i + 1 < argc) {
        interval = atoi(argv[++i]);
    } else if (strcmp(argv[i], "--logfile") == 0 && i + 1 < argc) {
        logfile = argv[++i];
    }
}
```
6. Tests
Se proporcionaron ejemplos de tests para:

El módulo sensor.

El main del programa.

Se indicó la ubicación correcta de los tests dentro de la estructura de carpetas del proyecto.

7. Manejo de señales y cierre del programa
Para permitir que el programa se cierre correctamente con Ctrl+C y otras señales:

```c
// Registrar varias señales que pueden "cerrar" el programa
signal(SIGINT, handle_sigterm);   // Ctrl+C
signal(SIGTERM, handle_sigterm);  // kill PID
signal(SIGQUIT, handle_sigterm);  // Ctrl+\
signal(SIGHUP, handle_sigterm);   // cierre de terminal
Se explicó cómo acceder a subprocesos, finalizarlos y leer alertas desde el código.
```

8. Manejo de logs
Se discutió cómo borrar o vaciar el archivo de log /tmp/assignment_sensor.log:

Vaciar contenido sin borrar el archivo:

```bash
> /tmp/assignment_sensor.log
```
Eliminar el archivo completo:

```bash
rm /tmp/assignment_sensor.log
```
Verificar estado del archivo:

```bash
ls -lh /tmp/assignment_sensor.log
cat /tmp/assignment_sensor.log
```
9. Archivos de servicio
Se pidió orientación sobre cómo declarar el archivo .service. Ejemplo básico de sensor-logger.service:

```ini
[Unit]
Description=Mock sensor logger service
After=network.target

[Service]
ExecStart=/usr/local/bin/sensor-logger --interval 5 --logfile /tmp/assignment_sensor.log
Restart=always

[Install]
WantedBy=multi-user.target
```

10. Makefile
Se discutieron recomendaciones para estructurar el Makefile:

- Separar compilación de tests y main.

- Incluir reglas de limpieza (clean) y compilación (all).

- Usar variables para binarios y rutas.

11. WSL y servicios
Problema: WSL no permite definir servicios systemd de forma nativa.

Solución: usar scripts de inicio alternativos, ejecutar manualmente o habilitar systemd en WSL2 con configuraciones recientes.

12. Ejecución en carpetas diversas
Discusión sobre cómo ejecutar códigos en diferentes carpetas y la implicación del uso de & al correr procesos en segundo plano.

13. Borrado de archivos .c
Problema: borrar accidentalmente un .c.

Recomendación: siempre mantener respaldo y usar Git para recuperar versiones.

14. Esquema de la documentación final (README.md)
Se sugirió incluir:

- Objetivo del proyecto.

- Estructura de carpetas.

- Instrucciones de compilación y ejecución.

- Parámetros de ejecución y logs.

- Tests unitarios y cómo correrlos.

- Manejo de señales y cierre del programa.

- Servicios (.service) y Makefile.

- Notas sobre WSL y compatibilidad.

- Errores comunes y soluciones.

Este registro refleja paso a paso la interacción con la IA, mostrando cómo se resolvieron dudas de compilación, modularización, tests, manejo de argumentos, señales, logs y servicios.
