#include <bits/stdc++.h>
#include<vector>
#define ll                                      long long int
#define fi                                      freopen("in.txt", "r", stdin)
#define fo                                      freopen("out.txt", "w", stdout)
#define m0(a) memset(a , 0 , sizeof(a))
#define m1(a) memset(a , -1 , sizeof(a))

#define mx 150000
using namespace std;

ll a[100001] = {} ;

ll rec(ll n)
{
    if(n <= 2)
    {
        return a[n] = 1 ;
    }
    if(a[n] != 0)
    {
        return a[n] ;
    }
    return a[n] = rec(n-1) + rec(n-2) ;
}

int main()
{
    cout << rec(1000) << endl ;
    return 0 ;
}
