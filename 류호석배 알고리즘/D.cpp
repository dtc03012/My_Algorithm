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

const int MAX = 1010;
struct inf{
	string x;
	vector<string> vk;
	inf() : x(""){

	}
	inf(string x) : x(x){

	}
	void push_back(string a){
		vk.push_back(a);
	}
	bool operator<(const inf& O){
		return x < O.x;
	}
};
inf arr[MAX];
map<string,int> mm;
string org[MAX];
vector<int> v[MAX],rv[MAX];
int sz[MAX],vis[MAX];
bool comp(int a,int b){
	return org[a] < org[b];
}
void solve(int tc){
	int n;
	cin >> n;
	for(int e=1;e<=n;e++){
		string a;
		cin >> a;
		org[e] = a;
		mm[a] = e;
	}
	int m;
	cin >> m;
	for(int e=0;e<m;e++){
		string a,b;
		cin >> a >> b;
		int f1 = mm[a];
		int f2 = mm[b];
		v[f2].push_back(f1);
		sz[f1]++;
	}
	vector<int> root,now;
	for(int e=1;e<=n;e++){
		if(sz[e]==0){
			root.push_back(e);
			now.push_back(e);
		}
	}
	while(true){
		if(sz(now)==0) break;
		vector<int> nextv;
		for(int e=0;e<sz(now);e++){
			int x = now[e];
			for(int p=0;p<sz(v[x]);p++){
				int nx = v[x][p];
				sz[nx]--;
			}
		}
		for(int e=0;e<sz(now);e++){
			int x = now[e];
			for(int p=0;p<sz(v[x]);p++){
				int nx = v[x][p];
				if(sz[nx]==0){
					rv[x].push_back(nx);
					nextv.push_back(nx);
				}
			}
		}
		now = nextv;
	}
	for(int e=1;e<=n;e++){
		arr[e] = inf(org[e]);
		for(int p=0;p<sz(rv[e]);p++){
			int nx = rv[e][p];
			arr[e].push_back(org[nx]);
		}
		sort(all(arr[e].vk));
	}
	cout << sz(root) << "\n";
	sort(all(root),comp);
	for(int e=0;e<sz(root);e++) cout << org[root[e]] << " ";
	cout << "\n";
	sort(arr+1,arr+n+1);
	for(int e=1;e<=n;e++){
		cout << arr[e].x << " " << sz(arr[e].vk) << " ";
		for(int p=0;p<sz(arr[e].vk);p++) cout << arr[e].vk[p] << " ";
		cout << "\n";
	}
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