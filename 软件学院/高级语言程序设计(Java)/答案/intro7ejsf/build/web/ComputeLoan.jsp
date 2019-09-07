<?xml version="1.0" encoding="UTF-8"?>
<jsp:root version="1.2" xmlns:f="http://java.sun.com/jsf/core" xmlns:h="http://java.sun.com/jsf/html" xmlns:jsp="http://java.sun.com/JSP/Page" xmlns:webuijsf="http://www.sun.com/webui/webuijsf">
    <jsp:directive.page contentType="text/html;charset=UTF-8" pageEncoding="UTF-8"/>
    <f:view>
        <webuijsf:page binding="#{ComputeLoan.page1}" id="page1">
            <webuijsf:html binding="#{ComputeLoan.html1}" id="html1">
                <webuijsf:head binding="#{ComputeLoan.head1}" id="head1">
                    <webuijsf:link binding="#{ComputeLoan.link1}" id="link1" url="/resources/stylesheet.css"/>
                </webuijsf:head>
                <webuijsf:body binding="#{ComputeLoan.body1}" id="body1" style="-rave-layout: grid">
                    <webuijsf:form binding="#{ComputeLoan.form1}" id="form1">
                        <h:panelGrid binding="#{ComputeLoan.gridPanel1}" columns="2" id="gridPanel1"
                            style="height: 120px; left: 48px; top: 24px; position: absolute" width="288">
                            <webuijsf:staticText binding="#{ComputeLoan.staticText1}" id="staticText1" text="Loan Amount:"/>
                            <webuijsf:textField binding="#{ComputeLoan.tfLoanAmount}" id="tfLoanAmount"/>
                            <webuijsf:staticText binding="#{ComputeLoan.staticText3}" id="staticText3" text="Number of Year:"/>
                            <webuijsf:textField binding="#{ComputeLoan.tfNumberOfYears}" id="tfNumberOfYears"/>
                            <webuijsf:staticText binding="#{ComputeLoan.staticText4}" id="staticText4" text="Annual Interest Rate:"/>
                            <webuijsf:textField binding="#{ComputeLoan.tfAnnualInterestRate}" id="tfAnnualInterestRate"/>
                            <webuijsf:button actionExpression="#{ComputeLoan.btComputeLoan_action}" binding="#{ComputeLoan.btComputeLoan}" id="btComputeLoan" text="Compute Loan"/>
                        </h:panelGrid>
                        <h:panelGrid binding="#{ComputeLoan.gridPanel2}" columns="2" id="gridPanel2" rendered="false"
                            style="height: 72px; left: 48px; top: 168px; position: absolute" width="288">
                            <webuijsf:staticText binding="#{ComputeLoan.staticText5}" id="staticText5" text="Monthly Payment:"/>
                            <webuijsf:textField binding="#{ComputeLoan.tfMonthlyPayment}" id="tfMonthlyPayment"/>
                            <webuijsf:staticText binding="#{ComputeLoan.staticText6}" id="staticText6" text="Total Payment:"/>
                            <webuijsf:textField binding="#{ComputeLoan.tfTotalPayment}" id="tfTotalPayment"/>
                        </h:panelGrid>
                    </webuijsf:form>
                </webuijsf:body>
            </webuijsf:html>
        </webuijsf:page>
    </f:view>
</jsp:root>
