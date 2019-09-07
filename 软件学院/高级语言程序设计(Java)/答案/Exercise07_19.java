public class Exercise07_19 {
  public static void main(String[] args) {
    java.util.Scanner input = new java.util.Scanner(System.in);

    // Enter values for list1
    System.out.print("Enter a list: ");
    int size = input.nextInt();
    int[] list = new int[size];    
    for (int i = 0; i < list.length; i++) 
      list[i] = input.nextInt();

    if (isSorted(list))    
      System.out.println("The list is already sorted");
    else
      System.out.println("The list is not sorted");
  }

  public static boolean isSorted(int[] list) {
    for (int i = 0; i < list.length - 1; i++) {
      if (list[i] > list[i + 1]) {
        return false;
      }
    }

    return true;
  }
}
