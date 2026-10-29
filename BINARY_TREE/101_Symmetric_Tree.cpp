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

/*
Observation: Use a queue to compare mirror node pairs.
Push (left, right) and compare their values.
Then push (left->left, right->right) and
(left->right, right->left).

Time: O(n)
Space: O(n)
*/

    bool isSymmetric(TreeNode* root) {
       queue<TreeNode*>q;
       q.push(root->left);
       q.push(root->right);
       while(q.size()>0){
        TreeNode * l = q.front();
        q.pop();
        TreeNode * r = q.front();
        q.pop();
        if(!l && !r) continue;
        if(!l || !r) return false;
        if(l->val != r->val ) return false;
        
        q.push(l->left);
        q.push(r->right);

        q.push(l->right);
        q.push(r->left);

       }
       return true;
    }

    /*
Observation: Compare mirror nodes recursively.
Check left->left with right->right and
left->right with right->left.

Time: O(n)
Space: O(h)
*/

    bool helper(TreeNode*l,TreeNode * r ){
        if(!l && !r) return true;
        if(!l||!r) return false;
        if(l->val!=r->val) return false;
       return helper(l->left,r->right) && helper(l->right,r->left);
    }
    bool isSymmetric(TreeNode* root) {
        return helper(root->left,root->right);
    }
