import java.util.Scanner;

public class Test {
  public static void main(String[] args) {
    
    System.out.printf("amount is %5.2f%% %5.4e\n", 32.328, 32.32);
    
    double t = 56_454.65;
    
    Scanner input = new Scanner(System.in);
    System.out.print("Enter the current year tuition: ");
    double tuition = input.nextDouble();
    
    int year = 0;
    double newTuition = tuition;
    while (newTuition < 2 * tuition) {
      newTuition = newTuition * 1.07;
      year++;
    }
  
    System.out.println("Tuition will be doubled in " 
      + year + " years");
    System.out.printf("Tuition will be $%.2f in %1d years",  
      tuition, year);
  }
}
