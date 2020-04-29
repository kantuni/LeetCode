class LRUCache {
  private:
    int capacity;
    list<pair<int, int>> values;
    unordered_map<int, list<pair<int, int>>::iterator> memo;

  public:
    LRUCache(int capacity) {
      this->capacity = capacity;
    }

    int get(int key) {
      if (memo.count(key) == 0) {
        return -1;
      }
      values.splice(values.begin(), values, memo[key]);
      return values.front().second;
    }

    void put(int key, int value) {
      if (memo.count(key) == 0) {
        values.push_front({key, value});
        memo[key] = values.begin();
      } else {
        memo[key]->second = value;
        values.splice(values.begin(), values, memo[key]);
      }
      if (memo.size() > capacity) {
        auto lru = values.back();
        memo.erase(lru.first);
        values.pop_back();
      }
    }
};
