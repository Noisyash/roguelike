#include "../include/rogue.h"

Room createRoom(int y, int x, int height, int width) {
  Room newRoom;

  newRoom.pos.y = y;
  newRoom.pos.x = x;
  newRoom.height = height;
  newRoom.width = width;
  newRoom.center.y = y + (int)(height / 2);
  newRoom.center.x = x + (int)(width / 2);

  return newRoom;
}
