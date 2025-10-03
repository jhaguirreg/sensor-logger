#include <stdio.h>
#include "../src/sensor/sensor.c"

int main(void) {
	printf("=== Sensor Test ===\n");
			
	// Inicializamos el sensor
	sensor_init();

	// Revisamos si ya inicialzó
	if (!sensor_is_ok()) {
		printf("Error: El sensor no está disponible.\n");
        	return 1; // Salimos con error
	}

	// Leemos 5 veces el sensor
	for (int i = 0; i < 5; i++) {
		int value = sensor_read();
		// Recordemos que sensor_read devuelve -1 si no está activado.
		if (value >= 0) {
        	printf("Lectura #%d: %d\n", i + 1, value);
		}
	}

	printf("=== Fin del test ===\n");

	return 0;
}
