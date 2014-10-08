/*
 * date: 2014-10-07
 * author: qile68@163.com
 *
 * leetcode problem: https://oj.leetcode.com/problems/n-queens-ii/
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
    int totalNQueens(int n) {
        if(n < 1)
            return 0;
        vector<int> board;
        board.assign(n,-1);

        // DFS backtracking
        return findSolution(0,board);
    }
    int findSolution(int row, vector<int>& board){
        int len = board.size();
        if(row == len){
            return 1;
        }
        int total = 0;
        for(int i = 0; i < len; i++){
            board[row] = i;
            if(isValid(board,row,i)){
                total += findSolution(row + 1,board);
            }
        }
        return total;
    }
    bool isValid(vector<int>& board,int row,int val){
        for(int i = 0; i < row; i ++){
            if(board[i] == val || abs(board[i] - val) == row -i){
                return false;
            }
        }
        return true;
    }
};

int main(){
    int n = 8;
    Solution sol;
    cout<<n<<" queens have totle "<<sol.totalNQueens(n)<<" Solutions."<<endl;
    return 0;
}
