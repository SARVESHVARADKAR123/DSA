class Solution {
public:

    bool issafe(int row,int col,vector<string>&board,int n,vector<bool>& rowcheck,vector<bool>&lowdiagcheck,vector<bool> &updiagcheck){
        int duprow=row;
        int dupcol=col;

        if(rowcheck[row]){
            return false;
        }
        if(lowdiagcheck[row+col]){
            return false;
        }
        if(updiagcheck[(n-1)+(col-row)]){
            return false;
        }
        return true;
    }

    void nqueen(int col,int n,vector<vector<string>>&ans,vector<string>&board,vector<bool>& rowcheck,vector<bool>&lowdiagcheck,vector<bool> &updiagcheck){
        if(col==n){
            ans.push_back(board);
            return ;
        }

        for(int row=0;row<n;row++){
            if(issafe(row,col,board,n,rowcheck,lowdiagcheck,updiagcheck)){
                board[row][col]='Q';
                rowcheck[row]=true;
                lowdiagcheck[row+col]=true;
                updiagcheck[(n-1)+(col-row)]=true;
                nqueen(col+1,n,ans,board,rowcheck,lowdiagcheck,updiagcheck);
                rowcheck[row]=false;
                lowdiagcheck[row+col]=false;
                updiagcheck[(n-1)+(col-row)]=false;
                board[row][col]='.';
            }
        }

    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>board(n);
        string s(n,'.');

        vector<bool> rowcheck(n,0);
        vector<bool> lowdiagcheck(2*n,0);
        vector<bool> updiagcheck(2*n,0);
        
        for(int i=0;i<n;i++){
            board[i]=s;
        }
        nqueen(0,n,ans,board,rowcheck,lowdiagcheck,updiagcheck);
        return ans;
    }
};