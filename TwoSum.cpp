class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>ans;
        map<int,int>mp;
        for (int i=0;i<nums.size();i++){
            int firstValue = nums[i];
            int secondValue = target-nums[i];
            auto itr = mp.find(secondValue);
            if(itr!=mp.end()){
                ans.push_back(itr->second);
                ans.push_back(i);
                break;
            }
            mp.insert({firstValue,i});
        }
        return ans;
    }
};