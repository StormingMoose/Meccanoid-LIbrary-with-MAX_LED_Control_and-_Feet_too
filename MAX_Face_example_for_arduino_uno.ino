
#include "MeccaBrain.h"

const int chainpin1 = 5;         //   my ESP32 pin just for the MAX led face

MeccaBrain chain1(chainpin1);       // M.A.X. LED may not work in a chain and may need its own pin

/*
int pinFACE = 19;  
MeccaBrain chain1(chainpin1); 
*/

static byte happyFace[18] = {
  0xFF, 0xFF, 0xF1, 0xE6, 0xE4, 0xB1, 0x7F, 0x7F,
  0x7F, 0x7F, 0xF1, 0xE6, 0xE4, 0xF1, 0xFF, 0xFF,
  0xF5, 0x2D
  };

static byte Moose[18] = {
  0xA9, 0xf9, 0xa9, 0xf9, 0xA9, 0xf9, 0xfF, 0xfF,
  0xe7, 0xE7, 0x07, 0x1B, 0x89, 0x9F, 0x1F, 0x1F,
  0xF5, 0x2D
  };

 static byte Moose1[18] = {
  0x51, 0xf9, 0x51, 0xf9, 0x51, 0xf9, 0xfF, 0xfF,
  0xe7, 0xE7, 0x07, 0x1B, 0x89, 0x9F, 0x1F, 0x1F,
  0xF5, 0x2D
  };
  
static byte Moose2[18] = {
  0xA1, 0x59, 0xA1, 0x59, 0xA1, 0x59, 0xfF, 0xfF,
  0xe7, 0xE7, 0x07, 0x1B, 0x89, 0x9F, 0x1F, 0x1F,
  0xF5, 0x2D
  };

static byte sadFace[18] = {
  0xFF, 0xFF, 0xFF, 0xC7, 0x8B, 0x8D, 0xC3, 0xFF, 
  0xFF, 0xC3, 0x8D, 0x8B, 0xC7, 0xFF, 0xFF, 0xFF, 
  0xF5, 0x2D 
};


void setup() {

  Serial.begin(9600);

  happyFace[17] = chain1.calculateImageCheckSum(happyFace, 17);
  Moose[17] = chain1.calculateImageCheckSum(Moose, 17);
  Moose1[17] = chain1.calculateImageCheckSum(Moose1, 17);
  Moose2[17] = chain1.calculateImageCheckSum(Moose2, 17);
  
  sadFace[17] = chain1.calculateImageCheckSum(sadFace, 17);

  while (chain1.moduleTypeInfo(0) == NULL) {
        chain1.communicate(); // start comm with devices
    delay(100);
  }
 

  Serial.println("Completed setup...");
}

// the loop routine runs over and over again forever:
void loop() {


//  chain1.setImage(happyFace, 18);
//  delay(2000);

  chain1.setImage(Moose, 18);
  delay(100);
  chain1.setImage(Moose1, 18);
  delay(100);
  chain1.setImage(Moose2, 18);
  delay(100);
  
    
//  chain1.setImage(sadFace, 18);
//     delay(1000);
    

}

