//
//  Lou Ciampanelli
//  threads.cpp
//  airport
//

#include "threads.hpp"
#include "functions.hpp"
#include "Plane.hpp"
#include "Runway.hpp"
#include <mutex>
#include <iostream>
#include <queue>

std::mutex my_mutex;

int total_planes = 0; // count of the total planes, initalized to 0
int max_plane = 20; // max amount of planes the generator should generate


// take off thread
void take_off_thread(int *wind, std::queue<Plane> *take_off, Runway *north_south, Runway *east_west)
{
    while(total_planes <= max_plane)
    {
        if(take_off->size() == 0){}
        else
        {
            //std::lock_guard<std::mutex> guard(my_mutex);
            
            my_mutex.lock();
            
            std::cout << "Plane " << take_off->front().get_plane_id()
            << " took off from " << wind_string(wind) << " Wind was: "
            << *wind << std::endl;
            
            take_off->front().set_details(wind_string(wind));

            if((*wind >= 46 && *wind <= 135) || (*wind >= 226 && *wind <= 315))
            {
                east_west->take_off(take_off->front());
                take_off->pop();
            }
            else
            {
                north_south->take_off(take_off->front());
                take_off->pop();
            }
            total_planes++;
            
            my_mutex.unlock();
        }
        //sleep(4);
    }
}

// land thread
void land_thread(int *wind, std::queue<Plane> *land, Runway *north_south, Runway *east_west)
{
    while(total_planes <= max_plane)
    {
        if(land->size() == 0){}
        else
        {
            //std::lock_guard<std::mutex> guard(my_mutex);
            
            my_mutex.lock();
            
            std::cout << "Plane " << land->front().get_plane_id()
            << " landed on " << wind_string(wind) << " Wind was: "
            << *wind << std::endl;
            
            land->front().set_details(wind_string(wind));
            
            if((*wind >= 46 && *wind <= 135) || (*wind >= 226 && *wind <= 315))
            {
                east_west->land(land->front());
                land->pop();
            }
            else
            {
                north_south->land(land->front());
                land->pop();
            }
            total_planes++;
            
            my_mutex.unlock();
        }
        //sleep(3);
    }
}

// wind thread
void wind_thread(int *wind)
{
    while(total_planes < max_plane )
    {
        std::lock_guard<std::mutex> guard(my_mutex);
        *wind = random(1, 360);
    }
}

// plane generator thread
void plane_generator(std::queue<Plane> *land, std::queue<Plane> *take_off)
{
    while(total_planes < max_plane)
    {
        if(total_planes == 20)
            break;
        // decides which queue the plane should be placed in, no real logic here
        // I just chose false for landing and true for taking off
        bool stat = random(0, 1);
        
        // create new plane, pass it's take off/landing status
        Plane myPlane = *new Plane(stat);
        
        // keep both queues at a max of 10 planes
        while(land->size() >= 10 && take_off->size() >= 10);
        
        // lock the take off / landing queue
        //std::lock_guard<std::mutex> guard(my_mutex);
        
        my_mutex.lock();
        
        // figure out if the plane should be put in the landing or take off queue
        if(myPlane.get_status() == false)
        {
            if(land->size() == 10){}
            else
            {
                land->push(myPlane);
                std::cout << "Plane " << myPlane.get_plane_id()
                << " entered the airspace." << std::endl;
            }
        }
        else
        {
            if(take_off->size() == 10){}
            else
            {
                take_off->push(myPlane);
                std::cout << "Plane " << myPlane.get_plane_id()
                << " would like to take off. " << std::endl;
            }
        }
        //total_planes++;
        my_mutex.unlock();
        //sleep(1);
    }

}