#include <stdlib.h>
#include <string.h>
#include "grid.h"

Grid* Grid_new() {
  Grid* grid = malloc(sizeof(Grid));
  grid->cells = malloc(sizeof(CellType)*GRID_SIZE);
  memset(grid->cells, CELL_CLEAR, GRID_SIZE);
  return grid;
}

void Grid_delete(Grid* grid) {
  free(grid->cells);
  free(grid);
}
