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
int A[MAX],B[MAX];
void solve(int tc){
	int n;
	scanf("%d",&n);
	for(int e=0;e<n;e++) scanf("%d",&A[e]);
	for(int e=0;e<n;e++) scanf("%d",&B[e]);
	set<pi> s;
	for(int e=0;e<n;e++){
		if(sz(s)==0){
			if(A[e]-B[e]<=0){
				s.insert(mk(A[e],B[e]-A[e]+1));
			}
		}else{
			if(A[e]-B[e]<=0){
				int xx = A[e];
				for(set<pi>::iterator it=prev(s.end());;){
					if(it->y>B[e]-A[e]+1){
						xx = min(xx,it->x);
						if(it==s.begin()){
							s.erase(it);
							break;
						}else{
							s.erase(it--);
						}
					}else{
						break;
					}
				}
				s.insert(mk(xx,B[e]-A[e]+1));
			}else{
				set<pi>::iterator it  = s.lower_bound(mk(A[e]-B[e],-1));
				for(;it!=s.end();) s.erase(it++);
			}
		}
	}
	if(sz(s)==0) printf("0\n");
	else{
		set<pi>::iterator it = prev(s.end());
		printf("%d\n",it->y);
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