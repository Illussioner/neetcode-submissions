class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        
        int left = 0;
        int right = people.size() - 1;
        int boats = 0;

        while (left <= right) {
            // If the lightest and heaviest can share a boat
            if (people[left] + people[right] <= limit) {
                left++; // Lightest person gets on
            }
            
            // The heaviest person ALWAYS gets on a boat
            // (either with the lightest or by themselves)
            right--;
            boats++;
        }
        
        return boats;
    }
};