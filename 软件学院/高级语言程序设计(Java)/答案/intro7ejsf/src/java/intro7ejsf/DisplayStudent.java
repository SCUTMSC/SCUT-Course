/*
 * DisplayStudent.java
 *
 * Created on April 22, 2007, 8:25 PM
 * Copyright Liang
 */
package intro7ejsf;

import com.sun.data.provider.impl.CachedRowSetDataProvider;
import com.sun.rave.web.ui.appbase.AbstractPageBean;
import com.sun.webui.jsf.component.Body;
import com.sun.webui.jsf.component.Button;
import com.sun.webui.jsf.component.DropDown;
import com.sun.webui.jsf.component.Form;
import com.sun.webui.jsf.component.Head;
import com.sun.webui.jsf.component.Html;
import com.sun.webui.jsf.component.Link;
import com.sun.webui.jsf.component.MessageGroup;
import com.sun.webui.jsf.component.Page;
import com.sun.webui.jsf.component.StaticText;
import com.sun.webui.jsf.component.Table;
import com.sun.webui.jsf.component.TableColumn;
import com.sun.webui.jsf.component.TableRowGroup;
import com.sun.webui.jsf.model.DefaultTableDataProvider;
import com.sun.webui.jsf.model.SingleSelectOptionsList;
import javax.faces.FacesException;

/**
 * <p>Page bean that corresponds to a similarly named JSP page.  This
 * class contains component definitions (and initialization code) for
 * all components that you have defined on this page, as well as
 * lifecycle methods and event handlers where you may add behavior
 * to respond to incoming events.</p>
 */
public class DisplayStudent extends AbstractPageBean {
  // <editor-fold defaultstate="collapsed" desc="Managed Component Definition">
  private int __placeholder;
  
