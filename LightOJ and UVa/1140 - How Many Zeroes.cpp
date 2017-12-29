/**
@author - Rumman BUET CSE'15
Problem - 1140 - How Many Zeroes?

Concept - Digit DP ( নতুন শিখসি ) ।

আইডিয়াঃ  লাইনের পাশে পাশে কমেন্ট করে লিখে দিসি । দেখে নিন ।


ডিজিট ডিপি কি ?

উঃ এটা একধরনের ডিপি । এটা যে কাজটা করে সেটা হলো একটা রেঞ্জের ভিতরে নির্দিষ্ট ধর্ম অনুযায়ী সংখ্যা কাউন্ট করে ।
আমি পেস্টবিনে কপি করে রাখসি শাকিলের ব্লগ থেকে । লিংক - https://pastebin.com/xkLEe4e2
দেখে নিও ।

ডিজিট ডীপি তে নরমালি ৪ টা স্টেট লাগে । কম বেশি লাগতে পারে । বাট ৪ টা লাগতে দেখসি নরমালি ।
এই প্রব্লেমের ক্ষেত্রে -

১। pos -  কত নাম্বার পজিশনে আছে ।
২। prevSmall -  আমি এখন যেই পজিশনে আছি , তাঁর ঠিক আগের বিট পর্যন্ত নিলে মূল নাম্বারের কোরেস্পন্ডিং অংশের চেয়ে এর মান কি বড় নাকি ছোট ?
৩। isStart - আমি এই মুহূর্তে যেই পজিশনে আছি সেটা কি স্টারটিং পজিশন কি না । মানে '০" তম পজিশন কি না । এটা অন্য প্রব্লেমে লাগে না নরমালি । কেন লাগে এটা ?
- সাপোজ , এমন কোন কেস পড়সে , যেটাতে প্রথম পজিশনে "০" বসবে না । অথবা প্রথম পজিশনে কিছু আলাদা শর্ত আছে । এর জন্য এই স্টেট লাগে ।
৪। zeroes - এখন পর্যন্ত যা যা কাউন্ট হইসে , কয়টা ০ লিখসো ।

বাকিটা কমেন্ট গুলায় পারটে পারটে লিখসি ।

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


ll dp[70][2][2][70] ;
ll len ;
vector<ll> v ;


ll solve(ll pos, ll prevSmall, ll isStart, ll zeroes)
{
    if(pos >= len)
    {
        return zeroes ; /// এটা না বুঝার কিছু নাই । :3
    }

    if(dp[pos][prevSmall][isStart][zeroes] != -1)
    {
        return dp[pos][prevSmall][isStart][zeroes] ; /// এটাও নরমাল ব্যাপার ।
    }

    ll bestPossible ;

    bestPossible = (prevSmall)? 9 : v[pos] ; /// এটায় কিছুটা কাহিনী আছে ।
    /// সাপোজ , এই বিটের আগে যতদূর পর্যন্ত আসছি , সেটা যদি স্মল হয় মূল নাম্বারের চাইতে , তাঁর মানে হইলো অলরেডি স্মল হইয়া গেসে । আর কোন ভাবেই এটা আর বড় বা সমান হবে না ।
    /// যেমন ধরো , ১২৪৫ । আমি ধরি , ১২৩ এ আসছি । এই যে ৪ এর চেয়ে ৩ ছোট হইয়া গেসে , আর কি বড় বা সমান হওয়া পসিবল ? না । তাইলে এখনের পজিশনে ০-৯ যা ইচ্ছা বসানো যাবে ।
    /// কিন্তু যদি ১২৪ হয় , তাইলে এখন ৫ এর চেয়ে ছোট বা সমান বসানো যাবে । বড় বসাইলেই পুরা নাম্বার টা বড় হয়ে যাবে ।

    ll ret = 0 ;

    if(isStart)
    {
        for(ll i = 1 ; i <= bestPossible ; i++)
        {
            ret += solve(pos + 1, prevSmall | (i < v[pos]), 0, (i == 0) + zeroes) ;
            /// এখানে কয়েকটা জিনিস -
            /// ১। pos+1 - এর মানে হলো এই ধাপে তো একটা সংখ্যা সিকুয়েন্সে যোগ করলাম ই । এখন ডিপি ফাংশ্নে পরের ধাপের জন্য রিকারশ্ন কল দিবো ।
            /// সে এন্সার দিবে ।

            ///******************  ২ । prevSmall | (i < v[pos]) - এই টা খুব জরুরী । খুব খুব খুব ইম্পরটেন্ট ।
            /// কি হচ্ছে এখানে ? - আগেই একটা কথা বলসিলাম । একটা নাম্বার একবার ছোট হয়ে গেলে আর বড় হবার উপায় নাই ।
            /// এজন্য একবার prevSmall যদি নন জিরো  হয়ে যায় , তাঁর এই নন জিরো ভ্যালুটা পরবরতী সব ধাপে পাস করা লাগবে ।
            /// কেমনে হবে ? or করতে করতে । যদি   prevSmall একবার  নন জিরো  হয়ে যায়  , তাইলে পরের সব ধাপে এর সাথে যাই যোগ হোক না কেন , জিরো আর হবে না ।
            /// অলয়েজ নন - জিরো হবে । অর্থাৎ , শুরু র দিকে কোন একটা ও যদি স্মল হয়ে যায় , তাঁর মানে এরপরের সব ধাপে এর ফলাফল টা বয়ে নিয়ে যাবে ।
            /// ইফ এলস দিয়াও করা যাবে । কিন্তু অনেকবার কল করা লাগে । লজিক এ তাল্গোল লাগতে পারে ।
            /// সো , এমনে অর ইউজ করে করাটা বেটার ।


            /// ৩। ০ দিসি isSart - পরের আর কোথাও স্টারটিং হচ্ছে না ।

            /// ৪। (i == 0) + zeroes - এটা ইউজ করসি কারণ , যদি i == 0 হয়  , তাইলে বুলিয়ান থেকে ইন্টেজার হবে ১ , সেই ১ যোগ হবে
            /// আগের zeroes এর সাথে ।
        }

        ret += solve(pos + 1, 1, 1, 0) ;

        ///আলাদা রিকারশ্ন কেন ? :/
        /// কারণ হলো সবাই যে গিভেন সংখ্যক ডিজিটের নাম্বার হবে  , তা তো না । তাই না ? তাইলে যে কাজ টা করবো ,
        /// ১। pos+1 - হবে কারণ , প্রথম বা স্টারটিং এ কিছু বসাইলাম না ।
        /// ২। prevSmall =  1 , কারণ , যেই ধাপের জন্য এই রিকারশন কল করসি , ওই ধাপের আগের ধাপ গুলা স্মল হয়ে গেসে অলরেডি ।
        /// কারণ , স্টারটিং এ কিছু বসাই নাই , অথচ কিছু না কিছু ছিলো । সেজন্য এক ডিজিট কমসে , বা মান কমসে ।
        /// ৩। isStart = 1  , কারণ , পরের ধাপ থেকে স্টার্ট করার জন্য ই এত কিছু ।
        /// ৪। জিরো এখনও পাই নাই ।
    }
    else
    {
        for(ll i = 0 ; i <= bestPossible ; i++)
        {
            ret += solve(pos + 1, prevSmall | (i < v[pos]), 0, (i == 0) + zeroes) ;
        }
    }

    return dp[pos][prevSmall][isStart][zeroes] = ret ;
}

ll calculate(ll a)
{
    if(a < 0)
    {
        return 0 ;
    }
    if(a <= 9)
    {
        return 1 ;
    }

    v.clear() ;
    m1(dp) ;
    while(a)
    {
        ll b ;
        b = a % 10 ;
        v.push_back(b) ;
        a = a / 10 ;
    }
    reverse(v.begin(), v.end()) ;
    len = v.size() ;

    ll ans ;

    ans = solve(0, 0, 1, 0) + 1 ;
    return ans ;
}

int main()
{
    ll T, t = 0 ;
    scanf("%lld",&T) ;

    while(T--)
    {
        t++ ;

        ll m, n ;
        scanf("%lld %lld",&m, &n) ;

        ll ans ;
        ans = calculate(n) - calculate(m-1) ;

//        cout << calculate(n) << endl ;
//        cout << calculate(m) << endl ;

        printf("Case %lld: ",t) ;
        printf("%lld\n", ans) ;
    }

    return 0 ;
}

