import java.util.Scanner;

public class Exercise18_23 {
  public static void main(String[] args) {
    Scanner input = new Scanner(System.in);
    System.out.print("Enter a binary number: ");
    String binary = input.nextLine();
    System.out.println(binary + " is decimal " + binaryToDecimal(binary));
  }  

  public static int binaryToDecimal(String binaryString) {
    return binaryToDecimal(binaryString, 0, binaryString.length() - 1);
  }
  
  public static int binaryToDecimal(String binaryString, int low, int high) {
    if (high < low)
      return 0;
    else 
      return binaryToDecimal(binaryString, low, high - 1) * 2
        + (binaryString.charAt(high) - '0');
  }
}
