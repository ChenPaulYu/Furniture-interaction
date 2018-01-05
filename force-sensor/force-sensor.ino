// 棕黑橙 = 10k
int FSR_Pin = A0z

void setup(){
  Serial.begin(9600);
}

void loop(){
  int FSRReading = analogRead(FSR_Pin); 

  Serial.write(FSRReading/4);
  
  delay(250); //just here to slow down the output for easier reading
}
