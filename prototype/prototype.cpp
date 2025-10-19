#include <iostream>
#include <vector>

class Button {
    
public:

    virtual Button* clone() const = 0;
    virtual void render() const = 0;
    virtual ~Button() = default;

};

class RedButton : public Button {
    
public:

    Button* clone() const override
    {
        return new RedButton(*this);
    }
    
    void render() const override
    {
        std::cout << "Rendering a Red Button!" << std::endl;
    }

};

class BlueButton : public Button {
    
public:

    Button* clone() const override
    {
        return new BlueButton(*this);
    }
    
    void render() const override
    {
        std::cout << "Rendering a Blue Button!" << std::endl;
    }

};

int main()
{
    std::vector<Button*> uiButtons;
    
    RedButton redPrototype;
    BlueButton bluePrototype;
    
    uiButtons.push_back(redPrototype.clone());
    uiButtons.push_back(bluePrototype.clone());
    uiButtons.push_back(redPrototype.clone());
    
    for (auto btn : uiButtons) {
        btn->render();
    }
    
    for (auto btn : uiButtons) {
        delete btn;
    }
    
    return 0;
}