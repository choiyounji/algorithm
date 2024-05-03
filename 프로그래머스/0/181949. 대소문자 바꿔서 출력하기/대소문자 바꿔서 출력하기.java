import java.util.Scanner;

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String a = sc.next();
        for(int i=0;i<a.length();i++){
            char b=a.charAt(i);
            if(Character.isUpperCase(b)){
                System.out.print(Character.toLowerCase(b));
            } else{
                System.out.print(Character.toUpperCase(b));
            }
        }
    }
}