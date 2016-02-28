//
//  Lou Ciampanelli
//  Plane.hpp
//  airport
//

#ifndef Plane_hpp
#define Plane_hpp

#include <stdio.h>
#include <iomanip>


class Plane
{
    
public:
    
    // default constructor, the bool if is it's in the air or on the ground
    Plane(bool);
    
    //~Plane(void);
    
    void set_status(bool);
    
    void set_plane_id(int);
    
    void set_details(std::string);
    
    bool get_status(void);
    
    unsigned int get_plane_id(void) const;
    
    std::string get_details(void) const;
    
    void take_off(void) const;
    
    void land(void) const;
    
    
    
    
private:
    static int plane_id_count;
    int plane_id;
    bool status;
    std::string details;
};

#endif /* Plane_hpp */
