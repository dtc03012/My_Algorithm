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

const int MAX = 1e6;
void solve(int tc){
	lld n;
	scanf("%lld",&n);
	vector<pli> v;
	for(lld e=2;e*e<=n;e++){
		if(n%e==0){
			int tot = 0;
			while(n%e==0){
				n/=e;
				tot++;
			}
			v.push_back(mk(e,tot));
		}
	}
	if(n!=1) v.push_back(mk(n,1));
	sort(all(v));
	vector<lld> ans;
	for(int e=0;e<sz(v);){
		int tot = v[e].y;
		for(int p=e+1;p<sz(v);p++){
			tot += v[p].y;
		}
		if(tot==1){
			printf("-1");
			return;
		}
		if(tot==3){
			lld xx = 1;
			for(int p=0;p<v[e].y;p++) xx *= v[e].x;
			for(int p=e+1;p<sz(v);p++){
				for(int q=0;q<v[p].y;q++) xx *= v[p].x;
			}
			ans.push_back(xx);
			break;
		}else{
			lld xx = 1;
			if(v[e].y>=2){
				xx = v[e].x*v[e].x;
				v[e].y -= 2;
			}else{
				if(v[e].y==0){
					e++;
					continue;
				}
				xx = v[e].x;
				v[e].y--;
				for(int p=e+1;p<sz(v);p++){
					if(v[p].y){
						xx *= v[p].x;
						v[p].y--;
						break;
					}
				}
				e++;
			}
			ans.push_back(xx);
		}
	}
	for(int e=0;e<sz(ans);e++) printf("%lld ",ans[e]);
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