#include "../include/rogue.h"

const int MAXROOMS = 11; // maximum number of rooms +1
const int MINROOMS = 5;

const int MAXROOMHEIGHT = 7;
const int MINROOMHEIGHT = 3;
const int MAXROOMWIDTH = 15;
const int MINROOMWIDTH = 5;
Tile **createMapTiles(void) {
  Tile **tiles = calloc(MAP_HEIGHT, sizeof(Tile *));

  for (int y = 0; y < MAP_HEIGHT; y++) {
    tiles[y] = calloc(MAP_WIDTH, sizeof(Tile));
    for (int x = 0; x < MAP_WIDTH; x++) {
      tiles[y][x].ch = '#';
      tiles[y][x].walkable = false;
    }
  }

  return tiles;
}

Position setupMap(void) {
  int y, x, height, width, n_rooms;
  n_rooms = (rand() % 11) + 5;
  Room *rooms = calloc(n_rooms, sizeof(Room));
  Position start_pos;

  for (int i = 0; i < n_rooms; i++) {
    y = (rand() % (MAP_HEIGHT - 10)) + 1;
    x = (rand() % (MAP_WIDTH - 20)) + 1;
    height = (rand() % 7) + 3;
    width = (rand() % 15) + 5;
    rooms[i] = createRoom(y, x, height, width);
    addRoomToMap(rooms[i]);
  }

  start_pos.y = rooms[0].center.y;
  start_pos.x = rooms[0].center.x;

  free(rooms);

  return start_pos;
}

void freeMap(void) {
  for (int y = 0; y < MAP_HEIGHT; y++) {
    free(map[y]);
  }
  free(map);
}
