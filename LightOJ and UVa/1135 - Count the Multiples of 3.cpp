/**
@author - Rumman BUET CSE'15

Problem - 1135 - Count the Multiples of 3

SPOJ MULTQ3 এর টুইন ব্রাদার ।

Concept - Segment Tree , Lazy Propagation

** It is a beautiful problem on segment tree.

*** মেমরি লেন বানাচ্ছি । আজ থেকে ৫ বছর পর কই যাই জানি না । হয়তো এই স্মৃতি গুলো কেউ একদিন দেখবে ।
হয়তো আমিই দেখবো । আর বাংলায় ঘটনা গুলো পড়ে অনেকেরই সুবিধা হবে এজন্য বাংলায় দেয়া  । :p

** বাংলায় কই , নাইলে মজা নাই । :/
** এই প্রব্লেম করতে গিয়া বেশ টাইম গেসে । না । লজিক বাইর করতে যায় নাই । ইমপ্লিমেন্টে বাগ ধরতে গিয়া গেসে ।
** এই প্রব্লেম আমার জন্য স্পেশাল । কারণ , এই প্রব্লেমের লজিক পুরাটা আমার ডেভেলপ করা আর এর আইডিয়া ধরতে আমার টাইম লাগসে মাত্র ২ মিনিট । :3
** এবং এই আইডীয়া কোথাও থেকে শেখা না । অন্য সল্ভ দেখলে বুঝবা এই আইডিয়া অন্য কেউ ইউজ করে নাই । এটলিস্ট আমি দেখি নাই ।
** ইমপ্লিমেন্টে ভুল ধরতে ৫-৬ ঘণ্টা গেসে । -_-

আইডীয়াঃ


একটা class থাকবে । zero , one , two . মানে

আমার আন্ডারের রেঞ্জের সবার সাথে ১ যোগ করলে যার ৩ দ্বারা ভাগশেষ ০ ছিলো তাঁর এখন ভাগশেষ হবে ১ , যার ১ ছিলো সে হবে ২ , আর ২ হবে ০
সেই ভাবে সোয়াপ করার একটা সিস্টেম বাইর করসি । নিজেই ভেবে দেখো বুঝবা । :3



ভুলঃ

    seg[sp].zero = seg[2*sp+1].zero + seg[2*sp+2].zero ;
    seg[sp].one = seg[2*sp+1].one + seg[2*sp+2].one ;
    seg[sp].two = seg[2*sp+1].two + seg[2*sp+2].two ;

    seg[sp] = loopPropagate(seg[sp], seg[sp].prop % 3) ; /// এই লাইন টা লিখি নাই প্রথমে বাকী কোড ঠিক ছিলো । :/ তাহসিন ভাই ধরসে এইখানে ঘাপলা । :3


    শিক্ষাঃ

    ১ । আপডেটে সবসময় মনে রাখবি  - যদি পুরা রেঞ্জ আমি কভার করি মানে   if(lo >= i && hi <= j) হয় , তাইলেই শুধুমাত্র prop এর ভ্যালু চেঞ্জ হবে ।
    আর নাইলে prop কখনো নরমালি চেঞ্জ হবে না । তাইলে কি চেঞ্জ হবে ? হ্যাঁ । সাম বা অন্য ডাটা । কেমনে চেঞ্জ হবে ? আমার চাইল্ডের সব গুলা যেম্নে দরকার আমি মারজ করলাম ।

    ২ । এরপর ওই মারজড রেজাল্টের মধ্যে আমার নিজের prop এর প্রভাব এপ্লাই করতে হবে । হইতে পারে আগের মতো ( hi - lo + 1) * seg[sp].prop যোগ করতে হবে ।

     ৩ । এখানে যেটা করসি সেটা হলো ,     seg[sp].prop এর সমান সংখ্যক বার সোয়াপ করসি ।  loopPropagate ফাংশন ইউজ করে এই কাজ টা করসি ।

     ৪ । প্রতি কেসের শেষে অ্যারে ক্লিয়ার করা সবসময় উচিত । :3

     স্পেশালঃ

     ফাংশনে যখন ইটারেট এর জন্য সংখ্যা পাস করসি , তখন % ৩ করে পাস করসি । এতে লাভ হইসে যে , হায়েস্ট ২ বার লুপ ঘুরবে । নাইলে ৫০০০০ বার ও ঘুরা লাগতে পারতো ।
     এই জিনিসটা না করলে ১.১০০ সেকেন্ড আসে , করলে ০.৪০৮ সেকেন্ড আসে । :p


*/


