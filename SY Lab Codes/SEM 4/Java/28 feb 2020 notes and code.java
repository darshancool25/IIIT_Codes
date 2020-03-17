class run
{
	int a;
	run add() //Similar to factory method
	{
		this.a = 90;
		System.out.println("Ae Rajuuuuuu");
		return this;
	}
	static void addd()  //static method
	{
		System.out.println("Raj");
		//return this;    research on this , why we cant return non statc object from a static method ["this" is non static object]
	}
	run(int aa) //parameterized constructor
	{
		a = aa;
	}
	run() // constructor
	{
		a = 90;
	}
	public static void main(String args[])
	{
		System.out.println(new run(69).a);  //calling parameterized constructor
		addd();
	}
}

//Advantage of instance method : 
// 1. Direct use of instance variable.
// 2. You can return variable as well as object from method. 
// [Factory method]  - A static method which can retrun object.
// [Instance Method]      
			// -  it is serialized method, cannot be parallelized
// Method of Chain
//When we use factory method inside a class, the class is called a singleton class.

//Constructor is used to initialize the object , 

