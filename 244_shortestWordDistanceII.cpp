//==============================================================================
// 244. Shortest Word Distance II
// C++
// Tag: Design(Hash Table)
//==============================================================================
// Summary:
// https://leetcode.com/problems/shortest-word-distance-ii/description/

class WordDistance {
public:
    WordDistance(vector<string> words) {
        for (int i = 0; i < words.size(); ++i) {
            tables[words[i]].push_back(i);
        }
    }
    
    int shortest(string word1, string word2) {
        int index1 = 0;
        int index2 = 0;
        int tmp = INT_MAX;
        
        while (index1 < tables[word1].size() && index2 < tables[word2].size()) {
            tmp = min(tmp, abs(tables[word1][index1] - tables[word2][index2]));
            (tables[word1][index1] < tables[word2][index2]) ? ++index1:++index2;
        }
        
        return tmp;
    }
    
private:
    unordered_map<string, vector<int>> tables;
};

/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance obj = new WordDistance(words);
 * int param_1 = obj.shortest(word1,word2);
 */
