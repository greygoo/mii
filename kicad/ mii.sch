EESchema Schematic File Version 2
LIBS:rfm69
LIBS:power
LIBS:device
LIBS:switches
LIBS:relays
LIBS:motors
LIBS:transistors
LIBS:conn
LIBS:linear
LIBS:regul
LIBS:74xx
LIBS:cmos4000
LIBS:adc-dac
LIBS:memory
LIBS:xilinx
LIBS:microcontrollers
LIBS:dsp
LIBS:microchip
LIBS:analog_switches
LIBS:motorola
LIBS:texas
LIBS:intel
LIBS:audio
LIBS:interface
LIBS:digital-audio
LIBS:philips
LIBS:display
LIBS:cypress
LIBS:siliconi
LIBS:opto
LIBS:atmel
LIBS:contrib
LIBS:valves
LIBS:RPi_Zero_pHat_Template-cache
LIBS:wemos_mini
LIBS: mii-cache
EELAYER 25 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L WeMos_mini U1
U 1 1 5B41CB77
P 5800 3200
F 0 "U1" H 5800 3700 60  0000 C CNN
F 1 "WeMos_mini" H 5800 2700 60  0000 C CNN
F 2 "wemos_d1_mini:D1_mini_board" H 6350 2500 60  0001 C CNN
F 3 "" H 6350 2500 60  0000 C CNN
	1    5800 3200
	1    0    0    -1  
$EndComp
$Comp
L RFM69 IC1
U 1 1 5B42321C
P 5800 4350
F 0 "IC1" H 5500 4850 50  0000 L CNN
F 1 "RFM69" H 5500 3850 50  0000 L CNN
F 2 "RF_Modules:HOPERF-RFM69HW" H 5500 3750 50  0001 L CNN
F 3 "http://www.hoperf.com/upload/rf/RFM69HW-V1.3.pdf" H 5500 3650 50  0001 L CNN
	1    5800 4350
	1    0    0    -1  
$EndComp
Text GLabel 6300 2850 2    60   Output ~ 0
3.3V
Text GLabel 5400 4650 0    60   Input ~ 0
3.3V
Text GLabel 5300 2950 0    60   Input ~ 0
GND
Text GLabel 6200 4650 2    60   Output ~ 0
GND
Text GLabel 5400 4050 0    60   Output ~ 0
DIO0
Text GLabel 6200 4050 2    60   Input ~ 0
NSS
Text GLabel 6200 4350 2    60   Input ~ 0
SCK
Text GLabel 6200 4150 2    60   Input ~ 0
MOSI
Text GLabel 6200 4250 2    60   Output ~ 0
MISO
Text GLabel 5300 3150 0    60   Input ~ 0
DIO0
Text GLabel 6300 2950 2    60   Output ~ 0
NSS
Text GLabel 6300 3250 2    60   Output ~ 0
SCK
Text GLabel 6300 3150 2    60   Input ~ 0
MISO
Text GLabel 6300 3050 2    60   Output ~ 0
MOSI
Text GLabel 5300 3450 0    60   Input ~ 0
RX
Text GLabel 5300 3550 0    60   Output ~ 0
TX
$Comp
L Conn_Coaxial J1
U 1 1 5BB51258
P 7050 4550
F 0 "J1" H 7060 4670 50  0000 C CNN
F 1 "Conn_Coaxial" V 7165 4550 50  0000 C CNN
F 2 "Connectors:SMA_THT_Jack_Straight" H 7050 4550 50  0001 C CNN
F 3 "" H 7050 4550 50  0001 C CNN
	1    7050 4550
	1    0    0    -1  
