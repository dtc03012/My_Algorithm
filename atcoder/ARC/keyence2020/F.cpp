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
pair<pi,int> arr[MAX];
lld col[MAX];
vector<int> idx;
int start = 1;
lld seg[MAX*3*4];
int getidx(int x){
	return lower_bound(all(idx),x) - idx.begin();
}
void add(int x,lld v){
	x += start;
	seg[x] += v;
	for(int e=(x/2);e>=1;e/=2) seg[e] = seg[e*2] + seg[e*2+1];
}
lld getn(int l,int r){
	l += start;
	r += start;
	lld tot =0;
	while(l<=r){
		if(l&1) tot += seg[l++];
		if(!(r&1)) tot += seg[r--];
		l >>= 1;
		r >>= 1;
	}
	return tot;
}
lld ans[MAX];
void solve(int tc){
	while(start<MAX*3) start *= 2;
	int n,l;
	scanf("%d%d",&n,&l);
	for(int e=0;e<n;e++){
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		arr[e] = mk(mk(x,y),z);
		idx.push_back(y);
		idx.push_back(y-l);
		idx.push_back(y+l);
	}
	sort(all(idx));
	idx.erase(unique(all(idx)),idx.end());
	priority_queue<pi> q;
	sort(arr,arr+n);
	for(int e=0;e<n;e++){
		while(!q.empty()){
			int x = -q.top().x;
			int pos = q.top().y;
			if(x+l>=arr[e].x.x) break;
			add(getidx(arr[pos].x.y),-arr[pos].y);
			q.pop();
		}
		add(getidx(arr[e].x.y),arr[e].y);
		ans[e] = getn(getidx(arr[e].x.y-l),getidx(arr[e].x.y+l));
		q.push(mk(-arr[e].x.x,e));
	}
	for(int e=0;e<start*2;e++) seg[e] = 0;
	q = priority_queue<pi>();
	for(int e=n-1;e>=0;e--){
		while(!q.empty()){
			int x = q.top().x;
			int pos = q.top().y;
			if(x-l<=arr[e].x.x) break;
			add(getidx(arr[pos].x.y),-arr[pos].y);
			q.pop();
		}
		ans[e] += getn(getidx(arr[e].x.y-l),getidx(arr[e].x.y+l));
		q.push(mk(arr[e].x.x,e));
		add(getidx(arr[e].x.y),arr[e].y);
	}
	lld mx = 0;
	for(int e=0;e<n;e++) mx = max(mx,ans[e]);
	printf("%lld",mx);
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