#include "pch.h"
#include "Player.h"
#include "TextureHolder.h"

Player::Player() {
	m_Health = START_HEALTH;

	m_Sprite = Sprite(TextureHolder::GetTexture("graphics/player.png"));

	m_Sprite.setOrigin(25, 25);
}

void Player::spawn(IntRect arena, Vector2f Resolution, int tilesize) {

}