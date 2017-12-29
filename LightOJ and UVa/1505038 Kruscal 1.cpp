
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


ll nodeNum, edgeNum ;


class Edge
{
public:
    ll first ;
    ll last ;
    ll weight ;

    Edge()
    {
        first = last = weight ;
    }
    Edge(ll a, ll b, ll w)
    {
        first = a ;
        last = b ;
        weight = w ;
    }
};

Edge EdgeArr[1000], Result[1000];

struct myCompare
{
    bool operator() (const Edge& a, const Edge& b)
    {
        return a.weight < b.weight ;
    }
};

class Subset
{
public:
    ll par ;
    ll ranking ;
    Subset()
    {
        par = -1 ;
        ranking = -1 ;
    }
};

Subset Subsets[1000] ;


ll Find(ll i)
{
    if(Subsets[i].par == i) return Subsets[i].par ;

    Subsets[i].par = Find(Subsets[i].par) ;
}

ll Union(ll x, ll y)
{
    ll parX = Find(x) ;
    ll parY = Find(y) ;

    if(Subsets[parX].ranking < Subsets[parY].ranking)
    {
        Subsets[parX].par = parY ;
    }
    else if(Subsets[parX].ranking < Subsets[parY].ranking)
    {
        Subsets[parY].par = parX ;
    }
    else
    {
        Subsets[parY].par = parX ;
        Subsets[parX].ranking++ ;
    }
}


void MST()
{
    for(ll i = 0 ; i <= nodeNum ; i++)
    {
        Subsets[i].par = i ;
        Subsets[i].ranking = 0 ;
    }

    ll e = 0, i = 0, j = 0 ;

    while(e < nodeNum)
    {
        ll x, y ;

        x = Find(EdgeArr[i].first) ;
        y = Find(EdgeArr[i].last) ;


        if(x != y)
        {
            Result[e++] = EdgeArr[i] ;
            Union(x, y) ;
        }
        i++ ;
    }

    ll s = 0 ;
    for(ll i = 0 ; i < e-1 ; i++)
    {
        s+= Result[i].weight ;
        cout << Result[i].first << " " << Result[i].last << " " << Result[i].weight << endl ;
    }
    cout << s << endl ;
    return ;
}

int main()
{
    fi ;

    cin >> nodeNum >> edgeNum ;

    for(ll i = 0 ; i < edgeNum ; i++)
    {
        ll a, b, w;
        cin >> a >> b >> w ;
        EdgeArr[i] = Edge(a,b,w) ;
    }

    sort(EdgeArr, EdgeArr + edgeNum, myCompare()) ;

    MST() ;

    return 0 ;
}
