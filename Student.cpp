#ifndef STUDENT_CPP
#define STUDENT_CPP

#include "Student.h"
#include <iostream>
#include <cstdlib>
using namespace std;

Student::Student():wait(0), window(0), arrival(-1){}
//overloaded constructor
Student::Student(const unsigned int& w, const unsigned int& win, const unsigned int& a):wait(w), window(win), arrival(a){}

Student::~Student(){}
//accessor for time at window
void Student::setWindow(const unsigned int t)
{
    if (t >= 0)
	window = t;
    else
    {
	cout << "Error Student::setWindow(). Negative time inputed." << endl;
	exit(1);
    }
}
//accessor for wait time
void Student::setWait(const unsigned int t)
{
    if (t >= 0)
        wait = t;
    else
    {
        cout << "Error Student::setWait(). Negative time inputed." << endl;
        exit(1);
    }

}
//increments wait time
void Student::increaseWait(){wait++;}

void Student::decreaseWindow(){window--;}
//mutator for arrival time
void Student::setArrival(const unsigned int& t)
{
    if (t >= 0)
	arrival = t;
    else
    {
	cout << "Error Student::setArrival. Negative time inputed." << endl;
	exit(1);
    }
}
//accessors
unsigned int Student::getWait() const{return wait;}

unsigned int Student::getWindow() const{return window;}

unsigned int Student::getArrival() const{return arrival;}
//equals operator
bool Student::operator ==(const Student& other)
{
    return ((wait == other.wait) && (window == other.window) && (arrival == other.arrival));
}
//not equals operator
bool Student::operator !=(const Student& other)
{
    return ((wait != other.wait) || (window != other.window) || (arrival != other.arrival));
}
//assignment operator
void Student::operator =(const Student& stu)
{
    wait = stu.wait;
    arrival = stu.arrival;
    window = stu.window;
}
#endif
