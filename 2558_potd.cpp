class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        
        priority_queue<int> pq;
        for(auto it : gifts){
            pq.push(it);
        }

        while(k--) {
            int topElement = pq.top();
            pq.pop();
            pq.push(floor(sqrt(topElement)));
        }

        long long result = 0;
        while(!pq.empty()){
            result += pq.top();
            pq.pop();
        }
        return result;
    }
};
