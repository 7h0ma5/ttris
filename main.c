#include <GL/glut.h>
#include <time.h>
#include "game.h"
#include "controls.h"
#include "graphics.h"

#define WINDOW_WIDTH 480
#define WINDOW_HEIGHT 480

Game* current_game;

void tick(int time) {
  glutTimerFunc(1000, tick, 0);
  Game_tick(current_game);
  glutPostRedisplay();
}

int main(int argc, char** argv) {
  srand(time(NULL));

  current_game = Game_new();

  glutInit(&argc, argv);
  glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
  glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH);
  glutCreateWindow("ttris");


  glutDisplayFunc(display);
  glutKeyboardFunc(keyboard);
  glutSpecialFunc(keyboard);
  glutTimerFunc(1000, tick, 0);

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(0, GRID_WIDTH*BOX_SIZE, GRID_HEIGHT*BOX_SIZE, 0, 0, 1);
  glMatrixMode(GL_MODELVIEW);
  glDisable(GL_DEPTH_TEST);

  Game_tick(current_game);
  Game_tick(current_game);

  glutMainLoop();

  Game_delete(current_game);
  return 0;
}
