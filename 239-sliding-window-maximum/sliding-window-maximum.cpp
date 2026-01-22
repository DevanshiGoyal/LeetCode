class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        int n = nums.size() ;
        priority_queue<pair<int , int>> pq ; // {(nums[i] , i)};

        vector<int> ans(n-k+1) ; // no of windows n-k+1
        // TC---> O(k ·log k)
        for(int i = 0 ; i<k ; i++){
            pq.push({nums[i] , i}) ;
        }

        ans[0] = pq.top().first ;
        //(n-k)
        for(int i = k ; i<n ; i++){
            while(!pq.empty() && pq.top().second <=(i-k)){ // just outside the window
                pq.pop() ; // remove the ele not in window 
            }
            pq.push({nums[i] , i});
            ans[i-k+1] = pq.top().first ;
        }

        return ans ;
        
    }
};

// DRY RUN 
/*
 nums = [1,3,-1,-3,5] n = 5
k = 3

1 window 
(3,1), (1,0), (-1,2)

ans[0] = 3

2 window  i = 3 = k  (1, 0) remove  push(-3 , 3)
(3,1)(pq.top), (-1,2), (-3,3)

ans[1] = 3

Window 3 , i = 4  (3,1) remove push(5,4)
(5,4), (-1,2), (-3,3)

ans[2] = 5

ans=[3 , 3 , 5] // no of elements = 5-3+1 = 3


Time: O(n log n)

Space: O(n) (heap storage)
*/

