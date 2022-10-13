// find a unique no in an array where all elements repeat thrice except unique one.
#include <iostream>
using namespace std;

int getBit(int n,int pos){
    return (n&(1<<pos)) !=0;
}

int setBit(int n,int pos){
    return (n|(1<<pos));
}

int unique(int a[],int n){
    int result=0;
    for(int i=0;i<64;i++){
        int sum=0;
        for(int j=0;j<n;j++){
            if(getBit(a[j],i)){
                sum++;
            }
        }
        
        if(sum%3 !=0){
            result = setBit(result,i);
        }
    }
    return result;
}

int main(){
    int a[]={1,3,2,3,8,2,1,1,3,2};
    cout << unique(a,10)<<endl;
}