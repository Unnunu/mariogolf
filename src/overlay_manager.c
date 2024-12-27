#include "common.h"
#include "nusys.h"
#include "ld_addrs.h"

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

Overlay D_800B5F58[] = {
    {
        FALSE,
        D_800B5F14,
        (u32)ovl1_ROM_START,
        (u32)ovl1_ROM_END,
        (u32)ovl1_TEXT_START,
        (u32)ovl1_TEXT_END,
        (u32)ovl1_BSS_START,
        (u32)ovl1_BSS_END,
        NULL,
        NULL
    },
    // 91380
    {
        FALSE,
        D_800B5F14,
        (u32)ovl1_ROM_START,
        (u32)ovl1_ROM_END,
        (u32)ovl1_TEXT_START,
        (u32)ovl1_TEXT_END,
        (u32)ovl1_BSS_START,
        (u32)ovl1_BSS_END,
        NULL,
        NULL
    },
    // 913A8
    {
        FALSE,
        D_800B5F14,
        (u32)ovl1_ROM_START,
        (u32)ovl1_ROM_END,
        (u32)ovl1_TEXT_START,
        (u32)ovl1_TEXT_END,
        (u32)ovl1_BSS_START,
        (u32)ovl1_BSS_END,
        func_80025D30,
        func_80080E14
    },
    // 913D0
    {
        FALSE,
        D_800B5F20,
        (u32)ovl2_ROM_START,
        (u32)ovl2_ROM_END,
        (u32)ovl2_TEXT_START,
        (u32)ovl2_TEXT_END,
        (u32)ovl2_BSS_START,
        (u32)ovl2_BSS_END,
        func_8005A580,
        func_8005ACF8
    },
    // 913F8
    {
        FALSE,
        D_800B5F24,
        (u32)ovl3_ROM_START,
        (u32)ovl3_ROM_END,
        (u32)ovl3_TEXT_START,
        (u32)ovl3_TEXT_END,
        (u32)ovl3_BSS_START,
        (u32)ovl3_BSS_END,
        NULL,
        NULL
    },
    // 91420
    {
        FALSE,
        D_800B5F28,
        (u32)ovl4_ROM_START,
        (u32)ovl4_ROM_END,
        (u32)ovl4_TEXT_START,
        (u32)ovl4_TEXT_END,
        (u32)ovl4_BSS_START,
        (u32)ovl4_BSS_END,
        NULL,
        NULL
    },
    // 91448
    {
        FALSE,
        D_800B5F2C,
        (u32)ovl5_ROM_START,
        (u32)ovl5_ROM_END,
        (u32)ovl5_TEXT_START,
        (u32)ovl5_TEXT_END,
        (u32)ovl5_BSS_START,
        (u32)ovl5_BSS_END,
        NULL,
        NULL
    },
    // 91470
    {
        FALSE,
        D_800B5F30,
        (u32)ovl6_ROM_START,
        (u32)ovl6_ROM_END,
        (u32)ovl6_TEXT_START,
        (u32)ovl6_TEXT_END,
        (u32)ovl6_BSS_START,
        (u32)ovl6_BSS_END,
        func_80025D54,
        0x801F5100
    },
    // 91498
    {
        FALSE,
        D_800B5F34,
        0x0014EA70,
        0x0014FB50,
        0x801F4A30,
        0x801F5920,
        0x801F5B10,
        0x8022BE30,
        0x801F4C84,
        0x801F4D48
    },
    // 914C0
    {
        FALSE,
        D_800B5F38,
        0x0014FB50,
        0x001508D0,
        0x801F4A30,
        0x801F5770,
        0x801F57B0,
        0x801FFD40,
        0x801F4A40,
        NULL
    },
    // 914E8
    {
        FALSE,
        D_800B5F3C,
        0x001508D0,
        0x00150990,
        0x801F4A30,
        0x801F4AF0,
        0x801F4AF0,
        0x801F4B00,
        NULL,
        NULL
    },
    // 91510
    {
        FALSE,
        D_800B5F40,
        0x00150990,
        0x0015BB50,
        0x80241800,
        0x8024C450,
        0x8024C9C0,
        0x8024CF40,
        NULL,
        NULL
    },
    // 91538
    {
        FALSE,
        D_800B5F44,
        0x0015BB50,
        0x0015F250,
        0x80241800,
        0x80244E10,
        0x80244F00,
        0x8024AD00,
        NULL,
        NULL
    },
    // 91560
    {
        FALSE,
        D_800B5F48,
        0x0015F250,
        0x001619A0,
        0x80241800,
        0x80243E20,
        0x80243F50,
        0x80244000,
        NULL,
        NULL
    },
    // 91588
    {
        FALSE,
        D_800B5F4C,
        0x001619A0,
        0x00165BC0,
        0x80241800,
        0x802457D0,
        0x80245A20,
        0x80245AF0,
        NULL,
        NULL
    },
    // 915B0
    {
        FALSE,
        D_800B5F50,
        0x00165BC0,
        0x0016D650,
        0x801F4A30,
        0x801FBB20,
        0x801FC4C0,
        0x801FC5D0,
        0x801F4B20,
        0x801F4E70
    },
    {
        FALSE,
        D_800B5F54,
        0x0016D650,
        0x00171770,
        0x801F4A30,
        0x801F89A0,
        0x801F8B50,
        0x80223810,
        0x801F4B9C,
        0x801F4E54
    },
};

