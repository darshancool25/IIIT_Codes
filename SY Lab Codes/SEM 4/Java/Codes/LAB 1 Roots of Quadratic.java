//Enter Command "java run" to run the program after compiling
import java.lang.Math;
class run {
	public static void main(String[] args) {
		int a = 1, b = -1, c = -6;
		System.out.println("Values of a,b,c for a quadratic equation : " + a + " " + b + " " +  c);
		double x1, x2;
		x1 = ((-1) * b + Math.sqrt((b * b) - (4 * a * c))) / (2 * a);
		x2 = ((-1) * b - Math.sqrt((b * b) - (4 * a * c))) / (2 * a);
		System.out.println("The roots of the quadratic equation are : " + x1 + " " + x2);
	}
}