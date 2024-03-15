#include <iostream>
using namespace std;

int main()
{
    int n,k,i,j;
    int dp[202][202];
    while(cin >> n >> k)
    {
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=k;j++)
            {
                if(i==1||j==1)
                    dp[i][j]=1;
                else if(i==j)
                    dp[i][j]=1+dp[i][j-1];
                else if(i<j)
                    dp[i][j]=dp[i][i];
                else if(i>j)
                    dp[i][j]=dp[i-j][j]+dp[i][j-1];

            }
        }
        printf("%d\n",dp[n][k]);
	}
	return 0;
}

