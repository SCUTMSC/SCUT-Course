public class Exercise18_17 {
  public static void main(String[] args) {
    System.out.println(count(new char[]{'W', 'e', 'l', 'c', 'o', 'm', 'E'}, 'e'));
  }

  public static int count(char[] chars, char ch) {
    return count(chars, ch, chars.length - 1);
  }

  public static int count(char[] chars, char ch, int high) {
    if (high >= 0) {
      return count(chars, ch, high - 1) +
        ((chars[high] == ch) ? 1 : 0);
    }
    else
      return 0;
  }
}
