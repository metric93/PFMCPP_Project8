#pragma once
#include "Vehicle.h"

struct Car : public Vehicle
{
    Car(const std::string& s);

    //in-place construction from vehicle
    ~Car() override;
    Car(const Car&) = default;
    Car& operator=(const Car&) = default;


    void closeWindows();
    void tryToEvade() override;
};
