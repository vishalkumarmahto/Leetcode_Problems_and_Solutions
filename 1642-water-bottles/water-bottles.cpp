class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int consumer = 0;
        while (numBottles >= numExchange) {
            consumer += numExchange;
            numBottles -= numExchange;

            numBottles += 1;
        }
        return consumer + numBottles;
    }
};