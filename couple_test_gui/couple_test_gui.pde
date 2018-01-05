import processing.serial.*;
Serial serial;
int[] sensorArray = new int[9];

void setup() {
  size(360,360);
  noStroke();
  smooth();
  background(23,100,240);
  //serial = new Serial(this, "/dev/cu.usbmodem14111", 9600);
  print(Serial.list());
  String portName = Serial.list()[5];
  serial = new Serial(this,portName , 9600); 
  for(int i = 0 ; i<9 ; i++){
    sensorArray[i] = 0;
  }
  
  float x = 0 ;
  while(x < width){
    float y = 0 ;
    while(y < height){
      fill(0);
      rect(x,y,118,118);
      y = y + 120;
    }
    x = x + 120;
  }

}


void draw(){
  if ( serial.available() > 0) {
    //sensorValue = serial.read();
    //println(sensorValue);
    
    String myString = serial.readStringUntil(10);
    if(myString != null){
      String order = myString.substring(0,1);
      String value = myString.substring(1,myString.length());
      println(value);
      int c = int(trim(value));
      int a = 0;
      if(c>220){
        a = c-50;
      }else{
        a = 0;
      }
      
      int orderNum = int(order);
      if(orderNum > 3){
        orderNum = orderNum + 1;
      }
      
      fill(a,c,c);
      rect(orderNum%3*120,orderNum/3*120,118,118);
      
      println(order);
      println(value);
    }
  }
  
  
  
  
  

}