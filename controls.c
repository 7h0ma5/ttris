#include "controls.h"

void keyboard(unsigned char key, int x, int y) {
  switch(key){
  case 'q':
  case '\033':
    exit(0);
  }
}
