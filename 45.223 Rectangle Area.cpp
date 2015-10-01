/*
Find the total area covered by two rectilinear rectangles in a 2D plane.

Each rectangle is defined by its bottom left corner and top right corner as shown in the figure.

Rectangle Area
Assume that the total area is never beyond the maximum possible value of int.
*/

class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {

        long long sum = (C-A)*(D-B);
        sum += (G-E)*(H-F);
        
        if(E >= C || A >= G || B >= H || F >= D)
            return sum;
        else
            return sum - (min(G,C)-max(A,E))*(min(D,H)-max(B,F));
            
    }
};

/*
  这题没做出来，需要求出矩形的交集。
*/
