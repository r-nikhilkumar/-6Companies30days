// https://leetcode.com/problems/circle-and-rectangle-overlapping/submissions/1494097939/

class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        // Find the nearest point on the rectangle to the circle's center
        int x_nearest = max(x1, min(xCenter, x2));
        int y_nearest = max(y1, min(yCenter, y2));
        
        // Calculate the squared distance from the circle's center to the nearest point
        int dist_x = pow(xCenter - x_nearest, 2);
        int dist_y = pow(yCenter - y_nearest, 2);
        
        // Check if the squared radius is greater than or equal to the squared distance
        return pow(radius, 2) >= (dist_x + dist_y);
    }
};
