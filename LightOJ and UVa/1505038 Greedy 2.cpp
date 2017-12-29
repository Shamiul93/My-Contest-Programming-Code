#include <bits/stdc++.h>
#include<vector>
#define ll                                      long long int
#define fi                                      freopen("in.txt", "r", stdin)
#define fo                                      freopen("out.txt", "w", stdout)
#define m0(a) memset(a , 0 , sizeof(a))
#define m1(a) memset(a , -1 , sizeof(a))

#define mx 150000
using namespace std;

class customer
{
public:
    int time ;
    int idx ;
    customer();
    customer(int a, int b);
};

customer::customer()
{
    time = 0 ;
    idx = -1 ;
}

customer::customer(int a, int b)
{
    time = a ;
    idx = b ;
}

customer arr[mx] = {} ;

void Merge(ll lo, ll mid, ll hi)
{
    int i, j, k;

    int n1 = mid - lo + 1;
    int n2 =  hi - (mid + 1) + 1 ; // n2 == hi - mid ;

    customer L[n1], R[n2];

    for (i = 0; i < n1; i++)
    {
        L[i] = arr[lo + i];
    }

    for (j = 0; j < n2; j++)
    {
        R[j] = arr[mid + 1 + j];
    }

    i = 0 ;
    j = 0 ;
    k = lo ;

    while (i < n1 && j < n2)
    {
        if (L[i].time < R[j].time)
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }


    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }


    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }

    return ;
}


void mergeSort(ll lo, ll hi)
{
    if (lo >= hi)
    {
        return ;
    }

    ll mid = (lo+hi) / 2 ;

    mergeSort(lo, mid);
    mergeSort(mid+1, hi);

    Merge(lo, mid, hi);
    return ;
}


int main()
{
    int N ;
    cin >> N ;

    for(int i = 0 ; i < N ; i++)
    {
        int a ;
        cin >> a ;
        arr[i] = customer(a, i+1) ;
    }
    mergeSort(0, N-1) ;

    for(int i = 0 ; i < N ; i++)
    {
        cout << arr[i].idx << " " ;
    }
    cout << endl ;

    return 0 ;
}


/*

Input:

11
10 24 5 11 67 21 8 97 32 9 41

Output:

3 7 10 1 4 6 2 9 11 5 8

*/
