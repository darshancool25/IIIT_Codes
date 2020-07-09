import java.util.Scanner;
class Account{
    static Scanner ip = new Scanner(System.in);
    int balance;
    String username,password;
    Account(){
        balance = 3000;
    }
    void get_info(){
        System.out.println("Enter Username:");
        username = ip.next();
        System.out.println("Enter Password:");
        password = ip.next();
    }
    void deposit(int d){
        balance = balance + d;
        System.out.println("Deposit successful..");
    }
    void withdraw(int w){
        balance = balance - w;
        System.out.println("Withdrawal successful..");
    }
    void show_balance(){
        System.out.println("Dear user : "+username + " Your current balance is : " + balance);
    }
}
class Bank extends Account{
    public static void main(String args[]){
        Account A = new Account();
        try{
            Account B = new Account();
            B.get_info();
            B.deposit(1000);
            B.withdraw(560);
            B.show_balance();
        }
        catch(Exception ex){}
        A.get_info();
        A.deposit(2000);
        A.withdraw(1534);
        A.show_balance();
    }
}