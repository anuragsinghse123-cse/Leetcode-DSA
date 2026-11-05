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
Use DFS (Root to Leaf traversal) to generate all
possible root-to-leaf numbers.
Maintain a string to store the current path.
Whenever a leaf node is reached, convert the path
into an integer and add it to the total sum.

Time: O(n * h)
Space: O(h^2)
*/
    void helper(TreeNode* root,int &sum,string s){
        if(root==NULL) return;
        s+=to_string(root->val);
        if(root->left==NULL && root->right==NULL){
            sum+=stoi(s);
        }
        helper(root->left,sum,s);
        helper(root->right,sum,s);
    }
    int sumNumbers(TreeNode* root) {
        string s = "";
        int sum = 0;
        helper(root,sum,s);
        return sum;
    }

// Approach 2 :
/*
Observation:
Use DFS (Root to Leaf traversal) to generate all
possible root-to-leaf numbers.
Maintain a number instead of a string to store the
current path.
At each node, update the number using num = num*10 + root->val.
Whenever a leaf node is reached, add the formed number
to the total sum.

Time: O(n)
Space: O(h) due to recursion stack.
*/

    void helper(TreeNode* root,int &sum,int num){
        if(root==NULL) return;
        num= num*10+root->val;
        if(root->left==NULL && root->right==NULL){
            sum+=num;
            return;
        }
        helper(root->left,sum,num);
        helper(root->right,sum,num);
    }
    int sumNumbers(TreeNode* root) {
        int sum = 0;
        helper(root,sum,0);
        return sum;
    }