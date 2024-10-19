#include<iostream>
#include <bits/stdc++.h>
using namespace std; 
 
int main(){
 


int n;

 cout << "Enetr size of array : ";
 cin >>  n; 

int arr[n];

for(int i=0; i<n; i++)
 cin >>  arr[i]; 



int totalComparision=0;
 
for(int pass=0; pass<n-1; pass++){

    int minidx=pass;

    for(int j=pass+1; j<n; j++){

        if(arr[j]<arr[minidx]){
        minidx=j;
        totalComparision++;
        }

    }

    if(pass!=minidx)
    swap(arr[pass],arr[minidx]);
    

}


cout<<"Sorted array is: ";

for(int i : arr){
    cout << i << " ";
}
cout <<endl;

cout << "Total Comparision : " << totalComparision  << endl;

 cout << "prepared by 23CE140 Prince Vagadiya"; 


}