import java.util.Scanner;


public class Split {
	public static void main(String[] args) {
		String s = new Scanner(System.in).nextLine();
		for(String e : s.split(" "))
			System.out.println(Integer.parseInt(e));
	}
}
