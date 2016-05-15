#pragma once

#include "ServerCommandParser.h"
#include "Level.h"

class Minecraft {
public:
	char filler1[64];
	ServerCommandParser* cmdParser;
	
	Level* getLevel();
};
