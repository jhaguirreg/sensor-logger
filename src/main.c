#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <time.h>
#include <string.h>
#include "sensor/sensor.h"

static volatile int keep_running = 1;

void handle_sigterm(int sig) {
	    (void)sig; // evitar warning	      
	    keep_running = 0;
}

void get_timestamp(char *buffer, size_t size) {
	time_t now = time(NULL);		     
       	struct tm *tm_info = gmtime(&now); // UTC		      
	strftime(buffer, size, "%Y-%m-%dT%H:%M:%SZ", tm_info);		     
}
		    
int main(int argc, char *argv[]) {		      
	int interval = 5; // valor por defecto		      
	const char *logfile = "/tmp/assignment_sensor.log";		      
	const char *fallback_logfile = "/var/tmp/assignment_sensor.log";
		      
		      
	// Argumentos simples: --interval N	     
	for (int i = 1; i < argc; i++) {		      
		if (strcmp(argv[i], "--interval") == 0 && i + 1 < argc) {		      
			interval = atoi(argv[++i]);		      
		}
	}
	
	// Inicializar sensor
	if (sensor_init() != 0) {		   
		fprintf(stderr, "Error: no se pudo inicializar el sensor");
		return 1;	
	}
		   

	// Abrir archivo de log
	FILE *fp = fopen(logfile, "a");		   
	if (!fp) {		    
		fprintf(stderr, "No se pudo escribir en %s, intentando fallback %s\n", logfile, fallback_logfile);		      
		logfile = fallback_logfile;		      
		fp = fopen(logfile, "a");		      
		if (!fp) {		    
			fprintf(stderr, "Error fatal: no se pudo abrir archivo de log.\n");
			return 1;
		}		    
	}
		  
	// Manejo de SIGTERM
	signal(SIGTERM, handle_sigterm);
	signal(SIGINT, handle_sigterm);   // Ctrl+C					 				
      	signal(SIGQUIT, handle_sigterm); 
		    		   
	fprintf(stdout, "Logging en %s cada %d segundos\n", logfile, interval);
		    
	// Loop principal
	while (keep_running) {		      
		if (!sensor_is_ok()) {		       
			fprintf(stderr, "Error: sensor no disponible.\n");		       
			break;		       
		}		
		int value = sensor_read();		 
		char timestamp[32];		       
		get_timestamp(timestamp, sizeof(timestamp));
		   
		fprintf(fp, "%s | %d\n", timestamp, value);
		fflush(fp); // asegurar que se escribe	
		sleep(interval);		      
	}
		      		      
	fclose(fp);		      
	return 0;
		     
}
