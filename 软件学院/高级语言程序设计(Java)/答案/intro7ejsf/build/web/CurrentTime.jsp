<?xml version="1.0" encoding="UTF-8"?>
<jsp:root version="1.2" xmlns:f="http://java.sun.com/jsf/core" xmlns:h="http://java.sun.com/jsf/html" xmlns:jsp="http://java.sun.com/JSP/Page" xmlns:webuijsf="http://www.sun.com/webui/webuijsf">
    <jsp:directive.page contentType="text/html;charset=UTF-8" pageEncoding="UTF-8"/>
    <f:view>
        <webuijsf:page binding="#{CurrentTime.page1}" id="page1">
            <webuijsf:html binding="#{CurrentTime.html1}" id="html1">
                <webuijsf:head binding="#{CurrentTime.head1}" id="head1">
                    <webuijsf:link binding="#{CurrentTime.link1}" id="link1" url="/resources/stylesheet.css"/>
                </webuijsf:head>
                <webuijsf:body binding="#{CurrentTime.body1}" id="body1" style="-rave-layout: grid">
                    <webuijsf:form binding="#{CurrentTime.form1}" id="form1">
                        <webuijsf:staticText binding="#{CurrentTime.staticText1}" id="staticText1"
                            style="height: 24px; left: 24px; top: 48px; position: absolute; width: 190px" text="Current time on the server is:"/>
                        <webuijsf:staticText binding="#{CurrentTime.stCurrentTime}" id="stCurrentTime" style="height: 22px; left: 240px; top: 48px; position: absolute; width: 216px"/>
                        <webuijsf:staticText binding="#{CurrentTime.stURLParameter}" id="stURLParameter" style="position: absolute; left: 24px; top: 120px; width: 480px; height: 24px"/>
                    </webuijsf:form>
                </webuijsf:body>
            </webuijsf:html>
        </webuijsf:page>
    </f:view>
</jsp:root>
