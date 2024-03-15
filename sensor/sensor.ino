#include "SR04.h"
#include "LiquidCrystal_I2C.h"
#include <Keypad.h>

#define TRIG_PIN 10
#define ECHO_PIN 11
#define BUZ_PIN 12

// 4 octave
#define C4 261.63
#define Cs4 277.18
#define D4 293.66
#define Ds4 311.13
#define E4 329.63
#define F4 349.23
#define Fs4 369.99
#define G4 392.00
#define Gs4 415.30
#define A4 440.00
#define As4 466.16
#define B4 493.88

// 5 octave
#define C5 523.25
#define Cs5 554.37
#define D5 587.33
#define Ds5 622.25
#define E5 659.26
#define F5 698.46
#define Fs5 739.99
#define G5 783.99
#define Gs5 830.61
#define A5 880.00
#define As5 932.33
#define B5 987.77

// 6 octave
#define C6 1046.502
#define Cs6 1108.731
#define D6 1174.659
#define Ds6 1244.508
#define E6 1318.510
#define F6 1396.913
#define Fs6 1479.978
#define G6 1567.982
#define Gs6 1661.219
#define A6 1760.000
#define As6 1864.655
#define B6 1975.533

#define NUM_SONGS 4

LiquidCrystal_I2C lcd(0x27, 16, 2);
SR04 sr04 = SR04(ECHO_PIN, TRIG_PIN);
long a;

const byte ROWS = 4; // 行数
const byte COLS = 4; // 列数

char hexaKeys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte rowPins[ROWS] = {9, 8 , 7, 6}; 
byte colPins[COLS] = {5, 4, 3, 2}; 

//initialize an instance of class NewKeypad
Keypad keypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 

char songlist[NUM_SONGS][16] = { 
                                "Family Mart",
                                "Noritz",
                                "Dragon Quest",
                                "Legend Of Zelda"
                               };

void famima() {
  int chord[11] = { Fs5, D5, A4, D5, E5, A5, E5, Fs5, E5, A4, D5 };
  int i;
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(songlist[0]);
  for(i=0;i < 5;i++){
    tone(BUZ_PIN, chord[i]);
    delay(300);
    noTone(BUZ_PIN);
    delay(100);
  }
  tone(BUZ_PIN, chord[5]);
  delay(800);
  noTone(BUZ_PIN);
  delay(400);
  for(int j=i+1;j<10;j++){
    tone(BUZ_PIN, chord[j]);
    delay(300);
    noTone(BUZ_PIN);
    delay(100);
  }
  tone(BUZ_PIN, chord[10]);
  delay(800);
  noTone(BUZ_PIN);
  delay(400);
}

void noritz() {
  int chord[18] = { G5, F5, E5, G5, C6, B5, G5, D6, C6, E6, C6, B5, A5, F6, D6, C6, B5, C6 };
  int i,j,k,l,m;
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(songlist[1]);
  for(i=0;i < 2;i++){
    tone(BUZ_PIN, chord[i]);
    delay(200);
    noTone(BUZ_PIN);
    delay(80);
  }
  tone(BUZ_PIN, chord[i]);
  delay(300);
  noTone(BUZ_PIN);
  delay(150);
  for(j=i+1;j < 5;j++){
    tone(BUZ_PIN, chord[j]);
    delay(200);
    noTone(BUZ_PIN);
    delay(80);
  }
  tone(BUZ_PIN, chord[j]);
  delay(300);
  noTone(BUZ_PIN);
  delay(150);
  for(k=j+1;k < 8;k++){
    tone(BUZ_PIN, chord[k]);
    delay(200);
    noTone(BUZ_PIN);
    delay(80);
  }
  tone(BUZ_PIN, chord[k]);
  delay(300);
  noTone(BUZ_PIN);
  delay(180);
  tone(BUZ_PIN, chord[k+1]);
  delay(600);
  noTone(BUZ_PIN);
  delay(500);

  for(l=k+2;l < 12;l++){
    tone(BUZ_PIN, chord[l]);
    delay(200);
    noTone(BUZ_PIN);
    delay(80);
  }
  tone(BUZ_PIN, chord[l]);
  delay(300);
  noTone(BUZ_PIN);
  delay(180);
  for(m=l+1;m < 15;m++){
    tone(BUZ_PIN, chord[m]);
    delay(200);
    noTone(BUZ_PIN);
    delay(80);
  }
  tone(BUZ_PIN, chord[m]);
  delay(300);
  noTone(BUZ_PIN);
  delay(180);
  tone(BUZ_PIN, chord[m+1]);
  delay(300);
  noTone(BUZ_PIN);
  delay(180);
  tone(BUZ_PIN, chord[m+2]);
  delay(600);
  noTone(BUZ_PIN);
  delay(120);

}

