#include <bits/stdc++.h>
using namespace std;
typedef long long int lld;
typedef pair<int,int> pi;
typedef pair<lld,lld> pl;
typedef pair<int,lld> pil;
typedef pair<lld,int> pli;
typedef vector<int> vit;
typedef vector<vit> vitt;
typedef vector<lld> vlt;
typedef vector<vlt> vltt;
typedef vector<pi> vpit;
typedef vector<vpit> vpitt;
typedef long double ld;
#define x first
#define y second
#define pb push_back
#define all(v) v.begin(), v.end()
#define sz(x) (int)x.size()
#define mk(a,b) make_pair(a,b)
bool isrange(int y,int x,int n,int m){
	 if(0<=y&&y<n&&0<=x&&x<m) return true;
	 return false;
}
int dy[4] = {1,0,-1,0},dx[4]={0,1,0,-1},ddy[8] = {1,0,-1,0,1,1,-1,-1},ddx[8] = {0,1,0,-1,1,-1,1,-1};

map<int,int> mm[32];
int dfs(int n,int k){
	if(k==1) return n;
	if(n==0) return 0;
	if(n<=k) return 1;
	if(mm[k].count(n)) return mm[k][n];
	int tot = 33;
	for(int p=2;p<=min(32,n);p++){
		int go = (n/p);
		int tot2 = 0;
		for(int q=1;q<=p-1;q++) tot2 = max(tot2,q+dfs(n-go*q,k));
		int len = go - 1;
		int rlen = (len/(k-1));
		if(len%(k-1)) rlen++;
		tot2 = min(tot2,p-1+dfs(rlen,k-1));
		tot = min(tot,tot2);
	}
	mm[k][n] = tot;
	return tot;
}
void solve(int tc){
	int n,k;
	scanf("%d%d",&n,&k);
	int xx = 1e9;
	for(int p=1;p<=k;p++) xx = min(xx,p-1+dfs(n,p));
	if(xx>32) printf("Impossible\n");
	else printf("%d\n",xx);
}


int main(void){
	/*
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	*/
	int tc = 1;
	
		cin >> tc;
	
	for(int test_number=1;test_number<=tc;test_number++){
		solve(test_number);
	}
	return 0;
}