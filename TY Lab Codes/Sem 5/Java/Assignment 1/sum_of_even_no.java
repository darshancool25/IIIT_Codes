//Enter Command "java run" to run the program after compiling
import java.util.*;
import java.lang.*;
import java.io.*;

class add {
	void func() {
		int i = 2, cnt = 10;
		int sum = 0, temp = cnt;
		while (temp-- > 0) {
			sum += i;
			i += 2;
		}
		System.out.println("Print pf first " + cnt + " even numbers : " + sum);
	}
}

class run {
	public static void main(String[] args) {
		add obj = new add();
		obj.func();
	}
}