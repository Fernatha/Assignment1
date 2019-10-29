#ifndef CATEGORY_H
#define CATEGORY_H

//Entity/scene node category, used to dispatch nodes

namespace Category {

	enum Type {
		None = 0,
		Scene = 1 << 0,
		Player = 1 << 1,
		Ground = 1 << 2,
		Obstacle = 1 << 3,
	};
}

#endif