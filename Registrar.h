#ifndef REGISTRAR_H
#define REGISTRAR_H

#include "DList.h"
#include "Student.h"
#include "GenQueue.h"
#include "Window.h"

class Registrar
{
public:
    Registrar();
    ~Registrar();
    void increaseWait(int c);
    //takes in a int value for clock ticks
    //goes through the line and increases student wait times if they have arrived
    //they have arrived if arrival>clock time
    void decreaseWindow();
    //decreases each student's time at window
    void setWindow(const unsigned int& n);
    //set the size of the windows array
    bool openWindow(); //tells if there is one open window
    void occupyWindow();
    //fills all empty windows with students
    //sends idle times to windowTimes list
    //resets idle times
    void emptyWindow(); //kicks student out of window, put his wait time in the list
    void increaseIdle(); //goes through the windows and increments idle time if empty
    unsigned int getSize() const;
    //gets the number of windows open

private:
    GenQueue<Student>* line; //line 
    Window* windows;//array of windows available for students
    unsigned int size;
    DList<int>* waitTimes; //wait times size of # of students/queue.size
    DList<int>* windowTimes; //idle times for windows
};

#endif //REGISTRAR_H
