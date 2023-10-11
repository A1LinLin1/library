#include<iostream>
#include<cstdio>
#include<stdio.h>
#include<cstring>
#include<math.h>
#include<stdlib.h>
#include<algorithm>
#define up(l,r,i) for(int i=l,END##i=r;i<=END##i;++i)
#define dn(r,l,i) for(int i=r,END##i=l;i>=END##i;--i)
using namespace std;
typedef long long i64;
const int INF =2147483647;
const int MAXN=1e5+3;
int n,t,H[MAXN],F[MAXN];
int main(){
    while(~scanf("%d",&H[++n])); --n;
    t=0,memset(F,0,sizeof(F)),F[0]=INF;
    up(1,n,i){
        int l=0,r=t+1; while(r-l>1){
            int m=l+(r-l)/2;
            if(F[m]>=H[i]) l=m; else r=m;
        }
        int x=l+1;  // dp[i]
        if(x>t) t=x; F[x]=H[i];
    }
    printf("%d\n",t);
    t=0,memset(F,0,sizeof(F)),F[0]=0;
    up(1,n,i){
        int l=0,r=t+1; while(r-l>1){
            int m=l+(r-l)/2;
            if(F[m]<H[i]) l=m; else r=m;
        }
        int x=l+1;
        if(x>t) t=x; F[x]=H[i];
    }
    printf("%d\n",t);
    return 0;
}


























// int key[40]={0xAE, 0x7C, 0xA9, 0xC, 0x13, 0x9C, 0x97, 0x97, 0xB2, 0x3C, 0x7D, 0xCD, 0x93, 0x53, 0x48, 0x7D, 0x94, 0x59, 0x5F,0xFC, 0xA, 0x5A, 0x6F, 0xD3, 0xAB, 0x49, 0x6E, 0xB5, 0xAC, 0x96, 0xDA, 0xB4, 0x26, 2, 0x42, 0xB4, 0xBE, 0xB3, 8, 0x1F};
// int ans[40]={0xA9, 0xFB, 0xC8, 0x6F, 0x55, 0x95, 0x85, 0x85, 0xA7, 0x2D, 0xE3, 0xCE, 0xCD, 7, 0x35, 0xE8, 0xD2, 9, 0x5C, 0x16C, 0x72, 0, 0xAD, 0x92, 0xD6, 0x2E, 0xE4, 0xA9, 0xDB, 0x84, 0xDF, 0xF2, 0xD, 0x24, 0x62, 0xF5, 0xFF, 0xAE, 0x6F, 0x5F};
// int flag[40]={0};
// int main(){
//   for(int i=0;i<40;i++){
//     flag[i]=(key[i]+19)^ans[i];
//     printf("%c",flag[i]);
//   }
//   for(int i=0;i<40;i++){
//     printf("%c",key[i]);
//   }
//   for(int i=0;i<40;i++){
//     printf("%c",ans[i]);
//   }
//   return 0;
// }
