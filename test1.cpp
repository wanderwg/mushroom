#include<vector>
using namespace std;
int main()
{
    int m,n,k;
    while(cin>>m>>n>>k)
    {
        vector<vector<int>> grassland((m+1),vector<int>(n+1));
        vector<vector<double>> p((m+1),vector<double>(n+1));
        p[1][1]=1.0;
        int x,y;
        for(int i=0;i<k;++i)
        {
            cin>>x>>y;
            grassland[x][y]=1;
        }
        for(int i=1;i<=m;++i)
        {
            for(int j=1;j<=n;++j)
            {
                if(!(i==1&&j==1))
                {
                    if(grassland[i][j]==1)
                        p[i][j]=0;
                    else
                        p[i][j]=p[i-1][j]*(j==n?1:0.5)+p[i][j-1]*(i==m?1:0.5);
                }
            }
        }
        printf("%.2lf\n",p[m][n]);
    }
    return 0;
}