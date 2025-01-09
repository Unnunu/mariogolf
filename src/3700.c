#include "nusys.h"

//INCLUDE_ASM("asm/nonmatchings/3700", nuGfxInitEX2);
extern NUUcode nugfx_ucode[];
extern u16*	FrameBuf[3];
extern Gfx rdpstateinit_dl[];

void nuGfxInitEX2(void)
{
    Gfx		gfxList[0x100];
    Gfx*	gfxList_ptr;
    

    /* Activate the graphics thread. */
    nuGfxThreadStart();

    nuGfxSetCfb(FrameBuf, 3);		/* Register the frame buffer. */
    nuGfxSetZBuffer((u16*)NU_GFX_ZBUFFER_ADDR);

    /* Register the callback function for frame buffer switching. */
    nuGfxSwapCfbFuncSet(nuGfxSwapCfb);


    nuGfxSetUcode(nugfx_ucode);
    /* Initialize the graphics task manager. */
    nuGfxTaskMgrInit();

    /* At first, the RDP only has to be initialized once. */
    /* Here that initialization is performed. */
    gfxList_ptr = gfxList;
    gSPDisplayList(gfxList_ptr++, OS_K0_TO_PHYSICAL(rdpstateinit_dl));
    gDPFullSync(gfxList_ptr++);
    gSPEndDisplayList(gfxList_ptr++);
    nuGfxTaskStart(gfxList,
		   (s32)(gfxList_ptr - gfxList) * sizeof (Gfx),
		   NU_GFX_UCODE_F3DEX , 0);

    /* Wait for the task to end. */
    nuGfxTaskAllEndWait();
}
