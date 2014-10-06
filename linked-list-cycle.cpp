/*
 * date: 2014-10-06
 * author: qile68@163.com
 *
 * leetcode problem: https://oj.leetcode.com/problems/linked-list-cycle/
 */

#include <iostream>
#include <vector>
#include <stack>

using namespace std;



// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == NULL)
            return false;
        ListNode* first = head;
        ListNode* second = head;
        while(first != NULL && second != NULL){
            if(first->next == second)
                return true;
            first = first->next;
            if(first == NULL)
                return false;
            first = first->next;
            second = second->next;

        }
        return false;
    }
};

int main(){
    return 0;
}
