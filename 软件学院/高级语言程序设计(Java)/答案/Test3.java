import java.math.BigInteger;
import java.security.KeyFactory;
import java.security.KeyPair;
import java.security.KeyPairGenerator;
import java.security.spec.RSAKeyGenParameterSpec;
import java.security.spec.RSAPublicKeySpec;

import javax.crypto.Cipher;
import javax.crypto.SealedObject;

public class Test3 {
  public static void main(String[] args) throws Exception {
 // Get an instance of the RSA key generator
    KeyPairGenerator kpg = KeyPairGenerator.getInstance("RSA");
    // Generate the keys — might take sometime on slow computers
    KeyPair myPair = kpg.generateKeyPair();

 // Get an instance of the Cipher for RSA encryption/decryption
    Cipher c = Cipher.getInstance("RSA");
    // Initiate the Cipher, telling it that it is going to Encrypt, giving it the public key
    c.init(Cipher.ENCRYPT_MODE, myPair.getPublic()); 
    
    
 // Create a secret message
    String myMessage = new String("Secret Message");
    // Encrypt that message using a new SealedObject and the Cipher we created before
    SealedObject myEncyptedMessage = new SealedObject( myMessage, c);
    
 // Get an instance of the Cipher for RSA encryption/decryption
    Cipher dec = Cipher.getInstance("RSA");
    // Initiate the Cipher, telling it that it is going to Decrypt, giving it the private key
    dec.init(Cipher.DECRYPT_MODE, myPair.getPrivate());
    
 // Tell the SealedObject we created before to decrypt the data and return it
    SealedObject test = myEncyptedMessage;
    String message = (String) myEncyptedMessage.getObject(dec);
    System.out.println("foo = " + message);
    
    System.out.println(myEncyptedMessage);
  }
}
