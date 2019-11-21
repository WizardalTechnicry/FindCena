//Arduboy test

#include <Arduboy2.h>
#include <ArduboyTones.h>

Arduboy2 arduboy;
ArduboyTones sound(arduboy.audio.enabled);
  
const uint16_t cenaMusic[] PROGMEM = {
  NOTE_REST,1200, NOTE_D4,300, NOTE_REST,20, NOTE_E4,150, NOTE_REST,20, NOTE_C4,300, NOTE_REST,20, NOTE_D4,700,
  NOTE_REST,1500, NOTE_F4,300, NOTE_REST,20, NOTE_E4,150, NOTE_REST,20, NOTE_C4,300, NOTE_REST,20, NOTE_D4,800,
  NOTE_REST,1000, 
  NOTE_REST,500, NOTE_D4,300, NOTE_REST,20, NOTE_E4,150, NOTE_REST,20, NOTE_C4,300, NOTE_REST,20, NOTE_D4,700,
  NOTE_REST,1500, NOTE_F4,300, NOTE_REST,20, NOTE_E4,150, NOTE_REST,20, NOTE_C4,300, NOTE_REST,20, NOTE_D4,800,
  NOTE_REST,1000, TONES_END
};

int gameScreen = 0;
bool AButtonPressed = false;
bool BButtonPressed = false;
bool UpButtonPressed = false;
bool DownButtonPressed = false;
bool LeftButtonPressed = false;
bool RightButtonPressed = false;

int cursorX = 62;
int cursorY = 10;
int cursorSize = 4;
int cursorMoveHor = 0;
int cursorMoveVer = 0;

int cenaX = 0;
int cenaY = 0;
int cenaSize = 30;


void setup() {
  arduboy.begin();
  arduboy.setFrameRate(60);
  sound.tones(cenaMusic); 
  arduboy.clear();
  arduboy.audio.on();
}

void loop() {
  if(!arduboy.nextFrame()) {
    return; 
  }

  arduboy.clear();
  
  switch( gameScreen ) {
    case 0:
      //Press Start Screen
      arduboy.setCursor(0, 0);
      arduboy.println("Adrian Presents...");
      arduboy.println();
      arduboy.println("----------------------");
      arduboy.println("   FIND JOHN CENA!!!");
      arduboy.println("    The Video Game");
      arduboy.println("----------------------");
      arduboy.println();
      arduboy.println(" press 'A' to start");

      if(arduboy.pressed(A_BUTTON) and AButtonPressed == false) {
        AButtonPressed = true;
        randomSeed(millis());
        cenaX = random(0,98);
        cenaY = random(0,34);        
        gameScreen = 1;
      }
      break;
      
    case 1:
      //Game Screen
      arduboy.setCursor(0, 0);
      arduboy.fillRect(cursorX, cursorY, cursorSize, cursorSize, WHITE);
      
      if(arduboy.pressed(UP_BUTTON)) {
        UpButtonPressed = true;
        cursorY = cursorY - 1;
        if(cursorY<0){
          cursorY=0;
        }
      }
      if(arduboy.pressed(DOWN_BUTTON)) {
        DownButtonPressed = true;
        cursorY = cursorY + 1;
        if(cursorY>60){
          cursorY=60;
        }
      }
      if(arduboy.pressed(LEFT_BUTTON)) {
        LeftButtonPressed = true;
        cursorX = cursorX - 1;
        if(cursorX<0){
          cursorX=0;
        }
      }
      if(arduboy.pressed(RIGHT_BUTTON)) {
        RightButtonPressed = true;
        cursorX = cursorX + 1;
        if(cursorX>124){
          cursorX=124;
        }
      }
      if(arduboy.pressed(A_BUTTON) and AButtonPressed == false) {
        AButtonPressed = true;
        if(cursorX>cenaX and cursorX<(cenaX+cenaSize) and cursorY>cenaY and cursorY<(cenaY+cenaSize)){
          gameScreen = 2;
        }
      }
      if(arduboy.pressed(B_BUTTON) and BButtonPressed == false) {
        BButtonPressed = true;
        gameScreen = 0;
      }
      break;
    
    case 2:
      //Found Cena Screen
       arduboy.setCursor(0, 0);
       arduboy.println("Cena Found!");//replace with waving cena
       if(arduboy.pressed(A_BUTTON) and AButtonPressed == false) {
        AButtonPressed = true;
        gameScreen = 0;
      }
      break;
    
    default:
      //Error State Screen - remove if memory becomes and issue
      arduboy.setCursor(0, 0);
      arduboy.print("How did you reach this?!");  
      if(arduboy.pressed(A_BUTTON) and AButtonPressed == false) {
        AButtonPressed = true;
        gameScreen = 0;
      }
  }
  arduboy.display();
  
  if(arduboy.notPressed(A_BUTTON)) {
    AButtonPressed = false;
  }
  if(arduboy.notPressed(B_BUTTON)) {
    BButtonPressed = false;
  }  
  if(arduboy.notPressed(UP_BUTTON)) {
    UpButtonPressed = false;
  }  
  if(arduboy.notPressed(DOWN_BUTTON)) {
    DownButtonPressed = false;
  }  
  if(arduboy.notPressed(LEFT_BUTTON)) {
    LeftButtonPressed = false;
  }
  if(arduboy.notPressed(RIGHT_BUTTON)) {
    RightButtonPressed = false;
  }
}
