#include <GL/glut.h>
#include "game.h"
#include "controls.h"

void keyboard(unsigned char key, int x, int y) {
  switch(key){
  case 'q':
  case '\033':
    exit(0);

  case GLUT_KEY_LEFT:
    Block_moveLeft(current_game->block, current_game->grid);
    break;

  case GLUT_KEY_RIGHT:
    Block_moveRight(current_game->block, current_game->grid);
    break;

  case GLUT_KEY_UP:
    Block_rotate(current_game->block, current_game->grid);
    break;

  case GLUT_KEY_DOWN:
    Block_moveDown(current_game->block, current_game->grid);
    break;
  }
  glutPostRedisplay();
}
