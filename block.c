#include <stdlib.h>
#include "block.h"
#include "grid.h"

static int figures[][4] = {
  { 0, GRID_WIDTH, GRID_WIDTH * 2, GRID_WIDTH * 3 },
  { 0, GRID_WIDTH, GRID_WIDTH + 1, GRID_WIDTH * 2 },
  { 0, GRID_WIDTH, GRID_WIDTH * 2, GRID_WIDTH * 2 + 1 },
  { 1, GRID_WIDTH + 1, GRID_WIDTH * 2 + 1, GRID_WIDTH * 2 },
};

static CellType colors[] = {
  CELL_RED,
  CELL_GREEN,
  CELL_BLUE,
  CELL_YELLOW,
};

static int offset(Block* block) {
  return (GRID_WIDTH * block->y) + block->x;
}

static int width(int* figure) {
  int max = 0;
  for (int i = 0; i < 4; i++) {
    int width = figure[i] % GRID_WIDTH;
    if (width > max) max = width;
  }
  return max;
}

static int height(int* figure) {
  int max = 0;
  for (int i = 0; i < 4; i++) {
    int width = figure[i] / GRID_WIDTH;
    if (width > max) max = width;
  }
  return max;
}

static int testCollision(Block* block, Grid* grid) {
  int h = height(figures[block->figure]);
  int w = width(figures[block->figure]);
  if (block->y + h >= GRID_HEIGHT) return 1;
  if (block->x < 0) return 1;
  if (block->x + w >= GRID_WIDTH) return 1;

  int* figure = figures[block->figure];
  int off = offset(block);
  for (int i = 0; i < 4; i++) {
    if (grid->cells[off+figure[i]] != CELL_CLEAR) return 1;
  }

  return 0;
}

Block* Block_new() {
  Block* block = malloc(sizeof(Block));
  block->figure = rand() % 4;
  block->x = GRID_WIDTH/2-1;
  block->y = -1;
  return block;
}

void Block_clear(Block* block, Grid* grid) {
  int* figure = figures[block->figure];
  int off = offset(block);
  for (int i = 0; i < 4; i++) {
    grid->cells[off+figure[i]] = CELL_CLEAR;
  }
}

void Block_draw(Block* block, Grid* grid) {
  int* figure = figures[block->figure];
  int off = offset(block);
  for (int i = 0; i < 4; i++) {
    grid->cells[off+figure[i]] = colors[block->figure];
  }
}

int Block_tick(Block* block, Grid* grid) {
  int down = 0;
  if (block->y >= 0) Block_clear(block, grid);
  block->y++;
  if (testCollision(block, grid)) {
    block->y--;
    down = 1;
  }
  Block_draw(block, grid);
  return down;
}

void Block_moveLeft(Block* block, Grid* grid) {
  Block_clear(block, grid);
  block->x--;
  if (testCollision(block, grid)) block->x++;
  Block_draw(block, grid);
}

void Block_moveRight(Block* block, Grid* grid) {
  Block_clear(block, grid);
  block->x++;
  if (testCollision(block, grid)) block->x--;
  Block_draw(block, grid);
}

void Block_rotate(Block* block, Grid* grid) {

}

void Block_moveDown(Block* block, Grid* grid) {
  Block_clear(block, grid);
  block->y++;
  if (testCollision(block, grid)) block->y--;
  Block_draw(block, grid);
}

void Block_delete(Block* block) {
  free(block);
}
