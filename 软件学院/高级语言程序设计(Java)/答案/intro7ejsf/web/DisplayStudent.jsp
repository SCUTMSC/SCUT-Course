<?xml version="1.0" encoding="UTF-8"?>
<jsp:root version="1.2" xmlns:f="http://java.sun.com/jsf/core" xmlns:h="http://java.sun.com/jsf/html" xmlns:jsp="http://java.sun.com/JSP/Page" xmlns:webuijsf="http://www.sun.com/webui/webuijsf">
    <jsp:directive.page contentType="text/html;charset=UTF-8" pageEncoding="UTF-8"/>
    <f:view>
        <webuijsf:page binding="#{DisplayStudent.page1}" id="page1">
            <webuijsf:html binding="#{DisplayStudent.html1}" id="html1">
                <webuijsf:head binding="#{DisplayStudent.head1}" id="head1">
                    <webuijsf:link binding="#{DisplayStudent.link1}" id="link1" url="/resources/stylesheet.css"/>
                </webuijsf:head>
                <webuijsf:body binding="#{DisplayStudent.body1}" id="body1" style="-rave-layout: grid">
                    <webuijsf:form binding="#{DisplayStudent.form1}" id="form1">
                        <webuijsf:staticText binding="#{DisplayStudent.staticText1}" id="staticText1"
                            style="height: 24px; left: 24px; top: 24px; position: absolute; width: 118px" text="Choose a course:"/>
                        <webuijsf:dropDown binding="#{DisplayStudent.ddCourse}" id="ddCourse"
                            items="#{DisplayStudent.courseDataProvider.options['course.courseId,course.title']}" style="height: 24px; left: 168px; top: 24px; position: absolute; width: 216px"/>
                        <webuijsf:button actionExpression="#{DisplayStudent.btDisplayStudent_action}" binding="#{DisplayStudent.btDisplayStudent}"
                            id="btDisplayStudent" style="height: 24px; left: 407px; top: 24px; position: absolute; width: 120px" text="Display Student"/>
                        <webuijsf:table augmentTitle="false" binding="#{DisplayStudent.tbStudent}" id="tbStudent" rendered="false"
                            style="height: 216px; left: 24px; top: 72px; position: absolute" title="Table" width="768">
                            <webuijsf:tableRowGroup binding="#{DisplayStudent.tableRowGroup1}" id="tableRowGroup1" rows="5"
                                sourceData="#{DisplayStudent.studentDataProvider}" sourceVar="currentRow">
                                <webuijsf:tableColumn binding="#{DisplayStudent.tableColumn1}" headerText="ssn" id="tableColumn1" sort="student.ssn">
                                    <webuijsf:staticText binding="#{DisplayStudent.staticText2}" id="staticText2" text="#{currentRow.value['student.ssn']}"/>
                                </webuijsf:tableColumn>
                                <webuijsf:tableColumn binding="#{DisplayStudent.tableColumn2}" headerText="firstName" id="tableColumn2" sort="student.firstName">
                                    <webuijsf:staticText binding="#{DisplayStudent.staticText3}" id="staticText3" text="#{currentRow.value['student.firstName']}"/>
                                </webuijsf:tableColumn>
                                <webuijsf:tableColumn binding="#{DisplayStudent.tableColumn3}" headerText="mi" id="tableColumn3" sort="student.mi">
                                    <webuijsf:staticText binding="#{DisplayStudent.staticText4}" id="staticText4" text="#{currentRow.value['student.mi']}"/>
                                </webuijsf:tableColumn>
                                <webuijsf:tableColumn binding="#{DisplayStudent.tableColumn4}" headerText="lastName" id="tableColumn4" sort="student.lastName">
                                    <webuijsf:staticText binding="#{DisplayStudent.staticText5}" id="staticText5" text="#{currentRow.value['student.lastName']}"/>
                                </webuijsf:tableColumn>
                                <webuijsf:tableColumn binding="#{DisplayStudent.tableColumn5}" headerText="phone" id="tableColumn5" sort="student.phone">
                                    <webuijsf:staticText binding="#{DisplayStudent.staticText6}" id="staticText6" text="#{currentRow.value['student.phone']}"/>
                                </webuijsf:tableColumn>
                                <webuijsf:tableColumn binding="#{DisplayStudent.tableColumn6}" headerText="birthDate" id="tableColumn6" sort="student.birthDate">
                                    <webuijsf:staticText binding="#{DisplayStudent.staticText7}" id="staticText7" text="#{currentRow.value['student.birthDate']}"/>
                                </webuijsf:tableColumn>
                                <webuijsf:tableColumn binding="#{DisplayStudent.tableColumn7}" headerText="street" id="tableColumn7" sort="student.street">
                                    <webuijsf:staticText binding="#{DisplayStudent.staticText8}" id="staticText8" text="#{currentRow.value['student.street']}"/>
                                </webuijsf:tableColumn>
                                <webuijsf:tableColumn binding="#{DisplayStudent.tableColumn8}" headerText="zipCode" id="tableColumn8" sort="student.zipCode">
                                    <webuijsf:staticText binding="#{DisplayStudent.staticText9}" id="staticText9" text="#{currentRow.value['student.zipCode']}"/>
                                </webuijsf:tableColumn>
                                <webuijsf:tableColumn binding="#{DisplayStudent.tableColumn9}" headerText="deptId" id="tableColumn9" sort="student.deptId">
                                    <webuijsf:staticText binding="#{DisplayStudent.staticText10}" id="staticText10" text="#{currentRow.value['student.deptId']}"/>
                                </webuijsf:tableColumn>
                            </webuijsf:tableRowGroup>
                        </webuijsf:table>
                        <webuijsf:messageGroup binding="#{DisplayStudent.messageGroup1}" id="messageGroup1" style="left: 552px; top: 24px; position: absolute"/>
                    </webuijsf:form>
                </webuijsf:body>
            </webuijsf:html>
        </webuijsf:page>
    </f:view>
</jsp:root>
