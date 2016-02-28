//
//  Lou Ciampanelli
//  threads.hpp
//  airport
//

#ifndef threads_hpp
#define threads_hpp

#include <stdio.h>
#include "Plane.hpp"
#include "Runway.hpp"
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <queue>

// take off thread
void take_off_thread(int *wind, std::queue<Plane> *take_off, Runway *north_south, Runway *east_west);

// land thread
void land_thread(int *wind, std::queue<Plane> *land, Runway *north_south, Runway *east_west);

// wind thread
void wind_thread(int *wind);


void plane_generator(std::queue<Plane> *land, std::queue<Plane> *take_off);

#endif /* threads_hpp */
