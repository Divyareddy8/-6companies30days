class Solution {
    vector<vector<int>> rects;   // Store the given rectangles
    vector<int> weights;         // Store cumulative weights for each rectangle

public:
    // Constructor
    Solution(vector<vector<int>>& rects) : rects(rects) {
        int totalPoints = 0;
        for (const auto& rect : rects) {
            int a = rect[0], b = rect[1], x = rect[2], y = rect[3];
            int points = (x - a + 1) * (y - b + 1);  // Total integer points in the rectangle
            totalPoints += points;
            weights.push_back(totalPoints);  // Maintain cumulative weights
        }
    }
    
    // Pick a random integer point
    vector<int> pick() {
        // Step 1: Select a rectangle based on cumulative weights
        int target = rand() % weights.back();  // Random number in [0, totalPoints-1]
        int rectIndex = upper_bound(weights.begin(), weights.end(), target) - weights.begin();
        
        // Step 2: Randomly pick a point inside the selected rectangle
        const auto& rect = rects[rectIndex];
        int a = rect[0], b = rect[1], x = rect[2], y = rect[3];
        int u = a + rand() % (x - a + 1);  // Random x-coordinate
        int v = b + rand() % (y - b + 1);  // Random y-coordinate
        
        return {u, v};
    }
};
