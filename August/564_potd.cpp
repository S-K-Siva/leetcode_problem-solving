#include<bits/stdc++.h>
using namespace std;

// TLE(Time Limit Exceeded)

// class Solution {
// public:
//     string nearestPalindromic(string n) {
//         long long int number = stoll(n)-1;
//         vector<pair<int,string>> res;
//         int step = 0;
//         while(number >= 0){
//             string reverseString = to_string(number);
//             string rev = reverseString;
//             reverse(rev.begin(),rev.end());
//             if(rev == reverseString){
//                 res.push_back({step, rev});
//                 break;
//             }
//             ++step;
//             --number;
//         }

//         number = stoll(n)+1;
//         step = 0;
//         while(true){
//             string reverseString = to_string(number);
//             string rev = reverseString;
//             reverse(rev.begin(),rev.end());
//             if(reverseString == rev){
//                 res.push_back({step,rev});
//                 break;
//             }
//             ++step;
//             ++number;
//         }
        
//         sort(res.begin(),res.end());
//         string result;
//         if(res.size() == 2 && res[0].first == res[1].first){
//             int num1 = stoi(res[0].second);
//             int num2 = stoi(res[1].second);
//             result = to_string(min(num1,num2));
//         }else{
//             result = res[0].second;
//         }
//         return result;
//     }
// };

// Reference Solution
class Solution {
public:
    // This function finds the nearest palindrome to a given number n
    string nearestPalindromic(string n) {
        int len = n.length();  // Get the length of the number
        if(len == 1) return to_string(stol(n)-1);  // Special case: if the number is a single digit, return the previous digit

        vector<long long> candidates;  // To store possible palindromic numbers

        // Add two edge cases: all 9s and 100...001 (like 999 and 1001)
        candidates.push_back(pow(10, len-1) - 1);  // Example: if n = "123", this adds "99"
        candidates.push_back(pow(10, len) + 1);  // Example: if n = "123", this adds "1001"
        
        long prefix = stol(n.substr(0, (len+1)/2));  // Extract the prefix (first half of the number)
        vector<long> nearPrefixes = {prefix - 1, prefix, prefix + 1};  // Try the prefix and its neighbors

        // Create palindrome candidates based on the prefix
        for(auto it: nearPrefixes){
            string prefix = to_string(it);  // Convert the prefix number back to a string
            if(len % 2 ) prefix.pop_back();  // If the length is odd, remove the last digit
            reverse(prefix.begin(), prefix.end());  // Reverse the prefix
            candidates.push_back(stol(to_string(it) + prefix));  // Combine to form a palindrome
        }

        long mini = LONG_MAX;  // To store the minimum difference found
        long close = 0;  // To store the closest palindrome
        for(auto it: candidates){
            long diff = abs(it - stol(n));  // Calculate the difference between the candidate and the original number
            if(mini > diff && it != stol(n)){  // Check if this candidate is closer than the previous ones
                mini = diff;
                close = it;
            }
        }
        return to_string(close);  // Return the closest palindrome as a string
    }
};
