#ifndef _STAT_STUFF
#define _StAT_STUFF
#include "DList.h"
class StatStuff{
private:
  int* data;
  double mean;
  double median;
  double var;
  double min;
  double max;
  int overVal;
  int size;
  
public:
  StatStuff();
  StatStuff(DList<int>* d);
  ~StatStuff();
  void sortData();
  void setData(DList<int>* d);
  double getMean();
  double getMedian();
  double getVar();
  double getMin();
  double getMax();
  int getOverVal();
  double calcMean();
  double calcMedian();
  double calcVar();
  double calcMin();
  double calcMax();
  int countOverVal(int val);
};
#endif
