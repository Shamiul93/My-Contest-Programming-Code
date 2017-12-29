#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>
#include<cstdlib>

#define ll long long
#define pb push_back
#define mp make_pair

using namespace std ;
typedef pair< ll, ll> PII ;

vector< PII > vec[110] ;

class NodeMax
{
public:
    ll Node ;
    ll cost ;
    NodeMax(ll N, ll C)
    {
        Node = N ;
        cost = C ;
    }
    bool operator < (NodeMax A)
    {
        return cost < A.cost ;
    }
};

class NodeMin
{
public:
    ll Node ;
    ll cost ;
    NodeMin(ll d , ll i)
    {
        Node = d ;
        cost = i ;
    }
    bool operator < (NodeMin A)
    {
        return cost > A.cost ;
    }
};

int visited[110] ;
int costing[110] ;
priority_queue< NodeMax > PQ ;

ll maxprims(ll start)
{
    memset(visited,0,sizeof(visited));
    memset(costing,LONG_MAX, sizeof(costing));

    ll maxi = 0 ;
    PQ.push(NodeMax(start, 0));

    costing[start] = 0 ;

    while(!PQ.empty())
    {
        NodeMax x = PQ.top();
        PQ.pop();

        if(visited[x.Node]==1)
        {
            continue ;
        }

        visited[x.Node]=1 ;
        maxi += x.cost;

        for(PII v : vec[x.Node])
        {
            if(visited[v.first]==0 && v.second > costing[v.first])
            {
                costing[v.first] = v.second ;
                PQ.push(NodeMax(v.first,v.second)) ;
            }
        }
    }

    return maxi ;
}


ll minprims(ll start)
{
    memset(visited,0,sizeof(visited));
    memset(costing,LONG_MAX, sizeof(costing));

    priority_queue < NodeMin > pq ;

    ll mini = 0 ;

    pq.push(NodeMin(start, 0));
    costing[start] = 0 ;

    while(!pq.empty())
    {
        NodeMin x = pq.top();
        pq.pop();

        if(visited[x.Node]==0)
        {
            visited[x.Node] = 1 ;
            mini += costing[x.Node] ;

            for(PII v : vec[x.Node])
            {
                if(visited[v.first]==0 && v.second < costing[v.first])
                {
                    costing[v.first] = v.second ;
                    pq.push(NodeMin(v.first,v.second));
                }
            }
        }
    }

    return mini ;
}

int main()
{
    ll T, t=0 ;
    cin >> T ;
    while(T--)
    {
        t++ ;

        ll N ;
        cin >> N ;
        ll first, second, c ;
        ll maxi , mini ;
        double avg ;

        while((cin >> first >> second >> c) && (first||second||c))
        {
            vec[first].pb(mp(second,c));
            vec[second].pb(mp(first,c));
        }

        maxi = maxprims(0);
        mini = minprims(0);

        avg = ( maxi + mini ) / 2.0 ;
        cout << avg << endl ;

    }

    return 0 ;
}

