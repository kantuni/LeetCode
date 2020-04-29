class LRUCache {
  private:
    int capacity;
    list<pair<int, int>> items;
    unordered_map<int, list<pair<int, int>>::iterator> memo;

  public:
    LRUCache(int capacity) {
      this->capacity = capacity;
    }

    int get(int key) {
      if (memo.count(key) == 0) {
        return -1;
      }
      items.splice(items.begin(), items, memo[key]);
      return items.front().second;
    }

    void put(int key, int value) {
      if (memo.count(key) == 0) {
        items.push_front({key, value});
        memo[key] = items.begin();
      } else {
        memo[key]->second = value;
        items.splice(items.begin(), items, memo[key]);
      }
      if (memo.size() > capacity) {
        auto lru = items.back();
        memo.erase(lru.first);
        items.pop_back();
      }
    }
};
