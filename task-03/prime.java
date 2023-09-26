import java.util.Scanner;

public class Prime {

    public static boolean isPrime(int num) {
        if (num < 2) return false;
        if (num == 2 || num == 3) return true;
        if (num % 2 == 0 || num % 3 == 0) return false;

        int i = 5;
        while (i * i <= num) {
            if (num % i == 0 || num % (i + 2) == 0) return false;
            i += 6;
        }

        return true;
    }

    public static int getInput() {
        Scanner scanner = new Scanner(System.in);
        int k = 0;
        while (k < 2) {
            System.out.print("Type a number: ");
            k = scanner.nextInt();
        }
        scanner.close();
        return k;
    }

    public static void printPrimes(int n) {
        for (int i = 2; i <= n; i++) {
            if (isPrime(i)) System.out.println(i);
        }
    }

    public static void main(String[] args) {
        int k = getInput();
        printPrimes(k);
    }
}
