class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> max_left(height.size(), 0);
        int max_left_val = 0;
        // for each element starting from index 1,
        // the max height to its left is calculated
        for(int i = 1; i < height.size(); i++){
            max_left[i] = max(max_left_val, height[i - 1]);
            max_left_val = max(max_left_val, height[i - 1]);
        }

        vector<int> max_right(height.size(), 0);
        int max_right_val = 0;
        // for each elmt starting from nums.size() - 2
        // the max height to its right is calculated
        for(int i = height.size() - 2; i >= 0; i--){
            max_right[i] = max(max_right_val, height[i + 1]);
            max_right_val = max(max_right_val, height[i + 1]);
        }

        vector<int> min_height;
        // we now find the min of the max_right and max_left
        for(int i = 0; i < height.size(); i++){
            min_height.push_back(min(max_left[i], max_right[i]));
        }

        // now the water collected at i
        // is equal to min_height[i] - height[i]
        int water_collected = 0;
        for(int i = 0; i < height.size(); i++){
            if(min_height[i] - height[i] <= 0){
                water_collected += 0;
            }   else{
                water_collected += min_height[i] - height[i];
            }
        }

        return water_collected;
    }
};