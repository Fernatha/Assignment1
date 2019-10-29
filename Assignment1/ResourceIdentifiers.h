#ifndef RESOURCEIDENTIFIERS_H
#define RESOURCEIDENTIFIERS_H


namespace sf{
	class Texture;
	class Font;
}

namespace Textures{
	enum ID {
		Character,
		Health,
		Coin,
		Background,
		Ground,
		Obstacle,
		Screen,
	};
}
namespace Fonts {
	enum ID {
		Main,
	};
}

//declarations and type defs
template <typename Resource, typename Identifier>
class ResourceHolder;

typedef ResourceHolder<sf::Texture, Textures::ID> TextureHolder;
typedef ResourceHolder<sf::Font, Fonts::ID> FontHolder;
#endif