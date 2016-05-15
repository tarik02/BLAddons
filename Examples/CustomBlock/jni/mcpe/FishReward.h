#pragma once

struct ItemInstance;
struct Random;

struct FishReward {
	//void** vtable;		// 0
	int wtf;				// 4
	ItemInstance instance;	// 8
	char filler1[28 - 12];	// 12
	float damage;			// 28
	bool enchanted;			// 32
	
	virtual ~FishReward();
	
	FishReward(const ItemInstance&, int);
	const ItemInstance& getItem(Random&) const;
	void setDamage(float);
	void setEnchanted();
};

struct FishRewardMgr {
	std::vector<FishReward> trash;		// 0
	std::vector<FishReward> treasure;	// 12
	std::vector<FishReward> fish;		// 24
	
	//virtual ~FishRewardMgr();
	
	FishRewardMgr();
	static FishRewardMgr* GetPtr();
	std::vector<FishReward> getFishList();
	void getTrashList();
	std::vector<FishReward> getTreasureList();
};