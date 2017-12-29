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
#define ones(mask)  __builtin_popcount(mask)
#define mx 150000

using namespace std;

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

int health[20] = {} ;
int arr[20][20] = {} ;
int N ;

ll dp[((1<<20)+5)] ;


ll solve(int mask)
{
    if(mask == (1 << N) - 1)
    {
        return 0 ;
    }
    if(dp[mask] != -1)
    {
        return dp[mask] ;
    }

    ll best = inf ;

    for(int i = 0 ; i < N ; i++)
    {
        if(!check(mask, i))
        {
            ll shots = 0 ;
            for(int  j = 0 ; j < N ; j++)
            {
                if(check(mask, j))
                {
                    if(j == 0)
                    {
                        shots += health[j] ;
                    }
                    else if(arr[i][j] != 0)
                    {
                        shots += ceil( (double) health[j] / (double)  arr[i][j]) ;
                    }
                    else
                    {
                        shots +=  health[j] ;
                    }
                }
            }

            ll ret = shots + solve(Set(mask, i)) ;
            best = min(best, ret) ;
        }
    }

    return dp[mask] = best ;
}

int main()
{
    fi ;
    fo ;

    ll T, t = 0 ;
    scanf("%lld",&T) ;

    while(T--)
    {
        m1(dp) ;
        m0(arr);
        t++ ;
        scanf("%d",&N) ;
        for(int i = 0 ; i < N ; i++)
        {
            scanf("%d",&health[i]) ;
        }

        string s ;

        for(int i = 0 ; i < N ; i++)
        {
            cin >> s ;
            for(int j = 0 ; j < s.size() ; j++)
            {
                arr[i][j] = s[j] - '0' ;
            }
        }

        int mask = 0 ;

        ll ans ;

        ans = solve(mask) ;

        printf("Case %lld: ",t) ;
        cout << ans << endl  ;
    }
    return 0 ;
}
