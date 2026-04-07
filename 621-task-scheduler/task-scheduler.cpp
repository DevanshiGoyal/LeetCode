class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        // edge cases 
        if(n==0) return tasks.size(); // no cooldown
        int freq[26] ={0} ;

        for(int i = 0 ; i<tasks.size() ; i++){
            freq[tasks[i] - 'A']++;
        }

        priority_queue<int> maxHeap ;

        for(int f : freq){
            if(f>0) maxHeap.push(f);
        }

        int ans = 0 ; 

        while(!maxHeap.empty()){
            int taskcycle = 0 ; // no of tasks executed in curr cycle 

            int cycle = n+1 ;// each cycle len

            vector<int> temp ;

            while(cycle>0 && !maxHeap.empty()){
                int curr = maxHeap.top();  // task with high freq
                maxHeap.pop(); 
                if(curr>1){
                    temp.push_back(curr-1);
                }
                taskcycle++; //1 task exec.
                cycle--;

            }

            for(int ele : temp){  // reinsert rem tasks
                maxHeap.push(ele) ;

            }

            if(!maxHeap.empty()){
                ans+= n+1;  // full cycle (n+1)
            }else{
                ans+=taskcycle;  // last cycle (no idle) 
            }
        }

        return ans ;
        
    }
};