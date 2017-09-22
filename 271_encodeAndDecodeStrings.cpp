//==============================================================================
// 271. Encode and Decode Strings
// C++
// Tag: String
//==============================================================================
// Summary:
// https://leetcode.com/problems/encode-and-decode-strings/description/

class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string tmp;
        
        for (int i = 0; i < strs.size(); ++i) {
            int length = strs[i].size();
            tmp += to_string(length) + "#" + strs[i];
        }
        
        return tmp;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> tmp;
        int head = 0;
        
        while (head < s.size()) {
            int index = s.find_first_of('#', head);
            int length = stoi(s.substr(head, index - head));
            head = index + 1;
            tmp.push_back(s.substr(head, length));
            head += length;
        }
        
        return tmp;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));
