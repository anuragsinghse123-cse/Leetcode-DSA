/*
class Solution{
public :
TreeNode *iop(TreeNode* root){
 if(root==NULL) return root;
 TreeNode* pred = root->left;
 while(pred->right){
  pred = pred->right;
 }
  return pred;
}

 TreeNode* deleteNode(TreeNode* root, int key){
 if(root==NULL) return root;

 if(root->val==key){
  if(root->left==NULL && root->right==NULL) return NULL;

  else if(root->left==NULL || root->right==NULL){
   if(root->left) return root->left;

   else return root->right;
  }

  else{
   TreeNode * temp = iop(root);
   root->val = temp->val;
   root->left= deleteNode(root->left,root->val);
  }

 }
  else if(root->val>key){
  root->left = deleteNode(root->left,key);
  }
  else {
  root->right = deleteNode(root->right,key);
  }
  return root;
 }
}
*/