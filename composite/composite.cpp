#include <iostream>
#include <string>
#include <vector>
#include <memory>

class Node {
    
public:

    virtual void render(int indent = 0) const = 0;
    virtual void addChild(std::shared_ptr<Node> child) {}
    virtual ~Node() = default;

};

class TextNode : public Node {
    
private:

    std::string text;
    
public:

    TextNode(const std::string& t) : text(t) {}
    void render(int indent = 0) const override
    {
        std::cout << std::string(indent, ' ') << text << std::endl;
    }

};

class ElementNode : public Node {
    
private:

    std::string tagName;
    std::vector<std::shared_ptr<Node>> children;
    
public:

    ElementNode(const std::string& tag) : tagName(tag) {}
    void addChild(std::shared_ptr<Node> child) override
    {
        children.push_back(child);
    }
    void render(int indent = 0) const override 
    {
        std::cout << std::string(indent, ' ') << "<" << tagName << ">" << std::endl;
        for(auto& child : children) {
            child->render(indent + 2);
        }
        std::cout << std::string(indent, ' ') << "</" << tagName << ">" << std::endl;
    }

};

int main()
{
    auto html = std::make_shared<ElementNode>("html");
    auto body = std::make_shared<ElementNode>("body");
    auto div = std::make_shared<ElementNode>("div");
    auto p = std::make_shared<ElementNode>("p");
    
    div->addChild(std::make_shared<TextNode>("Hello, World!"));
    p->addChild(std::make_shared<TextNode>("This is a paragraph."));
    body->addChild(div);
    body->addChild(p);
    html->addChild(body);
    
    html->render();
    
    return 0;
}