#ifndef AUDIOMANAGER_H
#define AUDIOMANAGER_H

#include <SFML/Audio.hpp>
#include <string>
#include <memory>

class AudioManager {
public:
    AudioManager();
    bool loadMusic(const std::string& filename);
    void playMusic();
    void pauseMusic();
    void stopMusic();
    void setVolume(float volume);
    bool isPlaying() const;

private:
    std::unique_ptr<sf::Music> music;
};

#endif
