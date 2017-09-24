ARDUINO_VARIANT = "d1_mini"
SERIAL_PORT = /dev/ttyUSB0
#USER_DEFINE = -D_SSID_=\"YourSSID\" -D_WIFI_PASSWORD_=\"YourPassword\"
#ARDUINO_LIB_PATH = ./libraries
USER_LIBDIR = ./libraries
ARDUINO_LIBS = RadioHead SPI UC121902-TNARX-A
FLASH_SIZE = 512K
FLASH_FREQ = 40MHz

include tools/Arduino-Esp8266-Makefile/arduinoEsp8266.mk

serial	:
	xterm -e "screen /dev/ttyUSB0 9600"
