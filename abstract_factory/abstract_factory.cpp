#include <iostream>
#include <memory>

class Comedy {
    
public:

    virtual void play() = 0;
    virtual ~Comedy() = default;

};

class DisneyComedy : public Comedy {
    
public:

    void play() override {
        std::cout << "Disney Comedy" << std::endl;
    };

};

class ParamountComedy : public Comedy {
    
public:

    void play() override {
        std::cout << "Paramount Comedy" << std::endl;
    };

};

class Horror {
    
public:

    virtual void play() = 0;
    virtual ~Horror() = default;

};

class DisneyHorror : public Horror {
    
public:

    void play() override {
        std::cout << "Disney Horror" << std::endl;
    };

};

class ParamountHorror : public Horror {
    
public:

    void play() override {
        std::cout << "Paramount Horror" << std::endl;
    };

};

class MovieFactory {
    
public:

    virtual std::unique_ptr<Comedy> createComedy() = 0;
    virtual std::unique_ptr<Horror> createHorror() = 0;
    virtual ~MovieFactory() = default;

};

class DisneyFactory : public MovieFactory {
    
public:

    std::unique_ptr<Comedy> createComedy() override {
        return std::make_unique<DisneyComedy>();
    };

    std::unique_ptr<Horror> createHorror() override {
        return std::make_unique<DisneyHorror>();
    };

};

class ParamountFactory : public MovieFactory {
    
public:

    std::unique_ptr<Comedy> createComedy() override {
        return std::make_unique<ParamountComedy>();
    };

    std::unique_ptr<Horror> createHorror() override {
        return std::make_unique<ParamountHorror>();
    };

};

void makeMovieSet(MovieFactory& factory)
{
    auto comedy = factory.createComedy();
    auto horror = factory.createHorror();
    
    comedy->play();
    horror->play();
    
    std::cout << "-----------------------------------\n";
}

int main()
{
    std::cout << "Disney Studio Produces:\n";
    DisneyFactory disney;
    makeMovieSet(disney);
    
    std::cout << "Paramount Studio Produces:\n";
    ParamountFactory paramount;
    makeMovieSet(paramount);
}