/*
 * date: 2014-10-08
 * author: qile68@163.com
 *
 * leetcode problem: https://oj.leetcode.com/problems/remove-duplicates-from-sorted-array/
 */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
    public:
    int removeDuplicates(int A[], int n) {
        if(n < 1) return 0;
        int pre = A[0];
        int len = 1;
        int i,j,k;
        for(i = 1; i < n; i ++){
            if(A[i] != pre){
                A[len++] = A[i];
                pre = A[i];
            }
        }
        return len;
    }
};

int main(){
    int A[] = {1,1,2,3,4,5,5,6,7,7};
    int n = sizeof(A)/sizeof(int);

    cout<<"Array: "<<endl;
    for(int i = 0; i < n; i++){
        cout<<A[i]<<" ";
    }
    cout<<endl;

    Solution sol;
    int n1 = sol.removeDuplicates(A,n);

    cout<<"After Remove: "<<endl;
    for(int i = 0; i < n1; i++){
        cout<<A[i]<<" ";
    }
    cout<<endl;

}
