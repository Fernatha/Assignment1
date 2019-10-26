#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;
class Player {
private:
	const float START_HEALTH = 4;
	//where is the player
	Vector3f m_Position;

	Sprite m_Sprite;

	Texture m_Texture;

	Vector2f m_Resolution;

	IntRect m_Arena;

	int m_TileSize;

	bool leftPressed;
	bool rightPressed;
	bool jumpPressed;

	int m_Health;

	Time m_LastHit;

	float m_Speed = 200;

public:
	Player();
	void spawn(IntRect arena, Vector2f resolution, int tilesize);

	void resetPlayerStats();

	bool hit(Time timeHit);

	Time getLastHitTime();

	FloatRect getPosition();

	Vector2f getCenter();

	Sprite getSprite();

	//movement
	void moveLeft();
	void moveRight();

	//stop player from moving in target direction
	void stopRight();
	void stopLeft();

	void update(float elapsedTime, Vector2i mousePosition);

	int getHealth();
};