//
//  Lou Ciampanelli
//  Runway.cpp
//  airport
//

#include "Runway.hpp"
#include <vector>

// vector of planes landed and taken off

// land and take off methods

// land and take off methods take planes as an arguement.
// pop them off the land / take off queues
// but add them to the runways vectors

// I guess pass the queues to the runways ... or pass the threads the runways and the queues

// unlock the queues and lock the runways.

Runway::Runway(std::string x)
{
    name = x;
    landed = {};
    taken_off = {};
}

void Runway::take_off(Plane x)
{
    taken_off.push_back(x);
}

void Runway::land(Plane x)
{
    landed.push_back(x);
}

void Runway::display(void)
{
    std::cout << name << ":\n\n";
    std::cout << "\tLanded: " << landed.size() << std::endl;
    
    for (int i = 0; i < landed.size(); i++)
    {
        std::cout << "\t\tPlane #" << landed[i].get_plane_id() << " landed on " << landed[i].get_details() << std::endl;
    }
    
    std::cout << "\tTook off: " << taken_off.size() << std::endl;
    
    for (int i = 0; i < taken_off.size(); i++)
    {
        std::cout << "\t\tPlane #" << taken_off[i].get_plane_id() << " took off on " << taken_off[i].get_details() << std::endl;
    }
    std::cout << std::endl;
}

