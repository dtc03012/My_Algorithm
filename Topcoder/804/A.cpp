
#include <vector>
#include <algorithm>
using namespace std;
#define sz(x) (int)x.size()
#define all(v) v.begin(), v.end()
const int MAX = 202020;
class YetAnotherGraphColoring{
public:
	int arr[MAX];
	int minColors(int n, int a1, int a2, int x, int y, int z, int m){
		arr[1] = a1;
		arr[2] = a2;
		for(int e=3;e<=n;e++){
			arr[e] = (1ll*x*arr[e-1]+1ll*y*arr[e-2]+z)%m;
		}
		vector<int> v;
		v.push_back(-arr[1]);
		for(int e=2;e<=n;e++){
			if(v.back()<-arr[e]) v.push_back(-arr[e]);
			else v[lower_bound(all(v),-arr[e])-v.begin()] = -arr[e];
		}
		return sz(v);
	}
};
