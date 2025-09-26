class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        // Brute force approach
        // using simplee iteration
        vector<int> ans  ;
        int cnt = 0 ;
        for(int i = 0 ; i<nums1.size() ; i++){
           
            for(int j = 0 ; j<nums2.size()-1 ;j++){

                if(nums1[i] == nums2[j]){
                    for(int k = j ; k<nums2.size() ; k++){
                        if(nums2[k]> nums1[i]){
                            ans.push_back(nums2[k]);
                            cnt+=1;
                            break;
                        }
                    }
                    if(cnt>0) break;
                    
                    
                }
                cnt = 0 ;
            }
            if(cnt == 0 ){
                ans.push_back(-1);
            }
        }
        return ans ;
        
    }
};