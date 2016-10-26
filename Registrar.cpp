#ifndef REGISTRAR_CPP
#define REGISTRAR_CPP

#include "Registrar.h"
#include "Student.h"
#include "DList.h"
#include "DNode.h"
#include "Window.h"
#include <iostream>
#include <cstdlib>
#include <cstddef>
using namespace std;

Registrar::Registrar() : open(-1) {}

Registrar::~Registrar(){
	if(line != NULL){
		delete line;
	}
	if(windows != NULL){
		delete windows;
	}
	if(waitTimes !=NULL){
		delete waitTimes;
	}
	if(windowTimes !=NULL){
		delete windowTimes;
	}
}

void Registrar::increaseWait(){
	GenQueue<Student>* templine = new GenQueue<Student>();
	Student tempStud;
	while(line.getSize() != 0)
	{	tempStud = line->peek();
	 	tempStud.increaseWait();
		templine->enqueue(tempStud);
		line->dequeue();
	}
	line = templine;
	templine = NULL;
	delete templine;
}

void Registrar::increaseIdle(){}

void Registrar::setWindow(const unsigned int& n)
{
    if(n <= 0)
    {
	cout << "Error Registrar::setWindow(). Cannot set negative or no windows." << endl;
	exit(1);
    }

    windows = new Window[n];
    open = n;
}

bool Registrar::openWindow()
{
    if(open <= 0)
    {
	cout << "Error Registrar::openWindow(). No windows set." << endl;
	exit(1);
    }

    for (int i = 0; i < open; ++i)
    {
	if (windows[i].empty())
	    return true;
    }
    return false;
}

void Registrar::occupyWindow(){}

void Registrar::emptyWindow(){}

#endif
