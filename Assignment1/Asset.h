#ifndef ASSET_H
#define ASSET_H

#include "Entity.h"
#include "ResourceIdentifiers.h"

#include <SFML\Graphics\Sprite.hpp>

class Asset : public Entity {
public:
	enum Type {
		Character,
		Ground,
		Obstacle
	};

public:
	Asset(Type type, const TextureHolder& texture);
	virtual unsigned int getCategory() const;

private:
	virtual void drawCurrent(sf::RenderTarget&, sf::RenderStates states) const;

private:
	Type mType;
	sf::Sprite mSprite;
};

#endif
