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


int ck[21];
void solve(int tc){
	memset(ck,0,sizeof(ck));
	int n,w;
	scanf("%d%d",&n,&w);
	for(int e=0;e<n;e++){
		int w;
		scanf("%d",&w);
		int wh = -1;
		for(int p=0;p<20;p++) if(w&(1<<p)) wh = p;
		ck[wh]++;
	}
	int ans = 0,tot = n;
	while(true){
		ans++;
		int wid = w;
		while(wid){
			if(tot==0) break;
			bool flag = false;
			for(int p=20;p>=0;p--){
				if(ck[p]){
					if(wid>=(1<<p)){
						wid -= (1<<p);
						ck[p]--;
						tot--;
						flag = true;
						break;
					}
				}
			}
			if(!flag) break;
		}
		if(tot==0) break;
	}
	printf("%d\n",ans);
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