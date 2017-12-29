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

int main()
{
    fi ;
    fo ;
    ll T , t = 0 ;
    scanf("%lld",&T) ;

    while(T--)
    {
        m1(dp) ;
        t++ ;

        scanf("%lld %lld",&N , &K) ;

        for(ll i = 0 ; i < N ; i++)
        {
            scanf("%lld",&coin[i]) ;
        }
        ll ans ;
        ans = solve(0 , K) ;
		printf("Case %lld: ",t) ;
		printf("%lld\n",ans) ;
//		cout << "hi" << endl ;
    }

    return 0 ;
}
