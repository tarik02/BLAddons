#pragma once

#include "Item.h"

// Size: 136
class BowItem : public Item {
public:
	TextureUVCoordinateSet bow_pulling_0;	// 64-68; R7
	char obladi[20];			// 68-88
	TextureUVCoordinateSet bow_pulling_1;	// 88-92; R6
	char oblada[20];			// 92-112
	TextureUVCoordinateSet bow_pulling_2;	// 112-116; R8
	char lifegoeson[20];			// 116-136
	
	//virtual ~BowItem();
	virtual int getEnchantSlot() const;
	virtual int getEnchantValue() const;
	virtual void* use(ItemInstance&, Player&);
	virtual void releaseUsing(ItemInstance*, Player*, int);
	virtual int getAnimationFrameFor(Mob&) const;
	virtual const TextureUVCoordinateSet& getIcon(int, int, bool) const;
	
	BowItem(const std::string&, int);
};
