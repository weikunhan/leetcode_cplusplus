//==============================================================================
// 380. Insert Delete GetRandom O(1)
// C++
// Tag: Design, Array(Hash Table)
//==============================================================================
// Summary:
// https://leetcode.com/problems/insert-delete-getrandom-o1/description/

class RandomizedSet {
public:
    /** Initialize your data structure here. */
    RandomizedSet() {}
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (tables.find(val) != tables.end()) {
            return false;
        } else {
            number.push_back(val);
            tables[val] = number.size() - 1;
            return true;
        }
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (tables.find(val) == tables.end()) {
            return false;
        } else {
            int last = number.back();
            tables[last] = tables[val];
            number[tables[val]] = last;
            number.pop_back();
            tables.erase(val);
            return true;
        }
    }
    
    /** Get a random element from the set. */
    /** Weikun Assume the vector is not empty */
    int getRandom() {
        return number[rand() % number.size()];
    }
    
private:
    vector<int> number;
    unordered_map<int, int> tables;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */
