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
        // Here you will eventually link ONNX runtime to read frameQueue[0] and frameQueue[1]
        // and calculate the AI interpolated frame.
    }
}

JNIEXPORT void JNICALL Java_com_aificraft_AIFINativeEngine_renderInterpolatedFrame
  (JNIEnv *env, jclass clazz) {
    
    if (frameQueue.size() == 2) {
        // Here you will inject the AI frame back into the OpenGL pipeline.
    }
}
