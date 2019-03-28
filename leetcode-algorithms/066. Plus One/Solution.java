class Solution {
    public int[] plusOne(int[] digits) {
        int pos = digits.length - 1;

        int carrage = 1;
        int sum = 0;
        for (; pos >= 0; pos--) {
        	sum = 0;
        	sum += carrage;
        	sum += digits[pos];

        	carrage = sum / 10;
        	digits[pos] = sum % 10;
        }

        if (carrage == 0) return digits;
        else {
        	int[] newarray = new int[digits.length + 1];
        	newarray[0] = 1;
        	System.arraycopy(digits, 0, newarray, 1, digits.length);

        	return newarray;

        }
    }
}
