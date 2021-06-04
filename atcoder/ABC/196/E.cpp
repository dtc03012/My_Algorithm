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
lld a[MAX],t[MAX];
set<pli> s;
int uf[MAX];
lld val[MAX];
int find(int x){
	if(uf[x]!=x) return uf[x] = find(uf[x]);
	return x;
}
void solve(int tc){
	int n;
	scanf("%d",&n);
	for(int e=0;e<n;e++) scanf("%lld%lld",&a[e],&t[e]);
	int q;
	scanf("%d",&q);
	for(int e=0;e<q;e++){
		uf[e] = e;
		lld r;
		scanf("%lld",&r);
		s.insert(mk(r,e));
	}
	lld res = 0;
	for(int e=0;e<n;e++){
		if(t[e]==1) res += a[e];
		if(t[e]==2){
			set<pli>::iterator it = s.lower_bound(mk(a[e]+1-res,-1));
			if(it==s.begin()) continue;
			it--;
			int wh = find(it->y);
			if(it==s.begin()){
				s.erase(it);
			}else{
				s.erase(it--);
				for(;;){
					int wh1 = find(it->y);
					uf[wh1] = wh;
					if(it==s.begin()) break;
					s.erase(it--); 
				}
			}
			s.insert(mk(a[e]-res,wh));
		}
		if(t[e]==3){
			set<pli>::iterator it = s.lower_bound(mk(a[e]-res,-1));
			if(it==s.end()) continue;
			int wh = find(it->y);
			for(;it!=s.end();){
				int wh2 = find(it->y);
				uf[wh2] = wh;
				s.erase(it++);
			}
			s.insert(mk(a[e]-res,wh));
		}
	}
	for(set<pli>::iterator it = s.begin();it!=s.end();it++){
		val[it->y] = it->x + res;
	}
	for(int e=0;e<q;e++){
		int now = find(e);	
		printf("%lld\n",val[now]);
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
		cin >> tc;
	*/
	for(int test_number=1;test_number<=tc;test_number++){
		solve(test_number);
	}
	return 0;
}