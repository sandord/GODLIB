/* ###################################################################################
#  INCLUDES
################################################################################### */

#include	"REL_FED.H"

#include	"FED.H"
#include	<GODLIB/ASSET/RELOCATE.H>


/* ###################################################################################
#  DATA
################################################################################### */

sRelocater 	gRelocator_FEDReloc;

/* ###################################################################################
#  PROTOTYPES
################################################################################### */

U32	Relocator_FED_IsType(     sAssetItem * apAsset );
U32	Relocator_FED_DoDelocate( sAssetItem * apAsset );
U32	Relocator_FED_DoRelocate( sAssetItem * apAsset );
U32	Relocator_FED_DoInit(     sAssetItem * apAsset );
U32	Relocator_FED_DoDeInit(   sAssetItem * apAsset );


/* ###################################################################################
#  CODE
################################################################################### */

/*-----------------------------------------------------------------------------------*
* FUNCTION : Relocator_FED_Init( void )
* ACTION   : Relocator_FED_Init
* CREATION : 06.01.2004 PNK
*-----------------------------------------------------------------------------------*/

void	Relocator_FED_Init( void )
{
	 Relocater_Init( &gRelocator_FEDReloc, "FED", Relocator_FED_IsType, Relocator_FED_DoInit, Relocator_FED_DoDeInit, Relocator_FED_DoRelocate, Relocator_FED_DoDelocate );
}


/*-----------------------------------------------------------------------------------*
* FUNCTION : Relocator_FED_DeInit( void )
* ACTION   : Relocator_FED_DeInit
* CREATION : 06.01.2004 PNK
*-----------------------------------------------------------------------------------*/

void	Relocator_FED_DeInit( void )
{
	Relocater_DeInit( &gRelocator_FEDReloc );
}


/*-----------------------------------------------------------------------------------*
* FUNCTION : Relocator_FED_IsType( sAssetItem * apAsset )
* ACTION   : Relocator_FED_IsType
* CREATION : 06.01.2004 PNK
*-----------------------------------------------------------------------------------*/

U32	Relocator_FED_IsType( sAssetItem * apAsset )
{
	(void)apAsset;
	return( 1 );
}


/*-----------------------------------------------------------------------------------*
* FUNCTION : Relocator_FED_DoRelocate( sAssetItem * apAsset )
* ACTION   : Relocator_FED_DoRelocate
* CREATION : 06.01.2004 PNK
*-----------------------------------------------------------------------------------*/

U32	Relocator_FED_DoRelocate( sAssetItem * apAsset )
{
	Fed_Relocate( (sFedHeader*)apAsset->mpData );
	return( 1 );
}


/*-----------------------------------------------------------------------------------*
* FUNCTION : Relocator_FED_DoDelocate( sAssetItem * apAsset )
* ACTION   : Relocator_FED_DoDelocate
* CREATION : 19.03.2005 PNK
*-----------------------------------------------------------------------------------*/

U32	Relocator_FED_DoDelocate( sAssetItem * apAsset )
{
	(void)apAsset;

/*	Fed_Delocate( (sFedHeader*)apData );*/
	return( 1 );
}


/*-----------------------------------------------------------------------------------*
* FUNCTION : Relocator_FED_DoInit( sAssetItem * apAsset )
* ACTION   : Relocator_FED_DoInit
* CREATION : 21.03.2004 PNK
*-----------------------------------------------------------------------------------*/

U32	Relocator_FED_DoInit( sAssetItem * apAsset )
{
	Fed_Init( (sFedHeader*)apAsset->mpData );
	Fed_Begin( (sFedHeader*)apAsset->mpData, "MAIN" );
	return( 1 );
}


/*-----------------------------------------------------------------------------------*
* FUNCTION : Relocator_FED_DoDeInit( sAssetItem * apAsset )
* ACTION   : Relocator_FED_DoDeInit
* CREATION : 21.03.2004 PNK
*-----------------------------------------------------------------------------------*/

U32	Relocator_FED_DoDeInit( sAssetItem * apAsset )
{
	Fed_DeInit( (sFedHeader*)apAsset->mpData );
	return( 1 );
}


/* ################################################################################ */
