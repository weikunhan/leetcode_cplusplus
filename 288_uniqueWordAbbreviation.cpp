//==============================================================================
// 288. Unique Word Abbreviation
// C++
// Tag: Design(Hash Table)
//==============================================================================
// Summary:
// https://leetcode.com/problems/unique-word-abbreviation/description/

class ValidWordAbbr {
public:
    ValidWordAbbr(vector<string> dictionary) {
        for (int i = 0; i < dictionary.size(); ++i) {
            string tmp = dictionary[i].front() + to_string(dictionary[i].size() - 2) + dictionary[i].back();
            tables[tmp].insert(dictionary[i]);
        }

    }
    
    bool isUnique(string word) {
        string tmp = word.front() + to_string(word.size() - 2) + word.back();
        
	return tables[tmp].count(word) == tables[tmp].size(); 
    }
    
private:
	unordered_map<string, unordered_set<string>> tables;
};

/**
 * Your ValidWordAbbr object will be instantiated and called as such:
 * ValidWordAbbr obj = new ValidWordAbbr(dictionary);
 * bool param_1 = obj.isUnique(word);
 */
