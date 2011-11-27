#include <GL/glut.h>
#include "game.h"
#include "controls.h"
#include "graphics.h"

#define WINDOW_WIDTH 480
#define WINDOW_HEIGHT 480

Game* current_game;

int main(int argc, char** argv) {
  current_game = Game_new();

  glutInit(&argc, argv);
  glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
  glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH);
  glutCreateWindow("ttris");

  glutDisplayFunc(display);
  glutKeyboardFunc(keyboard);

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(0, GRID_WIDTH*BOX_SIZE, GRID_HEIGHT*BOX_SIZE, 0, 0, 1);
  glMatrixMode(GL_MODELVIEW);
  glDisable(GL_DEPTH_TEST);

  glutMainLoop();

  Game_delete(current_game);
  return 0;
}
