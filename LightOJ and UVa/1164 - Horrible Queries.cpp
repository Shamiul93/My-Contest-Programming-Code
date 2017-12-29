/**
@author - Rumman BUET CSE'15
Problem - 1164 - Horrible Queries

Concept - Segment Tree + Lazy Propagation

# Very Easy problem on lazy propagation.
# I made a very silly mistake. That took precious 6 hours from my life. -_-
# I'm sure now. আমি একজন বিশাল মাপের বাল হবো । :)
# The mistake -
        seg[sp].sum  += ((hi-lo+1)*x) ;
        seg[sp].prop += x ;

        এই দুইটা লাইনে প্লিজ তোরা সবসময় " + " চিহ্ন দিস ভাই । -_-
         ** I was solving MULTQ3 in SPOJ and suddenly noticed this thing by thinking. Didn't notice it in
         Shafayet Vai's Blog.

        Other than these, it was a quite easy problem.

        *** It has a twin brother in SPOJ - HORRIBLE. Just made some changes and that got AC.
*/


#include <bits/stdc++.h>
#define ll                                      long long
#define fi                                      freopen("in.txt", "r", stdin)
#define fo                                      freopen("out.txt", "w", stdout)
#define m0(a) memset(a , 0 , sizeof(a))
#define m1(a) memset(a , -1 , sizeof(a))

#define mx 100009
using namespace std;

class node
{
public:
    ll sum ;
    ll prop ;

    node()
    {
        sum = prop = 0 ;
    }
} seg[mx*4]  ;

ll i, j, idx, N ;

node update(ll lo, ll hi, ll sp, ll x)
{
    if(lo > j || hi < i)
    {
        node n ;
        return n ;
    }
    if(lo >= i && hi <= j)
    {
        seg[sp].sum  += ((hi-lo+1)*x) ;
        seg[sp].prop += x ;
        return seg[sp];
    }
    ll mid ;
    mid = (lo + hi) / 2 ;
    update(lo, mid, 2*sp + 1, x) ;
    update(mid + 1, hi, 2*sp + 2, x);

    seg[sp].sum = seg[2 * sp + 1].sum + seg[2*sp+2].sum + (hi - lo + 1) * seg[sp].prop ;
    return seg[sp];
}

ll query(ll lo, ll hi, ll sp, ll carry )
{
    if(lo > j || hi < i)
    {
        return 0 ;
    }
    if(lo >= i && hi <= j)
    {
        return (seg[sp].sum + ((hi-lo+1)*carry)) ;
    }

    ll mid ;
    mid = (lo+hi) / 2 ;

    ll l, r ;
    l = query(lo, mid, 2*sp + 1, carry + seg[sp].prop) ;
    r = query(mid + 1, hi, 2*sp+2, carry + seg[sp].prop);

    return (l+r) ;
}


int main()
{
//    fi ;
//    fo ;
    ll t = 0, T ;
    scanf("%lld",&T);
    while(T--)
    {
        t++ ;
        ll q ;
        scanf("%lld %lld",&N, &q ) ;

        for(ll k = 0 ; k < mx*4 ; k++)
        {
            seg[k].sum = 0 ;
            seg[k].prop = 0 ;
        }

        printf("Case %lld:\n",t);
        while(q--)
        {
            ll c ;
            scanf("%lld",&c) ;

            if(c==0)
            {
                ll v ;
                scanf("%lld %lld %lld",&i, &j, &v) ;
                update(0, N-1, 0, v);
            }
            else
            {
                scanf("%lld %lld",&i, &j);
                ll ans ;
                ans = query(0, N-1, 0, 0) ;
                printf("%lld\n",ans);
            }
        }
    }
    return 0 ;
}
