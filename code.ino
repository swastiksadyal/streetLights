// mainc
int relay_output[4] = {0, 0, 0, 0}; // pins
int IR_sensor_input[4] = {0, 0, 0, 0};

int controll[4] = {0, 1, 0, 1};

void setup(){
  // IR sensors setup
  pinMode(IR_sensor_input[0], INPUT);
  pinMode(IR_sensor_input[1], INPUT);
  pinMode(IR_sensor_input[2], INPUT);
  pinMode(IR_sensor_input[3], INPUT);

  //Relay setup
  pinMode(relay_output[0], OUTPUT);
  pinMode(relay_output[1], OUTPUT);
  pinMode(relay_output[2], OUTPUT);
  pinMode(relay_output[3], OUTPUT);
}

void loop(){

  // first
  int IR0 = digitalRead(IR_sensor_input[0]);
  int IR1 = digitalRead(IR_sensor_input[1]);
  int IR02 = digitalRead(IR_sensor_input[2]);
  int IR12 = digitalRead(IR_sensor_input[3]);
  if ((IR0 == 0) && (IR1 == 1)){
    controll[0] += 1;
    delay(100);
  }else if ((IR0 == 1) && (IR1 == 0) && (controll[0] > 0)){
    controll[0] -= 1;
    delay(100);
  }
  if ((IR02 == 0) && (IR12 == 1)){
  controll[1] += 1;
  delay(100);
  }else if ((IR02 == 1) && (IR12 == 0) && (controll[1] > 0)){
    controll[1] -= 1;
    delay(100);
  }
  

  // controolll
  if (controll[0] > 0){
    digitalWrite(relay_output[0], HIGH);
    delay(6000);
  }else{
    delay(1000);
    digitalWrite(relay_output[0], LOW);
    delay(2000);
  }
  if (controll[1] > 0){
  digitalWrite(relay_output[1], HIGH);
  delay(6000);
  }else{
    delay(1000);
    digitalWrite(relay_output[1], LOW);
    delay(2000);
  }
}

//  int IR_status = digitalRead(IRSensor);
//
//  if (IR_status == 1){
//    delay(3000);
//    digitalWrite(relay_one, HIGH);
//
//    // digitalWrite(8, LOW);
//  }
//  
//
//
//
//}
  
//  if (statusSensor == 1)
//    digitalWrite(LED, LOW); // LED LOW
//  }
//  
//  else
//  {
//    digitalWrite(LED, HIGH); // LED High
//  }
  
