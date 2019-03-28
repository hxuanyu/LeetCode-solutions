class Solution {
    public boolean canPlaceFlowers(int[] flowerbed, int n) {

        int total = 0;
        for (int i = 0; i < flowerbed.length; i++) {
        	if (flowerbed[i] == 1) continue;

        	boolean leftok = (i - 1 >= 0) ? flowerbed[i - 1] == 0 : true;
        	boolean rigok = (i + 1 < flowerbed.length) ? flowerbed[i + 1] == 0 : true;

        	if (leftok && rigok) {
        		flowerbed[i] = 1;
        		total++;
        	}
        }

        return total >= n;
    }
}
