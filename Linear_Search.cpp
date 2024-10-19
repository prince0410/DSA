#include<iostream>
#include <bits/stdc++.h>
using namespace std; 
 
int main(){
 
  int n;
 cin >>  n;

 int x;
  cin >>  x; 
 

 int arr[n];

 for(int i=0; i<n; i++){

cin >> arr[i];

 } 

 for(int i=0; i<n; i++){

    if(arr[i]==x)
     cout << i<< endl;

 }

 
 
  

 
}