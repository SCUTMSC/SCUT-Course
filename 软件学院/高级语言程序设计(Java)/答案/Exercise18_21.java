import java.util.Scanner;

public class Exercise18_21 {
  public static void main(String[] args) {
    Scanner input = new Scanner(System.in);
    System.out.print("Enter a decimal integer: ");
    int decimal = input.nextInt();
    System.out.println(decimal + " is binary " + decimalToBinary(decimal));
  }  

  public static String decimalToBinary(int value) {
    if (value == 0)
      return "";
    else
      return decimalToBinary(value / 2) + value % 2;   
  }
}
