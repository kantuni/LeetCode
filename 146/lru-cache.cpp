class LRUCache {
  private:
    map<int, int> memo, kToA, aToK;
    // NB: Age cannot start at 0
    int capacity, age = 1;
  
    void update(int key) {
      aToK.erase(kToA[key]);
      kToA[key] = age;
      aToK[age] = key;
      age++;
    }
  
    void removeLRU() {
      auto [oldAge, oldKey] = *aToK.begin();
      memo.erase(oldKey);
      kToA.erase(oldKey);
      aToK.erase(oldAge);
    }

  public:
    LRUCache(int capacity) {
      this->capacity = capacity;
    }

    int get(int key) {
      if (memo.count(key) == 0) {
        return -1;
      }
      update(key);
      return memo[key];
    }

    void put(int key, int value) {
      if (memo.count(key) == 0 and memo.size() == capacity) {
        removeLRU();
      }
      update(key);
      memo[key] = value;
    }
};
