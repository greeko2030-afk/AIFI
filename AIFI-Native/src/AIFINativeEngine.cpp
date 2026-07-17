// Fix: Simply include the file since it is now in the exact same folder
#include "com_aificraft_AIFINativeEngine.h"
#include <iostream>
#include <vector>

struct FrameData {
    long pointer;
    int width;
    int height;
};

std::vector<FrameData> frameQueue;

JNIEXPORT void JNICALL Java_com_aificraft_AIFINativeEngine_processFrame
  (JNIEnv *env, jclass clazz, jlong framePointer, jint width, jint height) {
    
    FrameData currentFrame = {framePointer, width, height};
    frameQueue.push_back(currentFrame);

    if (frameQueue.size() > 2) {
        frameQueue.erase(frameQueue.begin());
    }

    if (frameQueue.size() == 2) {
        // AI interpolation logic will go here
    }
}

JNIEXPORT void JNICALL Java_com_aificraft_AIFINativeEngine_renderInterpolatedFrame
  (JNIEnv *env, jclass clazz) {
    
    if (frameQueue.size() == 2) {
        // OpenGL injection logic will go here
    }
}
