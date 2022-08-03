#include <Servo.h>
Servo gripper;
Servo wrist;
Servo elbow;
Servo shoulder;
Servo base;
double base_angle=90;
double shoulder_angle=90;
double elbow_angle=90;
double wrist_angle=90;
void setup() {
 Serial.begin(115200); //Baud Rate 115200
   base.attach(8);
  shoulder.attach(9); 
  elbow.attach(10);
  wrist.attach(11);
  gripper.attach(12); 
  base.write(base_angle);
  shoulder.write(shoulder_angle);
  elbow.write(elbow_angle);
  wrist.write(wrist_angle);
}
String getValue(String values, char sep, int i1)
{
  int found = 0;
  int stIndex[] = {0, -1};
  int largIndex = values.length()-1;

  for(int i=0; i<=largIndex && found<=i1; i++){
    if(values.charAt(i)==sep || i==largIndex){
        found++;
        stIndex[0] = stIndex[1]+1;
        stIndex[1] = (i == largIndex) ? i+1 : i;
    }
  }

  return found>i1 ? values.substring(stIndex[0], stIndex[1]) : "";
}

void loop(){
  
  String computerT = Serial.readStringUntil('@');
  computerT.trim();
  if (computerT.length() == 0) {
    return;
  }
  String command = getValue(computerT, ' ',0);

    if (command == "right" || command == "يمين" || command == "Right") {
      base.write(base_angle -= 30);
    }
    if (command == "left" || command == "Left" || command == "يسار") {
     base.write(base_angle += 30);
    }
    if (command == "top" || command == "فوق" || command == "Top") {
      shoulder.write(shoulder_angle -= 30);
    }
   if (command == "bottom"|| command == "تحت" || command == "Bottom") {
     shoulder.write(shoulder_angle += 30);
    }
    Serial.println(command);
    Serial.println("running");
  delay(1000);
}