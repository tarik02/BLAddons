#include <jni.h>
#include <dlfcn.h>
#include <android/log.h>
#include <stdlib.h>
#include "Substrate.h"

#define LOG_TAG "net.caborambo.addon.customitem"
#define LOGI(...) ((void)__android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__))

JNIEXPORT jint JNI_OnLoad(JavaVM* vm, void* reserved) {
	return JNI_VERSION_1_2;
}
