#include "pch.h"
#include "Player.h"
#include "CommandQueue.h"
#include "Asset.h"
#include "Foreach.h"

#include <map>
#include <string>
#include <algorithm>

struct PlayerMover {
	PlayerMover(float vx, float vy)
	: velocity(vx, vy)
	{
	}

	void operator()(Asset& asset, sf::Time) const {
		asset.accelerate(velocity);
	}

	sf::Vector2f velocity;

};


Player::Player() {
	//initial key binding
	mKeyBinding[sf::Keyboard::Left] = MoveLeft;
	mKeyBinding[sf::Keyboard::Right] = MoveRight;
	mKeyBinding[sf::Keyboard::Space] = Jump;

	//initial action bindings
	initializeActions();

	//assign categories to player
	FOREACH(auto& pair, mActionBinding)
		pair.second.category - Category::Player;
}

void Player::handleEvent(const sf::Event& event, CommandQueue& commands) {
	if (event.type ==sf::Event::KeyPressed) {
		//check if key appears in key bindings, issue commands in yes
		auto found = mKeyBinding.find(event.key.code);
		if (found != mKeyBinding.end() && !isRealtimeAction(found->second))
			commands.push(mActionBinding[found->second]);
	}
}

void Player::handleRealtimeInput(CommandQueue& commands) {
	//traverse all assigned keys and check if they are pressed
	FOREACH(auto pair, mKeyBinding) {
		//if key is pressed look up action and trigger its action
		if(sf::Keyboard::isKeyPressed(pair.first) && isRealtimeAction(pair.second))
			commands.push(mActionBinding[pair.second]);
	}
}

void Player::assignKey(Action action, sf::Keyboard::Key key) {
	//remove all keys that already map to action
	for (auto itr = mKeyBinding.begin(); itr != mKeyBinding.end();)
	{
		if (itr->second == action)
			mKeyBinding.erase(itr++);
		else
			itr++;
	}

	//insert new binding
	mKeyBinding[key] = action;
}

sf::Keyboard::Key Player::getAssignedKey(Action action) const {
	FOREACH(auto pair, mKeyBinding) {
		if (pair.second == action)
			return pair.first;
	}

	return sf::Keyboard::Unknown;
}

void Player::initializeActions() {

	const float playerSpeed = 200.f;
	mActionBinding[MoveLeft].action = derivedAction<Asset>(PlayerMover(-playerSpeed, 0.f));
	mActionBinding[MoveRight].action = derivedAction<Asset>(PlayerMover(+playerSpeed, 0.f));

	//jump goes here maybe?
}

bool Player::isRealtimeAction(Action action) {
	switch (action) {
	case MoveLeft:
	case MoveRight:
	case Jump:
		return true;
	default:
		return false;
	}
}