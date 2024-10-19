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



for(int i=0; i<n-1; i++){

    int SwapingPerPass=0;
      bool isSorted=true;
      
    for(int j=0; j<n-1-i; j++){

        if(arr[j]>arr[j+1]){
            
            swap(arr[j],arr[j+1]);
            isSorted=false;
           SwapingPerPass++;
              
                }
          
    }

    cout << "Swap in " << i+1 << " pass " << SwapingPerPass << endl;
  
    if(isSorted){
        break;
    }



}



cout << endl;

for(int i=0; i<n; i++){
    cout << arr[i] << " ";
}
 
 cout << "prepared by 23CE140 Prince Vagadiya"; 


}