#ifndef	INCLUDED_FADE_H
#define	INCLUDED_FADE_H

/* ###################################################################################
#  INCLUDES
################################################################################### */

#include	<GODLIB/BASE/BASE.H>


/* ###################################################################################
#  PROTOTYPES
################################################################################### */

void	Fade_Init( void );
void	Fade_DeInit( void );

void	Fade_PalST( U16 * apDest, U16 * apSrc, U16 * apTarget, U16 aColourCount, U16 aPos );
void	Fade_PalSTE( U16 * apDest, U16 * apSrc, U16 * apTarget, U16 aColourCount, U16 aPos );
void	Fade_PalFalcon( U32 * apDest, U32 * apSrc, U32 * apTarget, U16 aColourCount, U16 aPos );

void	Fade_Main( U16 * apPal, U16 aFrames );

void	Fade_StartVblFade( U16 * apPal, const U16 aFrames );
U8		Fade_IsVblFadeFinished( void );

U16 *	Fade_GetpBlackPal( void );
U16 *	Fade_GetpWhitePal( void );

void	Fade_SetGamma( const U16 aGamma );
void	Fade_UpdateCurrentPal( void );
void	Fade_SetPalDirect( U16 * apPal );

void	Fade_BuildGammaCorrectedPal( const U16 * apSrc, U16 * apDst );
void	Fade_SetCurrentBasePal( const U16 * apPal );


/* ################################################################################ */

#endif	/*	INCLUDED_VIDEO_H */
