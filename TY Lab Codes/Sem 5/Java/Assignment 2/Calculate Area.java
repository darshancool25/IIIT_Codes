//Enter Command "java run" to run the program after compiling
import java.util.*;
import java.lang.*;
import java.io.*;

class Area {
	double area;
	void calc_area(int r) {
		area = Math.PI * r * r;
	}
	void calc_area(int l, int b) {
		area = l * b;
	}
	void calc_area(int a, int b, int c) {
		double s = 0;
		s = (a + b + c) / 2.0;
		area = Math.sqrt(s * (s - a) * (s - b) * (s - c));
	}
	double disp() {
		return area;
	}
}

class run {
	public static void main(String[] args) {
		Area obj = new Area();
		obj.calc_area(5);
		System.out.println("Area of Circle with radius 5 is : " + obj.disp());
		obj.calc_area(5, 7);
		System.out.println("Area of Rectangle with sides 5,7 is : " + obj.disp());
		obj.calc_area(5, 12, 13);
		System.out.println("Area of Triangle with sides 5,12,13 is : " + obj.disp());
	}
}