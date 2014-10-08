/*
 * date: 2014-10-08
 * author: qile68@163.com
 *
 * leetcode problem: https://oj.leetcode.com/problems/remove-element/
 */

#include <iostream>

using namespace std;

class Solution {
    public:
    int removeElement(int A[], int n, int elem) {
        if(n < 0) return 0;
        int end = n -1;
        int begin = 0;
        for(begin = 0; begin < n; begin++){
            if(A[begin] == elem){
                while(end >= 0 && A[end] == elem){
                    end --;
                }
                A[begin] = A[end--];
            }
            if(begin > end){
                break;
            }
        }
        return begin;
    }
};

int main(){
    int A[] = {2,1,2,2,2,2,3,4,5};
    int n = sizeof(A)/sizeof(int);
    cout<<"Array:"<<endl;
    for(int i = 0; i < n; i++){
        cout<<A[i]<<" ";
    }
    cout<<endl;
    int elem = 2;
    Solution sol;
    cout<<"Remove element "<<elem<<" and remain length is: "<<sol.removeElement(A,n,elem)<<endl;
    return 0;
}
