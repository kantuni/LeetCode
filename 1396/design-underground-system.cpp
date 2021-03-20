class UndergroundSystem {
  private:
    map<int, pair<string, int>> enter;
    map<string, pair<double, int>> average;

  public:
    void checkIn(int id, string stationName, int t) {
      enter[id] = {stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
      auto [enterStation, enterTime] = enter[id];
      auto [oldSum, count] = average[enterStation + "->" + stationName];
      average[enterStation + "->" + stationName] = {
        oldSum + (t - enterTime), 
        count + 1
      };
      enter.erase(id);
    }
    
    double getAverageTime(string startStation, string endStation) {
      auto [sum, count] = average[startStation + "->" + endStation];
      return (double) sum / count;
    }
};
