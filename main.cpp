//
//  Lou Ciampanelli
//  main.cpp
//  airport
//


#include <iostream>
#include <thread>
#include <queue>
#include <time.h>
#include "threads.hpp"

#include "Plane.hpp"
#include "Runway.hpp"

//std::atomic<int> x;
//std::ref(x);

int main(int argc, const char * argv[])
{
    
    clock_t timer_1, timer_2;
    timer_1 = clock();
    
    std::queue<Plane> take_off_queue;
    std::queue<Plane> land_queue;
    int wind;
    Runway north_south("Runway 18-36");
    Runway east_west("Runway 9-27");
    
    
    std::thread t1(&plane_generator, &land_queue, &take_off_queue);
    std::thread t2(&wind_thread, &wind);
    std::thread t3(&take_off_thread, &wind, &take_off_queue, &north_south, &east_west);
    std::thread t4(&land_thread, &wind, &land_queue, &north_south, &east_west);
    
    
    // JOIN THREADS TO MAIN: ---------------------------------------------------
    

    // Plane Generator Thread
    if(t1.joinable())
    {
        t1.join();
    }
    else
    {
        std::cout << "Plane Generator Thread Could Not Join Main" << std::endl;
    }
    
    // Wind Generator Thread
    if(t2.joinable())
    {
        t2.join();
    }
    else
    {
        std::cout << "Wind Thread Could Not Join Main" << std::endl;
    }

    // Take Off Thread
    if(t3.joinable())
    {
        t3.join();
    }
    else
    {
        std::cout << "Take Off Thread Could Not Join Main" << std::endl;
    }
    
    // Land Thread
    if(t4.joinable())
    {
        t4.join();
    }
    else
    {
        std::cout << "Landing Thread Could Not Join Main" << std::endl;
    }

    // END OF JOINING THREADS --------------------------------------------------

    
    // DISPLAY
    
    std::cout << "\n########### Display ##########\n\n";
    
    east_west.display();
    
    std::cout << std::endl;
    
    north_south.display();
    
    
    timer_2 = clock();
    float diff = ((float)timer_2-(float)timer_1);
    diff = diff / CLOCKS_PER_SEC;
    std::cout << "Total Time: " << diff << " seconds.\n\n";
    
    return 0;
}
