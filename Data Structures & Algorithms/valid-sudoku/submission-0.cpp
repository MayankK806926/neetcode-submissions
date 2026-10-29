class Solution {
public:
    bool colCheck(vector<vector<char>>& board){
        for(int i=0;i<9;++i){
            vector<int> hsh(10,0);
            for(int j=0;j<9;++j){
                if(board[i][j]=='.') continue;
                hsh[board[i][j] - '0']++;
                if(hsh[board[i][j]-'0'] > 1) return false;
            }
        }

        return true;
    }

    bool rowCheck(vector<vector<char>>& board){
        for(int i=0;i<9;++i){
            vector<int> hsh(10,0);
            for(int j=0;j<9;++j){
                if(board[j][i]=='.') continue;
                hsh[board[j][i] - '0']++;
                if(hsh[board[j][i]-'0'] > 1) return false;
            }
        }

        return true;
    }

    bool boxCheck(vector<vector<char>>& board){
        for(int i=0;i<3;++i){
            for(int j=0;j<3;++j){
                vector<int> hsh(10,0);
                for(int x=3*i;x<3*i+3;++x){
                    for(int y=3*j;y<3*j+3;++y){
                        if(board[x][y]=='.') continue;
                        hsh[board[x][y]-'0']++;
                        if(hsh[board[x][y]-'0'] > 1) return false;
                    }
                }
            }
        }
        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        return colCheck(board) && rowCheck(board) && boxCheck(board);
    }
};
