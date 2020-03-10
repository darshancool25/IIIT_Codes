import java.io.*; 
import java.util.*;

class age{
	String name;
	float son,father;
	static int cons = 64;
	public age(String name, int father) 
    { 
        this.name = name; 
        this.father = father;
        this.son = cons - this.father;
    }  
}
class run {
	public static void main(String[] args) {
		ArrayList<age> arr = new ArrayList<age>(5);
		arr.add(new age("lokhande",50));
		arr.add(new age("kumar",40));
		arr.add(new age("kaur",30));
		arr.add(new age("advani",25));
		arr.add(new age("mule",32));
		System.out.println("Age of sons and ratios are as follows : ");
		for(int i=0;i<5;i++){
			System.out.println(arr.get(i).name + " : " + (arr.get(i).son + 8));
			System.out.println("Ratio : " + (float)((arr.get(i).father + 8) / (arr.get(i).son + 8)));
		}
	}
}