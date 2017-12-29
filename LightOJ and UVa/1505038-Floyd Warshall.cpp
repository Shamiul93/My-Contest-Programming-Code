/*
@author - Rumman BUET CSE'15
Problem - Floyd Warshall
Topic - Floyd Warshall Algorithm
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

#define inf 999999
#define minf LLONG_MIN
#define min3(a,b,c) min(a,min(b,c))
#define max3(a,b,c) max(a,max(b,c))
#define ones(mask)  __builtin_popcount(mask)
#define mx 150000

using namespace std;

ll nodeNo, edgeNo ;
ll Cost[1000][1000] = {} ;
ll Path[1000][1000] = {} ;

void FloydWarshall()
{
    cout << "All Pair Shortest Path: " << endl ;

    for(ll k = 1 ; k <= nodeNo ; k++)
    {
        for(ll i = 1 ; i <= nodeNo ; i++)
        {
            for(ll j = 1 ; j <= nodeNo ; j++)
            {
                if(Cost[i][j] > Cost[i][k] + Cost[k][j])
                {
                    Cost[i][j] = Cost[i][k] + Cost[k][j] ;
                    Path[i][j] = Path[k][j] ;
                }
            }
        }
    }

    for(ll i = 1 ; i <= nodeNo ; i++)
    {
        for(ll j = 1 ; j <= nodeNo ; j++)
        {
            if(Cost[i][j] == 999999)
            {
                cout << "Inf" << " " ;
            }
            else
                cout << Cost[i][j] << " " ;
        }
        cout << endl ;
    }
}


void pathBetweenNodes(ll Source, ll Destination)
{
    stack<ll> stk ;

    stk.push(Destination) ;

    while(Source != Destination)
    {
        Destination = Path[Source][Destination] ;
        if(Destination == inf)
        {
            cout << "No Path Available." << endl ;
            return ;
        }
        stk.push(Destination) ;
    }


    while(!stk.empty())
    {
        if(stk.size() == 1)
        {
            cout << stk.top() ;
        }
        else
            cout << stk.top() << " -> " ;
        stk.pop() ;
    }
    cout << endl ;
}


void PathPrint()
{
    cout << "Predecessor Matrix: " << endl ;

    for(ll i = 1 ; i <= nodeNo ; i++)
    {
        for(ll j = 1 ; j <= nodeNo ; j++)
        {
            if(Path[i][j] == 999999)
            {
                cout << "inf" << " " ;
            }
            else
                cout << Path[i][j] << " " ;
        }
        cout << endl ;
    }
}

void NegativeCycleDetection()
{
    cout << "Negative Cycle?: " << endl ;

    for(ll i = 1 ; i <= nodeNo ; i++)
    {
        for(ll j = 1 ; j <= nodeNo ; j++)
        {
            if(Cost[i][j] < 0)
            {
                cout << "Yes" << endl ;
                return ;
            }
        }
    }
    cout << "No" << endl ;
}


int main()
{
//    fi ;
    cin >> nodeNo >> edgeNo ;
    for(ll i = 0 ; i < 1000 ; i++)
    {
        for(ll j = 0 ; j < 1000 ; j++)
        {
            Path[i][j] = inf ;
            if(i == j)
            {
                Cost[i][j] = 0 ;
            }
            else
            {
                Cost[i][j] = 999999 ;
            }
        }
    }

    for(ll i = 0 ; i < edgeNo ; i++)
    {
        ll a, b, w ;
        cin >> a >> b >> w ;
        Cost[a][b] = w ;
        Path[a][b] = a ;
    }

    cout << "Initial Graph: " << endl ;

    for(ll i = 1 ; i <= nodeNo ; i++)
    {
        for(ll j = 1 ; j <= nodeNo ; j++)
        {
            if(Cost[i][j] == 999999)
            {
                cout << "inf" << " " ;
            }
            else
                cout << Cost[i][j] << " " ;
        }
        cout << endl ;
    }
    cout << endl ;

    FloydWarshall() ;
    cout << endl ;
    PathPrint() ;
    cout << endl ;
    NegativeCycleDetection() ;

//    cout << "Print path between 2 nodes:" << endl ;

//    ll K = 100 ;
//    while(K--)
//    {
//        ll Source, Destination ;
//        cin >> Source >> Destination ;
//        pathBetweenNodes(Source, Destination) ;
//    }

    return 0 ;
}
