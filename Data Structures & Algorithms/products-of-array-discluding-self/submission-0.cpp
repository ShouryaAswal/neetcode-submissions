class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n);
        vector<int> xiferp(n);
        int mult = 1;
        int tlum = 1;

        for(int i=0; i<n; i++)
        {
            mult = nums[i]*mult;
            prefix[i] = mult;

            tlum = nums[n-i-1]*tlum;
            xiferp[n-i-1] = tlum;
        }

        vector<int> ans(n);
        ans[0] = xiferp[1];
        ans[n-1] = prefix[n-2];

        for(int i=1; i<n-1; i++)
        {
            ans[i] = prefix[i-1] * xiferp[i+1];
        }

        return ans;
    }
};
