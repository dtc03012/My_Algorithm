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

const int MAX = 5050;
int arr[MAX],ck[MAX];
void solve(int tc){
	int n;
	scanf("%d",&n);
	for(int e=1;e<=n;e++){
		scanf("%d",&arr[e]);
		ck[e] = 0;
	}
	lld ans = 0;
	for(int e=1;e<=n;e++){
		int df = arr[e] - (n-e);
		if(df>=ck[e]){
			arr[e] -= ck[e];
			arr[e] = max(arr[e],1);
			if(e==n){
				if(arr[e]-df>=1){
					arr[e] -= df;
					ans += df;
				}else{
					ans += (arr[e]-1);
					break;
				}
			}else{
				df -= ck[e];
				ans += df;
				arr[e] -= df;
				arr[e] = max(arr[e],1);
			}
		}else{
			if(e==n){
				break;
			}else{
				if(df>0){
					arr[e] -= df;
					ck[e] -= df;
				}
				int lim = ck[e];
				for(int p=0;p<lim&&arr[e]>1;p++){
					ck[e+arr[e]]++;
					arr[e]--;
					ck[e]--;
				}
				ck[e+1] += ck[e];
			}
		}
		assert(arr[e]<=n+100);
		while(arr[e]>1){
			ck[e+arr[e]]++;
			arr[e]--;
			ans++;
		}
	}
	printf("%lld\n",ans);
}


int main(void){
	
	
	int tc = 1;
	
		scanf("%d",&tc);
	
	for(int test_number=1;test_number<=tc;test_number++){
		solve(test_number);
	}
	return 0;
}