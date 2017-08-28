//==============================================================================
// 170. Two Sum III - Data structure design
// C++
// Tag: Design(Hash Table)
//==============================================================================
// Summary:
// https://leetcode.com/problems/two-sum-iii-data-structure-design/description/

class TwoSum {
public:
    /** Initialize your data structure here. */
    TwoSum() {}
    
    /** Add the number to an internal data structure.. */
    void add(int number) {
        ++tables[number];
    }
    
    /** Find if there exists any pair of numbers which sum is equal to the value. */
    bool find(int value) {
        for (auto n:tables) {
            int tmp = value - n.first;
            if (n.first == tmp && n.second > 1) {
                return true;    
            }
            if (n.first != tmp && tables.find(tmp) != tables.end()) {
                return true;
            }
        }
            
        return false;
    }
    
private:
    unordered_map<int, int> tables;
};

/**
 * Your TwoSum object will be instantiated and called as such:
 * TwoSum obj = new TwoSum();
 * obj.add(number);
 * bool param_2 = obj.find(value);
 */
