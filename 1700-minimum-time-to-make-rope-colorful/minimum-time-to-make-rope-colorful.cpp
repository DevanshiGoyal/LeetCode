class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) 
    {
        // totalTime---> total minimum time req
        int totalTime = 0;
        
        // Traverse through each balloon starting from index 1
        for (int i = 1; i < colors.size(); ++i) 
        {   
            // Compare curr balloon color with prev 
            if (colors[i] == colors[i - 1]) 
            {
                
                // if same, remove the one with smaller neededTime
                totalTime += min(neededTime[i], neededTime[i - 1]);
                
                // Keep the balloon with higher removal time for next comparison
                neededTime[i] = max(neededTime[i], neededTime[i - 1]);
            }
            // if colors differ, continue to the next balloon
        }
        
        // Return the total time required to make the rope colorful
        return totalTime;
 
        
    }
};
// TC---. O(N)
//SC--->O(1)