/*
 * ComputeLoan.java
 *
 * Created on April 22, 2007, 7:00 PM
 * Copyright Liang
 */
package intro7ejsf;

import com.sun.rave.web.ui.appbase.AbstractPageBean;
import com.sun.webui.jsf.component.Body;
import com.sun.webui.jsf.component.Button;
import com.sun.webui.jsf.component.Form;
import com.sun.webui.jsf.component.Head;
import com.sun.webui.jsf.component.Html;
import com.sun.webui.jsf.component.Link;
import com.sun.webui.jsf.component.Page;
import com.sun.webui.jsf.component.StaticText;
import com.sun.webui.jsf.component.TextField;
import javax.faces.FacesException;
import javax.faces.component.html.HtmlPanelGrid;

/**
 * <p>Page bean that corresponds to a similarly named JSP page.  This
 * class contains component definitions (and initialization code) for
 * all components that you have defined on this page, as well as
 * lifecycle methods and event handlers where you may add behavior
 * to respond to incoming events.</p>
 */
public class ComputeLoan extends AbstractPageBean {
  // <editor-fold defaultstate="collapsed" desc="Managed Component Definition">
  private int __placeholder;
  
  /**
   * <p>Automatically managed component initialization.  <strong>WARNING:</strong>
   * This method is automatically generated, so any user-specified code inserted
   * here is subject to being replaced.</p>
   */
  private void _init() throws Exception {
  }
  
  private Page page1 = new Page();
  
  public Page getPage1() {
    return page1;
  }
  
  public void setPage1(Page p) {
    this.page1 = p;
  }
  
  private Html html1 = new Html();
  
  public Html getHtml1() {
    return html1;
  }
  
  public void setHtml1(Html h) {
    this.html1 = h;
  }
  
  private Head head1 = new Head();
  
  public Head getHead1() {
    return head1;
  }
  
  public void setHead1(Head h) {
    this.head1 = h;
  }
  
  private Link link1 = new Link();
  
  public Link getLink1() {
    return link1;
  }
  
  public void setLink1(Link l) {
    this.link1 = l;
  }
  
  private Body body1 = new Body();
  
  public Body getBody1() {
    return body1;
  }
  
  public void setBody1(Body b) {
    this.body1 = b;
  }
  
  private Form form1 = new Form();
  
  public Form getForm1() {
    return form1;
  }
  
  public void setForm1(Form f) {
    this.form1 = f;
  }

  private HtmlPanelGrid gridPanel1 = new HtmlPanelGrid();

  public HtmlPanelGrid getGridPanel1() {
    return gridPanel1;
  }

  public void setGridPanel1(HtmlPanelGrid hpg) {
    this.gridPanel1 = hpg;
  }

  private StaticText staticText1 = new StaticText();

  public StaticText getStaticText1() {
    return staticText1;
  }

  public void setStaticText1(StaticText st) {
    this.staticText1 = st;
  }

  private TextField tfLoanAmount = new TextField();

  public TextField getTfLoanAmount() {
    return tfLoanAmount;
  }

  public void setTfLoanAmount(TextField tf) {
    this.tfLoanAmount = tf;
  }

  private StaticText staticText3 = new StaticText();

  public StaticText getStaticText3() {
    return staticText3;
  }

  public void setStaticText3(StaticText st) {
    this.staticText3 = st;
  }

  private TextField tfNumberOfYears = new TextField();

  public TextField getTfNumberOfYears() {
    return tfNumberOfYears;
  }

  public void setTfNumberOfYears(TextField tf) {
    this.tfNumberOfYears = tf;
  }

  private StaticText staticText4 = new StaticText();

  public StaticText getStaticText4() {
    return staticText4;
  }

  public void setStaticText4(StaticText st) {
    this.staticText4 = st;
  }

  private TextField tfAnnualInterestRate = new TextField();

  public TextField getTfAnnualInterestRate() {
    return tfAnnualInterestRate;
  }

  public void setTfAnnualInterestRate(TextField tf) {
    this.tfAnnualInterestRate = tf;
  }

  private Button btComputeLoan = new Button();

  public Button getBtComputeLoan() {
    return btComputeLoan;
  }

  public void setBtComputeLoan(Button b) {
    this.btComputeLoan = b;
  }

