package chapter39;

public class Loan {
  private double annualInterestRate;
  private int numberOfYears;
  private double loanAmount;
  private java.util.Date loanDate;

  /** Default constructor */
  public Loan() {
    annualInterestRate = 2.5;
    numberOfYears = 1;
    loanAmount = 1000;
  }

  /** Construct a loan with specified annual interest rate,
      number of years and loan amount
    */
  public Loan(double newAnnualInterestRate, int newNumberOfYears,
      double newLoanAmount) {
    annualInterestRate = newAnnualInterestRate;
    numberOfYears = newNumberOfYears;
    loanAmount = newLoanAmount;
    loanDate = new java.util.Date();
  }

  /** Return annualInterestRate */
  public double getAnnualInterestRate() {
    return annualInterestRate;
  }

  /** Set a new annualInterestRate */
  public void setAnnualInterestRate(double newAnnualInterestRate) {
    annualInterestRate = newAnnualInterestRate;
  }

  /** Return numberOfYears */
  public int getNumberOfYears() {
    return numberOfYears;
  }

  /** Set a new numberOfYears */
  public void setNumberOfYears(int newNumberOfYears) {
    numberOfYears = newNumberOfYears;
  }

  /** Return loanAmount */
  public double getLoanAmount() {
    return loanAmount;
  }

  /** Set a newloanAmount */
  public void setLoanAmount(double newLoanAmount) {
    loanAmount = newLoanAmount;
  }

  /** Find monthly payment */
  public double getMonthlyPayment() {
    double monthlyInterestRate = annualInterestRate / 1200;
    return loanAmount * monthlyInterestRate / (1 -
      (Math.pow(1 / (1 + monthlyInterestRate), numberOfYears * 12)));
  }

  /** Find total payment */
  public double getTotalPayment() {
    return getMonthlyPayment() * numberOfYears * 12;
  }

  /** Return loan date */
  public java.util.Date getLoanDate() {
    return loanDate;
  }
}
