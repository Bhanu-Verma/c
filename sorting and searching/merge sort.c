//name - Bhanu Verma
//CSE B.Tech.
//Roll no.-22075021
//S. No. - 21




#include <stdio.h>
#include <stdlib.h>

            /*function to print the content of the array*/
void print(int* arr, int n){
    for(int i=0; i<n; i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}

void merge(int* arr, int s, int mid, int e){
    int n1=mid-s+1;     //size of the first half of the array
    int n2=e-mid;       //size of the second half of the array
    int* a=(int*) calloc(n1,sizeof(int));
    int* b=(int*) calloc(n2,sizeof(int));
    for(int i=0; i<n1; i++){
        a[i]=arr[s+i];          //copying the elements of the first half
    }
    for(int i=0; i<n2; i++){
        b[i]=arr[mid+1+i];        //copying the elements of the second half
    }
                    
    int i=0, j=0, k=s;      //thre variables to traverse the three arrays
    while(i<n1 && j<n2){
        if(a[i]<b[j]){
            arr[k++]=a[i++];
        }else{
            arr[k++]=b[j++];
        } 
    }

    while(i<n1){
        arr[k++]=a[i++];
    }

    while(j<n2){
        arr[k++]=b[j++];
    }
    free(a);
    free(b);
}

void merge_sort(int* arr, int s, int e){
    //base case
    if(s>=e){
        return;     
    }
    int mid=s+(e-s)/2;
    //recursive call to sort the left part of the array
    merge_sort(arr,s,mid);
    //recursive call to sort the right part of the array
    merge_sort(arr,mid+1,e);
    //now call to the merge functoin to merge the two sorted arrays
    merge(arr,s,mid,e);
}

int main(){
    int n;                  
    printf("enter the number of elemens in the array:\n");
    scanf("%d",&n);


    int* arr=(int*) calloc(n,sizeof(int));                  //declaration of array dynamically
    printf("enter the elements of the array:\n");
    for(int i=0; i<n; i++){
        scanf("%d",arr+i);                  //taking input of array element
    }


    printf("\n\narray before applying the merge sort:\n");
    print(arr,n);


    merge_sort(arr,0,n-1);          //call for the function of merge sort 

    
    printf("\n\narray after applying the merge sort:\n");
    print(arr,n);
    return 0;
}