#include <jni.h>
#include "example.h"

extern "C"
JNIEXPORT void JNICALL
Java_com_reactnativeimagecolors_ImageColorsModule_nativeInstall(JNIEnv *env, jobject thiz,
                                                                jlong jsi_ptr) {
    auto runtime = reinterpret_cast<facebook::jsi::Runtime *>(jsi_ptr);

    if (runtime) {
        installImageColors(*runtime);
    }
}

extern "C"
JNIEXPORT void JNICALL
Java_com_reactnativeimagecolors_ImageColorsModule_invalidate(JNIEnv *env, jobject thiz,
                                                             jlong jsi_ptr) {
    cleanUpImageColors();
}
