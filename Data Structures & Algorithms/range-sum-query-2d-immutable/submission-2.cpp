class NumMatrix {
    vector<vector<int>> prefixSum;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        prefixSum = vector<vector<int>> (m+1 ,
        vector<int>(n+1, 0));
        for(int i=1; i<m+1; i++){
            int r_pre_sum=0;
            for(int j=1; j<n+1; j++){
                r_pre_sum += matrix[i-1][j-1];
                prefixSum[i][j]= r_pre_sum+
                prefixSum[i-1][j];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        row1++, row2++, col1++; col2++;
        int bottomRight = prefixSum[row2][col2];
        int above = prefixSum[row1-1][col2];
        int left = prefixSum[row2][col1-1];
        int topLeft = prefixSum[row1-1][col1-1];
        return bottomRight - above - left + topLeft;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */