class LRUCache {
  private:
    map<int, int> memo, kToA, aToK;
    // NB: Age cannot start at 0
    int capacity, age = 1;

  public:
    LRUCache(int capacity) {
      this->capacity = capacity;
    }

    int get(int key) {
      if (memo.count(key) == 0) {
        return -1;
      }
      aToK.erase(kToA[key]);
      kToA[key] = age;
      aToK[age] = key;
      age++;
      return memo[key];
    }

    void put(int key, int value) {
      if (memo.count(key) == 0 and memo.size() == capacity) {
        auto [oldAge, oldKey] = *aToK.begin();
        memo.erase(oldKey);
        kToA.erase(oldKey);
        aToK.erase(oldAge);
      }
      memo[key] = value;
      aToK.erase(kToA[key]);
      kToA[key] = age;
      aToK[age] = key;
      age++;
    }
};
