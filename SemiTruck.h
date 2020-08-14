#pragma once

#include "Vehicle.h"

struct SemiTruck : public Vehicle
{
    SemiTruck(const std::string& s);

    //in-place construction from vehicle
    ~SemiTruck() override;
    SemiTruck(const SemiTruck&) = default;
    SemiTruck& operator=(const SemiTruck&) = default;

    void tailgate( int distance);

    void pullOver();
};
