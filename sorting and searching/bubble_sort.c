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
        /*function for the bubblesort*/
void special_bsort(int* arr, int n){
    int n1=n/2;             //to access first n/2 elements of the array
        /*to sort the first n/2 elements in the ascending order*/
    int count1=1;
    while(count1<=n1-1){
        for(int i=0; i<n1-count1; i++){
            if(arr[i]>arr[i+1]){
                int t=arr[i];
                arr[i]=arr[i+1];
                arr[i+1]=t;
            }
        }
        count1++;
    }

        /*to sort the remaining elements in the descending order*/
    int n2=n-n1;
    int count2=1;
    while(count2<=n2-1){
        for(int i=n1; i<n-count2; i++){
            if(arr[i]<arr[i+1]){
                int t=arr[i];
                arr[i]=arr[i+1];
                arr[i+1]=t;
            }
        }
        count2++;
    }

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
   special_bsort(arr,n);
    printf("the required array is:\n");
    print(arr,n);         //printing the array
    return 0;
}