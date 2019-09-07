public class Exercise07_17 {
  public static void main(String[] args) {
    java.util.Scanner input = new java.util.Scanner(System.in);

    // Prompt the user to enter the number of students
    System.out.print("Enter the number of students: ");
    int numberOfStudents = input.nextInt();

    String[] names = new String[numberOfStudents];
    double[] scores = new double[numberOfStudents];

    // Enter student name and score
    for (int i = 0; i < scores.length; i++) {
      System.out.print("Enter a student name: ");
      names[i] = input.next();
      System.out.print("Enter a student score: ");
      scores[i] = input.nextDouble();
    }

    // Sort
    for (int i = 0; i < numberOfStudents - 1; i++) {
      // Find the minimum in the scores[i..numberOfStudents-1]
      double currentMin = scores[i];
      int currentMinIndex = i;

      for (int j = i + 1; j < numberOfStudents; j++) {
        if (currentMin > scores[j]) {
          currentMin = scores[j];
          currentMinIndex = j;
        }
      }

      // Swap scores[i] with scores[currentMinIndex] if necessary;
      // Swap names[i] with names[currentMinIndex] if necessary;
      if (currentMinIndex != i) {
        scores[currentMinIndex] = scores[i];
        scores[i] = currentMin;
        String temp = names[currentMinIndex];
        names[currentMinIndex] = names[i];
        names[i] = temp;
      }
    }

    // Print names and scores
    for (int i = scores.length - 1; i >= 0; i--) {
      System.out.println(names[i] + "\t" + scores[i]);
    }
  }
}
