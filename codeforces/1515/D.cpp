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

const int MAX = 202020;
int lv[MAX],rv[MAX];
void solve(int tc){
	int n,l,r;
	cin >> n >> l >> r;
	for(int e=1;e<=n;e++){
		lv[e] = rv[e] = 0;
	}
	for(int e=0;e<l;e++){
		int k;
		cin >> k;
		lv[k]++;
	}	
	for(int e=0;e<r;e++){
		int k;
		cin >> k;
		rv[k]++;
	}
	for(int p=1;p<=n;p++){
		while(lv[p]&&rv[p]){
			lv[p]--;
			rv[p]--;
			l--;
			r--;
		}
	}
	int ans = 0;
	if(l<r){
		for(int p=1;p<=n;p++){
			while(rv[p]>=2&&l<r){
				rv[p] -= 2;
				r -= 2;
				ans++;
			}
		}
	}else if(l>r){
		for(int p=1;p<=n;p++){
			while(lv[p]>=2&&l>r){
				lv[p] -= 2;
				l -= 2;
				ans++;
			}
		}
	}
	int mid = (l+r)/2;
	ans += abs(mid-l);
	ans += mid;
	cout << ans << "\n";
}


int main(void){
	
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int tc = 1;
	
		cin >> tc;
	
	for(int test_number=1;test_number<=tc;test_number++){
		solve(test_number);
	}
	return 0;
}