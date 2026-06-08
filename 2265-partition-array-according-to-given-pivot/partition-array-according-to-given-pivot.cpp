class Solution 
{
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) 
    {
        vector<int> before, after;
        int pivotCount = 0, j = 0;

        
        for (int num : nums) 
        {
            if (num < pivot)
            {
                before.push_back(num);
            } 
            else if (num > pivot)
            {
                after.push_back(num);
            } 
            else
            {
                pivotCount++;
            } 
        }

       
        for (int num : before)
        {
            nums[j++] = num;
        } 
        
        while (pivotCount--)
        {
            nums[j++] = pivot;
        } 
        
        for (int num : after)
        {
            nums[j++] = num;
        } 

        return nums;
    }
};

// tc-->O(n)  sc-->O(n)