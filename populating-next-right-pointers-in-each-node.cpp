/*
 * date: 2014-10-03
 * author: qile68@163.com
 *
 * leetcode problem: https://oj.leetcode.com/problems/same-tree/
 */

#include <iostream>

using namespace std;

struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(root == NULL)
            return;
        TreeLinkNode* head = root;
        TreeLinkNode* p = head;
        TreeLinkNode* pre = head;
        while(head != NULL){
            if(head->left == NULL || head->right == NULL)
                break;
            // connect node at the same level
            p = head;
            pre = NULL;
            while(p != NULL){
                p->left->next = p->right;
                if(pre != NULL){
                    pre->next = p->left;
                }
                pre = p->right;
                p = p->next;
            }
            head = head->left;
        }
    }
};

int main(){
    Solution sol;
    sol.connect(NULL);
    return 0;
}
