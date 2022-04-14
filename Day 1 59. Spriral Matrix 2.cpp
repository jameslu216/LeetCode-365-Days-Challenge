class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n,vector<int>(n));
        int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
        int cur_dir = 1;
        int sy=0,sx=0,count=1;
		// I just found the regular like below
		// take input 5 as example, it will 
		// go head 5 turn right 
		// go head 4 turn right go head 4 turn right 
		// go head 3 turn right go head 3 turn right...,
		// The general steps will be n n-1 n-1 n-2 n-2 .... 1 1
        matrix[0][0]=0;
        for(sx=0;sx<n;++sx)
        {    
            matrix[sy][sx] = count;
            count++;
        }
        sx--;
        for(int i=n-1;i>0;--i)
        {
            for(int k=0;k<2;++k)
            {

                for(int j=0;j<i;++j)
                {
                    cout << sx << " "  <<" " << sy<<endl;

                    sx+=dir[cur_dir][0];
                    sy+=dir[cur_dir][1];
                    matrix[sy][sx] = count;
                    count ++;
                }
                cur_dir = (cur_dir+1)%4;
            }
        }
        return matrix;
    }
};