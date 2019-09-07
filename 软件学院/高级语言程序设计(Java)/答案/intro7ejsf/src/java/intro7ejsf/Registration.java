/*
 * Registration.java
 *
 * Created on April 22, 2007, 11:56 AM
 * Copyright Liang
 */
package intro7ejsf;

import com.sun.rave.web.ui.appbase.AbstractPageBean;
import com.sun.webui.jsf.component.Body;
import com.sun.webui.jsf.component.Button;
import com.sun.webui.jsf.component.Checkbox;
import com.sun.webui.jsf.component.CheckboxGroup;
import com.sun.webui.jsf.component.DropDown;
import com.sun.webui.jsf.component.Form;
import com.sun.webui.jsf.component.Head;
import com.sun.webui.jsf.component.Html;
import com.sun.webui.jsf.component.Link;
import com.sun.webui.jsf.component.Listbox;
import com.sun.webui.jsf.component.Page;
import com.sun.webui.jsf.component.PanelGroup;
import com.sun.webui.jsf.component.PanelLayout;
import com.sun.webui.jsf.component.RadioButtonGroup;
import com.sun.webui.jsf.component.StaticText;
import com.sun.webui.jsf.component.TextArea;
import com.sun.webui.jsf.component.TextField;
import com.sun.webui.jsf.model.DefaultOptionsList;
import com.sun.webui.jsf.model.MultipleSelectOptionsList;
import com.sun.webui.jsf.model.SingleSelectOptionsList;
import javax.faces.FacesException;
import javax.faces.component.html.HtmlPanelGrid;
import javax.faces.event.ValueChangeEvent;

/**
 * <p>Page bean that corresponds to a similarly named JSP page.  This
 * class contains component definitions (and initialization code) for
 * all components that you have defined on this page, as well as
 * lifecycle methods and event handlers where you may add behavior
 * to respond to incoming events.</p>
 */
public class Registration extends AbstractPageBean {
  // <editor-fold defaultstate="collapsed" desc="Managed Component Definition">
  private int __placeholder;
  
