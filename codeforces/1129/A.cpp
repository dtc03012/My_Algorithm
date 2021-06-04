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

const int MAX = 5050;
vector<int> v[MAX];
void solve(int tc){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int e=0;e<m;e++){
		int a,b;
		scanf("%d%d",&a,&b);
		v[a].push_back(b);
	}
	int mx = 0;
	for(int e=1;e<=n;e++){
		mx = max(mx,sz(v[e]));
		sort(all(v[e]));
	}
	for(int e=1;e<=n;e++){
		int tot = (mx-1)*n;
		int kk = 0;
		for(int p=1;p<=n;p++){
			if(sz(v[p])==mx){
				int x = (p-e+n)%n;
				int kk2 = 1e9;
				for(int q=0;q<sz(v[p]);q++){
					int nx = v[p][q];
					nx = (nx-e+n)%n;
					if(x>nx){
						kk2 = min(kk2,n+nx);
					}else{
						kk2 = min(kk2,nx);
					}
				}
				if(kk2!=1e9) kk = max(kk,kk2);
			}else if(sz(v[p])==mx-1){
				int x = (p-e+n)%n;
				int kk2 = 1e9;
				for(int q=0;q<sz(v[p]);q++){
					int nx = v[p][q];
					nx = (nx-e+n)%n;
					if(x>nx){
						kk2 = min(kk2,nx);
					}else{
						kk2 = 0;
					}
				}
				if(kk2!=1e9) kk = max(kk,kk2);
			}
		}
		printf("%d ",tot+kk);
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