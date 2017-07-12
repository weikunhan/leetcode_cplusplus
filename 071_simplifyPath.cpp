//==============================================================================
// 71. Simplify Path
// C++
// Tag: Stack
//==============================================================================
// Summary:
// https://leetcode.com/problems/simplify-path/#/description

class Solution {
public:
    string simplifyPath(string path) {
        string res;
        string tmp;
        stack<string> files;
        stringstream ss(path);
        
        while (getline(ss, tmp, '/')) {
            if (tmp == "" || tmp == ".") {
                continue;
            }
            if (tmp == ".." && !files.empty()) {
                files.pop();
            } 
            if (tmp != "..") {
                files.push(tmp);
            }
        }
        
        while (!files.empty()) {
            res = "/" + files.top() + res;
            files.pop();
        }
        
        return res = res.empty() ? "/":res;
    }
};
