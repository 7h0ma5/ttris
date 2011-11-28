#ifndef BLOCK_H
#define BLOCK_H

#include "grid.h"

typedef struct Block {
  int figure_id;
  int figure[4];
  int x, y;
} Block;

Block* Block_new();
void Block_delete(Block* block);

int Block_tick(Block* block, Grid* grid);
void Block_moveLeft(Block* block, Grid* grid);
void Block_moveRight(Block* block, Grid* grid);
void Block_rotate(Block* block, Grid* grid);
void Block_moveDown(Block* block, Grid* grid);

#endif
