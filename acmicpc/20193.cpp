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

const int NMAX = 101010;
const int MAX = 250505 * 2;
vector<int> v[MAX/2];
map<pi,int> ck[NMAX];
set<pi> s[NMAX];
int n,k,col[NMAX],yy[NMAX],lpos[NMAX],rpos[NMAX];
pi len[NMAX];
struct lazySeg{
	int start = 1,arr[MAX*4],lazy[MAX*4];
	lazySeg(){
		memset(arr,0,sizeof(arr));
		memset(lazy,0,sizeof(lazy));
		while(start<MAX) start *= 2;
	}
	void propagate(int node){
		if(lazy[node]){
			if(node<start){
				lazy[node*2] += lazy[node];
				lazy[node*2+1] += lazy[node];
			}
			arr[node] += lazy[node];
			lazy[node] = 0;
		}
	}
	void add(int node,int ns,int ne,int l,int r,int x){
		propagate(node);
		if(ne<=l||r<=ns) return;
		if(ns>=l&&ne<=r){
			lazy[node] += x;
			propagate(node);
			return;
		}
		int mid = (ns+ne)/2;
		add(node*2,ns,mid,l,r,x);
		add(node*2+1,mid,ne,l,r,x);
		arr[node] = max(arr[node*2],arr[node*2+1]);
	}
	void add(int l,int r,int x){
		add(1,0,start,l,r,x);
	}
	int sum(int l,int r){
		return sum(1,0,start,l,r);
	}
	int sum(int node,int ns,int ne,int l,int r){
		propagate(node);
		if(ne<=l||r<=ns) return 0;
		if(ns>=l&&ne<=r) return arr[node];
		int mid = (ns+ne)/2;
		return max(sum(node*2,ns,mid,l,r),sum(node*2+1,mid,ne,l,r));
	}
};
void erase(lazySeg& seg,int pos,int mid){
	if(len[pos].x==-1) return;
	int ll = len[pos].x;
	int rr = len[pos].y;
	int cl = col[pos];
	seg.add(ll,rr+1,-1);
	int lm = ll;
	set<pi>::iterator it = s[cl].lower_bound(mk(ll,pos));
	if(lpos[pos]!=-1){
		int npos = lpos[pos];
		int nll = len[npos].x;
		int nrr = yy[npos];
		seg.add(lm,nrr+1,1);
		lm = max(lm,nrr+1);
		len[npos] = mk(nll,nrr);
		rpos[npos] = rpos[pos];
	}
	if(rpos[pos]!=-1){
		int npos = rpos[pos];
		int nll = yy[npos] - mid;
		int nrr = len[npos].y;
		s[cl].erase(mk(nll,npos));
		nll = max(nll,lm);
		seg.add(nll,rr+1,1);
		len[npos] = mk(nll,nrr);
		lpos[npos] = lpos[pos];
		s[cl].insert(mk(nll,npos));
	}
	s[cl].erase(it);
	len[pos] = mk(-1,-1);
	lpos[pos] = rpos[pos] = -1;
}
void insert(lazySeg& seg,int pos,int mid){
	int ll = yy[pos] - mid;
	int rr = yy[pos];
	int cl = col[pos];
	set<pi>::iterator liv = s[cl].lower_bound(mk(ll,-1e9));
	if(liv!=s[cl].begin()){
		liv--;
		int npos = liv->y;
		ll = max(ll,len[npos].y+1);
		rpos[npos] = pos;
		lpos[pos] = npos;
		liv++;
	}
	if(liv!=s[cl].end()){
		rr = min(rr,liv->x-1);
		int npos = liv->y;
		lpos[npos] = pos;
		rpos[pos] = npos;
	}
	seg.add(ll,rr+1,1);
	len[pos] = mk(ll,rr);
	s[cl].insert(mk(ll,pos));
}
bool can(int x){
	for(int e=0;e<n;e++){
		len[e] = mk(-1,-1);
		lpos[e] = rpos[e] = -1;
	}
	for(int e=1;e<=k;e++) s[e].clear();
	lazySeg seg;
	for(int e=0;e<MAX/2;e++){
		int lx = e - x - 1;
		if(lx>=0){
			for(int p=0;p<sz(v[lx]);p++){
				int pos = v[lx][p];
				erase(seg,pos,x);
			}
		}
		for(int p=0;p<sz(v[e]);p++){
			int pos = v[e][p];
			insert(seg,pos,x);
		}
		if(seg.sum(0,MAX)==k) return true;
	}
	return false;
}
void solve(int tc){
	cin >> n >> k;
	for(int e=0;e<n;e++){
		int x,y,k;
		cin >> x >> y >> k;
		y += (MAX/2);
		col[e] = k;
		yy[e] = y;
		v[x].push_back(e);
	}
	int ll = 0,rr = MAX/2,mid,ans = MAX/2;
	while(ll<=rr){
		mid = (ll+rr)/2;
		if(can(mid)){
			ans = min(ans,mid);
			rr = mid - 1;
		}else ll = mid + 1;
	}
	cout << ans << "\n";
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