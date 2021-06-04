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

	const int MAX = 101010;
	const int mod = 1e6;
	int v[MAX],c[3],two[MAX];
	int dfs(int x,int r){
		if(x==0) return 0;
		if(v[x]!=r) return (dfs(x-1,3^v[x]^r)+two[x-1])%mod;
		return dfs(x-1,r);	
	}
	void solve(int tc){
		int n;
		scanf("%d",&n);
		for(int e=0;e<3;e++) scanf("%d",&c[e]);
		for(int e=0;e<3;e++){
			for(int p=0;p<c[e];p++){
				int k;
				scanf("%d",&k);
				v[k] = e;
			}
		}
		two[0] = 1;
		for(int e=1;e<MAX;e++) two[e] = (two[e-1]*2)%mod;
		printf("%d\n",v[n]+1);
		printf("%d\n",dfs(n-1,v[n]));
	}


	int main(void){
		/*
		ios_base :: sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
		*/
		int tc = 1;
		/*
			cin >> tc;
		*/
		for(int test_number=1;test_number<=tc;test_number++){
			solve(test_number);
		}
		return 0;
	}