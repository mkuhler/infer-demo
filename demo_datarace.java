import com.facebook.infer.annotation.ThreadSafe;

@ThreadSafe
public class demo_datarace {
  private int mUnsafeVar;

  public void testThreadSafetyViolation() {
  //public synchronized void testThreadSafetyViolation() {
    setUnsafeVar();
  }

  private void setUnsafeVar() {
    mUnsafeVar = 42; // unprotected write.
  }
}