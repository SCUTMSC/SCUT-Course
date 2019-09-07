import java.util.Scanner;

public class Exercise18_22 {
  public static void main(String[] args) {
    Scanner input = new Scanner(System.in);
    System.out.print("Enter a decimal integer: ");
    int decimal = input.nextInt();
    System.out.println(decimal + " is hex " + decimalToHex(decimal));
  }  

  public static String decimalToHex(int value) {
    if (value == 0)
      return "";
    else {
      return decimalToHex(value / 16) + decimalToHexChar(value % 16);   
    }
  }
  
  public static char decimalToHexChar(int value) {
    if (value >= 10 && value <=15)
      return (char)('A' + value - 10);
    else 
      return (char)('0' + value);
  }
}
