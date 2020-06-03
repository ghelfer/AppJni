#include <jni.h>
#include <string>

extern "C" JNIEXPORT jstring JNICALL
Java_com_ghelfer_appjni_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}
extern "C"
JNIEXPORT jint JNICALL
Java_com_ghelfer_appjni_MainActivity_sumValues(JNIEnv *env, jobject thiz, jint a, jint b) {
    return a + b;
}extern "C"
JNIEXPORT jfloat JNICALL
Java_com_ghelfer_appjni_MainActivity_getFahreinheit(JNIEnv *env, jobject thiz, jfloat celcius) {

    jfloat result = celcius*1.8 + 32;
    return  result;
}extern "C"
JNIEXPORT jintArray JNICALL
Java_com_ghelfer_appjni_MainActivity_getBubbleSort(JNIEnv *env, jobject thiz, jintArray values) {
    // TODO: implement getBubbleSort()
}