#include <jni.h>
#include "example.h"

extern "C"
JNIEXPORT jint JNICALL
Java_com_reactnativeimagecolors_ImageColorsModule_nativeMultiply(JNIEnv *env, jclass type, jint a, jint b) {
    return example::multiply(a, b);
}
