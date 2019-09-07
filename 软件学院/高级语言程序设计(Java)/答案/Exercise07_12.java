import java.util.Scanner;

public class Exercise07_12 {
  public static void main(String[] args) {
    Scanner input = new Scanner(System.in);

    System.out.print("Enter 10 integers: ");
    int[] myList = new int[10];
    for (int i = 0; i < myList.length; i++)
      myList[i] = input.nextInt();

    reverse(myList);

    for (int i = 0; i < myList.length; i++)
      System.out.print(myList[i] + " ");
  }

  public static int[] reverse(int[] list) {
    for (int i = 0, j = list.length - 1; i < list.length / 2; i++, j--) {
      int temp = list[i];
      list[i] = list[j];
      list[j] = temp;
    }

    return list;
  }
}
