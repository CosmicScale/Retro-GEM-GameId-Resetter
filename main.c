#include <gsKit.h>
#include <string.h>
#include <stdint.h>

// Function to calculate CRC
static uint8_t gameid_calc_crc(const uint8_t *data, int len) {
    uint8_t crc = 0x00;
    for (int i = 0; i < len; i++) {
        crc += data[i];
    }
    return 0x100 - crc;
}

// Function to draw game ID using GSKit
void gameid_draw_auto(GSGLOBAL *gsGlobal, int screenWidth, int screenHeight, const char* game_id) {
    uint8_t data[64] = { 0 };
    int gidlen = strnlen(game_id, 11);  // Ensure the length does not exceed 11 characters

    int dpos = 0;
    data[dpos++] = 0xA5;  // detect word
    data[dpos++] = 0x00;  // address offset
    dpos++;
    data[dpos++] = gidlen;

    memcpy(&data[dpos], game_id, gidlen);
    dpos += gidlen;

    data[dpos++] = 0x00;
    data[dpos++] = 0xD5;  // end word
    data[dpos++] = 0x00;  // padding

    int data_len = dpos;
    data[2] = gameid_calc_crc(&data[3], data_len - 3);

    int xstart = (screenWidth / 2) - (data_len * 8);
    int ystart = screenHeight - (((screenHeight / 8) * 2) + 20);
    int height = 2;

    for (int i = 0; i < data_len; i++) {
        for (int ii = 7; ii >= 0; ii--) {
            int x = xstart + (i * 16 + ((7 - ii) * 2));
            int x1 = x + 1;

            gsKit_prim_sprite(gsGlobal, x, ystart, x1, ystart + height, 1, GS_SETREG_RGBA(0xFF, 0x00, 0xFF, 0x80));

            uint32_t color = (data[i] >> ii) & 1 ? GS_SETREG_RGBA(0x00, 0xFF, 0xFF, 0x80) : GS_SETREG_RGBA(0xFF, 0xFF, 0x00, 0x80);
            gsKit_prim_sprite(gsGlobal, x1, ystart, x1 + 1, ystart + height, 1, color);
        }
    }
}

int main(int argc, char *argv[]) {
    // Initialize GSKit
    GSGLOBAL *gsGlobal = gsKit_init_global();

    // Set the screen mode (e.g., GS_MODE_PAL, GS_MODE_NTSC)
    gsGlobal->Mode = GS_MODE_DTV_480P;  // Set to 480p mode
    gsGlobal->Width = 640;  // Width of the screen
    gsGlobal->Height = 448;  // Height of the screen
    gsGlobal->Interlace = GS_NONINTERLACED;  // Non-interlaced mode for progressive scan
    gsGlobal->Field = GS_FRAME;  // Frame mode
    gsGlobal->PSM = GS_PSM_CT24;  // Pixel storage format (24-bit color)
    gsGlobal->PSMZ = GS_PSMZ_32;  // Z buffer format (32-bit depth)
    gsGlobal->DoubleBuffering = GS_SETTING_OFF;  // Disable double buffering
    gsGlobal->ZBuffering = GS_SETTING_OFF;  // Disable Z buffering

    // Initialize the screen
    gsKit_vram_clear(gsGlobal);  // Clear VRAM
    gsKit_init_screen(gsGlobal);

    // Display game ID
    char game_id[] = "";
    gameid_draw_auto(gsGlobal, gsGlobal->Width, gsGlobal->Height, game_id);

    // Sync and flip the GS (Graphics Synthesizer)
    gsKit_sync_flip(gsGlobal);
    gsKit_queue_exec(gsGlobal);

    return 0;
}