/*
 * date: 2014-10-07
 * author: qile68@163.com
 *
 * leetcode problem: https://oj.leetcode.com/problems/n-queens/
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
    vector<vector<string> > solveNQueens(int n) {
        vector<vector<string> > result;
        if(n < 1)
            return result;
        vector<int> board;
        board.assign(n,-1);

        // DFS backtracking
        findSolution(result,0,board);

        return result;
    }
    void findSolution(vector<vector<string> >& res,int row, vector<int>& board){
        int len = board.size();
        if(row == len){
            res.push_back(oneSolution(board));
            return;
        }
        for(int i = 0; i < len; i++){
            board[row] = i;
            if(isValid(board,row,i)){
                findSolution(res,row + 1,board);
            }
        }
        return;
    }
    bool isValid(vector<int>& board,int row,int val){
        for(int i = 0; i < row; i ++){
            if(board[i] == val || abs(board[i] - val) == row -i){
                return false;
            }
        }
        return true;
    }
    vector<string> oneSolution(vector<int>& sol){
        vector<string> result;
        int len = sol.size();
        int i,j;
        string str;
        for(i = 0; i < len; i ++){
            str = "";
            for(j = 0; j < len; j++){
                if(sol[i] == j){
                    str += "Q";
                }else{
                    str += ".";
                }
            }
            result.push_back(str);
        }
        return result;
    }
};

int main(){
    int n = 1;
    Solution sol;
    vector<vector<string> > res = sol.solveNQueens(n);
    // print solutions
    for(int i = 0; i < res.size(); i++){
        cout<<"---- Solution "<<i<<endl;
        for(int j = 0; j < res[i].size(); j ++){
            cout<<res[i][j]<<endl;
        }
    }
    return 0;
}
