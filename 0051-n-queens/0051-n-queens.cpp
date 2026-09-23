class Solution {
public:
    vector<vector<string>> res;
    vector<int> col , d1 , d2;

    void recursive(int r , int n , vector<string> b){
        if(r==n){
            res.push_back(b);
            return;
        }
        for(int c = 0 ; c < n ; c++ ){
            if(col[c] || d1[r-c+n-1] || d2[r+c]) continue;

            b[r][c]='Q';
            col[c]=1;
            d1[r-c+n-1] = 1 ;
            d2[r+c] = 1 ;

            recursive( r+1 , n , b);

            b[r][c]='.';
            col[c]=0;
            d1[r-c+n-1]=0;
            d2[r+c]=0;
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        col.resize( n , 0 );
        d1.resize(2*n-1 , 0);
        d2.resize(2*n-1 , 0);
        vector<string> b( n , string(n , '.'));

        recursive( 0 , n , b);

        return res;
    }
};