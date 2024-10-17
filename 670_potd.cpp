class Solution {
public:
    // Wrong Answer

    // int maximumSwap(int num) {
    //     string number = to_string(num);
        
    //     int size = number.size();
        
    //     bool swapMade = false;
    
    //     for(int i = 0;i<size;i++){
            
    //         char ch = number[i];
    //         int index = i;
    //         for(int j = i+1;j<size;j++){
    //             if(number[j] > number[index]){
    //                 index = j;
    //                 ch = number[j];
    //             }
    //         }

    //         if(index != i){
    //             swap(number[i],number[index]);
    //             swapMade = true;
    //         }

    //         if(swapMade) break;
    //     }

    //     return stoi(number);
    // }

    int maximumSwap(int num) {
        string number = to_string(num);
        int size = number.size();

        vector<int> trackDigitIndexes(10,-1);


        for(int i = 0;i<size;i++){
            trackDigitIndexes[number[i] - '0'] = i;
        }

        for(int i = 0;i<size;i++){
            for(int digit = 9;digit > number[i]-'0';digit--){
                if(trackDigitIndexes[digit] > i){
                    swap(number[i],number[trackDigitIndexes[digit]]);
                    return stoi(number);
                }
            }
        }

        return num;
    }
};
