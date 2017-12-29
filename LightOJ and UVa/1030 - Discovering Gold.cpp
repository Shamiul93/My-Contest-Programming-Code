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
    bool operator () (const ll &a , const ll &b)
    {
        return a > b ;
    }
};


int Set(int &N,int pos)
{
    return N=N | (1<<pos);
}
int reset(int &N,int pos)
{
    return N= N & ~(1<<pos);
}
bool check(int N,int pos)
{
    return (bool)(N & (1<<pos));
}


priority_queue<ll , vector<ll> , compare> pq ;

/************************************** END OF INITIALS ****************************************/
ll N ;
ll arr[110] = {} ;
double tem = -1.0 ;
double dp[1000] = {} ;


double solvE(ll pos)
{
    if(pos >= N)
    {
        return 0 ;
    }

    if(pos == N-1)
    {
        return dp[pos] = arr[pos] * 1.0 ;
    }

    if(dp[pos] != tem)
    {
        return dp[pos] ;
    }

    ll inRange = 0 ;

    for(ll diceVal = 1 ; diceVal <= 6 ; diceVal++)
    {
        if(pos + diceVal < N)
        {
            inRange++;
        }
    }

    dp[pos] = arr[pos] * 1.0 ;

    for(ll i = 1 ; i <= inRange ; i++)
    {
        dp[pos] += solvE(pos+i) * (1.0 / inRange) ;
    }

    return dp[pos] ;
}

int main()
{
    ll T , t = 0 ;
    scanf("%lld",&T) ;

    while(T--)
    {
        t++ ;
        cin >> N ;

        for(ll i = 0 ; i < N ; i++)
        {
            cin >> arr[i] ;
            dp[i] = tem ;
        }


		printf("Case %lld: ",t) ;
		double ans ;
		ans = solvE(0) ;
		printf("%.9f\n",ans) ;
    }
    return 0 ;
}

/*
3

1
101

2
10 3

3
3 6 9

*/
