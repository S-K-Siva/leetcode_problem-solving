#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        vector<pair<int, pair<int, char>>> robots;
        
        // Create a combined vector of robots with their position, health, and direction
        for (int i = 0; i < n; ++i) {
            robots.push_back({positions[i], {healths[i], directions[i]}});
        }
        
        // Sort robots by their positions
        sort(robots.begin(), robots.end());
        
        // Stack to manage the collision process
        stack<pair<int, pair<int, char>>> robotStack;
        
        // Process each robot
        for (auto& robot : robots) {
            if (robotStack.empty()) {
                robotStack.push(robot);
            } else {
                while (!robotStack.empty()) {
                    auto& topRobot = robotStack.top();
                    
                    // If top robot and current robot are moving in the same direction or there's no collision, push the current robot
                    if (topRobot.second.second == robot.second.second || (topRobot.second.second == 'L' && robot.second.second == 'R')) {
                        robotStack.push(robot);
                        break;
                    } else if (robot.second.second == 'L' && topRobot.second.second == 'R') {
                        // Handle collision
                        if (robot.second.first == topRobot.second.first) {
                            // Both robots have the same health, they destroy each other
                            robotStack.pop();
                            break;
                        } else if (robot.second.first > topRobot.second.first) {
                            // Current robot destroys the top robot
                            robot.second.first -= 1;
                            robotStack.pop();
                            if (robotStack.empty()) {
                                robotStack.push(robot);
                                break;
                            }
                        } else {
                            // Top robot destroys the current robot
                            topRobot.second.first -= 1;
                            break;
                        }
                    }
                }
            }
        }
        
        // Collect the surviving robots' healths in the original order
        unordered_map<int, int> healthMap;
        while (!robotStack.empty()) {
            auto& robot = robotStack.top();
            healthMap[robot.first] = robot.second.first;
            robotStack.pop();
        }
        
        vector<int> result;
        for (int i = 0; i < n; ++i) {
            if (healthMap.count(positions[i])) {
                result.push_back(healthMap[positions[i]]);
            }
        }
        
        return result;
    }
};
