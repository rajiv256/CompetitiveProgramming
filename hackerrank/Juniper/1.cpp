#include <iostream> 
using namespace std;
#define ll long long int
int main()
{
    int test;
    cin>>test;
    while(test--)
    {
        string S;
        cin>>S;
        // count substring
        ll count = 1, ans = 0;
        for(int i=1;i<S.size();i++)
        {
            if(S[i]!=S[i-1])
                count++;
            else{
                ans += (count*(count+1))/2;
                count = 1;
            }
        }
        ans += (count*(count+1))/2;
        cout<<ans<<endl;
    }
    return 0;
}