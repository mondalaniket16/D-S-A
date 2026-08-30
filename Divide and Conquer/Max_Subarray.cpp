/*
53. Maximum Subarray

Given an integer array nums, find the subarray with the largest sum, and return its sum.

Example 1:
Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: The subarray [4,-1,2,1] has the largest sum 6.

Example 2:
Input: nums = [1]
Output: 1
Explanation: The subarray [1] has the largest sum 1.

Example 3:
Input: nums = [5,4,-1,7,8]
Output: 23
Explanation: The subarray [5,4,-1,7,8] has the largest sum 23.

SPECIAL TEST CASES: 
[-1,-2,-3,0] --> 0
[-2,1]  --> 1
[1] ---> 1

Time complexity: O(n log n)
Space complexity: O(log n) due to recursion.
 
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int crossSum(vector<int>& nums, int l, int mid, int r)
    {
        int lsum = 0;
        int rsum = 0;
        int maxL = INT_MIN;
        int maxR = INT_MIN;

        for(int i = mid; i >= l; i--)
        {
            lsum += nums[i];
            maxL = max(lsum, maxL);
        }

        for(int i = mid + 1; i <= r; i++)
        {
            rsum += nums[i];
            maxR = max(rsum, maxR);
        }

        return maxL + maxR;
    }
    int maxSum(vector<int>& nums, int l, int r)
    {
        if(l == r)
            return nums[l];

        int mid = l + (r - l) / 2;
        int left = maxSum(nums, l, mid);
        int right = maxSum(nums, mid + 1, r);
        int cross = crossSum(nums, l, mid, r);
        return max(cross, max(left, right));
    }
    int maxSubArray(vector<int>& nums)
    {
        int n = nums.size();
        int l = 0;
        int r = n - 1;

        return maxSum(nums, l, r);
    }
};

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    Solution obj;
    cout << obj.maxSubArray(nums);
    return 0;
}