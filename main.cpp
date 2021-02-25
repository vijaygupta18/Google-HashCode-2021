#include<bits/stdc++.h> 
using namespace std; 
#define ll long long 
#define pb push_back
#define mp make_pair
ll mod= 998244353;
ll st[1000000];
ll power(ll n,ll k){
    ll res=1;
    while(k){
        if(k%2!=0){
            res*=n;
        }
        n=n*n;
        k/=2;
    }
    return res;
}

ll binary(vector<pair<string,pair<ll,ll>>> arr, ll l, ll r, string x) 
{ 
    if (r >= l) { 
        ll mid = l + (r - l) / 2; 
  
        // If the element is present at the middle 
        // itself 
        if (arr[mid].first==x) 
            return mid; 
  
        // If element is smaller than mid, then 
        // it can only be present in left subarray 
        if (arr[mid].first > x) 
            return binary(arr, l, mid - 1, x); 
  
        // Else the element can only be present 
        // in right subarray 
        return binary(arr, mid + 1, r, x); 
    } 
  
    // We reach here when element is not 
    // present in array 
    return -1; 
} 

int main(){ 
    ios_base::sync_with_stdio(false);cin.tie(NULL); 
    
    #ifndef ONLINE_JUDGE 
    freopen("a.txt", "r", stdin); 
    freopen("aa.txt", "w", stdout); 
    #endif 
 
    ll d,i,s,f,v;
    cin>>d>>i>>s>>v>>f;
    vector<pair<string,pair<ll,ll>>> street;
    for(ll j=0;j<s;j++){
        ll x,y,z;
        cin>>x>>y;
        string str;
        cin>>str>>z;
        street.pb(mp(str,mp(x,y)));
    }
    vector<string> sig[100000];
    // for(ll j=0;j<street.size();j++)
    //     cout<<street[]
    sort(street.begin(),street.end());
    for(ll j=0;j<v;j++){
        ll x;
        cin>>x;
        for(ll z=0;z<x;z++){
            string str;
            cin>>str;
            ll pos;
            if(z!=x-1){
               pos=binary(street,0,street.size(),str);
            sig[street[pos].second.second].pb(street[pos].first); 
            }
            
        }
    }
    ll te=0;
    for(ll j=0;j<100000;j++){
        if(!sig[j].empty()){
            te++;
        }
    }
    cout<<te<<'\n';
    for(ll j=0;j<100000;j++){
        if(!sig[j].empty()){
            cout<<j<<'\n';
            set<string> s1;
            for(ll x=0;x<sig[j].size();x++)
                s1.insert(sig[j][x]);
            cout<<s1.size()<<'\n';
            for(auto itr=s1.begin();itr!=s1.end();itr++)
                cout<<*itr<<" 1\n";
        }
    }
    cerr<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl; 
    return 0; 
}