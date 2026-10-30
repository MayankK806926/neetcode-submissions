class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> ans;

        int t=0,b=n-1;
        int l=0,r=m-1;

        while(true){
            //Top row
            for(int j=l;j<=r;++j){
                ans.push_back(matrix[t][j]);
            }
            t++;
            //Right column
            for(int i=t;i<=b;++i){
                ans.push_back(matrix[i][r]);
            }
            r--;
            //Bottom row
            if(t <= b){
                for(int j=r;j>=l;--j){
                    ans.push_back(matrix[b][j]);
                }
                b--;
            }
            //Left Column
            if(l <= r){
                for(int i=b;i>=t;--i){
                    ans.push_back(matrix[i][l]);
                }
                l++;
            }

            if(t > b || l > r) break;
        }

        return ans;
    }
};