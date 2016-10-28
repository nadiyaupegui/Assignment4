#include <iostream>
#include <cstdlib>
#include <string>
#include "DNode.h"
#include "DList.h"
#include "GenQueue.h"
#include "Student.h"
#include "Window.h"
#include "Registrar.h"
using namespace std;

int main(int argc, char** argv)
{
  string fileIn =  argv[1];
  Registrar r;
  
  r.run(fileIn);
	cout<<"that's all folks"<<endl;
}
