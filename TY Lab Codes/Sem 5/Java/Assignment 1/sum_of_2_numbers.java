//Enter Command "java run" to run the program after compiling

import java.util.*;
import java.lang.*;
import java.io.*;

class sum {
	int a, b, c;
	void input() {
		a = 10;
		b = 40;
	}
	void calculate() {
		c = a + b;
	}
	void disp() {
		System.out.println("Sum : " + c);
	}
}

class run {
	public static void main(String[] args) {
		sum obj = new sum();
		obj.input();
		obj.calculate();
		obj.disp();
	}
}