/*
 		Resilience is the greatest of all virtues.
 		Code by rajiv
 */
 #include <iostream>
 #include <cstring>
 #include <vector>
 #include <map>
 #include <set>
 #include <stack>
 #include <queue>
 #include <deque>
 #include <sstream>
 #include <iomanip>
 #include <cassert>
 #include <sys/time.h>
 #include <algorithm>
 #include <bitset>
 #include <cmath>
 #include <functional>
 #include <cmath>

using namespace std;
typedef long long int lli;
multiset<lli>m;
lli a[100005],prefsum,ans,x;
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		cin>>x;
		m.insert(a[i]+prefsum);
		prefsum+=x;
		ans=lli(m.size())*x;
		while(m.size()&&*m.begin()<=prefsum){
			ans-=(prefsum-*m.begin());
			m.erase(m.begin());
		}
		cout<<ans<< "\n";
	}
}
