#include "pch.h"
#include "Asset.h"
#include "ResourceHolder.h"
#include "Utility.h"

#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderStates.hpp>

Textures::ID toTextureID(Asset::Type type) {
	switch (type) {
	case Asset::Character:
		return Textures::Character;

	case Asset::Ground:
		return Textures::Ground;

	case Asset::Obstacle:
		return Textures::Obstacle;
	}
}

Asset::Asset(Type type, const TextureHolder& textures)
: mType(type),
  mSprite(textures.get(toTextureID(type))) {
	centerOrigin(mSprite);
}

void Asset::drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const {
	target.draw(mSprite, states);
}

unsigned int Asset::getCategory() const {
	switch (mType) {
	case Character:
		return Category::Player;

	case Obstacle:
		return Category::Obstacle;

	default:
		return Category::Ground;
	}
}
