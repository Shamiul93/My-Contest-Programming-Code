
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

class info
{
public:
    ll num ;
    bool isPalin ;

    info()
    {
        num = -1 ;
        isPalin = false ;
    }
};

info dp[1010][1010] ;

info pal(ll i, ll j)
{
    if(dp[i][j].num != -1)
    {
        return dp[i][j] ;
    }

//    if(i >= N || j >= N)
//    {
//        dp[i][j].num = 0 ;
//        dp[i][j].isPalin = false ;
//        return dp[i][j] ;
//    }

    if(i == j)
    {
        dp[i][j].num = 1 ;
        dp[i][j].isPalin = true ;
        return dp[i][j] ;
    }

    if(i == j-1 && s[i] != s[j])
    {
        dp[i][j].num = 2 ;
        dp[i][j].isPalin = false ;
        return dp[i][j] ;
    }

    if(i == j-1 && s[i] == s[j])
    {
        dp[i][j].num = 1 ;
        dp[i][j].isPalin = true ;
        return dp[i][j] ;
    }

    if(s[i] == s[j])
    {
        info t ;
        t = pal(i+1, j-1) ;

        if(t.isPalin == true)
        {
            dp[i][j].num = t.num ;
            dp[i][j].isPalin = true ;
            return dp[i][j] ;
        }
        else
        {
            dp[i][j].num = 2 + t.num ;
            dp[i][j].isPalin = false ;
            return dp[i][j] ;
        }
    }
    else
    {
        info t1, t2 ;
        t1 = pal(i, j-1) ;
        t2 = pal(i+1, j) ;

        dp[i][j].isPalin = false ;
        dp[i][j].num = 1 + min(t1.num, t2.num) ;
        return dp[i][j] ;
    }
}


int main()
{
    fi ;
    fo ;
    ll T, t = 0 ;
    scanf("%lld",&T) ;

    while(T--)
    {
//        m1(dp) ;
        for(ll i = 0 ; i < 1010 ; i++)
        {
            for(ll j = 0 ; j < 1010 ; j++)
            {
                dp[i][j].num = -1 ;
                dp[i][j].isPalin = false ;
            }
        }

        t++ ;
        cin >> s ;
        N = s.length() ;

        printf("Case %lld: %lld\n",t, pal(0, N-1)) ;
    }
    return 0 ;
}
