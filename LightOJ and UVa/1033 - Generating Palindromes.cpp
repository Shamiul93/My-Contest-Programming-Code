
// LightOJ always needs this format for sure..so I made a copy of it...
#include <bits/stdc++.h>
#include<vector>
#define ll                                      long long int
#define fi                                      freopen("in.txt", "r", stdin)
#define fo                                      freopen("out.txt", "w", stdout)
#define m0(a) memset(a , 0 , sizeof(a))
#define m1(a) memset(a , -1 , sizeof(a))

#define mx 150000
using namespace std;
string s ;
ll N ;

ll dp[110][110] ;

ll pal()
{
    for(ll i = 0 ; i < N ; i++)
    {
        dp[i][i] = 0 ;
    }

    for(ll n = 1 ; n < N ; n++)
    {
        for(ll i = 0 ; i < N ; i++)
        {
            ll j = i + n ;

            if(j < N)
            {
                if(s[i] == s[j])
                {
                    dp[i][j] = dp[i+1][j-1] ;
                }
                else
                {
                    dp[i][j] = 1 + min(dp[i+1][j] , dp[i][j-1]) ;
                }
            }
        }
    }

    return dp[0][N-1] ;
}


int main()
{
    ll T, t = 0 ;
    scanf("%lld",&T) ;

    while(T--)
    {
        t++ ;
        cin >> s ;
        N = s.length() ;

        printf("Case %lld: %lld\n",t , pal()) ;
    }
    return 0 ;
}
