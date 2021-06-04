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
int arr[MAX],ck[MAX];
vector<int> k[MAX],v;
int getidx(int x){
	return lower_bound(all(v),x) - v.begin();
}
void solve(int tc){
	int n;
	scanf("%d",&n);
	bool suc = true;
	for(int e=1;e<=n;e++){
		scanf("%d",&arr[e]);
		v.push_back(arr[e]);
		if(e>1&&arr[e]!=arr[e-1]) suc = false;
	}
	if(n==1){
		printf("1");
		return;
	}
	if(suc){
		printf("-1");
		return;
	}
	sort(all(v));
	v.erase(unique(all(v)),v.end());
	for(int e=1;e<=n;e++){
		arr[e] = getidx(arr[e]);
		k[arr[e]].push_back(e);
	}
	vector<int> ans;
	set<int> s;
	s.insert(0);
	s.insert(n+1);
	int lim = sz(v) - 1;
	for(int e=0;e<sz(k[lim]);e++){
		int x = k[lim][e];
		bool k1 = false,k2 = false;
		if(x>1&&arr[x-1]<arr[x]) k1 = true;
		if(x<n&&arr[x+1]<arr[x]) k2 = true;
		if(k1||k2) ck[x] = 1;
		s.insert(x);
	}
	for(int e=lim-1;e>=0;e--){
		int ll = -1,lst = -1;
		for(int p=0;p<sz(k[e]);p++){
			int x = k[e][p];
			set<int>::iterator it = s.lower_bound(x);
			it--;
			if(ll!=*it){
				if(lst!=-1){
					int nn = (*it) - ll - 2 + v[e];
					bool suc = false;
					if(ll&&nn>v[arr[ll]]&&ck[ll]) suc = true;
					if(nn>v[arr[*it]]&&ck[*it]) suc = true;
					if(suc){
						for(int q=lst;q<p;q++){
							int nx = k[e][q];
							bool k1 = false,k2 = false;
							if(nx>1&&arr[nx-1]<arr[nx]) k1 = true;
							if(nx<n&&arr[nx+1]<arr[nx]) k2 = true;
							if(k1||k2) ck[nx] = 1;
						}
					}
				}
				ll = *it;
				lst = p;
			}
		}
		set<int>::iterator it = s.lower_bound(k[e][sz(k[e])-1]);
		int nn = (*it) - ll - 2 + v[e];
		bool suc = false;
		if(ll&&nn>v[arr[ll]]&&ck[ll]) suc = true;
		if((*it)!=n+1&&nn>v[arr[*it]]&&ck[*it]) suc = true;
		if(suc){
			 for(int q=lst;q<sz(k[e]);q++){
			 	int nx = k[e][q];
				bool k1 = false,k2 = false;
				if(nx>1&&arr[nx-1]<arr[nx]) k1 = true;
				if(nx<n&&arr[nx+1]<arr[nx]) k2 = true;
				if(k1||k2) ck[nx] = 1;
			 }
		}
		for(int p=0;p<sz(k[e]);p++) s.insert(k[e][p]);
	}
	for(int e=1;e<=n;e++){
		if(ck[e]){
			printf("%d ",e);
		}
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