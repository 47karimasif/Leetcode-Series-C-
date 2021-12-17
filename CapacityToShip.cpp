class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
       int sum=0,max=weights[0],ans;
        for(auto x:weights){
            sum+=x;
            if(x>max){
                max=x;
            }
        }
        int l=max,h=sum;
        while(l<=h){
            int m = (l+h)/2;
            if(possible(weights,m,days)){
                ans=m;
                h=m-1;
            }else{
                l=m+1;
            }
        }
        return ans;
        
    }
    
    bool possible(vector<int>w,int m,int days){
        int d=1,dsum=0;
        for(auto x:w){
            dsum+=x;
            if(dsum>m){
                d++;
                dsum=x;
            }
        }
        if(d<=days){
            return true;
        }
        return false;
    }
};