#ifndef WINDOW_CPP
#define WINDOW_CPP

#include "Window.h"
#include "Student.h"
#include <cstdlib>

Window::Window():idleTime(0), isEmpty(true){}

Window::~Window(){}

bool Window::empty() const {return isEmpty;}

void Window::increaseIdle(){idleTime++;}

void Window::resetIdle(){idleTime = 0;}

void Window::occupy(const Student stu)//fills in a window with a student
{
    s = stu;
    isEmpty = false;
}
bool Window::timeup()//says if time is up
{
    if(s.getWindow() == 0)
    {
        return true;
    }
    else 
    {
        return false;
    }
}

void Window::decrementWindow()//decreases the studen'ts window time
{
    s.decreaseWindow();
}

void Window::remove()//removes a student out of a window
{
    s.setWait(0);
    s.setArrival(0);
    s.setWindow(0);
    isEmpty = true;
}

unsigned int Window::getIdle() const{return idleTime;}//accessor for Idle Time

#endif //WINDOW_CPP
