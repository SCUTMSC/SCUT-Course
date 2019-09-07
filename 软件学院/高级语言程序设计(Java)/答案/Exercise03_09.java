import java.util.Scanner;

public class Exercise03_09 {
  public static void main(String[] args) {
    Scanner input = new Scanner(System.in);

    // Prompt the user to enter an integer
    System.out.print(
      "Enter the first 9 digits of an ISBN as integer: ");
    int number = input.nextInt();

    // Calculate checksum (You may write a loop to simplify it in Ch4
    int checksum = 
      ((number / 100000000 % 10) * 1 +
      (number / 10000000 % 10) * 2 +
      (number / 1000000 % 10) * 3 +
      (number / 100000 % 10) * 4 +
      (number / 10000 % 10) * 5 +
      (number / 1000 % 10) * 6 +
      (number / 100 % 10) * 7 +
      (number / 10 % 10) * 8 +
      (number % 10) * 9) % 11;
      
    System.out.print("The ISBN-10 number is ");

    // Display leading zeros, improve the solution using loops in the next chapter
    if (number / 100000000 == 0) {
      System.out.print("0");
      if (number / 10000000 == 0) {
        System.out.print("0");
        if (number / 1000000 == 0) {
          System.out.print("0");
          if (number / 100000 == 0) {
            System.out.print("0");
            if (number / 10000 == 0) {
              System.out.print("0");
              if (number / 1000 == 0) {
                System.out.print("0");
                if (number / 100 == 0) {
                  System.out.print("0");
                  if (number / 10 == 0) {
                    System.out.print("0");
                    if (number == 0) {
                      System.out.print("0");
                    }
                  }
                }
              }
            }
          }
        }
      }
    }

    System.out.print(number);

    if (checksum == 10)
      System.out.print("X");
    else
      System.out.print(checksum);
  }
}
