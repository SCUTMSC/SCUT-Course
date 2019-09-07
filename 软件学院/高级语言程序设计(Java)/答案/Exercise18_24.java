import java.util.Scanner;

public class Exercise18_24 {
  public static void main(String[] args) {
    Scanner input = new Scanner(System.in);
    System.out.print("Enter a hex number: ");
    String hex = input.nextLine();
    System.out.println(hex + " is decimal " + hexToDecimal(hex));
  }  

  public static int hexToDecimal(String hexString) {
    return hexToDecimal(hexString, 0, hexString.length() - 1);
  }
  
  public static int hexToDecimal(String hexString, int low, int high) {
    if (high < low)
      return 0;
    else {
      return hexToDecimal(hexString, low, high - 1) * 16
        + hexCharToDecimal(hexString.charAt(high));
    }
  }
  
  public static int hexCharToDecimal(char ch) {
      if (ch >= 'A' && ch <= 'F')
        return 10 + ch - 'A';
      else 
        return ch - '0';
  }
}
