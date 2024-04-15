class Solution {
public:
    
    string hash_code(string word){
        string code = "";
        int arr[26] = {0};
        
        for(char c : word){
            arr[c -'a']++;
        }
        
        int freq;
        for(int i = 0; i < 26; i++){
            freq = arr[i];
            if(freq>0){
                code+=string(freq, i + 'a');
            }
        }
        
        return code;
    }
    
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map< string, vector<string>> m;
        
        for(string word: strs){
            m[hash_code(word)].push_back(word);
        }
        
        vector<vector<string>> result;
        
        for(pair< string, vector<string>> str: m){
            result.push_back(str.second);
        }
        
        return result;
    }
};