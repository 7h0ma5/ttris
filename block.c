#include <stdlib.h>
#include <string.h>
#include "block.h"
#include "grid.h"

#define FIGURE_COUNT 5

static int figures[][4] = {
  { 0, GRID_WIDTH, GRID_WIDTH * 2, GRID_WIDTH * 3 },
  { 0, GRID_WIDTH, GRID_WIDTH + 1, GRID_WIDTH * 2 },
  { 0, GRID_WIDTH, GRID_WIDTH * 2, GRID_WIDTH * 2 + 1 },
  { 1, GRID_WIDTH + 1, GRID_WIDTH * 2 + 1, GRID_WIDTH * 2 },
  { 0, 1, GRID_WIDTH, GRID_WIDTH + 1 },
};

static CellType colors[] = {
  CELL_RED,
  CELL_GREEN,
  CELL_BLUE,
  CELL_YELLOW,
  CELL_PURPLE,
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
  int h = height(block->figure);
  int w = width(block->figure);

  if (block->y + h >= GRID_HEIGHT) return 1;
  if (block->x < 0) return 1;
  if (block->x + w >= GRID_WIDTH) return 1;

  int off = offset(block);
  for (int i = 0; i < 4; i++) {
    if (grid->cells[off+block->figure[i]] != CELL_CLEAR) return 1;
  }

  return 0;
}

static void rotate(Block* block, int times) {
  int w = width(block->figure);

  for (int j = times; j > 0; j--) {
    for (int i = 0; i < 4; i++) {
      int x = block->figure[i] % GRID_WIDTH;
      int y = block->figure[i] / GRID_WIDTH;
      block->figure[i] = y + (w-x) * GRID_WIDTH;
    }
  }
}

Block* Block_new() {
  Block* block = malloc(sizeof(Block));
  block->figure_id = rand() % FIGURE_COUNT;
  memcpy(block->figure, figures[block->figure_id], sizeof(int)*4);
  block->x = GRID_WIDTH/2-1;
  block->y = 0;
  return block;
}

void Block_clear(Block* block, Grid* grid) {
  int off = offset(block);
  for (int i = 0; i < 4; i++) {
    grid->cells[off+block->figure[i]] = CELL_CLEAR;
  }
}

void Block_draw(Block* block, Grid* grid) {
  int off = offset(block);
  for (int i = 0; i < 4; i++) {
    grid->cells[off+block->figure[i]] = colors[block->figure_id];
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
  Block_clear(block, grid);
  rotate(block, 1);
  if (testCollision(block, grid)) rotate(block, 3);
  Block_draw(block, grid);
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
