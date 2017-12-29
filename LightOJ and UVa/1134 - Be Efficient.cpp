/**
@author - Rumman BUET CSE'15
Problem - 1134 - Be Efficient
Idea - সব ভাগশেষ গুলার কিউমিলিটীভ সাম বের করো। যদি দেখো যে ওই সামের মধ্যে কোনটা ০, তার মানে ফার্স্ট ইন্ডেক্স
থেকে এই পর্যন্ত সবার সাম আসলে M দ্বারা  ডিভিজিবল। আবার যদি দেখো যে যেকোন ২ টা ইন্ডেক্সের কিউম সাম সমান,
তার মানে এই দুই ইন্ডেক্সের মধ্যে যারা ছিলো, তাদের সাম হয় শুণ্য, নাইলে M দ্বারা ডিভিজিবল
তাইলে অ্যান্সার হইলো কি?
ans = total number of '0's + n * (n-1) / 2 ;
হিসাব করে দেখ, এরকম কম্বিনেশন n * (n-1) /2  ই হওয়া পসিবল ।
*/

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


using namespace std;

ll N, M ;
ll arr[100009] = {} ;

ll cumsum[100002] ;
map<ll,ll> Map ;

int main()
{
//    fi;
//    fo ;

    ll T, t = 0 ;
    scanf("%lld",&T) ;

    while(T--)
    {
        t++ ;

        m0(cumsum) ;
        scanf("%lld %lld",&N,&M) ;

        for(ll i = 0 ; i < N ; i++)
        {
            scanf("%lld",&arr[i]) ;
        }

        ll ans = 0 ;
        cumsum[0] = arr[0] % M ;
        for(ll i = 0  ;i < N ; i++)
        {
            cumsum[i] = (cumsum[i-1] % M + arr[i] % M)%M ;

            if(cumsum[i] == 0)
            {
                ans++ ;
            }

            if(Map.find(cumsum[i]) == Map.end())
            {
                Map[cumsum[i]] = 1 ;
            }
            else
            {
                Map[cumsum[i]]++ ;
            }
        }

        map<ll , ll>:: iterator it ;

        for(it = Map.begin() ; it != Map.end() ; it++)
        {
            ll a , b ;
            a = it -> first ;
            b = it -> second ;

            ans += (b * (b-1) / 2) ;
        }


        printf("Case %lld: %lld\n", t , ans) ;
        Map.clear();
    }
    return 0 ;
}
