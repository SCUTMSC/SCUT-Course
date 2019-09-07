import java.util.Comparator;

public class Exercise23_05 {
  public static void main(String[] args) {
    Integer[] list = {2, 3, 2, 5, 6, 1, -2, 3, 14, 12};
    heapSort(list);
    for (int i = 0; i < list.length; i++) {
      System.out.print(list[i] + " ");
    }

    System.out.println();
    Circle[] list1 = {new Circle(2), new Circle(3), new Circle(2),
      new Circle(5), new Circle(6), new Circle(1), new Circle(2),
      new Circle(3), new Circle(14), new Circle(12)};
    heapSort(list1, new GeometricObjectComparator());
    for (int i = 0; i < list1.length; i++) {
      System.out.print(list1[i] + " ");
    }
  }

  public static<E extends Comparable<E>>void heapSort(E[] list) {
    Heap<E> heap = new Heap<E>(); // Create a Heap

    // Add elements to the heap
    for (int i = 0; i < list.length; i++) {
      heap.add(list[i]);
    }

    // Remove elements from the heap
    for (int i = list.length - 1; i >= 0; i--) {
      list[i] = heap.remove();
    }
  }

  public static<E>void heapSort(E[] list,
    Comparator<? super E>comparator) {
    // Create a Heap
    HeapWithComparator<E> heap = new HeapWithComparator<E>(comparator);

    // Add elements to the heap
    for (int i = 0; i < list.length; i++) {
      heap.add(list[i]);
    }

    // Remove elements from the heap
    for (int i = list.length - 1; i >= 0; i--) {
      list[i] = heap.remove();
    }
  }

  static class Heap<E extends Comparable<E>> {
    private java.util.ArrayList<E> list = new java.util.ArrayList<E>();

    /** Create a default heap */
    public Heap() {
    }

    /** Create a heap from an array of objects */
    public Heap(E[] objects) {
      for (int i = 0; i < objects.length; i++) {
        add(objects[i]);
      }
    }

    /** Add a new object into the heap */
    public void add(E newObject) {
      list.add(newObject); // Append to the heap
      int currentIndex = list.size() - 1; // The index of the last node

      while (currentIndex > 0) {
        int parentIndex = (currentIndex - 1) / 2;
        // Swap if the current object is greater than its parent
        if (list.get(currentIndex).compareTo(
          list.get(parentIndex)) > 0) {
          E temp = list.get(currentIndex);
          list.set(currentIndex, list.get(parentIndex));
          list.set(parentIndex, temp);
        }
        else {
          break; // the tree is a heap now
        }

        currentIndex = parentIndex;
      }
    }

    /** Remove the root from the heap */
    public E remove() {
      if (list.size() == 0) {
        return null;
      }

      E removedObject = list.get(0);
      list.set(0, list.get(list.size() - 1));
      list.remove(list.size() - 1);

      int currentIndex = 0;
      while (currentIndex < list.size()) {
        int leftChildIndex = 2 * currentIndex + 1;
        int rightChildIndex = 2 * currentIndex + 2;

        // Find the maximum between two children
        if (leftChildIndex >= list.size()) {
          break; // The tree is a heap
        }
        int maxIndex = leftChildIndex;
        if (rightChildIndex < list.size()) {
          if (((Comparable)(list.get(maxIndex))).compareTo(
            list.get(rightChildIndex)) < 0) {
            maxIndex = rightChildIndex;
          }
        }

        // Swap if the current node is less than the maximum
        if (((Comparable)(list.get(currentIndex))).compareTo(
          list.get(maxIndex)) < 0) {
          E temp = list.get(maxIndex);
          list.set(maxIndex, list.get(currentIndex));
          list.set(currentIndex, temp);
          currentIndex = maxIndex;
        }
        else {
          break; // The tree is a heap
        }
      }

      return removedObject;
    }

    /** Get the number of nodes in the tree */
    public int getSize() {
      return list.size();
    }
  }

}
