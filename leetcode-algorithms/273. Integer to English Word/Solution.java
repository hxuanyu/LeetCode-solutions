
class Solution {
    public String numberToWords(int num) {
        if (num <= 20) return under20[num]; //0 - 20
        else if (num < 100) return tens[num / 10] + (num % 10 == 0 ? "" : " " + numberToWords(num % 10)); // 21 - 99
        else if (num < 1000) return numberToWords(num / 100) + " Hundred" + (num % 100 == 0 ? "" : " " + numberToWords(num % 100));
        else if (num < 1000000) return numberToWords(num / 1000) + " Thousand" + (num % 1000 == 0 ? "" : " " + numberToWords(num % 1000));
        else if (num < 1000000000) return numberToWords(num / 1000000) + " Million" + (num % 1000000 == 0 ? "" : " " + numberToWords(num % 1000000));
        else return numberToWords(num / 1000000000) + " Billion" + (num % 1000000000 == 0 ? "" : " " + numberToWords(num % 1000000000));
    }

    String[] under20 = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen",
            "Sixteen", "Seventeen", "Eighteen", "Nineteen", "Twenty"};
    String [] tens = {" ", " ", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
}
