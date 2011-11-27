#ifndef BLOCK_H
#define BLOCK_H

typedef struct Block {
  int format;
} Block;

Block* Block_new();
void Block_delete(Block* block);

#endif
