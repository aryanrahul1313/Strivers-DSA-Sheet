int find(int A[],int X)
{
    if(X == A[X]){
        return X;
    }
    // path compression
    return A[X] = find(A, A[X]);
}

void unionSet(int A[],int X,int Z)
{
    // union by rank
    int ultimateParent_u = find(A, X);
    int ultimateParent_v = find(A, Z);
    
    if(ultimateParent_u == ultimateParent_v){
        return;
    }
    else{
        A[ultimateParent_u] = ultimateParent_v;
    }
}
