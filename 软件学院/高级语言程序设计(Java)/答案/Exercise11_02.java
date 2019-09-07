import java.util.*;

public class Exercise11_02 {
  public static void main(String[] args) {
    
  }
}

class Person {
  protected String name;
  protected String address;
  protected String phoneNumber;
  protected String email;

  @Override
  public String toString() {
    return "Person";
  }
}

class Student1 extends Person {
  public static int FRESHMAN = 1;
  public static int SOPHOMORE = 2;
  public static int JUNIOR = 3;
  public static int SENIOR = 4;

  protected int status;

  @Override
  public String toString() {
    return "Student";
  }
}

class Employee extends Person {
  protected String office;
  protected int salary;
  protected Calendar dateHired;

  @Override
  public String toString() {
    return "Employee";
  }
}

class Faculty extends Employee {
  public static int LECTURER = 1;
  public static int ASSISTANT_PROFESSOR = 2;
  public static int ASSOCIATE_PROFESSOR = 3;
  public static int PROFESSOR = 4;

  protected String officeHours;
  protected int rank;

  @Override
  public String toString() {
    return "Faculty";
  }
}

class Staff extends Employee {
  protected String title;

  @Override
  public String toString() {
    return "Staff's title is " + title;
  }
}
