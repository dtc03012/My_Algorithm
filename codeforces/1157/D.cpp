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
lld arr[MAX],can[MAX];
void solve(int tc){
	lld n,k;
	scanf("%lld%lld",&k,&n);
	lld least = (n*(n+1))/2;
	if(k<least) printf("NO\n");
	else{
		if(n==1){
			printf("YES\n");
			printf("%lld\n",k);
			return;
		}
		lld orgk = k;
		{
			k -= least;
			priority_queue<pli> pq;
			for(int e=1;e<n;e++){
				arr[e] = e;
				pq.push(mk(0ll,e));
			}
			arr[n] = n;
			can[n] = arr[n-1] - 1;
			pq.push(mk(arr[n-1]-1,n));
			while(k>0){
				pli xx = pq.top();pq.pop();
				lld vv = xx.x;
				int pos = xx.y;
				if(vv<=0) break;
				if(can[pos]!=vv) continue;
				if(k<=vv){
					arr[pos] += min(k,vv);
					k = 0;
					break;
				}
				k -= vv;
				arr[pos] += vv;
				if(pos>1){
					lld rr = arr[pos] - 1;
					if(pos-1>1) rr = min(rr,arr[pos-2]*2);
					can[pos-1] = rr - arr[pos-1];
					pq.push(mk(can[pos-1],pos-1));
				}
				if(pos<n){
					lld rr = arr[pos] * 2;
					if(pos+1<n) rr = min(rr,arr[pos+2]-1);
					can[pos+1] = rr - arr[pos+1];
					pq.push(mk(can[pos+1],pos+1));
				}
			}
			if(k==0){
				printf("YES\n");
				for(int e=1;e<=n;e++) printf("%lld ",arr[e]);
				printf("\n");
				return;
			}
		}
		{
			k = orgk;
			if(least+n>k){
				printf("NO\n");
				return;
			}
			k -= least + n;
			priority_queue<pli> pq;
			for(int e=1;e<n;e++){
				arr[e] = e + 1;
				pq.push(mk(0ll,e + 1));
			}
			arr[n] = n + 1;
			can[n] = arr[n-1] - 1;
			pq.push(mk(arr[n-1]-1,n));
			while(k>0){
				pli xx = pq.top();pq.pop();
				lld vv = xx.x;
				int pos = xx.y;
				if(vv<=0) break;
				if(can[pos]!=vv) continue;
				if(k<=vv){
					arr[pos] += min(k,vv);
					k = 0;
					break;
				}
				k -= vv;
				arr[pos] += vv;
				if(pos>1){
					lld rr = arr[pos] - 1;
					if(pos-1>1) rr = min(rr,arr[pos-2]*2);
					can[pos-1] = rr - arr[pos-1];
					pq.push(mk(can[pos-1],pos-1));
				}
				if(pos<n){
					lld rr = arr[pos] * 2;
					if(pos+1<n) rr = min(rr,arr[pos+2]-1);
					can[pos+1] = rr - arr[pos+1];
					pq.push(mk(can[pos+1],pos+1));
				}
			}
			if(k>0){
				printf("NO\n");
				return;
			}
			if(k==0){
				printf("YES\n");
				for(int e=1;e<=n;e++) printf("%lld ",arr[e]);
				printf("\n");
			}
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
		scanf("%d",&tc);
	*/
	for(int test_number=1;test_number<=tc;test_number++){
		solve(test_number);
	}
	return 0;
}