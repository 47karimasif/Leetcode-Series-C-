class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++)
        {
            if (i != 0 and nums[i] == nums[i - 1])
            {
                continue;
            }
            int j = i + 1, k = nums.size() - 1;
            while (j < k)
            {
                if (j != i + 1 and nums[j] == nums[j - 1])
                {
                    j++;
                    continue;
                }
                int sum = nums[i] + nums[j] + nums[k];
                if (sum > 0)
                {
                    k--;
                }
                else if (sum < 0)
                {
                    j++;
                }
                else
                {
                    vector<int> tmp;
                    tmp.push_back(nums[i]);
                    tmp.push_back(nums[j]);
                    tmp.push_back(nums[k]);
                    ans.push_back(tmp);
                    tmp.clear();
                    j++;
                    k--;
                }
            }
        }
        return ans;
    }
};