/* 
Signal Pin {Water Sensor} - D8
+Ve Pin {Water Sensor} - 3.3V
-Ve Pin {Water Sensor} - GND

Passive Buzzer {+} - 11
Pazzive Buzzer {-} - GND

*/

int piezo = 11;
int sensor = 8;

void setup(){
  pinMode(piezo,OUTPUT);
  pinMode(sensor,INPUT);
  Serial.begin(9600);
}
void piezo_activation(int value){
  if (value > 190  && value < 194){
    digitalWrite(piezo,HIGH);
    delay(20);
    digitalWrite(piezo,LOW);
    delay(1000);
  }
   else if (value > 180 && value < 189 ){
    digitalWrite(piezo,HIGH);
    delay(50);
    digitalWrite(piezo,LOW);
    delay(500);
  }

  else if (value <  179){
    digitalWrite(piezo,HIGH);
    delay(50);
    digitalWrite(piezo,LOW);
    delay(125);
  }
}
void loop(){
  int sensor_value = analogRead(sensor);
  Serial.println(sensor_value);
  piezo_activation(sensor_value);
}
