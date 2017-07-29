class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> startWords;
        unordered_set<string> lastWords;
        unordered_set<string> wordDicts(wordList.begin(), wordList.end());
        int res = 0;
        
        if (wordDicts.find(endWord) == wordDicts.end()) {
            return res;
        }
        
        if (beginWord == endWord) {
			return res = 1;
        }
        
        wordDicts.erase(beginWord);
        wordDicts.erase(endWord);
        startWords.insert(beginWord);
		lastWords.insert(endWord);
        
        return res = helper(startWords,lastWords, wordDicts, 1);
    }

private:
    int helper(unordered_set<string> startWordsIn, 
               unordered_set<string> lastWordsIn,
               unordered_set<string> wordDictsIn, 
               int levelIn) {
		unordered_set<string> intermediates;
        
        if (startWordsIn.empty()) {
            return 0;
        }
        
		if (startWordsIn.size() > lastWordsIn.size()) {
			return helper(lastWordsIn, startWordsIn, wordDictsIn, levelIn);
        }

        for (auto word:startWordsIn) {
			string tmp = word;
			for (int i = 0; i < word.size(); ++i) {
				char letter = word[i];
                for (int j = 0; j < 26; ++j) {
                    word[i] = 'a' + j;
						if (lastWordsIn.find(word) != lastWordsIn.end()) {
                            return levelIn + 1;
                        } else if (wordDictsIn.find(word) != wordDictsIn.end()) {
                            wordDictsIn.erase(word);
                            intermediates.insert(word);
                        }
                }
				word[i] = letter;
            }
        }
        
        return helper(lastWordsIn, intermediates, wordDictsIn, levelIn + 1);
    }
};
