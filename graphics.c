#include <GL/glut.h>
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

    printf("%d %d == %d %d\n", x1, x2, y1, y2);

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
    }

    glVertex2f(x1, y1);
    glVertex2f(x2, y1);
    glVertex2f(x2, y2);
    glVertex2f(x1, y2);
    glEnd();
  }
}

void display(void) {
  glClear(GL_COLOR_BUFFER_BIT);
  render_grid(current_game->grid);
  glutSwapBuffers();
}
