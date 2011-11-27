#ifndef GRID_H
#define GRID_H

#define GRID_WIDTH 32
#define GRID_HEIGHT 18
#define GRID_SIZE GRID_WIDTH * GRID_HEIGHT

typedef enum CellType {
  CELL_CLEAR,
  CELL_RED,
  CELL_BLUE,
  CELL_GREEN,
  CELL_YELLOW,
} CellType;

typedef struct Grid {
  CellType* cells;
} Grid;

Grid* Grid_new();
void Grid_delete(Grid* grid);

#endif
