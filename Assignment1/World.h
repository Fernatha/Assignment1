#ifndef WORLD_H
#define WORLD_H

#include "ResourceHolder.h"
#include "ResourceIdentifiers.h"
#include "SceneNode.h"
#include "SpriteNode.h"
#include "Asset.h"
#include "CommandQueue.h"
#include "Command.h"

#include <SFML/System/NonCopyable.hpp>
#include <SFML/Graphics/View.hpp>
#include <SFML/Graphics/Texture.hpp>

#include <array>
#include <queue>

//forward declaration
namespace sf {
	class RenderWindow;
}

class World : private sf::NonCopyable {
public:
	explicit World(sf::RenderWindow& window);
	void update(sf::Time dt);
	void draw();

	CommandQueue& getCommandQueue();

private:
	void loadTexture();
	void buildSCene();
	void adaptPlayerPosition()l
		void adaptPlayerVelocity();

private:
	enum Layer {
		Background,
		Air,
		LayerCount
	};

private:
	sf::RenderWindow& mWindow;
	sf::View mWorldView;
	TextureHolder mTextures;

	SceneNode mSceneGraph;
	std::array<SceneNode*, LayerCount> mSceneLayers;
	CommandQueue mCommandQueue;

	sf::FloatRect mWorldBounds;
	sf::Vector2f mSpawnPosition;
	float mScrollSpeed;
	Asset* mPlayer;
};

#endif