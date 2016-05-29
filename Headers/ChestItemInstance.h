#pragma once

#include "ItemInstance.h"

typedef void WeighedTreasureItem;
typedef WeighedTreasureItem ChestItemInstance;

struct ChestItemInstance {
	ItemInstance& iteminstance;	// 0-4
	int minChance;				// 4-8
	int maxChance;				// 8-12
	
	ChestItemInstance(int itemId, int count, int data, int minChance, int maxChance) : iteminstance(itemId, count, data), minChance(minChance), maxChance(maxChance) {}
	ChestItemInstance(ItemInstance iteminstance, int minChance, int maxChance) : iteminstance(iteminstance), minChance(minChance), maxChance(maxChance) {}
};