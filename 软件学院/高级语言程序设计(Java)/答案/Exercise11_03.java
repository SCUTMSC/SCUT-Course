class Checkings extends Account {
  protected int overdraftLimit = 5000;

  @Override
  public String toString() {
    return "Checkings";
  }
}

class Saving extends Account {
  protected int overdraftLimit = 5000;

  @Override
  public String toString() {
    return "Saving";
  }
}
