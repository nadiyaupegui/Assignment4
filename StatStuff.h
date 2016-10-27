class StatStuff{
private:
  GenQueue<int>* data;
  double mean;
  double median;
  double var;
  double min;
  double max

public:
  StatStuff();
  StatStuff(GenQueue<int>* d);
  ~StatStuff();
  doubleSetData();
  getMean();
  getMedian();
  getVar();
  getMin();
  getMax();
  calcMean();
  calcMedian();
  calcVar();
  calcMin();
  calcMax();
}
