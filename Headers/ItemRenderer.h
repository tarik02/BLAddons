#pragma once

namespace mce {
	class TextureGroup;
	struct TexturePtr;
}

struct ItemRenderer {
	void createSingleton(mce::TextureGroup&);
	
	static mce::TexturePtr mItemGraphics[512];
	static ItemRenderer instance;
};