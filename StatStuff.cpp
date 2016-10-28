#include "StatStuff.h"
#include "DList.h"
#include <algorithm>
using namespace std;
StatStuff::StatStuff()
{
  data = NULL;
  mean = -1;
  median = -1;
  var = -1;
  min = -1;
  max = -1;
  overVal = -1;
  size = -1;
}

StatStuff::StatStuff(DList<int>* d)
{
  setData(d);
  mean = -1;
  median = -1;
  var = -1;
  min = -1;
  max = -1;
  overVal = -1;
}

StatStuff::~StatStuff()
{
  if(data !=NULL)
  {
    delete data;
  }
}

void StatStuff::sortData()
{
  std::sort(data, data+size);
}

void StatStuff::setData(DList<int>* d)
{//goes through the linked list and puts it into an array and sorts it
  size = d -> getSize();
  data = new int[size];
  for(int i = 0; i < size;++i)
  {
    data[i]= d-> front(); 
    d -> removeFront();
  } 
  sortData();
}

double StatStuff::getMean()
{
  return mean;
}

double StatStuff::getMedian()
{
  return median;
}

double StatStuff::getVar()
{
  return min;
}

double StatStuff::getMax()
{
  return max;
}

int StatStuff::getOverVal()
{
  return overVal;
}

double StatStuff::calcMean()
{//calculates mean
  int sum = 0;
  for(int i = 0; i < size; ++i)
  {
    //gets the total sum
    sum+=data[i];
  }
  //divides it by number of observations
  mean = (double)sum/(double)size;
  return mean;
}

double StatStuff::calcMedian()
{
  int idx = 0;
  idx = (int)(size/2);
  if(size%2 == 1) //if it's odd
  {
    //it's just the middle number
    median = data[idx];
  }
  else
  {
    //if its even take the average of the two midldle numbers
    median = (double)(data[idx]+data[idx-1])/(double)2;
  }
  return median;
}

double StatStuff::calcVar()
{//gets the variance
  double squaresum = 0;
  for(int i = 0; i<size; ++i)
  {
    squaresum += (data[i]-mean)*(data[i]-mean);
  }
    var = (double)squaresum/(double)(size-1);
    return var;
 }

double StatStuff::calcMin(){
//gets the min
  min = data[0];
  return min;
}

double StatStuff::calcMax()
{
  //gets the max
  max = data[size-1];
  return max;
}

int StatStuff::countOverVal(int val){
  //gets the number of observations over a value val
  int count = 0;
  for(int i = 0; i<size;++i)
  {
    if(data[i]>val)
    {
      count++;
    }
  }
  overVal = count;
  return overVal;
}
