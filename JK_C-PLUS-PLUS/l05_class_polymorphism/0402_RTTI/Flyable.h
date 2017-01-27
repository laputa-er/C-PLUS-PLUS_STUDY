#ifndef FLYABLE_H_
#define FLYABLE_H_

class Flyable
{
public:
	virtual void takeOff() = 0;
	virtual void land() = 0;
};

#endif