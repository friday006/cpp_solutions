#include<bits/stdc++.h>
using namespace std;

int getmin(int arr[],int n){
    int mini=INT_MAX;

    for(int i=0;i<n;i++){
        mini=min(arr[i],mini);
    }

    return mini;
}

void solve(){
    int n;
    cin>>n;

    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int mini=getmin(arr,n);
    // cout<<mini<<endl;
    int sum=0;

    for(int i=0;i<n;i++){
        sum+=(arr[i]-mini);
    }

    cout<<sum<<endl;
}
int main(){
    int t;
    cin>>t;

    while(t--){
        solve();
    }
    return 0;
}