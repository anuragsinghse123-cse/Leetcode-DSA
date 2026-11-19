#include<bits/stdc++.h>

using namespace std;

    int minimizeSum(vector<int>& nums) {
        if(nums.size()==3) return 0;
        sort(nums.begin(),nums.end());
       int n = nums.size();
       return min({
        nums[n-1]-nums[2],
        nums[n-2] - nums[1],
        nums[n-3] - nums[0]
       });
    }

    int minimizeSum(vector<int>& nums) {
        if(nums.size()==3) return 0;
        int mx1 = INT_MIN, mx2 = INT_MIN, mx3 = INT_MIN;
        int mn1 = INT_MAX, mn2 = INT_MAX , mn3= INT_MAX;
        for(int i= 0;i<nums.size();i++){
            if(nums[i]<mn1){
                mn3 = mn2;
                mn2 = mn1;
                mn1 = nums[i];
            }
            else if(nums[i]<mn2){
                mn3 = mn2;
                mn2 = nums[i];
            }
            else if(nums[i]<mn3){
                mn3 = nums[i];
            }
            if(mx1<nums[i]){
                mx3 = mx2;
                mx2 = mx1;
                mx1 = nums[i];
            }
            else if(mx2<nums[i]){
                mx3 = mx2;
                mx2 = nums[i];
            }
            else if(mx3<nums[i]){
                mx3 = nums[i];
            }
        }
        return min({mx1-mn3,mx2-mn2,mx3-mn1});
    }    
