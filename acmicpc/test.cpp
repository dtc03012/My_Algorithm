#include <cstdio>
#include <vector>

using namespace std;
typedef enum __Status {
    IS_NOT_VISITED,
    IS_VISITING,
    IS_VISITED
}Status;
int G[1000001];
Status stat[1000001];
bool isCycle[1000001];
long long int numOfColor[1000001];
int N;
long long int K;
long long int lmod = 1000000007LL;
long long int answer = 1;
void DFS(int i);
int main(void)
{
    scanf("%d %lld", &N, &K);
    
    //init graph G
    for (int i = 1; i <= N; i++) {
        scanf("%d", &G[i]);
    }
    
    //init stat
    for (int i = 1; i <= N; i++) {
        stat[i] = IS_NOT_VISITED;
    }
    
    //init isCycle
    for (int i = 1; i <= N; i++) {
        isCycle[i] = false;
    }
    
    //init numOfColor
    
    numOfColor[1] = K;
    numOfColor[2] = (K * (K - 1)) % lmod;
    numOfColor[3] = (numOfColor[2] * (K - 2)) % lmod;
    for (int i = 4; i <= N; i++){
        numOfColor[i] = (K - 1) * numOfColor[i - 2];
        numOfColor[i] += (K - 2) * numOfColor[i - 1];
        numOfColor[i] %= lmod;
    }

    
    
    // DFS search (cycle)
    for (int i = 1; i <= N; i++) {
        if(stat[i] == IS_NOT_VISITED)
            DFS(i);
    }
    
   
    for (int i = 1; i <= N; i++) {
        if(!isCycle[i]){
            answer *= K-1;
            answer %= lmod;
        }
    }
    
    printf("%lld\n", answer);
    return 0;
    
}


void DFS(int i)
{
    stat[i] = IS_VISITING;
    int cur_i = G[i];
    if(stat[cur_i] == IS_NOT_VISITED)
    {
        DFS(cur_i);
    }
    else if (stat[cur_i] == IS_VISITING){
        int cnt = 0;
        for (int x = cur_i; x != i; x = G[x]) {
            isCycle[x] = true;
            cnt++;
            
        }
        isCycle[i] = true;
        cnt++;
        answer *= numOfColor[cnt];
        answer %= lmod;
    //    printf("answer : %lld\n", answer);
    }

    stat[i] = IS_VISITED;
}


