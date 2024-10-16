#include "../include/rogue.h"

Entity *createPlayer(Position start_pos) {
  Entity *newPlayer = calloc(1, sizeof(Entity));

  newPlayer->pos.x = start_pos.x;
  newPlayer->pos.y = start_pos.y;
  newPlayer->ch = '@';
  return newPlayer;
}

void handleInput(int Input) {
  switch (Input) {
  case 'i':
    player->pos.y--;
    break;
  case 'k':
    player->pos.y++;
    break;
  case 'j':
    player->pos.x--;
    break;
  case 'l':
    player->pos.x++;
    break;
  default:
    break;
  }
}
