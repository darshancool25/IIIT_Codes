//Enter Command "java run" to run the program after compiling

import java.util.*;
import java.lang.*;
import java.io.*;

class maximum {
	int a, b, c;
	void input() {
		a = 10;
		b = 30;
	}
	void disp() {
		System.out.println("Maximum of " + a + "," + b + " is : " + c);
	}
	void calc() {
		c = Math.max(a, b);
	}
}

class run {
	public static void main(String[] args) {
		maximum obj = new maximum();
		obj.input();
		obj.calc();
		obj.disp();
	}
}