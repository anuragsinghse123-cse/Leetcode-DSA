#include<iostream>
#include<queue>
using namespace std;
/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

    void helper(TreeNode* root , vector<int>& ans){
        TreeNode* curr = root;
        while(curr!=NULL){
            if(curr->left){
                TreeNode* pred = curr->left;
                while(pred->right!=curr && pred->right!= NULL){
                    pred = pred->right;
                }
                if(!pred->right){
                    pred->right = curr;
                    curr= curr->left;
                }
            
            else{
                ans.push_back(curr->val);
                pred->right = NULL;
                curr=curr->right;
            }
            }
            else{
                ans.push_back(curr->val);
                curr= curr->right;
            }
        }
    }
    vector<int> merge(vector<int>ans1,vector<int>ans2){
        vector<int>ans;
        int i = 0;
        int j = 0;
        while(i<ans1.size() && j<ans2.size()){
            if(ans1[i]<=ans2[j]){
                ans.push_back(ans1[i]);
                i++;
            }
            else{
                ans.push_back(ans2[j]);
                j++;
            }
        }
        while(i<ans1.size()){
                ans.push_back(ans1[i]);
                i++;            
        }
        while(j<ans2.size()){
            ans.push_back(ans2[j]);
            j++;
        }
        return ans;
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int>ans1;
        vector<int>ans2;
        helper(root1,ans1);
        helper(root2,ans2);
        return merge(ans1,ans2);
    }