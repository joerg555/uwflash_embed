/******************************************************************************
**              Copyright (C) 2005 Ezurio Ltd
**
** Project:		UWF Firmware file maker
**
** Module:		UWFLASH.H
**
** Notes:
**
*******************************************************************************/

#if !defined(_UWFLASH_H)     /* prevent multiple inclusions */
#define _UWFLASH_H

/******************************************************************************/
/* CONDITIONAL COMPILE DEFINES*/
/******************************************************************************/

/******************************************************************************/
/* Include Files*/
/******************************************************************************/
#include "UwgPublic.h"
#include "StdPublic.h"
#include "RbfPublic.h"

/******************************************************************************/
/* Local Defines*/
/******************************************************************************/



/******************************************************************************/
/* Local Macros*/
/******************************************************************************/

#define UwfASSERT(cond)         DEVASSERT(cond)
#define UwfMESSAGE(msg)         DEVMESSAGE(msg)
#define UwfFAIL(msg)            DEVFAIL(msg)

#define UwfASSERT1(cond)        DEVASSERT1(cond)
#define UwfMESSAGE1(msg)        DEVMESSAGE1(msg)
#define UwfFAIL1(msg)           DEVFAIL1(msg)

#define UwfASSERT2(cond)        DEVASSERT2(cond)
#define UwfMESSAGE2(msg)        DEVMESSAGE2(msg)
#define UwfFAIL2(msg)           DEVFAIL2(msg)

#define UwfASSERT3(cond)        DEVASSERT3(cond)
#define UwfMESSAGE3(msg)        DEVMESSAGE3(msg)
#define UwfFAIL3(msg)           DEVFAIL3(msg)


/******************************************************************************/
/* Local Forward Class,Struct & Union Declarations*/
/******************************************************************************/

/******************************************************************************/
/* Local Class,Struct,Union Typedefs*/
/******************************************************************************/

/*=============================================================================*/
/* This enum collects all module MMM specific result codes */
/*=============================================================================*/
enum
{
    UWRESULTCODE_UWF_EOF_DONOTUSE           = 0xC200
   ,UWRESULTCODE_UWF_UNKNOWN_PLATFORM       /*  C201 */
   ,UWRESULTCODE_UWF_COMPORT_OPENFAIL       /*  C202 */
   ,UWRESULTCODE_UWF_RESP_TIMEOUT           /*  C203 */
   ,UWRESULTCODE_UWF_NOT_ATS                /*  C204 */
   ,UWRESULTCODE_UWF_INVALID_FLASH          /*  C205 */
   ,UWRESULTCODE_UWF_INVALID_BANK           /*  C206 */
   ,UWRESULTCODE_UWF_NO_SECTOR_MAP          /*  C207 */
   ,UWRESULTCODE_UWF_SECTOR_MAP_EXISTS      /*  C208 */
   ,UWRESULTCODE_UWF_SECTOR_MAP_MISMATCH    /*  C209 */
   ,UWRESULTCODE_UWF_USER_CLOSE             /*  C20A */
   ,UWRESULTCODE_UWF_NOT_ACK                /*  C20B */
   ,UWRESULTCODE_UWF_ADDR_OUTOF_RANGE       /*  C20C */
   ,UWRESULTCODE_UWF_WRITE_TOO_LARGE        /*  C20D */
   ,UWRESULTCODE_UWF_VERIFY_FAIL            /*  C20E */
   ,UWRESULTCODE_UWF_NOT_DATA               /*  C20F */
   ,UWRESULTCODE_UWF_CHECKSUM_ERROR         /*  C210 */
   ,UWRESULTCODE_UWF_USER_ABORT             /*  C211 */
   ,UWRESULTCODE_UWF_NOT_QUERY_RESPONSE     /*  C212 */
   ,UWRESULTCODE_UWF_TEST_UNKNOWN           /*  C213 */
   ,UWRESULTCODE_UWF_MODULE_NOT_READY       /*  C214 */
   ,UWRESULTCODE_UWF_MODULE_RESP_FAIL       /*  C215 */

   /*
   ,UWRESULTCODE_UWF_
   */
};

/******************************************************************************/
/* External Variable Declarations*/
/******************************************************************************/

/******************************************************************************/
/* Global/Static Variable Declarations*/
/******************************************************************************/

/******************************************************************************/
/* External Function Declarations*/
/******************************************************************************/

/******************************************************************************/
/* Local Forward Function Declarations*/
/******************************************************************************/

/******************************************************************************/
/******************************************************************************/
/* Local Functions or Private Members*/
/******************************************************************************/
/******************************************************************************/

/******************************************************************************/
/******************************************************************************/
/* Global Functions or Public Members*/
/******************************************************************************/
/******************************************************************************/



#endif /* #if !defined(_PCFSA_H) */
/******************************************************************************/
/* END OF FILE*/
/******************************************************************************/
