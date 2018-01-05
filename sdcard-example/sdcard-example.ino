#include <SPI.h>
#include <SD.h>

File myFile;

// 設定 SD library 功能變數:

Sd2Card card;
SdVolume volume;
SdFile root;

const int chipSelect = 4;

void setup() {

  Serial.begin(9600);  // 開啟通訊串列埠開啟
  while (!Serial) {    // 等待串列埠連線
  }

  //----------- 寫入檔案
  Serial.print("\nWaiting for SD card ready...");

  if (!SD.begin(4)) {
    Serial.println("Fail!");
    return;
  }
  Serial.println("Success!");
  
  
  myFile = SD.open("data.csv", FILE_WRITE);       // 開啟檔案，一次僅能開啟一個檔案
  
  if (myFile) {                                   // 假使檔案開啟正常
    Serial.print("Write to card.txt...");         
    myFile.println("position-x,position-y,sensorvalue,timestamp");  // 繼續寫在檔案後面
    myFile.close();                               // 關閉檔案
    Serial.println("Completed!");
  } else {
    Serial.println("\n open file error ");    // 無法開啟時顯示錯誤
  }
  

}

void loop() {            


  
}
