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

const int MAX = 303030;
struct lazySeg{
	lld arr[MAX*4],hei[MAX*4];
	lld alazy[MAX*4],hlazy[MAX*4];
	pi len[MAX*4];
	int start = 1;
	lazySeg(){
		memset(alazy,-1,sizeof(alazy));
		memset(hlazy,-1,sizeof(hlazy));
		while(start<MAX) start *= 2;
		go(1,0,start);
	}
	void go(int node,int ns,int ne){
		len[node] = mk(ns,ne);
		if(ns+1==ne) return;
		int mid = (ns+ne)/2;
		go(node*2,ns,mid);
		go(node*2+1,mid,ne);
	}
	void propagate(int node){
		if(alazy[node]!=-1){
			if(node<start){
				alazy[node*2] = alazy[node];
				alazy[node*2+1] = alazy[node];
			}
			arr[node] = alazy[node];
			alazy[node] = -1;
		}
		if(hlazy[node]!=-1){
			if(node<start){
				hlazy[node*2] = hlazy[node];
				hlazy[node*2+1] = hlazy[node];
			}
			hei[node] = hlazy[node];
			hlazy[node] = -1;
		}
	}
	void add(int l,int r,int x,int v){
		add(1,0,start,l,r,x,v);
	}
	void add(int node,int ns,int ne,int l,int r,int x,int v){
		propagate(node,ns,ne);
		if(r<=ns||ne<=l) return;
		if(ns>=l&&ne<=r){
			alazy[node] = x;
			hlazy[node] = v;
			propagate(node);
			return;
		}
		int mid = (ns+ne)/2;
		add(node*2,ns,mid,l,r,x,v);
		add(node*2+1,mid,ne,l,r,x,v);
		hei[node] = max(hei[node*2],hei[node*2+1]);
	}
	lld sum(int l){
		return sum(1,0,start,l,l+1);
	}
	lld sum(int node,int ns,int ne,int l,int r){
		propagate(node,ns,ne);
		if(r<=ns||ne<=l) return 0;
		if(ns>=l&&ne<=r) return arr[node];
		int mid = (ns+ne)/2;
		return sum(node*2,ns,mid,l,r) + sum(node*2+1,mid,ne,l,r);
	}
	int rfind(int l,int r,int h){
		l += start;
		r += start;
		int vv[50];
		memset(vv,-1,sizeof(vv));
		int ll = 0,rr = 49;
		while(l<=r){
			if(l&1) vv[ll++] = l++;
			if(!(r&1)) vv[rr--] = r--;
			l >>= 1;
			r >>= 1;
		}
		for(int e=0;e<50;e++){
			if(vv[e]==-1) continue;
			if(hei[vv[e]]>=h){

			}
		}
	}
}
void solve(int tc){
	int n,q;
	scanf("%d%d",&n,&q);

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