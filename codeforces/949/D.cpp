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
const int MAX = 101010;
lld vv[MAX*4];
struct lazySeg{
	lld arr[MAX*4];
	int start = 1;
	int lazy[MAX*4];
	lazySeg(){
	}
	void init(int V){
		while(start<=V) start *= 2;
		for(int e=start;e<start*2;e++) arr[e] = vv[e-start];
		for(int e=start-1;e>=1;e--) arr[e] = arr[e*2] + arr[e*2+1];
	}
	void propagate(int node,int ns,int ne){
		if(lazy[node]){
			if(node<start){
				lazy[node*2] = lazy[node];
				lazy[node*2+1] = lazy[node];
			}
			if(lazy[node]){
				arr[node] = 0;
			}
			lazy[node] = 0;
		}
	}
	lld add(lld l,lld r,int ty,lld v){
		return add(1,0,start,(int)l,(int)r,ty,v);
	}
	void go(int node,int ns,int ne,int ty,lld v){
		propagate(node,ns,ne);
		if(ns+1==ne){
			arr[node] -= v;
			return;
		}
		int mid = (ns+ne)/2;
		propagate(node*2,ns,mid);
		propagate(node*2+1,mid,ne);
		if(ty==0){
			if(arr[node*2]>=v) go(node*2,ns,mid,ty,v);
			else{
				lld xx = arr[node*2];
				lazy[node*2] = 1;
				propagate(node*2,ns,mid);
				go(node*2+1,mid,ne,ty,v-xx);
			}
		}else{
			if(arr[node*2+1]>=v) go(node*2+1,mid,ne,ty,v);
			else{
				lld xx = arr[node*2+1];
				lazy[node*2+1] = 1;
				propagate(node*2+1,mid,ne);
				go(node*2,ns,mid,ty,v-xx);
			}
		}
		arr[node] = arr[node*2] + arr[node*2+1];
	}
	lld add(int node,int ns,int ne,int l,int r,int ty,lld v){
		propagate(node,ns,ne);
		if(ne<=l||r<=ns) return 0;
		if(ns>=l&&ne<=r){
			lld dist = min(arr[node],v);
			if(dist>=arr[node]){
				lazy[node] = 1;
				propagate(node,ns,ne);
			}else if(v){
				go(node,ns,ne,ty,v);
			}
			return dist;
		}
		if(ty==0){
			int mid = (ns+ne)/2;
			lld xx = add(node*2,ns,mid,l,r,ty,v);
			xx += add(node*2+1,mid,ne,l,r,ty,v-xx);
			arr[node] = arr[node*2] + arr[node*2+1];
			return xx;
		}else{
			int mid = (ns+ne)/2;
			lld xx = add(node*2+1,mid,ne,l,r,ty,v);
			xx += add(node*2,ns,mid,l,r,ty,v-xx);
			arr[node] = arr[node*2] + arr[node*2+1];
			return xx;
		}
	}
	lld sum(lld l,lld r){
		return sum(1,0,start,(int)l,(int)r);
	}
	lld sum(int node,int ns,int ne,int l,int r){
		propagate(node,ns,ne);
		if(ne<=l||r<=ns) return 0;
		if(ns>=l&&ne<=r) return arr[node];
		int mid = (ns+ne)/2;
		return sum(node*2,ns,mid,l,r) + sum(node*2+1,mid,ne,l,r);
	}
};
lazySeg seg;
void solve(int tc){
	lld n,d,b;
	scanf("%lld%lld%lld",&n,&d,&b);
	for(int e=0;e<n;e++) scanf("%lld",&vv[e]);
	seg.init(n);
	int x1 = 0,x2 = 0;
	lld ll = 0,rr = n-1,cnt = 1;
	while(ll<=rr){
		if(ll==rr){
			lld tot = seg.sum(max(0ll,ll-cnt*d),min(n-1,ll+cnt*d)+1);
			if(tot<b) x1++;
			break;
		}else{
			if(x1>=x2){
				lld v1 = seg.sum(max(0ll,ll-cnt*d),min(n-1,ll+cnt*d)+1);
				if(v1<b) x1++;
				else seg.add(max(0ll,ll-cnt*d),min(n-1,ll+cnt*d)+1,0,b);
				lld v2 = seg.sum(max(0ll,rr-cnt*d),min(n-1,rr+cnt*d)+1);
				if(v2<b) x2++;
				else seg.add(max(0ll,rr-cnt*d),min(n-1,rr+cnt*d)+1,1,b);
			}else{
				lld v2 = seg.sum(max(0ll,rr-cnt*d),min(n-1,rr+cnt*d)+1);
				if(v2<b) x2++;
				else seg.add(max(0ll,rr-cnt*d),min(n-1,rr+cnt*d)+1,1,b);
				lld v1 = seg.sum(max(0ll,ll-cnt*d),min(n-1,ll+cnt*d)+1);
				if(v1<b) x1++;
				else seg.add(max(0ll,ll-cnt*d),min(n-1,ll+cnt*d)+1,0,b);
			}
			ll++;
			rr--;
		}
		cnt++;
	}
	printf("%d\n",max(x1,x2));
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