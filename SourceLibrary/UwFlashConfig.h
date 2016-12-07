/******************************************************************************
**              Copyright (C) 2002 TDK Systems Europe Ltd
**
** Project:
**
** Module:      UwFlashConfig.H
**
*******************************************************************************/
DO NOT INCLUDE THIS FILE

#if !defined(_UWFLASHCONFIG_H)     /* prevent multiple inclusions */
#define _UWFLASHCONFIG_H

/******************************************************************************/
// Include Files
/******************************************************************************/
#include "Target.h"
#include "project.h"

/******************************************************************************/
// Defines
/******************************************************************************/

/******************************************************************************/
// Macros
/******************************************************************************/

/******************************************************************************/
// Enum Typedefs
/******************************************************************************/

typedef enum
{
    //The values in this enum MUST match the item index values
    //in the radiogroup in the main form.

    UPGFILE_UWF                     = 0
}
UPGRADE_FILETYPE;

typedef enum
{
    TARGET_WITS_VU                  = 0
   ,TARGET_LEGACY_WISM
   ,TARGET_WISM2B
   ,TARGET_WISM4B
   ,TARGET_WISM8
   ,TARGET_BL600
   ,TARGET_BL620
   ,TARGET_BT900_9K6
   ,TARGET_BT900
   ,TARGET_BL6XX                    /* Any BL6xx based hardware with new bootloader */

   ,TARGET_PREPROCESS_MASK          = 0x8000
   ,TARGET_UNKNOWN                  = 0xFFFF
}
ETargetType;

#define TARGET_WITS_VU_STR          "WitsVehicleUnit"
#define TARGET_LEGACY_WISM_STR      "LegacyWism"
#define TARGET_WISM2B_STR           "Wism2MB_Banked"
#define TARGET_WISM4B_STR           "Wism4MB_Banked"
#define TARGET_WISM8_STR            "Wism8MB"
#define TARGET_BL600_STR            "BL600"
#define TARGET_BL620_STR            "BL620"
#define TARGET_BT900_9K6_STR        "BT900(9600)"
#define TARGET_BT900_STR            "BT900"
#define TARGET_BL6XX_STR            "BL6XX"

/******************************************************************************/
// Simple (non struct/union) Typedefs
/******************************************************************************/

/******************************************************************************/
// Forward declaration of Class, Struct & Unions
/******************************************************************************/

/******************************************************************************/
// Struct definitions
/******************************************************************************/

typedef struct
{
    int                  mnBaudrate;
    int                  mnDataBits;
    int                  mnStopBits;
    int                  mnParity;
}
COMPARMS;

/******************************************************************************/
// Class definitions
/******************************************************************************/

class UwFlashConfig
{
//Data
private:

//Data
protected:

//Data
public:
    int                  mnComPort;
    COMPARMS             mUserCommParms;
    UPGRADE_FILETYPE     mUpgFileType;
    bool                 mfForceDownload;
    bool                 mfAutomaticMode;
    bool                 mfAlreadyInLoaderMode;
    bool                 mfVirtualPort;
    bool                 mfMultiProg;
    bool                 mfAutoExit;
    ETargetType          mTargetType;
    UI32                 mTotalEraseByteEquiv;
    UI32                 mTotalWriteLen;
    UI32                 mEraseDefEq;
    UI32                 mEraseDefSize;
    INT                  mTestNum;

//Functions
private:

//Functions
protected:

//Functions
public:
    UwFlashConfig();
    virtual ~UwFlashConfig();
};


/******************************************************************************/
// Union definitions
/******************************************************************************/

/******************************************************************************/
// Global Functions (API etc) exported for other modules
/******************************************************************************/
extern UwFlashConfig  gUwFlashConfig;

#endif /* Prevention of multiple inclusion */
/******************************************************************************/
// END OF FILE
/******************************************************************************/
