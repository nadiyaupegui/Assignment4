class StatStuff{
private:
  GenQueue<int>* data;
public:
  StatStuff();
  StatStuff(GenQueue<int>* d);
  ~StatStuff();
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
