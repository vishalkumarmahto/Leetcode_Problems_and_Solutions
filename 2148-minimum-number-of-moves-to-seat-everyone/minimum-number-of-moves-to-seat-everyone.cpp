class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        int n = seats.size();
        vector<int> position_seat(101, 0);
        vector<int> position_stud(101, 0);

        for (int& pos : seats) {
            position_seat[pos]++;
        }
        for (int& pos : students) {
            position_stud[pos]++;
        }
        int i = 0, j = 0;
        int moves = 0;
        while (i <= 100 && j <= 100) {
            if (position_seat[i] == 0)
                i++;
            if (position_stud[j] == 0)
                j++;
            if (i <= 100 && j <= 100 && position_seat[i] != 0 &&
                position_stud[j] != 0) {
                moves += abs(i - j);
                position_seat[i]--;
                position_stud[j]--;
            }
        }
        return moves;
    }
};