$EndComp
Text GLabel 7050 4750 3    60   Output ~ 0
GND
Text GLabel 6900 4550 0    60   Input ~ 0
ANA
Text GLabel 6200 4550 2    60   Output ~ 0
ANA
Text GLabel 6950 3550 3    60   Input ~ 0
3.3V
Text GLabel 7050 3550 3    60   Input ~ 0
TX
Text GLabel 7150 3550 3    60   BiDi ~ 0
SCL
Text GLabel 7250 3550 3    60   Output ~ 0
MISO
Text GLabel 7350 3550 3    60   Input ~ 0
SCK
Text GLabel 6950 3050 1    60   Output ~ 0
GND
Text GLabel 7050 3050 1    60   Output ~ 0
RX
Text GLabel 7150 3050 1    60   BiDi ~ 0
SDA
Text GLabel 7250 3050 1    60   Input ~ 0
MOSI
Text GLabel 7350 3050 1    60   Input ~ 0
NSS
Text GLabel 5300 3350 0    60   BiDi ~ 0
SDA
Text GLabel 5300 3250 0    60   BiDi ~ 0
SCL
Text GLabel 6300 3550 2    60   Output ~ 0
RST
$Comp
L Conn_01x03 J3
U 1 1 5BB6492D
P 8200 2950
F 0 "J3" H 8200 3150 50  0000 C CNN
F 1 "Conn_01x03" H 8200 2750 50  0000 C CNN
F 2 "Connectors_Molex:Molex_KK-6410-03_03x2.54mm_Straight" H 8200 2950 50  0001 C CNN
F 3 "" H 8200 2950 50  0001 C CNN
	1    8200 2950
	1    0    0    -1  
$EndComp
$Comp
L Conn_01x03 J4
U 1 1 5BB64A62
P 8200 3600
F 0 "J4" H 8200 3800 50  0000 C CNN
F 1 "Conn_01x03" H 8200 3400 50  0000 C CNN
F 2 "Connectors_Molex:Molex_KK-6410-03_03x2.54mm_Straight" H 8200 3600 50  0001 C CNN
F 3 "" H 8200 3600 50  0001 C CNN
	1    8200 3600
	1    0    0    -1  
$EndComp
$Comp
L Conn_01x03 J5
U 1 1 5BB64A8D
P 8200 4250
F 0 "J5" H 8200 4450 50  0000 C CNN
F 1 "Conn_01x03" H 8200 4050 50  0000 C CNN
F 2 "Connectors_Molex:Molex_KK-6410-03_03x2.54mm_Straight" H 8200 4250 50  0001 C CNN
F 3 "" H 8200 4250 50  0001 C CNN
	1    8200 4250
	1    0    0    -1  
$EndComp
Text GLabel 8000 2850 0    60   Output ~ 0
GND
Text GLabel 8000 3050 0    60   Input ~ 0
3.3V
Text GLabel 8000 3500 0    60   Output ~ 0
GND
Text GLabel 8000 3700 0    60   Input ~ 0
3.3V
Text GLabel 8000 4150 0    60   Output ~ 0
GND
Text GLabel 8000 4350 0    60   Input ~ 0
3.3V
Text GLabel 8000 2950 0    60   BiDi ~ 0
D4
Text GLabel 8000 3600 0    60   BiDi ~ 0
D0
Text GLabel 8000 4250 0    60   BiDi ~ 0
A0
Text GLabel 5300 3050 0    60   BiDi ~ 0
D4
Text GLabel 6300 3350 2    60   BiDi ~ 0
D0
Text GLabel 6300 3450 2    60   BiDi ~ 0
A0
$Comp
L Conn_01x05 J2
U 1 1 5BB68E3C
P 7150 3250
F 0 "J2" H 7150 3550 50  0000 C CNN
F 1 "Conn_01x05" H 7150 2950 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x05_Pitch2.54mm" H 7150 3250 50  0001 C CNN
F 3 "" H 7150 3250 50  0001 C CNN
	1    7150 3250
	0    1    1    0   
$EndComp
$Comp
L Conn_01x05 J6
U 1 1 5BB68ECD
P 7150 3350
F 0 "J6" H 7150 3650 50  0000 C CNN
F 1 "Conn_01x05" H 7150 3050 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x05_Pitch2.54mm" H 7150 3350 50  0001 C CNN
F 3 "" H 7150 3350 50  0001 C CNN
	1    7150 3350
	0    -1   -1   0   
$EndComp
$EndSCHEMATC
