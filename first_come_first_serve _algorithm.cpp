#include<bits/stdc++.h>
using namespace std;

int main(){
    float n;
    int x,y,i;
    float atat=0;
    float a1,a2;
    float awt=0;
    int ct=0;
    cout<<"Enter number of Processes: ";
    cin>>n;
    vector<pair<int,int>>a; //to map the arrival time and burst time of process
    vector<int>ctime(n);
    vector<int>tat(n);
    vector<int>wt(n);
    for(i=0;i<n;i++){
        cout<<"Enter Arrival time of Process "<<i<<" = ";
        cin>>x;
        cout<<"Enter Burst time of Process "<<i<<" = ";
        cin>>y;
        a.push_back(make_pair(x,y));
        cout<<endl;
    }
    sort(a.begin(), a.end());//sort the arrival time so we can easily recognize which process comes first
    for(int j=0;j<n;j++){
        ctime[j]=ct+a[j].second;

        if(a[j+1].first<=a[j].second){
            ct+=a[j].second;
        }
        else{
            ct=a[j+1].first;
        }
    }
    cout<<endl;
    for(int q=0;q<n;q++){
        tat[q]=ctime[q]-a[q].first;
    }
    
    cout<<endl;
    for(int m=0;m<n;m++){
        wt[m]=tat[m]-a[m].second; 
    }

    for(int l=0;l<n;l++){
        atat=(atat+tat[l]);
       
        awt=(awt+wt[l]);
             
    }
     a1=atat/n;
     a2=awt/n;  

    cout<<"Process\t\tArrival Time\t\tBurst Time\t\tCompletion Time\t\tTurn Around Time\tWaiting Time"<<endl;
    for(int k=0;k<n;k++){
        cout<<k<<"\t\t"<<a[k].first<<"\t\t\t"<<a[k].second<<"\t\t\t"<<ctime[k]<<"\t\t\t"<<tat[k]<<"\t\t\t"<<wt[k]<<endl;
    }
    cout<<"Average Turn Around Time="<<a1<<endl;
    cout<<"Average waiting Time="<<a2;
    return 0;
}