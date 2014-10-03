/*
 * date: 2014-10-03
 * author: qile68@163.com
 *
 * leetcode problem: https://oj.leetcode.com/problems/same-tree/
 */

#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isSameTree(TreeNode *p, TreeNode *q) {
        if(p == q)
            return true;
        if(!p || !q)
            return false;
        return ((p->val == q->val) && isSameTree(p->left,q->left) && isSameTree(p->right,q->right));
    }
};

int main(){
    // create a tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(2);
    root->right->right = new TreeNode(2);
    root->right->right->left = new TreeNode(2);

    TreeNode* root2 = new TreeNode(1);
    root2->left = new TreeNode(2);
    root2->right = new TreeNode(2);
    root2->right->left = new TreeNode(2);
    root2->right->right = new TreeNode(2);
    root2->right->right->left = new TreeNode(2);

    Solution sol;
    cout<<"Is same tree: "<<sol.isSameTree(root,root2)<<endl;
    return 0;
}
