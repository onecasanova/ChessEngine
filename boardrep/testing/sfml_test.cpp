#include<SFML/Graphics.hpp> 


int main(){
    unsigned int N_square = 800; //window size
    // const float circle_radius = (N_square/2).f;
    const float circle_radius = 100.f;


    sf::RenderWindow window(sf::VideoMode({N_square, N_square}), "SFML works!");
    sf::CircleShape shape(circle_radius);
    shape.setFillColor(sf::Color::Green);

    // set position of circle
    shape.setOrigin(circle_radius, circle_radius); //draw shapefrom the center
    shape.setPosition(N_square/2.f, N_square/2.f); //position in the center



    while (window.isOpen()){
        sf::Event event;
        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed){
                window.close();
            }
        }

        window.clear();
        window.draw(shape);
        window.display();
    }
    return 0;
}
