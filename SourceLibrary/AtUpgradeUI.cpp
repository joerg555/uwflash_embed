/******************************************************************************
**              Copyright (C) 2002 TDK Systems Europe Ltd
**
** Project:     TDK Intelligent Serial Dongle - Upgrade Class
**
** Module:      ATUPGRADEUI.CPP
**
*******************************************************************************/

/******************************************************************************/
// CONDITIONAL COMPILE DEFINES
/******************************************************************************/

/******************************************************************************/
// Include Files
/******************************************************************************/
#include <stdlib.h>
#include <stdio.h>

#include "AtUpgradeUI.h"
#include "UwFlash.h"
#include "Misc.h"

/******************************************************************************/
// Local Defines
/******************************************************************************/

/******************************************************************************/
// Local Macros
/******************************************************************************/

/******************************************************************************/
// Local Forward Class,Struct & Union Declarations
/******************************************************************************/

/******************************************************************************/
// Local Class,Struct,Union Typedefs
/******************************************************************************/

/******************************************************************************/
// External Variable Declarations
/******************************************************************************/

/******************************************************************************/
// Global/Static Variable Declarations
/******************************************************************************/
AtUpgradeUI *gpAtUpgradeUI = NULL;

#if DEBUGLEVEL > 2
static char baMsg[2048];
#endif

/******************************************************************************/
// External Function Declarations
/******************************************************************************/

/******************************************************************************/
// Local Forward Function Declarations
/******************************************************************************/

/******************************************************************************/
/******************************************************************************/
// Local Functions or Private Members
/******************************************************************************/
/******************************************************************************/

//=============================================================================
//=============================================================================

/******************************************************************************/
/******************************************************************************/
// Global Functions or Public Members
/******************************************************************************/
/******************************************************************************/

//------------------------------------------------------------------------------
// Constructor
//------------------------------------------------------------------------------
AtUpgradeUI::AtUpgradeUI()
{
    mLangId  = ATUPG_LANGID_ENGLISH;
}

//------------------------------------------------------------------------------
// Destructor
//------------------------------------------------------------------------------
AtUpgradeUI::~AtUpgradeUI()
{
}

//=============================================================================
//=============================================================================
UI32 AtUpgradeUI::TimeElapsed(UI32 nTickStart)
{
    UI32 nTickNow;
    UI32 nElapsed;

    nTickNow=MiscGetTickCount();
    if(  nTickNow >=  nTickStart )
    {
        nElapsed =  nTickNow -  nTickStart;
    }
    else
    {
        nElapsed = 0xFFFFFFFF -  nTickStart;
        nElapsed += nTickNow;
    }
    return  nElapsed;
}

/*=============================================================================*/
/*=============================================================================*/
UWRESULTCODE AtUpgradeUI::Sleep(UI32 nSleepMs, bool fDisplayProgress)
{
    UI32 nTickStart=MiscGetTickCount();
    UI32 nElapsed;

    if(fDisplayProgress)
    {
        InitAndShowProgressBar(0,nSleepMs);
    }
    nElapsed = TimeElapsed(nTickStart);
    while( nElapsed < nSleepMs )
    {
        UpdateProgressBar(nElapsed);
        if( MiscPollBackground() )
        {
            if(fDisplayProgress)
            {
                HideProgressBar();
            }
            return UWRESULTCODE_UWF_USER_CLOSE;
        }
        nElapsed = TimeElapsed(nTickStart);
    }
    if(fDisplayProgress)
    {
        HideProgressBar();
    }
    MiscPollBackground();
    return UWRESULTCODE_SUCCESS;
}

/*=============================================================================*/
/*=============================================================================*/
char * AtUpgradeUI::GetText(int nMsgId)
{
    static char baMsg[16];
    sprintf(baMsg,"%d",nMsgId);
    return baMsg;
}

/*=============================================================================*/
/*=============================================================================*/
void AtUpgradeUI::Message(int nMsgId)
{
    if(nMsgId < ENUM_ATUPG_MSGID(LAST_ID))
    {
#if DEBUGLEVEL <= 2
        char baMsg[16];
#endif
        sprintf(baMsg,"%d",nMsgId);
        WriteToMemo(baMsg);
    }
}

/*=============================================================================*/
/*=============================================================================*/
void AtUpgradeUI::Message(int nMsgId, int nParam)
{
    if(nMsgId < ENUM_ATUPG_MSGID(LAST_ID))
    {
#if DEBUGLEVEL <= 2
        char baMsg[32];
#endif
        sprintf(baMsg,"%d(%d)",nMsgId,nParam);
        WriteToMemo(baMsg);
    }
}

/*=============================================================================*/
/*=============================================================================*/
void AtUpgradeUI::Message(int nMsgId, int nParam1,int nParam2,int nParam3,int nParam4,int nParam5 )
{
    if(nMsgId < ENUM_ATUPG_MSGID(LAST_ID) )
    {
#if DEBUGLEVEL <= 2
        char baMsg[64];
#endif
        sprintf(baMsg,"%d(%d,%d,%d,%d,%d)",nMsgId,nParam1,nParam2,nParam3,nParam4,nParam5);
        WriteToMemo(baMsg);
    }
}

/*=============================================================================*/
/*=============================================================================*/
void AtUpgradeUI::Message(int nMsgId, char *pStr)
{
    if(nMsgId < ENUM_ATUPG_MSGID(LAST_ID) )
    {
#if DEBUGLEVEL <= 2
        char baMsg[256];
#endif
        sprintf(baMsg,"%d(%s)",nMsgId,pStr);
        WriteToMemo(baMsg);
    }
}

/*=============================================================================*/
/*=============================================================================*/
const char *UwgResultCodeString(UWRESULTCODE resCode)
{
    static char baMsg[16];
    sprintf(baMsg,"%d",resCode);
    return baMsg;
}
/******************************************************************************/
// END OF FILE
/******************************************************************************/

