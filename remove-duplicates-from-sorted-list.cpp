/*
 * date: 2014-10-06
 * author: qile68@163.com
 *
 * leetcode problem: https://oj.leetcode.com/problems/remove-duplicates-from-sorted-list/
 */

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if(head == NULL)
            return head;
        ListNode* p = head;
        ListNode* dump = NULL;
        while(p != NULL){
            if(p->next == NULL)
                break;
            if(p->val == p->next->val){
                dump = p->next;
                p->next = p->next->next;
                delete dump;
            }else{
                p = p->next;
            }
        }
        return head;
    }
};

int main(){
    ListNode* root = new ListNode(1);
    root->next = new ListNode(1);
    root->next->next = new ListNode(2);
    root->next->next->next = new ListNode(3);
    root->next->next->next->next = new ListNode(3);

    cout<<"origin list: ";
    ListNode* p = root;
    while(p != NULL){
        cout<<p->val<<" ";
        p = p->next;
    }
    cout<<endl;
    Solution sol;
    ListNode* result = sol.deleteDuplicates(root);
    p = result;
    while(p != NULL){
        cout<<p->val<<" ";
        p = p->next;
    }
    cout<<endl;
    p = result;
    while(p != NULL){
        result = p;
        p = p->next;
        delete result;
    }

}