  /**
   * <p>Automatically managed component initialization.  <strong>WARNING:</strong>
   * This method is automatically generated, so any user-specified code inserted
   * here is subject to being replaced.</p>
   */
  private void _init() throws Exception {
    rbgGenderDefaultOptions.setOptions(new com.sun.webui.jsf.model.Option[] {new com.sun.webui.jsf.model.Option("Male", "Male"), new com.sun.webui.jsf.model.Option("Female", "Female")});
    ddMajorDefaultOptions.setOptions(new com.sun.webui.jsf.model.Option[] {new com.sun.webui.jsf.model.Option("Mathematics", "Mathematics"), new com.sun.webui.jsf.model.Option("Computer Science", "Computer Science"), new com.sun.webui.jsf.model.Option("Physics", "Physics")});
    lbxMinorDefaultOptions.setOptions(new com.sun.webui.jsf.model.Option[] {new com.sun.webui.jsf.model.Option("Mathematics", "Mathematics"), new com.sun.webui.jsf.model.Option("Computer Science", "Computer Science"), new com.sun.webui.jsf.model.Option("Chemistry", "Chemistry")});
    chkgHobbyDefaultOptions.setOptions(new com.sun.webui.jsf.model.Option[] {new com.sun.webui.jsf.model.Option("Tennis", "Tennis"), new com.sun.webui.jsf.model.Option("Golf", "Golf"), new com.sun.webui.jsf.model.Option("Ping Pong", "Ping Pong")});
    chkgHobbyDefaultOptions.setSelectedValue(null);
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

  private StaticText staticText1 = new StaticText();

  public StaticText getStaticText1() {
    return staticText1;
  }

  public void setStaticText1(StaticText st) {
    this.staticText1 = st;
  }

  private StaticText staticText2 = new StaticText();

  public StaticText getStaticText2() {
    return staticText2;
  }

  public void setStaticText2(StaticText st) {
    this.staticText2 = st;
  }

  private TextField tfLastName = new TextField();

  public TextField getTfLastName() {
    return tfLastName;
  }

  public void setTfLastName(TextField tf) {
    this.tfLastName = tf;
  }

  private StaticText staticText3 = new StaticText();

  public StaticText getStaticText3() {
    return staticText3;
  }

  public void setStaticText3(StaticText st) {
    this.staticText3 = st;
  }

  private TextField tfMi = new TextField();

  public TextField getTfMi() {
    return tfMi;
  }

  public void setTfMi(TextField tf) {
    this.tfMi = tf;
  }

  private StaticText staticText4 = new StaticText();

  public StaticText getStaticText4() {
    return staticText4;
  }

  public void setStaticText4(StaticText st) {
    this.staticText4 = st;
  }

  private TextField tfFirstName = new TextField();

  public TextField getTfFirstName() {
    return tfFirstName;
  }

  public void setTfFirstName(TextField tf) {
    this.tfFirstName = tf;
  }

  private RadioButtonGroup rbgGender = new RadioButtonGroup();

  public RadioButtonGroup getRbgGender() {
    return rbgGender;
  }

  public void setRbgGender(RadioButtonGroup rbg) {
    this.rbgGender = rbg;
  }

  private SingleSelectOptionsList rbgGenderDefaultOptions = new SingleSelectOptionsList();

  public SingleSelectOptionsList getRbgGenderDefaultOptions() {
    return rbgGenderDefaultOptions;
  }

  public void setRbgGenderDefaultOptions(SingleSelectOptionsList ssol) {
    this.rbgGenderDefaultOptions = ssol;
  }

  private StaticText staticText5 = new StaticText();

  public StaticText getStaticText5() {
    return staticText5;
  }

  public void setStaticText5(StaticText st) {
    this.staticText5 = st;
  }

  private DropDown ddMajor = new DropDown();

  public DropDown getDdMajor() {
    return ddMajor;
  }

  public void setDdMajor(DropDown dd) {
    this.ddMajor = dd;
  }

  private SingleSelectOptionsList ddMajorDefaultOptions = new SingleSelectOptionsList();

  public SingleSelectOptionsList getDdMajorDefaultOptions() {
    return ddMajorDefaultOptions;
  }

  public void setDdMajorDefaultOptions(SingleSelectOptionsList ssol) {
    this.ddMajorDefaultOptions = ssol;
  }

  private StaticText staticText6 = new StaticText();

  public StaticText getStaticText6() {
    return staticText6;
  }

  public void setStaticText6(StaticText st) {
    this.staticText6 = st;
  }

  private Listbox lbxMinor = new Listbox();

  public Listbox getLbxMinor() {
    return lbxMinor;
  }

  public void setLbxMinor(Listbox l) {
    this.lbxMinor = l;
  }

  private DefaultOptionsList lbxMinorDefaultOptions = new DefaultOptionsList();

  public DefaultOptionsList getLbxMinorDefaultOptions() {
    return lbxMinorDefaultOptions;
  }

  public void setLbxMinorDefaultOptions(DefaultOptionsList dol) {
    this.lbxMinorDefaultOptions = dol;
  }

  private StaticText staticText8 = new StaticText();

  public StaticText getStaticText8() {
    return staticText8;
  }

  public void setStaticText8(StaticText st) {
    this.staticText8 = st;
  }

  private TextArea taRemarks = new TextArea();

  public TextArea getTaRemarks() {
    return taRemarks;
  }

  public void setTaRemarks(TextArea ta) {
    this.taRemarks = ta;
  }

  private Button btRegister = new Button();

  public Button getBtRegister() {
    return btRegister;
  }

  public void setBtRegister(Button b) {
    this.btRegister = b;
  }

  private Form form2 = new Form();

  public Form getForm2() {
    return form2;
  }

  public void setForm2(Form f) {
    this.form2 = f;
  }

  private StaticText stLastName = new StaticText();

  public StaticText getStLastName() {
    return stLastName;
  }

  public void setStLastName(StaticText st) {
    this.stLastName = st;
  }

  private StaticText stMi = new StaticText();

  public StaticText getStMi() {
    return stMi;
  }

  public void setStMi(StaticText st) {
    this.stMi = st;
  }

  private StaticText stFirstName = new StaticText();

  public StaticText getStFirstName() {
    return stFirstName;
  }

  public void setStFirstName(StaticText st) {
    this.stFirstName = st;
  }

  private StaticText stMajor = new StaticText();

  public StaticText getStMajor() {
    return stMajor;
  }

  public void setStMajor(StaticText st) {
    this.stMajor = st;
  }

  private StaticText stMinor = new StaticText();

  public StaticText getStMinor() {
    return stMinor;
  }

  public void setStMinor(StaticText st) {
    this.stMinor = st;
  }

  private StaticText stHobby = new StaticText();

  public StaticText getStHobby() {
    return stHobby;
  }

  public void setStHobby(StaticText st) {
    this.stHobby = st;
  }

  private CheckboxGroup chkgHobby = new CheckboxGroup();

  public CheckboxGroup getChkgHobby() {
    return chkgHobby;
  }

  public void setChkgHobby(CheckboxGroup cg) {
    this.chkgHobby = cg;
  }

  private MultipleSelectOptionsList chkgHobbyDefaultOptions = new MultipleSelectOptionsList();

  public MultipleSelectOptionsList getChkgHobbyDefaultOptions() {
    return chkgHobbyDefaultOptions;
  }

  public void setChkgHobbyDefaultOptions(MultipleSelectOptionsList msol) {
    this.chkgHobbyDefaultOptions = msol;
  }

  private StaticText stRemarks = new StaticText();

  public StaticText getStRemarks() {
    return stRemarks;
  }

  public void setStRemarks(StaticText st) {
    this.stRemarks = st;
  }

  private StaticText stGender = new StaticText();

  public StaticText getStGender() {
    return stGender;
  }

  public void setStGender(StaticText st) {
    this.stGender = st;
  }
  
  // </editor-fold>
  
  /**
   * <p>Construct a new Page bean instance.</p>
   */
  public Registration() {
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
      log("Registration Initialization Failure", e);
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

  public String button1_action() {
    // TODO: Process the action. Return value is a navigation
    // case name where null will return to the same page.
    
    return null;
  }

  public String btRegister_action() {
    // TODO: Replace with your code
    form1.setRendered(false);
    form2.setRendered(true);
    stLastName.setText("Last name is " + tfLastName.getText());
    stMi.setText("MI is " + tfMi.getText());
    stFirstName.setText("First name is " + tfFirstName.getText());

    stGender.setText("Selected gender is " + 
      rbgGender.getSelected().toString());
    stMajor.setText("Selected major is " + 
      ddMajor.getSelected().toString());
    
    String[] selectedMinors = (String[])(lbxMinor.getSelected());
    String minors = "";
    for (int i = 0; i < selectedMinors.length; i++)
      minors += selectedMinors[i];
    stMinor.setText("Selected minors are " + minors);

    String[] selectedHobbies = (String[])(chkgHobby.getSelected());
    String hobbies = "";
    for (int i = 0; i < selectedHobbies.length; i++)
      hobbies += selectedHobbies[i];
    stHobby.setText("Selected hobbies are " + hobbies);

    stRemarks.setText("Remarks are " + taRemarks.getText());
    return null;
  }

  public void chkgHobby_processValueChange(ValueChangeEvent vce) {
    // TODO: Replace with your code
    
  }
}

