class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int i = 0, j = n-1;
        int row = -1;
        while(i <= j){
            int mid = i + (j-i) / 2;

            if(target >= matrix[mid][0] && target <= matrix[mid][m-1]){
                row = mid;break;
            }else if(target > matrix[mid][m-1]) i = mid+1;
            else j = mid-1;
        }   
        if(row == -1) return false;

        int l = 0,r=m-1;
        while(l <= r){
            int mid = l + (r - l) / 2;

            if(matrix[row][mid] == target) return true;
            else if(matrix[row][mid] < target) l = mid + 1;
            else r = mid-1;
        }

        return false;
    }
};
