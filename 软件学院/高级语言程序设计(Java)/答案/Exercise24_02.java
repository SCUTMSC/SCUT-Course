import java.util.*;
import java.util.ArrayList;

public class Exercise24_02 {
  public static void main(String[] args) {
    new Exercise24_02();
  }

  public Exercise24_02() {
    String[] name = {"Tom", "George", "Peter", "Jean", "George", "Jane"};
    MyList<String> list = new MyLinkedList<String>(name);   

    System.out.println(list.contains("George"));
    System.out.println(list.get(3));
    System.out.println(list.indexOf("George"));
    System.out.println(list.lastIndexOf("George"));
    list.set(4, "Michael");
    System.out.println(list);
  }

  public interface MyList<E> extends java.lang.Iterable {
    /** Add a new element at the end of this list */
    public void add(E e);

    /** Add a new element at the specified index in this list */
    public void add(int index, E e);

    /** Clear the list */
    public void clear();

    /** Return true if this list contains the element */
    public boolean contains(E e);

    /** Return the element from this list at the specified index */
    public E get(int index);

    /** Return the index of the first matching element in this list.
     *  Return -1 if no match. */
    public int indexOf(E e);

    /** Return true if this list contains no elements */
    public boolean isEmpty();

    /** Return the index of the last matching element in this list
     *  Return -1 if no match. */
    public int lastIndexOf(E e);

    /** Remove the first occurrence of the element o from this list.
     *  Shift any subsequent elements to the left.
     *  Return true if the element is removed. */
    public boolean remove(E e);

    /** Remove the element at the specified position in this list
     *  Shift any subsequent elements to the left.
     *  Return the element that was removed from the list. */
    public E remove(int index);

    /** Replace the element at the specified position in this list
     *  with the specified element and return the old element. */
    public Object set(int index, E e);

    /** Return the number of elements in this list */
    public int size();
  }

  public abstract class MyAbstractList<E> implements MyList<E> {
    protected int size = 0; // The size of the list

    /** Create a default list */
    protected MyAbstractList() {
    }

    /** Create a list from an array of objects */
    protected MyAbstractList(E[] objects) {
      for (int i = 0; i < objects.length; i++)
        add(objects[i]);
    }

    /** Add a new element at the end of this list */
    public void add(E e) {
      add(size, e);
    }

    /** Return true if this list contains no elements */
    public boolean isEmpty() {
      return size == 0;
    }

    /** Return the number of elements in this list */
    public int size() {
      return size;
    }

    /** Remove the first occurrence of the element o from this list.
     *  Shift any subsequent elements to the left.
     *  Return true if the element is removed. */
    public boolean remove(E e) {
      if (indexOf(e) >= 0) {
        remove(indexOf(e));
        return true;
      }
      else 
        return false;
    }
  }

  public class MyLinkedList<E> extends MyAbstractList<E> {
    private Node<E> head, tail;

    /** Create a default list */
    public MyLinkedList() {
    }

    /** Create a list from an array of objects */
    public MyLinkedList(E[] objects) {
      super(objects);
    }

    /** Return the head element in the list */
    public E getFirst() {
      if (size == 0) {
        return null;
      }
      else {
        return head.element;
      }
    }

    /** Return the last element in the list */
    public E getLast() {
      if (size == 0) {
        return null;
      }
      else {
        return tail.element;
      }
    }

    /** Add an element to the beginning of the list */
    public void addFirst(E e) {
      Node<E> newNode = new Node<E>(e); // Create a new node
      newNode.next = head; // link the new node with the head
      head = newNode; // head points to the new node
      size++; // Increase list size

      if (tail == null) // the new node is the only node in list
        tail = head;
    }

    /** Add an element to the end of the list */
    public void addLast(E e) {
      Node<E> newNode = new Node<E>(e); // Create a new for element e

      if (tail == null) {
        head = tail = newNode; // The new node is the only node in list
      }
      else {
        tail.next = newNode; // Link the new with the last node
        tail = tail.next; // tail now points to the last node
      }

      size++; // Increase size
    }


