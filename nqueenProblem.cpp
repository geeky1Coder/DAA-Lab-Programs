#include <bits/stdc++.h>
using namespace std;

bool isPos(vector<vector<int>> board,int col,int row){
    int n=board.size();
    if(col==0){
        return true;
    }
    //row check
    for(int c=0;c<col;++c){
        if(board[row][c]){
            return false;
        }
    }
    
    int pos1=row+1;
    int pos2=row-1;
    int c=col-1;
    //upper diagonal
    while(pos2>=0&&c>=0){
        if(board[pos2][c]){
            return false;
        }
        pos2--;
        c--;
    }
    c=col-1;
    //lower diagonal
    while(pos1<n&&c>=0){
        if(board[pos1][c]){
            return false;
        }
        pos1++;
        c--;
    }
    return true;
}
bool nQueen(vector<vector<int>> &board,int col,int n){
    if(col==n){
        //possible solution found
        return true;
    }
    for(int i=0;i<n;++i){
        board[i][col]=1;
        if(isPos(board,col,i) && nQueen(board,(col+1),n)){
            return true;
        }
        //backtrack
        board[i][col]=0;
    }
    return false;
}
int main(){
    vector<vector<int>> board={
        {0,0,0,0},
        {0,0,0,0},
        {0,0,0,0},
        {0,0,0,0}
    };
    nQueen(board,0,4);
    for(auto el:board){
        for(auto c:el){
            cout<<c<<" ";
        }
        cout<<endl;
    }
    return 0;
}