#include "common.h"

// rodata
extern const char D_800CA0D0[]; // "DestBillMan\n"
extern const char D_800CA0E0[]; // "InitBillMan\n"
extern const char D_800CA0F0[]; // "RevertBillMan\n"

typedef struct UnkAlpha {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ s32 unk_04;
    /* 0x08 */ s32 unk_08;
    /* 0x0C */ s32 unk_0C;
} UnkAlpha; // size = 0x10

typedef struct UnkBeta {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ s32 unk_04;
    /* 0x08 */ Mtx unk_08;
    /* 0x0C */ Mtx unk_48;
} UnkBeta; // size = 0x88

typedef struct UnkGamma {
    /* 0x00 */ s16 x;
    /* 0x02 */ s16 y;
    /* 0x04 */ s16 z;
    /* 0x06 */ s8 unk_06;
    /* 0x08 */ s16 unk_08;
    /* 0x08 */ s16 unk_0A;
    /* 0x0C */ u16 scaleX;
    /* 0x0E */ u16 scaleY;
} UnkGamma; // size = 0x10

#define NUM_SOMETHING 128

extern UnkAlpha D_800B6284[46];
extern s8 D_800B6564;
extern s32 D_800B6568;
extern s32 D_800B656C;
extern s16 D_800B6570[NUM_SOMETHING];
extern UnkBeta D_801EFFD0[NUM_SOMETHING];
extern UnkGamma D_800FBEA0[NUM_SOMETHING];
extern s8 D_801B60C2;

void func_8004DDE4(s32);
void func_8004DD70(s32, s32, s32);
s32 func_80043A04(s32, s32);

void func_800263B0(void) {
    u32 i;

    osSyncPrintf(D_800CA0D0);
    for (i = 0; i < ARRAY_COUNT(D_800B6284); i++) {
        D_800B6284[i].unk_0C = 0;
    }
    func_8004DDE4(1);
    D_800B6564 = 0;
}

void func_80026400(s32 arg0, s32 arg1) {
    s32 temp_s0;

    osSyncPrintf(D_800CA0E0);
    temp_s0 = arg0 + arg1;
    func_800263B0();
    D_800B6568 = arg0;
    D_800B656C = temp_s0;
    func_8004DD70(1, arg0, temp_s0);
    D_800B6564 = 1;
}

void func_8002646C(void) {
    osSyncPrintf(D_800CA0F0);
    func_800263B0();
    func_8004DD70(1, D_800B6568, D_800B656C);
    D_800B6564 = 1;
}

void func_800264BC(void) {
    s32 i;
    f32 x, y, z;

    for (i = 0; i != NUM_SOMETHING; i++) {
        D_800B6570[i] = i;
    }

    for (i = 0; i < NUM_SOMETHING; i++) {
        if (D_800FBEA0[i].unk_06 < 0) {
            continue;
        }

        x = D_800FBEA0[i].x;
        z = D_800FBEA0[i].z;

        if (!D_801B60C2 && (x <= 256.0f || z <= 256.0f || x >= 3840.0f || z >= 7936.0f)) {
            D_800FBEA0[i].unk_0A = TRUE;
        } else {
            D_800FBEA0[i].unk_0A = FALSE;
        }
        D_800FBEA0[i].y = y = func_80043A04(x * 1024.0f, z * 1024.0f) / 1024;

        guTranslate(&D_801EFFD0[i].unk_08, x, y, z);
        guScale(&D_801EFFD0[i].unk_48, D_800FBEA0[i].scaleX, D_800FBEA0[i].scaleY, 1.0f);
    }
}

INCLUDE_ASM("asm/nonmatchings/17B0", func_8002671C);

INCLUDE_ASM("asm/nonmatchings/17B0", func_8002687C);

INCLUDE_ASM("asm/nonmatchings/17B0", func_80026CC4);

INCLUDE_ASM("asm/nonmatchings/17B0", func_80027ACC);

INCLUDE_ASM("asm/nonmatchings/17B0", func_80028110);

INCLUDE_ASM("asm/nonmatchings/17B0", func_80028204);
