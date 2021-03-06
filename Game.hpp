#ifndef _GAME_
#define _GAME_

#include <vector>
#include <ctime>
#include <sstream>
#include "Player.hpp"
#include "Enemy.hpp"

using namespace std;

class Game{

    public:
        // Constructors / Destructors
        Game();
        ~Game() = default;

        // Update Functions
        void spawnEnemy();
        void updateEnemyAndCombat();
        void updateText();
        void processInput();
        void update(sf::Time);

        // Render Function
        void renderWorld(sf::RenderTarget&);
        void renderText(sf::RenderTarget&);
        void renderBullet(sf::RenderTarget&);
        void renderEnemies(sf::RenderTarget&);
        void render();
        void run();

    private:
        // Variables
        sf::RenderWindow window;
        sf::Event event;

        // Resources
        sf::Font font;
        sf::Texture worldBackgroundTex;
        sf::Sprite worldBackground;

        // Text
        sf::Text uiText;
        sf::Text gameOverText;

        // Game logic
        bool endGame;
        unsigned points;
        float enemySpawnTimer;
        float enemySpawnTimerMax;
        int maxEnemies;

        // Game objects
        Player player;
        std::vector<Enemy*> enemies;
};

#endif
