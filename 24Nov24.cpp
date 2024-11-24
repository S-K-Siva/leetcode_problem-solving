class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int count = 0;
        int n = matrix.size();
        long long total = 0;
        int mini = INT_MAX;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                if(matrix[i][j] < 0) count++;
                mini = min(mini,abs(matrix[i][j]));
                total += abs(matrix[i][j]);
            }
        }
        if(count%2)
            return total - (2 * mini);
        return total;
    }
};
