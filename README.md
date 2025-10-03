# Mock Sensor Logger Service

Este proyecto implementa un **servicio systemd** que registra periódicamente un sensor simulado en un archivo de log.  

El programa está escrito en **C** y corre como un daemon, mostrando un **timestamp ISO-8601 | valor simulado**.

---

## Clonar y Build

### Prerrequisitos
- Compilador C compatible con **C11** (`gcc`).  
- Linux con **systemd** instalado (versión 220+ recomendada).  

### Comandos
```bash
git clone <repo-url>
cd <repo-name>
make all
```

### Artifacto generado
Binario compilado: ./build/sensor-logger

## Install & Enable

### Instalar binario y unidad systemd
```bash
make install
```

Esto hace:

- Copia binario a: /usr/local/bin/sensor-logger

- Copia unidad systemd a: /etc/systemd/system/sensor-logger.service

- Recarga systemd: sudo systemctl daemon-reload

- Habilita y arranca servicio: sudo systemctl enable --now sensor-logger.service

## Configuration
### El servicio se puede configurar mediante flags de CLI:

Flag        Descripción             Valor por defecto
--interval  Intervalo de muestreo en segundos   5

Ejemplo:

```bash
/usr/local/bin/sensor-logger --interval 10
```

Si /tmp no es escribible, se puede usar /var/tmp como fallback.

## Testing

### Ver estado del servicio

```bash
sudo systemctl status sensor-logger.service
```

### Revisar logs

```bash
tail -f /tmp/sensor-logger.log
```

Ejemplo de línea de log:


2025-10-02T17:34:21Z | 42

### Fallback demo
- Cambia permisos de /tmp para que no sea escribible:

```bash
sudo chmod 500 /tmp
sudo systemctl restart sensor-logger.service
```

El log debería aparecer en /var/tmp/sensor-logger.log (o la ruta configurada).

### Shutdown Graceful

```bash
sudo systemctl stop sensor-logger.service
```

El programa recibe SIGTERM o cualquier otra instrucción de cierre y cierra correctamente, asegurando que el log quede guardado.

## Uninstall

```bash
make uninstall
```

Esto hace:

- Detiene y deshabilita el servicio.

- Borra binario y archivo de unidad.

- Recarga systemd.

## Limpiar

```bash
make clean
```

Esto elimina los objetos compilados de /build.

## Notas

- El "sensor" está simulado usando la función rand() de C, inicializada con srand(time(NULL)).

- Las lecturas generadas son enteros entre 0 y 99.# Mock Sensor Logger Service

- Este proyecto implementa un **servicio systemd** que registra periódicamente un sensor simulado en un archivo de log.  

- El programa está escrito en **C** y corre como un daemon, mostrando un **timestamp ISO-8601 | valor simulado**.

---

