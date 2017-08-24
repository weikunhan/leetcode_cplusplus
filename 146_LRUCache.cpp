//==============================================================================
// 146. LRU Cache
// C++
// Tag: Design
//==============================================================================
// Summary:
// https://leetcode.com/problems/lru-cache/description/

class LRUCache {
public:
    LRUCache(int capacity) {
        maxSize = capacity;
    }
    
    int get(int key) {
        if (tables.find(key) != tables.end()) {
            auto it = tables[key];
            data.splice(data.begin(), data, it);
            return it->second;
        } else {
            return -1;
        }
    }
    
    void put(int key, int value) {
        if (tables.find(key) != tables.end()) {
            auto it = tables[key];
            it->second = value;
            data.splice(data.begin(), data, it);
        } else {
            if (data.size() == maxSize) {
                int lastKey = data.back().first;
                data.pop_back();
                tables.erase(lastKey);
            }
            data.emplace_front(key, value);
            tables[key] = data.begin();
        }
    }
    
private:
    int maxSize = 0;
    list<pair<int, int>> data;
    unordered_map<int, list<pair<int, int>>::iterator> tables;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
