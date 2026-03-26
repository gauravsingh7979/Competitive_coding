class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k<=1) return 0;
        int l=0,r=1,ans=0;

        for(int i=0;i<nums.size();i++){
         r*=nums[i];
         while(r>=k){
            r/=nums[l];
            l++;
         }
         ans+=(i-l)+1;
        }
        return ans;
    }
};