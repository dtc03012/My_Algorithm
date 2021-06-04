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
pi arr[MAX];
struct lazySeg{
	int arr[MAX*4],lazy[MAX*4],start = 1;
	lazySeg(){
	}
	void init(int n){
		start = 1;
		while(start<=n) start *= 2;
		for(int e=0;e<2*start;e++){
			arr[e] = lazy[e] = 0;
		}
	}
	void propagate(int node,int ns,int ne){
		if(lazy[node]){
			if(node<start){
				lazy[node*2] = lazy[node];
				lazy[node*2+1] = lazy[node];
			}
			if(lazy[node]==1) arr[node] = (ne-ns);
			else arr[node] = 0;
			lazy[node] = 0;
		}
	}
	void add(int l,int r,int v){
		add(1,0,start,l,r,v);
	}
	void add(int node,int ns,int ne,int l,int r,int v){
		propagate(node,ns,ne);
		if(ne<=l||r<=ns) return;
		if(ns>=l&&ne<=r){
			lazy[node] = v;
			propagate(node,ns,ne);
			return;
		}
		int mid = (ns+ne)/2;
		add(node*2,ns,mid,l,r,v);
		add(node*2+1,mid,ne,l,r,v);
		arr[node] = arr[node*2] + arr[node*2+1];
	}
	int sum(int l,int r){
		return sum(1,0,start,l,r);
	}
	int sum(int node,int ns,int ne,int l,int r){
		propagate(node,ns,ne);
		if(ne<=l||r<=ns) return 0;
		if(ns>=l&&ne<=r) return arr[node];
		int mid = (ns+ne)/2;
		return sum(node*2,ns,mid,l,r) + sum(node*2+1,mid,ne,l,r);
	}
};
lazySeg seg;
void solve(int tc){
	int n,q;
	scanf("%d%d",&n,&q);
	string a,b;
	cin >> a >> b;
	seg.init(n);
	for(int e=0;e<q;e++){
		scanf("%d%d",&arr[e].x,&arr[e].y);
		arr[e].x--;
		arr[e].y--;
	}
	for(int e=0;e<n;e++){
		int ty = 1;
		if(b[e]=='0') ty = 2;
		seg.add(e,e+1,ty);
	}
	bool suc = true;
	for(int e=q-1;e>=0;e--){
		int l = arr[e].x, r = arr[e].y;
		int xx = seg.sum(l,r+1);
		int len = r - l + 1;
		if(xx*2==len){
			suc = false;
			break;
		}else{
			if(xx*2<len){
				seg.add(l,r+1,2);
			}else{
				seg.add(l,r+1,1);
			}
		}
	}
	if(suc){
		string c = "";
		for(int e=0;e<n;e++){
			int now = seg.sum(e,e+1) + '0';
			c += now;
			if(now!=a[e]){
				suc = false;
				break;
			}
		}
	}
	if(suc) printf("YES\n");
	else printf("NO\n");
}


int main(void){
	/*
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	*/
	int tc = 1;
	
		scanf("%d",&tc);
	
	for(int test_number=1;test_number<=tc;test_number++){
		solve(test_number);
	}
	return 0;
}