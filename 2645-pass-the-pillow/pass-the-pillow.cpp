class Solution {
public:
    int passThePillow(int n, int time) {
        int fullRounds = time/(n-1);

        int timeLeft = time % (n-1);
        if(fullRounds % 2==0){
            // you must be standing at first position
            return timeLeft + 1;
        }
        else{
           return n - timeLeft;
        }
        return -1;
    }
};