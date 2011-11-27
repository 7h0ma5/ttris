#include "block.h"

Block* Block_new() {

}

void Block_delete(Block* block) {
  free(block);
}
