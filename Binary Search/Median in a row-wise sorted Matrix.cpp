int smallerEquals(vector<int> row, int midnumber)
{
    int s = 0;
    int e = row.size()-1;

    while(s <= e){
        int mid = s + (e-s)/2;

        if(row[mid] <= midnumber){
            s = mid+1;
        }
        else{
            e = mid-1;
        }
    }
    return s;
}

int median(vector<vector<int>> &matrix, int m, int n)
{    
    int low = 1;
    int high = 1e9;

    while(low <= high){
        int midnumber = low + (high-low)/2;
        int count = 0;
        // traverse every row
        for(int i=0; i<m; i++){
            count += smallerEquals(matrix[i], midnumber);
        }

        if(count <= (m*n)/2){
            low = midnumber+1;
        }
        else{
            high = midnumber-1;
        }
    }
    return low;
}
