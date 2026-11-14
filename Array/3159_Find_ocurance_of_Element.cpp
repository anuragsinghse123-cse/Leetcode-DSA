#include<iostream>
#include<vector>
using namespace std;

    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries, int x) {
        vector<int>index;
        for(int i = 0;i<nums.size();i++){
            if(nums[i]==x){
                index.push_back(i);
            }
        }
        for(int i = 0;i<queries.size();i++){
            if(queries[i]>index.size()){
                queries[i]=-1;
            }
            else {
                queries[i]= index[queries[i]-1];
            }
        }
        return queries;
    }