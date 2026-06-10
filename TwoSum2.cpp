/*The input array is sorted so look for better approach -- use two pointers i and j such that  if it matches the target return otherwise if sum is less than target then i++ otherwise j--.
 */
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        int n = nums.size();
        int i = 0;
        int j = n - 1;
        while (i < j)
        {
            int sum = nums[i] + nums[j];
            if (sum == target)
            {
                return {i + 1, j + 1};
            }
            else if (sum < target)
            {
                i++;
            }
            else
            {
                j--;
            }
        }
        return {};
    }
};

int
main()
{
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    Solution s;
    vector<int> ans = s.twoSum(nums, target);// why ans array decalared here? because we want to store the result of twoSum function which is a vector of integers and then we can print it.
    for (int i = 0; i < ans.size(); i++)// for(auto i:ans) is also valid adn for (int i:ans) is also valid
    {
        cout << ans[i] << " ";
    }
    return 0;
}