//Arduboy test

#include <Arduboy2.h>
#include <ArduboyTones.h>

Arduboy2 arduboy;
ArduboyTones sound(arduboy.audio.enabled);

/*MUSIC/SFX DECLARATIONS*/
  
const uint16_t cenaMusic[] PROGMEM = {
  NOTE_D4,300, NOTE_REST,20, NOTE_E4,150, NOTE_REST,20, NOTE_C4,300, NOTE_REST,20, NOTE_D4,700,
  NOTE_REST,1500, NOTE_F4,300, NOTE_REST,20, NOTE_E4,150, NOTE_REST,20, NOTE_C4,300, NOTE_REST,20, NOTE_D4,800,
  NOTE_REST,1000, 
  NOTE_REST,500, NOTE_D4,300, NOTE_REST,20, NOTE_E4,150, NOTE_REST,20, NOTE_C4,300, NOTE_REST,20, NOTE_D4,700,
  NOTE_REST,1500, NOTE_F4,300, NOTE_REST,20, NOTE_E4,150, NOTE_REST,20, NOTE_C4,300, NOTE_REST,20, NOTE_D4,800,
  NOTE_REST,1000, TONES_END
};

const uint16_t cenaMusicShort[] PROGMEM = {
  NOTE_REST,600, NOTE_D4,300, NOTE_REST,20, NOTE_E4,150, NOTE_REST,20, NOTE_C4,300, NOTE_REST,20, NOTE_D4,700,
  NOTE_REST,1500, NOTE_F4,300, NOTE_REST,20, NOTE_E4,150, NOTE_REST,20, NOTE_C4,300, NOTE_REST,20, NOTE_D4,800,
  TONES_END
};

const uint16_t clickFail[] PROGMEM = {NOTE_D3,80, NOTE_REST,500, TONES_END};

const uint16_t clickWin[] PROGMEM = {NOTE_C5,100, NOTE_REST,10, NOTE_C5,100, NOTE_REST,10, NOTE_F5, 150, NOTE_REST, 500, TONES_END};

/*SPRITE DECLARATIONS*/

