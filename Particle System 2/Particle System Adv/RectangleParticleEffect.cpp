#include "RectangleParticleEffect.h"
#include "Random.h"

using namespace gm;


RectangleParticleEffect::RectangleParticleEffect() {
	particleArray = new RectangleParticle[10];
}

void RectangleParticleEffect::update(sf::RenderWindow& window) {
	for (int i = 0; i < 10; i++) {
		particleArray[i].shape->move(particleArray[i].velocity);
		//std::cout << particleArray[i].velocity.x << " " << particleArray[i].velocity.y << std::endl;
		//p.shape->scale(1.2, 0.8);
	}
}

void RectangleParticleEffect::render(sf::RenderWindow& window) {
	for (int i = 0; i < 10; i++) {
		particleArray[i].render(window);
	}
}

RectangleParticleEffect::~RectangleParticleEffect() {
	delete [] particleArray;
	particleArray = nullptr;
}