    /** Add a new element at the specified index in this list
     * The index of the head element is 0 */
    public void add(int index, E e) {
      if (index == 0) {
        addFirst(e);
      }
      else if (index >= size) {
        addLast(e);
      }
      else {
        Node<E> current = head;
        for (int i = 1; i < index; i++) {
          current = current.next;
        }
        Node<E> temp = current.next;
        current.next = new Node<E>(e);
        (current.next).next = temp;
        size++;
      }
    }

    /** Remove the head node and
     *  return the object that is contained in the removed node. */
    public E removeFirst() {
      if (size == 0) {
        return null;
      }
      else {
        Node<E> temp = head;
        head = head.next;
        size--;
        if (head == null) {
          tail = null;
        }
        return temp.element;
      }
    }

    /** Remove the last node and
     * return the object that is contained in the removed node. */
    public E removeLast() {
      if (size == 0) {
        return null;
      }
      else if (size == 1) {
        Node<E> temp = head;
        head = tail = null;
        size = 0;
        return temp.element;
      }
      else {
        Node<E> current = head;

        for (int i = 0; i < size - 2; i++) {
          current = current.next;
        }

        Node<E> temp = tail;
        tail = current;
        tail.next = null;
        size--;
        return temp.element;
      }
    }

    /** Remove the element at the specified position in this list.
     *  Return the element that was removed from the list. */
    public E remove(int index) {
      if (index < 0 || index >= size) {
        return null;
      }
      else if (index == 0) {
        return removeFirst();
      }
      else if (index == size - 1) {
        return removeLast();
      }
      else {
        Node<E> previous = head;

        for (int i = 1; i < index; i++) {
          previous = previous.next;
        }

        Node<E> current = previous.next;
        previous.next = current.next;
        size--;
        return current.element;
      }
    }

    @Override
    public String toString() {
      StringBuilder result = new StringBuilder("[");

      Node<E> current = head;
      for (int i = 0; i < size; i++) {
        result.append(current.element);
        current = current.next;
        if (current != null) {
          result.append(", "); // Separate two elements with a comma
        }
        else {
          result.append("]"); // Insert the closing ] in the string
        }
      }

      return result.toString();
    }

    /** Clear the list */
    public void clear() {
      head = tail = null;
    }

    /** Return true if this list contains the element o */
    public boolean contains(Object o) {
      // Implement it in this exercise
      Node<E> current = head;
      for (int i = 0; i < size; i++) {
        if (current.element.equals(o))
          return true;
        current = current.next;
      }

      return false;
    }

    /** Return the element from this list at the specified index */
    public E get(int index) {
      // Implement it in this exercise
      if (index < 0 || index > size - 1)
        return null;

      Node<E> current = head;
      for (int i = 0; i < index; i++)
        current = current.next;

      return current.element;
    }

    /** Returns the index of the first matching element in this list.
     *  Returns -1 if no match. */
    public int indexOf(Object o) {
      // Implement it in this exercise
      Node<E> current = head;
      for (int i = 0; i < size; i++) {
        if (current.element.equals(o))
          return i;
        current = current.next;
      }

      return -1;
    }

    /** Returns the index of the last matching element in this list
     *  Returns -1 if no match. */
    public int lastIndexOf(Object o) {
      // Implement it in this exercise
      int lastIndex = -1;
      Node<E> current = head;
      for (int i = 0; i < size; i++) {
        if (current.element.equals(o))
          lastIndex = i;
        current = current.next;
      }

      return lastIndex;
    }

    /** Replace the element at the specified position in this list
     *  with the specified element. */
    public E set(int index, E e) {
      if (index < 0 || index > size - 1)
        return null;

      Node<E> current = head;
      for (int i = 0; i < index; i++)
        current = current.next;

      E temp =  current.element;
      current.element = e;
      
      return temp;
    }

    /** Override the iterator method defined in Iterable */
    public java.util.Iterator<E> iterator() {
      return new LinkedListIterator();
    }

    private class LinkedListIterator 
        implements java.util.Iterator<E> {
      private Node<E> current = head; // Current index 
      
      public boolean hasNext() {
        return (current != null);
      }

      public E next() {
        E e = current.element;
        current = current.next;
        return e;
      }

      public void remove() {
        System.out.println("Implementation left as an exercise");
      }
    }
    
    private class Node<E> {
      E element;
      Node<E> next;

      public Node(E element) {
        this.element = element;
      }
    }
  }
}
