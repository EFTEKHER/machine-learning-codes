/*
code written by Eftekher Ali Efte from Bangladesh 
 email:eftekherali2000@gmail.com
pursuing computer science and engingeering in Ruet 
*/
#include<iostream>
#include<stdio.h>
#include<bits/stdc++.h>
#include<stdlib.h>
#define ull unsigned long long int
#include<ctype.h> 
using namespace std;
      
        
int main()
{
    int s,n;
   
    cin>>s>>n;
   
    int flag=0;
     ull temp=s;
    for(int i=1;i<=n;i++)
    {
        ull x,y;
        cin>>x>>y;

        if(temp>=x)
        {
            temp+=y;
            s=temp;
            flag=1;
        }
        else{
            flag=0;
        }
      
    }
    if(flag==1)
    {
        printf("YES\n");
    }
    else{
        printf("NO\n");
    }




        
return 0;
}
