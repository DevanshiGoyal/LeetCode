class Solution {
public:

    typedef long long ll;

    int n;

    vector<int> getnextSmallerLeft(vector<int>& nums){

        stack<int> st;
        vector<int> NSL(n,-1);

        for(int i=0;i<n;i++){

            while(!st.empty() && nums[st.top()] > nums[i]){
                st.pop();
            }

            if(!st.empty()){
                NSL[i] = st.top();
            }

            st.push(i);
        }

        return NSL;
    }

    vector<int> getnextSmallerRight(vector<int>& nums){

        stack<int> st;
        vector<int> NSR(n,n);

        for(int i=n-1;i>=0;i--){

            while(!st.empty() && nums[st.top()] >= nums[i]){
                st.pop();
            }

            if(!st.empty()){
                NSR[i] = st.top();
            }

            st.push(i);
        }

        return NSR;
    }

    vector<int> getnextGreaterLeft(vector<int>& nums){

        stack<int> st;
        vector<int> NGL(n,-1);

        for(int i=0;i<n;i++){

            while(!st.empty() && nums[st.top()] <= nums[i]){
                st.pop();
            }

            if(!st.empty()){
                NGL[i] = st.top();
            }

            st.push(i);
        }

        return NGL;
    }

    vector<int> getnextGreaterRight(vector<int>& nums){

        stack<int> st;
        vector<int> NGR(n,n);

        for(int i=n-1;i>=0;i--){

            while(!st.empty() && nums[st.top()] < nums[i]){
                st.pop();
            }

            if(!st.empty()){
                NGR[i] = st.top();
            }

            st.push(i);
        }

        return NGR;
    }

    long long maxTotalValue(vector<int>& nums, int k) {

        n = nums.size();

        vector<int> nextSmallerLeft = getnextSmallerLeft(nums);
        vector<int> nextSmallerRight = getnextSmallerRight(nums);

        vector<int> nextGreaterLeft = getnextGreaterLeft(nums);
        vector<int> nextGreaterRight = getnextGreaterRight(nums);

        vector<int> ord(n);

        for(int i=0;i<n;i++){
            ord[i] = i;
        }

        sort(ord.begin(),ord.end(),
        [&](int a,int b){

            if(nums[a] != nums[b]){
                return nums[a] < nums[b];
            }

            return a < b;
        });

        priority_queue<
            pair<ll,pair<int,int>>
        > maxHeap;

        for(int hi=0;hi<n;hi++){

            ll diff =
            (ll)nums[ord[hi]]
            - nums[ord[0]];

            maxHeap.push({
                diff,
                {hi,0}
            });
        }

        ll totalVal = 0;
        ll remaining = k;

        while(remaining > 0 && !maxHeap.empty()){

            ll score = maxHeap.top().first;

            int hi = maxHeap.top().second.first;
            int lo = maxHeap.top().second.second;

            maxHeap.pop();

            int maxValIdx = ord[hi];
            int minValIdx = ord[lo];

            int leftBoundary =
            max(
                nextGreaterLeft[maxValIdx],
                nextSmallerLeft[minValIdx]
            ) + 1;

            int rightBoundary =
            min(
                nextGreaterRight[maxValIdx],
                nextSmallerRight[minValIdx]
            ) - 1;

            int leftIdx =
            min(maxValIdx,minValIdx);

            int rightIdx =
            max(maxValIdx,minValIdx);

            if(leftBoundary <= leftIdx &&
               rightBoundary >= rightIdx){

                ll leftChoices =
                leftIdx - leftBoundary + 1;

                ll rightChoices =
                rightBoundary - rightIdx + 1;

                ll totalSubarrays =
                leftChoices * rightChoices;

                ll take =
                min(remaining,totalSubarrays);

                totalVal += take * score;

                remaining -= take;
            }

            if(lo + 1 <= hi){

                ll newScore =
                (ll)nums[ord[hi]]
                - nums[ord[lo+1]];

                maxHeap.push({
                    newScore,
                    {hi,lo+1}
                });
            }
        }

        return totalVal;
    }
};