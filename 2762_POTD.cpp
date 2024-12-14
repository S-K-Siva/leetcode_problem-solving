class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        // // [1] -> 1
        // // [1,2] = [1],[2],[1,2] -> 3
        // // [1,2,3] -> 6
        // // [1,2,3,4] -> 8
        // wrg logic, not maintained the constraint '|nums[i]-nums[j]| <= 2'

        // int n = nums.size();
        // if(n == 0) return 0LL;
        
        
        // long long prev = 1;
        // for(int i = 2;i<=n;i++){
        //     if(i%2){
        //         prev *= 2;
        //     }else{
        //         prev += 2;
        //     }
        // }
        // return prev;



        deque<int> mini, maxi;
        int n = nums.size();
        long long result = 0;
        int front = 0;
        for(int rear = 0;rear<n;rear++){
            while(!mini.empty() && nums[mini.back()] > nums[rear]){
                mini.pop_back();
            }
            while(!maxi.empty() && nums[maxi.back()] < nums[rear]){
                maxi.pop_back();
            }
            mini.push_back(rear);
            maxi.push_back(rear);

            while(abs(nums[mini.front()] - nums[maxi.front()]) > 2){
                if(mini.front() == front) mini.pop_front();
                if(maxi.front() == front) maxi.pop_front();
                front++;
            }

            result += (rear - front + 1);
        }
        return result;
    }
};
