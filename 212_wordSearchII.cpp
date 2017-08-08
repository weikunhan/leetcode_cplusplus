//==============================================================================
// 212. Word Search II
// C++
// Tag: Backtracking(Trie)
//==============================================================================
// Summary:
// https://leetcode.com/problems/word-search-ii/description/

class Solution {
public:
    struct TrieNode {
        vector<TrieNode *> child;
        string word;
        TrieNode():word(""), child(26, nullptr) {}
    };
    
    TrieNode* buildTrie(vector<string> wordIn) {
        TrieNode* root = new TrieNode();
        
        for (int i = 0; i <wordIn.size(); ++i) {
            TrieNode* tmp = root;
            for (int j = 0; j < wordIn[i].size(); ++j) {
                if (tmp->child[wordIn[i][j] - 'a'] == NULL) {
                    tmp->child[wordIn[i][j] - 'a'] = new TrieNode();
                }
                tmp = tmp->child[wordIn[i][j] - 'a'];
            }
            tmp->word = wordIn[i];
        }
        
        return root;
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> res;
        TrieNode* root = buildTrie(words);
        
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                helper(board, i, j, root, res);
            }
        }
        
        return res;
    }
    
private:
    void helper(vector<vector<char>> boardIn, int stepIn1, int stepIn2, TrieNode* rootIn, vector<string>& res) {
        char tmp = boardIn[stepIn1][stepIn2];
        
        if (tmp == '#' || !rootIn->child[tmp - 'a']) {
            return;
        }
        
        rootIn = rootIn->child[tmp - 'a'];
        
        if (rootIn->word != "") {
            res.push_back(rootIn->word);
            rootIn->word = "";
        }
        
        boardIn[stepIn1][stepIn2] = '#';
        
        if (stepIn1 > 0) {
            helper(boardIn, stepIn1 - 1, stepIn2 , rootIn, res); 
        }
        
        if (stepIn2 > 0) {
            helper(boardIn, stepIn1, stepIn2 - 1, rootIn, res);
        }
        
        if (stepIn1 < boardIn.size() - 1) {
            helper(boardIn, stepIn1 + 1, stepIn2, rootIn, res); 
        }
        
        if (stepIn2 < boardIn[0].size() - 1) {
            helper(boardIn, stepIn1, stepIn2 + 1, rootIn, res); 
        }
        
        boardIn[stepIn1][stepIn2] = tmp;
        
        return;
    }
};
