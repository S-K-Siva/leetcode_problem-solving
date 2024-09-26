#include<bits/stdc++.h>
using namespace std;

class MyCalendar {
public:
    vector<pair<int,int>> booking;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        for(auto it : booking){
            if(max(it.first , start) < min(it.second,end)) return false;
        }
        booking.push_back({start,end});
        return true;
    }
};
