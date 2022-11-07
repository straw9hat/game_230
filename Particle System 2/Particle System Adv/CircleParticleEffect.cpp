#include "Game.h"
#include "Random.h"

using namespace gm;


CircleParticleEffect::CircleParticleEffect() {
	particleArray = new CircleParticle[10];
}

void CircleParticleEffect::update(sf::RenderWindow& window) {
	for (int i = 0; i < 10; i++) {
		particleArray[i].shape->move(particleArray[i].velocity);
		//std::cout << particleArray[i].velocity.x << " " << particleArray[i].velocity.y << std::endl;
		//p.shape->scale(1.2, 0.8);
	}
}

void CircleParticleEffect::render(sf::RenderWindow& window) {
	for (int i = 0; i < 10; i++) {
		particleArray[i].render(window);
	}
}

CircleParticleEffect::~CircleParticleEffect() {
	delete [] particleArray;
	particleArray = nullptr;
}