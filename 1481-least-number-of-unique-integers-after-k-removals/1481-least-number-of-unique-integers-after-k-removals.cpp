class Solution {
public:
    struct comp {

        template <typename T>


        bool operator()(const T& l, const T& r) const

        {

         return l.second <= r.second;

        }
    };
 

    set<pair<int, int>, comp> sort(map<int, int>& M)
    {
        set<pair<int, int>, comp> S(M.begin(), M.end());
        return S;
    }

    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        
        map<int,int> allValues;
        
        for(int value: arr){
            if(allValues.count(value) == 0) allValues[value] = 1;
            else allValues[value]++;
        }
        
        set<pair<int, int>, comp> res = sort(allValues);
 
        for(const auto&[key, value]: res){
  
            if (k >= value){
            
            k -= value;
                
            allValues.erase(key);
          
            }
            else break;
        }
        return allValues.size();
    }
};