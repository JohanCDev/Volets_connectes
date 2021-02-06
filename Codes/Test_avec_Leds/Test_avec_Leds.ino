#define gLed 1
#define rLed 2
#define bLed 3
#define switch1 4
#define switch2 5

void setup()
{
  // Set up the switch pins to be an input:
  pinMode(switch1, INPUT);
  pinMode(switch2, INPUT);
  // Set up the LED pins to be an output:
  pinMode(gLed, OUTPUT);
  pinMode(rLed, OUTPUT);
  pinMode(bLed, OUTPUT);
}

void loop()
{
  // variables to hold the switch state
  int switch1Val;
  int switch2Val;

  switch1Val = digitalRead(switch1);
  switch2Val = digitalRead(switch2);

  if ((switch1Val == HIGH) && (switch2Val == LOW))
  {
    digitalWrite(gLed, HIGH);
    digitalWrite(rLed, LOW);
    digitalWrite(bLed, LOW);
  }
  else if ((switch1Val == LOW) && (switch2Val == HIGH)){
    digitalWrite(gLed, LOW);
    digitalWrite(rLed, HIGH);
    digitalWrite(bLed, LOW);
  }
  else if ((switch1Val == LOW) && (switch2Val == LOW)){
    digitalWrite(gLed, LOW);
    digitalWrite(rLed, LOW);
    digitalWrite(bLed, HIGH);
  }
  else if ((switch1Val == HIGH) && (switch2Val == HIGH)){
    digitalWrite(gLed, HIGH);
    digitalWrite(rLed, HIGH);
    digitalWrite(bLed, HIGH);
  }
}
