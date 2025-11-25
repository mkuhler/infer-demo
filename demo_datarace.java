import com.facebook.infer.annotation.ThreadSafe;
/* 
* HOW TO RUN TESTS:
* infer --racerd-only -- javac -cp lib/infer-annotation-0.18.0.jar -d build demo_datarace.java
* infer --racerd -- javac -cp lib/infer-annotation-0.18.0.jar -d build demo_datarace.java
* infer --no-racerd -- javac -cp lib/infer-annotation-0.18.0.jar -d build demo_datarace.java
*/

/*
* ANNOTATIONS
* Annotations in Infer specify properties to their compiler
* in this case, the ThreadSafe annotation tells Infer that
* this class needs to be thread safe, otherwise exception.
*/
@ThreadSafe
public class demo_datarace {
  private int mUnsafeVar;

  public void testThreadSafetyViolation() {
  /* 
  * FIX: THREAD SAFETY VIOLATION
  * The synchronized keyword in Java resolves this issue and
  * achieves thread safety. It enforces mutual exclusion - 
  * only one thread can execute a synchronized block at a time.
  */
  //public synchronized void testThreadSafetyViolation() {

    setUnsafeVar();
  }

  private void setUnsafeVar() {
    mUnsafeVar = 42; // unprotected write.
  }
}