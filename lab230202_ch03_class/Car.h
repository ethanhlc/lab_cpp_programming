// Car.h file
// class Car declarations

#pragma once

class Car
{
    enum
    {
        ID_LEN = 20,
        MAX_SPD = 200,
        FUEL_STEP = 2,
        ACC_STEP = 10,
        BRK_STEP = 10
    };

private:
    char gamerID[ID_LEN];
    int fuelGauge;
    int curSpeed;

public:
    void InitMembers(const char* ID, int fuel);
    void ShowCarState();
    void Accel();
    void Break();
};
