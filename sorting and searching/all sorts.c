#include "array.c"

int min(int a, int b){
    if(a<b){
        return a;
    }else{
        return b;
    }
}

void selection_sort(int* arr, int n){
    
    for(int i=0; i<n; i++){
        int min_idx=i;
        for(int j=i+1; j<n; j++){
            if(arr[j]<arr[min_idx]){
                min_idx=j;
            }
        }
        swap(arr+i,arr+min_idx);
    }
}

 void rselection_sort(int* arr, int n, int idx){
    if(idx==n){
        return;
    }
    int min_idx=idx;
    for(int j=idx+1; j<n; j++){
        if(arr[j]<arr[min_idx]){
            min_idx=j;
        }
    }
    swap(arr+idx,arr+min_idx);
    rselection_sort(arr,n,idx+1);
}

void rinsertion_sort(int* arr, int n, int idx){
    if(idx==n){
        return;
    }
    int t=arr[idx];
    int j=idx-1;
     while(arr[j]>t && j>=0){
        arr[j+1]=arr[j];
        j--;
    }
    arr[j+1]=t;
    rinsertion_sort(arr,n,idx+1);
}

void rbubble_sort(int* arr, int n, int idx){
    if(idx==n){
        return;
    }

    for(int j=0; j<n-idx; j++){
        if(arr[j+1]<arr[j]){
            swap(arr+j+1, arr+j);
        }
    }

    rbubble_sort(arr,n,idx+1);
}

void merge(int* arr, int l, int mid, int r){
    int n1=mid-l+1;
    int n2=r-mid;
    int* arr1=(int*) calloc(n1,sizeof(int));
    int* arr2=(int*) calloc(n2,sizeof(int));
    for(int i=0; i<n1; i++){
        arr1[i]=arr[l+i];
    }
    for(int i=0; i<n2; i++){
        arr2[i]=arr[mid+1+i];
    }
    print(arr1,n1);
    print(arr2,n2);
    int i=0, j=0, k=l;
    while(i<n1 && j<n2){
        if(arr1[i]<arr2[j]){
            arr[k++]=arr1[i++];
        }else{
            arr[k++]=arr2[j++];
        }
    }

    while (i<n1)
    {
        arr[k++]=arr1[i++];
    }
    
    while (j<n2)
    {
        arr[k++]=arr2[j++];
    }
    
    free(arr1);
    free(arr2);

}

void merge_sort(int* arr, int s, int e,int n){
    if(s>=e){
        return;
    }
    int mid=s+(e-s)/2;
    merge_sort(arr,s,mid,n);
    merge_sort(arr,mid+1,e,n);
    merge(arr,s,mid,e);
    printf("original array:\n");
    print(arr,n);
}

void imerge_sort(int* arr,int n){
    int len=1;
    while(len<n){
        
        int s=0;
        while(s<n-1){
            int mid=min(s+len-1,n-1);
            int e=min(s+2*len-1,n-1);
            merge(arr,s,mid,e);
            s+=2*len;
        }
        print(arr,n);
        len*=2;
    }
}

int pivot(int* arr, int s, int e){
    int x = arr[s];
    int i=e+1;
    for(int j=e; j>s; j--){
        if(arr[j]>x){
            i--;
            swap(arr+j,arr+i);
        }
    }
    swap(arr+i-1, arr+s);
    return i-1;
}

void quick_sort(int* arr, int s, int e){
    while(s<e){
         int p=pivot(arr,s,e);
        printf("p=%d\n",p);
        quick_sort(arr,s,p-1);
        s=p+1;
    }
}

int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    input(arr,n);
    merge_sort(arr,0,n-1,n);
    print(arr,n);
    return 0;
}