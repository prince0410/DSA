#include<iostream>
#include <bits/stdc++.h>
using namespace std; 

int FindIndex(int** arr, int midrow, int colum, int x){

int s=0;
int e=colum-1;



while(s<=e){

int mid=(s+e)/2;

if(arr[midrow][mid]==x)
    return mid;

     else if(arr[midrow][mid]>x)
     e=mid-1;

    else
    s=mid+1;


}
   return -1;


}







 
int main(){
 
 int row;
 int col;

     cin >>  row;
      cin >>  col;

     int** arr = new int*[row];
    for (int i = 0; i < row; i++) {
        arr[i] = new int[col];
    }
      

      for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cin >> arr[i][j];
        }
    }





     
     int k;
      cin >>  k; 
     

    int s=0;
    int e=row-1;
    

    while(s<=){

        int mid=(s+e)/2;

       if(arr[mid][0]<=k && arr[mid][col-1]>=k){

    int ans =  FindIndex(arr,mid,col,k);

    if(ans==-1){
        cout << "-1" << endl;
    }else{
     

    cout << "(" <<mid<<","<<ans << ")"

    }
         
           break;

        }else if(arr[mid][0]>k){

            e=mid-1;
            

        }else{

            s=mid+1;
           
        }
        

    } 


}