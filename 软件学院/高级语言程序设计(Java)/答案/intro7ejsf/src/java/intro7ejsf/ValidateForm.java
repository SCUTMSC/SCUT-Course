/*
 * ValidateForm.java
 *
 * Created on April 23, 2007, 8:29 PM
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
import com.sun.webui.jsf.component.Message;
import com.sun.webui.jsf.component.Page;
import com.sun.webui.jsf.component.StaticText;
import com.sun.webui.jsf.component.TextField;
import javax.faces.FacesException;
import javax.faces.application.FacesMessage;
import javax.faces.component.UIComponent;
import javax.faces.component.html.HtmlPanelGrid;
import javax.faces.context.FacesContext;
import javax.faces.validator.LengthValidator;
import javax.faces.validator.ValidatorException;

/**
 * <p>Page bean that corresponds to a similarly named JSP page.  This
 * class contains component definitions (and initialization code) for
 * all components that you have defined on this page, as well as
 * lifecycle methods and event handlers where you may add behavior
 * to respond to incoming events.</p>
 */
public class ValidateForm extends AbstractPageBean {
  // <editor-fold defaultstate="collapsed" desc="Managed Component Definition">
  private int __placeholder;
  
  /**
   * <p>Automatically managed component initialization.  <strong>WARNING:</strong>
   * This method is automatically generated, so any user-specified code inserted
   * here is subject to being replaced.</p>
   */
  private void _init() throws Exception {
    lengthValidator1.setMaximum(10);
    lengthValidator1.setMinimum(1);
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

  private TextField tfName = new TextField();

  public TextField getTfName() {
    return tfName;
  }

  public void setTfName(TextField tf) {
    this.tfName = tf;
  }

  private StaticText staticText2 = new StaticText();

  public StaticText getStaticText2() {
    return staticText2;
  }

  public void setStaticText2(StaticText st) {
    this.staticText2 = st;
  }

  private TextField tfAge = new TextField();

  public TextField getTfAge() {
    return tfAge;
  }

  public void setTfAge(TextField tf) {
    this.tfAge = tf;
  }

  private StaticText staticText3 = new StaticText();

  public StaticText getStaticText3() {
    return staticText3;
  }

  public void setStaticText3(StaticText st) {
    this.staticText3 = st;
  }

  private TextField tfHeight = new TextField();

  public TextField getTfHeight() {
    return tfHeight;
  }

  public void setTfHeight(TextField tf) {
    this.tfHeight = tf;
  }

  private Button button1 = new Button();

  public Button getButton1() {
    return button1;
  }

  public void setButton1(Button b) {
    this.button1 = b;
  }

  private StaticText staticText4 = new StaticText();

  public StaticText getStaticText4() {
    return staticText4;
  }

  public void setStaticText4(StaticText st) {
    this.staticText4 = st;
  }

  private TextField tfSSN = new TextField();

  public TextField getTfSSN() {
    return tfSSN;
  }

  public void setTfSSN(TextField tf) {
    this.tfSSN = tf;
  }

  private StaticText stResult = new StaticText();

  public StaticText getStResult() {
    return stResult;
  }

  public void setStResult(StaticText st) {
    this.stResult = st;
  }

  private HtmlPanelGrid gridPanel2 = new HtmlPanelGrid();

  public HtmlPanelGrid getGridPanel2() {
    return gridPanel2;
  }

  public void setGridPanel2(HtmlPanelGrid hpg) {
    this.gridPanel2 = hpg;
  }

  private Message message1 = new Message();

  public Message getMessage1() {
    return message1;
  }

  public void setMessage1(Message m) {
    this.message1 = m;
  }

  private Message message2 = new Message();

  public Message getMessage2() {
    return message2;
  }

  public void setMessage2(Message m) {
    this.message2 = m;
  }

  private Message message3 = new Message();

  public Message getMessage3() {
    return message3;
  }

  public void setMessage3(Message m) {
    this.message3 = m;
  }

  private Message message4 = new Message();

  public Message getMessage4() {
    return message4;
  }

  public void setMessage4(Message m) {
    this.message4 = m;
  }

  private LengthValidator lengthValidator1 = new LengthValidator();

  public LengthValidator getLengthValidator1() {
    return lengthValidator1;
  }

  public void setLengthValidator1(LengthValidator lv) {
    this.lengthValidator1 = lv;
  }
  
  // </editor-fold>
  
  /**
   * <p>Construct a new Page bean instance.</p>
   */
  public ValidateForm() {
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
      log("ValidateForm Initialization Failure", e);
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
  protected SessionBean1 getSessionBean1() {
    return (SessionBean1)getBean("SessionBean1");
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

  public String button1_action() {
    // TODO: Process the action. Return value is a navigation
    // case name where null will return to the same page.
    String output = "The input you entered are <br />" + 
      "Name: " + tfName.getText() + "<br />" +
      "SSN: " + tfSSN.getText() + "<br />" +
      "Age: " + tfAge.getText() + "<br />" + 
      "Height: " + tfHeight.getText() + "<br />";
     stResult.setText(output);
    return null;
  }

  public void tfSSN_validate(FacesContext context, 
      UIComponent component, Object value) {
    String ssn = String.valueOf(value);
    
    if (!ssn.matches("[\\d]{3}-[\\d]{2}-[\\d]{4}")) {
      throw new ValidatorException(new FacesMessage(
        "Enter a valid SSN, e.g., 123-44-5678"));
    }
  }
}

