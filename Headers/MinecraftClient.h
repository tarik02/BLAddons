#pragma once

#include "Minecraft.h"

struct ScreenChooser;
class ParticleEngine;
struct LocalPlayer;

class MinecraftClient {
public:
	char filler1[100];
	Minecraft& minecraft;
	
	ScreenChooser* getScreenChooser() const;
	LocalPlayer* getLocalPlayer();
	ParticleEngine* getParticleEngine() const;
};
