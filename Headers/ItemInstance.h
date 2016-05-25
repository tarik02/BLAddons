#pragma once

#include <memory>

#include "Block.h"
#include "Item.h"
#include "NBT.h"

struct ItemInstance {
	char count;			// 0-2
	short auxValue;		// 2-8; lolwat
	CompoundTag* tag;	// 8-12
	Item* item;			// 12-16
	Block* block;		// 16-20
	
	static const void* MAX_STACK_SIZE;
	static const std::string TAG_DISPLAY;
	static const std::string TAG_DISPLAY_NAME;
	static const std::string TAG_ENCHANTS;
	static const std::string TAG_REPAIR_COST;
	
	ItemInstance();
	ItemInstance(bool);
	ItemInstance(int, int, int);
	ItemInstance(const Item*, int, int, const CompoundTag*);
	ItemInstance(const Block*);
	ItemInstance(const Block*, int);
	ItemInstance(const Block*, int, int);
	ItemInstance(const Item*);
	ItemInstance(const Item*, int);
	ItemInstance(const Item*, int, int);
	ItemInstance(const Item*, int, int, const CompoundTag*);
	ItemInstance(const ItemInstance&);
	
	// essentials
	int getId() const;
	short getAuxValue();
	std::string getName() const;
	
	void _setItem(int);
	void add(int);
	bool canDestroySpecial(Block*);
};