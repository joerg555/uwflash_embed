// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Copyright (c) 2016, Laird                                                  ++
//                                                                            ++
// Permission to use, copy, modify, and/or distribute this software for any   ++
// purpose with or without fee is hereby granted, provided that the above     ++
// copyright notice and this permission notice appear in all copies.          ++
//                                                                            ++
// THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES   ++
// WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF           ++
// MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR    ++
// ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES     ++
// WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN      ++
// ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR ++
// IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.                ++
//                                                                            ++
// SPDX-License-Identifier:ISC                                                ++
//                                                                            ++
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//                                                                            ++
// Source to embed firmware upgrader functionality into a host system which   ++
// interacts with specific Laird modules. The host can be a microcontroller   ++
// or full blown OS based PC like Windows/Linex/Mac or other.                 ++
//                                                                            ++
// The source requires a C++ compiler and has been used to create utilities   ++
// supplied by Laird.                                                         ++
//                                                                            ++
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

/******************************************************************************/
/* Target Build Definition Header File */
/******************************************************************************/
#include "Target.h"

/******************************************************************************/
/* CONDITIONAL COMPILE DEFINES*/
/******************************************************************************/

/******************************************************************************/
/* Include Files*/
/******************************************************************************/
#include "BlrPublic.h"
#include "BlrPrivate.h"

/******************************************************************************/
/* Local Defines*/
/******************************************************************************/

/******************************************************************************/
/* Local Macros*/
/******************************************************************************/

/******************************************************************************/
/* Local Forward Class,Struct & Union Declarations*/
/******************************************************************************/

/******************************************************************************/
/* Local Class,Struct,Union Typedefs*/
/******************************************************************************/

/******************************************************************************/
/* External Variable Declarations*/
/******************************************************************************/

/******************************************************************************/
/* Global/Static Variable Declarations*/
/******************************************************************************/

/******************************************************************************/
/* External Function Declarations*/
/******************************************************************************/

VOID *
BlrPubOpenCPP(
    UWRESULTCODE *pResultCode
    );

VOID
BlrPubCloseCPP(
    VOID *pBlrContext
    );

BOOL
BlrPubCheckPlatformCPP(
    VOID *pBlrContext,
    UI32  nPlatform
    );

UWRESULTCODE
BlrPubRegisterDeviceCPP(
    VOID *pBlrContext,
    UI8  nFlashDevice,
    UI32 nBaseAddress,
    UI8  nNumOfBanks,
    UI32 nBankSize,
    UI8  nBankSelAlgoFuncId
    );

UWRESULTCODE
BlrPubUnregisterDeviceCPP(
    VOID *pBlrContext,
    UI8  nFlashDevice
    );

UWRESULTCODE
BlrPubSetBankCPP(
    VOID *pBlrContext,
    UI8  nFlashDevice,
    UI8  nBank
    );

UWRESULTCODE
BlrPubWriteBlockHeaderCPP(
    VOID *pBlrContext,
    UI32  nOffset,
    UI32  nBlockLenBytes,
    UI32  nFlags
    );

UWRESULTCODE
BlrPubWriteBlockEndCPP(
    VOID *pBlrContext
    );

UWRESULTCODE
BlrPubWriteBlockCPP(
    VOID *pBlrContext,
    UI8  *pData,
    UI32  nAddrOffset,
    UI32  nBlockLenBytes
    );

UWRESULTCODE
BlrPubEraseBlockCPP(
    VOID *pBlrContext,
    UI32  nAddrOffsetStart,
    UI32  nBlockSize
    );

UWRESULTCODE
BlrPubSectorMapCPP(
    VOID *pBlrContext,
    SBlrSectorMapItem *pSectorMapArray,
    UI32 nNumOfItems
    );

UWRESULTCODE
BlrPubAutoSelectBankCPP(
    VOID *pBlrContext,
    UI8  nFlashDevice,
    UI8  *pBank
    );

UWRESULTCODE
BlrPubQueryCPP(
    VOID *pBlrContext,
    UI32  nQueryId,
    UI32  *pQueryVals,
    UI16  nNumOfVals
    );

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


/*=============================================================================*/
/*
** Open the boot loader manager session
*/
/*=============================================================================*/
VOID *
BlrPubOpen(
    UWRESULTCODE *pResultCode
    )
{
    return BlrPubOpenCPP(pResultCode);
}

/*=============================================================================*/
/*
** Close the boot loader manager session
*/
/*=============================================================================*/
VOID
BlrPubClose(
    VOID *pBlrContext
    )
{
    BlrPubCloseCPP(pBlrContext);
}


