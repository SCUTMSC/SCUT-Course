import java.util.Comparator;

public class Exercise20_21 {
  /** The method for sorting the numbers */
  public static <E> void selectionSort(E[] list,
      Comparator<? super E> comparator) {
    boolean needNextPass = true;

    for (int k = 1; k < list.length && needNextPass; k++) {
      // Array may be sorted and next pass not needed
      needNextPass = false;
      for (int i = 0; i < list.length - k; i++) {
        if (comparator.compare(list[i], list[i + 1]) > 0) {
          // Swap list[i] with list[i + 1]
          E temp = list[i];
          list[i] = list[i + 1];
          list[i + 1] = temp;

          needNextPass = true; // Next pass still needed
        }
      }
    }
  }

  public static void main(String[] args) {
    GeometricObject[] list = {new Circle(5), new Rectangle(4, 5),
        new Circle(5.5), new Rectangle(2.4, 5), new Circle(0.5), 
        new Rectangle(4, 65), new Circle(4.5), new Rectangle(4.4, 1),
        new Circle(6.5), new Rectangle(4, 5)};

    Circle[] list1 = {new Circle(2), new Circle(3), new Circle(2),
      new Circle(5), new Circle(6), new Circle(1), new Circle(2),
      new Circle(3), new Circle(14), new Circle(12)};
    selectionSort(list1, new GeometricObjectComparator());
    for (int i = 0; i < list1.length; i++)
      System.out.println(list1[i].getArea() + " ");
  }
    
    
}
