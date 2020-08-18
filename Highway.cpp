#include "Highway.h"
#include "Vehicle.h"
#include "Car.h"
#include "Motorcycle.h"
#include "SemiTruck.h"
#include <algorithm>

struct Vehicle;


void Highway::changeSpeed(int newSpeed)
{
    speedLimit = newSpeed;
    for( auto* vehicle : vehicles )
    {
        vehicle->setSpeed(speedLimit);
    }
}

void Highway::addVehicleInternal(Vehicle* v)
{
    //assert(false);

    /*
    depending on the derived type, call the member function that doesn't evade the cops. 
    */
    //Check if the Vehicle Pointer v can be converted to a carPointer
    if (auto* carPointer = dynamic_cast<Car*>(v))
    {
        carPointer->closeWindows();
    }
   if (auto* motorcyclePointer = dynamic_cast<Motorcycle*>(v))
    {
        motorcyclePointer->lanesplitAndRace(250);
    }
    if (auto* truckPointer = dynamic_cast<SemiTruck*>(v))
    {
        truckPointer->tailgate(1);
    }

}

void Highway::removeVehicleInternal(Vehicle* v)
{
    //assert(false);

    if(auto* carPointer = dynamic_cast<Car*>(v))
    {
        carPointer->tryToEvade();
    }
    if(auto* motorcyclePointer = dynamic_cast<Motorcycle*>(v))
    {
        motorcyclePointer->tryToEvade();
    }
    if(auto* truckPointer = dynamic_cast<SemiTruck*>(v))
    {
        truckPointer->pullOver();
    }

    /*
    depending on the derived type, call the member function that tries to evade the cops. 

    trucks pull over, but cars and bikes try to evade!!
    */
    
}

void Highway::addVehicle(Vehicle* v)
{
    vehicles.push_back(v);
    addVehicleInternal(v);
}
void Highway::removeVehicle(Vehicle* v)
{
    vehicles.erase(std::remove(vehicles.begin(), 
                               vehicles.end(), 
                               v), 
                   vehicles.end());
    removeVehicleInternal(v);
}