  /**
   * <p>Automatically managed component initialization.  <strong>WARNING:</strong>
   * This method is automatically generated, so any user-specified code inserted
   * here is subject to being replaced.</p>
   */
  private void _init() throws Exception {
    courseDataProvider.setCachedRowSet((javax.sql.rowset.CachedRowSet)getValue("#{SessionBean1.courseRowSet}"));
    studentDataProvider.setCachedRowSet((javax.sql.rowset.CachedRowSet)getValue("#{SessionBean1.studentRowSet}"));
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
  
  private DropDown ddCourse = new DropDown();
  
  public DropDown getDdCourse() {
    return ddCourse;
  }
  
  public void setDdCourse(DropDown dd) {
    this.ddCourse = dd;
  }
  
  private Button btDisplayStudent = new Button();
  
  public Button getBtDisplayStudent() {
    return btDisplayStudent;
  }
  
  public void setBtDisplayStudent(Button b) {
    this.btDisplayStudent = b;
  }
  
  private Table tbStudent = new Table();
  
  public Table getTbStudent() {
    return tbStudent;
  }
  
  public void setTbStudent(Table t) {
    this.tbStudent = t;
  }
  
  private TableRowGroup tableRowGroup1 = new TableRowGroup();
  
  public TableRowGroup getTableRowGroup1() {
    return tableRowGroup1;
  }
  
  public void setTableRowGroup1(TableRowGroup trg) {
    this.tableRowGroup1 = trg;
  }
  
  private TableColumn tableColumn1 = new TableColumn();
  
  public TableColumn getTableColumn1() {
    return tableColumn1;
  }
  
  public void setTableColumn1(TableColumn tc) {
    this.tableColumn1 = tc;
  }
  
  private StaticText staticText2 = new StaticText();
  
  public StaticText getStaticText2() {
    return staticText2;
  }
  
  public void setStaticText2(StaticText st) {
    this.staticText2 = st;
  }
  
  private TableColumn tableColumn2 = new TableColumn();
  
  public TableColumn getTableColumn2() {
    return tableColumn2;
  }
  
  public void setTableColumn2(TableColumn tc) {
    this.tableColumn2 = tc;
  }
  
  private StaticText staticText3 = new StaticText();
  
  public StaticText getStaticText3() {
    return staticText3;
  }
  
  public void setStaticText3(StaticText st) {
    this.staticText3 = st;
  }
  
  private TableColumn tableColumn3 = new TableColumn();
  
  public TableColumn getTableColumn3() {
    return tableColumn3;
  }
  
  public void setTableColumn3(TableColumn tc) {
    this.tableColumn3 = tc;
  }
  
  private StaticText staticText4 = new StaticText();
  
  public StaticText getStaticText4() {
    return staticText4;
  }
  
  public void setStaticText4(StaticText st) {
    this.staticText4 = st;
  }
  
  private TableColumn tableColumn4 = new TableColumn();
  
  public TableColumn getTableColumn4() {
    return tableColumn4;
  }
  
  public void setTableColumn4(TableColumn tc) {
    this.tableColumn4 = tc;
  }
  
  private StaticText staticText5 = new StaticText();
  
  public StaticText getStaticText5() {
    return staticText5;
  }
  
  public void setStaticText5(StaticText st) {
    this.staticText5 = st;
  }
  
  private TableColumn tableColumn5 = new TableColumn();
  
  public TableColumn getTableColumn5() {
    return tableColumn5;
  }
  
  public void setTableColumn5(TableColumn tc) {
    this.tableColumn5 = tc;
  }
  
  private StaticText staticText6 = new StaticText();
  
  public StaticText getStaticText6() {
    return staticText6;
  }
  
  public void setStaticText6(StaticText st) {
    this.staticText6 = st;
  }
  
  private TableColumn tableColumn6 = new TableColumn();
  
  public TableColumn getTableColumn6() {
    return tableColumn6;
  }
  
  public void setTableColumn6(TableColumn tc) {
    this.tableColumn6 = tc;
  }
  
  private StaticText staticText7 = new StaticText();
  
  public StaticText getStaticText7() {
    return staticText7;
  }
  
  public void setStaticText7(StaticText st) {
    this.staticText7 = st;
  }
  
  private TableColumn tableColumn7 = new TableColumn();
  
  public TableColumn getTableColumn7() {
    return tableColumn7;
  }
  
  public void setTableColumn7(TableColumn tc) {
    this.tableColumn7 = tc;
  }
  
  private StaticText staticText8 = new StaticText();
  
  public StaticText getStaticText8() {
    return staticText8;
  }
  
  public void setStaticText8(StaticText st) {
    this.staticText8 = st;
  }
  
  private TableColumn tableColumn8 = new TableColumn();
  
  public TableColumn getTableColumn8() {
    return tableColumn8;
  }
  
  public void setTableColumn8(TableColumn tc) {
    this.tableColumn8 = tc;
  }
  
  private StaticText staticText9 = new StaticText();
  
  public StaticText getStaticText9() {
    return staticText9;
  }
  
  public void setStaticText9(StaticText st) {
    this.staticText9 = st;
  }
  
  private TableColumn tableColumn9 = new TableColumn();
  
  public TableColumn getTableColumn9() {
    return tableColumn9;
  }
  
  public void setTableColumn9(TableColumn tc) {
    this.tableColumn9 = tc;
  }
  
  private StaticText staticText10 = new StaticText();
  
  public StaticText getStaticText10() {
    return staticText10;
  }
  
  public void setStaticText10(StaticText st) {
    this.staticText10 = st;
  }
  
  private MessageGroup messageGroup1 = new MessageGroup();
  
  public MessageGroup getMessageGroup1() {
    return messageGroup1;
  }
  
  public void setMessageGroup1(MessageGroup mg) {
    this.messageGroup1 = mg;
  }
  
  private CachedRowSetDataProvider courseDataProvider = new CachedRowSetDataProvider();
  
  public CachedRowSetDataProvider getCourseDataProvider() {
    return courseDataProvider;
  }
  
  public void setCourseDataProvider(CachedRowSetDataProvider crsdp) {
    this.courseDataProvider = crsdp;
  }
  
  private CachedRowSetDataProvider studentDataProvider = new CachedRowSetDataProvider();
  
  public CachedRowSetDataProvider getStudentDataProvider() {
    return studentDataProvider;
  }
  
  public void setStudentDataProvider(CachedRowSetDataProvider crsdp) {
    this.studentDataProvider = crsdp;
  }
  
  // </editor-fold>
  
  /**
   * <p>Construct a new Page bean instance.</p>
   */
  public DisplayStudent() {
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
      log("DisplayStudent Initialization Failure", e);
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
    try {
      if (this.getSessionBean1().isFirstTime()) {
        studentDataProvider.getCachedRowSet().setObject(1, "11111");
        //studentDataProvider.refresh();
      }
    } catch (Exception ex) {
      ex.printStackTrace();
    }
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
    courseDataProvider.close();
    studentDataProvider.close();
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
  
  public String btDisplayStudent_action() {
    // Get the selected course ID
    String courseId = ddCourse.getSelected().toString();
    error("courseId " + courseId);
    
    this.getSessionBean1().setFirstTime(false);
    
    try {
      studentDataProvider.getCachedRowSet().setObject(1, courseId);
      studentDataProvider.refresh();
    } catch (Exception ex) {
      ex.printStackTrace();
    }
    
    tbStudent.setRendered(true);
    return null;
  }
}

