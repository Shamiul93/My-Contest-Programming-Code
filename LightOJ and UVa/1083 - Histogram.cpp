#include <bits/stdc++.h>
#include<vector>
#define ll                                      long long int
#define fi                                      freopen("in.txt", "r", stdin)
#define fo                                      freopen("out.txt", "w", stdout)
#define m0(a) memset(a , 0 , sizeof(a))
#define m1(a) memset(a , -1 , sizeof(a))

#define mx 150000
using namespace std;

ll height[30009] = {} ;
stack<ll> stk ;

int main()
{
    ll T , t = 0 ;
    while(T--)
    {
        ll maxarea , area ;
        t++ ;
        ll N ;
        scanf("%lld",&N) ;
        for(ll i = 0 ; i < N ; i++)
        {
            scanf("%lld",&height[i]) ;
        }

        for(ll i = 0 ; i < N ; i++)
        {
            if(!stk.empty())
            {
                ll top ;
                top = stk.top() ;

                if(height[top] > height[i])
                {

                }
                else
                {

                }
            }
            else
            {
                stk.push(i) ;
            }
        }
    }
    return 0 ;
}
