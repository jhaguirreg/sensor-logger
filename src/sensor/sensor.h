#ifndef SENSOR_H
#define SENSOR_H

#include <stdbool.h>

// Inicializar el sensor.
int sensor_init(void);

// Leer un valor del sensor.
int sensor_read(void);

// Verificar si el sensor está funcionando correctamente.
bool sensor_is_ok(void);

#endif // SENSOR_H
