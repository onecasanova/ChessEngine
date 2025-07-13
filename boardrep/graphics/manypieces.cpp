#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <map>

const float TILE_SIZE = 80.f;
const float BOARD_SIZE = 8.f;





int main() {
    sf::RenderWindow window(sf::VideoMode(TILE_SIZE * BOARD_SIZE, TILE_SIZE * BOARD_SIZE), "Chess Board");

    //TEXTURES
    // Load piece textures

    //WHITE
    sf::Texture whitePawnTexture;
    if (!whitePawnTexture.loadFromFile("assets/white_pieces/white-pawn.png")) {
        std::cerr << "Failed to load white pawn png!" << std::endl;
        return -1; //terminates the function, prevents it from proceeding
    }

    sf::Texture whiteKingTexture;
    if(!whiteKingTexture.loadFromFile("assets/white_pieces/white-king.png")) {
        std::cerr << "Failed to load white King png!" << std::endl;
        return -1;
    }

    sf::Texture whiteQueenTexture;
    if(!whiteQueenTexture.loadFromFile("assets/white_pieces/white-queen.png")) {
        std::cerr << "Failed to load white queen png!" << std::endl;
        return -1;
    }

    sf::Texture whiteRookTexture;
    if(!whiteRookTexture.loadFromFile("assets/white_pieces/white-rook.png")) {
        std::cerr << "Failed to load white rook png!" << std::endl;
        return -1;
    }

    sf::Texture whiteBishopTexture;
    if(!whiteBishopTexture.loadFromFile("assets/white_pieces/white-bishop.png")) {
        std::cerr << "Failed to load white bishop png!" << std::endl;
        return -1;
    }

    sf::Texture whiteKnightTexture;
    if(!whiteKnightTexture.loadFromFile("assets/white_pieces/white-knight.png")) {
        std::cerr << "Failed to load white knight png!" << std::endl;
        return -1;
    }


    //BLACK
    sf::Texture blackPawnTexture;
    if (!blackPawnTexture.loadFromFile("assets/black_pieces/black-pawn.png")) {
        std::cerr << "Failed to load black pawn!" << std::endl;
        return -1;
    }

    sf::Texture blackKingTexture;
    if(!blackKingTexture.loadFromFile("assets/black_pieces/black-king.png")) {
        std::cerr << "Failed to load black King png!" << std::endl;
        return -1;
    }

    sf::Texture blackQueenTexture;
    if(!blackQueenTexture.loadFromFile("assets/black_pieces/black-queen.png")) {
        std::cerr << "Failed to load black queen png!" << std::endl;
        return -1;
    }

    sf::Texture blackRookTexture;
    if(!blackRookTexture.loadFromFile("assets/black_pieces/black-rook.png")) {
        std::cerr << "Failed to load black rook png!" << std::endl;
        return -1;
    }

    sf::Texture blackBishopTexture;
    if(!blackBishopTexture.loadFromFile("assets/black_pieces/black-bishop.png")) {
        std::cerr << "Failed to load black bishop png!" << std::endl;
        return -1;
    }

    sf::Texture blackKnightTexture;
    if(!blackKnightTexture.loadFromFile("assets/black_pieces/black-knight.png")) {
        std::cerr << "Failed to load black knight png!" << std::endl;
        return -1;
    }


    //SPRITES
    // Create a sprite and place it at e2 (row 6, column 4). A sprite is an object that diplays the texture (png image) on the screen
    
    //PAWNS
    std::map<std::string, sf::Sprite> wpieces;
    std::map<std::string, sf::Sprite> bpieces;
    
    for (int i = 1; i <= 8; ++i) {
        std::string wname = "wp" + std::to_string(i); //wp1, wp2...
        std::string bname = "bp" + std::to_string(i);

        wpieces[wname] = sf::Sprite(whitePawnTexture);
        wpieces[wname].setScale(
            TILE_SIZE / whitePawnTexture.getSize().x,
            TILE_SIZE / whitePawnTexture.getSize().y
        );
        bpieces[bname] = sf::Sprite(blackPawnTexture);
        bpieces[bname].setScale(
            TILE_SIZE / blackPawnTexture.getSize().x,
            TILE_SIZE / blackPawnTexture.getSize().y
        );

        //set initial position for each
        wpieces[wname].setPosition((i-1) * TILE_SIZE, 6 * TILE_SIZE);
        bpieces[bname].setPosition((i-1) * TILE_SIZE, 1 * TILE_SIZE);
    }

    //BISHOPS
    for (int i = 1; i <=2; ++i) {
        std::string wname = "wb" + std::to_string(i);
        std::string bname = "bb" + std::to_string(i);

        wpieces[wname] = sf::Sprite(whiteBishopTexture);
        wpieces[wname].setScale(
            TILE_SIZE / whiteBishopTexture.getSize().x,
            TILE_SIZE / whiteBishopTexture.getSize().y
        );
        bpieces[bname] = sf::Sprite(blackBishopTexture);
        bpieces[bname].setScale(
            TILE_SIZE / blackBishopTexture.getSize().x,
            TILE_SIZE / blackBishopTexture.getSize().y
        );

        //set initial position for each
        wpieces[wname].setPosition((5 - 3*(i-1)) * TILE_SIZE, 7 * TILE_SIZE);
        bpieces[bname].setPosition((5 - 3*(i-1)) * TILE_SIZE, 0);

    }

    //KNIGHTS
    for (int i = 1; i <=2; ++i) {
        std::string wname = "wk" + std::to_string(i);
        std::string bname = "bk" + std::to_string(i);

        wpieces[wname] = sf::Sprite(whiteKnightTexture);
        wpieces[wname].setScale(
            TILE_SIZE / whiteKnightTexture.getSize().x,
            TILE_SIZE / whiteKnightTexture.getSize().y
        );
        bpieces[bname] = sf::Sprite(blackKnightTexture);
        bpieces[bname].setScale(
            TILE_SIZE / blackKnightTexture.getSize().x,
            TILE_SIZE / blackKnightTexture.getSize().y
        );

        //set initial position for each
        wpieces[wname].setPosition((6 - 5*(i-1)) * TILE_SIZE, 7 * TILE_SIZE);
        bpieces[bname].setPosition((6 - 5*(i-1)) * TILE_SIZE, 0);

    }

    //ROOKS
    for (int i = 1; i <=2; ++i) {
        std::string wname = "wr" + std::to_string(i);
        std::string bname = "br" + std::to_string(i);

        wpieces[wname] = sf::Sprite(whiteRookTexture);
        wpieces[wname].setScale(
            TILE_SIZE / whiteRookTexture.getSize().x,
            TILE_SIZE / whiteRookTexture.getSize().y
        );
        bpieces[bname] = sf::Sprite(blackRookTexture);
        bpieces[bname].setScale(
            TILE_SIZE / blackRookTexture.getSize().x,
            TILE_SIZE / blackRookTexture.getSize().y
        );

        //set initial position for each
        wpieces[wname].setPosition((7 - 7*(i-1)) * TILE_SIZE, 7 * TILE_SIZE);
        bpieces[bname].setPosition((7 - 7*(i-1)) * TILE_SIZE, 0);

    }

    //KINGS
    wpieces["wKing"] = sf::Sprite(whiteKingTexture);
    wpieces["wKing"].setScale(
        TILE_SIZE / whiteKingTexture.getSize().x,
        TILE_SIZE / whiteKingTexture.getSize().y
    );
    wpieces["wKing"].setPosition(4 * TILE_SIZE, 7 * TILE_SIZE);

    bpieces["bKing"] = sf::Sprite(blackKingTexture);
    bpieces["bKing"].setScale(
        TILE_SIZE / blackKingTexture.getSize().x,
        TILE_SIZE / blackKingTexture.getSize().y
    );
    bpieces["bKing"].setPosition(4 * TILE_SIZE, 0);


    //QUEENS
    wpieces["wQueen"] = sf::Sprite(whiteQueenTexture);
    wpieces["wQueen"].setScale(
        TILE_SIZE / whiteQueenTexture.getSize().x,
        TILE_SIZE / whiteQueenTexture.getSize().y
    );
    wpieces["wQueen"].setPosition(3 * TILE_SIZE, 7 * TILE_SIZE);

    bpieces["bQueen"] = sf::Sprite(blackQueenTexture);
    bpieces["bQueen"].setScale(
        TILE_SIZE / blackQueenTexture.getSize().x,
        TILE_SIZE / blackQueenTexture.getSize().y
    );
    bpieces["bQueen"].setPosition(3 * TILE_SIZE, 0);


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
        for (auto& [name, sprite] : wpieces) {
            window.draw(sprite);
        }

        for (auto& [name, sprite] : bpieces) {
            window.draw(sprite);
        }
        
        window.display();
    }

    return 0;
}
