class Solution {
    public String addStrings(String num1, String num2) {
        int p1 = num1.length() - 1;
        int p2 = num2.length() - 1;

        StringBuilder sb = new StringBuilder();
        int sum = 0;
        int carrage = 0;
        while ((p1 >= 0) || (p2 >= 0)) {
        	sum = carrage;
        	if (p1 >= 0) {
        		sum += num1.charAt(p1) - '0';
        		p1--;
        	}
        	if (p2 >= 0) {
        		sum += num2.charAt(p2) - '0';
        		p2--;
        	}
        	sb.insert(0, Character.valueOf((char)(sum % 10 + '0')));
        	carrage = sum / 10;
        }

        if (carrage > 0) sb.insert(0, '1');

        return sb.toString();
    }
}
