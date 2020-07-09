//Enter Command "java run" to run the program after compiling
class test {
	int a, b;
	void input() {
		a = 10;
		b = 69;
	}
	void display() {
		System.out.println("The values are : " + a + " " + b);
	}
}
class run {
	public static void main(String[] args) {
		test obj = new test();
		obj.input();
		obj.display();
	}
}