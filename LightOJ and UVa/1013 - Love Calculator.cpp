/**
@author - Rumman BUET CSE'15
Problem - 1013 - Love Calculator

concept - LCS , DP

শিক্ষাঃ

অনেক অনেক অনেক জোস প্রব্লেম । এবং আমার ঘাম ছুটে গেসে এটা করতে গিয়ে । সিম্পল আইডীয়া । ৮০০+ সল্ভ । মানে আসলে ফালতু প্রব্লেম । কিন্তু নতুন নতুন শিখতেসি বলে টাইম বেশি লাগলো ।

১। ২ টা জিনিস চাইসে । -
        1. The length of the shortest string that contains the names as subsequence.
        2. Total number of unique shortest strings which contain the names as subsequence.

    ১ নাম্বারের জন্য ২ টা উপায় আছে । - প্রথমে LCS বের করে এরপরে                 =  s1 length + s2 length - LCS(s1,s2)
    এটা গেলো একটা । আরেকটা আছে । - ডায়রেক্ট এমন কোন shortest string ডিপি দিয়ে জেনারেট করা , যাতে করে that contains the names as subsequence.

    এই সেকেন্ড উপায় টা লাভ জনক কারণ , এটা দিয়ে ২ নাম্বারের এন্সার দিতে পারাটা ইজি । এজন্য ২ নাম্বার ওয়েতেই সল্ভ করসি ।


আসলে কি করসি ?

উঃ প্রথমে এমনে একটা এমন shortest string ডিপি দিয়ে জেনারেট করসি , যাতে করে that contains the names as subsequence.
কেমনে ? প্রথমে  SeqLen অ্যারে এর প্রথম রো আর প্রথম কলাম যথাক্রমে রো নাম্বার আর কলাম নাম্বার দিয়ে ভরসি । এক কথায় , ইনক্রিজিং নাম্বার দিয়ে ভরসি ।
কেন ? এর সিগ্নিফিকেন্স কি ?

সাপোজ , জাস্ট একটা স্ট্রিং নিসি । মানে s1 নিবো , কিন্তু s2 নিবো না । তাইলে লেংথ কতো হবে ? পুরাটাই আস্তে আসতে নিবো না ? হ্যাঁ । কারণ নাইলে তো আমি যে স্ট্রিং বানাবো তাতে আমার পুরা
s1 স্ট্রিং টা থাকবে না ।
সেম কাজ s2 এর জন্য । - এগুলা হলো বেস কেস ।

আচ্ছা , যদি এখন আর শুধু একটা না নেই , মানে বেস কেস ছাড়া অন্য কেস নেই তাইলে কি হবে ?
যদি ২ টা অক্ষর সেইম হয় , তাইলে কর্ণ বরাবর উপরে যে সংখ্যা আছে তার সাথে ১ যোগ করে যোগফলই হবে লেংথ । এটা সোজা বুঝা যাবে ।

আর যদি  সেইম না হয় ? তাইলে যে দিক গেলে লেংথ মিনিমাম আসে সেটার সাথে ১ যোগ ।
উঃ আচ্ছা ১ যোগ তো বুঝলাম । কারণ যেহেতু shortest string জেনারেট করতে চাইতেসি , যাতে করে that contains the names as subsequence. কাউকে
তো বাদ দেয়া যাবে না । সবাইকেই থাকা লাগবে । কিন্তু মিনিমাম কেন ? আমরা lcs বের করার সময় তো ঠিকই ম্যাক্সিমাম নিতাম , তাইলে ?

* এখানে কারণ হলো , আমি এখানে lcs বা লংগেস্ট বের কতে চাইতেসি না । চাইতেসি শরটেস্ট স্ট্রিং বের করতে , যাতে করে সবাই থাকে । এজন্য -

            ১। মিনিমাম নিতে হবে , ২ । ১ যোগ করতে হবে সব ক্ষেত্রেই ।



২য় পারটঃ

আচ্ছা । ওয়ে কেমনে বাইর করবো ?
উঃ ওয়ে বাইর করতে হলে সবার বেইস কেইস হবে 1 . কেন ? কারণ হলো , ধরো তুমি কোন অক্ষরই নেও নাই , কিন্তু সেটাও কিন্তু একটা ওয়ে । আবার তুমি একটা স্ট্রিং টোটালি বাদ দিয়ে
আরেকটা স্ট্রিং কে নিতেসো , প্রতি পারটে আসলে একটাই উপায় বা ওয়ে থাকবে । USSR - U , US , USS , USSR এরা প্রত্যেকেই আলাদা ওয়ে । এবং এদের প্রত্যেকেই ১ ভাবেই নেয়া যায় ।

আর অন্য সব কেইসে সহজ । নরমালি " কয়টা LCS পসিবল ?" - এই প্রশ্নের সাথে এই প্রশ্নের খুব বেশি পার্থক্য নাই । উপায় হলো  ,
যদি দেখো যে ২ টা অক্ষর সেইম , তাইলে , জাস্ট কর্ণ বরাবর উপরের সংখ্যাই এখানে বসবে । কেন ? চিন্তা করে দেখো , ২ টা সমান হইলে ২ টাকে নিবো না । ১ টাকে নিবো । রাইট ???
তার মানে আমার কাজ হলো যা ছিলো , তার শেষে একটা অক্ষর যোগ করে দেয়া । ওয়ে চেঞ্জ হইসে ? হয় নাই ।

আর যদি অক্ষর সেইম না হয় , তাইলে জাস্ট চিন্তা করো । ২ জনের লেংথে যেদিক গেলে লেংথ কম হয় সেদিকে যাইতে হবে না ? হ্যাঁ । সেদিকে যে ওয়ে পাবো সেদিকের ওয়েই হবে এন্সার ।

কিন্তু অক্ষর সেইম হইলো না , উপরে আর বামের লেংথ সেইম । তাইলে ২ দিকেই সমান লেংথ আসতেসে । সো , ২ দিকের ওয়ে যোগ হয়ে সামনে প্রসীড করবো । এর চেয়ে বেশি আপাতত ব্যাখ্যা
করার তেল নাই । বাকিটা মাথায় বুঝে নিলাম ।

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
string s1, s2 ;
ll len1, len2 ;

ll SeqLen[40][40] = {} ;
ll SeqNum[40][40] = {} ;

ll Length()
{
    for(ll i = 0 ; i < 40 ; i++)
    {
        SeqLen[i][0] = i ;
        SeqLen[0][i] = i ;
    }

    for(ll i = 1 ; i <= len1 ; i++)
    {
        for(ll j = 1 ; j <= len2 ; j++)
        {
            if(s1[i-1] == s2[j-1])
            {
                SeqLen[i][j] = 1 + SeqLen[i-1][j-1] ;
            }
            else
            {
                SeqLen[i][j] = 1 + min(SeqLen[i-1][j], SeqLen[i][j-1]) ;
            }
        }
    }

    return SeqLen[len1][len2] ;
}

ll Number()
{
    for(ll i = 0 ; i < 40 ; i++)
    {
        SeqNum[i][0] = 1 ;
        SeqNum[0][i] = 1 ;
    }

    for(ll i = 1 ; i <= len1 ; i++)
    {
        for(ll j = 1 ; j <= len2 ; j++)
        {
            if(s1[i-1] == s2[j-1])
            {
                SeqNum[i][j] = SeqNum[i-1][j-1] ;
            }
            else
            {
                if(SeqLen[i-1][j] < SeqLen[i][j-1])
                {
                    SeqNum[i][j] = SeqNum[i-1][j] ;
                }
                else if(SeqLen[i-1][j] > SeqLen[i][j-1])
                {
                    SeqNum[i][j] = SeqNum[i][j-1] ;
                }
                else if(SeqLen[i-1][j] == SeqLen[i][j-1])
                {
                    SeqNum[i][j] = SeqNum[i-1][j] + SeqNum[i][j-1] ;
                }
            }
        }
    }
    return SeqNum[len1][len2] ;
}

void print()
{
    for(int i = 0 ; i < len1+1 ; i++)
    {
        for(int j = 0 ; j < len2+1 ; j++)
        {
            cout << SeqLen[i][j] << " " ;
        }
        cout << endl ;
    }
    cout << endl ;
    for(int i = 0 ; i < len1+1 ; i++)
    {
        for(int j = 0 ; j < len2+1 ; j++)
        {
            cout << SeqNum[i][j] << " " ;
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
        m1(SeqLen);
        m1(SeqNum) ;

        t++ ;

        cin >> s1 >> s2 ;
        len1 = s1.length() ;
        len2 = s2.length() ;

        ll l, n ;

        l = Length() ;
        n = Number() ;

//        print() ;

        printf("Case %lld: ",t) ;
        printf("%lld %lld\n",l, n) ;

    }
    return 0 ;
}

