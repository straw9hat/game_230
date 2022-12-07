#include "SoundManager.h"

using namespace sf;
using namespace gm;

// Default constructor
SoundManager::SoundManager() {
	buffer = new SoundBuffer[4];
	for (int i = 0; i < 4; i++) {
		buffer[i].loadFromFile("Music/sound" + std::to_string(i + 1) + ".wav");
	}
}



// Our position setter, takes a Vector2f by const reference
void SoundManager::PlaySFX(int type) {
	sound.setBuffer(buffer[type]);
	sound.play();
}

SoundManager::~SoundManager() {}