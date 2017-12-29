/**
@author - Rumman BUET CSE'15

Problem - 1005 - Rooks
Concept - DP , Easy one.

Barriers - ট্রিক খাটানো লাগে একটু । nCr বের করার সময় যে বাংলা নিয়ম আমরা ইউজ করি সেটা করা যাবে না ।

nCr = n! / ( r! * ( n - r ) ! ) ; - এই ফরমুলা ইউজ করলে ডিনমিনেটরের গুণফল ওভারফ্লো হবে ।

এজন্য ডিপি ইউজ করা লাগবে আর কি । ডিপি তে nCr বের করতে যোগের সূত্র ইউজ করবো ।

nCr + nC(r-1) = (n+1)Cr

ইন্টারের ফরমুলা ।

আর মূল অব্জারভেশন -

অ্যাটাকিং থাকবে না কত উপায়ে ? রো কতভাবে চুজ করা যায় ? রো চুজ করার পর ওই রো তে কয়টা কলামে রুক গুলাকে বসানো যায় ? এটা সমাবেশ বাইর
করলেই এন্সার ।
*/



// LightOJ always needs this format for sure..so I made a copy of it...
#include <bits/stdc++.h>
#include<vector>
#define ll                                      unsigned long long int
#define fi                                      freopen("in.txt", "r", stdin)
#define fo                                      freopen("out.txt", "w", stdout)
#define m0(a) memset(a , 0 , sizeof(a))
#define m1(a) memset(a , -1 , sizeof(a))

#define mx 100000007
using namespace std;

ll dp[40][40] = {} ;

ll C(ll n, ll r)
{
    if(r == 0)
    {
        dp[n][r] = 1 ;
        return 1 ;
    }
    if(r == 1)
    {
        dp[n][r] = n ;
        return n ;

    }
    if(n == r)
    {
        dp[n][r] = 1 ;
        return 1 ;
    }

    if(dp[n][r] != 0)
    {
        return dp[n][r] ;
    }

    return dp[n][r] = C(n-1, r-1) + C(n-1, r) ;
}

int main()
{
//    fi ;
//    fo  ;

    dp[0][0] = 1 ;

    ll T, t = 0 ;
    scanf("%llu",&T) ;

    while(T--)
    {
        t++ ;
        ll n, k ;
        scanf("%llu %llu",&n, &k) ;

        printf("Case %llu: ",t) ;

        if(k == 0)
        {
            printf("1\n") ;
        }
        else if(k > n)
        {
            printf("0\n") ;
        }
        else
        {
            ll mul =  1, ans ;
            ll nck ;

            nck = C(n,k) ;

            while(k--)
            {
                mul *= n ;
                n-- ;
            }
            ans = nck * mul ;

            printf("%llu\n",ans) ;
        }
    }
    return 0 ;
}

