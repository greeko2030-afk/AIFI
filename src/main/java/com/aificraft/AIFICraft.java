package com.aificraft;

import net.fabricmc.api.ClientModInitializer;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

import java.io.File;
import java.io.InputStream;
import java.nio.file.Files;
import java.nio.file.StandardCopyOption;

public class AIFICraft implements ClientModInitializer {
    public static final Logger LOGGER = LoggerFactory.getLogger("AIFI-Craft");

    @Override
    public void onInitializeClient() {
        LOGGER.info("Starting AIFI-Craft: AI Frame Interpolation Init");
        extractAndLoadNativeLibrary();
    }

    private void extractAndLoadNativeLibrary() {
        try {
            InputStream in = getClass().getResourceAsStream("/natives/aifi_engine.dll");
            if (in == null) {
                LOGGER.error("aifi_engine.dll not found in mod resources!");
                return;
            }
            File tempFile = File.createTempFile("aifi_engine", ".dll");
            tempFile.deleteOnExit();
            Files.copy(in, tempFile.toPath(), StandardCopyOption.REPLACE_EXISTING);
            
            System.load(tempFile.getAbsolutePath());
            LOGGER.info("AIFI Native Engine Hooked Successfully.");
        } catch (Exception e) {
            LOGGER.error("Failed to inject native AI engine: ", e);
        }
    }
}
