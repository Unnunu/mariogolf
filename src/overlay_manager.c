#include "common.h"
#include "nusys.h"
#include "ld_addrs.h"

#define NUM_OVERLAYS ARRAY_COUNTU(sOverlays)
#define OVERLAY(name) \
    (u32) name ## _ROM_START, \
    (u32) name ## _ROM_END, \
    (u32) name ## _TEXT_START, \
    (u32) name ## _TEXT_END, \
    (u32) name ## _BSS_START, \
    (u32) name ## _BSS_END

typedef struct Overlay {
    /* 0x00 */ s8 isLoaded;
    /* 0x04 */ s8* unk_04;
    /* 0x08 */ u32 romStart;
    /* 0x0C */ u32 romEnd;
    /* 0x10 */ u32 textStart;
    /* 0x14 */ u32 textEnd;
    /* 0x18 */ u32 bssStart;
    /* 0x1C */ u32 bssEnd;
    /* 0x20 */ void (*initFunc)(void);
    /* 0x24 */ void (*uninitFunc)(void);
} Overlay; // size = 0x28

void func_80025D30(void);
void func_80025D54(void);

s8 D_800B5F10[] = { 0, -1 };
s8 D_800B5F14[] = { 15, 9, 1, 10, 11, 17, 18, 20, 23, 24, 25, -1 };
s8 D_800B5F20[] = { 2, -1 };
s8 D_800B5F24[] = { 6, 28, -1 };
s8 D_800B5F28[] = { 7, -1 };
s8 D_800B5F2C[] = { 8, -1 };
s8 D_800B5F30[] = { 3, 16, 19, -1 };
s8 D_800B5F34[] = { 4, 30, -1 };
s8 D_800B5F38[] = { 12, -1 };
s8 D_800B5F3C[] = { 13, -1 };
s8 D_800B5F40[] = { 5, 14, -1 };
s8 D_800B5F44[] = { 26, -1 };
s8 D_800B5F48[] = { 21, -1 };
s8 D_800B5F4C[] = { 22, -1 };
s8 D_800B5F50[] = { 27, 29, 32, -1 };
s8 D_800B5F54[] = { 31, -1 };

Overlay sOverlays[] = {
    { FALSE, D_800B5F14, OVERLAY(ovl1), NULL, NULL },
    { FALSE, D_800B5F14, OVERLAY(ovl1), NULL, NULL },
    { FALSE, D_800B5F14, OVERLAY(ovl1), func_80025D30, func_80080E14 },
    { FALSE, D_800B5F20, OVERLAY(ovl2), func_8005A580, func_8005ACF8 },
    { FALSE, D_800B5F24, OVERLAY(ovl3), NULL, NULL },
    { FALSE, D_800B5F28, OVERLAY(ovl4), NULL, NULL },
    { FALSE, D_800B5F2C, OVERLAY(ovl5), NULL, NULL },
    { FALSE, D_800B5F30, OVERLAY(ovl6), func_80025D54, func_801F5100_137780 },
    { FALSE, D_800B5F34, OVERLAY(ovl7), func_801F4C84_14ECC4, func_801F4D48_14ED88 },
    { FALSE, D_800B5F38, OVERLAY(ovl8), func_801F4A40_14FB60, NULL },
    { FALSE, D_800B5F3C, OVERLAY(ovl9), NULL, NULL },
    { FALSE, D_800B5F40, OVERLAY(ovlA), NULL, NULL },
    { FALSE, D_800B5F44, OVERLAY(ovlB), NULL, NULL },
    { FALSE, D_800B5F48, OVERLAY(ovlC), NULL, NULL },
    { FALSE, D_800B5F4C, OVERLAY(ovlD), NULL, NULL },
    { FALSE, D_800B5F50, OVERLAY(ovlE), func_801F4B20_165CB0, func_801F4E70_166000 },
    { FALSE, D_800B5F54, OVERLAY(ovlF), func_801F4B9C_16D7BC, func_801F4E54_16DA74 },
};

s8 DD_800D2930[64] ALIGNED(8);
s8 gOverlayDataLoaded[64] ALIGNED(8);
u32 D_8012CFC0[64] ALIGNED(8);

void func_80025D30(void) {
    func_80080DCC();
    func_801FD624();
}

void func_80025D54(void) {
    func_802033B0();
    func_801F5018();
}

s32 func_80025D78(s32 arg0) {
    return DD_800D2930[arg0] | 0x100;
}

void initOverlayManager(void) {
    s32 i;
    s32 k;
    s8* ptr;

    for (i = 0; i < 64; i++) {
        DD_800D2930[i] = -1;
        gOverlayDataLoaded[i] = FALSE;
        D_8012CFC0[i] = 0x80000000;
    }

    for (i = 0; i < NUM_OVERLAYS; i++) {
        ptr = sOverlays[i].unk_04;
        for (k = 0; ptr[k] != -1; k++) {
            if (DD_800D2930[ptr[k]] != -1) {
                if (!func_800299F4(0x4D)) {
                    osSyncPrintf("OverlayManager\n");
                }
            }
            DD_800D2930[ptr[k]] = i;
        }
    }

    for (i = 0; i < 64; i++) {
        if (DD_800D2930[i] == -1) {
            gOverlayDataLoaded[i] = TRUE;
        }
    }
}

