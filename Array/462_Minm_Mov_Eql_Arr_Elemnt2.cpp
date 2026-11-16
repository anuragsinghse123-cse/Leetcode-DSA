#include <bits/stdc++.h>
using namespace std;

    int minMoves2(vector<int>& nums) {
    int n = nums.size();
    sort(nums.begin(),nums.end());
    int ans = 0;
    for(int i = 0;i<n/2;i++){
      ans+=(nums[n/2]-nums[i]);
    }
    for(int i = n/2;i<n;i++){
        ans+=(nums[i]-nums[n/2]);
    } 
    return ans;      
    }
