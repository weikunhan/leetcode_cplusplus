//==============================================================================
// 251. Flatten 2D Vector
// C++
// Tag: Design
//==============================================================================
// Summary:
// https://leetcode.com/problems/flatten-2d-vector/description/

class Vector2D {
public:
    Vector2D(vector<vector<int>>& vec2d) {
        it1 = vec2d.begin();
        it2 = vec2d.end();
    }

    int next() {
        hasNext();
        
        return (*it1)[index++];
    }

    bool hasNext() {
        while (it1 != it2 && index == (*it1).size()) {
            it1++;
            index = 0;
        }

        return it1 != it2;
    }

private:
    vector<vector<int>>::iterator it1;
    vector<vector<int>>::iterator it2;
    int index = 0;
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D i(vec2d);
 * while (i.hasNext()) cout << i.next();
 */
