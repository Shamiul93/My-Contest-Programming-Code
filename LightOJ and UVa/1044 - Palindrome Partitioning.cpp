

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

int N ;
int dp[1002][1002] = {} ;
bool pallin[1002][1002] = {} ;

string s ;

int pal()
{
    for(int i = 0 ; i < N  ; i++)
    {
        dp[i][i] = 1 ;
        pallin[i][i] = true ;
    }

    for(int i = 0 ; i < N-1 ; i++)
    {
        if(s[i] == s[i+1])
        {
            dp[i][i+1] = 1 ;
            pallin[i][i+1] = true ;
        }
        else
        {
            dp[i][i+1] = 2 ;
            pallin[i][i+1] = false ;
        }
    }

    for(int n = 2 ; n < N  ; n++)
    {
        for(int i = 0 ; i < N ; i++)
        {
            int j ;
            j = i + n ;
            if(s[i] == s[j])
            {
                if(pallin[i+1][j-1] == true)
                {
                    pallin[i][j] = pallin[i+1][j-1] ;
                    dp[i][j] = dp[i+1][j-1] ;
                }
                else
                {
                    pallin[i][j] = false ;
                    dp[i][j] = 1 + min(dp[i][j-1], dp[i+1][j]) ;
                }
            }
            else
            {
                pallin[i][j] = false ;
                dp[i][i+n] = 1 + min(dp[i][j-1], dp[i+1][j]) ;
            }
        }
    }


    return dp[0][N-1] ;
}

void print()
{
    cout << endl ;
    for(int i = 0 ; i < N ; i++)
    {
        for(int j = 0 ; j < N ; j++)
        {
            cout << dp[i][j] << " " ;
        }
        cout << endl ;
    }
}

int main()
{
//    fi ;
//    fo ;
    ll T, t = 0 ;
    scanf("%lld",&T);

    while(T--)
    {
//        m0(dp) ;

        t++ ;
        s.clear();
        cin >> s ;
        printf("Case %lld: ",t) ;

        N = s.length() ;

        for(ll i = 0 ; i < N + 2 ; i++)
        {
            for(ll j = 0 ; j < N+2 ; j++)
            {
                dp[i][j] = 0 ;
                pallin[i][j] = false ;
            }
        }

        int ans ;
        ans = pal();
        printf("%d\n", ans) ;
        print();

    }
    return 0 ;
}
