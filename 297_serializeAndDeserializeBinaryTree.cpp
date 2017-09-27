//==============================================================================
// 297. Serialize and Deserialize Binary Tree
// C++
// Tag: Tree, Design
//==============================================================================
// Summary:
// https://leetcode.com/problems/serialize-and-deserialize-binary-tree/description/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        ostringstream out;
        
        helper1(root, out);
        
        return out.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream in(data);
        
        return helper2(in);
    }
    
private:
    void helper1(TreeNode* rootIn, ostringstream &out) {
        if (rootIn) {
            out << rootIn->val << ' ';
            helper1(rootIn->left, out);
            helper1(rootIn->right, out);
        } else {
            out << "# ";
        }
    }

    TreeNode *helper2(istringstream &in) {
        string tmp;
        
        in >> tmp;
        
        if (tmp == "#") {
            return NULL;
        }
        
        TreeNode *root = new TreeNode(stoi(tmp));
        root->left = helper2(in);
        root->right = helper2(in);
        
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
