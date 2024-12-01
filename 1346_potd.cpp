class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        map<int,int> vals;

        for(auto it : arr){
            ++vals[it];
        }

        for(auto it : arr){
            if(vals[it*2] && it == 0 && vals[it] > 1) return true;
            if(vals[it*2] && it != 0){
                
                return true;
            }
        }
        return false;
    }
};
