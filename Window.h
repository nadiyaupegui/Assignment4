#ifndef WINDOW_H
#define WINDOW_H

#include "Student.h"

class Window
{
public:
    Window();
    ~Window();
    bool empty() const; //Returns true if s is empty
    void occupy(const Student stu); //Sets student member variable
    bool timeup(); //tells if the student's time is up
    void decrementWindow(); //decrements student window time
    void remove(); //Sets student to window
    unsigned int getIdle() const;
    void increaseIdle(); //Increases idle time by 1
    void resetIdle(); //Sets idle time to 0

private:
    Student s;
    unsigned int idleTime;
    bool isEmpty;
};

#endif 
