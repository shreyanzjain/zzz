#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int lo = 0;
        int hi = 0;
        int totalArea = 0;

        while(hi < height.size() - 1) {
            // keep ascending till peak from left
            while(((lo + 1) < height.size()) && 
            (height[lo + 1] >= height[lo])) {
                lo++;
                hi++;
            }

            // keep descending till bottom
            while(((hi + 1) < height.size()) &&
            (height[hi + 1] <= height[hi])) {
                hi++;
            }

            int bottom = hi;

            // keep ascending till new peak on right
            while(((hi + 1) < height.size()) &&
            (height[hi + 1] >= height[hi])) {
                hi++;
            }

            // now we are on good locations
            int width = hi - lo - 1;
            int minHeight = min(height[hi], height[lo]);
            int area = minHeight * width;

            lo++; // move the left pointer ahead 1 step
            while((lo < height.size()) && (lo < hi)) {
                area = area - height[lo];
                lo++;
            }

            if(area < 0) {
                area = 0;
            }

            totalArea += area;
        }

        return totalArea;
    }
};

int main() {
    vector<int> height = {4,2,0,3,2,5};
    Solution solution;
    int result = solution.trap(height);
    
    cout << "Trapped Water: " << result << endl;
    
    return 0;
}
