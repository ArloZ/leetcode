/*
 * date: 2014-10-09
 * author: qile68@163.com
 *
 * leetcode problem: https://oj.leetcode.com/problems/swap-nodes-in-pairs/
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
    ListNode *swapPairs(ListNode *head) {
        if(head == NULL || head->next == NULL)
            return head;
        ListNode* node = head;
        ListNode* tmp = NULL;
        head = head->next;
        node->next = head->next;
        head->next = node;
        ListNode* pre = node;
        node = node->next;
        while(node != NULL && node->next != NULL){
            tmp = node->next;
            node->next = tmp->next;
            tmp->next = node;
            pre->next = tmp;
            node = tmp->next->next;
            pre = tmp->next;
        }

        return head;
    }
};

int main(){
    ListNode* l = new ListNode(2);
    l->next = new ListNode(5);
    l->next->next = new ListNode(3);
    l->next->next->next = new ListNode(4);
    l->next->next->next->next = new ListNode(6);
    l->next->next->next->next->next = new ListNode(2);
    l->next->next->next->next->next->next = new ListNode(2);

    cout<<"List: "<<endl;
    ListNode* p = l;
    while(p != NULL){
        cout<<p->val<<" ";
        p = p->next;
    }
    cout<<endl;

    Solution sol;
    cout<<"After swap List: "<<endl;
    p = sol.swapPairs(l);
    while(p != NULL){
        cout<<p->val<<" ";
        p = p->next;
    }
    cout<<endl;
    return 0;
}