extern s8 D_800D2930[];
extern s8 D_800FC858[];
extern u32 D_8012CFC0[];
extern u32 D_800B67F0;
extern s8 D_800B67C0;

void func_80025D30(void) {
    func_80080DCC();
    func_801FD624();
}

void func_80025D54(void) {
    func_802033B0();
    func_801F5018();
}

s32 func_80025D78(s32 arg0) {
    return D_800D2930[arg0] | 0x100;
}

void func_80025D8C(void) {
    s32 i;
    s32 k;
    s8* ptr;

    for (i = 0; i < 64; i++) {
        D_800D2930[i] = -1;
        D_800FC858[i] = 0;
        D_8012CFC0[i] = 0x80000000;
    }

    for (i = 0; i < 17U; i++) {
        ptr = D_800B5F58[i].unk_04;
        for (k = 0; ptr[k] != -1; k++) {
            if (D_800D2930[ptr[k]] != -1) {
                if (!func_800299F4(0x4D)) {
                    osSyncPrintf("OverlayManager\n");
                }
            }
            D_800D2930[ptr[k]] = i;
        }
    }

    for (i = 0; i < 64; i++) {
        if (D_800D2930[i] == -1) {
            D_800FC858[i] = 1;
        }
    }
}

s32 func_80025EC8(s32 arg0) {
    if (arg0 < 0x100 || arg0 >= 0x100 + 0x11U) {
        if (!func_800299F4(0x4D)) {
            osSyncPrintf("Illegal ModuleSetNo.\n");
        }
        return 0;
    }

    return arg0 & 0xFF;
}

s32 func_80025F18(s32 arg0) {
    s32 v0;
    s32 i;
    s8* ptr;
    s32 k;

    v0 = func_80025EC8(arg0);
    if (D_800B5F58[v0].isLoaded) {
        if (!func_800299F4(0x4D)) {
            osSyncPrintf("Already Loaded\n");
        }
        return 1;
    }

    for (i = 0; i < 17U; i++) {
        if (i == v0 || D_800B5F58[i].textStart > D_800B5F58[v0].bssEnd || D_800B5F58[i].bssEnd < D_800B5F58[v0].textStart) {
            continue;
        }

        if (D_800B5F58[i].isLoaded) {
            if (!func_800299F4(0x4D)) {
                osSyncPrintf("Conflicting %d m.s. and other moduleset[%x] is alive\n", v0, i);
            }
            return 0;
        }

        ptr = D_800B5F58[i].unk_04;
        for (k = 0; ptr[k] != -1; k++) {
            if (D_800B67F0 - D_8012CFC0[ptr[k]] < 2) {
                if (!func_800299F4(0x4D)) {
                    osSyncPrintf("Conflicting %d m.s. and other module[%x-%x]'s RDP request\n", v0, i, k);
                }
                return 0;
            }
        }
    }

    return 1;
}

s32 func_800260C4(s32 arg0) {
    s8* ptr;
    s32 k;
    Overlay* s0;

    if (func_80025F18(arg0)) {
        arg0 = func_80025EC8(arg0);
        if (!func_800299F4(0x4D)) {
            osSyncPrintf("Load ModuleSet %x (absolute No.)\n", arg0);
        }

        s0 = &D_800B5F58[arg0];
        ptr = s0->unk_04;

        osWritebackDCacheAll();
        nuPiReadRom(s0->romStart, (void*)s0->textStart, s0->romEnd - s0->romStart);
        bzero((void*)s0->bssStart, s0->bssEnd - s0->bssStart);
        osWritebackDCache((void*)s0->bssStart, s0->bssEnd - s0->bssStart);
        osInvalICache((void*)s0->textStart, s0->textEnd - s0->textStart);

        if (s0->initFunc != NULL) {
            s0->initFunc();
        }

        for (k = 0; ptr[k] != -1; k++) {
            D_800FC858[ptr[k]] = 1;
        }

        s0->isLoaded = TRUE;

        if (!func_800299F4(0x4D)) {
            osSyncPrintf("Complete Load ModuleSet %x (absolute No.)\n", arg0);
        }
        return 1;
    } else {
        if (!func_800299F4(0x4D)) {
            osSyncPrintf("Can't Load ModuleSet %x (logical No.)\n", arg0);
        }
        return 0;
    }
}

void func_80026230(s32 arg0) {
    Overlay* s0;
    s8* ptr;
    s32 k;

    arg0 = func_80025EC8(arg0);
    s0 = &D_800B5F58[arg0];
    

    if (!s0->isLoaded) {
        return;
    }

    if (s0->uninitFunc != NULL) {
        s0->uninitFunc();
    }
    ptr = s0->unk_04;

    s0->isLoaded = 0;
    if (!func_800299F4(0x4D)) {
        osSyncPrintf("Moduleset %x Disposed\n", arg0);
    }

    for (k = 0; ptr[k] != -1; k++) {
        D_800FC858[ptr[k]] = 0;
    }

    osWritebackDCacheAll();
    if (D_800B67C0 && osVirtualToPhysical((void*)s0->textStart) < 0x400000) {
        bzero((void*)s0->textStart, s0->textEnd - s0->textStart);
        osWritebackDCache((void*)s0->textStart, s0->textEnd - s0->textStart);
        osInvalICache((void*)s0->textStart, s0->textEnd - s0->textStart);
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
