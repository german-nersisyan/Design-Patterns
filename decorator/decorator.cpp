#include <iostream>
#include <memory>
#include <string>

class ChristmasTree {
    
public:

    virtual std::string decorate() = 0;
    virtual ~ChristmasTree() = default;

};

class SimpleTree : public ChristmasTree {
    
public:

    std::string decorate() override
    {
        return "Christmas Tree";
    }

};

class TreeDecorator : public ChristmasTree {
    
protected:

    std::shared_ptr<ChristmasTree> tree;
    
public:

    TreeDecorator(std::shared_ptr<ChristmasTree> t) :tree(t) {}
    
    std::string decorate() override
    {
        return tree->decorate();
    }

};


class LightsDecorator : public TreeDecorator {
    
public:

    LightsDecorator(std::shared_ptr<ChristmasTree> t) : TreeDecorator(t) {}
    
    std::string decorate() override
    {
        return TreeDecorator::decorate() + " with Lights";
    }

};

class OrnamentsDecorator : public TreeDecorator {
    
public:

    OrnamentsDecorator(std::shared_ptr<ChristmasTree> t) : TreeDecorator(t) {}
    
    std::string decorate() override
    {
        return TreeDecorator::decorate() + " with Ornaments";
    }

};

class TinselDecorator : public TreeDecorator {
    
public:

    TinselDecorator(std::shared_ptr<ChristmasTree> t) : TreeDecorator(t) {}
    
    std::string decorate() override
    {
        return TreeDecorator::decorate() + " with Tinsel";
    }

};

class StarDecorator : public TreeDecorator {
    
public:

    StarDecorator(std::shared_ptr<ChristmasTree> t) : TreeDecorator(t) {}
    
    std::string decorate() override
    {
        return TreeDecorator::decorate() + " with a Star on top";
    }

};

int main()
{
    std::shared_ptr<ChristmasTree> tree = std::make_shared<SimpleTree>();
    
    tree = std::make_shared<LightsDecorator>(tree);
    tree = std::make_shared<OrnamentsDecorator>(tree);
    tree = std::make_shared<TinselDecorator>(tree);
    tree = std::make_shared<StarDecorator>(tree);
    
    std::cout << tree->decorate() << std::endl;
    return 0;
}