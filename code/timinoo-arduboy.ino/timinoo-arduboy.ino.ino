#include <Arduboy2.h>
#include "Tinyfont.h"

/*
 * Normal font
 *  -> Max cols: 21
 *  -> Max lines: 8
 * 
 * Tiny font
 *  -> Max cols: 25
 *  -> Max lines: 13
 */

Arduboy2 arduboy;
Tinyfont tinyfont = Tinyfont(arduboy.sBuffer, Arduboy2::width(), Arduboy2::height());

void setup() {
  arduboy.begin();
  arduboy.setFrameRate(30);
  arduboy.clear();
}

void loop() {
  if ( !arduboy.nextFrame() ) {
    return;
  }

  arduboy.clear();
  tinyfont.setCursor(0, 0);
  arduboy.pollButtons();

  if ( arduboy.justPressed(A_BUTTON) ) {
    currentDialog += 1;
    if ( currentDialog > ( countDialogs - 1 ) ) {
      currentDialog = 0;
    }
  }
  
  arduboy.display();
}
