//==============================================================================
// 281. Zigzag Iterator
// C++
// Tag: Design
//==============================================================================
// Summary:
// https://leetcode.com/problems/zigzag-iterator/description/

class ZigzagIterator {
public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        if (v1.size() != 0) {
            tables.push(make_pair(v1.begin(), v1.end()));
        }
        
        if (v2.size() != 0) {
            tables.push(make_pair(v2.begin(), v2.end()));
        }
    }

    int next() {
        vector<int>::iterator it1 = tables.front().first;
        vector<int>::iterator it2 = tables.front().second;
        tables.pop();
        
        if (it1 + 1 != it2) {
            tables.push(make_pair(it1 + 1, it2));
        }
        
        return *it1;
    }

    bool hasNext() {
         return !tables.empty();
    }
    
private:
    queue<pair<vector<int>::iterator, vector<int>::iterator>> tables;
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */
