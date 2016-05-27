#pragma once

#include <string>

enum TextureLocation {};

namespace mce {
	struct TexturePtr;
	
	class TextureGroup {
	public:
		void* getTexture(const std::string&, TextureLocation);
	};
}
