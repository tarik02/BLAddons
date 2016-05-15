#pragma once

#include "EntityType.h"
#include "NBT.h"

struct SpawnData {
	//void** vtable;							// 0
	int weight;									// 4
	EntityType type;							// 8
	std::unique_ptr<CompoundTag> properties;	// 12
	
	virtual ~SpawnData();
	
	SpawnData();
	SpawnData(const CompoundTag&);
	SpawnData(int, EntityType);
	SpawnData(int, EntityType, CompoundTag*);
	std::unique_ptr<CompoundTag> save();
};