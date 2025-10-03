#include "sensor.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Estado interno del sensor.
static bool sensor_initialized = false;

// Inicializamos el sensor.
int sensor_init(void) {
     srand(time(NULL)); // Usamos aleatoriedad para simular lecturas.
     sensor_initialized = true;
     printf("[SENSOR] Inicializado correctamente.\n");
     return 0; 
}

// Lee un valor del sensor.
int sensor_read(void) {
	if (!sensor_initialized) {
		printf("[SENSOR] Error: Sensor no inicializado.\n");
		return -1;
        }
// Simulación de lectura: número aleatorio entre 0 y 100.
	int value = rand()% 100;
        printf("[SENSOR] Lectura = %d\n", value);
        return value;
}

// Verifica si el sensor está inicializado.
bool sensor_is_ok(void) {
     return sensor_initialized;
}                                                       
