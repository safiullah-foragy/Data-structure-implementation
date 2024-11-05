
#include <bits/stdc++.h>
using namespace std;

void solve()

 {
int cnt1,cnt2;
        cin>>cnt1>>cnt2;
        if(cnt1%2)
        {
            cout<<"NO"<<endl;
        }
        else
        {
            if(cnt2%2==0)
            {
                cout<<"YES"<<endl;
            }
            else
            {
                if(cnt1==0)
                {
                    cout<<"NO"<<endl;
                }
                else
                {
                    cout<<"YES"<<endl;
                }
            }
        }

}
   

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}
