/*
 * date: 2014-10-08
 * author: qile68@163.com
 *
 * leetcode problem: https://oj.leetcode.com/problems/merge-two-sorted-lists/
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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;

        ListNode* p = NULL;
        if(l1->val > l2->val){
            p = l2;
            l2 = l2->next;
        }else{
            p = l1;
            l1 = l1->next;
        }
        cout<<"head "<<p->val<<endl;
        ListNode* res = p;
        while(l1 != NULL && l2 != NULL){
            if(l1->val > l2->val){
                p->next = l2;
                l2 = l2->next;
            }else{
                p->next = l1;
                l1 = l1->next;
            }
            p = p->next;
        }
        if(l1 == NULL)
            p->next = l2;
        if(l2 == NULL)
            p->next = l1;
        return res;
    }
};

int main(){
    ListNode* l1 = new ListNode(2);
    ListNode* l2 = new ListNode(1);
    Solution sol;
    ListNode* res = sol.mergeTwoLists(l1,l2);
    while(res != NULL)
    {
        cout<<res->val<<" ";
        res = res->next;
    }

    return 0;
}