void draque() {
  int chord[60] = { G4, G4, C5, D5, E5, F5, G5, C6, B5, A5, A5, G5, Fs5, Fs5, A5, G5, E5, E4, E4, E4, E4, Fs4, G4, A4, A4, B4, C5, D5, A4, A4, C5, C5, B4, A4, G4, E5, F5, E5, D5, C5, A4, C5, D5, E5, D5, C5, C5, B4, G4, G5, E5, F5, G5, A5, A4, B4, C5, F5, E5, C5};
  int i;
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(songlist[2]);
  tone(BUZ_PIN, chord[0]);
  delay(300);
  noTone(BUZ_PIN);
  delay(100);
  tone(BUZ_PIN, chord[1]);
  delay(200);
  noTone(BUZ_PIN);
  delay(50);
  for(i=2;i < 7;i++){
    tone(BUZ_PIN, chord[i]);
    delay(500);
    noTone(BUZ_PIN);
    delay(100);
  }
  tone(BUZ_PIN, chord[i]);
  delay(1000);
  noTone(BUZ_PIN);
  delay(200);
  tone(BUZ_PIN, chord[i+1]);
  delay(300);
  noTone(BUZ_PIN);
  delay(100);
  tone(BUZ_PIN, chord[i+2]);
  delay(100);
  noTone(BUZ_PIN);
  delay(100);
  tone(BUZ_PIN, chord[i+3]);
  delay(800);
  noTone(BUZ_PIN);
  delay(200);
  tone(BUZ_PIN, chord[i+4]);
  delay(200);
  noTone(BUZ_PIN);
  delay(400);
  for(i=12;i<16;i++){
    tone(BUZ_PIN, chord[i]);
    delay(200);
    noTone(BUZ_PIN);
    delay(100);
  }
}

void zelda(){
  int chord[30] = {As4, F4, As4, As4, C5, D5, Ds5, F5, F5, F5, Fs5, Gs5, As5, As5, As5, Gs5, Fs5, Gs5, Fs5, F5};
  int i;
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(songlist[3]);
  tone(BUZ_PIN, chord[0]);
  delay(100);
  noTone(BUZ_PIN);
  delay(400);
  tone(BUZ_PIN, chord[1]);
  delay(600);
  noTone(BUZ_PIN);
  delay(200);
  for(i=2;i<7;i++){
    tone(BUZ_PIN, chord[i]);
    delay(100);
    noTone(BUZ_PIN);
    delay(50);
  }
  tone(BUZ_PIN, chord[i]);
  delay(800);
  noTone(BUZ_PIN);
  delay(400);
  tone(BUZ_PIN, chord[i+1]);
  delay(100);
  noTone(BUZ_PIN);
  delay(50);
  tone(BUZ_PIN, chord[i+2]);
  delay(100);
  noTone(BUZ_PIN);
  delay(50);
  tone(BUZ_PIN, chord[i+3]);
  delay(100);
  noTone(BUZ_PIN);
  delay(50);
  tone(BUZ_PIN, chord[i+4]);
  delay(100);
  noTone(BUZ_PIN);
  delay(50);
  tone(BUZ_PIN, chord[i+5]);
  delay(800);
  noTone(BUZ_PIN);
  delay(200);
  tone(BUZ_PIN, chord[i+6]);
  delay(100);
  noTone(BUZ_PIN);
  delay(50);
  tone(BUZ_PIN, chord[i+7]);
  delay(100);
  noTone(BUZ_PIN);
  delay(50);
  tone(BUZ_PIN, chord[i+8]);
  delay(100);
  noTone(BUZ_PIN);
  delay(50);
  tone(BUZ_PIN, chord[i+9]);
  delay(100);
  noTone(BUZ_PIN);
  delay(50);
  tone(BUZ_PIN, chord[i+10]);
  delay(100);
  noTone(BUZ_PIN);
  delay(200);
  tone(BUZ_PIN, chord[i+11]);
  delay(100);
  noTone(BUZ_PIN);
  delay(50);
  tone(BUZ_PIN, chord[i+12]);
  delay(800);
  noTone(BUZ_PIN);
}

