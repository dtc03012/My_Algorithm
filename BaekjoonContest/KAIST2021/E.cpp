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

const int MAX = 10;
int vis[(1<<MAX)][(1<<MAX)],arr[MAX],res[MAX],gg[(1<<MAX)],g2[MAX+5][(1<<MAX)];
void solve(int tc){
	int n,k,m;
	cin >> n >> k >> m;
	for(int e=0;e<n;e++) cin >> arr[e];
	for(int e=0;e<m;e++){
		int bit = 0;
		int r;
		cin >> r;
		for(int p=0;p<r;p++){
			int t;
			cin >> t;
			t--;
			bit ^= (1<<t);
		}
		res[e] = bit;
	}
	for(int e=0;e<(1<<m);e++){
		for(int p=0;p<m;p++){
			if(e&(1<<p)){
				gg[e] |= res[p];
			}
		}
	}
	for(int e=0;e<(1<<n);e++){
		for(int p=0;p<(1<<m);p++){
			vis[e][p] = 1e9;
		}
	}
	for(int e=1;e<=k;e++){
		for(int p=0;p<(1<<n);p++){
			int nbit = 0;
			for(int q=0;q<n;q++){
				if((p&(1<<q))&&arr[q]==e) nbit ^= (1<<q);
			}
			g2[e][p] = nbit;
		}
	}
	int org = 0;
	for(int p=0;p<n;p++) if(arr[p]==1) org ^= (1<<p);
	queue<pi> q;
	q.push(mk(org,0));
	vis[org][0] = 0;
	while(!q.empty()){
		int col = q.front().x;
		int eq = q.front().y;
		q.pop();
		for(int p=0;p<m;p++){
			if(vis[col][eq^(1<<p)]>vis[col][eq] + 1){
				vis[col][eq^(1<<p)] = vis[col][eq] + 1;
				q.push(mk(col,eq^(1<<p)));
			}
		}
		int nbit = col & gg[eq];
		for(int p=1;p<=k;p++){
			int xbit = g2[p][((1<<n)-1)^gg[eq]] ^ nbit;
			if(vis[xbit][eq]>vis[col][eq]+1){
				vis[xbit][eq] = vis[col][eq] + 1;
				q.push(mk(xbit,eq));
			}
		}
	}
	if(vis[(1<<n)-1][0]==1e9) vis[(1<<n)-1][0] = -1;
	cout << vis[(1<<n)-1][0] << "\n";
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