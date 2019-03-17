import java.util.Scanner;
import java.math.BigInteger;
public class Hw1 {
		public static void main(String[] argv) {

				int n=Integer.parseInt(argv[0]);
				if (n < 1 || n > 99)
						return;
				fib(n);
		}

		public static void fib(int n) {
				BigInteger a = new BigInteger("1") ;
				BigInteger b = new BigInteger("1") ;
				BigInteger tmp = new BigInteger("0") ;
				if (n == 2 || n == 1)
						System.out.println("1");
				for (int i = 3; i <= n; i++) {
						tmp = b;
						b=b.add(a);
						a = tmp;
				}
				System.out.println(b);
		}
}
