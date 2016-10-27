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
  double SetData();
  double getMean();
  double getMedian();
  double getVar();
  double getMin();
  double getMax();
  int getOverVal();
  void calcMean();
  void calcMedian();
  void calcVar();
  void calcMin();
  void calcMax();
  void countOverVal(int val);
}
