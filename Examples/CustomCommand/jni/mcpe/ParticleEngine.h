#pragma once

struct Particle;
enum ParticleType;

class ParticleEngine {
public:
	Particle* _create(ParticleType);
};
