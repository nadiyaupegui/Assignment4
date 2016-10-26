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

Registrar::Registrar() : size(-1) {}

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

void Registrar::increaseWait(int c){//goes through the line, increments everyones wait time
	GenQueue<Student>* templine = new GenQueue<Student>();
	Student tempStud;
	while(line -> getSize() != 0)
	{	
		tempStud = line->peek();
		if(tempStud.getArrival()>c)
		//if the arrival time is after the clock time
		{
			tempStud.increaseWait();
		}
		templine->enqueue(tempStud);
		line->dequeue();
	}
	line = templine;
	//switch pointers
	templine = NULL;
	delete templine;
}

void Registrar::increaseIdle() // goes through windows and increases idle time if empty
{
	for(int i = 0; i<size; ++i){
		if(windows[i].empty()){
			windows[i].increaseIdle();
		}
	}
}

void Registrar::setWindow(const unsigned int& n)
{
    if(n <= 0)
    {
	cout << "Error Registrar::setWindow(). Cannot set negative or no windows." << endl;
	exit(1);
    }

    windows = new Window[n];
    size = n;
}

bool Registrar::openWindow()
{
    if(size <= 0)
    {
	cout << "Error Registrar::openWindow(). No windows set." << endl;
	exit(1);
    }

    for (int i = 0; i < size; ++i)
    {
	if (windows[i].empty())
	    return true;
    }
    return false;
}

void Registrar::occupyWindow(){
	for(int i = 0; i < size; ++i)
	{
		if(windows[i].empty())
		{
			windows[i].occupy(line->peek())
			waitTimes.addBack(line->peek()->getWait());
			//add student timew to wait times list
			line->dequeue;
			//fills empty windows with students
			windowTimes.addBack(windows[i].getIdle())
			//adds idletimes to window times list
			windowTimes.resetIdle();
		}
	}
}

void Registrar::emptyWindow(){//need to add code!!!
	for(int i=0; i < size; ++i) //goes through every window
	{
		if(windows[i].timeup)//if student is out of window time
		{
			window[i].remove();

		}
	}
}

#endif
