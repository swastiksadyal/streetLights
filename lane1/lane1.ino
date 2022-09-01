int relay_op[4] = {0, 0, 0, 0}; // relay outputs
int IR_sensor_lane_1[2] = {0, 0}; // lane 1
int IR_sensor_lane_2[2] = {0, 0}; // lane 2
int lane1 = 0;
int lane2 = 0;

void setup(){
  pinMode(IR_sensor_lane_1[0], INPUT);
  pinMode(IR_sensor_lane_1[1], INPUT);
  pinMode(IR_sensor_lane_2[0], INPUT);
  pinMode(IR_sensor_lane_2[1], INPUT);

  //Relay setup
  pinMode(relay_op[0], OUTPUT);
  pinMode(relay_op[1], OUTPUT);
  pinMode(relay_op[2], OUTPUT);
  pinMode(relay_op[3], OUTPUT);
}

void loop(){
  //  lane one test
  int IR1 = digitalRead(IR_sensor_lane_1[0]);
  int IR2 = digitalRead(IR_sensor_lane_1[1]);

  if (IR1 != 1){
    lane1 = 1;
  }
  if (IR2 != 1){
    lane1 = 0;
  }

  if (lane1 == 1){
    digitalWrite(relay_op[0], HIGH);
    delay(4000);
  }else{
    digitalWrite(relay_op[0], LOW);
    delay(4000);
  }  
}
