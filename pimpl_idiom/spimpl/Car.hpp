#pragma once

#include <memory>
#include <string>

class CarImpl;

class Car {

public:

    Car(const std::string& model);
    ~Car();

    void startEngine() const;
    void drive() const;

private:

    std::unique_ptr<CarImpl> pImpl;

};