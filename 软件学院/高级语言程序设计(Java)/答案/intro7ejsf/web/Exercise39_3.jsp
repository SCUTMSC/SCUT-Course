<?xml version="1.0" encoding="UTF-8"?>
<jsp:root version="1.2" xmlns:f="http://java.sun.com/jsf/core" xmlns:h="http://java.sun.com/jsf/html" xmlns:jsp="http://java.sun.com/JSP/Page" xmlns:webuijsf="http://www.sun.com/webui/webuijsf">
    <jsp:directive.page contentType="text/html;charset=UTF-8" pageEncoding="UTF-8"/>
    <f:view>
        <webuijsf:page binding="#{Exercise39_3.page1}" id="page1">
            <webuijsf:html binding="#{Exercise39_3.html1}" id="html1">
                <webuijsf:head binding="#{Exercise39_3.head1}" id="head1">
                    <webuijsf:link binding="#{Exercise39_3.link1}" id="link1" url="/resources/stylesheet.css"/>
                </webuijsf:head>
                <webuijsf:body binding="#{Exercise39_3.body1}" id="body1" style="-rave-layout: grid">
                    <webuijsf:form binding="#{Exercise39_3.form1}" id="form1">
                        <webuijsf:staticText binding="#{Exercise39_3.staticText1}" id="staticText1"
                            style="height: 22px; left: 48px; top: 48px; position: absolute; width: 70px" text="Number 1:"/>
                        <webuijsf:textField binding="#{Exercise39_3.tfNumber1}" id="tfNumber1" style="height: 24px; left: 120px; top: 48px; position: absolute; width: 72px"/>
                        <webuijsf:staticText binding="#{Exercise39_3.staticText2}" id="staticText2"
                            style="height: 24px; left: 216px; top: 48px; position: absolute; width: 72px" text="Number 2:"/>
                        <webuijsf:textField binding="#{Exercise39_3.tfNumber2}" id="tfNumber2" style="left: 288px; top: 48px; position: absolute; width: 96px"/>
                        <webuijsf:staticText binding="#{Exercise39_3.staticText3}" id="staticText3" style="left: 408px; top: 48px; position: absolute" text="Result:"/>
                        <webuijsf:textField binding="#{Exercise39_3.tfResult}" id="tfResult" style="left: 456px; top: 48px; position: absolute; width: 96px"/>
                        <webuijsf:button binding="#{Exercise39_3.btAdd}" id="btAdd" style="position: absolute; left: 48px; top: 96px; width: 72px; height: 24px" text="Add"/>
                        <webuijsf:button binding="#{Exercise39_3.btSubtract}" id="btSubtract"
                            style="height: 24px; left: 143px; top: 96px; position: absolute; width: 72px" text="Subtract"/>
                        <webuijsf:button actionExpression="#{Exercise39_3.multiply_action}" binding="#{Exercise39_3.multiply}" id="multiply"
                            style="height: 24px; left: 239px; top: 96px; position: absolute; width: 72px" text="Multiply"/>
                        <webuijsf:button binding="#{Exercise39_3.btDivide}" id="btDivide"
                            style="height: 24px; left: 335px; top: 96px; position: absolute; width: 72px" text="Divide"/>
                    </webuijsf:form>
                </webuijsf:body>
            </webuijsf:html>
        </webuijsf:page>
    </f:view>
</jsp:root>
