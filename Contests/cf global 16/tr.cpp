#include <bits/stdc++.h>
using namespace std;


void minCost(int arr[], int n)
{
    
    if (n < 3) {
        cout << arr[0];
        return;
    }

    
    int* my = new int[n];

    
    my[0] = arr[0];
    my[1] = my[0] + arr[1] + arr[2];

    
    for (int i = 2; i < n - 1; i++)
        my[i] = min(my[i - 2] + arr[i],
                    my[i - 1] + arr[i]
                        + arr[i + 1]);

    
    my[n - 1] = min(my[n - 2],
                    my[n - 3] + arr[n - 1]);

    
    cout << my[n - 1];
}


int main()
{
    int n; cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
   
    minCost(arr, n);

    return 0;
}