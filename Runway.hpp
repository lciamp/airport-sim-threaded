//
//  Lou Ciampanelli
//  Runway.hpp
//  airport
//

#ifndef Runway_hpp
#define Runway_hpp

#include <stdio.h>
#include "Plane.hpp"
#include <vector>
#include <iostream>
#include <string>


class Runway
{
    public:
        Runway(std::string name);
    
        void take_off(Plane x);
    
        void land(Plane x);
    
    void display(void);
    
    private:
        std::string name;
        std::vector<Plane> landed;
        std::vector<Plane> taken_off;   
};




#endif /* Runway_hpp */