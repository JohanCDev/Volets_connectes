#include <SoftwareSerial.h>
#define TX 2
#define RX 3
#define bLed 4
#define relayUp 5
#define relayDown 6
SoftwareSerial BT(TX, RX);
char textIn;

void setup() {
  //Initialize Serial Monitor
  Serial.begin(9600);
  //Initialize Bluetooth Serial Port
  BT.begin(9600);
  pinMode(bLed, OUTPUT);
  pinMode(relayDown, OUTPUT);
  pinMode(relayUp, OUTPUT);
  digitalWrite(relayUp, HIGH);
  digitalWrite(relayDown, HIGH);
}

void loop() {

  while (BT.available() == 0);
  textIn = BT.read();
  if (textIn == 'm') {
    Serial.println("UP");
    goUp();
  }
  else if (textIn == 'd') {
    Serial.println("DOWN");
    goDown();
  }
  else if (textIn == 's') {
    Serial.println("STOP");
    _stop();
  }
}

void goUp() {
  digitalWrite(relayUp, LOW);
  digitalWrite(relayDown, HIGH);
  digitalWrite(bLed, LOW);
}

void goDown(){
  digitalWrite(relayDown, LOW);
  digitalWrite(relayUp, HIGH);
  digitalWrite(bLed, LOW);
}

void _stop(){
  digitalWrite(relayDown, HIGH);
  digitalWrite(relayUp, HIGH);
  digitalWrite(bLed, HIGH);
}
