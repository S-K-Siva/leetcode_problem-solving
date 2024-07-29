#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        vector<int> adjList[n + 1];

        for(auto it : edges){
            int source = it[0];
            int des = it[1];

            adjList[des].push_back(source);
            adjList[source].push_back(des);
        }

        vector<int> dist1(n + 1 , INT_MAX);
        vector<int> dist2(n + 1 , INT_MAX);

        queue<pair<int , int>> qu;
        qu.push({0 , 1});

        while(!qu.empty()){
            int currentDistance = qu.front().first;
            int current = qu.front().second;

            qu.pop();

            if(currentDistance <= dist1[current]){
                dist1[current] = currentDistance;
            }else if(currentDistance < dist2[current]){
                dist2[current] = currentDistance;
            }else{
                continue;
            }

            if(((currentDistance / change) % 2)){
                currentDistance += (change - (currentDistance % change));
            }

            for(auto it : adjList[current]){
                int nextNode = it;
                int newDist = currentDistance + time;

                if(newDist<= dist1[it] || newDist < dist2[it]){
                    qu.push({newDist , it});
                }

            }
        }

        return dist2[n];
    }
};