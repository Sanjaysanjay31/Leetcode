class Solution {
public:
    int count ;
    vector<int> col , d1 , d2;

    void recursive(int r , int n ){
        if(r==n){
            count++;
            return;
        }
        for(int c = 0 ; c < n ; c++ ){
            if(col[c] || d1[r-c+n-1] || d2[r+c]) continue;

            col[c]=1;
            d1[r-c+n-1]=1;
            d2[r+c]=1;

            recursive(r+1 , n );

            col[c]=0;
            d1[r-c+n-1]=0;
            d2[r+c]=0;
        }
    }

    int totalNQueens(int n) {
        count = 0 ;
        col.resize(n, 0);
        d1.resize(2*n-1 , 0);
        d2.resize(2*n-1 , 0 );
        recursive(0 , n);

        return count;
    }
};