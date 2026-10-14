class MyHashSet {
   public:
    MyHashSet() {}

    void add(int key) { mySet[key] = true; }

    void remove(int key) { mySet[key] = false; }

    bool contains(int key) { return mySet.test(key); }

   private:
    std::bitset<1000001> mySet{0};
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */