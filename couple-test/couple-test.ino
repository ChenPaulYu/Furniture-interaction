#include <SPI.h>
#include <SD.h>
unsigned long time;

int FSR_Pin_0 = A0;
int FSR_Pin_1 = A1;
int FSR_Pin_2 = A2;
int FSR_Pin_3 = A3;
int FSR_Pin_4 = A4;
int FSR_Pin_5 = A5;
int FSR_Pin_6 = A6;
int FSR_Pin_7 = A7;

int timeAhead = 0;
String dataString = "";

int fileNumber = 0;
String fileName = "sample"+String(fileNumber)+".csv";


File myFile;

const int chipSelect = 53;

void setup() {

  Serial.begin(9600);  // 開啟通訊串列埠開啟
  while (!Serial) {    // 等待串列埠連線
  }

  //----------- 寫入檔案
  //  Serial.print("\nWaiting for SD card ready...");

  if (!SD.begin(53)) {
//                                                                    return;
  }
//    Serial.println("Success!");

//  if (SD.exists("test.csv")) {
//    //    Serial.println("example.txt exists.");
//    SD.remove("test.csv");
//
//  }
    while(1){
      if( !(SD.exists(fileName)) ){
        break;
      }else {
        fileNumber += 1 ;
        fileName = "sample"+String(fileNumber)+".csv";
      }
    }

  myFile = SD.open(fileName, FILE_WRITE);       // 開啟檔案，一次僅能開啟一個檔案

  if (myFile) {                                   // 假使檔案開啟正常
    //    Serial.print("Write to test.csv...");
    myFile.println("sensor_0,sensor_1,sensor_2,sensor_3,sensor_4,sensor_5,sensor_6,time");  // 繼續寫在檔案後面
    myFile.close();                               // 關閉檔案
    //    Serial.println("Completed!");
  } else {
    Serial.println("\n open file error ");    // 無法開啟時顯示錯誤
  }

  Serial.println(fileName);
  


}

void loop() {

  timeAhead = millis();

  
  int fsrValue_0 = analogRead(FSR_Pin_0);
  int fsrValue_1 = analogRead(FSR_Pin_1);
  int fsrValue_2 = analogRead(FSR_Pin_2);
  int fsrValue_3 = analogRead(FSR_Pin_3);
  int fsrValue_4 = analogRead(FSR_Pin_4);
  int fsrValue_5 = analogRead(FSR_Pin_5);
  int fsrValue_6 = analogRead(FSR_Pin_6);
  int fsrValue_7 = analogRead(FSR_Pin_7);

  
  String a0 = "0" + String(fsrValue_0 / 4);
  Serial.println(a0);
  String a1 = "1" + String(fsrValue_1 / 4);
  Serial.println(a1);
  String a2 = "2" + String(fsrValue_2 / 4);
  Serial.println(a2);
  String a3 = "3" + String(fsrValue_3 / 4);
  Serial.println(a3);
  String a4 = "4" + String(fsrValue_4 / 4);
  Serial.println(a4);
  String a5 = "5" + String(fsrValue_5 / 4);
  Serial.println(a5);
  String a6 = "6" + String(fsrValue_6 / 4);
  Serial.println(a6);
//  String a7 = "7" + String(fsrValue_7 / 4);
//  Serial.println(a7);


    saveData(fsrValue_0, fsrValue_1, fsrValue_2, fsrValue_3, fsrValue_4, fsrValue_5, fsrValue_6,timeAhead);


  delay(200);
}


void saveData(int value_0, int value_1 ,int value_2 ,int value_3 ,int value_4 ,int value_5 ,int value_6 , int timeNow) {

  myFile = SD.open(fileName, FILE_WRITE);
  if (myFile) {
    dataString = String(value_0) + "," + String(value_1) + ","  + String(value_2) + ","  + String(value_3) + ","  + String(value_4) + ","  + String(value_5) + ","  + String(value_6) + "," + String(timeNow);
    myFile.println(dataString);
    myFile.close();
  } else {
    Serial.println("\n open file error ");
  }
}

