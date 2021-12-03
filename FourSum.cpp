class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>finalAns;
        for(int i=0;i<nums.size();i++){
            if(i!=0 and nums[i]==nums[i-1]){
                continue;
            }
            vector<int>numscopy(nums.begin()+i+1,nums.end());
            vector<vector<int>>tmp = threeSum(numscopy,target-nums[i]);
            for(auto x:tmp){
                x.insert(x.begin(),nums[i]);
                finalAns.push_back(x);
            }
        }
        return finalAns;
        
    }
    vector<vector<int>> threeSum(vector<int>& nums,int target) {
        vector<vector<int>>ans;
        for(int i=0;i<nums.size();i++){
            if(i!=0 and nums[i]==nums[i-1]){
                continue;
            }
            int j=i+1,k=nums.size()-1;
            while(j<k){
                if(j!=i+1 and nums[j]==nums[j-1] ){
                    j++;
                    continue;
                }
            long long sum=nums[i];
              sum+=nums[j]+nums[k];
                if(sum>target){
                    k--;
                }else if(sum<target){
                    j++;
                }
                else{
                    vector<int>tmp;
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