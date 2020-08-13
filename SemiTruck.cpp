#include "SemiTruck.h"

SemiTruck::SemiTruck(const std::string& s) : Vehicle (s);

void SemiTruck::tailgate(int distance)
{
    std::cout << name << (distance > 1 ? "Coming for ya!" : "Honk, Honk, Get out of the Way!") << std::endl;
}