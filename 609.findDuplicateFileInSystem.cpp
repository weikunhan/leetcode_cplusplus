//==============================================================================
// 609. Find Duplicate File in System
// C++
// Tag: Hash Table
//==============================================================================
// Summary:
// The easy way is to use a hash table with key value are all files contents, 
// and store files name with same key value. Finally, print all the size of mapped 
// value is greate than 1, which prints the duplicates. 
// https://leetcode.com/problems/find-duplicate-file-in-system/#/description

class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        unordered_map<string, vector<string>> files;
        vector<vector<string>> res;
        
        for (auto path:paths) {
            stringstream ss(path);
            string root;
            string info;
            getline(ss, root, ' ');
            while (getline(ss, info, ' ')) {
                string fileName = root + '/' + info.substr(0, info.find('('));
//                string fileContent = info.substr(info.find('(') +1, info.find(')') - info.find('(') - 1);
                string fileContent = info.substr(info.find('('));
                files[fileContent].push_back(fileName);
            }
        }
        
        for (auto file:files) {
            if (file.second.size() > 1) {
                res.push_back(file.second);
            }
        }
        
        return res;
    }
};
