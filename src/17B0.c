#include "common.h"
#include "string.h"

// rodata
extern const char D_800CA0D0[]; // "DestBillMan\n"
extern const char D_800CA0E0[]; // "InitBillMan\n"
extern const char D_800CA0F0[]; // "RevertBillMan\n"
extern Vec3s D_800CA100; // { 0xFF, 0xDC, 0xA0 };
extern Vec3s D_800CA10C; // { 0x80, 0x40, 0x20 };
extern const char D_800CA118[];
extern const char D_800CA134[];
extern const char D_800CA14C[];
extern const char D_800CA164[];

typedef struct UnkAlpha {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ s16 unk_04;
    /* 0x06 */ s16 width;
    /* 0x08 */ s16 height;
    /* 0x0A */ s16 unk_0A;
    /* 0x0C */ u16* img;
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
    /* 0x07 */ u8 unk_07;
    /* 0x08 */ s16 unk_08;
    /* 0x0A */ u16 unk_0A;
    /* 0x0C */ u16 scaleX;
    /* 0x0E */ u16 scaleY;
} UnkGamma; // size = 0x10

typedef struct UnkDelta {
    /* 0x00 */ char unk_00[0x10];
} UnkDelta; // size = 0x10

typedef struct UnkEpsilon {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ char unk_04[0x4C];
} UnkEpsilon; // size = 0x50

#define NUM_SOMETHING 128

Vtx D_800B6200[] = {
    {{{ -1, 0, 0 }, 0, { 0x0000, 0x1000 }, { 150, 150, 150, 255 }}},
    {{{  1, 0, 0 }, 0, { 0x2000, 0x1000 }, { 255, 255, 255, 255 }}},
    {{{  1, -1, 0 }, 0, { 0x2000, 0x0000 }, { 255, 255, 255,  0 }}},
    {{{ -1, -1, 0 }, 0, { 0x0000, 0x0000 }, { 150, 150, 150, 0 }}},
    {{{ -1, 0, 0 }, 0, { 0x0000, 0x1000 }, { 63, 63, 127, 255 }}},
    {{{  1, 0, 0 }, 0, { 0x2000, 0x1000 }, { 127, 127, 191, 255 }}},
    {{{  1, 1, 0 }, 0, { 0x2000, 0x0000 }, { 127, 127, 191,  0 }}},
    {{{ -1, 1, 0 }, 0, { 0x0000, 0x0000 }, { 63, 63, 127, 0 }}},
};
s32 D_800B6280 = -1;
UnkAlpha D_800B6284[] = {
    { 1015, 2, 32, 64, 0, NULL },
    { 1016, 2, 32, 64, 0, NULL },
    { 1017, 2, 32, 64, 0, NULL },
    { 1018, 2, 32, 64, 0, NULL },
    { 1019, 2, 32, 64, 0, NULL },
    { 1020, 2, 32, 64, 0, NULL },
    { 1021, 2, 32, 64, 0, NULL },
    { 1022, 2, 32, 64, 0, NULL },
    { 1023, 2, 32, 64, 0, NULL },
    { 1024, 2, 32, 64, 0, NULL },
    { 1025, 2, 32, 64, 0, NULL },
    { 1026, 2, 32, 64, 0, NULL },
    { 1027, 2, 32, 64, 0, NULL },
    { 1028, 2, 32, 64, 0, NULL },
    { 1029, 2, 32, 64, 0, NULL },
    { 1030, 2, 32, 64, 0, NULL },
    { 1031, 2, 32, 64, 0, NULL },
    { 1031, 2, 32, 64, 0, NULL }, // 1031 ?
    { 1033, 2, 32, 64, 0, NULL },
    { 1034, 2, 32, 64, 0, NULL },
    { 1035, 2, 32, 64, 0, NULL },
    { 1036, 2, 32, 64, 0, NULL },
    { 1037, 2, 32, 64, 0, NULL },
    { 1038, 2, 32, 64, 0, NULL },
    { 1039, 2, 32, 64, 0, NULL },
    { 1040, 2, 32, 64, 0, NULL },
    { 1041, 2, 32, 64, 0, NULL },
    { 1042, 2, 32, 64, 0, NULL },
    { 1043, 2, 32, 64, 0, NULL },
    { 1044, 2, 32, 64, 0, NULL },
    { 1045, 2, 32, 64, 0, NULL },
    { 1046, 2, 32, 64, 0, NULL },
    { 1047, 2, 32, 64, 0, NULL },
    { 1048, 2, 32, 64, 0, NULL },
    { 1049, 2, 32, 64, 0, NULL },
    { 1050, 2, 32, 64, 0, NULL },
    { 1051, 2, 32, 64, 0, NULL },
    { 1052, 2, 32, 64, 0, NULL },
    { 1053, 2, 32, 64, 0, NULL },
    { 1054, 2, 32, 64, 0, NULL },
    { 1055, 2, 32, 64, 0, NULL },
    { 2319, 2, 32, 64, 0, NULL },
    { 2320, 2, 32, 64, 0, NULL },
    { 2321, 2, 32, 64, 0, NULL },
    { 2322, 2, 32, 64, 0, NULL },
    { 2323, 2, 32, 64, 0, NULL },
};
s8 D_800B6564 = 0;
s32 D_800B6568 = 0;
s32 D_800B656C = 0;
extern u16 D_800B6570[NUM_SOMETHING];

