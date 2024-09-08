#include <iostream>
#include <vector>
using namespace std;
//we will take the first number in the fibonacci sequence is 0 
int memoization_helper(int n, vector<int>& vec){
    if(n==1)
    return 0;
    if(n==2)
    return 1;
    if(vec[n]!=-1)
    return vec[n];
    vec[n]=memoization_helper(n-1,vec)+memoization_helper(n-2,vec);
    return vec[n];
}
//Top-Down (Memoization) Approach
int fibonacci_memoization(int n) {
    if(n<=0)
    {
        cout<<"Fibonacci number has to be greater than 0";
        return -1;
    }
    vector<int> vec(n+1,-1);
    return memoization_helper(n, vec);
}
//Bottom-Up Approach (Tabulation)
int fibonacci_tabulation_caching(int n) {
    if(n<=0){
        cout<<"Fibonacci number has to be greater than 0";
        return -1;
    }
    //check for heap-buffer-overflow when n < 2 
    if (n == 1) {
        return 0;  
    }
    if (n == 2) {
        return 1; 
    }
    vector<int> cache(n+1);
    cache[1]=0;
    cache[2]=1;
    for(int i=3;i<=n;i++){
        cache[i]=cache[i-1] + cache[i-2];
    }
    return cache[n];
    }
//Optimized Bottom-Up (Constant Space)
int fibonacci_tabulation_no_caching(int n) {
    if(n<=0){
        cout<<"Fibonacci number has to be greater than 0";
        return -1;
    }
    if(n==1)
    return 0;
    int pre=0;
    int next=1;
    for(int i=3;i<=n;i++){
        int temp=next;
        next=next+pre;   
        pre=temp;
    }
    return next;

}

int main() {
    int test_var;
    test_var=fibonacci_tabulation_no_caching(28);
    cout<<"fibonacci number: "<<test_var<<endl;
    
//0 1 1 2 3 5 8 13
    return 0;
}
