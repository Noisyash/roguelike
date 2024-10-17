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
  int y, x, width, height, n_rooms;
  n_rooms = (rand() % MAXROOMS) + MINROOMS;
  Room *rooms = calloc(n_rooms, sizeof(Room));
  Position startPos = {10, 50};
  for (int i = 0; i < n_rooms; i++) {
    y = (rand() % (MAP_HEIGHT - 10)) + 1;
    x = (rand() % (MAP_WIDTH - 20)) + 1;
    height = (rand() % MAXROOMHEIGHT) + MINROOMHEIGHT;
    width = (rand() % MAXROOMWIDTH) + MINROOMWIDTH;
    rooms[i] = createRoom(y, x, height, width);
    addRoomToMap(rooms[i]);
  }

  startPos.y = rooms[0].center.y;
  startPos.x = rooms[0].center.x;

  free(rooms);

  return startPos;
}

void freeMap(void) {
  for (int y = 0; y < MAP_HEIGHT; y++) {
    free(map[y]);
  }
  free(map);
}
