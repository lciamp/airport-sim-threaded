//
//  Lou Ciampanelli
//  Plane.cpp
//  airport
//

#include "Plane.hpp"

int Plane::plane_id_count = 0;


Plane::Plane(bool x)
{
    plane_id = plane_id_count++;
    set_status(x);
}

void Plane::set_status(bool x)
{
    status = x;
}

void Plane::set_plane_id(int x)
{
    plane_id = x;
}

void Plane::set_details(std::string x)
{
    details = x;
}


bool Plane::get_status(void)
{
    return status;
}

unsigned int Plane::get_plane_id(void) const
{
    return plane_id;
}

std::string Plane::get_details(void) const
{
    return details;
}

void Plane::take_off(void) const
{
    
}

void Plane::land(void) const
{
    
}