#ifndef REGISTRAR_CPP
#define REGISTRAR_CPP

#include "Registrar.h"
#include "Student.h"
#include "DList.h"
#include "DNode.h"
#include "Window.h"
#include "StatStuff.h"
#include <iostream>
#include <cstdlib>
#include <cstddef>
#include <fstream>
#include <algorithm>

using namespace std;

Registrar::Registrar() : size(-1) 
{
    line = new GenQueue<Student>();
    waitTimes = new DList<int>();
    windowTimes = new DList<int>();
}

Registrar::~Registrar(){
	
	if(line != NULL){
		delete line;
	}

	if(windows != NULL){
		[]delete windows;
	}

	if(waitTimes !=NULL){
		delete waitTimes;
	}

	if(windowTimes !=NULL){
		delete windowTimes;
	}

}

void Registrar::increaseWait(int c)//goes through the line, increments everyones wait time
{
	GenQueue<Student>* templine = new GenQueue<Student>();
	Student tempStud;
	while(line -> getSize() != 0)
	{	
		tempStud = line -> peek();
		if(tempStud.getArrival() > c)
		//if the arrival time is after the clock time
		{
			tempStud.increaseWait();
		}
		templine -> enqueue(tempStud);
		line -> dequeue();
	}
	line = templine;
	//switch pointers
	templine = NULL;
	delete templine;
}

void Registrar::decreaseWindow()
//goes through the window array and decreases everyone's window time
{
	for(int	i = 0; i < size; ++i)//goes through the window array
	{
		if(!windows[i].empty())//if the window isn't empty
		{
			windows[i].decrementWindow();//decrease the time of the student at window
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

bool Registrar::openWindow() //says if there exists an open window
{
	//if there are no windows return error
    if(size <= 0)
    {
	cout << "Error Registrar::openWindow(). No windows set." << endl;
	exit(1);
    }

	//go through each window and see if there is at least one open one
    for (int i = 0; i < size; ++i)
    {
	if (windows[i].empty())
	    return true;
    }
    return false;
}

bool Registrar::allOpen() //says if all windows are open
{
	for (int i = 0; i < size; ++i)
	{
		if (!windows[i].empty())
			return false;
	}
	
	return true;
}

void Registrar::occupyWindow(int c){
	//puts students in al the empty windows
	for(int i = 0; i < size; ++i)
	{
		//checks condition that the window is empty, line has people and the people have arrived
		if((windows[i].empty()) && (line -> getSize() != 0) && (line -> peek().getArrival() <= c))
		{
			windows[i].occupy(line -> peek());
			waitTimes -> addBack(line->peek().getWait());
			//add student timew to wait times list
			line->dequeue();
			//fills empty windows with students
			
			windowTimes -> addBack(windows[i].getIdle());	
			//adds idletimes to window times list
			windows[i].resetIdle();
		}
	}

}

void Registrar::emptyWindow(){//need to add code!!!
	for(int i =  0;  i < size; ++i) //goes through every window
	{
		if(windows[i].timeup())//if student is out of window time
		{
			windows[i].remove();

		}
	}
}

void Registrar::increaseIdle() // goes through windows and increases idle time if empty
{
	for(int i = 0; i<size; ++i){
		if(windows[i].empty()){
			windows[i].increaseIdle();
		}
	}
}

unsigned int Registrar::getSize() const
{
	return size;
}

void Registrar::readFile(std::string str)
{
	ifstream inStream;
	inStream.open(str.c_str());
	
	//check for fail
	if (inStream.fail())
	{
		cout << "Error opening file." << endl;
		inStream.close();
		exit(1);
	}
	
	int n;
	inStream >> n;
	setWindow(n);
	//takes in the first char as the line windows open
	
	int time, count, wTime;
	
	while (!inStream.eof())
	{
		inStream >> time;
		//next time is arrival time
		inStream >> count;
		//next line is the number of students arriving
		for (int i = 0; i < count; ++i)
		{
			inStream >> wTime;
			//time they need at the window
			Student temp(0, wTime, time);
			//make a student
			line->enqueue(temp);
		}
	}
	inStream.close();
}

void Registrar::run(std::string str)
{
	readFile(str);
	int clock = 0;
	//while loop increments the clock
	while(line -> getSize() > 0 || !allOpen())
	{
		//first check if windows are open and fills them
		occupyWindow(clock);
		//increases the wait for anyone still in line
		increaseWait(clock);
		//increase idle time for any open windows
		increaseIdle();
		//decrease window time for anyone at a window
		decreaseWindow();
		//empty windows for anyone who's done
		emptyWindow();
		clock++;
	}

	//do stats stuff
	
cout<<"student"<<endl;
	StatStuff lineStats(waitTimes);
cout<<"window"<<endl;
	StatStuff windowStats(windowTimes);
	cout<<"Average Student Wait:\t"<<lineStats.calcMean()<<endl;
	cout<<"Median Student Wait:\t"<<lineStats.calcMedian()<<endl;
	cout<<"Longest Student Wait:\t"<<lineStats.calcMax()<<endl;
	cout<<"Number of Students Waiting over 10 min:\t"<<lineStats.countOverVal(10)<<endl;
	cout<<"Mean Window Idle Time:\t"<<windowStats.calcMean()<<endl;
	cout<<"Longest Window idle time:\t"<<windowStats.calcMax()<<endl;
	cout<<"Number of Windows idle for over 5 min:\t"<<windowStats.countOverVal(5)<<endl;
	//and we done
}
#endif
