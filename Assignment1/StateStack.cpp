#include "StateStack.h"
#include "Foreach.h"

#include <cassert>

StateStack::StateStack(State::Context context)
	:mStack(),
	mPendingList(),
	mContext(context),
	mFactories()
{}

void StateStack::update(sf::Time dt) {
	//iterate from top to botton, stop when false is returned
	for (auto itr = mStack.rbegin(); itr != mStack.rend(); ++itr) {
		if (!(*itr)->update(dt))
			break;
	}
	applyPendingChanges();
}

void StateStack::draw() {
	//draw active states from top to bottom
	FOREACH(State::Ptr& state, mStack)
		state->draw();
}

void StateStack::handleEvent(const sf::Event& event) {
	//iterate from topto bottom until false is returned
	for (auto itr = mStack.rbegin(); itr != mStack.rend(); ++itr) {
		if (!(*itr)->handleEvent(event))
			break;
	}
	applyPendingChanges();
}

void StateStack::pushState(States::ID stateID) {
	mPendingList.push_back(PendingChange(Push, stateID));
}

void StateStack::popState() {
	mPendingList.push_back(PendingChange(Pop));
}

void StateStack::clearStates() {
	mPendingList.push_back(PendingChange(Clear));
}

bool StateStack::isEmpty() const {
	return mStack.empty();
}