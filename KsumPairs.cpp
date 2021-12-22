class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        map<int,int>mp;
        int count=0;
        for(int i=0;i<nums.size();i++){
            int key=nums[i];
            int value = k-key;
            auto itr = mp.find(value);
            if(itr!=mp.end()){
               count++;
               itr->second==1 ? mp.erase(itr->first):itr->second--;
            }else{
                mp[key]++;
            }
        }
        return count;
        
    }
};