  private HtmlPanelGrid gridPanel2 = new HtmlPanelGrid();

  public HtmlPanelGrid getGridPanel2() {
    return gridPanel2;
  }

  public void setGridPanel2(HtmlPanelGrid hpg) {
    this.gridPanel2 = hpg;
  }

  private TextField tfTotalPayment = new TextField();

  public TextField getTfTotalPayment() {
    return tfTotalPayment;
  }

  public void setTfTotalPayment(TextField tf) {
    this.tfTotalPayment = tf;
  }

  private StaticText staticText5 = new StaticText();

  public StaticText getStaticText5() {
    return staticText5;
  }

  public void setStaticText5(StaticText st) {
    this.staticText5 = st;
  }

  private StaticText staticText6 = new StaticText();

  public StaticText getStaticText6() {
    return staticText6;
  }

  public void setStaticText6(StaticText st) {
    this.staticText6 = st;
  }

  private TextField tfMonthlyPayment = new TextField();

  public TextField getTfMonthlyPayment() {
    return tfMonthlyPayment;
  }

  public void setTfMonthlyPayment(TextField tf) {
    this.tfMonthlyPayment = tf;
  }
  
  // </editor-fold>
  
  /**
   * <p>Construct a new Page bean instance.</p>
   */
  public ComputeLoan() {
  }
  
  /**
   * <p>Callback method that is called whenever a page is navigated to,
   * either directly via a URL, or indirectly via page navigation.
   * Customize this method to acquire resources that will be needed
   * for event handlers and lifecycle methods, whether or not this
   * page is performing post back processing.</p>
   *
   * <p>Note that, if the current request is a postback, the property
   * values of the components do <strong>not</strong> represent any
   * values submitted with this request.  Instead, they represent the
   * property values that were saved for this view when it was rendered.</p>
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
      log("ComputeLoan Initialization Failure", e);
      throw e instanceof FacesException ? (FacesException) e: new FacesException(e);
    }
    
    // </editor-fold>
    // Perform application initialization that must complete
    // *after* managed components are initialized
    // TODO - add your own initialization code here
  }
  
  /**
   * <p>Callback method that is called after the component tree has been
   * restored, but before any event processing takes place.  This method
   * will <strong>only</strong> be called on a postback request that
   * is processing a form submit.  Customize this method to allocate
   * resources that will be required in your event handlers.</p>
   */
  public void preprocess() {
  }
  
  /**
   * <p>Callback method that is called just before rendering takes place.
   * This method will <strong>only</strong> be called for the page that
   * will actually be rendered (and not, for example, on a page that
   * handled a postback and then navigated to a different page).  Customize
   * this method to allocate resources that will be required for rendering
   * this page.</p>
   */
  public void prerender() {
  }
  
  /**
   * <p>Callback method that is called after rendering is completed for
   * this request, if <code>init()</code> was called (regardless of whether
   * or not this was the page that was actually rendered).  Customize this
   * method to release resources acquired in the <code>init()</code>,
   * <code>preprocess()</code>, or <code>prerender()</code> methods (or
   * acquired during execution of an event handler).</p>
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
   * <p>Return a reference to the scoped data bean.</p>
   */
  protected RequestBean1 getRequestBean1() {
    return (RequestBean1)getBean("RequestBean1");
  }

  /**
   * <p>Return a reference to the scoped data bean.</p>
   */
  protected SessionBean1 getSessionBean1() {
    return (SessionBean1)getBean("SessionBean1");
  }

  public String btComputeLoan_action() {
    // TODO: Process the action. Return value is a navigation
    // case name where null will return to the same page.
    double loanAmount = 
      Double.parseDouble(tfLoanAmount.getText().toString().trim());
    int numberOfYears = 
      Integer.parseInt(tfNumberOfYears.getText().toString().trim());
    double annualInterestRate = Double.parseDouble(
      tfAnnualInterestRate.getText().toString().trim());
    
    chapter39.Loan loan = new chapter39.Loan(
      annualInterestRate, numberOfYears, loanAmount);
    
    gridPanel2.setRendered(true);
    tfMonthlyPayment.setText(loan.getMonthlyPayment() + "");
    tfTotalPayment.setText(loan.getTotalPayment() + "");
    
    return null;
  }
}

