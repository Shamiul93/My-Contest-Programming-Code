
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
        first = last = weight = 0 ;
    }
    Edge(ll a, ll b, ll w)
    {
        first = a ;
        last = b ;
        weight = w ;
    }

    bool operator == (const Edge& e)
    {
        return (first == e.first && last == e.last && weight == e.weight) ;
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


bool isConnected()
{
    for(ll i = 0 ; i < 1000 ; i++)
    {
        Subsets[i].par = i ;
        Subsets[i].ranking = 0 ;
    }

    for(ll i = 0 ; i < edgeNum ; i++)
    {
        Union(EdgeArr[i].first, EdgeArr[i].last) ;
    }

    ll rep = Find(1) ;
    for(ll i = 2 ; i <= nodeNum ; i++)
    {
        if(rep != Find(i))
        {
            return false ;
        }
    }

    return true ;
}


Edge Result2[1000], mst[1000] ;


ll MST()
{
    sort(EdgeArr, EdgeArr + edgeNum, myCompare()) ;
    for(ll i = 0 ; i <= nodeNum ; i++)
    {
        Subsets[i].par = i ;
        Subsets[i].ranking = 0 ;
    }

    ll e = 0, i = 0, j = 0 ;

    while(e <= nodeNum - 1)
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

    ll W = 0 ;
    for(ll i = 0 ; i < e-1 ; i++)
    {
        W += Result[i].weight ;
    }
    return W ;
}


void SBMST()
{
    ll minWeight = MST() ;
    for(ll i = 0 ; i < nodeNum - 1 ; i++)
    {
        mst[i] = Result[i] ;
        Result[i] = Edge() ;
    }

    ll secondMin = inf, idx ;
    Edge tem ;


    for(ll i = 0 ; i < nodeNum - 1 ; i++)
    {
        ll t = 0 ;

        for(ll j = 0 ; j < edgeNum  ; j++)
        {
            if(EdgeArr[j].first == mst[i].first && EdgeArr[j].last== mst[i].last && EdgeArr[j].weight == mst[i].weight)
            {
                idx = j ;
                tem = EdgeArr[j] ;
                EdgeArr[j].first = EdgeArr[j].last = EdgeArr[j].weight = inf ;
                sort(EdgeArr, EdgeArr + edgeNum, myCompare()) ;
                edgeNum-- ;

                if(!isConnected())
                {
                    t = 1 ;
                    break ;
                }
            }
        }

        if(t == 0)
        {
            ll curr = MST() ;

            if(curr < secondMin)
            {
                secondMin = curr ;
                for(ll i = 0 ; i < nodeNum - 1 ; i++)
                {
                    Result2[i] = Result[i] ;
                    Result[i] = Edge();
                }
            }
        }

        edgeNum++ ;
        EdgeArr[edgeNum - 1] = tem ;
        sort(EdgeArr, EdgeArr + edgeNum, myCompare()) ;
    }

    for(ll i = 0 ; i < nodeNum - 1 ; i++)
    {
        cout << Result2[i].first << " " << Result2[i].last << " " << Result2[i].weight << endl ;
    }
    cout << secondMin << endl ;

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

    ll ms = MST() ;

    for(ll i = 0 ; i < nodeNum - 1 ; i++)
    {
        cout << Result[i].first << " " << Result[i].last << " " << Result[i].weight << endl ;
    }

    cout << ms << endl << endl ;

    SBMST() ;

    return 0 ;
}
