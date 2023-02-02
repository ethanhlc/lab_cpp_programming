// Car.cpp file
// class Car definitions

#include <iostream>
#include "Car.h"

using namespace std;

void Car::InitMembers(const char* ID, int fuel)
{
    strcpy_s(gamerID, ID);
    fuelGauge = fuel;
    curSpeed = 0;
}

void Car::ShowCarState()
{
    cout << "Owner ID: " << gamerID << endl;
    cout << "Fuel: " << fuelGauge << "%" << endl;
    cout << "Current Speed: " << curSpeed << "km/h" << endl << endl;
}

void Car::Accel()
{
    if (fuelGauge <= 0)
        return;
    else
        fuelGauge -= FUEL_STEP;

    if (curSpeed + ACC_STEP >= MAX_SPD)
    {
        curSpeed = MAX_SPD;
        return;
    }
    curSpeed += ACC_STEP;
}

void Car::Break()
{
    if (curSpeed < BRK_STEP)
    {
        curSpeed = 0;
        return;
    }
    curSpeed -= BRK_STEP;
}
