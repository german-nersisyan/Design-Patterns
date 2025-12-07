#include <iostream>
#include <string>

class Ability {
    
public:

    virtual void performAbility(const std::string& creatureName) = 0;
    
    virtual ~Ability() = default;
};

class FireBreathing : public Ability {
    
public:

    void performAbility(const std::string& creatureName) override
    {
        std::cout << creatureName << " breathes fire, burning everything in its path!" << std::endl;
    }
    
};

class Healing : public Ability {
    
public:

    void performAbility(const std::string& creatureName) override
    {
        std::cout << creatureName << " heals a wounded ally with magical light!" << std::endl;
    }
    
};

class Teleportation : public Ability {
    
public:

    void performAbility(const std::string& creatureName) override
    {
        std::cout << creatureName << " teleports across the world in the blink of an eye!" << std::endl;
    }
    
};

class Flight : public Ability {
    
public:

    void performAbility(const std::string& creatureName) override
    {
        std::cout << creatureName << " soars through the sky with majestic wings!" << std::endl;
    }
    
};

class Creature {

public:

    Creature(Ability* ability) : ability(ability) {}

    virtual void performAbility() = 0;
    
    virtual ~Creature() = default;
    
protected:

    Ability* ability;

};

class Dragon : public Creature {

public:

    Dragon(const std::string& name, Ability* ability) 
        : Creature(ability), name(name) {}

    void performAbility() override
    {
        ability->performAbility(name);
    }
    
private:

    std::string name;
    
};

class Unicorn : public Creature {

public:

    Unicorn(const std::string& name, Ability* ability) 
        : Creature(ability), name(name) {}

    void performAbility() override
    {
        ability->performAbility(name);
    }
    
private:

    std::string name;    

};

class Phoenix : public Creature {

public:
    Phoenix(const std::string& name, Ability* ability) 
        : Creature(ability), name(name) {}

    void performAbility() override
    {
        ability->performAbility(name);
    }
    
private:

    std::string name;

};

int main() {
    FireBreathing fireBreathingAbility;
    Healing healingAbility;
    Teleportation teleportationAbility;
    Flight flightAbility;

    Dragon dragon("Fire Dragon", &fireBreathingAbility);
    Unicorn unicorn("Healing Unicorn", &healingAbility);
    Phoenix phoenix("Flying Phoenix", &flightAbility);

    dragon.performAbility();
    unicorn.performAbility();
    phoenix.performAbility();

    std::cout << "\nThe Unicorn discovers new powers!" << std::endl;
    unicorn = Unicorn("Mystic Unicorn", &teleportationAbility);
    unicorn.performAbility();

    return 0;
}