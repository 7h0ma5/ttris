#ifdef __APPLE__
  #include <GLUT/glut.h>
#else
  #include <GL/glut.h>
#endif
#include <stdio.h>
#include <string.h>
#include "graphics.h"
#include "game.h"

void render_grid(Grid* grid) {
  for (int i = 0; i < GRID_SIZE; i++) {
    int x = i % GRID_WIDTH;
    int y = i / GRID_WIDTH;

    int x1 = x * BOX_SIZE;
    int x2 = x * BOX_SIZE + BOX_SIZE;
    int y1 = y * BOX_SIZE;
    int y2 = y * BOX_SIZE + BOX_SIZE;

    if (grid->cells[i] == CELL_CLEAR) glBegin(GL_LINE_LOOP);
    else glBegin(GL_QUADS);

    switch (grid->cells[i]) {
    case CELL_CLEAR:
      glColor3f(0, 0, 0);
      break;

    case CELL_RED:
      glColor3f(1, 0, 0);
      break;

    case CELL_BLUE:
      glColor3f(0, 0, 1);
      break;

    case CELL_GREEN:
      glColor3f(0, 1, 0);
      break;

    case CELL_YELLOW:
      glColor3f(1, 1, 0);
      break;

    case CELL_PURPLE:
      glColor3f(1, 0, 1);
      break;

    case CELL_ORANGE:
      glColor3f(1.0, 0.66, 0);
      break;
    }

    glVertex2f(x1, y1);
    glVertex2f(x2, y1);
    glVertex2f(x2, y2);
    glVertex2f(x1, y2);
    glEnd();
  }
}

void render_info(Game* game) {
  char score[20];
  sprintf(score, "%d", game->score);

  glColor3f(1.0, 1.0, 1.0);
  glRasterPos2f(20, 20);
  glutBitmapString(GLUT_BITMAP_TIMES_ROMAN_24, score);

  if (!game->running) {
    printf("end!");
    const char* text = "MISSION FAILED";
    glColor3f(1.0, 1.0, 1.0);
    //    glRasterPos2f(30, 20);
    glRasterPos2f(WINDOW_WIDTH/2.0, WINDOW_HEIGHT/2.0);
    printf("%f, %f\n", WINDOW_WIDTH/2.0, WINDOW_HEIGHT/2.0);
    glutBitmapString(GLUT_BITMAP_TIMES_ROMAN_24, text);
  }
}

void display(void) {
  glClear(GL_COLOR_BUFFER_BIT);
  render_grid(current_game->grid);
  render_info(current_game);
  glutSwapBuffers();
}
