// LightOJ always needs this format for sure..so I made a copy of it...
#include <bits/stdc++.h>
#include<vector>
#define ll                                      long long int
#define ull                                     unsigned long long
#define ld                                      long double

#define ff                                      first
#define ss                                      second

#define fi                                      freopen("in.txt", "r", stdin)
#define fo                                      freopen("out.txt", "w", stdout)
#define m0(a) memset(a , 0 , sizeof(a))
#define m1(a) memset(a , -1 , sizeof(a))
#define pi acos(-1.0)
#define debug                                   printf("yes\n")
#define what_is(x)                              cout << #x << " is " << x << endl
#define pf                                      printf
#define sf                                      scanf

#define pb                                      push_back
#define mp                                      make_pair
#define eb                                      emplace_back
#define pii                                     pair<int, int>
#define piii                                    pair<pii, int>

#define SQR(a)                                  ((a)*(a))
#define QUBE(a)                                 ((a)*(a)*(a))

#define scanI(a)                                scanf("%d",&a)
#define scanI2(a,b)                             scanI(a) , scanI(b)
#define scanI3(a,b,c)                           scanI(a), scanI(b), scanI(c)
#define scanI4(a,b,c,d)                         scanI(a), scanI(b), scanI(c), scanI(d)

#define scanLL(a)                                scanf("%lld",&a)
#define scanLL2(a,b)                             scanL(a) , scanL(b)
#define scanLL3(a,b,c)                           scanL(a), scanL(b), scanL(c)
#define scanLL4(a,b,c,d)                         scanL(a), scanL(b), scanL(c), scanL(d)

#define inf LLONG_MAX
#define minf LLONG_MIN
#define min3(a,b,c) min(a,min(b,c))
#define max3(a,b,c) max(a,max(b,c))
#define ones(mask)  __builtin_popcount(mask)
#define mx 150000

#define mod 1000000007

using namespace std;



/************************************** END OF INITIALS ****************************************/

ll K, P ;
bool vis[100000] = {} ;
ll Arr[1000] , phi[100000] ;

/// k = total koyta number nibo , p = first koyta prime must thakbe


ll seieve()
{
    for(ll i = 0 ; i < 100000 ; i++)
    {
        vis[i] = true ;
    }

    vis[0] = false ;
    vis[1] = false ;

    for(ll i = 2 ; i < 100000 ; i+=2)
    {
        vis[i] = false ;
    }

    for(ll i = 3 ; i < 100000 ; i++)
    {
        if(vis[i])
        {
            for(ll j = 2*i ; j < 100000 ; j+= i)
            {
                vis[i] = false ;
            }
        }
    }

    ll j = 0 ;

    for(ll i = 0 ; i < 100000, j < 500 ; i++)
    {
        if(vis[i] == true)
        {
            Arr[j] = i ;
            j++ ;
        }
    }

    return ;
}



ll Euler()
{
    for(ll i = 0 ; i < 100000 ; i++)
    {
        phi[i] = i ;
    }

    for(ll i = 0 ; i < 100000 ; i++)
    {
        if(vis[i])
        {
            for(ll j = i ; j < 100000 ; j+= i)
            {
                vis[j] = true ;
                phi[j] = (phi[j] / i) * (i-1) ;
            }
        }
    }
    return ;
}


ll dp[501][501] ;

ll solve(ll k , ll p, ll mul)
{
    if(k == K && p == P)
    {
        return phi[mul];
    }
    if(k == K) return 0 ;
    if(k > K || p > P) return 0 ;

    return dp[k][p] = (solve(k+1 , p , (mul % mod * Arr[p] % mod) % mod) % mod + solve(k , p+1, mul) % mod) % mod ;
}



int main()
{
//    fi ;
//    fo ;

    seieve() ;
    Euler() ;


    ll T, t = 0 ;
    scanf("%lld",&T) ;

    while(T--)
    {
        m1(dp) ;
        t++ ;
        scanLL2(K,P) ;

        ll ans ;
        ans = solve() ;


        printf("Case %lld: ", t) ;
    }

    return 0 ;
}
