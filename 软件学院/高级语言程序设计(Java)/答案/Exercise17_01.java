import java.io.*;
import java.util.*;

public class Exercise17_01 {
  public static void main(String[] args) throws IOException {
    try (
      Formatter output =
        new Formatter(new FileOutputStream("Exercise17_01.txt", true));
    ) {
      for (int i = 0; i < 100; i++)
        output.format("%d", (int)(Math.random() * 100000));
    }
  }
}