class Solution {
public:
    long long findScore(vector<int>& nums) {
        priority_queue<pair<int, int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;

        int n = nums.size();

        unordered_map<int, queue<int>> mpp;

        for (int i = 0; i < n; i++) {
            mpp[nums[i]].push(i);
        }

        for (int i = 0; i < n; i++) {
            pq.push({nums[i], i});
        }

        long long result = 0;
        vector<int> visited(n, 0);

        while (!pq.empty()) {
            auto topElement = pq.top();
            pq.pop();

            int value = topElement.first;
            int index = topElement.second;

            if (visited[index]) continue;

            result += value;
            visited[index] = 1;

            if (index - 1 >= 0 && !visited[index - 1]) {
                visited[index - 1] = 1;
            }
            if (index + 1 < n && !visited[index + 1]) {
                visited[index + 1] = 1;
            }
        }

        return result;
    }
};
