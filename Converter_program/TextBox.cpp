#include "TextBox.h"
#include <algorithm>

TextBox::TextBox(sf::Font& font, sf::Vector2f position, sf::Vector2f size)
	: cursorPos(0), blinkTime(0.f), showCaret(true), isActive(false),
	scrollOffsetX(0.f), scrollOffsetY(0.f), visibleWidth(size.x), visibleHeight(size.y),
	draggingV(false), draggingH(false)
{
	sfText.setFont(font);
	sfText.setCharacterSize(18);
	sfText.setFillColor(sf::Color::White);
	sfText.setPosition(position);

	box.setPosition(position);
	box.setSize(size);
	box.setFillColor(sf::Color(50, 50, 50));
	box.setOutlineColor(sf::Color::White);
	box.setOutlineThickness(2);

	caret.setSize({ 2.f, static_cast<float>(sfText.getCharacterSize()) });
	caret.setFillColor(sf::Color::White);
	caret.setPosition(sfText.getPosition());

	vScrollbar.setFillColor(sf::Color(180, 180, 180));
	vScrollbar.setPosition(position.x + size.x - 10, position.y);
	vScrollbar.setSize({ 10.f, size.y });

	hScrollbar.setFillColor(sf::Color(180, 180, 180));
	hScrollbar.setPosition(position.x, position.y + size.y - 10);
	hScrollbar.setSize({ size.x, 10.f });
}

void TextBox::handleEvent(const sf::Event& e, sf::Vector2f mousePos) {
	if (!isActive) return;

	if (e.type == sf::Event::MouseButtonPressed) {
		if (vScrollbar.getGlobalBounds().contains(mousePos)) { draggingV = true; dragOffset.y = mousePos.y - vScrollbar.getPosition().y; }
		if (hScrollbar.getGlobalBounds().contains(mousePos)) { draggingH = true; dragOffset.x = mousePos.x - hScrollbar.getPosition().x; }
	}
	if (e.type == sf::Event::MouseButtonReleased) { draggingV = false; draggingH = false; }

	if (e.type == sf::Event::MouseMoved) {
		if (draggingV) {
			float newY = mousePos.y - dragOffset.y;
			newY = std::max(box.getPosition().y, std::min(box.getPosition().y + box.getSize().y - vScrollbar.getSize().y, newY));
			vScrollbar.setPosition(vScrollbar.getPosition().x, newY);
			float textHeight = std::max(sfText.getLocalBounds().height, visibleHeight);
			scrollOffsetY = ((newY - box.getPosition().y) / (box.getSize().y - vScrollbar.getSize().y)) * (textHeight - visibleHeight);
		}
		if (draggingH) {
			float newX = mousePos.x - dragOffset.x;
			newX = std::max(box.getPosition().x, std::min(box.getPosition().x + box.getSize().x - hScrollbar.getSize().x, newX));
			hScrollbar.setPosition(newX, hScrollbar.getPosition().y);
			float textWidth = std::max(sfText.getLocalBounds().width, visibleWidth);
			scrollOffsetX = ((newX - box.getPosition().x) / (box.getSize().x - hScrollbar.getSize().x)) * (textWidth - visibleWidth);
		}
	}

	if (e.type == sf::Event::TextEntered) {
		if (e.text.unicode >= 32) {
			text.insert(cursorPos, 1, static_cast<char>(e.text.unicode));
			cursorPos++;
		}
	}
	else if (e.type == sf::Event::KeyPressed) {
		switch (e.key.code) {
		case sf::Keyboard::BackSpace:
			if (cursorPos > 0) { text.erase(cursorPos - 1, 1); cursorPos--; }
			break;
		case sf::Keyboard::Delete:
			if (cursorPos < text.size()) text.erase(cursorPos, 1);
			break;
		case sf::Keyboard::Left:
			if (cursorPos > 0) cursorPos--;
			break;
		case sf::Keyboard::Right:
			if (cursorPos < text.size()) cursorPos++;
			break;
		case sf::Keyboard::Enter:
			text.insert(cursorPos, "\n"); cursorPos++;
			break;
		case sf::Keyboard::C:
			if (e.key.control) sf::Clipboard::setString(text);
			break;
		case sf::Keyboard::V:
			if (e.key.control) {
				std::string clip = sf::Clipboard::getString();
				text.insert(cursorPos, clip);
				cursorPos += clip.size();
			}
			break;
		default: break;
		}
	}

	sfText.setString(text);
	caret.setPosition(sfText.findCharacterPos(cursorPos));
	updateScrollbars();
}

void TextBox::update(float dt) {
	if (!isActive) return;
	blinkTime += dt;
	if (blinkTime >= 0.5f) { showCaret = !showCaret; blinkTime = 0.f; }
}

void TextBox::draw(sf::RenderWindow& window) {
	window.draw(box);

	sf::View prevView = window.getView();

	sf::View view;
	view.setViewport(sf::FloatRect(
		box.getPosition().x / window.getSize().x,
		box.getPosition().y / window.getSize().y,
		box.getSize().x / window.getSize().x,
		box.getSize().y / window.getSize().y
	));
	view.setSize(box.getSize());
	view.setCenter(box.getPosition() + box.getSize() / 2.f);
	window.setView(view);

	sf::Text drawText = sfText;
	drawText.move(-scrollOffsetX, -scrollOffsetY);
	window.draw(drawText);

	if (isActive && showCaret) {
		sf::RectangleShape drawCaret = caret;
		drawCaret.move(-scrollOffsetX, -scrollOffsetY);
		window.draw(drawCaret);
	}

	window.setView(prevView);

	window.draw(vScrollbar);
	window.draw(hScrollbar);
}

void TextBox::scroll(float deltaX, float deltaY) {
	scrollOffsetX += deltaX; scrollOffsetY += deltaY;
	scrollOffsetX = std::max(0.f, scrollOffsetX);
	scrollOffsetY = std::max(0.f, scrollOffsetY);

	float textWidth = std::max(sfText.getLocalBounds().width, visibleWidth);
	float textHeight = std::max(sfText.getLocalBounds().height, visibleHeight);

	if (scrollOffsetX > textWidth - visibleWidth) scrollOffsetX = std::max(0.f, textWidth - visibleWidth);
	if (scrollOffsetY > textHeight - visibleHeight) scrollOffsetY = std::max(0.f, textHeight - visibleHeight);

	updateScrollbars();
}

void TextBox::updateScrollbars() {
	float textWidth = std::max(sfText.getLocalBounds().width, visibleWidth);
	float textHeight = std::max(sfText.getLocalBounds().height, visibleHeight);

	vScrollbar.setSize({ 10.f, visibleHeight * (visibleHeight / textHeight) });
	vScrollbar.setPosition(box.getPosition().x + visibleWidth - 10,
		box.getPosition().y + (scrollOffsetY / (textHeight - visibleHeight)) * (visibleHeight - vScrollbar.getSize().y));

	hScrollbar.setSize({ visibleWidth * (visibleWidth / textWidth), 10.f });
	hScrollbar.setPosition(box.getPosition().x + (scrollOffsetX / (textWidth - visibleWidth))*(visibleWidth - hScrollbar.getSize().x),
		box.getPosition().y + visibleHeight - 10);
}

void TextBox::setActive(bool active) { isActive = active; }
void TextBox::setText(const std::string& t) { text = t; cursorPos = t.size(); sfText.setString(text); caret.setPosition(sfText.findCharacterPos(cursorPos)); updateScrollbars(); }
std::string TextBox::getText() const { return text; }
bool TextBox::contains(sf::Vector2f point) const { return box.getGlobalBounds().contains(point); }