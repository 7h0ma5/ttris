#include <stdlib.h>
#include <math.h>
#include "game.h"

Game* Game_new() {
  Game* game = malloc(sizeof(Game));
  game->grid = Grid_new();
  game->block = Block_new();
  game->score = 0;
  return game;
}

int Game_tick(Game* game) {
  int down = Block_tick(game->block, game->grid);
  if (down) {
    int count = Grid_checkFull(game->grid);
    game->score += pow(count, 2) * 100;

    Block_delete(game->block);
    game->block = Block_new();
    down = Block_tick(game->block, game->grid);
    if (down) return 0;
  }

  return 1000 * pow(0.95, (game->score/1000)+1);
}

void Game_delete(Game* game) {
  Grid_delete(game->grid);
  Block_delete(game->block);
  free(game);
}
