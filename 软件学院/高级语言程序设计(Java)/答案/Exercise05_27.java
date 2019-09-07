public class Exercise05_27 {
  public static void main(String[] args) {
    int count = 0;
    for (int year = 101; year <= 2100; year++) {
      if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
        System.out.print((++count % 10 == 0)? year + "\n": year + " ");
    }
    
    System.out.println("The number of leap year is " + count);
  }
}
