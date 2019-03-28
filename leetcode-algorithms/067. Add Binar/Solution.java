class Solution {
    public String addBinary(String a, String b) {
        int posa = a.length() - 1;
        int posb = b.length() - 1;

        StringBuilder sb = new StringBuilder();
        int carrage = 0;
        int sum = 0;
        while ((posa >= 0) || (posb >= 0)) {
        	sum = 0;
        	sum += carrage;
        	if (posa >= 0) {
        		sum += a.charAt(posa) - '0';
        		posa--;
        	}
        	if (posb >= 0) {
        		sum += b.charAt(posb) - '0';
        		posb--;
        	}

        	sb.append((char)(sum % 2 + '0'));
        	carrage = sum / 2;
        }

        if (carrage == 1) sb.append('1');
        return sb.reverse().toString();
    }
}
