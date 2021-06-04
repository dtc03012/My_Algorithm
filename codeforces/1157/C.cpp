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
int a[MAX];
void solve(int tc){
	int n;
	cin >> n;
	for(int e=1;e<=n;e++) cin >> a[e];
	string ans = "";
	int l = 1,r = n,lv = 0;
	while(l<=r){
		if(a[l]==a[r]){
			if(a[l]<lv) break;
			string f1 = "",f2 = "";
			int f1v = lv,f2v = lv;
			for(;a[l]>f1v;l++){
				f1 += "L";
				f1v = a[l];
			}
			for(;a[r]>f2v;r--){
				f2 += "R";
				f2v = a[r];
			}
			if(sz(f1)>sz(f2)) ans += f1;
			else ans += f2;
			break;
		}else{
			if(a[l]<=lv&&a[r]<=lv) break;
			if(a[l]<=lv&&a[r]>lv){
				ans += "R";
				lv = a[r--];
			}else if(a[l]>lv&&a[r]<=lv){
				ans += "L";
				lv = a[l++];
			}else{
				if(a[l]<a[r]){
					ans += "L";
					lv = a[l++];
				}else{
					ans += "R";
					lv = a[r--];
				}
			}
		}
	}
	cout << sz(ans) << "\n";
	cout << ans;
}


int main(void){
	
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int tc = 1;
	/*
		scanf("%d",&tc);
	*/
	for(int test_number=1;test_number<=tc;test_number++){
		solve(test_number);
	}
	return 0;
}