#ifndef CIRCLE_INTERFACE_
#define CIRCLE_INTERFACE_

//  Listing 2
/** @file CircleInterface.h */

class CircleInterface
{
public:
    /** Updates the radius of this Circle
     @param  newRadius the new radius for this Circle
     @pre    newRadius must be larger than zero
     @post   If newRadius is valid, the radius
             of this object is set to newRadius
             Otherwise, the Circle is not updated
     @return  True if this object is updated,
              and false otherwise. */
    virtual void setRadius(double newRadius) = 0;

    /** Gets the radius  of this Circle
     @return The radius of this Circle. */
    virtual double getRadius() const = 0;

    /** Gets the area  of this Circle
     @return The area of this Circle. */
    virtual double getArea() const = 0;

    /** Destroys this Circle and frees its assigned memory. */
    virtual ~CircleInterface() {}
};
#endif