using SongFunc = void(*)();
SongFunc songs[NUM_SONGS] = {famima, noritz, draque, zelda};

void showValidInput1(){
  lcd.clear();
  lcd.print("#: next, *: prev");
  lcd.setCursor(0,1);
  lcd.print("A: return home");
}

void showValidInput2(){
  lcd.clear();
  lcd.print("#: determine");
  lcd.setCursor(0,1);
  lcd.print("*: reset input");
  delay(2000);
  lcd.clear();
  lcd.print("A:return home");
  delay(2000);
}

void showPlaylist(){
  char key;
  int index=1;
  showValidInput1();
  delay(2000);
  lcd.clear();
  lcd.print("0: Family Mart");
  lcd.setCursor(0,1);
  lcd.print("1: Noritz");
  key = keypad.waitForKey();
  while(key == '#' || key == '*'){
    if(key == '#'){
      if(index <= NUM_SONGS-1){
        lcd.clear();
        lcd.print(index);
        lcd.print(": ");
        lcd.print(songlist[index]);
        if(index == NUM_SONGS-1){
          lcd.setCursor(0,1);
          lcd.print("--END OF LIST---");
        }else{
          lcd.setCursor(0,1);
          lcd.print(index+1);
          lcd.print(": ");
          lcd.print(songlist[index+1]);
          index++;
        }
        key = keypad.waitForKey();
      }else{
        showValidInput1();
        key = keypad.waitForKey();
      }
    }else{
      if(index < 2){
        showValidInput1();
        index = 0;
        key = keypad.waitForKey();
      }else{
        lcd.clear();
        lcd.print(index-2);
        lcd.print(": ");
        lcd.print(songlist[index-2]);
        lcd.setCursor(0,1);
        lcd.print(index-1);
        lcd.print(": ");
        lcd.print(songlist[index-1]);
        index--;
        key = keypad.waitForKey();
      }
    }
  }
  if(key == 'A'){
    return;
  }else{
    showPlaylist();
  }
}

void inputSongNum(){
  char key;
  int songNum=0, cnt=0, keyInt;
  showValidInput2();
  lcd.clear();
  lcd.print("Enter songNum");
  key = keypad.waitForKey();
  while((key >= '0') || (key <= '9') || (key == 'A') || (key == '*') || (key == '#')){
    if(key >= '0' && key <= '9'){
      keyInt = key - '0';
      lcd.setCursor(cnt,1);
      lcd.print(keyInt);
      songNum = songNum * (int)pow(10.0, (double)cnt) + keyInt;
      cnt++;
      key = keypad.waitForKey();
    }else if(key == '#'){
      if(songNum < NUM_SONGS){
        songs[songNum]();
        showValidInput2();
        lcd.clear();
        lcd.print("Enter songNum");
        cnt = 0;
        songNum = 0;
        key = keypad.waitForKey();
      }else{
        lcd.clear();
        lcd.print("input number ");
        lcd.setCursor(0,1);
        lcd.print("smaller than ");
        lcd.print(NUM_SONGS);
        showValidInput2();
        lcd.clear();
        lcd.print("Enter songNum");
        cnt = 0;
        songNum = 0;
        key = keypad.waitForKey();
      }
    }else if(key == '*'){
      songNum = 0;
      cnt = 0;
      lcd.clear();
      lcd.print("Enter songNum");
      key = keypad.waitForKey();
    }else if(key == 'A'){
      lcd.clear();
      lcd.print("returning home");
      return;
    }else{
      inputSongNum();
    }
  }
}


void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.backlight();
  pinMode(BUZ_PIN, OUTPUT);
}

void loop() {
  char key;
  lcd.clear();
  lcd.print("A: show playlist");
  lcd.setCursor(0,1);
  lcd.print("B: choose song");
  key = keypad.waitForKey();
  if(key == 'A'){
    showPlaylist();
  }else if(key == 'B'){
    inputSongNum();
  }else{
    return;
  }
  /*
  if(key >= '0' && key <='9'){
    keyInt = key - '0';
    if (keyInt < NUM_SONGS){
      songs[keyInt]();
    } else {
      lcd.clear();
      lcd.print("invalid input.");
      delay(1000);
      return;
    }
  }else{
    lcd.clear();
    lcd.print("invalid input.");
    delay(1000);
    return;
  }
  */
}
