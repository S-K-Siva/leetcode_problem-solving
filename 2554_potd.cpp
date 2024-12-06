class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        vector<int> unbanned;
        unordered_map<int,int> track;
        for(auto it : banned){
            ++track[it];
        }
        long long int total = 0;
        for(int i = 0;i<n;i++){
            if(track.find(i+1) == track.end()){
                total += (i+1);
                unbanned.push_back(i+1);
            }
        }
        if(total <= maxSum){
            return unbanned.size();
        }
        
        long long int result = 0;
        int count = 0;
        for(int i = 0;i<n;i++){
            if(result + unbanned[i] <= maxSum){
                ++count;
                result += unbanned[i];
            }else{
                break;
            }
        }
        return count;
    }
};
