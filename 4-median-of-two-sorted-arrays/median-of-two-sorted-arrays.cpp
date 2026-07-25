class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size();
        int n2=nums2.size();
        int ct=0;
        int i=0,j=0;
        int n=n1+n2;
        int midr=n/2;
        int midl=midr-1;
        int val1=-1,val2=-1;
        while(i<n1 && j<n2){
            if(nums1[i]<nums2[j]){
                if(ct==midl)val1=nums1[i];
                if(ct==midr)val2=nums1[i];
                ct++;
                i++;
            }
            else{
                if(ct==midl)val1=nums2[j];
                if(ct==midr)val2=nums2[j];
                ct++;
                j++;
            }
            
        }
        while (i < n1) {
        if (ct == midl)val1 = nums1[i];
        if (ct == midr)val2 = nums1[i];
        ct++;
        i++;
    }
    while (j < n2) {
        if (ct == midl)val1 = nums2[j];
        if (ct == midr)val2 = nums2[j];
        ct++;
        j++;
    }
    if(n%2==0){
        return (double)(val1+val2)/2;
    }else{
        return val2;
    }

        return -1;
    }
};