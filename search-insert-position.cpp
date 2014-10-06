/*
 * date: 2014-10-06
 * author: qile68@163.com
 *
 * leetcode problem: https://oj.leetcode.com/problems/search-insert-position/
 */

#include <iostream>

using namespace std;

class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        if(n < 1)
            return 0;
        int idx = search(A,true,0,n-1,target);
        return idx < 0 ? 0 : idx;
    }
    int search(int A[],bool prehalf,int begin,int end,int target){
        if(end < begin){
            if(prehalf)
                return begin;
            else
                return end + 1;
        }
        if((end - begin) == 0){
            if(A[begin] == target){
                return begin;
            }else if(A[begin] > target){
                return begin;
            }else{
                return begin + 1;
            }
        }
        int mid = (begin + end)/2;
        if(target == A[mid])
            return mid;
        if(target < A[mid]){
            return search(A,true,begin,mid-1,target);
        }else{
            return search(A,false,mid+1,end,target);
        }
    }
};

int main(){
    int A[] = {1,3};
    int length = sizeof(A)/sizeof(int);
    Solution sol;
    cout<<"Array: ";
    for(int i = 0; i < length; i++){
        cout<<A[i]<<" ";
    }
    cout<<endl;

    int target = 5;
    cout<<"SearchInsert target: "<<target<<" position: "<<sol.searchInsert(A,length,target)<<endl;
    target = 2;
    cout<<"SearchInsert target: "<<target<<" position: "<<sol.searchInsert(A,length,target)<<endl;
    target = 7;
    cout<<"SearchInsert target: "<<target<<" position: "<<sol.searchInsert(A,length,target)<<endl;
    target = 0;
    cout<<"SearchInsert target: "<<target<<" position: "<<sol.searchInsert(A,length,target)<<endl;
}
