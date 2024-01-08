//PROBLEM STATEMENT
/*
You are given a circle represented as (radius, xCenter, yCenter) and an axis-aligned rectangle represented as (x1, y1, x2, y2), where (x1, y1) are the coordinates of the bottom-left corner, and (x2, y2) are the coordinates of the top-right corner of the rectangle.

Return true if the circle and rectangle are overlapped otherwise return false. In other words, check if there is any point (xi, yi) that belongs to the circle and the rectangle at the same time.
*/
//CODE
//APPROACH => We Find Nearest X And Nearest Y Then Simply Calculate Distance X And Distance Y Between Circle And Rectangle Using Pythageorus Theorem then check if this distance <= radius then we return true
//otherwise return false
/*
T.C = O(1)
S.C = O(1)
*/
class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        int nearest_x = max(x1,min(x2,xCenter));
        int nearest_y = max(y1,min(y2,yCenter));

        int dist_x = nearest_x-xCenter;
        int dist_y = nearest_y-yCenter;
        return dist_x*dist_x + dist_y*dist_y <= radius*radius;
    }
};
