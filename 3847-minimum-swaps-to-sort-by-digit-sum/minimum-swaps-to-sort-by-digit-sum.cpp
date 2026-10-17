class Solution {
public:
    long long find(int n){

        long long sum = 0 ; 

        while(n > 0){
            sum += n%10 ; 
            n /= 10 ;
        }
        return sum ; 
    }
    int minSwaps(vector<int>& nums) {

        int n = nums.size();
        map<long long ,long long >mp;

        vector<pair<long long ,long long>>a;
        for(int i = 0 ; i < n; i++){
            //calulate the sum 
            long long b = find(nums[i]);

           // Mapping 
            mp[nums[i]]= i;

            a.push_back({b , nums[i]});
        }

        sort(a.begin() , a.end() );

        int ans = 0 ;

        for(int i = 0 ; i < n ; i++){

           if(nums[i] != a[i].second){

                int c = mp[a[i].second];
                mp[nums[i]] = c;
                mp[a[i].second] = i;

                swap(nums[i], nums[c]);

                ans++;
            }
        }

        return ans;
        
    }
};