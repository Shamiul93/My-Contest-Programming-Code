#include<bits/stdc++.h>
#define MAX_HEAP_SIZE 100000
#define MAXREAL 999999.0
#define nll -999999
#define ll long long
#define fi                                      freopen("in.txt", "r", stdin)
#define fo                                      freopen("out.txt", "w", stdout)
#define m0(a) memset(a , 0 , sizeof(a))
#define m1(a) memset(a , -1 , sizeof(a))

char data[MAX_HEAP_SIZE] ;
int freq[MAX_HEAP_SIZE] ;
int N ;
int arr[MAX_HEAP_SIZE] ;

class HeapItem
{
public:
    char data; //actual data that is stored
    int key; //key value of the data, heap is constructed based on key
    HeapItem *left, *right ;
    HeapItem(char c, int b)
    {
        data = c ;
        key = b ;
        left = 0 ;
        right = 0 ;
    }

    HeapItem()
    {
        data = 0 ;
        key = 0 ;
        left = 0 ;
        right = 0 ;
    }
};

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

    void insertItem(char data, int key, HeapItem *l, HeapItem *r)
    {
        HeapItem t ;
        t.data = data ;
        t.key = key ;
        t.left = l ;
        t.right = r ;

        heapLength++ ;

        A[heapLength] = t ;
        map[data] = heapLength ;
        buHeapify(heapLength) ;
        return ;
    }

    //this function removes (and returns) the node which contains the minimum key value
    HeapItem removeMin()
    {
        HeapItem ret ;
        ret.data = 0 ;
        ret.key = 0 ;
        ret.left = 0 ;
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
            printf("(%c,%d) ", A[i].data, A[i].key);
            if(A[i].left && A[i].right )
            {
                printf(" [left: %c %d ", A[i].left -> data, A[i].left -> key ) ;
                printf(" , right: %c %d ] ", A[i].right -> data, A[i].right -> key ) ;
            }
        }
        printf("\n");
    }

    bool Empty()
    {
        if(heapLength==0)
            return true;
        else
            return false;
    }
};

MinHeap minheap ;

HeapItem getHuffmanCode()
{
    for(int i = 0 ; i < N ; i++)
    {
        minheap.insertItem(data[i], freq[i], 0, 0) ;
    }

    while(minheap.heapLength > 1)
    {
        HeapItem *right, *left ;
        HeapItem top ;
        HeapItem l, r ;

        l = minheap.removeMin() ;
        r = minheap.removeMin() ;

        left = (HeapItem*) malloc(sizeof(HeapItem));
        right = (HeapItem*) malloc(sizeof(HeapItem));

        left -> data = l.data ;
        right -> data = r.data ;

        left -> key = l.key ;
        right-> key = r.key ;

        left -> left = l.left ;
        right -> left = r.left ;

        left -> right = l.right ;
        right -> right = r.right ;

        top.data = '!' ;
        top.key = l.key + r.key ;
        top.left = left ;
        top.right = right ;

        minheap.insertItem(top.data, top.key, top.left, top.right) ;

        /// This line will print the heap along with all node and it's left and right pointer values.
        minheap.printHeap();

    }

    return minheap.removeMin() ;
}


void printCode(HeapItem *node, int idx)
{
    if(node -> left)
    {
        arr[idx] = 0 ;
        printCode(node -> left, idx+1) ;
    }
    if(node -> right)
    {
        arr[idx] = 1 ;
        printCode(node -> right, idx + 1) ;
    }

    if(node -> left == 0 && node -> right ==0)
    {
        printf("%c  ", node -> data) ;
//        printf(" %d " , idx) ;

/// This line will print length of the code.

        for(int i = 0 ; i < idx ; i++)
        {
            printf("%d",arr[i]) ;
        }

        printf("\n") ;
        return ;
    }
}

int main()
{
//    fi ;
    char c ;
    int f ;
    scanf("%d",&N) ;

    for(int i = 0 ; i < N ; i++)
    {
        scanf(" %c",&data[i]) ;
        scanf("%d",&freq[i]) ;
    }

    HeapItem tem ;

    tem = getHuffmanCode();


    printCode(&tem, 0);

    return 0 ;
}

/*
Sample

Input:

6
a 45
b 13
c 12
d 16
e 9
f 5

Output:

a  0
c  100
b  101
f  1100
e  1101
d  111

*/
