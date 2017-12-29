
// LightOJ always needs this format for sure..so I made a copy of it...
#include <bits/stdc++.h>
#include<vector>
#define ll                                      long long int
#define fi                                      freopen("in.txt", "r", stdin)
#define fo                                      freopen("out.txt", "w", stdout)
#define m0(a) memset(a , 0 , sizeof(a))
#define m1(a) memset(a , -1 , sizeof(a))
#define inf LLONG_MAX
#define min3(a,b,c) min(a,min(b,c))
#define max3(a,b,c) max(a,max(b,c))
#define ones(mask)  __builtin_popcount(mask) /// __builtin_popcount : it's a built in function of GCC. Finds out the numbers of 1 in binary representation.
#define mx 150000

using namespace std;

ll N, M ;
ll value[102], numCoin[102] ;
ll dp[101][100001];

map<ll,ll> m ;

ll d = 0 ;

ll solve(ll i, ll make)
{
    if(make > M) return 0 ;

    if(i >= N) return 0 ;
    if(dp[i][make] != -1) return dp[i][make] ;

    ll ans = 1 ;

    for(ll j = 1 ; j <= numCoin[i] - 1 ; j++)
    {
        ll p = solve(i, make + value[i]) ;
        ans += p ;
//        if(m.find(p) == m.end())
//        {
//            m[p] = d ;
//            d++ ;
//            ans += p ;
//        }
    }

    ll p = solve(i+1, make) ;
    ans += p ;
//    if(m.find(p) == m.end())
//    {
//        m[p] = d ;
//        d++ ;
//        ans += p ;
//    }
    dp[i][make] = ans ;

    return dp[i][make] ;
}

int main()
{
    fi;
    ll T, t = 0 ;
    scanf("%lld",&T) ;

    while(T--)
    {
        t++ ;

        m1(dp) ;
        scanf("%lld %lld",&N,&M) ;

        for(ll i = 0 ; i < N ; i++)
        {
            scanf("%lld",&value[i]) ;
        }

        for(ll i = 0 ; i < N ; i++)
        {
            scanf("%lld",&numCoin[i]) ;
        }

        printf("Case %lld: ",t) ;

        ll ans ;
        ans = solve(0, 0) ;

        printf("%lld\n",ans) ;

    }
    return 0 ;
}
