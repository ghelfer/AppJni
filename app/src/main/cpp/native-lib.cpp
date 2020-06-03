#include <jni.h>
#include <string>

extern "C" JNIEXPORT jstring JNICALL
Java_com_ghelfer_appjni_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}


extern "C" JNIEXPORT jint JNICALL
Java_com_ghelfer_appjni_MainActivity_sumValues(JNIEnv *env, jobject thiz, jint a, jint b) {
    return a + b;
}extern "C"

JNIEXPORT jfloat JNICALL
Java_com_ghelfer_appjni_MainActivity_getFahreinheit(JNIEnv *env, jobject thiz, jfloat celcius) {

    jfloat result = celcius*1.8 + 32;
    return  result;
}

extern "C" JNIEXPORT jintArray JNICALL
Java_com_ghelfer_appjni_MainActivity_getBubbleSort(JNIEnv *env, jobject thiz, jintArray values) {
    const jsize TAM = env->GetArrayLength(values);
    jint *array = env->GetIntArrayElements(values, NULL);
    jintArray newArray = env->NewIntArray(TAM);

    jint i = 0, j = 0,  aux = 0,  k = TAM - 1 ;

    for(i = 0; i < TAM; i++)    {
        for(j = 0; j < k; j++)        {
            if(array[j] > array[j+1])            {
                aux = array[j];
                array[j] = array[j+1];
                array[j+1]=aux;
            }
        }
        k--;
    }
    env->SetIntArrayRegion(newArray, 0, TAM, array);

    return newArray;
}