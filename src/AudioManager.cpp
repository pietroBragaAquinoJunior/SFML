#include "AudioManager.h"

AudioManager::AudioManager() : music(std::make_unique<sf::Music>()) {}

bool AudioManager::loadMusic(const std::string& filename) {
    if (!music->openFromFile(filename)) {
        return false;
    }
    music->setLoop(true);  // A música vai tocar em loop
    return true;
}

void AudioManager::playMusic() {
    if (music) {
        music->play();
    }
}

void AudioManager::pauseMusic() {
    if (music) {
        music->pause();
    }
}

void AudioManager::stopMusic() {
    if (music) {
        music->stop();
    }
}

void AudioManager::setVolume(float volume) {
    if (music) {
        music->setVolume(volume);
    }
}

bool AudioManager::isPlaying() const {
    return music && music->getStatus() == sf::Music::Playing;
}
