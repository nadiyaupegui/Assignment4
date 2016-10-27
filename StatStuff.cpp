StatStuff::StatStuff()
{
  data = NULL;
}

StatStuff::StatStuff(GenQueue<int>* d)
{
  mean = -1
  median = -1
  var = -1
  min = -1
  max = -1
}

StatStuff::~StatStuff()
{
  if(data !=NULL)
  {
    delete data;
  }
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
  return var;
}

double StatStuff::getMin()
{
  return min;
}

double StatStuff::getMax()
{
  return max;
}

int StatStuff::getOverVal()
{
  return overval;
}

void StatStuff::calcMean()
{

}

void StatStuff::calcMedian(){}

void StatStuff::calcVar(){}

void StatStuff::calcMin(){}

void StatStuff::calcMax(){}

void StatStuff::calcOverVal(){}
