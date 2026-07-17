package com.aificraft;

public class AIFINativeEngine {
    // Sends frame data pointer to C++
    public static native void processFrame(long frameBufferPointer, int width, int height);
    
    // Tells C++ to render the AI generated frame
    public static native void renderInterpolatedFrame();
}
