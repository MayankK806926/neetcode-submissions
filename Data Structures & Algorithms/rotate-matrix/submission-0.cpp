class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int i=0;i<n;++i){
            for(int j=0;j<n/2;++j){
                swap(matrix[i][j],matrix[i][n-1-j]);
            }
        }
        for(int i=0;i<n;++i){
            for(int j=0;j<n-i;++j){
                swap(matrix[i][j],matrix[n-1-j][n-1-i]);
            }
        }
    }
};
// 9 6 3
// 8 5 2
// 7 4 1