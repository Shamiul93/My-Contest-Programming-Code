/**
@author - Rumman BUET CSE'15
Problem - 1025 - The Specials Menu

Concept - DP .

প্রব্লেম টা ঝামেলা আছে । তাও ৮০০+ সল্ভ ।
যাই হোক , প্রব্লেমের মূল বক্তব্য হলো - একটা স্ট্রিং এর মধ্যে কতগুলা প্যালিন্ড্রোমিক সাব সিকোয়েন্স হইতে পারে ? এই সংখ্যাটা বাইর করা লাগবে ।

১। যখন দেখবা , s[i] == s[j] , ধরি , s[i] == 'a' , s[j] == 'a' , তাইলে কি হবে ? aa এটা একটা পসিবল সিকু , এর জন্য ১ যোগ হবে ,
আর এর সাথে যোগ করা লাগবে এই ২ টার মাঝখানে যতটুক স্ট্রিং আছে তার এন্সার ।
কিন্তু এছাড়াও কি আরো ওয়ে থাকতে পারে না ? যদি প্রথম ও শেষের অক্ষর সমান হয় ? পারে । যদি প্রথম অক্ষর টাকে নিয়া কোন প্যালিন পাওয়া যায় , কিন্তু শেষ টারে বাদ দিয়ে ।
আবার শেষ টারে নিয়া , প্রথম টা বাদ দিয়ে । কিন্তু দেখো , এদের ২ জনের মধ্যেই  a[i+1][j-1] আছে । ২ বার যোগ হইসে । তাই ১ বার বিয়োগ দিবা ।

২। সমান না হইলে শুধু  প্রথম অক্ষর টাকে নিয়া কোন প্যালিন পাওয়া যায় , কিন্তু শেষ টারে বাদ দিয়ে , সেটা হিসাব করবা ।
আবার শেষ টারে নিয়া , প্রথম টা বাদ দিয়ে । কিন্তু দেখো , এদের ২ জনের মধ্যেই  a[i+1][j-1] আছে । ২ বার যোগ হইসে । তাই ১ বার বিয়োগ দিবা ।

*** ঝামেলা আছে । দেখে দেখে রাখা লাগবে ।

**/


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

ll dp[70][70] ;
string s ;
ll len ;

ll solve(ll i , ll j)
{
    if(j < i)
        return dp[i][j] = 0 ;
    if(i == j)
        return dp[i][j] = 1 ;
    if(dp[i][j] != -1)
        return dp[i][j] ;

    if(s[i] == s[j])
    {
        dp[i][j] = (1 + solve(i+1,j-1)) + (solve(i,j-1) + solve(i+1,j) - solve(i+1,j-1)) ;
    }
    else
    {
        dp[i][j] = solve(i,j-1) + solve(i+1,j) - solve(i+1,j-1) ;
    }
    return dp[i][j] ;
}

int main()
{
//    fi ; fo ;
    ll T, t = 0 ;
    scanf("%lld",&T) ;

    while(T--)
    {
        t++ ;

        m1(dp) ;
        cin >> s ;
        len = s.size() ;
        ll ans = solve(0,len-1) ;

        printf("Case %lld: ",t) ;
        cout << ans << endl ;
    }
    return 0 ;
}

