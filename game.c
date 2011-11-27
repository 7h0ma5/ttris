#include <stdlib.h>
#include "game.h"

Game* Game_new() {
  Game* game = malloc(sizeof(Game));
  game->grid = Grid_new();
  game->block = Block_new();
  return game;
}

void Game_delete(Game* game) {
  Grid_delete(game->grid);
  free(game);
}
