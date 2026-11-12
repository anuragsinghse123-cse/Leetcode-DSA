#include<iostream>
#include<vector>
using namespace std;

    int longestMonotonicSubarray(vector<int>& nums) {
        int j = 0;
        int inc =1;
        int dec = 1;
        int ans = 1;
        while(j<nums.size()){
         if(j>0 && nums[j]>nums[j-1]){
            inc++;
            dec = 1;
         }
         else if(j>0 && nums[j]<nums[j-1]){
            dec++;
            inc = 1;
         }
         else {
            inc = 1;
            dec = 1;
         }
         ans = max(ans,max(inc,dec));
         j++;
        }
        return ans;
    }