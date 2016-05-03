#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int ans[30];
int n;
bool found = false;
bool zero = true;
bool judge()
{
    if(zero){zero = false; return false;}
    int res = 0;
    for(int i = 25; i >= 0; i--){
        res = (res * 10 + ans[i]) % n;
    }
    return res  == 0;
}
void dfs(int depth)
{
    if(depth < 0){
        if(judge()){
            int i = 25;
            while(!ans[i]) i--;
            for(; i >= 0; i--) printf("%d", ans[i]);
            printf("\n");
            found = true;
        }
        return;
    }
    if(found) return;
    ans[depth] = 1;
    dfs(depth - 1);
    if(found) return;
    ans[depth] = 0;
    dfs(depth - 1);
}
int main (void)
{
    int t;scanf("%d",&t);
    while(t--){
        scanf("%d", &n);
        zero = true;
        found = false;
        dfs(25);
    }
    return 0;
}