const unsigned char PROGMEM CenaFaceSprite[] =
{
// width, height,
128, 64,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0x00, 0x00, 0x80, 0x00, 0x00, 0x80, 0x80, 0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 0x80, 0x00, 0x00, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x64, 0xfa, 0x03, 0x82, 0x0a, 0xc3, 0xb1, 0x87, 0xfc, 0x92, 0xa2, 0xff, 0xc1, 0x9c, 0xe5, 0x87, 0xfb, 0x82, 0x9b, 0xf1, 0x81, 0xe3, 0xb2, 0x8e, 0xe3, 0xf8, 0xef, 0x91, 0x9d, 0x27, 0x31, 0x8c, 0x42, 0x78, 0x47, 0x39, 0xf5, 0x10, 0xc7, 0x38, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x40, 0xc0, 0xc0, 0xc0, 0xc0, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0x18, 0x0f, 0x01, 0x00, 0x20, 0x20, 0x20, 0x20, 0x40, 0x40, 0x40, 0xc0, 0x81, 0x80, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x81, 0xc0, 0x40, 0x40, 0x40, 0x40, 0x61, 0x21, 0x21, 0x21, 0x21, 0x21, 0x13, 0x03, 0x04, 0xff, 0x84, 0x83, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x80, 0xff, 0xff, 0xff, 0xff, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0x01, 0x41, 0x67, 0xff, 0x00, 0x00, 0x10, 0x28, 0x28, 0x44, 0x44, 0x7c, 0x7c, 0x54, 0x44, 0x44, 0x28, 0x28, 0x01, 0xf3, 0x00, 0x00, 0x80, 0xe1, 0x09, 0x14, 0x22, 0x22, 0x22, 0x3e, 0x3e, 0x26, 0x22, 0x22, 0x14, 0x08, 0x00, 0x00, 0x00, 0xff, 0x0c, 0x38, 0x00, 0xe1, 0x3e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 0x80, 0x81, 0xff, 0xff, 0xff, 0xff, 0x81, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x30, 0x1c, 0x03, 0x01, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x0f, 0x08, 0x08, 0x04, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x7f, 0x00, 0x00, 0x7f, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0x04, 0x04, 0x06, 0x07, 0x04, 0x04, 0x04, 0x04, 0x04, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x80, 0x80, 0x80, 0x80, 0xff, 0xff, 0xff, 0xff, 0x83, 0x0c, 0x08, 0x30, 0x20, 0x40, 0x80, 
0xe0, 0x20, 0x1c, 0x02, 0xff, 0xff, 0xff, 0xff, 0x02, 0x02, 0x02, 0x02, 0x02, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x04, 0x02, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x02, 0x06, 0x0c, 0x00, 0x00, 0x80, 0xc0, 0xe0, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0x08, 0x08, 0x08, 0x08, 0x08, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0x03, 0x0c, 0x30, 0xc0, 0x00, 0x00, 0x00, 
0x00, 0x00, 0xf8, 0x04, 0xff, 0xff, 0xff, 0xff, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x20, 0x20, 0x20, 0x20, 0x27, 0x38, 0x30, 0x20, 0xc0, 0x80, 0x80, 0x80, 0x80, 0x80, 0x8c, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x0e, 0x0e, 0x0e, 0x0e, 0x0e, 0x86, 0x87, 0x83, 0x83, 0x81, 0x81, 0x80, 0x80, 0x80, 0x40, 0x38, 0x48, 0x48, 0x4f, 0x40, 0x40, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x04, 0x04, 0x04, 0x04, 0x04, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x00, 0x00, 0x0f, 0x10, 0x20, 0x40, 
0x02, 0x01, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0x60, 0x20, 0x10, 0x10, 0x08, 0x08, 0x08, 0x04, 0x04, 0x04, 0x04, 0x08, 0x08, 0x08, 0x10, 0x10, 0x20, 0x20, 0xe0, 0x30, 0x18, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x08, 0x78, 0xc0, 0x40, 0x40, 0x20, 0x20, 0x10, 0x18, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x10, 0x10, 0x10, 0x10, 0x10, 0x20, 0x40, 0x40, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0x01, 0x06, 0x08, 0x08, 0x10, 0x10, 0x60, 
};

const unsigned char PROGMEM CenaHandSprite[] =
{
// width, height,
32, 48,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0x98, 0x98, 0xe0, 0x00, 0xc0, 0x3c, 0x04, 0x3a, 0xa6, 0xfc, 0x00, 0x00, 0x80, 0x60, 0xf0, 0x10, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0xff, 0x0d, 0x89, 0x4e, 0x78, 0xc0, 0x7f, 0x00, 0x08, 0xff, 0xc0, 0x7f, 0x00, 0x08, 0xe8, 0x3f, 0x80, 0x70, 0x1e, 0xc1, 0x80, 0xfc, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x03, 0xfc, 0x00, 0x00, 0x00, 0x03, 0x30, 0x00, 0x00, 0x01, 0x0d, 0x00, 0x00, 0x00, 0xe7, 0x03, 0x01, 0x00, 0xe0, 0x38, 0x0f, 0xf1, 0x08, 0x1c, 0x7c, 0xc4, 0xf8, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x01, 0x3f, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x04, 0x06, 0x03, 0x80, 0x66, 0x38, 0x0e, 0x03, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x10, 0x0f, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
};

