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
    void increaseWait();
    void decreaseWindow();    
    void setWindow(const unsigned int& n);
    bool openWindow();
    void occupyWindow();
    void emptyWindow();
    void increaseIdle();
    unsigned int getSize() const;

private:
    GenQueue<Student*>* line;
    Window* windows;
    unsigned int size;
    DList<int>* waitTimes;
    DList<int>* windowTimes;
};

#endif //REGISTRAR_H
