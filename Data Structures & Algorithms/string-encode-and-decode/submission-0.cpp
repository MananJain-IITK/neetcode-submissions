class Solution {
public:

    string encode(vector<string>& strs) {
        if (strs.empty()) return "";
        string lengths ;
        string strings ;
        for(const auto& x: strs){
            lengths += to_string(x.size()) + ",";
            strings += x;
        }
        string encoded = lengths + "#" + strings;
        return encoded;
    }

    vector<string> decode(string s) {
        if (s.empty()) return {};
        int hash_idx=0;
        vector<int> sizes;
        while(s[hash_idx] != '#'){
            string temp ;
            while(s[hash_idx] != ','){
                temp += s[hash_idx];
                hash_idx++;
            }
            sizes.push_back(stoi(temp));
            hash_idx++;
        }
        hash_idx++; 

        vector<string> decoded;
        for(int sz: sizes){
            decoded.push_back(s.substr(hash_idx, sz));
            hash_idx += sz;

        }

        return decoded;
    }
};
