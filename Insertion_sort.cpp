#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{

 int n;

 cout << "Enetr size of array : ";
 cin >>  n; 

int arr[n];

for(int i=0; i<n; i++)
 cin >>  arr[i]; 


    for (int j = 0; j < n; j++)
    {

        int i = j - 1;
        int key = arr[j];

        while (i >= 0 && arr[i] > key)
        {

            arr[i + 1] = arr[i];
            i--;
        }

        arr[i + 1] = key;
    }

    cout << "Sorted array is: ";

    for (int i : arr)
    {
        cout << i << " ";
    }
    cout << endl;

    cout << "prepared by 23CE140 Prince Vagadiya"; 
}