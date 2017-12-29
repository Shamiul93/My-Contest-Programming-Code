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
#define visited true

using namespace std;

ll BigMod(ll B,ll P,ll M)
{
    ll R=1;
    while(P>0)
    {
        if(P%2==1)
        {
            R=(R*B)%M;
        }
        P/=2;
        B=(B*B)%M;
    }
    return R;
}

int Set(int N,int pos)
{
    return N=N | (1<<pos);
}
int reset(int N,int pos)
{
    return N= N & ~(1<<pos);
}
bool check(int N,int pos)
{
    return (bool)(N & (1<<pos));
}

/************************************** END OF INITIALS ****************************************/

ll M, N ;
ll dp[110][110] ;
ll arr[110][110] ;
bool vis[110][110] ;

ll solve(ll i, ll j)
{
    if(i >= M || j >= N) return -1 ;
    if(i == M-1 && j == N-1) return arr[i][j] ;
    if(vis[i][j] == visited) return -1 ;
    if(dp[i][j] != -1) return dp[i][j] ;

//    vis[i][j] = visited ;

    ll ret = 0 , right , down ;

    right = solve(i, j+1) ;
    down = solve(i+1 , j) ;

    if(right > down)
    {
        vis[i][j+1] = visited ;
        ret = right ;
    }
    else
    {
        vis[i+1][j] = visited ;
        ret = down ;
    }

//    ret = max( ) ;
    return dp[i][j] = arr[i][j] + ret ;
}


void PrintDP()
{
    for(ll i = 0 ; i < M ; i++)
    {
        for(ll j = 0 ; j < N ; j++)
        {
            cout << dp[i][j] << " " ;
        }
        cout << endl ;
    }
    return ;
}


void PrintVis()
{
    for(ll i = 0 ; i < M ; i++)
    {
        for(ll j = 0 ; j < N ; j++)
        {
            cout << vis[i][j] << " " ;
        }
        cout << endl ;
    }
    return ;
}

int main()
{
    fi ;
//    fo ;

    ll T, t = 0 ;
    scanf("%lld",&T) ;

    while(T--)
    {
        m1(dp) ;

        for(ll i = 0 ; i < M ; i++)
        {
            for(ll j = 0 ; j < N ; j++)
            {
                vis[i][j] = !visited ;
            }
        }

        t++ ;

        scanf("%lld %lld",&M, &N) ;

        for(ll i = 0 ; i < M ; i++)
        {
            for(ll j = 0 ; j < N ; j++)
            {
                scanLL(arr[i][j]) ;
            }
        }

        ll ans ;
        ans = solve(0,0) ;

        PrintDP() ;
        cout << endl ;
//                PrintArray(vis) ;

        PrintVis() ;


//        vis[0][0] = !visited ;
//        vis[M-1][N-1] = !visited ;
        cout << endl ;
//                PrintArray(vis) ;
        PrintVis() ;
        m1(dp) ;
        ans = ans + solve(0,0) ;

//                PrintArray(dp) ;
        PrintDP() ;
        cout << endl ;
//                PrintArray(vis) ;

        PrintVis( ) ;
//        ans = ans - arr[0][0] - arr[M-1][N-1] ;


        printf("Case %lld: ", t) ;
        printf("%lld\n",ans) ;
    }

    return 0 ;
}
