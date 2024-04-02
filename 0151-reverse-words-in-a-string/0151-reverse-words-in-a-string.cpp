class Solution {
public:
    string reverseWords(string s) {
        vector<string> m;
        string word = "";
        for(char a : s) {
            if (a == ' ') {
                if (word.size() != 0) {
                    m.push_back(word);
                    word = "";
                }
            } else {
                word += a;
            }
        }
        
        if (word.size() != 0) {
            m.push_back(word);
            word = "";
        }
        
        string result = "";
        for(int i = m.size() - 1; i > 0; i--){
            result += m[i] + " ";
        }
        result += m[0];
        return result;
    }
};