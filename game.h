#ifndef GAME_H
#define GAME_H

#include "grid.h"
#include "block.h"

typedef struct Game {
  int time;
  Grid* grid;
  Block* block;
} Game;

Game* Game_new();

void Game_tick(Game* game);
void Game_delete(Game* game);

extern Game* current_game;
extern int lock;
#endif
