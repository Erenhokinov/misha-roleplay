#ifndef PLAYER_H
#define PLAYER_H

#include <string>

enum Location { CLASSROOM, HALLWAY, HOME, FOREST, STREET };

struct player {
  std::string name;
  int hp = 100;
  Location currentLoc = CLASSROOM;
  bool hasKey = false;
};

#endif
