import java.math.BigInteger;
import java.security.KeyFactory;
import java.security.KeyPair;
import java.security.KeyPairGenerator;
import java.security.spec.RSAKeyGenParameterSpec;
import java.security.spec.RSAPublicKeySpec;

public class Test2 {
  public static void main(String[] args) throws Exception {
    int eValue = 179;
    int bitLength = 1024; // KeySize

    BigInteger e = new BigInteger(Integer.toString(eValue));

    KeyPairGenerator kpg = KeyPairGenerator.getInstance("RSA");
    kpg.initialize(bitLength);
    KeyPair kp = kpg.generateKeyPair();

    KeyFactory kfactory = KeyFactory.getInstance("RSA");
    RSAPublicKeySpec kspec = (RSAPublicKeySpec) kfactory.getKeySpec(kp.getPublic(),
        RSAPublicKeySpec.class);

    kpg = KeyPairGenerator.getInstance("RSA", "SunRsaSign");

    e = new BigInteger(Integer.toString(eValue));
    System.out.println("e =" + e);
    RSAKeyGenParameterSpec param = new RSAKeyGenParameterSpec(bitLength, e);
    kpg.initialize(param);
    kp = kpg.generateKeyPair();

    kfactory = KeyFactory.getInstance("RSA", "SunRsaSign");

    kspec = (RSAPublicKeySpec) kfactory.getKeySpec(kp.getPublic(),RSAPublicKeySpec.class);
  }
}
