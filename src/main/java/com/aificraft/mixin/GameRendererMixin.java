package com.aificraft.mixin;

import com.aificraft.AIFINativeEngine;
import net.minecraft.client.render.GameRenderer;
import org.spongepowered.asm.mixin.Mixin;
import org.spongepowered.asm.mixin.injection.At;
import org.spongepowered.asm.mixin.injection.Inject;
import org.spongepowered.asm.mixin.injection.callback.CallbackInfo;

@Mixin(GameRenderer.class)
public class GameRendererMixin {

    @Inject(method = "render", at = @At("TAIL"))
    private void onRender(float tickDelta, long startTime, boolean tick, CallbackInfo ci) {
        long fboPointer = 0; 
        int currentWidth = 1920; 
        int currentHeight = 1080;

        try {
            AIFINativeEngine.processFrame(fboPointer, currentWidth, currentHeight);
            AIFINativeEngine.renderInterpolatedFrame();
        } catch (UnsatisfiedLinkError e) {
            // DLL might not be loaded yet, safely ignore
        }
    }
}
