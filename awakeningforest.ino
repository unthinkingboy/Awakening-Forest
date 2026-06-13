int touchPins[] = {2, 3, 4, 5, 6, 7, 8}; 
int trigPin = 9;                         
int echoPin = 10;                        

void setup() {
  Serial.begin(9600);
  
  
  for (int i = 0; i < 7; i++) {
    pinMode(touchPins[i], INPUT);
  }
  
  
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  
  long duration, distance;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 17 / 1000; 

  
  for (int i = 0; i < 7; i++) {
    Serial.print(digitalRead(touchPins[i]));
    Serial.print(" "); 
  }

  
  Serial.println(distance); 

  delay(50); 
}