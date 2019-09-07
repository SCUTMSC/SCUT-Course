/*
 * SessionBean1.java
 *
 * Created on April 22, 2007, 9:58 AM
 * Copyright Liang
 */
package intro7ejsf;

import com.sun.rave.web.ui.appbase.AbstractSessionBean;
import com.sun.sql.rowset.CachedRowSetXImpl;
import javax.faces.FacesException;

/**
 * <p>Session scope data bean for your application.  Create properties
 *  here to represent cached data that should be made available across
 *  multiple HTTP requests for an individual user.</p>
 *
 * <p>An instance of this class will be created for you automatically,
 * the first time your application evaluates a value binding expression
 * or method binding expression that references a managed bean using
 * this class.</p>
 */
public class SessionBean1 extends AbstractSessionBean {
  // <editor-fold defaultstate="collapsed" desc="Managed Component Definition">
  private int __placeholder;
  
  /**
   * <p>Automatically managed component initialization.  <strong>WARNING:</strong>
   * This method is automatically generated, so any user-specified code inserted
   * here is subject to being replaced.</p>
   */
  private void _init() throws Exception {
    courseRowSet.setDataSourceName("java:comp/env/jdbc/dataSource_1177287974062");
    courseRowSet.setCommand("SELECT ALL course.courseId, \n                    course.subjectId, \n                    course.courseNumber, \n                    course.title, \n                    course.numOfCredits \nFROM course ");
    courseRowSet.setTableName("course");
    studentRowSet.setDataSourceName("java:comp/env/jdbc/dataSource2");
    studentRowSet.setCommand("SELECT ALL student.ssn, \n                    student.firstName, \n                    student.mi, \n                    student.lastName, \n                    student.phone, \n                    student.birthDate, \n                    student.street, \n                    student.zipCode, \n                    student.deptId, \n                    course.courseId \nFROM student, enrollment, course\nWHERE course.courseId = ?\n          AND student.ssn = enrollment.ssn\n          AND enrollment.courseId = course.courseId ");
    studentRowSet.setTableName("student");
  }
  
  private CachedRowSetXImpl courseRowSet = new CachedRowSetXImpl();
  
  public CachedRowSetXImpl getCourseRowSet() {
    return courseRowSet;
  }
  
  public void setCourseRowSet(CachedRowSetXImpl crsxi) {
    this.courseRowSet = crsxi;
  }
  
  private CachedRowSetXImpl studentRowSet = new CachedRowSetXImpl();
  
  public CachedRowSetXImpl getStudentRowSet() {
    return studentRowSet;
  }
  
  public void setStudentRowSet(CachedRowSetXImpl crsxi) {
    this.studentRowSet = crsxi;
  }
  // </editor-fold>
  
  /**
   * <p>Construct a new session data bean instance.</p>
   */
  public SessionBean1() {
    number = (int)(Math.random() * 100);
  }
  
  /**
   * <p>This method is called when this bean is initially added to
   * session scope.  Typically, this occurs as a result of evaluating
   * a value binding or method binding expression, which utilizes the
   * managed bean facility to instantiate this bean and store it into
   * session scope.</p>
   *
   * <p>You may customize this method to initialize and cache data values
   * or resources that are required for the lifetime of a particular
   * user session.</p>
   */
  public void init() {
    // Perform initializations inherited from our superclass
    super.init();
    // Perform application initialization that must complete
    // *before* managed components are initialized
    // TODO - add your own initialiation code here
    
    // <editor-fold defaultstate="collapsed" desc="Managed Component Initialization">
    // Initialize automatically managed components
    // *Note* - this logic should NOT be modified
    try {
      _init();
    } catch (Exception e) {
      log("SessionBean1 Initialization Failure", e);
      throw e instanceof FacesException ? (FacesException) e: new FacesException(e);
    }
    
    // </editor-fold>
    // Perform application initialization that must complete
    // *after* managed components are initialized
    // TODO - add your own initialization code here
  }
  
  /**
   * <p>This method is called when the session containing it is about to be
   * passivated.  Typically, this occurs in a distributed servlet container
   * when the session is about to be transferred to a different
   * container instance, after which the <code>activate()</code> method
   * will be called to indicate that the transfer is complete.</p>
   *
   * <p>You may customize this method to release references to session data
   * or resources that can not be serialized with the session itself.</p>
   */
  public void passivate() {
  }
  
  /**
   * <p>This method is called when the session containing it was
   * reactivated.</p>
   *
   * <p>You may customize this method to reacquire references to session
   * data or resources that could not be serialized with the
   * session itself.</p>
   */
  public void activate() {
  }
  
  /**
   * <p>This method is called when this bean is removed from
   * session scope.  Typically, this occurs as a result of
   * the session timing out or being terminated by the application.</p>
   *
   * <p>You may customize this method to clean up resources allocated
   * during the execution of the <code>init()</code> method, or
   * at any later time during the lifetime of the application.</p>
   */
  public void destroy() {
  }
  
  /**
   * <p>Return a reference to the scoped data bean.</p>
   */
  protected ApplicationBean1 getApplicationBean1() {
    return (ApplicationBean1)getBean("ApplicationBean1");
  }
  
  /**
   * Holds value of property number.
   */
  private int number;
  
  /**
   * Getter for property number.
   * @return Value of property number.
   */
  public int getNumber() {
    return this.number;
  }
  
  /**
   * Setter for property number.
   * @param number New value of property number.
   */
  public void setNumber(int number) {
    this.number = number;
  }
  
  private boolean firstTime = true;
  
  public boolean isFirstTime() {
    return firstTime;
  }
  
  public void setFirstTime(boolean firstTime) {
    this.firstTime = firstTime;
  }
}