s32 getOverlayAbsoluteNo(s32 logicalNo) {
    if (logicalNo < 0x100 || logicalNo >= 0x100 + NUM_OVERLAYS) {
        if (!func_800299F4(0x4D)) {
            osSyncPrintf("Illegal ModuleSetNo.\n");
        }
        return 0;
    }

    return logicalNo & 0xFF;
}

s32 canOverlayBeLoaded(s32 ovlIndex) {
    s32 asbNum;
    s32 i;
    s8* ptr;
    s32 k;

    asbNum = getOverlayAbsoluteNo(ovlIndex);
    if (sOverlays[asbNum].isLoaded) {
        if (!func_800299F4(0x4D)) {
            osSyncPrintf("Already Loaded\n");
        }
        return TRUE;
    }

    for (i = 0; i < NUM_OVERLAYS; i++) {
        if (i == asbNum || sOverlays[i].textStart > sOverlays[asbNum].bssEnd || sOverlays[i].bssEnd < sOverlays[asbNum].textStart) {
            continue;
        }

        if (sOverlays[i].isLoaded) {
            if (!func_800299F4(0x4D)) {
                osSyncPrintf("Conflicting %d m.s. and other moduleset[%x] is alive\n", asbNum, i);
            }
            return FALSE;
        }

        ptr = sOverlays[i].unk_04;
        for (k = 0; ptr[k] != -1; k++) {
            if (D_800B67F0 - D_8012CFC0[ptr[k]] < 2) {
                if (!func_800299F4(0x4D)) {
                    osSyncPrintf("Conflicting %d m.s. and other module[%x-%x]'s RDP request\n", asbNum, i, k);
                }
                return FALSE;
            }
        }
    }

    return TRUE;
}

s32 loadOverlay(s32 ovlIndex) {
    s8* ptr;
    s32 k;
    Overlay* overlay;

    if (canOverlayBeLoaded(ovlIndex)) {
        ovlIndex = getOverlayAbsoluteNo(ovlIndex);
        if (!func_800299F4(0x4D)) {
            osSyncPrintf("Load ModuleSet %x (absolute No.)\n", ovlIndex);
        }

        overlay = &sOverlays[ovlIndex];
        ptr = overlay->unk_04;

        osWritebackDCacheAll();
        nuPiReadRom(overlay->romStart, (void*)overlay->textStart, overlay->romEnd - overlay->romStart);
        bzero((void*)overlay->bssStart, overlay->bssEnd - overlay->bssStart);
        osWritebackDCache((void*)overlay->bssStart, overlay->bssEnd - overlay->bssStart);
        osInvalICache((void*)overlay->textStart, overlay->textEnd - overlay->textStart);

        if (overlay->initFunc != NULL) {
            overlay->initFunc();
        }

        for (k = 0; ptr[k] != -1; k++) {
            gOverlayDataLoaded[ptr[k]] = TRUE;
        }

        overlay->isLoaded = TRUE;

        if (!func_800299F4(0x4D)) {
            osSyncPrintf("Complete Load ModuleSet %x (absolute No.)\n", ovlIndex);
        }
        return TRUE;
    } else {
        if (!func_800299F4(0x4D)) {
            osSyncPrintf("Can't Load ModuleSet %x (logical No.)\n", ovlIndex);
        }
        return FALSE;
    }
}

void unloadOverlay(s32 ovlIndex) {
    Overlay* overlay;
    s8* ptr;
    s32 k;

    ovlIndex = getOverlayAbsoluteNo(ovlIndex);
    overlay = &sOverlays[ovlIndex];
    

    if (!overlay->isLoaded) {
        return;
    }

    if (overlay->uninitFunc != NULL) {
        overlay->uninitFunc();
    }
    ptr = overlay->unk_04;

    overlay->isLoaded = FALSE;
    if (!func_800299F4(0x4D)) {
        osSyncPrintf("Moduleset %x Disposed\n", ovlIndex);
    }

    for (k = 0; ptr[k] != -1; k++) {
        gOverlayDataLoaded[ptr[k]] = FALSE;
    }

    osWritebackDCacheAll();
    if (D_800B67C0 && osVirtualToPhysical((void*)overlay->textStart) < 0x400000) {
        bzero((void*)overlay->textStart, overlay->textEnd - overlay->textStart);
        osWritebackDCache((void*)overlay->textStart, overlay->textEnd - overlay->textStart);
        osInvalICache((void*)overlay->textStart, overlay->textEnd - overlay->textStart);
    }
}

s32 func_80026358(void) {
    if (!func_800299F4(0x4D)) {
        osSyncPrintf("Module %d not alive !!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
    }
    if (!func_800299F4(0x4D)) {
        osSyncPrintf("Module %d not alive !!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
    }
    return 0;
}
