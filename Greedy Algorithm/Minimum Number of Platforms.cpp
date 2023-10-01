int calculateMinPatforms(int at[], int dt[], int n)
{
    //sort the arrays
    sort(at, at+n);
    sort(dt, dt+n);

    int maxi = 1;
    int platform = 1;
    //2 pointers for at and dt
    int arrival = 1;
    int depart = 0;

    while(arrival < n && depart < n){
        if(at[arrival] <= dt[depart]){
            platform++;
            arrival++; 
        }
        else{
            platform--;
            depart++;
        }
        maxi = max(maxi, platform);
    }
    return maxi;
}
