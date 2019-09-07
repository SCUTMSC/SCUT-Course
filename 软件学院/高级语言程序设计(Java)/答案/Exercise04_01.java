import java.util.Scanner;

public class Exercise04_01 {
  public static void main(String[] args) {   
    Scanner input = new Scanner(System.in);

    System.out.print("Enter the length from the center to a vertex: ");
    double r = input.nextDouble();
    
    double side = 2 * r * Math.sin(Math.PI / 5);
    double area = 5 * side * side / Math.tan(Math.PI / 5) / 4;
    
    System.out.println("The area of the pentagon is " + 
        area);
  }
}