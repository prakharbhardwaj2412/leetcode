class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int xOverlap=0, yOverlap=0;
        xOverlap = min(ax2, bx2) - max(ax1, bx1);
        yOverlap = min(ay2, by2) - max(ay1, by1);
        int areaOfOverlap=0;
        if(xOverlap>0 && yOverlap>0) areaOfOverlap = xOverlap*yOverlap;
        int area = (ay2-ay1)*(ax2-ax1) + (by2-by1)*(bx2-bx1) - areaOfOverlap;
        return area;
    }
};