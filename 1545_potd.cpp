class Solution {
public:
    char findKthBit(int n, int k) {
        
        string value = "";
        value += '0';

        for(int i = 0;i<n;i++){
            string toAdd = "";
            toAdd += '1';
            for(int j = value.size()-1;j>=0;j--){
                if(value[j] == '0')
                    toAdd += '1';
                else
                    toAdd += '0';
            }
            value += toAdd;
        }

        return value[k-1];
    }
};
