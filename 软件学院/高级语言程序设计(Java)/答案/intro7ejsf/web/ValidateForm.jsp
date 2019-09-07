<?xml version="1.0" encoding="UTF-8"?>
<jsp:root version="1.2" xmlns:f="http://java.sun.com/jsf/core" xmlns:h="http://java.sun.com/jsf/html" xmlns:jsp="http://java.sun.com/JSP/Page" xmlns:webuijsf="http://www.sun.com/webui/webuijsf">
    <jsp:directive.page contentType="text/html;charset=UTF-8" pageEncoding="UTF-8"/>
    <f:view>
        <webuijsf:page binding="#{ValidateForm.page1}" id="page1">
            <webuijsf:html binding="#{ValidateForm.html1}" id="html1">
                <webuijsf:head binding="#{ValidateForm.head1}" id="head1">
                    <webuijsf:link binding="#{ValidateForm.link1}" id="link1" url="/resources/stylesheet.css"/>
                </webuijsf:head>
                <webuijsf:body binding="#{ValidateForm.body1}" id="body1" style="-rave-layout: grid">
                    <webuijsf:form binding="#{ValidateForm.form1}" id="form1">
                        <h:panelGrid binding="#{ValidateForm.gridPanel1}" columns="2" id="gridPanel1"
                            style="height: 144px; left: 48px; top: 24px; position: absolute" width="240">
                            <webuijsf:staticText binding="#{ValidateForm.staticText1}" id="staticText1" text="Name:"/>
                            <webuijsf:textField binding="#{ValidateForm.tfName}" id="tfName" required="true" validatorExpression="#{ValidateForm.lengthValidator1.validate}"/>
                            <webuijsf:staticText binding="#{ValidateForm.staticText4}" id="staticText4" text="SSN:"/>
                            <webuijsf:textField binding="#{ValidateForm.tfSSN}" id="tfSSN" required="true" validatorExpression="#{ValidateForm.tfSSN_validate}"/>
                            <webuijsf:staticText binding="#{ValidateForm.staticText3}" id="staticText3" text="Age:"/>
                            <webuijsf:textField binding="#{ValidateForm.tfAge}" id="tfAge" required="true"/>
                            <webuijsf:staticText binding="#{ValidateForm.staticText2}" id="staticText2" text="Height:"/>
                            <webuijsf:textField binding="#{ValidateForm.tfHeight}" id="tfHeight" required="true"/>
                            <webuijsf:button actionExpression="#{ValidateForm.button1_action}" binding="#{ValidateForm.button1}" id="button1" text="Sumbit"/>
                        </h:panelGrid>
                        <webuijsf:staticText binding="#{ValidateForm.stResult}" escape="false" id="stResult" style="position: absolute; left: 48px; top: 192px; width: 240px; height: 96px"/>
                        <h:panelGrid binding="#{ValidateForm.gridPanel2}" id="gridPanel2" style="height: 120px; left: 288px; top: 24px; position: absolute" width="336">
                            <webuijsf:message binding="#{ValidateForm.message1}" for="tfName" id="message1" showDetail="false" showSummary="true"/>
                            <webuijsf:message binding="#{ValidateForm.message2}" for="tfSSN" id="message2" showDetail="false" showSummary="true"/>
                            <webuijsf:message binding="#{ValidateForm.message3}" for="tfAge" id="message3" showDetail="false" showSummary="true"/>
                            <webuijsf:message binding="#{ValidateForm.message4}" for="tfHeight" id="message4" showDetail="false" showSummary="true"/>
                        </h:panelGrid>
                    </webuijsf:form>
                </webuijsf:body>
            </webuijsf:html>
        </webuijsf:page>
    </f:view>
</jsp:root>
