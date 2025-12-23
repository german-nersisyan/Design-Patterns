#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window/Clipboard.hpp>
#include <string>

class TextBox {
private:
	std::string text;
	size_t cursorPos;

	sf::Text sfText;
	sf::RectangleShape box;
	sf::RectangleShape caret;

	bool isActive;
	float blinkTime;
	bool showCaret;

	float scrollOffsetX;
	float scrollOffsetY;
	float visibleWidth;
	float visibleHeight;

	sf::RectangleShape vScrollbar;
	sf::RectangleShape hScrollbar;
	bool draggingV;
	bool draggingH;
	sf::Vector2f dragOffset;

public:
	TextBox(sf::Font& font, sf::Vector2f position, sf::Vector2f size);

	void handleEvent(const sf::Event& e, sf::Vector2f mousePos);
	void update(float dt);
	void draw(sf::RenderWindow& window);

	void scroll(float deltaX, float deltaY);
	void updateScrollbars();

	void setActive(bool active);
	void setText(const std::string& t);
	std::string getText() const;
	bool contains(sf::Vector2f point) const;
};