class Solution {
    public boolean detectCapitalUse(String word) {
        if (Character.isUpperCase(word.charAt(0))) return samec(word.substring(1), true) || samec(word.substring(1), false);
        else return samec(word, false);
    }

    boolean samec(String word, boolean up) {
    	if (up) {
    		for (char c : word.toCharArray()) {
    			if (Character.isLowerCase(c)) return false;
    		}
    	} else {
    		for (char c : word.toCharArray()) {
    			if (Character.isUpperCase(c)) return false;
    		}
    	}

    	return true;
    }
}