#include <bits/stdc++.h>
#define ll                                      long long
#define fi                                      freopen("in.txt", "r", stdin)
#define fo                                      freopen("out.txt", "w", stdout)
#define m0(a) memset(a , 0 , sizeof(a))
#define m1(a) memset(a , -1 , sizeof(a))

#define mx 100009
using namespace std;


ll i, j, idx, N ;

class node
{
public:
    ll zero,  one, two, prop ;
    node()
    {
        one = two = zero =  prop =  0 ;

    }
} seg[mx*4];


node build(ll lo, ll hi, ll sp)
{
    if(lo == hi)
    {
        seg[sp].zero = seg[sp].zero + 1 ;
        return seg[sp];
    }
    ll mid ;
    mid = (lo + hi) / 2 ;

    node l, r ;
    l = build(lo, mid, 2*sp+1) ;
    r = build(mid+1, hi, 2*sp+2) ;

    seg[sp].zero = l.zero + r.zero ;
//    seg[sp].one = l.one + r.one ;
//    seg[sp].two = l.two + r.two ;
    return seg[sp] ;
}


node propagate(node a, ll x)
{
    a.prop += x ;
    swap(a.zero, a.one) ;
    swap(a.zero, a.two) ;
    return a ;
}


node loopPropagate(node a, ll x)
{
    for(ll m = 0 ; m < x ; m++)
    {
        swap(a.zero, a.one) ;
        swap(a.zero, a.two) ;
    }
    return a ;
}


node update(ll lo, ll hi, ll sp, ll x)
{
    if(lo > j || hi < i)
    {
        node n ;
        return n;
    }
    if(lo >= i && hi <= j)
    {
        seg[sp] = propagate(seg[sp], x) ;
        return seg[sp] ;
    }
    ll mid ;
    mid = (lo + hi) / 2 ;

    update(lo, mid, 2*sp+1, x) ;
    update(mid+1, hi, 2*sp+2, x) ;

    seg[sp].zero = seg[2*sp+1].zero + seg[2*sp+2].zero ;
    seg[sp].one = seg[2*sp+1].one + seg[2*sp+2].one ;
    seg[sp].two = seg[2*sp+1].two + seg[2*sp+2].two ;

    seg[sp] = loopPropagate(seg[sp], seg[sp].prop % 3) ; /// এই লাইন টাই মিস করসিলাম ।

    return seg[sp] ;
}


ll query(ll lo, ll hi, ll sp, ll carry)
{
    if(lo > j || hi < i)
    {
        return 0 ;
    }
    if(lo >= i && hi <= j)
    {
        node n ;
        n = loopPropagate(seg[sp], carry % 3) ;
        return n.zero ;
    }

    ll mid ;
    mid = (lo + hi) / 2 ;

    ll l, r ;
    l = query(lo, mid, 2*sp+1, carry + seg[sp].prop) ;
    r = query(mid+1, hi, 2*sp+2, carry+seg[sp].prop) ;

    return (l+r) ;
}

int main()
{
    fi ;
    fo ;
    ll T, t = 0 ;
    scanf("%lld",&T);
    while(T--)
    {
        for(int k = 0 ; k < mx*4 ; k++)
        {
            seg[k].zero = 0 ;
            seg[k].one = 0  ;
            seg[k].two = 0 ;
            seg[k].prop = 0 ;
        }
        t++ ;
        ll q ;
        scanf("%lld %lld",&N, &q) ;
        build(0, N-1, 0) ;
        printf("Case %lld:\n",t);
        while(q--)
        {
            ll c ;
            scanf("%lld %lld %lld",&c, &i, &j) ;
            if(c==0)
            {
                update(0, N-1, 0, 1) ;
            }
            else
            {
                ll ans ;
                ans = query(0, N-1, 0, 0) ;
                printf("%lld\n",ans);
            }
        }
    }
    return 0 ;
}
