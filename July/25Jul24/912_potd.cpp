#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to heapify a subtree rooted with node i
    void heapify(std::vector<int>& arr, int n, int i) {
        int largest = i; // Initialize largest as root
        int left = 2 * i + 1; // left = 2*i + 1
        int right = 2 * i + 2; // right = 2*i + 2

        // If left child is larger than root
        if (left < n && arr[left] > arr[largest])
            largest = left;

        // If right child is larger than largest so far
        if (right < n && arr[right] > arr[largest])
            largest = right;

        // If largest is not root
        if (largest != i) {
            std::swap(arr[i], arr[largest]);

            // Recursively heapify the affected sub-tree
            heapify(arr, n, largest);
        }
    }

    // Main function to do heap sort
    void heapSort(std::vector<int>& arr) {
        int n = arr.size();

        // Build heap (rearrange array)
        for (int i = n / 2 - 1; i >= 0; i--)
            heapify(arr, n, i);

        // One by one extract an element from heap
        for (int i = n - 1; i > 0; i--) {
            // Move current root to end
            std::swap(arr[0], arr[i]);

            // Call max heapify on the reduced heap
            heapify(arr, i, 0);
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        // using in-build method TC : O(n * log(n)) , SC : O(1)
        // sort(nums.begin(),nums.end());
        // return nums;

        // using multiset TC : O(n * log n) , SC : O(n)
        // log(n)-> insertion, deletion,retrieving in multiset
        // multiset<int> arr(nums.begin(),nums.end());
        // return {arr.begin(),arr.end()};


        // Optimal Solution
        // using Quick Sort takes TC : O(n * log(n)), SC : O(n)
        // so we can go with Heap sort, TC : (n * log(n)) , SC : O(1)
        // alternative of in-built method
        heapSort(nums);
        return nums;

    }
};