#include<bits/stdc++.h>
using namespace std;

vector<int> twosum(vector<int>& a,int n,int target){
    vector<int> ans;
    sort(a.begin(),a.end());
    int l=0,r=n-1;
    while(l<r){
        int sum=a[l]+a[r];
        if(sum==target){
            return {a[l],a[r]};
        }else if(sum<target){
            l++;
        }else{
            r--;
        }
    }
    return {-1,-1};
}


int main(){
    int n;
    cout<<"enter the size of the array:";
    cin>>n;
    vector<<int> a;
    for(int i=0;i<n;i++){
        int num;
        cout<<"enter the number:";
        cin>>num;
        a.push_back(num);
    }
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<"\n";
    vector<int> ans=twosum(a,n,5);
    for(int i=0;i<2;i++){
        cout<<ans[i]<<" ";
    }
    
}
