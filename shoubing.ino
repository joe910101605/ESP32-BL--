/**
 * This example turns the ESP32 into a Bluetooth LE keyboard that writes the words, presses Enter, presses a media key and then Ctrl+Alt+Delete

 https://github.com/T-vK/ESP32-BLE-Keyboard
 1.下载安装库
 2.ESP32接手柄
 */
#include <BleKeyboard.h>

BleKeyboard bleKeyboard;

const int upPin = 0;  //上  0
const int downPin = 2;  //下  2 
const int leftPin = 14;  //左 14
const int rightPin = 15;  //右 15
const int selectPin = 12;  //select  13
const int startPin = 13;  //start  12
const int aPin = 1;  //A  1
const int bPin = 3;  //B  3

int upState=1;
int downState=1;
int leftState=1;
int rightState=1;
int selectState=1;
int startState=1;
int aState=1;
int bState=1;


void setup() {
  Serial.begin(115200);
  Serial.println("Starting BLE work!");
  pinMode(upPin		,  INPUT_PULLUP);
  pinMode(downPin 	, INPUT_PULLUP);
  pinMode(leftPin 	, INPUT_PULLUP);
  pinMode(rightPin 	, INPUT_PULLUP);
  pinMode(selectPin 	, INPUT_PULLUP);
  pinMode(startPin 	, INPUT_PULLUP);
  pinMode(aPin 		, INPUT_PULLUP);
  pinMode(bPin 		, INPUT_PULLUP);

  bleKeyboard.begin();
}

void loop() {
  if(bleKeyboard.isConnected()) {
    upState = digitalRead(upPin);
    if (upState == LOW) {
      bleKeyboard.press('w');
    } 
    else{
      bleKeyboard.release('w');
    }
    downState = digitalRead(downPin);
    if (downState == LOW) {
    bleKeyboard.press('s');
    } 
    else{
      bleKeyboard.release('s');
    }
    leftState = digitalRead(leftPin);
    if (leftState == LOW) {
    bleKeyboard.press('a');
    } 
    else{
      bleKeyboard.release('a');
    }
    rightState = digitalRead(rightPin);
    if (rightState == LOW) {
    bleKeyboard.press('d');
    } 
    else{
      bleKeyboard.release('d');
    }
    aState = digitalRead(aPin);
    if (aState == LOW) {
    bleKeyboard.press('j');
    } 
    else{
      bleKeyboard.release('j');
    }
    bState = digitalRead(bPin);
    if (bState == LOW) {
    bleKeyboard.press('k');
    } 
    else{
      bleKeyboard.release('k');
    }
    selectState = digitalRead(selectPin);
    if (selectState == LOW) {
    bleKeyboard.press(KEY_LEFT_CTRL);
    delay(100);
    bleKeyboard.releaseAll();
    } 
    startState = digitalRead(startPin);
    if (startState == LOW) {
    bleKeyboard.press(KEY_RETURN);
    delay(100);
    bleKeyboard.releaseAll();
    } 
    // Serial.println("Sending 'Hello world'...");
    // bleKeyboard.print("Hello world");
    // delay(1000);

    // Serial.println("Sending Enter key...");
    // bleKeyboard.write(KEY_RETURN);

    // delay(1000);

    // Serial.println("Sending Play/Pause media key...");
    // bleKeyboard.write(KEY_MEDIA_PLAY_PAUSE);

    // delay(1000);

   //
   // Below is an example of pressing multiple keyboard modifiers 
   // which by default is commented out.
    /*
    Serial.println("Sending Ctrl+Alt+Delete...");
    bleKeyboard.press(KEY_LEFT_CTRL);
    bleKeyboard.press(KEY_LEFT_ALT);
    bleKeyboard.press(KEY_DELETE);
    delay(100);
    bleKeyboard.releaseAll();
    */
  }

  // Serial.println("Waiting 5 seconds...");
  delay(10);
}
