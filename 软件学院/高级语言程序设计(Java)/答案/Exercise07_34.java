public class Exercise07_34 {
  public static void main(String args[]) {
    // Prompt the user to enter a string
    java.util.Scanner input = new java.util.Scanner(System.in);
    System.out.print("Enter a string: ");
    String s = input.nextLine();
    System.out.println("Sorted string is " + sort(s));
  }

  public static String sort(String s) {
    StringBuilder buffer = new StringBuilder(s);

    char currentMax;
    int currentMaxIndex;

    for (int i = buffer.length() - 1; i >= 1; i--) {
      // Find the maximum in the buffer[0..i]
      currentMax = buffer.charAt(i);
      currentMaxIndex = i;

      for (int j = 1; j <= i; j++) {
        if (currentMax < buffer.charAt(j)) {
          currentMax = buffer.charAt(j);
          currentMaxIndex = j;
        }
      }

      // Swap buffer.charAt(i) with buffer[currentMaxIndex] if necessary;
      if (currentMaxIndex != i) {
        buffer.setCharAt(currentMaxIndex, buffer.charAt(i));
        buffer.setCharAt(i, currentMax);
      }
    }

    return buffer.toString();
  }
}
