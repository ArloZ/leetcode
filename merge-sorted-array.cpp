/*
 * date: 2014-10-09
 * author: qile68@163.com
 *
 * leetcode problem: https://oj.leetcode.com/problems/merge-sorted-array/
 */

#include <iostream>

using namespace std;

class Solution {
    public:
    void merge(int A[], int m, int B[], int n) {
        int i = m - 1;
        int j = n - 1;
        int idx = m + n - 1;
        while(i >= 0 && j >= 0){
            if(A[i] > B[j]){
                A[idx--] = A[i--];
            }else{
                A[idx--] = B[j--];
            }
        }
        while(i >= 0){
            A[idx--] = A[i--];
        }
        while(j >= 0){
            A[idx--] = B[j--];
        }
    }
};

int main(){
    int m = 4;
    int n = 5;
    int A[10] = {1,2,3,4};
    int B[6] = {1,3,5,7,8,9};

    cout<<"Array A: "<<endl;
    for(int i = 0; i < m; i++){
        cout<<A[i]<<" ";
    }
    cout<<endl;

    cout<<"Array B: "<<endl;
    for(int i = 0; i < n; i++){
        cout<<B[i]<<" ";
    }
    cout<<endl;

    Solution sol;
    sol.merge(A,m,B,n);
    cout<<"merge Array: "<<endl;
    for(int i = 0; i < m+n; i++){
        cout<<A[i]<<" ";
    }
    cout<<endl;

}