const unsigned char PROGMEM CenaHandMask[] =
{
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0xf8, 0xf8, 0xe0, 0x00, 0xc0, 0xfc, 0xfc, 0xfe, 0xfe, 0xfc, 0x00, 0x00, 0x80, 0xe0, 0xf0, 0xf0, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xfe, 0xf8, 0xc0, 0xff, 0xff, 0xff, 0xff, 0xc0, 0xff, 0xff, 0xff, 0xff, 0x3f, 0x80, 0xf0, 0xfe, 0xff, 0xff, 0xff, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x03, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x3f, 0x0f, 0xf1, 0xf8, 0xfc, 0xfc, 0xfc, 0xf8, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x01, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0xfe, 0xff, 0xff, 0x7f, 0x3f, 0x0f, 0x03, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x1f, 0x0f, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
};


/*GAME VARIABLES DECLARATIONS*/
//set to sensible default states
int gameScreen = 0;
bool AButtonPressed = false;
bool BButtonPressed = false;
bool UpButtonPressed = false;
bool DownButtonPressed = false;
bool LeftButtonPressed = false;
bool RightButtonPressed = false;

bool cenaFound = false;
bool wonHard = false;

int cursorX = 62;
int cursorY = 10; //a nice feeling start position
int cursorSize = 4;
int cursorMoveHor = 0;
int cursorMoveVer = 0;

int cenaX = 0;
int cenaY = 0;
int cenaSize = 32;  //multiple of 8 so can be divided down and still work on screen. This is normal (1.0) difficulty. Maybe better to alter with shift registers or make smaller and times by int?
int handPos = 1;
int clickState = 1;
int randomLine = 0;

int cheatProgress = 0;

String difficultyName = "normal";
float difficultyValue = 1.0; //used to alter th size of the cena box (cenaSize)


void setup() {
  arduboy.begin();
  arduboy.setFrameRate(60);     //60 fps
  sound.tones(cenaMusicShort); //play intro song
  arduboy.clear();
  arduboy.audio.on();
}

