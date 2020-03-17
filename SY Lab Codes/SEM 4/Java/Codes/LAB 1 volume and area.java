//Enter Command "java run" to run the program after compiling
class run {
	static int a = 5, b = 7, c = 8;
	public static void main(String[] args) {
		System.out.println("Sides of cuboid are : " + a + " " + b + " " + c);
		System.out.println("Volume of cuboid is : " + (a * b * c));
		System.out.println("Surface area of cuboid is : " + (2 * (a * b + b * c + c * a)));
	}
}