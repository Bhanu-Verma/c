#include <bits/stdc++.h>
using namespace std;


int binary_search(int* arr, int n, int key){
    int s=0, e=n-1;
    int mid=s+(e-s)/2;

    while(s<=e){
        if(arr[mid]==key){
            return mid;
        }
        else if(arr[mid]>key){
            e=mid-1;
        }else{
            s=mid+1;
        }
        mid=s+(e-s)/2;
    }
    return -1;
}

int main(){
    int n;
    scanf("%d",&n);
    int* arr = (int*) calloc(n,sizeof(int));
    for(int i=0; i<n; i++){
        scanf("%d",arr+i);
    }

  //  imerge_sort(arr,n);

    cout<<binary_search(arr,n,5)<<endl;
    return 0;
}