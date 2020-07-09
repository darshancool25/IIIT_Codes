//Enter Command "java run" to run the program after compiling
import java.util.*;
import java.lang.*;
import java.io.*;

class leap {
	int yr;
	void input() {
		yr = 2016;
	}
	void check() {
		boolean ok = false;
		if ((yr % 400 == 0) || (yr % 4 == 0 && yr % 100 != 0))ok = true;
		if (ok)System.out.println(yr + " is a Leap Year");
		else System.out.println(yr + " is not a leap year");
	}
}

class run {
	public static void main(String[] args) {
		leap obj = new leap();
		obj.input();
		obj.check();
	}
}