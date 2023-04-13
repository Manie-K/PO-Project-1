#pragma once
#include "textCustomizer.h"

#define END_SIMULATION_KEY 'x'
#define ABILITY_KEY 'm'
#define SAVE_KEY 's'
#define LOAD_KEY 'l'
#define ARROW_MODIFIER_KEY 224
#define UP_ARROW	72
#define DOWN_ARROW  80
#define RIGHT_ARROW 77
#define LEFT_ARROW  75

#define LOG_MAX_MESSAGES 12
#define LOG_POS_OFFSET 4
#define DIRECTION_COUNT 4

#define ABILITY_TIME 5
#define ABILITY_COOLDOWN 10
#define PLANT_SEED_CHANCE 0.22

#define MAP_W 40
#define MAP_H 20

#define MAP_START_X 1
#define MAP_START_Y 1
#define BORDER_CHAR '#'

//animals chars 
#define HUMAN_CHAR '#'
#define WOLF_CHAR 'W'
#define SHEEP_CHAR 'S'
#define FOX_CHAR 'F'
#define TURTLE_CHAR 'T'
#define ANTELOPE_CHAR 'A'
//plants chars
#define GRASS_CHAR 'M'
#define DANDELION_CHAR '@'
#define GUARANA_CHAR '&'
#define WOLF_BERRIES_CHAR '%'
#define GIANT_HOGWEED_CHAR '!' //barsz sosnowskiego

//colors
#define BLACK			0
#define BLUE			1
#define GREEN			2
#define CYAN			3
#define RED				4
#define MAGENTA			5
#define BROWN			6
#define LIGHTGRAY		7
#define DARKGRAY		8
#define LIGHTBLUE		9
#define LIGHTGREEN		10
#define LIGHTCYAN		11
#define LIGHTRED		12
#define LIGHTMAGENTA	13
#define YELLOW			14
#define WHITE			15