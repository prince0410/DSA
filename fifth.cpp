#include<iostream>
#include <bits/stdc++.h>
using namespace std; 



int FindIndex(int arr[], int n , int x){

int s=0;
int e=n-1;

while(s<=e){

int mid=(s+e)/2;

if(arr[mid]==x)
    return mid;

     else if(arr[mid]>x)
     e=mid-1;

    else
    s=mid+1;


}
   return -1;


}
 
 
int main(){
 
 int n;
  cin >>  n;

  bool isPresent=false;

  int arr[n];

  for(int i=0; i<n; i++){
     cin >>  arr[i]; 
    
  } 

   for(int i=0; i<n; i++){

   int idx=FindIndex(arr,n,i)+1;

   if(n-idx == i ){
     cout << i <<endl; 
     isPresent=true;
    
   }

   } 
    
 if(isPresent)
 cout << "-1" << endl;

 
    
  
 
}