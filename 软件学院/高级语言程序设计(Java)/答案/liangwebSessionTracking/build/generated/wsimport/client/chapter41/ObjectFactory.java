
package chapter41;

import javax.xml.bind.JAXBElement;
import javax.xml.bind.annotation.XmlElementDecl;
import javax.xml.bind.annotation.XmlRegistry;
import javax.xml.namespace.QName;


/**
 * This object contains factory methods for each 
 * Java content interface and Java element interface 
 * generated in the chapter41 package. 
 * <p>An ObjectFactory allows you to programatically 
 * construct new instances of the Java representation 
 * for XML content. The Java representation of XML 
 * content can consist of schema derived interfaces 
 * and classes representing the binding of schema 
 * type definitions, element declarations and model 
 * groups.  Factory methods for each of these are 
 * provided in this class.
 * 
 */
@XmlRegistry
public class ObjectFactory {

    private final static QName _StoreAddressInSession_QNAME = new QName("http://chapter41/", "storeAddressInSession");
    private final static QName _GetAddress_QNAME = new QName("http://chapter41/", "getAddress");
    private final static QName _StoreAddressInSessionResponse_QNAME = new QName("http://chapter41/", "storeAddressInSessionResponse");
    private final static QName _StoreAddressResponse_QNAME = new QName("http://chapter41/", "storeAddressResponse");
    private final static QName _GetAddressResponse_QNAME = new QName("http://chapter41/", "getAddressResponse");
    private final static QName _StoreAddress_QNAME = new QName("http://chapter41/", "storeAddress");

    /**
     * Create a new ObjectFactory that can be used to create new instances of schema derived classes for package: chapter41
     * 
     */
    public ObjectFactory() {
    }

    /**
     * Create an instance of {@link Address }
     * 
     */
    public Address createAddress() {
        return new Address();
    }

    /**
     * Create an instance of {@link StoreAddressInSessionResponse }
     * 
     */
    public StoreAddressInSessionResponse createStoreAddressInSessionResponse() {
        return new StoreAddressInSessionResponse();
    }

    /**
     * Create an instance of {@link StoreAddressResponse }
     * 
     */
    public StoreAddressResponse createStoreAddressResponse() {
        return new StoreAddressResponse();
    }

    /**
     * Create an instance of {@link StoreAddressInSession }
     * 
     */
    public StoreAddressInSession createStoreAddressInSession() {
        return new StoreAddressInSession();
    }

    /**
     * Create an instance of {@link GetAddress }
     * 
     */
    public GetAddress createGetAddress() {
        return new GetAddress();
    }

    /**
     * Create an instance of {@link StoreAddress }
     * 
     */
    public StoreAddress createStoreAddress() {
        return new StoreAddress();
    }

    /**
     * Create an instance of {@link GetAddressResponse }
     * 
     */
    public GetAddressResponse createGetAddressResponse() {
        return new GetAddressResponse();
    }

    /**
     * Create an instance of {@link JAXBElement }{@code <}{@link StoreAddressInSession }{@code >}}
     * 
     */
    @XmlElementDecl(namespace = "http://chapter41/", name = "storeAddressInSession")
    public JAXBElement<StoreAddressInSession> createStoreAddressInSession(StoreAddressInSession value) {
        return new JAXBElement<StoreAddressInSession>(_StoreAddressInSession_QNAME, StoreAddressInSession.class, null, value);
    }

    /**
     * Create an instance of {@link JAXBElement }{@code <}{@link GetAddress }{@code >}}
     * 
     */
    @XmlElementDecl(namespace = "http://chapter41/", name = "getAddress")
    public JAXBElement<GetAddress> createGetAddress(GetAddress value) {
        return new JAXBElement<GetAddress>(_GetAddress_QNAME, GetAddress.class, null, value);
    }

    /**
     * Create an instance of {@link JAXBElement }{@code <}{@link StoreAddressInSessionResponse }{@code >}}
     * 
     */
    @XmlElementDecl(namespace = "http://chapter41/", name = "storeAddressInSessionResponse")
    public JAXBElement<StoreAddressInSessionResponse> createStoreAddressInSessionResponse(StoreAddressInSessionResponse value) {
        return new JAXBElement<StoreAddressInSessionResponse>(_StoreAddressInSessionResponse_QNAME, StoreAddressInSessionResponse.class, null, value);
    }

    /**
     * Create an instance of {@link JAXBElement }{@code <}{@link StoreAddressResponse }{@code >}}
     * 
     */
    @XmlElementDecl(namespace = "http://chapter41/", name = "storeAddressResponse")
    public JAXBElement<StoreAddressResponse> createStoreAddressResponse(StoreAddressResponse value) {
        return new JAXBElement<StoreAddressResponse>(_StoreAddressResponse_QNAME, StoreAddressResponse.class, null, value);
    }

    /**
     * Create an instance of {@link JAXBElement }{@code <}{@link GetAddressResponse }{@code >}}
     * 
     */
    @XmlElementDecl(namespace = "http://chapter41/", name = "getAddressResponse")
    public JAXBElement<GetAddressResponse> createGetAddressResponse(GetAddressResponse value) {
        return new JAXBElement<GetAddressResponse>(_GetAddressResponse_QNAME, GetAddressResponse.class, null, value);
    }

    /**
     * Create an instance of {@link JAXBElement }{@code <}{@link StoreAddress }{@code >}}
     * 
     */
    @XmlElementDecl(namespace = "http://chapter41/", name = "storeAddress")
    public JAXBElement<StoreAddress> createStoreAddress(StoreAddress value) {
        return new JAXBElement<StoreAddress>(_StoreAddress_QNAME, StoreAddress.class, null, value);
    }

}
