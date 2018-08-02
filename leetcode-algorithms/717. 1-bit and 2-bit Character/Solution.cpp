// We have two special characters. The first character can be represented by one bit 0. The second character can be represented by two bits (10 or 11).
//
// Now given a string represented by several bits. Return whether the last character must be a one-bit character or not. The given string will always end with a zero.
//
// Example 1:
// Input:
// bits = [1, 0, 0]
// Output: True
// Explanation:
// The only way to decode it is two-bit character and one-bit character. So the last character is one-bit character.
// Example 2:
// Input:
// bits = [1, 1, 1, 0]
// Output: False
// Explanation:
// The only way to decode it is two-bit character and two-bit character. So the last character is NOT one-bit character.
class Solution { // Can be further optimized
public:
    bool isOneBitCharacter(vector<int>& bits) {
        if (bits.size() == 1) return bits[0] == 0;
        else if (bits.size() == 2) return bits[0] != 1;

        for (int i = 0; i < bits.size(); ) {
            if (bits[i] == 0) i++;
            else {
                i += 2;
            }

            if (i == bits.size() - 1) {
                return bits[i] == 0;
            } else if (i == bits.size() - 2) {
                return bits[i] != 1;
            }
        }

        return false;
    }
};
