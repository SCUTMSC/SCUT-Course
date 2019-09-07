import java.util.Comparator;

public class Exercise24_06 {
  public static void main(String[] args) {
    new Exercise24_06();
  }

  public Exercise24_06() {
    MyPriorityQueue<GeometricObject> queue =
      new MyPriorityQueue<GeometricObject>(new GeometricObjectComparator());

    queue.enqueue(new Circle(3));
    queue.enqueue(new Circle(5));
    queue.enqueue(new Circle(1));

    System.out.println(queue.dequeue());
  }

  static class MyPriorityQueue<E> {
    HeapWithComparator<E> heap;
    private Comparator<? super E> comparator;

    /** Create a default heap */
    public MyPriorityQueue(Comparator<? super E>comparator) {
      this.comparator = comparator;
      heap = new HeapWithComparator<E>(comparator);
    }

    public void enqueue(E newObject) {
      heap.add(newObject);
    }

    public Object dequeue() {
      return heap.remove();
    }

    public int getSize() {
      return heap.getSize();
    }
  }
}
