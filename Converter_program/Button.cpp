#include "Button.h"

Button::Button(sf::Font& font,
	const std::string& text,
	sf::Vector2f position) {
	box.setSize({ 220.f, 50.f });
	box.setPosition(position);
	box.setFillColor(sf::Color(60, 120, 220));
	box.setOutlineThickness(2);
	box.setOutlineColor(sf::Color::Black);

	label.setFont(font);
	label.setString(text);
	label.setCharacterSize(20);
	label.setFillColor(sf::Color::White);

	sf::FloatRect textBounds = label.getLocalBounds();
	label.setOrigin(
		textBounds.left + textBounds.width / 2.f,
		textBounds.top + textBounds.height / 2.f
	);
	label.setPosition(
		position.x + box.getSize().x / 2.f,
		position.y + box.getSize().y / 2.f
	);
}

bool Button::isClicked(sf::Vector2f mouse) const {
	return box.getGlobalBounds().contains(mouse);
}

bool Button::isHovered(sf::Vector2f mouse) const {
	return box.getGlobalBounds().contains(mouse);
}

void Button::setSelected(bool value) {
	selected = value;
}

bool Button::isSelected() const {
	return selected;
}

void Button::draw(sf::RenderWindow& window, sf::Vector2f mouse) {
	if (selected)
		box.setFillColor(sf::Color(40, 180, 120));
	else if (isHovered(mouse))
		box.setFillColor(sf::Color(80, 140, 255));
	else
		box.setFillColor(sf::Color(60, 120, 220));

	window.draw(box);
	window.draw(label);
}