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
const int MAX = 17;
const lld mod = 1e9 + 7; 
lld bit[(1<<MAX)],dp[(1<<MAX)],nbit[(1<<MAX)];
void solve(int tc){
	int n,m;
	scanf("%d%d",&n,&m);
	if(n>m) swap(n,m);
	if(n==1){
		lld xx = 1;
		for(int e=0;e<m;e++) xx = (xx*2)%mod;
		printf("%lld\n",xx);
	}else{
		for(int e=0;e<(1<<n);e++){
			int nb = 0;
			for(int p=1;p<n;p++){
				int k1 = (e&(1<<p))&&(e&(1<<(p-1)));
				nb += (1<<(p-1))*k1;
			}
			dp[nb]++;
			bit[nb]++;
		}
		int lim = (1<<(n-1)) - 1;
		for(int e=0;e<n-1;e++){
			for(int p=0;p<=lim;p++){
				if(p&(1<<e)) bit[p] = (bit[p]+bit[p^(1<<e)])%mod;
			}
		}
		for(int e=1;e<m;e++){
			memset(nbit,0,sizeof(nbit));
			for(int p=0;p<=lim;p++){
				int xbit = lim^p;
				nbit[p] = (nbit[p]+bit[xbit]*dp[p])%mod;
			}
			memset(bit,0,sizeof(bit));
			for(int p=0;p<=lim;p++) bit[p] = nbit[p];
			for(int p=0;p<n-1;p++){
				for(int q=0;q<=lim;q++){
					if(q&(1<<p)) bit[q] = (bit[q]+bit[q^(1<<p)])%mod;
				}
			}
		}
		printf("%lld",bit[lim]);	
	}
}


int main(void){
	/*
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	*/
	int tc = 1;
	/*
		scanf("%d",&tc);
	*/
	for(int test_number=1;test_number<=tc;test_number++){
		solve(test_number);
	}
	return 0;
}