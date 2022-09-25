int relay_op[2] =  {0, 0}; // relay outputs
int IR_lane1[2] = {0, 0}; // lane 1
int IR_lane2[2] = {0, 0}; // lane 2

int lane1 = false;
int lane2 = false;
void setup(){
  //Relay setup
  pinMode(relay_op[0], OUTPUT);
  pinMode(relay_op[1], OUTPUT);
  pinMode(relay_op[2], OUTPUT);
  pinMode(relay_op[3], OUTPUT);

  // ir lanes
  pinMode(IR_lane1[0], INPUT);
  pinMode(IR_lane1[1], INPUT);
  pinMode(IR_lane2[0], INPUT);
  pinMode(IR_lane2[1], INPUT);  
}

void loop(){
  int IR01 = digitalRead(IR_lane1[0]);
  int IR02 = digitalRead(IR_lane1[1]);
  int IR11 = digitalRead(IR_lane2[0]);
  int IR12 = digitalRead(IR_lane2[1]);

  //lane 1
  if (lane1){
      if((IR01 == 0) || (IR02 == 0)){
        lane1 = false;
        digitalWrite(relay_op[0], LOW);
        delay(2000);
      }
  }else{
    if((IR01 == 0) || (IR02 == 0)){
      lane1 = true;
      digitalWrite(relay_op[0], HIGH);
      delay(5000);
    }
  }

  //lane 2
  if (lane2){
    if((IR11 == 0) || (IR12 == 0)){
      lane2 = false;
      digitalWrite(relay_op[1], LOW);
      delay(2000);
    }
  }else{
    if((IR11 == 0) || (IR12 == 0)){
      lane2 = true;
      digitalWrite(relay_op[1], HIGH);
      delay(5000);
    }
  }
}
