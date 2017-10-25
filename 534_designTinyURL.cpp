//==============================================================================
// 534. Design TinyURL
// C++
// Tag: Math(Hash Table)
//==============================================================================
// Summary:
// https://leetcode.com/problems/design-tinyurl/description/

class URlService {
public:
    string encode(string longUrl) {
        string tmp;
        
        if (tables1.find(longUrl) != tables1.end()) {
            return tables1[longUrl];
        }
        
        ++id;
        int number = id;
        
        while (number > 0) {
            tmp = dict[number % 62] + tmp;
            number /= 62;
        }
        
        while (tmp.size() < 6) {
            tmp = "0" + tmp;
        }
        
        tables1[longUrl] = tmp;
        tables2[id] = longUrl;
        
        return tmp;
    }

    string decode(string shortUrl) {
        string tmp;
        int id = 0;
        
        for (int i = 0; i < shortUrl.size(); ++i) {
            id = 62 * id + dict.find(shortUrl[i]);
        }
        
        if (tables2.find(id) != tables2.end()) {
            return tmp = tables2[id];
        }
        
        return tmp;
    }
    
private:
    string dict = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int id = 0;
    unordered_map<string, string> tables1;
    unordered_map<int, string> tables2;
};

int main() {
    URlService solution = new URlService();
    solution.decode(solution.encode("https://leetcode.com/problems/design-tinyurl"));

    return 0;
}
