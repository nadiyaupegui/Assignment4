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
{
  size = d -> getSize();
  data = new int[size];
  for(int i = 0; i < size;++i)
  {
    cout<<d->front();
    data[i]= d-> front();
    cout<<data[i]<<endl; 
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
{
  int sum = 0;
  for(int i = 0; i < size; ++i)
  {
    sum+=data[i];
  }
  mean = (double)sum/(double)size;
  return mean;
}

double StatStuff::calcMedian()
{
  int idx = 0;
  idx = (int)(size/2);
  if(size%2 == 1) //if it's odd
  {
    median = data[idx];
  }
  else
  {
    median = (double)(data[idx]+data[idx+1])/(double)2;
  }
  return median;
}

double StatStuff::calcVar()
{
  double squaresum = 0;
  for(int i = 0; i<size; ++i)
  {
    squaresum += (data[i]-mean)*(data[i]-mean);
  }
    var = (double)squaresum/(double)(size-1);
    return var;
 }

double StatStuff::calcMin(){
  min = data[0];
  return min;
}

double StatStuff::calcMax()
{
  max = data[size-1];
  return max;
}

int StatStuff::countOverVal(int val){
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
