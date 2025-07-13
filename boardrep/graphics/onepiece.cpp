#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

const float TILE_SIZE = 80.f;
const float BOARD_SIZE = 8.f;





int main() {
    sf::RenderWindow window(sf::VideoMode(TILE_SIZE * BOARD_SIZE, TILE_SIZE * BOARD_SIZE), "Chess Board");

    //TEXTURES
    // Load piece textures
    sf::Texture whitePawnTexture;
    if (!whitePawnTexture.loadFromFile("assets/white_pieces/white-pawn.png")) {
        std::cerr << "Failed to load piece PNG!" << std::endl;
        return -1;
    }

    sf::Texture blackPawnTexture;
    if (!blackPawnTexture.loadFromFile("assets/black_pieces/black-pawn.png")) {
        std::cerr << "Failed to load black pawn!" << std::endl;
        return -1;
    }

    //SPRITES
    // Create a sprite and place it at e2 (row 6, column 4). A sprite is an object that diplays the texture (png image) on the screen
    sf::Sprite wp1(whitePawnTexture);
    wp1.setScale(
        TILE_SIZE / whitePawnTexture.getSize().x,
        TILE_SIZE / whitePawnTexture.getSize().y
    );

    //for position, Sfml reads coordinates from top left**
    wp1.setPosition(4 * TILE_SIZE, 6 * TILE_SIZE); // e2. This will be edited to reflect current position of pieces.
    //need to find an elaborate way to do this. An efficient way to track piece moves.

    sf::Sprite bp1(blackPawnTexture);
    bp1.setScale(
        TILE_SIZE / blackPawnTexture.getSize().x,
        TILE_SIZE / blackPawnTexture.getSize().y
    );
    bp1.setPosition(4 * TILE_SIZE, 1 * TILE_SIZE);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();

        // Draw chessboard grid
        for (int row = 0; row < BOARD_SIZE; ++row) {
            for (int col = 0; col < BOARD_SIZE; ++col) {
                sf::RectangleShape square(sf::Vector2f(TILE_SIZE, TILE_SIZE));
                square.setPosition(col * TILE_SIZE, row * TILE_SIZE);
                bool isWhite = (row + col) % 2 == 0;
                square.setFillColor(isWhite ? sf::Color(240, 217, 181) : sf::Color(181, 136, 99));  // light/dark brown
                window.draw(square);
            }
        }

        // Draw piece
        window.draw(wp1);
        window.draw(bp1);

        window.display();
    }

    return 0;
}
