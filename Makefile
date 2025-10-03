# Nombre del binario y archivos
BINARY = sensor-logger
SRC = src/main.c src/sensor/sensor.c
UNIT = systemd/sensor-logger.service
PREFIX = /usr/local/bin
UNITDIR = /etc/systemd/system

# Ruta de build
BUILDDIR = build

all: build/$(BINARY)
#
# Compilar el programa
build/$(BINARY): $(SRC)
	mkdir -p $(BUILDDIR)
	gcc -Wall -Wextra -std=c11 -o $@ $(SRC)
	chmod +x $@

# Instalar binario y unidad systemd
install: build/$(BINARY)
	sudo cp build/$(BINARY) $(PREFIX)/
	sudo chmod +x $(PREFIX)/$(BINARY)
	sudo cp $(UNIT) $(UNITDIR)/
	sudo systemctl daemon-reload
	sudo systemctl enable --now $(BINARY).service
	@echo "Instalado y ejecutando: $(BINARY).service"

# Desinstalar binario y servicio
uninstall:
	sudo systemctl disable --now $(BINARY).service || true
	sudo rm -f $(PREFIX)/$(BINARY)
	sudo rm -f $(UNITDIR)/$(BINARY).service
	sudo systemctl daemon-reload
	@echo "Desinstalado: $(BINARY).service"

# Ver estado del servicio
status:
	systemctl status $(BINARY).service

# Ver logs del programa
logs:
	tail -f /tmp/assignment_sensor.log

# Limpiar build
clean:
	rm -rf $(BUILDDIR)
