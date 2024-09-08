#include <iostream>
using namespace std;


int main() { 
    int arr[]={5, 2, 9, 1, 5, 6};
    int size =sizeof(arr)/sizeof(arr[0]);
    
    for(int j=0;j<size-1;j++){     
        bool flag=true;   
        for(int i=0;i<size-j-1;i++){
            if(arr[i]>arr[i+1]){
                int temp=arr[i];
                arr[i]=arr[i+1];
                arr[i+1]=temp;
                flag=false;
            }
        }
            if(flag==true){
                break;//check if the list is sorted then no need for futher checking, because it the flag is true mean that the inner loop had no swap -> sorted
            }
    }
    for(int i=0;i<size;i++){
        cout<<arr[i];
    }
    

return 0;
}