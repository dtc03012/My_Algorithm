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


const int NMAX = 202020;
lld arr[NMAX][4];
pl getv(lld a,lld b,lld c,lld d){
	lld x1 = __gcd(a,b);
	a /= x1;
	b /= x1;
	lld x2 = __gcd(c,d);
	c /= x2;
	d /= x2;
	lld y1 = b*d/__gcd(b,d);
	lld f1 = y1 / b;
	lld f2 = y1 / d;
	a *= f1;
	c *= f2;
	lld k1 = __gcd(a,c);
	return mk(a/k1,c/k1);
}
map<pl,int> mm;
int A[NMAX][2],vis[NMAX*2],nn[NMAX*2];
vector<int> v[NMAX*2];
set<int> s[NMAX*2];
map<pi,int> ck;
int kk[NMAX*2];
void solve(int tc){
	int n;
	cin >> n;
	int cnt = 1;
	for(int e=1;e<=n;e++){
		cin >> arr[e][0] >> arr[e][1] >> arr[e][2] >> arr[e][3];
		pl v1 = getv(arr[e][0]+arr[e][1],arr[e][1],arr[e][2],arr[e][3]);
		pl v2 = getv(arr[e][0],arr[e][1],arr[e][2]+arr[e][3],arr[e][3]);
		if(!mm.count(v1)) mm[v1] = cnt++;
		if(!mm.count(v2)) mm[v2] = cnt++;
		A[e][0] = mm[v1];
		A[e][1] = mm[v2];
		s[A[e][0]].insert(e);
		s[A[e][1]].insert(e);
		int k1 = min(A[e][0],A[e][1]);
		int k2 = max(A[e][0],A[e][1]);
		if(!ck.count(mk(k1,k2))){
			ck[mk(k1,k2)] = 1;
			v[k1].push_back(k2);
			v[k2].push_back(k1);
			nn[k2]++;
			nn[k1]++;
		}
	}
	queue<int> q;
	for(int e=1;e<=cnt;e++) if(nn[e]==1){
		q.push(e);
		for(set<int>::iterator it = s[e].begin();it!=s[e].end();){
			if(kk[*it]) s[e].erase(it++);
			else it++;
		}
	}
	vector<pi> ans;
	while(!q.empty()){
		int xx = q.front();q.pop();
		vis[xx] = 1;
		int nx = -1;
		for(int p=0;p<sz(v[xx]);p++){
			int nnx = v[xx][p];
			if(vis[nnx]==0) nx = nnx; 
		}
		if(nx!=-1){
			for(set<int>::iterator it = s[nx].begin();it!=s[nx].end();){
				if(kk[*it]) s[nx].erase(it++);
				else it++;
			}

		}
		for(set<int>::iterator it = s[xx].begin();it!=s[xx].end();){
			it++;
			if(it==s[xx].end()) break;
			it--;
			int f1 = *it;
			it++;
			int f2 = *it;
			ans.push_back(mk(f1,f2));
			kk[f1] = 1;
			kk[f2] = 1;
			if(nx!=-1) s[nx].erase(f1);
			if(nx!=-1) s[nx].erase(f2);
			it--;
			s[xx].erase(it++);
			s[xx].erase(it++);
		}
		if(nx!=-1){
			nn[nx]--;
			if(nn[nx]==1) q.push(nx);
		}
	}
	for(int e=1;e<=cnt;e++){
		if(vis[e]==0){
			int xx = e,lx = -1;
			for(set<int>::iterator it = s[xx].begin();it!=s[xx].end();){
				if(kk[*it]) s[xx].erase(it++);
				else it++;
			}
			while(true){
				vis[xx] = 1;
				int nx = -1;
				for(int p=0;p<sz(v[xx]);p++){
					int nnx = v[xx][p];
					if(nnx!=lx&&vis[nnx]==0){
						nx = nnx;
					}
				}
				if(nx!=-1){
					for(set<int>::iterator it = s[nx].begin();it!=s[nx].end();){
						if(kk[*it]) s[nx].erase(it++);
						else it++;
					}

				}
				for(set<int>::iterator it = s[xx].begin();it!=s[xx].end();){
					it++;
					if(it==s[xx].end()) break;
					it--;
					int f1 = *it;
					it++;
					int f2 = *it;
					kk[f1] = 1;
					kk[f2] = 1;
					ans.push_back(mk(f1,f2));
					if(nx!=-1) s[nx].erase(f1);
					if(nx!=-1) s[nx].erase(f2);
					it--;
					s[xx].erase(it++);
					s[xx].erase(it++);
				}
				if(nx==-1||nx==e) break;
				lx = xx;
				xx = nx;
			}
		}
	}
	cout << sz(ans) << "\n";
	for(int e=0;e<sz(ans);e++) cout << ans[e].x << " " << ans[e].y << "\n";
}


int main(void){
	
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int tc = 1;
	/*
		cin >> tc;
	*/
	for(int test_number=1;test_number<=tc;test_number++){
		solve(test_number);
	}
	return 0;
}