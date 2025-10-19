#include <iostream>
#include <string>
#include <memory>

class ElectronicComponent {
    
public:

    virtual void simulate() const = 0;
    virtual std::string type() const = 0;
    virtual ~ElectronicComponent() = default;
    
};

class Resistor : public ElectronicComponent {
    
public:

    Resistor(double r = 1000) : resistance(r) {}
    void simulate() const override 
    {
        std::cout << "Resistor" << std::endl;
    }
    std::string type() const override 
    {
        return "Resistor (" + std::to_string(resistance) + " Ohm)";
    }

private:

    double resistance;
    
};

class Capacitor : public ElectronicComponent {
    
public:

    Capacitor(double c = 0.001) : capacitance(c) {}
    void simulate() const override 
    {
        std::cout << "Capacitor" << std::endl;
    }
    std::string type() const override 
    {
        return "Capacitor (" + std::to_string(capacitance) + " F)";
    }

private:

    double capacitance;
    
};

class Transistor : public ElectronicComponent {
    
public:

    void simulate() const override 
    {
        std::cout << "Transistor" << std::endl;
    }
    std::string type() const override 
    {
        return "Transistor (BJT)";
    }
    
};

class ComponentFactory {
    
public:

    virtual std::unique_ptr<ElectronicComponent> createComponent() const = 0;
    virtual ~ComponentFactory() = default;

};

class ResistorFactory : public ComponentFactory {
    
public:

    std::unique_ptr<ElectronicComponent> createComponent() const override
    {
        return std::make_unique<Resistor>(2200);
    }
    
};

class CapacitorFactory : public ComponentFactory {
    
public:

    std::unique_ptr<ElectronicComponent> createComponent() const override
    {
        return std::make_unique<Capacitor>(0.00047);
    }
    
};

class TransistorFactory : public ComponentFactory {
    
public:

    std::unique_ptr<ElectronicComponent> createComponent() const override
    {
        return std::make_unique<Transistor>();
    }
    
};

int main()
{
    std::unique_ptr<ComponentFactory> rFactory = std::make_unique<ResistorFactory>();
    std::unique_ptr<ComponentFactory> cFactory = std::make_unique<CapacitorFactory>();
    std::unique_ptr<ComponentFactory> tFactory = std::make_unique<TransistorFactory>();

    auto r = rFactory->createComponent();
    auto c = cFactory->createComponent();
    auto t = tFactory->createComponent();

    std::cout << "Created: " << r->type() << std::endl; 
    r->simulate();
    std::cout << "\nCreated: " << c->type() << std::endl; 
    c->simulate();
    std::cout << "\nCreated: " << t->type() << std::endl; 
    t->simulate();
    
    return 0;
}