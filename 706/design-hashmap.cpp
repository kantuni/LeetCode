/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */

class MyHashMap {
  private:
    vector<int> memo;

  public:
    // Initialize your data structure here.
    MyHashMap() {
      memo.assign(1000001, -1);
    }
    
    // Maps the given key to the given value.
    void put(int key, int value) {
      memo[key] = value;
    }
    
    // Returns the value to which the specified key is mapped, 
    // or -1 if this map contains no mapping for the key.
    int get(int key) {
      return memo[key];
    }
    
    // Removes the mapping of the specified value key 
    // if this map contains a mapping for the key.
    void remove(int key) {
      memo[key] = -1;
    }
};
