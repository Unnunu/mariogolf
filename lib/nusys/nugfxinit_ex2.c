/*======================================================================*/
/*		NuSYS							*/
/*		nugfxinit.c						*/
/*									*/
/*		Copyright (C) 1997, NINTENDO Co,Ltd.			*/
/*									*/
/*----------------------------------------------------------------------*/    
/* Ver 1.2	98/07/06	Created by Kensaku Ohki(SLANP)		*/
/*======================================================================*/
#define	F3DEX_GBI_2
#include <nusys.h>

/*------------------------------------------------------*/
/*  Graphics microcode for registering. 			*/
/*  When the microcode is changed, please make  	*/
/*  additions or changes here. 				*/
/*------------------------------------------------------*/    
static NUUcode nugfx_ucode[] = {
    {(u64*)gspF3DEX2_fifoTextStart, (u64*)gspF3DEX2_fifoDataStart},	/*0*/
    // {(u64*)gspF3DEX2_NoN_fifoTextStart, (u64*)gspF3DEX2_NoN_fifoDataStart},/*1*/
    // {(u64*)gspF3DEX2_Rej_fifoTextStart, (u64*)gspF3DEX2_Rej_fifoDataStart},/*2*/
    // {(u64*)gspF3DLX2_Rej_fifoTextStart, (u64*)gspF3DLX2_Rej_fifoDataStart},/*3*/
    // {(u64*)gspL3DEX2_fifoTextStart, (u64*)gspL3DEX2_fifoDataStart},	/*4*/
    // {(u64*)gspS2DEX2_fifoTextStart, (u64*)gspS2DEX2_fifoDataStart},	/*5*/
};


static u16*	FrameBuf[3] = {
    (u16*)NU_GFX_FRAMEBUFFER0_ADDR,
    (u16*)NU_GFX_FRAMEBUFFER1_ADDR,
    (u16*)NU_GFX_FRAMEBUFFER2_ADDR
};

/*------------------------------------------------------*/
/*  Display list for first initializing the RDP. 	*/
/*------------------------------------------------------*/
static Gfx rdpstateinit_dl[] = {

    /* set all of the attribute registers to zero */
    gsDPSetEnvColor(0,0,0,0),
    gsDPSetPrimColor(0,0,0,0,0,0),
    gsDPSetBlendColor(0,0,0,0),
    gsDPSetFogColor(0,0,0,0),
    gsDPSetFillColor(0),
    gsDPSetPrimDepth(0,0),
    gsDPSetConvert(0,0,0,0,0,0),
    gsDPSetKeyR(0,0,0),
    gsDPSetKeyGB(0,0,0,0,0,0),

    /* set combine mode */
    gsDPSetCombineMode(G_CC_SHADE, G_CC_SHADE),

    /* initialize the scissor box */
    gsDPSetScissor(G_SC_NON_INTERLACE, 0, 0,
		   NU_GFX_INIT_SCREEN_WD, NU_GFX_INIT_SCREEN_HT),

    /* initialize all the texture tile descriptors to zero */
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0, 6, 0, 0, 0, 0, 0, 0, 0),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0),

    gsDPSetTileSize(0, 0, 0, (1 - 1) << G_TEXTURE_IMAGE_FRAC, (1 - 1) <<
		G_TEXTURE_IMAGE_FRAC),
    gsDPSetTileSize(1, 0, 0, (1 - 1) << G_TEXTURE_IMAGE_FRAC, (1 - 1) <<
		G_TEXTURE_IMAGE_FRAC),
    gsDPSetTileSize(2, 0, 0, (1 - 1) << G_TEXTURE_IMAGE_FRAC, (1 - 1) <<
		G_TEXTURE_IMAGE_FRAC),
    gsDPSetTileSize(3, 0, 0, (1 - 1) << G_TEXTURE_IMAGE_FRAC, (1 - 1) <<
		G_TEXTURE_IMAGE_FRAC),
    gsDPSetTileSize(4, 0, 0, (1 - 1) << G_TEXTURE_IMAGE_FRAC, (1 - 1) <<
		G_TEXTURE_IMAGE_FRAC),
    gsDPSetTileSize(5, 0, 0, (1 - 1) << G_TEXTURE_IMAGE_FRAC, (1 - 1) <<
		G_TEXTURE_IMAGE_FRAC),
    gsDPSetTileSize(6, 0, 0, (1 - 1) << G_TEXTURE_IMAGE_FRAC, (1 - 1) <<
		G_TEXTURE_IMAGE_FRAC),
    gsDPSetTileSize(7, 0, 0, (1 - 1) << G_TEXTURE_IMAGE_FRAC, (1 - 1) <<
		G_TEXTURE_IMAGE_FRAC),
    gsDPPipeSync(),
    gsSPEndDisplayList(),
};


/*----------------------------------------------------------------------*/
/*	nuGfxInit - Initialize the graphics thread and manager. 		*/
/*	IN:	Nothing in particular. 						*/
/*	RET:	None							*/
/*----------------------------------------------------------------------*/
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
