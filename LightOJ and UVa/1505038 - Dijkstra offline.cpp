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
#define ones(mask)  __builtin_popcount(mask)
#define mx 150000

#define MAX_HEAP_SIZE 100000

#define MAXREAL 999999.0
#define nll -999999

using namespace std;


/********* data = nodeNum , key = tillCost ******************/

class HeapItem
{
public:
    int data;
    int key;
};

//MinHeap class, minimum item stored at the root of heap tree
class MinHeap
{
public:
    HeapItem * A; //stores heap items, e.g., nodes
    int heapLength;
    int * map;

    MinHeap() //constructor
    {
        A = new HeapItem[MAX_HEAP_SIZE];
        map = new int[MAX_HEAP_SIZE];
        for(int i = 0 ; i < MAX_HEAP_SIZE ; i++)
        {
            A[i].key = nll ;
            map[i] = nll ;
        }
        heapLength=0;
    }

    ~MinHeap() //destructor
    {
        if(map) delete [] map;
        if(A) delete [] A;
        map = 0; //set to NULL after deletion
        A = 0; //set to NULL after deletion
    }

    void initialize(int v[], int n)
    {
        heapLength = n;
        for(int i=0; i<n; i++) //nodes are stored from index 1 instead of 0 in the heap
        {
            A[i+1].data = v[i];
            A[i+1].key = MAXREAL;
            map[v[i]] = nll; //map tracks which vertex is stored at which heap node
        }
    }

    void insertItem(int data, int key)
    {
        HeapItem t ;
        t.data = data ;
        t.key = key ;
        heapLength++ ;

        A[heapLength] = t ;
        map[data] = heapLength ;
        buHeapify(heapLength) ;
        return ;
    }

    HeapItem removeMin()
    {
        HeapItem ret ;
        ret.data = 0 ;
        ret.key = 0 ;
        if(heapLength == 0)
        {
            return ret ;
        }

        map[A[1].data] = nll ;

        ret = A[1] ;

        A[1] = A[heapLength] ;
        heapLength-- ;
        heapify(1) ;
        return ret ;
    }

    void updateKey(int data, ll key)
    {
        if(data < 1)
        {
            printf("Data is out of bound.\n");
        }
        if(map[data] == nll)
        {
            printf("Data doesn't exist.\n");
            return ;
        }
        int prev ;
        int i ;
        i = map[data] ;

        prev = A[i].key ;
        A[i].key = key ;

        if(prev < key)
        {
            heapify(i) ;
        }
        else if(prev > key)
        {
            buHeapify(i);
        }
    }

    ll getKey(int data)
    {
        int i = map[data];
        return A[i].key;
    }

    void heapify(int i)
    {
        int l,r,smallest;
        while(1)
        {
            l=2*i;      //left child index
            r=2*i+1;    //right child index
            smallest=i;

            if(l>heapLength && r>heapLength)
                break; //nothing to do, we are at bottom
            else if(r>heapLength)
                smallest = l;
            else if(l>heapLength)
                smallest = r;
            else if( A[l].key < A[r].key )
                smallest = l;
            else
                smallest = r;

            if(A[i].key <= A[smallest].key)
                break;	//we are done heapifying
            else
            {
                HeapItem t;
                t=A[i];
                A[i]=A[smallest];
                map[A[i].data]=i;
                A[smallest]=t;
                map[A[smallest].data]=smallest;
                i=smallest;
            }
        }
    }

    void buHeapify(int i)
    {
        if(i == 0)
        {
            return ;
        }
        int parent, sibling, tem, smallest ;
        HeapItem t ;
        parent = i / 2 ;

        if(i % 2 == 0)
        {
            sibling = i+1 ;
        }
        else
        {
            sibling = i-1 ;
        }

        if(sibling > heapLength && i > heapLength)
        {
            return ;
        }
        else if(sibling > heapLength)
        {
            smallest = i ;
        }
        else if(i > heapLength)
        {
            smallest = sibling ;
        }
        else if(A[i].key > A[sibling].key)
        {
            smallest = sibling ;
        }
        else
        {
            smallest = i ;
        }

        if(A[smallest].key < A[parent].key)
        {
            t = A[smallest] ;
            A[smallest] = A[parent] ;
            map[A[smallest].data] = smallest ;
            A[parent] = t ;
            map[A[parent].data] = parent ;
            buHeapify(parent) ;
        }

        else
        {
            return ;
        }
    }

    void printHeap()
    {
        printf("Heap length: %d\n", heapLength);
        for(int i=1; i<=heapLength; i++)
        {
            printf("(%d,%.2f) ", A[i].data, A[i].key);
        }
        printf("\n");
    }

    bool Empty()
    {
        if(heapLength==0)return true;
        else return false;
    }
};



vector<ll> v[1000] ;
ll Distance[1000], Parent[1000] ;
int Cost[1000][1000] ;
int nodeNo, edgeNo, Source ;


bool check[1000] = {} ;

void Dijkstra()
{
    for(ll i = 0 ; i < 1000 ; i++)
    {
        Distance[i] = 99999 ;
        Parent[i] = -99999 ;
    }

    MinHeap pq ;

    for(ll i = 1 ; i <= nodeNo ; i++)
    {
        pq.insertItem(i, 99999) ;
        check[i] = true ;
    }

    pq.updateKey(Source, 0) ;
    Distance[Source] = 0 ;

    while(!pq.Empty())
    {
        HeapItem u ;
        u = pq.removeMin();
        check[u.data] = false ;
        for(ll i = 0 ; i < v[u.data].size() ; i++)
        {
            ll curr ;
            curr = v[u.data][i] ;

            if(check[curr] && Distance[u.data] + Cost[u.data][curr] < Distance[curr])
            {
                Distance[curr] = Distance[u.data] + Cost[u.data][curr] ;
                pq.updateKey(curr, Distance[curr]) ;
                Parent[curr] = u.data ;
            }
        }
    }

    return ;
}


int main()
{
    fi ;

    cin >> nodeNo >> edgeNo ;

    for(ll i = 0 ; i < edgeNo ; i++)
    {
        ll src, dst, wt ;
        cin >> src >> dst >> wt ;
        v[src].push_back(dst) ;
        Cost[src][dst] = wt ;
    }

    printf("Source?: ") ;
    cin >> Source ;

    Dijkstra() ;

    printf("\n\nV              V.d             V.parent\n\n") ;


    for(ll i = 1 ; i <= nodeNo ; i++)
    {
        if(i == Source)
        {
            printf("%lld               %lld                nil\n", i, Distance[i]);
        }
        else
        {
            printf("%lld               %lld                %lld\n", i, Distance[i], Parent[i]) ;
        }
    }

    return 0 ;
}
