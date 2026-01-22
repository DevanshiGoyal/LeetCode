/*
using deque approach   ---> montonic decreasing 
1  When new ele comes nums[i] , make space fo fit (window size can't be greater than k )
2  when nums[i] > deque ele no need to keep small ele in that window , pop them

3  push i in deque ---> for nums[i]

4  if(i>= k-1) , deq.front() is oue ans for that window 

*/
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size() ;

        deque<int> deq;

        vector<int> result ;

        for(int i = 0 ; i<n ; i++){
            // make space for nums[i] 
            // <=i-k
            while(!deq.empty() && deq.front() <= i-k){
                deq.pop_front() ;
            }
            // no need to keep small ele --> monotonic decreasing 
            while(!deq.empty() && nums[i] >= nums[deq.back()]){
                deq.pop_back();

            }
            deq.push_back(i) ;

            // add max for current window
            if(i>=k-1){
                result.push_back(nums[deq.front()]) ;
            }

        }
        return result ;        
        
    }
};

// tc-->o(N)  sc--> O(k)