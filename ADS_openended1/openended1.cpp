#include<bits/stdc++.h>
using namespace std;

void displaySort(vector<int> arr){
    sort(arr.begin(),arr.end());

    for(int j=0;j<arr.size()-2;j++)
        cout<<arr[j]<<" ";

    cout<<"\n";
}

int main(){
    int t,n,ele;
    cin>>t;

    vector<vector<int>> arr;

    for(int i=0;i<t;i++){
        cin>>n;

        vector<int> row;

        for(int j=0;j<n;j++){
            cin>>ele;
            row.push_back(ele); 
        }

        arr.push_back(row);
    
    }

    for(int i=0;i<t;i++)
        displaySort(arr[i]);
}
