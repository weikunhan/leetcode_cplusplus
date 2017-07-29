class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string> > ladders;
        vector<string> ladder;
        ladder.push_back(beginWord);
        unordered_set<string> startWords, endWords;
        unordered_set<string> wordDicts(wordList.begin(), wordList.end());
        startWords.insert(beginWord);
        endWords.insert(endWord);
        unordered_map<string, vector<string> > children;
        bool flip = true;
        
        if (wordDicts.find(endWord) == wordDicts.end()) return {};
        
        if (searchLadders(startWords, endWords, wordDicts, children, flip))
            genLadders(beginWord, endWord, children, ladder, ladders);
        return ladders;
    }
private:
    bool searchLadders(unordered_set<string>& startWords, unordered_set<string>& endWords, 
                 unordered_set<string>& dict, unordered_map<string, vector<string> >& children, bool flip) {
        flip = !flip;
        if (startWords.empty()) return false;
        if (startWords.size() > endWords.size())
            return searchLadders(endWords, startWords, dict, children, flip);
        for (string word : startWords) dict.erase(word);
        for (string word : endWords) dict.erase(word);
        unordered_set<string> intermediate;
        bool done = false;
        for (string word : startWords) {
            int n = word.length();
            string temp = word;
            for (int p = 0; p < n; p++) {
                char letter = word[p];
                for (int i = 0; i < 26; i++) {
                    word[p] = 'a' + i;
                    if (endWords.find(word) != endWords.end()) {
                        done = true;
						flip ? children[word].push_back(temp) : children[temp].push_back(word);
                    }
                    else if (!done && dict.find(word) != dict.end()) {
                        intermediate.insert(word);
						flip ? children[word].push_back(temp) : children[temp].push_back(word);
                    }
                }   
                word[p] = letter;
            }
        }
        return done || searchLadders(endWords, intermediate, dict, children, flip);
    }
    void genLadders(string& start, string& end, unordered_map<string, vector<string> >& children, 
                    vector<string>& ladder, vector<vector<string> >& ladders) {
        if (start == end) {
            ladders.push_back(ladder);
            return;
        }
        for (string child : children[start]) {
            ladder.push_back(child);
            genLadders(child, end, children, ladder, ladders);
            ladder.pop_back();
        }
    }
};
