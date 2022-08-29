int IRSensor = 2; // connect ir sensor to arduino pin 2
int relay_one = 8; // relay module

void setup() 
{
  pinMode (IRSensor, INPUT); // sensor pin INPUT
  pinMode(relay_one, OUTPUT);
}

void loop()
{
  int IR_status = digitalRead(IRSensor);

  if (IR_status == 1){
    delay(3000);
    digitalWrite(relay_one, HIGH);

    // digitalWrite(8, LOW);
  }
  



}
  
//  if (statusSensor == 1)
//    digitalWrite(LED, LOW); // LED LOW
//  }
//  
//  else
//  {
//    digitalWrite(LED, HIGH); // LED High
//  }
  
