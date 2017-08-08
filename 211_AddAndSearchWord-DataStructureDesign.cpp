//==============================================================================
// 211. Add and Search Word - Data structure design
// C++
// Tag: Design, Backtracking(Trie)
//==============================================================================
// Summary:
// https://leetcode.com/problems/add-and-search-word-data-structure-design/description/

class WordDictionary {
public:
    struct TrieNode {
        bool isWord;
        vector<TrieNode *> child;
        TrieNode():isWord(false), child(26, NULL) {}
        ~TrieNode() {
           child.clear();
        }
    };
    
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new TrieNode();
    }
    
    ~WordDictionary() {
        delete root;
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        TrieNode *tmp = root;
        
        for (int i = 0; i < word.size(); ++i) {
            if (!tmp->child[word[i] - 'a']) {
                tmp->child[word[i] - 'a'] = new TrieNode();
            }
            tmp = tmp->child[word[i] - 'a'];
        }
        
        tmp->isWord = true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return helper(word, 0, root);
    }
    
private:
    TrieNode *root;
    
    bool helper(string wordIn, int stepIn, TrieNode *rootIn) {
        if (stepIn == wordIn.size()) {
            return false;
        }
        
        if (wordIn[stepIn] != '.') {
            if (!rootIn->child[wordIn[stepIn] - 'a']) {
                return false;
            }
            if (stepIn == wordIn.size() - 1 && rootIn->child[wordIn[stepIn] - 'a']->isWord) {
                return true;
            }
            return helper(wordIn, stepIn + 1, rootIn->child[wordIn[stepIn] - 'a']);
        } else {
            for (auto n:rootIn->child) {
                if (n) {
                    if (stepIn == wordIn.size() - 1 && n->isWord) {
                        return true;
                    }
                    if (helper(wordIn, stepIn + 1, n)) {
                        return true;
                    }
                }
            }
            return false;
        }
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * bool param_2 = obj.search(word);
 */
