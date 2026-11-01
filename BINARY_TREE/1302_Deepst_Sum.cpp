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

// Approach 1 :
/*
Observation:
Use DFS to calculate the deepest leaves sum in a single traversal.
If the current level exceeds maxlevel, update maxlevel and reset ans.
If the current level equals maxlevel, add the node value to ans.

Time: O(n)
Space: O(h)
*/

    void helper(TreeNode* root, int &ans , int level,int & maxlevel){
    if(root==NULL) return ;
    if(level>maxlevel){
        maxlevel = level;
        ans = root->val;
    }
    else if(maxlevel==level) ans+=root->val;

    helper(root->left,ans,level+1,maxlevel);
    helper(root->right,ans,level+1,maxlevel);
    }
    int deepestLeavesSum(TreeNode* root) {
        int maxlevel = 0;
        int ans = 0;
        helper(root,ans,1,maxlevel);
        return ans;
    }

// Approach 2 :
/*
Observation:
Use BFS (Level Order Traversal) to calculate the sum
of nodes at each level. Update ans with the current
level's sum. After traversal, ans contains the sum
of the deepest leaves.

Time: O(n)
Space: O(w)
*/ 
 void helper(TreeNode* root, int &ans){
        queue<TreeNode*>q;
        q.push(root);
        while(q.size()>0){
            int n = q.size();
            int sum = 0;
            for(int i =0;i<n;i++){
                TreeNode* tem = q.front();
                q.pop();
                sum+=tem->val;
                if(tem->left) q.push(tem->left);
                if(tem->right) q.push(tem->right);
            }
            ans = sum;
        }
    }
    int deepestLeavesSum(TreeNode* root) {
        int ans = 0;
        helper(root,ans);
        return ans;
    }