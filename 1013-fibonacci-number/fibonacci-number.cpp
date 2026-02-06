class Solution {
public:
    // using recursion
    int fib(int n) {
        if(n==0) return 0 ;
        if(n==1) return 1 ;

        return fib(n-1) + fib(n-2)  ;
        
    }
};
/*
 TC---> O(2ⁿ) (exponential) Each fib(n) calls fib(n-1) and fib(n-2)
The recursion tree roughly doubles at each level
 SC-->O(n)  recursion stack space 
 */