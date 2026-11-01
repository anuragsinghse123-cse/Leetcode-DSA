#include<iostream>
using namespace std;
/*
Observation:
Instead of incrementing n-1 elements, consider decrementing
one element in each operation.

Make every element equal to the minimum element.
The required operations are the sum of differences between
each element and the minimum element.

Answer = sum - (minimum * n)

Time: O(n)
Space: O(1)
*/
    int minMoves(vector<int>& nums) {
        int sum = 0;
        int mn = INT_MAX;
        for(int i =0;i<nums.size();i++){
            sum+=nums[i];
            mn = min(mn,nums[i]);
        }
        return sum - mn*nums.size();
    }