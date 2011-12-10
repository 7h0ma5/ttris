#ifndef GRID_H
#define GRID_H

#define GRID_WIDTH 10
#define GRID_HEIGHT 18
#define GRID_SIZE GRID_WIDTH * GRID_HEIGHT

typedef enum CellType {
  CELL_CLEAR,
  CELL_RED,
  CELL_BLUE,
  CELL_GREEN,
  CELL_YELLOW,
  CELL_PURPLE,
} CellType;

typedef struct Grid {
  int* cells;
} Grid;

Grid* Grid_new();
int Grid_checkFull(Grid* grid);
void Grid_delete(Grid* grid);

#endif
