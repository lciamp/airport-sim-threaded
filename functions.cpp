//
//  Lou Ciampanelli
//  functions.cpp
//  airport
//

#include "functions.hpp"
#include <cmath>
#include <random>
#include <iostream>
#include <string>

int random(int min, int max)
{
    std::random_device randomd;
    std::mt19937 eng(randomd()); //seed
    std::uniform_int_distribution<> dist(min, max); //range
    
    return dist(eng);
}

/*
 -	If the wind direction is between 46 and 135 degrees, the takeoffs and landings will be on runway 9-27 in the direction from east to west.
 -	If the wind direction is between 136 and 225 degrees, the takeoffs and landings will be on runway 18-36 in the direction from south to north.
 -	If the wind direction is between 226 and 315 degrees, the takeoffs and landings will be on runway 9-27 in the direction from west to east.
 -	If the wind direction is between 316 and 360 or 1 and 45 degrees, the takeoffs and landings will be on runway 18-36 in the direction from north to south.
 */
std::string wind_string(int *x)
{
    std::string myString = "";
    
    if(*x >= 46 && *x <= 135)
    {
        myString = "runway 9-27 in the direction from east to west.";
        //std::cout << *x << std::endl;
    }
    else if(*x >= 136 && *x <= 225)
    {
        myString = "runway 18-36 in the direction from south to north.";
        //std::cout << *x << std::endl;
    }
    else if(*x >= 226 && *x <= 315)
    {
        myString = "runway 9-27 in the direction from west to east.";
        //std::cout << *x << std::endl;
    }
    else if((*x >= 316 && *x <= 360) || (*x >= 1 && *x <= 45))
    {
        myString = "runway 18-36 in the direction from north to south.";
        //std::cout << *x << std::endl;
    }
    
    return myString;
    
}