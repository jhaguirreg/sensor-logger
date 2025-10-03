#include <stdio.h>
#include <stdlib.h>

int main(void) {
	const char *paths[] = {
		            "/tmp/assignment_sensor.log","/var/tmp/assignment_sensor.log"};
        FILE *file = NULL;
	    const char *used_path = NULL;
		        // Intentar abrir primero en /tmp y luego en /var/tmp
			for (int i = 0; i < 2; i++) {
				file = fopen(paths[i], "r");
				if (file) {
				used_path = paths[i];
				break;
				}
			}

			if (!file) {
				printf("ERROR: No se encontró ningún log. ¿Ejecutaste primero ./main?\n");
				return 1;
			}
			printf("Se encontró %s. Mostrando contenido:\n\n", used_path);
			char line[256];
			int count = 0;

			while (fgets(line, sizeof(line), file)) {
				printf("%s", line);
				count++;

			}
			fclose(file);	
			if (count == 0) {
				printf("\nEl archivo existe pero está vacío.\n");
				return 1;
			}

			printf("\nPrueba exitosa: el main escribió %d líneas en %s\n", count, used_path);
			return 0;
}
