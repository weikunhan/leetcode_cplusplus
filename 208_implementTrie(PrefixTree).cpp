//==============================================================================
// 208. Implement Trie (Prefix Tree)
// C++
// Tag: Design(Trie)
//==============================================================================
// Summary:
// https://leetcode.com/problems/implement-trie-prefix-tree/description/

class Trie {
public:
    struct TrieNode {
        bool isWord = false;
        TrieNode *next[26];
        ~TrieNode() {
            for (auto n : next) {
                if (n) { 
                    delete n;
                }
            }
        }
    };
    
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }
    
    ~Trie() {
        delete root;
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode *tmp = root;
        
        for (int i = 0; i < word.size(); ++i) {
            if (!tmp->next[word[i] - 'a']) {
                tmp->next[word[i] - 'a'] = new TrieNode();
            }
            tmp = tmp->next[word[i] - 'a'];
        }
        
        tmp->isWord = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode *tmp = helper(word);
        
        return tmp && tmp->isWord;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode *tmp = helper(prefix);
        
        return tmp;
    }
    
private:
    TrieNode *root;
    
    TrieNode *helper(string wordIn) {
        TrieNode *tmp = root;
        
        for (int i = 0; i < wordIn.size(); ++i) {
            if (tmp->next[wordIn[i] - 'a']) {
                tmp = tmp->next[wordIn[i] - 'a'];
            } else {
                tmp = NULL;
                break;
            }
        }
        
        return tmp;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */