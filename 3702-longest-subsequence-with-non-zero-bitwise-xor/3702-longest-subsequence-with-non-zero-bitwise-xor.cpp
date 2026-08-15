class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        auto tot=0,nonzero=0;
        for(auto &n:nums){
            nonzero |=n>0;
            tot^=n;
        }
        return nonzero*(nums.size()-!tot);
        
    }
};