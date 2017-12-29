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


struct compare
{
    bool operator () (const ll &a, const ll &b)
    {
        return a > b ;
    }
};

priority_queue<ll,vector<ll>,compare> pq ;

int main()
{
    ll T ;
    cin >> T ;
    while(T--)
    {
        ll n ;
        cin >> n ;
        ll ans = 0 ;

        for(ll i = 1 ; i <= n ; i++)
        {
            pq.push(i) ;
        }

        while(!pq.empty() && pq.size()>1)
        {
            ll sum = 0 ;
            sum += pq.top() ;
            ans += pq.top() ;
            pq.pop() ;
            sum += pq.top() ;
            ans += pq.top() ;
            pq.pop() ;

            pq.push(sum) ;
        }

        cout << ans << endl ;

        while(!pq.empty())
        {
            pq.pop() ;
        }
    }
    return 0 ;
}

