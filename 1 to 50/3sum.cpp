/*the input array is sorted and we have to find the triplets which sum up to zero. We can use two pointer approach to solve this problem. We will fix one element and then use two pointers to find the other two elements which sum up to the negative of the fixed element. We will also skip the duplicate elements to avoid duplicate triplets in the result.
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
    public:
    vector<int> threeSum(vector<int>& nums){
        vector<vector<int>> res;
        int n =nums.size();
        sort(nums.begin(), nums.end());
        for(int i=0;i<n-2;i++){
            if(i>0 && nums[i]==nums[i-1]) continue; // skip duplicate elements
            int target = -nums[i];
            int j = i+1;
            int k = n-1;
            while(j<k){
                int sum = nums[j]+nums[k];
                if(sum==target){
                    res.push_back({nums[i], nums[j], nums[k]});
                    while(j<k && nums[j]==nums[j+1]) j++; // skip duplicate elements
                    while(j<k && nums[k]==nums[k-1]) k--; // skip duplicate elements
                    j++;
                    k--;
                }
                else if(sum<target){
                    j++;
                }
                else{
                    k--;
                }
            }
        }
        return {res};
    }
}