/*=============================================================================*/
/*
** Returns true if nPlatform matches the target platform this code is running
** on
*/
/*=============================================================================*/
BOOLEAN
BlrPubCheckPlatform(
    VOID *pBlrContext,
    UI32  nPlatform
    )
{
    return BlrPubCheckPlatformCPP(pBlrContext,nPlatform);
}

/*=============================================================================*/
/*
** Register a flash device for manipulation
*/
/*=============================================================================*/
UWRESULTCODE
BlrPubRegisterDevice(
    VOID *pBlrContext,
    UI8  nFlashDevice,
    UI32 nBaseAddress,
    UI8  nNumOfBanks,
    UI32 nBankSize,
    UI8  nBankSelAlgoFuncId
    )
{
    return BlrPubRegisterDeviceCPP(pBlrContext,nFlashDevice,nBaseAddress,nNumOfBanks,nBankSize,nBankSelAlgoFuncId);
}

/*=============================================================================*/
/*
** Unregister a flash device for manipulation
*/
/*=============================================================================*/
UWRESULTCODE
BlrPubUnregisterDevice(
    VOID *pBlrContext,
    UI8  nFlashDevice
    )
{
    return BlrPubUnregisterDeviceCPP(pBlrContext,nFlashDevice);
}

/*=============================================================================*/
/*
** Instructs the boot loader to make the bank available for the flash device
*/
/*=============================================================================*/
UWRESULTCODE
BlrPubSetBank(
    VOID *pBlrContext,
    UI8  nFlashDevice,
    UI8  nBank
    )
{
    return BlrPubSetBankCPP(pBlrContext,nFlashDevice,nBank);
}

/*=============================================================================*/
/*
** Pass WRITE_BLOCK header to the lower layers
*/
/*=============================================================================*/
UWRESULTCODE
BlrPubWriteBlockHeader(
    VOID *pBlrContext,
    UI32  nOffset,
    UI32  nBlockLenBytes,
    UI32  nFlags
    )
{
    return BlrPubWriteBlockHeaderCPP(pBlrContext,nOffset,nBlockLenBytes,nFlags);
}

/*=============================================================================*/
/*
** Called to end the WRITE_BLOCK packet processing
*/
/*=============================================================================*/
UWRESULTCODE
BlrPubWriteBlockEnd(
    VOID *pBlrContext
    )
{
    return BlrPubWriteBlockEndCPP(pBlrContext);
}

/*=============================================================================*/
/*
** Write the data at pData to the current bootloader activated flash
*/
/*=============================================================================*/
UWRESULTCODE
BlrPubWriteBlock(
    VOID *pBlrContext,
    UI8  *pData,
    UI32  nAddrOffset,
    UI32  nBlockLenBytes
    )
{
    return BlrPubWriteBlockCPP(pBlrContext,pData,nAddrOffset,nBlockLenBytes);
}

/*=============================================================================*/
/*
** Erase from start to end specified
*/
/*=============================================================================*/
UWRESULTCODE
BlrPubEraseBlock(
    VOID *pBlrContext,
    UI32  nAddrOffsetStart,
    UI32  nBlockSize
    )
{
    return BlrPubEraseBlockCPP(pBlrContext,nAddrOffsetStart,nBlockSize);
}

/*=============================================================================*/
/*
** Specify Sector Map
*/
/*=============================================================================*/
UWRESULTCODE
BlrPubSectorMap(
    VOID *pBlrContext,
    SBlrSectorMapItem *pSectorMapArray,
    UI32 nNumOfItems
    )
{
    return BlrPubSectorMapCPP(pBlrContext,pSectorMapArray,nNumOfItems);
}


/*=============================================================================*/
/*
** Asks the boot loader to choose a bank from the flash device selected
*/
/*=============================================================================*/
UWRESULTCODE
BlrPubAutoSelectBank(
    VOID *pBlrContext,
    UI8  nFlashDevice,
    UI8  *pBank
    )
{
    return BlrPubAutoSelectBankCPP(pBlrContext,nFlashDevice,pBank);
}

/*=============================================================================*/
/*
** Send a query to the boot loader
*/
/*=============================================================================*/
UWRESULTCODE
BlrPubQuery(
    VOID *pBlrContext,
    UI32  nQueryId,
    UI32  *pQueryVals,
    UI16  nNumOfVals
    )
{
    return BlrPubQueryCPP(pBlrContext,nQueryId,pQueryVals,nNumOfVals);
}



/******************************************************************************/
/* END OF FILE*/
/******************************************************************************/
