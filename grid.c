#include <stdlib.h>
#include <string.h>
#include "grid.h"

Grid* Grid_new() {
  Grid* grid = malloc(sizeof(Grid));
  grid->cells = malloc(sizeof(CellType)*GRID_SIZE);
  memset(grid->cells, CELL_CLEAR, GRID_SIZE);
  return grid;
}

int Grid_checkFull(Grid* grid) {
  for (int y = 0; y < GRID_HEIGHT; y++) {
    int full = 1;
    for (int x = 0; x < GRID_WIDTH; x++) {
      if (grid->cells[y*GRID_WIDTH+x] == CELL_CLEAR) full = 0;
    }
    if (full) {
      for (int i = (y+1)*GRID_WIDTH; i > GRID_WIDTH; i--) {
        grid->cells[i] = grid->cells[i-GRID_WIDTH];
      }
      return Grid_checkFull(grid)+1;
    }
  }
  return 0;
}

void Grid_delete(Grid* grid) {
  free(grid->cells);
  free(grid);
}
