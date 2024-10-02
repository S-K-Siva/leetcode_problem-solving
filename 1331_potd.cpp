class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> siva(arr.begin(),arr.end());
        map<int,int> mm;
        int index = 1;
        sort(siva.begin(),siva.end());
        for(auto it : siva){
            if(mm.find(it) == mm.end()){
                
                mm[it] = index;
                ++index;
            }
            
        }

        vector<int> res;
        for(auto it : arr){
            
            res.push_back(mm[it]);
            
        }

        return res;
    }
};
