/******************************************************************************
**              Copyright (C) 2015 Laird
**
** Project:     UwFlash
**
** Module:      TBootLdrRM1XX_PE.h
**
*******************************************************************************/

#if !defined(_TBOOTLDRRM1XX_PE_H)     /* prevent multiple inclusions */
#define _TBOOTLDRRM1XX_PE_H

/******************************************************************************/
// Include Files
/******************************************************************************/
#include "Target.h"
#include "project.h"
#include "TBootLdrProtV3.h"
#include "AtConfig.h"

/******************************************************************************/
// Defines
/******************************************************************************/

#define RM1XX_PE_NORMAL_MODE_BAUDRATE              (115200)

/******************************************************************************/
// Macros
/******************************************************************************/

/******************************************************************************/
// Enum Typedefs
/******************************************************************************/

/******************************************************************************/
// Simple (non struct/union) Typedefs
/******************************************************************************/

/******************************************************************************/
// Forward declaration of Class, Struct & Unions
/******************************************************************************/

/******************************************************************************/
// Struct definitions
/******************************************************************************/

/******************************************************************************/
// Class definitions
/******************************************************************************/

class TBootLdrRM1XX_PE : public TBootLdrProtV3
{
//Data
private:

//Data
protected:

//Data
public:

//Functions
private:

//Functions
protected:

//Functions
public:
    TBootLdrRM1XX_PE();
    virtual ~TBootLdrRM1XX_PE();

    virtual UWRESULTCODE DriveModuleResetLine(bool fAssert);
    virtual UWRESULTCODE SwitchModuleToProgramMode(void);
    virtual VOID OnFailSwitchModuleToProgramMode(void);
    virtual bool CheckPlatform(UI32  nPlatform);
    virtual bool IsCtsAsserted(void);
    virtual void WaitForCtsOrTimeout(unsigned int nDelayMs, bool fTargetCtsState );

};


/******************************************************************************/
// Union definitions
/******************************************************************************/

/******************************************************************************/
// Global Functions (API etc) exported for other modules
/******************************************************************************/

#endif /* Prevention of multiple inclusion */
/******************************************************************************/
// END OF FILE
/******************************************************************************/