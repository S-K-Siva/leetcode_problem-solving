class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        unordered_map<char, int> freq;
        for (char c : s) freq[c]++;
        
        priority_queue<pair<char, int>> maxHeap;
        for (auto [ch, count] : freq) {
            maxHeap.push({ch, count});
        }

        string hs;
        while (!maxHeap.empty()) {
            auto [currentChar, currentFreq] = maxHeap.top();
            maxHeap.pop();

            int use = min(repeatLimit, currentFreq);
            hs.append(use, currentChar);
            currentFreq -= use;

            if (currentFreq > 0) {
                if (maxHeap.empty()) break;
                auto [nextChar, nextFreq] = maxHeap.top();
                maxHeap.pop();

                hs.push_back(nextChar);
                nextFreq--;

                if (nextFreq > 0) maxHeap.push({nextChar, nextFreq});
                maxHeap.push({currentChar, currentFreq});
            }
        }

        return hs;
    }
};
