#pragma once

#include <Bindables/abstracttexture.h>

namespace Bind {
	class ImageTexture2DArray :public AbstractTexture {
	public:
	private:
		std::shared_ptr<RawTexture2D> m_texturearray;
	};
}