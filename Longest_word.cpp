#include<iostream>
#include <bits/stdc++.h>
#include <string>
using namespace std; 
 
 
int main(){
 
string str;

 cout << "Enter your string : "; 


getline(cin,str);

int i=0;
int maxi=0;
int length=0;


for(char ch : str){

if(isspace(ch)){
   
    maxi=max(maxi,length);
     length=0;
}else{
    ++length;
}

}

  maxi=max(maxi,length);

 cout << maxi; 



 
}