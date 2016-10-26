#ifndef WINDOW_CPP
#define WINDOW_CPP

#include "Window.h"
#include "Student.h"
#include <cstdlib>

Window::Window():idleTime(0), isEmpty(true){}

Window::~Window(){delete s;}

bool Window::empty() const {return isEmpty;}

void Window::increaseIdle(){idleTime++;}

void Window::resetIdle(){idleTime = 0;}

void Window::occupy(const Student stu)
{
    s = stu;
    isEmpty = false;
}

void Window::remove()
{
    s.setWait(0);
    s.setArrival(0);
    s.setWindow(0);
    isEmpty = true;
}

unsigned int Window::getIdle() const{return idleTime;}

#endif //WINDOW_CPP
