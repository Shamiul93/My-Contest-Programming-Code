/**
@author - Rumman BUET CSE'15
Problem - 1231 - Coin Change (I)

Concept -

    DP. Coin Change.

    ** I solved this with only recursion. It can also be solved by using for loop.But I couldn't understand that
    solution till now. May be someday I will.
    ** It consumes more memory. And not efficient. Gets TLE. -_-
    ** It's my first problem on Limited coin change.

*/

#include<bits/stdc++.h>
#define ll long long
#define fo freopen("out.txt","w",stdout)
#define fi freopen("in.txt","r",stdin)
#define DEBUG printf("hi\n");
#define DEBUG2 printf("bi\n");
#define pi acos(-1)
#define m 100000007
#define d 0.000000001

using namespace std ;

ll N, K ;
ll CoinValue[100] ;
ll AtMost[100] ;
int dp[51][1001][21] ;

void reset()
{
    memset(dp, -1, sizeof(dp));
}

int rec(ll i, ll n, ll t)   /// i == index , n == requirement theke komte komte koto hoise...
{
    if( t > AtMost[i])
    {
        return 0 ;
    }

    if (n == 0)
        return 1;

    if (n < 0)
        return 0;

    if(i >= N && n > 0)
    {
        return 0 ;
    }


    if(dp[i][n][t] != -1)
        return dp[i][n][t] ;

    return dp[i][n][t] = ((rec( i, n - CoinValue[i], t+1 ) % m  + rec( i+1, n, 0 )  ) % m ) % m  ;

}

int main()
{
//    fi ;
//    fo ;

    ll T, t = 0 ;
    scanf("%lld",&T);
    while(T--)
    {

        reset();
        t++ ;

        scanf("%lld %lld",&N, &K);

        for(ll i = 0 ; i< N ; i++)
        {
            scanf("%lld",&CoinValue[i]) ;
        }
        for(ll i = 0 ; i < N ; i++)
        {
            scanf("%lld", &AtMost[i]) ;
        }

        ll ans ;
        ans = rec(0, K, 0) ;

        printf("Case %lld: %lld\n",t, ans) ;
    }

    return 0 ;
}
