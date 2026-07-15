class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int a = 1;
        int b = 2;
        int d = 2;
        int sumOdd = n*a + ((n*(n-1))/2)*d;
        int sumEven = n*b + ((n*(n-1))/2)*d;
        return __gcd(sumOdd,sumEven); 
    }
};