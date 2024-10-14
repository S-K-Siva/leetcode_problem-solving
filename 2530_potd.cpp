class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        long long score = 0;

        priority_queue<int> pq;

        for(auto it : nums){
            pq.push(it);
        }

        int n = nums.size();

        while(k--){
            int top = pq.top();
            pq.pop();
            score += top;
            top = ceil((double)top/3);
            pq.push(top);
        }

        return score;
    }
};
