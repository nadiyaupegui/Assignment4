#ifndef WINDOW_H
#define WINDOW_H

#include "Student.h"

class Window
{
public:
    Window();
    ~Window();
    bool empty() const;
    void occupy(const Student stu);
    bool timeup(); //tells if the student's time is up
    void decrementWindow(); //decrements student window time
    void remove();
    unsigned int getIdle() const;
    void increaseIdle();
    void resetIdle();

private:
    Student s;
    unsigned int idleTime;
    bool isEmpty;
};

#endif 
