class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {

        long long sum = 0;
        for(int x : nums) sum += x;

        int rem = sum % p;
        if(rem == 0) return 0;

        unordered_map<int,int> mp;
        mp[0] = -1;

        int ans = nums.size();
        long long prefix = 0;

        for(int i = 0; i < nums.size(); i++){
            prefix = (prefix + nums[i]) % p;
            int need = (prefix - rem + p) % p;
            if(mp.count(need)){
                ans = min(ans, i - mp[need]);
            }
            mp[prefix] = i;
        }
        return ans == nums.size() ? -1 : ans;
    }
};