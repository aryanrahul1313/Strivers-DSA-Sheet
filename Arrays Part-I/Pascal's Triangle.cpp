class Solution {
public:
    vector<int> generateRows(int row){
        long long ans = 1;
        vector<int> ansRow;
        ansRow.push_back(1);

        for(int col=1; col<row; col++){
            ans = ans * (row-col);
            ans = ans/col;
            ansRow.push_back(ans);
        }
        return ansRow;
    }

    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> list;
        for(int i=1; i<=numRows; i++){
            list.push_back(generateRows(i));
        }
        return list;
    }
};
