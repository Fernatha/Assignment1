#include "State.h"
#include "StateStack.h"

State::Context::Context(sf::RenderWindow& window, TextureHolder& textures, FontHolder& fonts, Player& player)
	: window(&window)
	, textures(&textures)
	, fonts(&fonts)
	, player(&player)
{
}