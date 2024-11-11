// class Solution {
// public:
//     bool primeSubOperation(vector<int>& nums) {
//         if(is_sorted(nums.begin(),nums.end())) return true;
//         int maxElement = *max_element(nums.begin(),nums.end());

//         vector<bool> isPrime(maxElement+1,true);
//         isPrime[0] = isPrime[1] = false;
//         for(int i = 2;i*i<=maxElement;i++){
//             if(!isPrime[i]) continue;
//             for(int j = i*i;j<=maxElement;j+=i){
//                 isPrime[j] = false;
//             }
//         }

//         set<int> primes;

//         for(int i = 0;i<=maxElement;i++){
//             if(isPrime[i]){
//                 primes.insert(i);
//             }
//         }

//         int n = nums.size();
//         for(int i = 1;i<n;i++){
//             if(nums[i] <= nums[i-1]){
                
//                 bool found = false;
//                 for(auto it = primes.rbegin();it != primes.rend();it++){
//                     int val = *it;

//                     if(val < nums[i] && (nums[i] - val) > nums[i-1]){
//                         nums[i] -= val;
//                         found = true;
//                         break;
//                     }
//                 }
//                 if(!found) return false;
//             }
//         }

//         return true;
//     }
// };

class Solution {
public:
    bool primeSubOperation(vector<int>& nums) {
        int maxElement = *max_element(nums.begin(), nums.end());


        vector<bool> isPrime(1024, true);
        isPrime[0] = isPrime[1] = false;
        for (int i = 2; i * i <= maxElement; i++) {
            if (isPrime[i]) {
                for (int j = i * i; j <= maxElement; j += i) {
                    isPrime[j] = false;
                }
            }
        }

     
        set<int> primes;
        for (int i = 2; i <= maxElement; i++) {
            if (isPrime[i]) {
                primes.insert(i);
            }
        }

        int prev = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            
            if (nums[i] <= prev) return false;

            auto it = primes.lower_bound(nums[i] - prev);
            if (it != primes.begin()) --it;

            if (*it < nums[i] && nums[i] - *it > prev) {
                nums[i] -= *it;
            }
            
            prev = nums[i];
        }

        return true;
    }
};
