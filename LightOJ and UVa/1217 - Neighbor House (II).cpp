/*
@author - Rumman BUET CSE'15
Problem -
Topic -
*/

/*LightOJ always needs this format for sure..so I made a copy of it...*/
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

using namespace std;

ll dp[1010] , arr[1010] ;
ll N ;

ll solve(ll pos, ll startPos)
{
cout << pos << "  " << startPos << endl ;

    if(pos >= N) return 0 ;

    if(startPos == 0 && pos == N-1) return 0 ;

    if(dp[pos] != -1) return dp[pos] ;

    ll ret ;
    return ret = max(solve(pos + 1 , startPos) , solve(pos + 2 , startPos) + arr[pos]) ;
}


int main()
{
    fi ;

    ll T, t = 0 ;
    scanf("%lld",&T) ;


    while(T--)
    {
//        m1(dp) ;

        t++ ;
        scanf("%lld",&N) ;
        for(ll i = 0 ; i < N ; i++)
        {
            scanf("%lld",&arr[i]) ;
        }

        ll a , b ;

        m1(dp) ;
        a = solve(0 , 0) ;
//        cout << "hi" << endl ;
//        return 0 ;
        m1(dp) ;
        b = solve(1 , 1);
//        cout << "ho" << endl ;
//        return 0 ;



        printf("Case %lld: ", t) ;
        printf("%lld\n",max(a,b)) ;
    }

    return 0 ;
}
