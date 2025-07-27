class Solution {
public:
    // Brute Force
     double myPow(double x, int n) {
        long int times = n;
        if(n < 0){
            times = -1 * times;
        }
        double answer = 1;
        while(times > 0){
            if(times % 2 == 1){
                answer = answer * x;
                times--;
            }else{
                x = x * x;
                times /= 2;
            }
        }

        if(n < 0){
            answer = 1 / answer;
        }
        return answer;
    }
};