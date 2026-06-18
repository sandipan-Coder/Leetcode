class Solution {
public:
    double angleClock(int hour, int minutes) {
        
        double Angle_Min = (6 * minutes);
        double Angle_Hur = (30 * hour) + (0.5 * minutes);

        double first = abs(Angle_Hur - Angle_Min);
        double second = 360 - first;

        return (first < second) ? first : second;
    }
};