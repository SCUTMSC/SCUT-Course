<?xml version="1.0" encoding="UTF-8"?>
<jsp:root version="1.2" xmlns:f="http://java.sun.com/jsf/core" xmlns:h="http://java.sun.com/jsf/html" xmlns:jsp="http://java.sun.com/JSP/Page" xmlns:webuijsf="http://www.sun.com/webui/webuijsf">
    <jsp:directive.page contentType="text/html;charset=UTF-8" pageEncoding="UTF-8"/>
    <f:view>
        <webuijsf:page binding="#{GuessNumber.page1}" id="page1">
            <webuijsf:html binding="#{GuessNumber.html1}" id="html1">
                <webuijsf:head binding="#{GuessNumber.head1}" id="head1">
                    <webuijsf:link binding="#{GuessNumber.link1}" id="link1" url="/resources/stylesheet.css"/>
                </webuijsf:head>
                <webuijsf:body binding="#{GuessNumber.body1}" id="body1" style="-rave-layout: grid">
                    <webuijsf:form binding="#{GuessNumber.form1}" id="form1">
                        <webuijsf:staticText binding="#{GuessNumber.staticText1}" id="staticText1" style="left: 24px; top: 24px; position: absolute" text="Enter a guess:"/>
                        <webuijsf:textField binding="#{GuessNumber.tfGuess}" id="tfGuess" style="position: absolute; left: 120px; top: 24px; width: 96px; height: 24px"/>
                        <webuijsf:button actionExpression="#{GuessNumber.btGuess_action}" binding="#{GuessNumber.btGuess}" id="btGuess"
                            style="height: 24px; left: 240px; top: 24px; position: absolute; width: 95px" text="Guess"/>
                        <webuijsf:staticText binding="#{GuessNumber.stResponse}" id="stResponse" style="position: absolute; left: 24px; top: 72px; width: 312px; height: 24px"/>
                    </webuijsf:form>
                </webuijsf:body>
            </webuijsf:html>
        </webuijsf:page>
    </f:view>
</jsp:root>
