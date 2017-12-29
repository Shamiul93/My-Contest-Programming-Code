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
#define ones(mask)  __builtin_popcount(mask)
#define mx 150000

#define MAX_HEAP_SIZE 100000

#define MAXREAL 999999.0
#define nll -999999

using namespace std;

ll Row[1000], Colm[1000] ;
ll dp[1000][1000] ;
ll Bracket[1000][1000]  ;
char C = 'A' ;

void printParenthesis(ll i, ll j)
{
    if(i == j)
    {
        cout << C << " " ;
        C++ ;
        return ;
    }

    cout << "(" << " " ;

    printParenthesis(i, Bracket[i][j]) ;
    printParenthesis(Bracket[i][j]+1, j) ;

    cout << ")" << " " ;

    return ;
}

ll MCM(ll Begin, ll End)
{
    if(Begin == End)
    {
        return 0 ;
    }
    if(dp[Begin][End] != -1) return dp[Begin][End] ;

    ll ans = inf ;

    for(ll Mid = Begin ; Mid < End ; Mid++)
    {
        ll Left, Right, Multipliers, Total ;
        Left = MCM(Begin, Mid) ;
        Right = MCM(Mid+1, End) ;
        Multipliers = Row[Begin] * Colm[End] * Colm[Mid] ;
        Total = Left + Right + Multipliers ;

        if(Total < ans)
        {
            ans = Total ;
            dp[Begin][End] = ans ;
            Bracket[Begin][End] = Mid ;
        }
    }

    return  dp[Begin][End] ;
}


int main()
{
    fi ;
    m1(dp) ;
    ll N , poss ;
    char c = 'A' ;
    cin >> N ;

    cin >> Row[0] >> Colm[0] ;
    poss = Colm[0] ;

    for(ll i = 1 ; i < N ; i++)
    {
        c++ ;
        cin >> Row[i] >> Colm[i] ;
        if(poss != Row[i])
        {
            cout << "This Multiplication is Impossible." << endl ;
            return 0;
        }
        else
        {
            poss = Colm[i] ;
        }
    }

    ll ans = MCM(0, N-1) ;

    cout << ans << endl ;

    char ch = 'A' ;
    printParenthesis(0, N-1) ;

    return 0 ;
}
