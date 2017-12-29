/**
@author - Rumman BUET CSE'15

Problem - 1044 - Palindrome Partitioning ( This code is for subsequence though this problem wanted substring. -____-)

Concept - DP  , LCS

Idea - Tushar Roy videos have explained it clearly.

১। প্রথমে ডায়াগোনাল বরাবর সবাই ১ হয়ে যাবে । কারণ একই ইলিমেন্ট  ১ বার ই নেয়া যাবে ।
২ ।  বাকী সব চিন্তা হবে এভাবে । শুরু আর শেষের অক্ষর যদি সেইম হয় , তাহলে dp[i][j]  তে বসবে  1 + min(dp[i][j-1], dp[i+1][j]) - একটু চিন্তা করলেই বুঝবা । আমি খাতায় একে একে বের করসিলাম । ছবি পিসি তে রেখে দিচ্ছি ।
৩। আর যদি সেইম না হয় , তাহলে  dp[i][j]  তে বসবে  dp[i+1][j-1] ;

সমস্যাঃ কিছু বাগ আছে এই কোডে । যখন দেখসি প্রশ্ন ভুল দেখসি , ( -_______- :/ ) তখন আর এটা ঠিক করি নাই । বাট মূল কোড ঠিক আছে । আরো ভালো করা যাবে আর কি ।

*/



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
string s ;

int pal()
{
    for(int i = 0 ; i < N  ; i++)
    {
        dp[i][i] = 1 ;
    }

    for(int i = 0 ; i < N-1 ; i++)
    {
        if(s[i] == s[i+1])
        {
            dp[i][i+1] = 1 ;
        }
        else
        {
            dp[i][i+1] = 2 ;
        }
    }

    for(int n = 1 ; n < N  ; n++)
    {
        for(int i = 0 ; i < N ; i++)
        {
            if(s[i] == s[i+n])
            {
                dp[i][i+n] = dp[i+1][i+n-1] ;
            }
            else
            {
                dp[i][i+n] = 1 + min(dp[i][i+n-1], dp[i+1][i+n]) ;
            }
        }
    }


    return dp[0][N-1] ;
}

void print()
{
    cout << endl ;
    for(int i = 0 ; i < N+3 ; i++)
    {
        for(int j = 0 ; j < N+3 ; j++)
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
    scanf("%lld",&T) ;

    while(T--)
    {
        m0(dp) ;
        t++ ;
        s.clear();
        cin >> s ;
        printf("Case %lld: ",t) ;

        N = s.length() ;

        int ans ;
        ans = pal();
        printf("%d\n", ans) ;
        print() ;
    }
    return 0 ;
}

