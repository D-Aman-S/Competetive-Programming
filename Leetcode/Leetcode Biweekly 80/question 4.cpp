//link:https://leetcode.com/problems/count-subarrays-with-score-less-than-k

class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int n=nums.size();
        vector<long long> pref(n+1,0);
        for(int i=1;i<=nums.size();i++){
            pref[i]=pref[i-1]+nums[i-1];
        }
        int i=0,j=1;
        long long c=0;

        while(j<=n){
            long long sum=pref[j]-pref[i];
            long long prod=(sum*(j-i));
            if(prod<k){
                c+=(j-i);
                j++;
            }
           else{
                i++;
            }        
         }
       return c;

    }
};
