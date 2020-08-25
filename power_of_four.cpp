class Solution {
public:
    bool isPowerOfFour(int num) {
        int n = num;
        return ((n>0) && (((n) & (n-1)) == 0) && (n%3==1));
    }
};
