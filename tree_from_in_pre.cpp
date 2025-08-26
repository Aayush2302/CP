#include<bits/stdc++.h>

using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

  int preIndex = 0;
    unordered_map<int,int>inorderIndex;

    TreeNode* build(vector<int>&preorder,int start,int end){
        if( start > end ){
            return nullptr;
        }
        int rootVal = preorder[preIndex++];
        TreeNode* root = new TreeNode(rootVal);

        int mid = inorderIndex[rootVal];

        root->left = build(preorder,start,mid-1);
        root->right = build(preorder,mid+1,end);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    for(int i = 0; i < inorder.size(); i++){
        inorderIndex[inorder[i]] = i;
    }    

    return build(preorder,0,inorder.size()-1);
    }

  int main(){
    vector<int> preorder = {3,9,20,15,7};
    vector<int> inorder = {9,3,15,20,7};

    TreeNode* root = buildTree(preorder,inorder);

    // Output the root value to verify the tree is built correctly
    cout << "Root value: " << root->val << endl;

    return 0;
  }