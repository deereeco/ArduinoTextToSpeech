/*
Source:
https://www.instructables.com/id/TukuTuku-Voice-Recognition/

Software to program voice recognition module:
https://learn.sparkfun.com/tutorials/terminal-basics/coolterm-windows-mac-linux

Instructions to use software:
Connections(from FTDI to voice module):
TX - RX
RX- TX
VCC- VCC
GND -GND


open access port
- select baud rate - 9600
- Select - com port


Type Hex command :

At the beginning you need to select

AA 36 - to enter into common mode

then to record first group ,type

AA 11 - to start recording first group


whenever it says :-

start - you need to speak command ,

again- wait

different- wait

finish one -means command is recorded

repeat this for 4times - give different commands

finished group one - 5commands is recorded

after this type -
AA - 21 to import group one



if you want to record second group

type command

AA 12
AA 22 to import group 2

AA 24 - query

AA 01 to delete group1
AA 02 to delete group2

Connections:
TX-RX
RX-TX
VCC-VCC
GND -GND

and LED as per the diagram!!
*/

int redPin = 9;
int greenPin = 10;
int bluePin = 11; byte
com = 0; //reply from voice recognition
void setup() { Serial.begin(9600);
	pinMode(redPin, OUTPUT);
	pinMode(greenPin, OUTPUT);
	pinMode(bluePin, OUTPUT);
	delay(2000);
	Serial.write(0xAA);
	Serial.write(0x37);
	delay(1000);
	Serial.write(0xAA);
	Serial.write(0x21);
}
void loop(){
	while(Serial.available()){
		com = Serial.read();
		switch(com){
		case 0x11:
		digitalWrite(redPin, HIGH);
		break;
		case 0x12:
		digitalWrite(greenPin, HIGH);
		break;
		case 0x13:
		digitalWrite(bluePin, HIGH);
		break;
		case 0x14:
		digitalWrite(redPin, HIGH);
		digitalWrite(greenPin, HIGH);
		digitalWrite(bluePin, HIGH);
		break;
		case 0x15:
		digitalWrite(redPin, LOW);
		digitalWrite(greenPin, LOW);
		digitalWrite(bluePin, LOW);
		break;
		}
	}
}