#include <SFML/Graphics.hpp>
#include "TextBox.h"
#include "Button.h"
#include "FileDialog.h"
#include "ConverterFactory.h"
#include <fstream>
#include <sstream>
#include <iostream>

int main() {
	sf::RenderWindow window({ 1200,650 }, "Universal File Converter");
	window.setFramerateLimit(60);

	sf::Font font;
	if (!font.loadFromFile("arial.ttf")) return 1;

	TextBox input(font, { 20,100 }, { 550,500 });
	TextBox output(font, { 630,100 }, { 550,500 });

	Button browse(font, "Browse", { 20,20 });
	Button csvToJson(font, "CSV -> JSON", { 200,20 });
	Button jsonToCsv(font, "JSON -> CSV", { 380,20 });
	Button convert(font, "Convert", { 560,20 });
	Button save(font, "Save Output", { 720,20 });
	Button clear(font, "Clear", { 900,20 });

	ConvertType mode = ConvertType::CSV_TO_JSON;
	csvToJson.setSelected(true);
	jsonToCsv.setSelected(false);

	sf::Clock clock;

	while (window.isOpen()) {
		sf::Event e;
		sf::Vector2f mousePos(sf::Mouse::getPosition(window));

		while (window.pollEvent(e)) {
			if (e.type == sf::Event::Closed) window.close();

			if (e.type == sf::Event::MouseButtonPressed) {
				input.setActive(input.contains(mousePos));
				output.setActive(output.contains(mousePos));
			}

			input.handleEvent(e, mousePos);
			output.handleEvent(e, mousePos);

			if (e.type == sf::Event::MouseWheelScrolled) {
				float scrollAmount = e.mouseWheelScroll.delta*20.f;
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)) {
					if (input.contains(mousePos)) input.scroll(-scrollAmount, 0);
					if (output.contains(mousePos)) output.scroll(-scrollAmount, 0);
				}
				else {
					if (input.contains(mousePos)) input.scroll(0, -scrollAmount);
					if (output.contains(mousePos)) output.scroll(0, -scrollAmount);
				}
			}

			if (e.type == sf::Event::MouseButtonPressed) {
				if (browse.isClicked(mousePos)) {
					std::string path = openFileDialog();
					if (!path.empty()) {
						std::ifstream f(path);
						std::stringstream buffer; buffer << f.rdbuf();
						input.setText(buffer.str());
					}
				}
				if (csvToJson.isClicked(mousePos)) {
					mode = ConvertType::CSV_TO_JSON;
					csvToJson.setSelected(true);
					jsonToCsv.setSelected(false);
				}
				if (jsonToCsv.isClicked(mousePos)) {
					mode = ConvertType::JSON_TO_CSV;
					jsonToCsv.setSelected(true);
					csvToJson.setSelected(false);
				}
				if (convert.isClicked(mousePos)) {
					try {
						auto conv = ConverterFactory::create(mode);
						std::string result = conv->convertText(input.getText());
						if (result.empty()) output.setText("Conversion produced empty output");
						else output.setText(result);
					}
					catch (const std::exception& ex) {
						output.setText(std::string("Error: ") + ex.what());
					}
				}
				if (save.isClicked(mousePos)) {
					std::string filename = (mode == ConvertType::CSV_TO_JSON) ? "output.json" : "output.csv";
					std::ofstream out(filename);
					if (out.is_open()) {
						out << output.getText();
						out.close();
						output.setText(output.getText() + "\n\nSaved to " + filename);
					}
				}
				if (clear.isClicked(mousePos)) {
					input.setText("");
					output.setText("");
				}
			}
		}

		float dt = clock.restart().asSeconds();
		input.update(dt);
		output.update(dt);

		window.clear(sf::Color(35, 35, 35));
		input.draw(window);
		output.draw(window);
		browse.draw(window, mousePos);
		csvToJson.draw(window, mousePos);
		jsonToCsv.draw(window, mousePos);
		convert.draw(window, mousePos);
		save.draw(window, mousePos);
		clear.draw(window, mousePos);
		window.display();
	}

	return 0;
}