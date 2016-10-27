class StatStuff{
private:
  GenQueue<int>* data;
  double mean;
  double median;
  double var;
  double min;
  double max;
  int overVal;

public:
  StatStuff();
  StatStuff(GenQueue<int>* d);
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
