import java.math.*;
import java.util.*;
import java.io.*;

public class Main{
	public static void main(String args[]){
		Scanner in = new Scanner(System.in);
		PrintWriter pw = new PrintWriter(System.out);

		int n = in.nextInt();
		BigInteger a = new BigInteger("1");
		for(int i = 0; i < n; ++i){
			String x;
			x = in.next();
			a = a.multiply(new BigInteger(x));
		}
		int m = in.nextInt();
		BigInteger b = new BigInteger("1");
		for(int i = 0; i < m; ++i){
			String x;
			x = in.next();
			b = b.multiply(new BigInteger(x));
		}

		String res = a.gcd(b).toString();

		if(res.length() <= 9){
			pw.println(res);
		}
		else{
			for(int i = res .length() - 9; i < res.length(); ++i){
				pw.print(res.charAt(i));
			}
			pw.println();
		}
		pw.close();
	}
}