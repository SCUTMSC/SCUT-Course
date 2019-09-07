import java.util.Scanner;

public class Exercise18_09 {
  public static void main(String[] args) {
    Scanner input = new Scanner(System.in);
    System.out.print("Enter a string: ");
    String i = input.nextLine();
    reverseDisplay(i);
  }

  public static void reverseDisplay(String value) {
    if (value.length() > 0) {
      System.out.print(value.charAt(value.length() - 1));
      reverseDisplay(value.substring(0, value.length() - 1));
    }
  }
}
