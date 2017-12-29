/**
@author - Rumman BUET CSE'15
Problem - 1159 - Batman

Concept - LCS , DP

আইডিয়াঃ এই প্রব্লেমের আইডিয়া আমার মাথায় হুট করে আসছে । মিরাকুলাস ঘটনা বলবো কি না জানি না । প্রথমে ভাবসিলাম ২ জনের মধ্যে এল সি এস টা বাইর করবো । এর পর ৩ নাম্বারের সাথে
আবার এল সি এস বাইর করবো । কিন্তু তাতে রঙ আসবে । কেন ?? acdkkk , bkkkcd , pcd - এই কেসে মারা খাবে ।

এরপর ভাব্লাম , প্রতি ২ টা জোড়ার মধ্যে এল সি এস বের করি । তাইলে ঘটনা যেটা ঘটবে এদের মিনিমাম টা নিলেই শেষ ।

২ টা কাজ করলো না  তখন বুঝলাম বাংলা নিয়ম মারবো । কেমনে ? আগে ২ জনের জন্য এল সি এস বের করতাম , এখন ৩ জনের জন্য বের করবো । কেমনে ?

3D অ্যারে নিলাম । এরপর জাস্ট নরমালি ইন্ডেক্স টা সাজিয়ে কোড করলাম । AC আসলো ।

শিক্ষাঃ যত গুলা স্ট্রিং এর এল সি এস চাইবে , তাঁদের জন্য তত স্টেটের ডিপি অ্যারে নিবা । ঘটনা শেষ । :p শরটকাট খুজতে গেসিলাম ফার্স্টের ২ সিস্টেমে । এর চাইতে সরাসরি বের করা স্মার্ট সল্যুশন ।

অ্যান্ড বিলিভ মি , আমি এই সলুশন নিজে বাইর করসি । :3 এরপর বাইরে সল্ভ দেখে বুঝলাম , সবাই এমনেই করসে । বুঝতেসি না কি বুঝা উচিৎ এ থেকে । - আমি অতটা গাধা না যতটা নিজেকে ভাবি ,
নাকি সবাই আমার চেয়ে ভালো বা সমান , তাই তারা যা খুব দ্রুত বের করসে , আমি সেটা কেমনে কেমনে জানি বাইর করসি । :3

*/


// LightOJ always needs this format for sure..so I made a copy of it...
#include <bits/stdc++.h>
#include<vector>
#define ll                                      long long int
#define fi                                      freopen("in.txt", "r", stdin)
#define fo                                      freopen("out.txt", "w", stdout)
#define m0(a) memset(a , 0 , sizeof(a))
#define m1(a) memset(a , -1 , sizeof(a))
#define max3(a,b,c) max( a , max(b,c))

#define mx 150000
using namespace std;

string s1, s2, s3 ;
ll len1, len2, len3 ;

ll dp[60][60][60] ;

ll lcs()
{
    for(ll i = 0 ; i < 60 ; i++)
    {
        dp[i][0][0] = 0 ;
        dp[0][i][0] = 0 ;
        dp[0][0][i] = 0 ;
    }

    for(ll i = 1 ; i <= len1 ; i++)
    {
        for(ll j = 1 ; j <= len2 ; j++)
        {
            for(ll k = 1 ; k <= len3 ; k++)
            {
                if(s1[i-1] == s2[j-1] && s2[j-1] == s3[k-1])
                {
                    dp[i][j][k] = dp[i-1][j-1][k-1] + 1 ;
                }
                else
                {
                    dp[i][j][k] = max3(dp[i-1][j][k], dp[i][j-1][k], dp[i][j][k-1]) ;
                }
            }
        }
    }

    return dp[len1][len2][len3] ;
}


int main()
{
//    fi ;
//    fo ;
    ll T, t = 0 ;
    scanf("%lld",&T) ;

    while(T--)
    {
        t++ ;
        cin >> s1 >> s2 >> s3 ;
        len1 = s1.length() ;
        len2 = s2.length() ;
        len3 = s3.length() ;

        ll ans ;
        ans = lcs() ;

        printf("Case %lld: ",t) ;
        printf("%lld\n",ans);
    }
    return 0 ;
}