extern u16 D_800BAA00;
extern u16 D_800BAA02;

// .bss
extern s32 D_800FBE64;
extern s32 D_800FBE68;
extern s32 D_800FBE6C;
extern UnkGamma D_800FBEA0[NUM_SOMETHING];
extern Vec3f D_801B54EC;
extern Vec3f D_801B54F8;
extern UnkEpsilon D_801B5534[];
extern s8 D_801B60C2;
extern Gfx* D_801B93DC;
extern UnkBeta D_801EFFD0[NUM_SOMETHING];

s32 func_80045AC0(void);
void* func_8004E2DC(u32);
void func_8004E47C(void**);

void func_800504E8(s32, UnkDelta*);
void func_800505A0(s32, s32, UnkDelta*);
s32 func_8004DE7C(s32, s32);

void func_8004DDE4(s32);
void func_8004DD70(s32, s32, s32);
s32 func_80043A04(s32, s32);
s32 func_80065600(f32, f32, f32);

void func_800263B0(void) {
    u32 i;

    osSyncPrintf(D_800CA0D0);
    for (i = 0; i < ARRAY_COUNT(D_800B6284); i++) {
        D_800B6284[i].img = NULL;
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

void func_8002671C(void) {
    s32 i, j;

    for (i = 0; i != NUM_SOMETHING; i++) {
        if (D_800FBEA0[i].unk_06 < 0) {
            D_801EFFD0[i].unk_00 = 0x40000000;
        } else {
            D_801EFFD0[i].unk_00 = func_80065600(D_800FBEA0[i].x, D_800FBEA0[i].y, D_800FBEA0[i].z);
        }
    }

    for (i = 1; i != NUM_SOMETHING; i++) {
        u16 t = D_800B6570[i];
        for (j = i - 1; j >= 0; j--) {
            if (D_801EFFD0[D_800B6570[j]].unk_00 >= D_801EFFD0[t].unk_00) {
                break;
            }
            D_800B6570[j + 1] = D_800B6570[j];
        }

        D_800B6570[j + 1] = t;
    }
}

#ifdef NON_MATCHING
void func_8002687C(Gfx** gfxPtr, UnkGamma* arg1, UnkBeta* arg2, s32 arg3, s32 arg4) {
    Gfx* gfxPos = *gfxPtr;
    UnkDelta sp10;

    if (D_800B6284[arg3].img == NULL && D_800B6284[arg3].unk_04 == 2) {
        s32 width = D_800B6284[arg3].width;
        s32 height = D_800B6284[arg3].height;
        D_800B6284[arg3].img = func_8004DE7C(1, width * height * 2 + 8);
        if (D_800B6284[arg3].img != NULL) {
            func_800504E8(D_800B6284[arg3].unk_00, &sp10);
            func_800505A0(D_800B6284[arg3].unk_0C, 8, &sp10);
            func_800505A0(D_800B6284[arg3].unk_0C, width * height * 2, &sp10);
        }
    }

    if (arg1->unk_06 != D_800B6280 && D_800B6284[arg3].unk_04 == 2 && D_800B6284[arg3].img != NULL) {
        gDPLoadTextureBlock(gfxPos++, D_800B6284[arg3].img & ~7, G_IM_FMT_RGBA, G_IM_SIZ_16b,
                            D_800B6284[arg3].width, D_800B6284[arg3].height, 0,
                            G_TX_NOMIRROR | G_TX_WRAP, G_TX_MIRROR | G_TX_WRAP, 5, 6, 2, G_TX_NOLOD);
        gDPPipeSync(gfxPos++);
        gDPSetTextureLUT(gfxPos++, G_TT_NONE);
        gDPSetCombineLERP(gfxPos++, ENVIRONMENT, TEXEL0, ENV_ALPHA, TEXEL0,
                                    PRIMITIVE, 0, TEXEL0, 0,
                                    SHADE, 0, COMBINED, 0,
                                    0, 0, 0, COMBINED);
    }

    gSPMatrix(gfxPos++, &arg2->unk_08, G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
    gSPMatrix(gfxPos++, arg4 + 0xC0, G_MTX_NOPUSH | G_MTX_MUL | G_MTX_MODELVIEW); // todo struct
    gSPMatrix(gfxPos++, &arg2->unk_48, G_MTX_NOPUSH | G_MTX_MUL | G_MTX_MODELVIEW);
    gDPPipeSync(gfxPos++);
    gSPVertex(gfxPos++, &D_800B6200[arg1->unk_07 * 8], 4, 0);
    gSP2Triangles(gfxPos++, 0, 1, 2, 0, 0, 2, 3, 0);
    gDPPipeSync(gfxPos++);
    gSPPopMatrix(gfxPos++, G_MTX_MODELVIEW);

    D_800B6280 = arg1->unk_06;
    *gfxPtr = gfxPos;
}
#else
INCLUDE_ASM("asm/nonmatchings/17B0", func_8002687C);
void func_8002687C(Gfx** gfxPtr, UnkGamma* arg1, UnkBeta* arg2, s32 arg3, s32 arg4);
#endif

#ifdef NON_MATCHING
void func_80026CC4(s32 arg0, s32 arg1) {
    Gfx* gfxPos = D_801B93DC;
    f32 fv0, fs0, ft2, ft0;
    f32 temp1, temp2;
    s32 s7;
    s32 i;
    Vec3f sp48;
    Vec3f sp38;
    s32 envColor2[3] = { 0xFF, 0xDC, 0xA0 };
    s32 envColor[3] = { 0x80, 0x40, 0x20 };

    if (func_800299F4(14) || !D_800B6564) {
        return;
    }

    gDPPipeSync(gfxPos++);
    gDPPipeSync(gfxPos++);
    gDPSetCycleType(gfxPos++, G_CYC_2CYCLE);
    gDPPipeSync(gfxPos++);
    gDPSetEnvColor(gfxPos++, envColor[0], envColor[1], envColor[2], 32);

    sp38.x = D_801B54F8.x - D_801B54EC.x;
    sp38.z = D_801B54F8.z - D_801B54EC.z;
    sp38.y = 0.0f;

    temp1 = D_800BAA02 * 0.0000958738f;
    temp2 = D_800BAA00 * 0.0000958738f;

    sp48.x = cosf(temp1) * cosf(temp2);
    sp48.z = cosf(temp1) * sinf(temp2);
    sp48.y = sinf(temp1);

    if (fabsf(sp38.x) + fabsf(sp38.z) >= 1.0f) {
        guNormalize(&sp38.x, &sp38.y, &sp38.z);
        guNormalize(&sp48.x, &sp48.y, &sp48.z);

        fs0 = sp38.x * sp48.x + sp38.z * sp48.z;
        fv0 = cosf(temp1);
        
        if (fv0 >= 0.1f) {
            ft2 = fs0;
            if (ft2 > fv0) {
                ft2 = fv0;
            }

            if (ft2 < -fv0) {
                ft2 = -fv0;
            }

            ft0 = fs0;
            if (ft0 > fv0) {
                ft0 = fv0;
            }
            if (ft0 < -fv0) {
                ft0 = -fv0;
            }

            D_800B6200[0].v.cn[0] = (-fv0 * 0.5f + ft2 * 0.5f) * 127.0f + 255.0f;
            D_800B6200[0].v.cn[1] = (-fv0 * 0.5f + ft2 * 0.5f) * 127.0f + 255.0f;
            D_800B6200[0].v.cn[2] = (-fv0 * 0.5f + ft2 * 0.5f) * 127.0f + 255.0f;

            D_800B6200[1].v.cn[0] = (-fv0 * 0.5f + ft0 * 0.5f) * 127.0f + 255.0f;
            D_800B6200[1].v.cn[1] = (-fv0 * 0.5f + ft0 * 0.5f) * 127.0f + 255.0f;
            D_800B6200[1].v.cn[2] = (-fv0 * 0.5f + ft0 * 0.5f) * 127.0f + 255.0f;

            D_800B6200[2].v.cn[0] = (-fv0 * 0.5f + ft0 * 0.5f) * 255.0f + 255.0f;
            D_800B6200[2].v.cn[1] = (-fv0 * 0.5f + ft0 * 0.5f) * 255.0f + 255.0f;
            D_800B6200[2].v.cn[2] = (-fv0 * 0.5f + ft0 * 0.5f) * 255.0f + 255.0f;

            D_800B6200[3].v.cn[0] = (-fv0 * 0.5f + ft2 * 0.5f) * 255.0f + 255.0f;
            D_800B6200[3].v.cn[1] = (-fv0 * 0.5f + ft2 * 0.5f) * 255.0f + 255.0f;
            D_800B6200[3].v.cn[2] = (-fv0 * 0.5f + ft2 * 0.5f) * 255.0f + 255.0f;
        }
    }

    gSPClipRatio(gfxPos++, FRUSTRATIO_1);
    gDPPipeSync(gfxPos++);
    gDPSetColorDither(gfxPos++, G_CD_MAGICSQ);
    gSPClearGeometryMode(gfxPos++, G_ZBUFFER | G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH | G_CLIPPING | 0x0040F9FA);
    gSPSetGeometryMode(gfxPos++, G_ZBUFFER | G_SHADE | G_FOG | G_SHADING_SMOOTH);
    gDPPipeSync(gfxPos++);
    gDPSetTextureFilter(gfxPos++, G_TF_BILERP);
    gDPPipeSync(gfxPos++);
    gDPSetTexturePersp(gfxPos++, G_TP_PERSP);
    gDPSetBlendColor(gfxPos++, 255, 255, 255, 254);
    gDPPipeSync(gfxPos++);
    gDPSetTextureLOD(gfxPos++, G_TL_TILE);
    gDPPipeSync(gfxPos++);
    gDPSetAlphaDither(gfxPos++, G_AD_PATTERN);
    gSPTexture(gfxPos++, 0x8000, 0x8000, 0, G_TX_RENDERTILE, G_ON);

    if (D_801B5534[arg1].unk_00 != 1) {
        s7 = 0xFFFF0001;
    } else {
        s7 = func_80065600(D_800FBE64 * 0.0009765625f, D_800FBE68 * 0.0009765625f, D_801B5534[arg1].unk_00);
        if (s7 > 0) {
            s7 = 0xFFFF0001;
        }
    }

    func_8002671C();
    D_800B6280 = -1;

    gDPSetPrimColor(gfxPos++, 0, 0, 63, 180, 0, 255);
    gDPPipeSync(gfxPos++);
    gDPSetRenderMode(gfxPos++, G_RM_FOG_SHADE_A, G_RM_AA_ZB_TEX_EDGE2);
    gDPPipeSync(gfxPos++);
    gDPSetAlphaCompare(gfxPos++, G_AC_NONE);

    for (i = 0; i < NUM_SOMETHING; i++) {
        s32 k = D_800B6570[i];
        if (D_800FBEA0[k].unk_0A != 0 || D_800FBEA0[k].unk_06 < 0) {
            continue;
        } 
        if (D_801EFFD0[k].unk_00 >= -0x800) {
            continue;
        }
        
        func_8002687C(&gfxPos, &D_800FBEA0[k], &D_801EFFD0[k], D_800FBEA0[k].unk_06, arg0);
    }

    gDPPipeSync(gfxPos++);
    gDPSetRenderMode(gfxPos++, Z_CMP | Z_UPD | IM_RD | CVG_DST_FULL | ZMODE_XLU | FORCE_BL | G_RM_FOG_SHADE_A, Z_CMP | Z_UPD | IM_RD | CVG_DST_FULL | ZMODE_XLU | FORCE_BL | GBL_c2(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_1MA));
    gDPPipeSync(gfxPos++);
    gDPSetAlphaCompare(gfxPos++, G_AC_THRESHOLD);
    gDPSetBlendColor(gfxPos++, 255, 255, 255, 63);

    for (i = NUM_SOMETHING - 1; i >= 0; i--) {
        s32 k = D_800B6570[i];
        s32 s4;
        s32 s0;
        
        if (D_800FBEA0[k].unk_0A == 0 && (s4 = D_800FBEA0[k].unk_06) >= 0) {
            if (D_801EFFD0[k].unk_00 < -0x800) {
                continue;
            }
            if (D_801EFFD0[k].unk_00 >= 0) {
                continue;
            }
            
            s0 = -D_801EFFD0[k].unk_00;

            if (s0 > 255) {
                s0 = 255;
            }
            if (s0 < 128) {
                s0 = 128;
            }
            if (D_801EFFD0[k].unk_00 < s7) {
                s0 = 255;
            }
            if (func_80045AC0() && s7 - 100 > D_801EFFD0[k].unk_00) {
                continue;
            }
            if (s0 >= 255) {
                func_8002687C(&gfxPos, &D_800FBEA0[k], &D_801EFFD0[k], s4, arg0);
            }
        }
    }

    gDPPipeSync(gfxPos++);
    gDPSetAlphaCompare(gfxPos++, G_AC_NONE);
    gDPPipeSync(gfxPos++);
    gDPSetTextureLUT(gfxPos++, G_TT_NONE);
    gDPPipeSync(gfxPos++);
    gDPSetRenderMode(gfxPos++, G_RM_OPA_SURF, G_RM_OPA_SURF2);
    gDPPipeSync(gfxPos++);

    D_801B93DC = gfxPos;
}
#else
INCLUDE_ASM("asm/nonmatchings/17B0", func_80026CC4);
#endif

void func_80027ACC(s32 arg0, s32 arg1) {
    Gfx* gfxPos = D_801B93DC;
    Vec3s envColor2 = D_800CA100; //{ 0xFF, 0xDC, 0xA0 };
    Vec3s envColor = D_800CA10C; //{ 0x80, 0x40, 0x20 };
    s32 s2;
    s32 i;
    s32 s3;

    if (func_800299F4(14) || !D_800B6564 || func_80045AC0()) {
        return;
    }

    gDPPipeSync(gfxPos++);
    gDPPipeSync(gfxPos++);
    gDPSetCycleType(gfxPos++, G_CYC_2CYCLE);
    gDPPipeSync(gfxPos++);
    gDPSetEnvColor(gfxPos++, envColor.x, envColor.y, envColor.z, 32);


    gSPClipRatio(gfxPos++, FRUSTRATIO_1);
    gDPPipeSync(gfxPos++);
    gDPSetColorDither(gfxPos++, G_CD_MAGICSQ);
    gSPClearGeometryMode(gfxPos++, G_ZBUFFER | G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH | G_CLIPPING | 0x0040F9FA);
    gSPSetGeometryMode(gfxPos++, G_ZBUFFER | G_SHADE | G_FOG | G_SHADING_SMOOTH);
    gDPPipeSync(gfxPos++);
    gDPSetTextureFilter(gfxPos++, G_TF_BILERP);
    gDPPipeSync(gfxPos++);
    gDPSetTexturePersp(gfxPos++, G_TP_PERSP);
    gDPSetBlendColor(gfxPos++, 255, 255, 255, 254);
    gDPPipeSync(gfxPos++);
    gDPSetTextureLOD(gfxPos++, G_TL_TILE);
    gDPPipeSync(gfxPos++);
    gDPSetAlphaDither(gfxPos++, G_AD_PATTERN);
    gSPTexture(gfxPos++, 0x8000, 0x8000, 0, G_TX_RENDERTILE, G_ON);

    if (D_801B5534[arg1].unk_00 != 1) {
        s2 = 0xFFFF0001;
    } else {
        s2 = func_80065600(D_800FBE64 * 0.0009765625f, D_800FBE68 * 0.0009765625f, D_800FBE6C * 0.0009765625f);
        if (s2 > 0) {
            s2 = 0xFFFF0001;
        }
    }
    
    D_800B6280 = -1;

    gDPSetPrimColor(gfxPos++, 0, 0, 63, 180, 0, 255);
    gDPPipeSync(gfxPos++);
    gDPSetRenderMode(gfxPos++, G_RM_FOG_SHADE_A, G_RM_AA_ZB_TEX_EDGE2);
    gDPPipeSync(gfxPos++);
    gDPSetAlphaCompare(gfxPos++, G_AC_NONE);

    s3 = FALSE;

    gDPPipeSync(gfxPos++);
    gDPSetRenderMode(gfxPos++, Z_CMP | Z_UPD | IM_RD | CVG_DST_FULL | ZMODE_XLU | FORCE_BL | G_RM_FOG_SHADE_A, Z_CMP | Z_UPD | IM_RD | CVG_DST_FULL | ZMODE_XLU | FORCE_BL | GBL_c2(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_1MA));
    gDPPipeSync(gfxPos++);
    gDPSetAlphaCompare(gfxPos++, G_AC_THRESHOLD);
    gDPSetBlendColor(gfxPos++, 255, 255, 255, 63);

    
    for (i = NUM_SOMETHING - 1; i >= 0; i--) {
        s32 k = D_800B6570[i];
        s32 s4;
        s32 a2;
        
        if (D_800FBEA0[k].unk_0A == 0 && (s4 = D_800FBEA0[k].unk_06) >= 0) {
            if (D_801EFFD0[k].unk_00 < -0x800) {
                continue;
            }
            if (D_801EFFD0[k].unk_00 >= 0) {
                continue;
            }
            
            a2 = -D_801EFFD0[k].unk_00;

            if (a2 > 255) {
                a2 = 255;
            }
            if (a2 < 128) {
                a2 = 128;
            }
            if (D_801EFFD0[k].unk_00 < s2) {
                a2 = 255;
            }

            if (a2 != 255) {
                if (!s3 && a2 < 255) {
                    s3 = TRUE;
                    gDPPipeSync(gfxPos++);
                    gDPSetRenderMode(gfxPos++, G_RM_FOG_SHADE_A, G_RM_ZB_XLU_SURF2);
                }
                if (a2 < 255) {
                    gDPSetPrimColor(gfxPos++, 0, 0, 63, 180, 0, a2);
                }
                func_8002687C(&gfxPos, &D_800FBEA0[k], &D_801EFFD0[k], s4, arg0);
            }
        }
    }

    gDPPipeSync(gfxPos++);
    gDPSetAlphaCompare(gfxPos++, G_AC_NONE);
    gDPPipeSync(gfxPos++);
    gDPSetTextureLUT(gfxPos++, G_TT_NONE);
    gDPPipeSync(gfxPos++);
    gDPSetRenderMode(gfxPos++, G_RM_OPA_SURF, G_RM_OPA_SURF2);
    gDPPipeSync(gfxPos++);

    D_801B93DC = gfxPos;
}

s32 func_80028110(char* arg0, u32 arg1) {
    u32 length;
    u8* sp14;
    u32* sp10;

    if (arg1 == 0) {
        osSyncPrintf(D_800CA118);
        return 1;
    }

    length = strlen(arg0);
    if (length == 0) {
        osSyncPrintf(D_800CA134);
        return 2;
    }

    length = (length + 3) & ~3;
    if (length >= 256) {
        osSyncPrintf(D_800CA14C);
        return 3;
    }

    sp10 = func_8004E2DC(4);
    sp14 = func_8004E2DC(length);
    memcpy(sp14, arg0, length);

    *sp10 = 10;
    *sp10 = length;
    *sp10 = arg1;
    func_8004E47C((void**)&sp10);
    func_8004E47C((void**)&sp14);
    return 0;
}

s32 func_80028204(char* arg0, s32* arg1) {
    u32 length;
    u8* sp14;
    u32* sp10;

    length = strlen(arg0);
    if (length == 0) {
        osSyncPrintf(D_800CA134);
        return 2;
    }

    length = (length + 3) & ~3;
    if (length >= 256) {
        osSyncPrintf(D_800CA14C);
        return 3;
    }

    sp10 = func_8004E2DC(4);
    sp14 = func_8004E2DC(length);
    memcpy(sp14, arg0, length);

    *sp10 = 11;
    *sp10 = length;
    if (*sp10 == 0) {
        *arg1 = 0;
        osSyncPrintf(D_800CA164);
    }
    func_8004E47C((void**)&sp10);
    func_8004E47C((void**)&sp14);
    return 1;
}
