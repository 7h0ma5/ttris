#ifdef __APPLE__
  #include <GLUT/glut.h>
#else
  #include <GL/glut.h>
#endif
#include <time.h>
#include "game.h"
#include "controls.h"
#include "graphics.h"

#define WINDOW_HEIGHT 480

Game* current_game;
int lock;

void tick(int time) {
  lock = 1;
  glutTimerFunc(800, tick, 0);
  Game_tick(current_game);
  glutPostRedisplay();
  lock = 0;
}

int main(int argc, char** argv) {
  srand(time(NULL));

  lock = 0;
  current_game = Game_new();

  glutInit(&argc, argv);
  glutInitWindowSize((GRID_WIDTH/GRID_HEIGHT)*WINDOW_HEIGHT,
                     WINDOW_HEIGHT);
  glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH);
  glutCreateWindow("ttris");

  glutDisplayFunc(display);
  glutKeyboardFunc(keyboard);
  glutSpecialFunc(keyboard);
  glutTimerFunc(800, tick, 0);

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(0, GRID_WIDTH*BOX_SIZE, GRID_HEIGHT*BOX_SIZE, 0, 0, 1);
  glMatrixMode(GL_MODELVIEW);
  glDisable(GL_DEPTH_TEST);

  glutMainLoop();

  Game_delete(current_game);
  return 0;
}
