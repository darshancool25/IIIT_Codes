import java.util.ArrayList;
import java.util.Scanner;
class ShopCartList{
    static Scanner ip = new Scanner(System.in);
    int code;
    String name;
    int price;
    int quantity;
    ShopCartList(int c, String n, int p, int q){
        code = c;
        name = n;
        price = p;
        quantity = q;
    }
    void ShowDetails(){
        System.out.println(code);
        System.out.println(name);
        System.out.println(price);
        System.out.println(quantity);
    }
    public static void main(String args[]){
        ArrayList<ShopCartList> obj = new ArrayList<ShopCartList>();
        ArrayList<Integer> selected = new ArrayList<Integer>(); 

        ShopCartList obj1 = new ShopCartList(1,"floor mat",75,2);
        obj.add(obj1);
        ShopCartList obj2 = new ShopCartList(2,"calculator",100,1);
        obj.add(obj2);
        ShopCartList obj3 = new ShopCartList(3,"Nasal Drops",50,2);
        obj.add(obj3);
        ShopCartList obj4 = new ShopCartList(4,"Adhesive",35,2);
        obj.add(obj4);
        ShopCartList obj5 = new ShopCartList(5,"Blue ball point pen",10,5);
        obj.add(obj5);
        ShopCartList obj6 = new ShopCartList(6,"pencil",5,10);
        obj.add(obj6);
        ShopCartList obj7 = new ShopCartList(7,"gift wrap",5,6);
        obj.add(obj7);
        ShopCartList obj8 = new ShopCartList(8,"school bag",105,1);
        obj.add(obj8);
        int Total = 0;
        
        selected.add(1);
        selected.add(2);
        selected.add(4);
        selected.add(1);
        selected.add(3);
        selected.add(6);
        selected.add(7);
        selected.add(3);
        selected.add(1);
        selected.add(2);
        selected.add(3);
        selected.add(3);
        selected.add(5);
        selected.add(5);
        System.out.println("-----------------------------------------------------");
        for(int var : selected){
            for(ShopCartList v : obj){
                if(var == v.code && v.quantity > 0){
                    System.out.println(v.name + "--" + v.quantity+ "--" + v.price);
                    Total = Total + v.price;
                    v.quantity = v.quantity - 1;

                }
            }
        }
        System.out.println("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
        System.out.println("Total bill is :: " + Total + " Please come again!!");
    }
}