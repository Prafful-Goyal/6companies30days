//PROBLEM STATEMENT
/*
There is a grid with n + 2 horizontal bars and m + 2 vertical bars, and initially containing 1 x 1 unit cells.
The bars are 1-indexed.
You are given the two integers, n and m.
You are also given two integer arrays: hBars and vBars.
hBars contains distinct horizontal bars in the range [2, n + 1].
vBars contains distinct vertical bars in the range [2, m + 1].
You are allowed to remove bars that satisfy any of the following conditions:
If it is a horizontal bar, it must correspond to a value in hBars.
If it is a vertical bar, it must correspond to a value in vBars.
Return an integer denoting the maximum area of a square-shaped hole in the grid after removing some bars (possibly none).
*/
//CODE
class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
    sort(hBars.begin(), hBars.end());
    sort(vBars.begin(), vBars.end());

    // Find the horizontal and vertical gap sizes
    vector<int> hGaps, vGaps;
    for (int i = 1; i < hBars.size(); ++i) {
        hGaps.push_back(hBars[i] - hBars[i - 1] - 1);
    }
    for (int i = 1; i < vBars.size(); ++i) {
        vGaps.push_back(vBars[i] - vBars[i - 1] - 1);
    }

    // Sort the gap sizes in descending order
    sort(hGaps.rbegin(), hGaps.rend());
    sort(vGaps.rbegin(), vGaps.rend());

    // Find the minimum gap size
    int minHorizontalGap = !hGaps.empty() ? hGaps.front() : n;
    int minVerticalGap = !vGaps.empty() ? vGaps.front() : m;

    // Calculate the maximum square-shaped hole
    long long maxHole = min(minHorizontalGap, minVerticalGap);
    maxHole *= maxHole;

    return maxHole;
    }
};
