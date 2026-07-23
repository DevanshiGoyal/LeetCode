class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& v) {
        //TC-O(NlogN + 2N)
        //SC-O(N)
        /*int n=v.size();
        sort(v.begin(),v.end());
        vector<vector<int>> ans;

        for(int i=0;i<n;i++)
        {
            int s=v[i][0];
            int e=v[i][1];

            if(!ans.empty() && e<=ans.back()[1])
            continue;

            for(int j=i+1;j<n;j++)
            {
                if(v[j][0] <= e)
                e=max(e,v[j][1]);

                else
                break;
            }
        ans.push_back({s,e});
        }
    return ans;*/
    //TC-O(NlogN + N)
    //SC-O(N)
    int n=v.size();
    sort(v.begin(),v.end());
    vector<vector<int>> ans;

    for(int i=0;i<n;i++)
    {
        if(ans.empty() || v[i][0]>ans.back()[1])
        ans.push_back(v[i]);
        else
        ans.back()[1]=max(ans.back()[1],v[i][1]);
    }
    return ans;
    }
};