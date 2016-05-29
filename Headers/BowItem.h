#pragma once

#include "Item.h"

// Size: 136
class BowItem : public Item {
public:
	TextureUVCoordinateSet bow_pulling_0;	// 64-88; R7
	TextureUVCoordinateSet bow_pulling_1;	// 88-112; R6
	TextureUVCoordinateSet bow_pulling_2;	// 112-136; R8
	
	//virtual ~BowItem();
	virtual int getEnchantSlot() const;
	virtual int getEnchantValue() const;
	virtual void* use(ItemInstance&, Player&);
	virtual void releaseUsing(ItemInstance*, Player*, int);
	virtual int getAnimationFrameFor(Mob&) const;
	virtual const TextureUVCoordinateSet& getIcon(int, int, bool) const;
	
	BowItem(const std::string&, int);
};