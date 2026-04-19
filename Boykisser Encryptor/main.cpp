#include "config.h"

int main() {
    std::cout << "Enter a string to encrypt >W<: ";
    std::string input;
    std::cin >> input;

    boykisser_converter converter;
    std::string encrypted = converter.convert(input);

	std::cout << encrypted << "\n";

    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Boykisser Encryptor");

    sf::Texture boykisserTexture1;
    boykisserTexture1.loadFromFile("boykisser1.png");

    sf::Texture boykisserTexture2;
    boykisserTexture2.loadFromFile("boykisser2.png");

    sf::Sprite boykisserSprite1(boykisserTexture1);
    sf::Sprite boykisserSprite2(boykisserTexture2);

    float scale1 = 0.07f; 
	float scale2 = 0.05f;
    boykisserSprite1.setScale(scale1, scale1);
    boykisserSprite2.setScale(scale2, scale2);

    sf::Event e;
    while (window.isOpen()) {
        while (window.pollEvent(e)) {
            if (e.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) window.close();
        }
        window.clear(sf::Color::Black);

        float xPos = 10.0f;
        float yPos = 10.0f;
        float spacing = 50.0f; 
        float x = 0;

        for (char c : encrypted) {
            if (c == '1') {
                boykisserSprite1.setPosition(xPos, yPos);
                window.draw(boykisserSprite1);
            }
            else if (c == '0') {
                boykisserSprite2.setPosition(xPos, yPos);
                window.draw(boykisserSprite2);
            }
            xPos += spacing;

            if (xPos > 1900) {
                xPos = 10.0f;
                yPos += spacing;
            }
        }

        window.display();
    }
    return 0;
}
