class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();

        //Transpose the given matrix
        for(int i=0; i<n-1; i++){ //traverse only to last 2nd row
            for( int j=i+1; j<n; j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        //now reverse all rows
        for(int i=0; i<n; i++){
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};
