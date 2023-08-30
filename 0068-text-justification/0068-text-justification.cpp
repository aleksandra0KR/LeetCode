class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res;
        vector<string> temp;
        int lengh = 0;
        string str = "";
        int space;
 
        for(auto a: words){
    
            if(lengh + a.size() + 1 < maxWidth) {
                temp.push_back(a);
                lengh += a.size() + 1;
            }
            else if(lengh + a.size() == maxWidth ) {

                    temp.push_back(a);
            
                    for(int j = 0; j < temp.size() - 1; j++){
                        str += temp[j] + " ";
                    }
                    str += temp[temp.size() - 1];
                    res.push_back(str);
                    str = "";
                    temp = {};
                    lengh = 0;
            }
            else if(lengh + a.size() + 1 == maxWidth and a != words[words.size() - 1]) {
            
                temp.push_back(a);
                lengh += a.size() + 1;
                space = maxWidth - lengh + temp.size();
                int tspace = 0;
                int numw = temp.size() - 1;
                int ninres = 0;
    
                for(int j = 0; j < temp.size() - 1; j++){
                    int cut = space;
                    ninres = 0;
                    while(cut % (numw - ninres) != 0){
                        tspace += cut/(numw -  ninres);
                        cut = cut - (cut/(numw -  ninres) * (numw - ninres));
                        ninres++;
                        //tspace += cut/(numw - ninres);
                    }
                    tspace += cut / (numw - ninres);
                    str += temp[j];
                    for(int i = 0; i < tspace; i++) str += " ";
                    space -= tspace;
                    numw --;
                    tspace = 0;

                }
                str += temp[temp.size() - 1];
                while(str.size() < maxWidth)str += " ";
                res.push_back(str);
                str = "";
                temp = {};
                lengh = 0;
            }
            else if(lengh + a.size() + 1 > maxWidth) {

                space = maxWidth - lengh + temp.size();
                int tspace = 0;
                int numw = temp.size() - 1;
                int ninres = 0;
    
                for(int j = 0; j < temp.size() - 1; j++){
                    int cut = space;
                    ninres = 0;
                    while(cut % (numw - ninres) != 0){
                        tspace += cut/(numw -  ninres);
                        cut = cut - (cut/(numw -  ninres) * (numw - ninres));
                        ninres++;
                       // tspace += cut/(numw -  ninres);
                    }
                    tspace += cut / (numw - ninres);
                    str += temp[j];
                    for(int i = 0; i < tspace; i++) str += " ";
                    space -= tspace;
                    numw --;
                    tspace = 0;

                }
                str += temp[temp.size() - 1];
                while(str.size() < maxWidth)str += " ";
                res.push_back(str);
                str = "";
                temp = {a};
                lengh = a.size() + 1;
                
            }
            else{
                temp.push_back(a);
            }
        }
        if (temp.size() != 0){
              
            
                    for(int j = 0; j < temp.size() - 1; j++){
                        str += temp[j] + " ";
                    }
                    str += temp[temp.size() - 1];
                    while(str.size() < maxWidth)str += " ";
                    res.push_back(str);
                    str = "";
                    temp = {};
                    lengh = 0;
                
                
        }
        
        return res;
    }
};