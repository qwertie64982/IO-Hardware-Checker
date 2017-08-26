/**
 * SUMMARY:
 * This program shows what buttons are pressed,
 * as well as the coordinates for the c-stick and touchscreen.
 * 
 * FILENAMES:
 * Source: main.cpp
 * 
 * Maxwell Sherman (Qwertie64982)
 * v0.1.0
 * 21 August 2017
 */

#include <3ds.h>
#include <stdio.h>

int main(int argc, char **argv) {
    gfxInitDefault();
    
    PrintConsole topScreen, bottomScreen;
    consoleInit(GFX_TOP, &topScreen);
    consoleInit(GFX_BOTTOM, &bottomScreen);
    
    consoleSelect(&topScreen);
    
    // Circle Pad
    printf("\x1b[8;3HO");
    printf("\x1b[9;2HO");
    printf("\x1b[9;4HO");
    printf("\x1b[10;3HO");
    
    printf("\x1b[8;6HX: ");
    printf("\x1b[9;6HY: ");
    
    // D-Pad
    printf("\x1b[15;3HU");
    printf("\x1b[16;2HL");
    printf("\x1b[16;4HR");
    printf("\x1b[17;3HD");
    
    // C-Stick
    printf("\x1b[4;45H.");
    printf("\x1b[5;44H.");
    printf("\x1b[5;46H.");
    printf("\x1b[6;45H.");
    
    // A, B, X, Y
    printf("\x1b[11;48HA");
    printf("\x1b[12;47HB");
    printf("\x1b[10;47HX");
    printf("\x1b[11;46HY");
    
    // L, R, ZL, ZR
    printf("\x1b[2;18HL");
    printf("\x1b[2;31HR");
    printf("\x1b[2;21HZL");
    printf("\x1b[2;27HZR");
    
    // Start, Select
    printf("\x1b[20;41H* Start");
    printf("\x1b[21;41H* Select");
    
    // Touch Screen
    printf("\x1b[7;21HTouch: ");
    printf("\x1b[8;21HX: ");
    printf("\x1b[9;21HY: ");

    while(aptMainLoop()) {
        gspWaitForVBlank();
        
        // Read circle pad input
        circlePosition circle;
        hidCircleRead(&circle);
        
        // Read touchscreen input
        touchPosition touch;
        hidTouchRead(&touch);
        
        // Read buttons input
        hidScanInput();
        
        // Store button states in u32s
        u32 keysPressed = hidKeysDown();
        u32 keysReleased = hidKeysUp();
        u32 keysHeldDown = hidKeysHeld();
        
        consoleSelect(&topScreen);
        
        // Circle Pad
        // todo: make an actual animation of cpad movement
        if (keysPressed & KEY_CPAD_UP) {
            printf("\x1b[8;3H\x1b[32mO");
        } else if (keysReleased & KEY_CPAD_UP) {
            printf("\x1b[8;3H\x1b[37mO");
        }
        if (keysPressed & KEY_CPAD_LEFT) {
            printf("\x1b[9;2H\x1b[32mO");
        } else if (keysReleased & KEY_CPAD_LEFT) {
            printf("\x1b[9;2H\x1b[37mO");
        }
        if (keysPressed & KEY_CPAD_RIGHT) {
            printf("\x1b[9;4H\x1b[32mO");
        } else if (keysReleased & KEY_CPAD_RIGHT) {
            printf("\x1b[9;4H\x1b[37mO");
        }
        if (keysPressed & KEY_CPAD_DOWN) {
            printf("\x1b[10;3H\x1b[32mO");
        } else if (keysReleased & KEY_CPAD_DOWN) {
            printf("\x1b[10;3H\x1b[37mO");
        }
        
        printf("\x1b[37m"); // Set color to white for coordinates
        printf("\x1b[8;9H%04d%%", int(circle.dx / 1.55));
        printf("\x1b[9;9H%04d%%", int(circle.dy / 1.55));
        
        // D-Pad
        if (keysPressed & KEY_DUP) {
            printf("\x1b[15;3H\x1b[32mU");
        } else if (keysReleased & KEY_DUP) {
            printf("\x1b[15;3H\x1b[37mU");
        }
        if (keysPressed & KEY_DLEFT) {
            printf("\x1b[16;2H\x1b[32mL");
        } else if (keysReleased & KEY_DLEFT) {
            printf("\x1b[16;2H\x1b[37mL");
        }
        if (keysPressed & KEY_DRIGHT) {
            printf("\x1b[16;4H\x1b[32mR");
        } else if (keysReleased & KEY_DRIGHT) {
            printf("\x1b[16;4H\x1b[37mR");
        }
        if (keysPressed & KEY_DDOWN) {
            printf("\x1b[17;3H\x1b[32mD");
        } else if (keysReleased & KEY_DDOWN) {
            printf("\x1b[17;3H\x1b[37mD");
        }
        
        // C-Stick
        if (keysPressed & KEY_CSTICK_UP) {
            printf("\x1b[4;45H\x1b[32m.");
        } else if (keysReleased & KEY_CSTICK_UP) {
            printf("\x1b[4;45H\x1b[37m.");
        }
        if (keysPressed & KEY_CSTICK_LEFT) {
            printf("\x1b[5;44H\x1b[32m.");
        } else if (keysReleased & KEY_CSTICK_LEFT) {
            printf("\x1b[5;44H\x1b[37m.");
        }
        if (keysPressed & KEY_CSTICK_RIGHT) {
            printf("\x1b[5;46H\x1b[32m.");
        } else if (keysReleased & KEY_CSTICK_RIGHT) {
            printf("\x1b[5;46H\x1b[37m.");
        }
        if (keysPressed & KEY_CSTICK_DOWN) {
            printf("\x1b[6;45H\x1b[32m.");
        } else if (keysReleased & KEY_CSTICK_DOWN) {
            printf("\x1b[6;45H\x1b[37m.");
        }
        
        // A, B, X, Y
        if (keysPressed & KEY_A) {
            printf("\x1b[11;48H\x1b[32mA");
        } else if (keysReleased & KEY_A) {
            printf("\x1b[11;48H\x1b[37mA");
        }
        if (keysPressed & KEY_B) {
            printf("\x1b[12;47H\x1b[32mB");
        } else if (keysReleased & KEY_B) {
            printf("\x1b[12;47H\x1b[37mB");
        }
        if (keysPressed & KEY_X) {
            printf("\x1b[10;47H\x1b[32mX");
        } else if (keysReleased & KEY_X) {
            printf("\x1b[10;47H\x1b[37mX");
        }
        if (keysPressed & KEY_Y) {
            printf("\x1b[11;46H\x1b[32mY");
        } else if (keysReleased & KEY_Y) {
            printf("\x1b[11;46H\x1b[37mY");
        }
        
        // L, R, ZL, ZR
        if (keysPressed & KEY_L) {
            printf("\x1b[2;18H\x1b[32mL");
        } else if (keysReleased & KEY_L) {
            printf("\x1b[2;18H\x1b[37mL");
        }
        if (keysPressed & KEY_R) {
            printf("\x1b[2;31H\x1b[32mR");
        } else if (keysReleased & KEY_R) {
            printf("\x1b[2;31H\x1b[37mR");
        }
        if (keysPressed & KEY_ZL) {
            printf("\x1b[2;21H\x1b[32mZL");
        } else if (keysReleased & KEY_ZL) {
            printf("\x1b[2;21H\x1b[37mZL");
        }
        if (keysPressed & KEY_ZR) {
            printf("\x1b[2;27H\x1b[32mZR");
        } else if (keysReleased & KEY_ZR) {
            printf("\x1b[2;27H\x1b[37mZR");
        }
        
        // Start, Select
        if (keysPressed & KEY_START) {
            printf("\x1b[20;41H\x1b[32m*");
        } else if (keysReleased & KEY_START) {
            printf("\x1b[20;41H\x1b[37m*");
        }
        if (keysPressed & KEY_SELECT) {
            printf("\x1b[21;41H\x1b[32m*");
        } else if (keysReleased & KEY_SELECT) {
            printf("\x1b[21;41H\x1b[37m*");
        }
        
        // Touch Screen
        printf("\x1b[8;24H%04d", int(touch.px));
        printf("\x1b[9;24H%04d", int(touch.py));
        
        gfxFlushBuffers();
        gfxSwapBuffers();
    }

    gfxExit();
    return 0;
}
