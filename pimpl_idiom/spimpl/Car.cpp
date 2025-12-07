#include "Car.hpp"
#include <iostream>

class CarImpl {

public:

    CarImpl(const std::string& model) : model_(model), engineStatus(false)
    {
        std::cout << "Initializing car: " << model_ << std::endl;
        engineStatus = false;
    }

    void startEngine()
    {
        engineStatus = true;
        std::cout << "Engine started" << std::endl;
    }

    void drive() const
    {
        if (engineStatus)
            std::cout << "Car is driving..." << std::endl;
        else
            std::cout << "Cannot drive, engine is off!" << std::endl;
    }

private:

    std::string model_;
    bool engineStatus;

};

Car::Car(const std::string& model)
    : pImpl(std::make_unique<CarImpl>(model)) {}

Car::~Car() = default;

void Car::startEngine() const
{
    pImpl->startEngine();
}

void Car::drive() const
{
    pImpl->drive();
}