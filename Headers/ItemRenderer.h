#pragma once

namespace mce {
	class TextureGroup;
	struct TexturePtr;
}
struct ItemInstance;

struct ItemRenderer {
	void createSingleton(mce::TextureGroup&);
	static const mce::TexturePtr& getGraphics(ItemInstance const&);
	
	static void* mItemGraphics[512];
	static ItemRenderer instance;
};
