
class Circle { 
	static double pi; 
	double area;
	static { 
		pi = 3.14159265359; 
	} 
	void Area(double r){
		System.out.println("Area of Circle is : " (pi*r*r));	
	}	
} 

class run { 
	public static void main(String args[]) { 
		System.out.println(Circle.area(4.33)); 
		System.out.println(Circle.area(5.66)); 
	} 
} 
