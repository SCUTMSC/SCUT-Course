<?xml version="1.0" encoding="UTF-8"?>
<jsp:root version="1.2" xmlns:f="http://java.sun.com/jsf/core" xmlns:h="http://java.sun.com/jsf/html" xmlns:jsp="http://java.sun.com/JSP/Page" xmlns:webuijsf="http://www.sun.com/webui/webuijsf">
    <jsp:directive.page contentType="text/html;charset=UTF-8" pageEncoding="UTF-8"/>
    <f:view>
        <webuijsf:page binding="#{Registration.page1}" id="page1">
            <webuijsf:html binding="#{Registration.html1}" id="html1">
                <webuijsf:head binding="#{Registration.head1}" id="head1">
                    <webuijsf:link binding="#{Registration.link1}" id="link1" url="/resources/stylesheet.css"/>
                </webuijsf:head>
                <webuijsf:body binding="#{Registration.body1}" id="body1" style="-rave-layout: grid">
                    <webuijsf:form binding="#{Registration.form1}" id="form1">
                        <webuijsf:staticText binding="#{Registration.staticText1}" id="staticText1" style="left: 48px; top: 24px; position: absolute" text="Student Registration Form"/>
                        <webuijsf:staticText binding="#{Registration.staticText2}" id="staticText2" style="position: absolute; left: 48px; top: 72px" text="Last Nmae: "/>
                        <webuijsf:textField binding="#{Registration.tfLastName}" id="tfLastName" style="position: absolute; left: 144px; top: 72px"/>
                        <webuijsf:staticText binding="#{Registration.staticText3}" id="staticText3" style="position: absolute; left: 336px; top: 72px" text="MI:"/>
                        <webuijsf:textField binding="#{Registration.tfMi}" id="tfMi" style="left: 360px; top: 72px; position: absolute; width: 24px"/>
                        <webuijsf:staticText binding="#{Registration.staticText4}" id="staticText4" style="position: absolute; left: 408px; top: 72px" text="First Name:"/>
                        <webuijsf:textField binding="#{Registration.tfFirstName}" id="tfFirstName" style="left: 480px; top: 72px; position: absolute"/>
                        <webuijsf:radioButtonGroup binding="#{Registration.rbgGender}" columns="2" id="rbgGender"
                            items="#{Registration.rbgGenderDefaultOptions.options}" label="Gender" style="height: 48px; left: 48px; top: 120px; position: absolute; width: 192px"/>
                        <webuijsf:staticText binding="#{Registration.staticText5}" id="staticText5" style="position: absolute; left: 48px; top: 192px" text="Major:"/>
                        <webuijsf:dropDown binding="#{Registration.ddMajor}" id="ddMajor" items="#{Registration.ddMajorDefaultOptions.options}" style="left: 96px; top: 192px; position: absolute; width: 216px"/>
                        <webuijsf:staticText binding="#{Registration.staticText6}" id="staticText6" style="position: absolute; left: 360px; top: 192px" text="Minor:"/>
                        <webuijsf:listbox binding="#{Registration.lbxMinor}" id="lbxMinor" items="#{Registration.lbxMinorDefaultOptions.options}"
                            multiple="true" rows="2" style="position: absolute; left: 432px; top: 192px"/>
                        <webuijsf:staticText binding="#{Registration.staticText8}" id="staticText8" style="position: absolute; left: 48px; top: 288px" text="Remark:"/>
                        <webuijsf:textArea binding="#{Registration.taRemarks}" id="taRemarks" style="height: 72px; left: 48px; top: 312px; position: absolute; width: 600px"/>
                        <webuijsf:button actionExpression="#{Registration.btRegister_action}" binding="#{Registration.btRegister}" id="btRegister"
                            style="left: 47px; top: 408px; position: absolute; width: 8em" text="Register"/>
                        <webuijsf:checkboxGroup binding="#{Registration.chkgHobby}" columns="3" id="chkgHobby"
                            items="#{Registration.chkgHobbyDefaultOptions.options}" label="Hobby:"
                            style="height: 24px; left: 48px; top: 240px; position: absolute; width: 360px" valueChangeListenerExpression="#{Registration.chkgHobby_processValueChange}"/>
                    </webuijsf:form>
                    <webuijsf:form binding="#{Registration.form2}" id="form2" rendered="false" style="height: 192px; left: 48px; top: 24px; position: absolute; width: 552px">
                        <webuijsf:staticText binding="#{Registration.stLastName}" id="stLastName" style="left: 72px; top: 0px; position: absolute; width: 454px"/>
                        <webuijsf:staticText binding="#{Registration.stMi}" id="stMi" style="left: 72px; top: 24px; position: absolute; width: 454px"/>
                        <webuijsf:staticText binding="#{Registration.stFirstName}" id="stFirstName" style="left: 72px; top: 48px; position: absolute; width: 454px"/>
                        <webuijsf:staticText binding="#{Registration.stMajor}" id="stMajor" style="left: 72px; top: 96px; position: absolute; width: 454px"/>
                        <webuijsf:staticText binding="#{Registration.stMinor}" id="stMinor" style="left: 72px; top: 120px; position: absolute; width: 454px"/>
                        <webuijsf:staticText binding="#{Registration.stHobby}" id="stHobby" style="height: 24px; left: 72px; top: 144px; position: absolute; width: 454px"/>
                        <webuijsf:staticText binding="#{Registration.stRemarks}" id="stRemarks" style="height: 22px; left: 72px; top: 168px; position: absolute; width: 454px"/>
                        <webuijsf:staticText binding="#{Registration.stGender}" id="stGender" style="position: absolute; left: 72px; top: 72px; width: 456px; height: 24px"/>
                    </webuijsf:form>
                </webuijsf:body>
            </webuijsf:html>
        </webuijsf:page>
    </f:view>
</jsp:root>
