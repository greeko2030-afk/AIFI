#include <jni.h>

#ifndef _Included_com_aificraft_AIFINativeEngine
#define _Included_com_aificraft_AIFINativeEngine
#ifdef __cplusplus
extern "C" {
#endif

JNIEXPORT void JNICALL Java_com_aificraft_AIFINativeEngine_processFrame
  (JNIEnv *, jclass, jlong, jint, jint);

JNIEXPORT void JNICALL Java_com_aificraft_AIFINativeEngine_renderInterpolatedFrame
  (JNIEnv *, jclass);

#ifdef __cplusplus
}
#endif
#endif
