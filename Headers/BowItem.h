#pragma once

#include "Item.h"

// Size: 136
class BowItem : public Item {
public:
	TextureUVCoordinateSet frame[3];	// 64-136; each member is 24 long
	
	virtual ~BowItem();
	virtual int getEnchantSlot() const;
	virtual int getEnchantValue() const;
	virtual void* use(ItemInstance&, Player&);
	virtual void releaseUsing(ItemInstance*, Player*, int);
	virtual int getAnimationFrameFor(Mob&) const;
	virtual const TextureUVCoordinateSet& getIcon(int, int, bool) const;
	
	BowItem(const std::string&, int);
};