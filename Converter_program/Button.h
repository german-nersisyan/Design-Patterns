#pragma once
#include <SFML/Graphics.hpp>
#include <string>

class Button {
private:
	sf::RectangleShape box;
	sf::Text label;
	bool selected = false;

public:
	Button(sf::Font& font,
		const std::string& text,
		sf::Vector2f position);

	void setSelected(bool value);
	bool isSelected() const;

	bool isClicked(sf::Vector2f mouse) const;
	bool isHovered(sf::Vector2f mouse) const;

	void draw(sf::RenderWindow& window, sf::Vector2f mouse);
};