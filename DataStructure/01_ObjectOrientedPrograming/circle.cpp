#include <iostream>
using namespace std;

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

class Circle : public CircleInterface
{
public:
	Circle();
	void setRadius(double newRadius);
	double getRadius() const;
	double getArea() const;
private:
	double radius;
};

Circle::Circle()
{
	radius = 1.0;
}

void Circle::setRadius(double newRadius)
{
	if (newRadius > 0.0)
	{
		radius = newRadius;
	}
	// else leave this circle unchanged
}

double Circle::getRadius() const
{
	return radius;
}

double Circle::getArea() const
{
	return 3.14 * radius * radius;
}


class SuperCircle : public CircleInterface
{
  public:
	SuperCircle();
	void setRadius(double newRadius);
	double getRadius() const;
	double getArea() const;
  private:
	double radius;
};

SuperCircle::SuperCircle()
{
	radius = 10.0;
}

void SuperCircle::setRadius(double newRadius)
{
	if (newRadius > 0.0)
	{
		radius = newRadius;
	}
	// else leave this circle unchanged
}

double SuperCircle::getRadius() const
{
	return radius;
}

double SuperCircle::getArea() const
{
	return 9.14 * radius * radius;
}


int main()
{
	Circle theCircle;
	
	cout << "Intital state of the circle" << endl;
	cout << "    radius = " << theCircle.getRadius() << endl;
	cout << "    area   = " << theCircle.getArea() << endl << endl;
	
	theCircle.setRadius(2.0);
	cout << "Current state of the circle" << endl;
	cout << "    radius = " << theCircle.getRadius() << endl;
	cout << "    area   = " << theCircle.getArea() << endl << endl;


	SuperCircle theSuperCircle;
	
	cout << "Intital state of the super circle" << endl;
	cout << "    super radius = " << theSuperCircle.getRadius() << endl;
	cout << "    super area   = " << theSuperCircle.getArea() << endl << endl;
	
	theSuperCircle.setRadius(2.0);
	cout << "Current state of the circle" << endl;
	cout << "    super radius = " << theSuperCircle.getRadius() << endl;
	cout << "    super area   = " << theSuperCircle.getArea() << endl << endl;
	
	return 0;
}