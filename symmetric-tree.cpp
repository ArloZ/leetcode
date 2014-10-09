/*
 * date: 2014-10-09
 * author: qile68@163.com
 *
 * leetcode problem: https://oj.leetcode.com/problems/symmetric-tree/
 */

#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isSymmetric(TreeNode *root) {
        if(root == NULL) return true;
        return symmetric(root->left,root->right);
    }
    bool symmetric(TreeNode* p,TreeNode* q){
        if(p == q) return true;
        if(!p || !q) return false;

        return p->val == q->val && symmetric(p->left,q->right) && symmetric(p->right,q->left);
    }

};

int main(){
    /*
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);
    */
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(3);
    root->right->left = new TreeNode(2);

    Solution sol;
    cout<<"Tree is symmetric: "<<sol.isSymmetric(root)<<endl;
}
