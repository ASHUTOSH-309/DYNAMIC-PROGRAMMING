#include <bits/stdc++.h>
#include <iostream>

using namespace std;

class Solution
{
public:
    void GenerateSubsequences(int index, vector<int> &ds, vector<int> &nums,
                              vector<vector<int>> &ans)
    {

        if (index == nums.size())
        {
            ans.push_back(ds);
            return;
        }
        // Pick current Element
        ds.push_back(nums[index]);
        GenerateSubsequences(index + 1, ds, nums, ans);
        ds.pop_back();
        GenerateSubsequences(index + 1, ds, nums, ans);
    }

    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> ans;
        vector<int> ds;
        GenerateSubsequences(0, ds, nums, ans);

        return ans;
    }
};