void loop() {
  if(!arduboy.nextFrame()) {
    return; 
  }

  arduboy.clear();
  
  switch( gameScreen ) {        //This switch statement decided which screen the game is displaying, and what code runs as a result, therefore what is written/drawn on the screen and what logic is in use for control, etc. 
                                  //Works as a state machine (controlled change of gameScreen var to move between states or "screens" of the game)
                                  //if as draw is at the end of all this (and button handling), means all the correct "state" or "screen" code is calculated, then updated and drawn at the very end; all other states are skipped (hence the "breaks" on every state)
    case 0:
      //Press Start Screen

      //graphics (text) for start screen)
      arduboy.setCursor(0, 0);
      arduboy.println();
      arduboy.println("    Finding Cena");
      arduboy.println("  (The video game)");
      arduboy.println("----------------------");
      arduboy.println("'A' to start");
      arduboy.println("'B' for difficulty");
      arduboy.println();
      arduboy.println("Difficulty: " + difficultyName); //shows what difficulty is selected (updated on B button press)

      //the following set of "if" statements tracks the entering of a cheat code to unlock ultra without winning on hard first. Each sucessful press advances the counter until the whole code is entered.
      if(arduboy.pressed(DOWN_BUTTON) && arduboy.pressed(UP_BUTTON) && cheatProgress == 0) {
          cheatProgress++;     
      }
      if(arduboy.pressed(LEFT_BUTTON) && arduboy.pressed(RIGHT_BUTTON) && cheatProgress == 1) {
          cheatProgress++;     
      }
      if(arduboy.pressed(LEFT_BUTTON) && arduboy.pressed(UP_BUTTON) && cheatProgress == 2) {
          cheatProgress++;     
      }
      if(arduboy.pressed(DOWN_BUTTON) && arduboy.pressed(RIGHT_BUTTON) && cheatProgress == 3) {
          cheatProgress = 0;
          sound.tones(clickWin);  
          wonHard = true;     
      }

      if(arduboy.pressed(A_BUTTON) and AButtonPressed == false) {
        AButtonPressed = true;
        cheatProgress = 0; //undo cheat progress
        
        //generate random Cena position and end line (and ensure Cena box fits on the screen)
        randomSeed(millis());
        cenaX = random(0,128-(cenaSize*difficultyValue)); 
        cenaY = random(0,64-(cenaSize*difficultyValue));  
        randomLine = random(0,4);      
        gameScreen = 1; //advance to game
      }
      else if(arduboy.pressed(B_BUTTON) and BButtonPressed == false)
      {
         BButtonPressed = true;
         cheatProgress = 0; //undo cheat progress

         //code to cycle difficulty. Will only go via ultra if wonHard is set true.
         if(difficultyName=="normal") { difficultyName="easy"; difficultyValue = 2.0;} 
         else if(difficultyName=="easy") { difficultyName="hard"; difficultyValue = 0.5;}
         else if(difficultyName=="hard" && wonHard == false ) { difficultyName="normal"; difficultyValue = 1.0;}
         else if(difficultyName=="hard" && wonHard == true ) { difficultyName="ultra"; difficultyValue = 0.25;}
         else if(difficultyName=="ultra") { difficultyName="normal"; difficultyValue = 1.0;}
      }
      break;
      
    case 1:
      //Game Screen
       arduboy.setCursor(0, 0);
      arduboy.fillRect(cursorX, cursorY, cursorSize, cursorSize, WHITE); //players cursor
      
      switch(clickState){ //the state of the cursor (searching, failed to find cena click or found cena click) This is a series of sub-state only within the gameScreen state of 1
        case 1:
        //searching code for moving the cursor around (update cursor X or Y and will change drawRect on next draw update)
  
         if(arduboy.pressed(UP_BUTTON)) {
           UpButtonPressed = true;
           cursorY = cursorY - 1;
           if(cursorY<0){
               cursorY=0; //screen limit (top)
           }
        }
        if(arduboy.pressed(DOWN_BUTTON)) {
          DownButtonPressed = true;
          cursorY = cursorY + 1;
          if(cursorY>60){
            cursorY=60; //screen limit (bottom, factors cursor size)
          }
        }
        if(arduboy.pressed(LEFT_BUTTON)) {
          LeftButtonPressed = true;
          cursorX = cursorX - 1;
          if(cursorX<0){
            cursorX=0; //screen limit (left)
          }
        }
        if(arduboy.pressed(RIGHT_BUTTON)) {
          RightButtonPressed = true;
          cursorX = cursorX + 1;
          if(cursorX>124){
            cursorX=124; //screen limit (right, factors in cursor size)
          }
        }
        if(arduboy.pressed(A_BUTTON) and AButtonPressed == false) {
          //if a click (A BUTTON press) happens when in searching state on game screen...
          
          AButtonPressed = true;
          if(cursorX>=cenaX and cursorX<=(cenaX+(cenaSize*difficultyValue)) and cursorY>=cenaY and cursorY<=(cenaY+(cenaSize*difficultyValue))){      //if in the "cena box" location, this is win, found cena.
            clickState=3;  //go to win click state
            if(difficultyValue<0.9) { wonHard = true; } //mark that a difficulty creater than normal has been won
            sound.tones(clickWin);  //start win sound effect (also used to time leaving clickState 3)
          }
          else{ 
            clickState=2; //go to fail click state
            sound.tones(clickFail); //start fail sound effect (also used to time leaving clickState 2)
            
          }
        }
        break;
        
        case 2:
        //click fail state and graphics code
          arduboy.fillRect(cursorX+cursorSize, cursorY+cursorSize, cursorSize, cursorSize, WHITE);
          arduboy.fillRect(cursorX-cursorSize, cursorY+cursorSize, cursorSize, cursorSize, WHITE);
          arduboy.fillRect(cursorX+cursorSize, cursorY-cursorSize, cursorSize, cursorSize, WHITE);
          arduboy.fillRect(cursorX-cursorSize, cursorY-cursorSize, cursorSize, cursorSize, WHITE);
          if(sound.playing()==false){     //only go to state change code when sound fx is over
            clickState = 1; //return to searching (only when sound stops. This means sound length determines how long the graphics above last on screen before player can move by returning to searching state)
          }
          break;
          
        case 3:
        //click win graphics
        arduboy.fillRect(cursorX+cursorSize+2, cursorY, cursorSize, cursorSize, WHITE);
          arduboy.fillRect(cursorX-cursorSize-2, cursorY, cursorSize, cursorSize, WHITE);
          arduboy.fillRect(cursorX, cursorY+cursorSize+2, cursorSize, cursorSize, WHITE);
          arduboy.fillRect(cursorX, cursorY-cursorSize-2, cursorSize, cursorSize, WHITE);
          if(sound.playing()==false){       //only go to state change code when sound fx is over
            sound.tones(cenaMusic);
            gameScreen = 2; //move to the win screen
            clickState = 1; //resets to searching ready for next game
          }
          break;

        default:
        //error! Should never get here, resets what it can if it happens
        gameScreen = 3; 
        clickState = 1;
        break;
      }
 
      if(arduboy.pressed(B_BUTTON) and BButtonPressed == false) {
        BButtonPressed = true;
        gameScreen = 0; //exit game to menu
      }
      break;
    
    case 2:
      //Found Cena Screen   
       
       if (arduboy.everyXFrames(15)) { //every 15 frames at 60 fps
        //switch cycles through one by one every 15 frames. Updates graphics for hand wave and LED state
        switch(handPos){
        case 1:
          handPos = 2;
          arduboy.setRGBled(50,0,0);
          break;
        case 2:
          handPos = 3;
          arduboy.setRGBled(0,50,0);
          break;
        case 3:
        handPos=4;
        arduboy.setRGBled(0,0,50);
        break;
        case 4:
        handPos=1;
        arduboy.setRGBled(0,0,0);
        break;
        default:
        handPos = 1;
        break;
        }       
       }

        //draws frace, and overwrites hand with mask (so show through fingers) with position altered by state of above cycleing state machine
       Sprites::drawOverwrite(0, 0, CenaFaceSprite, 0);
       if(handPos==4||handPos==2) {Sprites::drawExternalMask(48,16, CenaHandSprite, CenaHandMask,0,0);}
       else if(handPos==1) {Sprites::drawExternalMask(56,15, CenaHandSprite, CenaHandMask,0,0);}
       else if(handPos==3) {Sprites::drawExternalMask(40,15, CenaHandSprite, CenaHandMask,0,0);}

        arduboy.setCursor(0, 0);
        
        //random win lines. If in ultra (difficulty 0.25) then a special like is used instead of a random one from the seed made earlier
        if(difficultyValue>0.3){
        switch(randomLine){
        case 0:
        arduboy.println("You *can* see me...");
        break;
        case 1:
        arduboy.println("Your time is now!");
        break;
        case 2:
        arduboy.println("A  Cena leapt out!");
        break;
        case 3:
        arduboy.println("We are both champs!");
        break;
        case 4:
        arduboy.println("Cena salutes you.");
        break;
        default:
        arduboy.println("WHAT!!?");
        break;
       }

       }
       else
       {
        arduboy.println("ULTIMATE CENA FOUND!");
       }
       
       if(arduboy.pressed(A_BUTTON) and AButtonPressed == false) {
        AButtonPressed = true;
        arduboy.setRGBled(0,0,0);
        gameScreen = 0; //return to menu
      }
      break;
    
    default:
      //Error State Screen - should never get here
      arduboy.setCursor(0, 0);
      arduboy.print("How did you reach this?!");  
      if(arduboy.pressed(A_BUTTON) and AButtonPressed == false) {
        AButtonPressed = true;
        gameScreen = 0;
      }
  }
  
  arduboy.display(); //draw what the above code has set to the screen


  //resets the bools that say a button is pressed (makes it wait for release to stop multiple hit on every press)
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
