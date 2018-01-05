

import controlP5.*;
import processing.serial.*;
Serial serial;  
ControlP5 cp5;
int myColor = color(0,0,0);
int sensorValue;
int sliderValue = 0;
int sliderTicks1 = 100;
int sliderTicks2 = 30;
Slider abc;

void setup() {
  size(640, 480);
  smooth();
  colorMode(HSB, 100);
  noStroke();
  
  serial = new Serial(this, "/dev/cu.usbmodem1411", 9600);
  cp5 = new ControlP5(this);
  

  // add a vertical slider
  cp5.addSlider("slider")
     .setPosition(100,100)
     .setSize(300,40)
     .setRange(0,255)
     .setValue(0)
     ;
  
}

void draw() {
  background(sliderTicks1);
  if ( serial.available() > 0) {
    
    sensorValue = serial.read();
    println(sensorValue);
    sliderValue = sensorValue;
    if(sliderValue >60){
      cp5.getController("slider").setValue(sliderValue);
    }
  }else{
    cp5.getController("slider").setValue(sliderValue);
  }

  
}