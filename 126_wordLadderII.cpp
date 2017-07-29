//==============================================================================
// 126. Word Ladder II
// C++
// Tag: Backtracking(BFS)
//==============================================================================
// Summary:
// https://leetcode.com/problems/word-ladder-ii/description/

class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> res;
        vector<string> solution;
        unordered_set<string> startWords;
        unordered_set<string> lastWords;
        unordered_set<string> wordDicts(wordList.begin(), wordList.end());
        unordered_map<string, vector<string> > tables;
        
        if (wordDicts.find(endWord) == wordDicts.end()) {
            return res;
        }

        startWords.insert(beginWord);
        lastWords.insert(endWord);
        solution.push_back(beginWord);

        if (helper(true, startWords, lastWords, wordDicts, tables)) {
            helper2(beginWord, endWord, tables, solution, res);
        }
        
        return res;
    }
	
private:
    bool helper(bool flagIn, 
                unordered_set<string> startWordsIn, 
                unordered_set<string> lastWordsIn, 
                unordered_set<string> wordDictsIn, 
                unordered_map<string, vector<string>> &tables) {
        unordered_set<string> intermediates;
        bool flag = false;
        
        flagIn = !flagIn;

        if (startWordsIn.empty()) {
            return false;
        }
        
        if (startWordsIn.size() > lastWordsIn.size()) {
            return helper(flagIn, lastWordsIn, startWordsIn, wordDictsIn, tables);
        }
        
        for (auto word:startWordsIn) {
            wordDictsIn.erase(word);
        }
        
        for (auto word:lastWordsIn) {
            wordDictsIn.erase(word);
        }
        
        for (auto word:startWordsIn) {
            string tmp = word;
            for (int i = 0; i < word.size(); ++i) {
                char letter = word[i];
                for (int j = 0; j < 26; ++j) {
                    word[i] = 'a' + j;
                    if (lastWordsIn.find(word) != lastWordsIn.end()) {
                        flag = true;
			(flagIn) ? tables[word].push_back(tmp):tables[tmp].push_back(word);
                    }
                    else if (!flag && wordDictsIn.find(word) != wordDictsIn.end()) {
                        intermediates.insert(word);
			(flagIn) ? tables[word].push_back(tmp):tables[tmp].push_back(word);
                    }
                }   
                word[i] = letter;
            }
        }
        
        return flag || helper(flagIn, lastWordsIn, intermediates, wordDictsIn, tables);
    }
    
    void helper2(string beginWordIn,
                 string endWordIn, 
                 unordered_map<string, vector<string>> tablesIn, 
                 vector<string> solutionIn, 
                 vector<vector<string>>& res) {
        if (beginWordIn == endWordIn) {
            res.push_back(solutionIn);
            return;
        }
        
        for (auto word:tablesIn[beginWordIn]) {
            solutionIn.push_back(word);
            helper2(word, endWordIn, tablesIn, solutionIn, res);
            solutionIn.pop_back();
        }
    }
};
