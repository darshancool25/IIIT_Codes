//Enter Command "java run arg1 arg2...." to run the program after compiling
import java.util.*;
import java.lang.*;
import java.io.*;


class run {
	public static void main(String[] args) {
		int [] arr = new int[args.length];
		for (int i = 0; i < args.length; i++) {
			arr[i] = Integer.parseInt(args[i]);
		}
		int minn = arr[0];
		for (int i = 0; i < args.length; i++) {
			if (arr[i] < minn)minn = arr[i];
		}
		System.out.println("The Minimum of all numbers entered is : " + minn);
	}
}