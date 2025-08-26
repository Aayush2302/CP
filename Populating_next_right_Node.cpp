#include<bits/stdc++.h>

using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    Node* connect(Node* root) {
         queue<Node*>q;

        if(root == nullptr){
            return root;
        }
        q.push(root);

        while(!q.empty()){
            int size = q.size();
            vector<Node*>level;
            for(int i = 0; i<size;i++){
                Node* node = q.front();
                q.pop();
                if(node->left != nullptr) q.push(node->left);
                if(node->right != nullptr) q.push(node->right);
                level.push_back(node);
            }
            int len = level.size();

          for(int i = 0; i<len-1; i++){
            level[i]->next = level[i+1];
          }  

          
          level[len-1]->next = nullptr;
        }
        return root; 
    }
};

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);

    root->right->left = new Node(6);
    root->right->right = new Node(7);

    
}