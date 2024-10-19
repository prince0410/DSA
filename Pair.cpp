#include<iostream>
#include <bits/stdc++.h>
using namespace std; 
 
 
int main(){


int n;
cin>>n;

int arr[n];

for(int i=0; i<n; i++){

cin>>arr[i];

}

int k;
cin>>k;


if(n%2==0){

int l=0; 
int ans[n]={0};
int temp=0;
int visited[n]={0};

for(int i=0; i<n; i++){

    for(int j=i+1; j<n; j++){

        if ((arr[i]+arr[j])%k==0 && visited[i]==0 && visited[j]==0)
        {
        
           visited[i]=1;
           visited[j]=1;
           ans[temp++]=arr[i];
           ans[temp++]=arr[j];
           l++;
           break;
        }
        

    }

}
if(l == n/2){
 
 for(int i = 0 ; i<n;i+=2)  {
    cout<<"("<<ans[i]<<","<<ans[i+1]<<")"<<endl;
 } 
}
else{
    cout<<"-1";
}

}else{
    cout<<"-1";
}


 
}