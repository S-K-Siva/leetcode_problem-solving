class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        unordered_map<string,int> track;
        int n = matrix.size();
        int m = matrix[0].size();
        int maxCnt = 0;
        for(int i = 0;i<n;i++){
            string key = "";
            string inverted = "";
            for(int j = 0;j<m;j++){
                if(matrix[i][j]){
                    key += ('0' + matrix[i][j]);
                    inverted += '0';
                }else{
                    key += ('0' + matrix[i][j]);
                    inverted += '1';
                }
            }
            track[key]++;
            track[inverted]++;

            maxCnt = max(maxCnt,max(track[key],track[inverted]));
        }

        return maxCnt;
    }
};
