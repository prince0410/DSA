#include<iostream>
#include <bits/stdc++.h>
using namespace std; 
 
 
int main(){
 
 int n;
 cin >>  n;
 
 int arr[n];
 
 for(int i=0; i<n; i++){
    cin >> arr[i];
 }
 
 int min_idx = 0;
 
 for (int i = 1; i < n; i++)
 {
    if (arr[i] < arr[min_idx])
        min_idx = i;
 }
 
 cout << "Minimum element is " << arr[min_idx];
 
 return 0;  // End of the program  // End of the program  // End of the program  // End of the program  // End of the program  // End of the program  // End of the program  // End of the program  // End of the program  // End of the program  // End of the program  // End of the program  // End of the program
 
}