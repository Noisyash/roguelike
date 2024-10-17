#include "../include/rogue.h"

Entity *createPlayer(Position start_pos) {
  Entity *newPlayer = calloc(1, sizeof(Entity));

  newPlayer->pos.x = start_pos.x;
  newPlayer->pos.y = start_pos.y;
  newPlayer->ch = '@';
  return newPlayer;
}

void handleInput(int Input) {

  Position newPos = {player->pos.y, player->pos.x};
  switch (Input) {
  case '8':
    newPos.y--;
    break;
  case '2':
    newPos.y++;
    break;
  case '4':
    newPos.x--;
    break;
  case '6':
    newPos.x++;
    break;
  case '7':
    newPos.y--;
    newPos.x--;
    break;
  case '9':
    newPos.y--;
    newPos.x++;
    break;
  case '1':
    newPos.y++;
    newPos.x--;
    break;
  case '3':
    newPos.y++;
    newPos.x++;
  default:
    break;
  }

  movePlayer(newPos);
}

void movePlayer(Position newPos) {
  if (map[newPos.y][newPos.x].walkable) {
    player->pos.y = newPos.y;
    player->pos.x = newPos.x;
  }
}
