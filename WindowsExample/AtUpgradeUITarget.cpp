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
// CONDITIONAL COMPILE DEFINES
/******************************************************************************/

/******************************************************************************/
// Include Files
/******************************************************************************/
#include <stdlib.h>
#include <stdio.h>

#include "AtUpgradeUITarget.h"
#include "UwFlash.h"

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

/******************************************************************************/
/******************************************************************************/
// Global Functions or Public Members
/******************************************************************************/
/******************************************************************************/

//------------------------------------------------------------------------------
// Constructor
//------------------------------------------------------------------------------
AtUpgradeUITarget::AtUpgradeUITarget()
{
}

//------------------------------------------------------------------------------
// Destructor
//------------------------------------------------------------------------------
AtUpgradeUITarget::~AtUpgradeUITarget()
{
}

//------------------------------------------------------------------------------
// If your system has a display or console output, then send the string in pMsg
// to that.
//------------------------------------------------------------------------------
void AtUpgradeUITarget::WriteToMemo(char *pMsg)
{
    printf("\n%s",pMsg);
}

/*=============================================================================*/
//
// This is called on startup to help you display a progress bar if you have a
// user interface. Use maxval as guide with regards to how much 100% progress
// means
//
UI32 gMinVal,gMaxVal,gChunk,gCount;
/*=============================================================================*/
void AtUpgradeUITarget::InitAndShowMainProgressBar(UI32 minVal, UI32 maxVal)
{
    gMinVal = minVal;
    gMaxVal = maxVal;
    gChunk =  (maxVal - minVal)/100;
    gCount = 0;
    //printf("\nINIT %d %d",minVal,maxVal);
}

/*=============================================================================*/
// As the upgrade process advances this function is called with a value which
// will be in the range minVal and maxVal (as provided by InitAndShowMainProgressBar()
// which then allows you to judge a progress bar of appropriate legth.
/*=============================================================================*/
void AtUpgradeUITarget::UpdateMainProgressBar(UI32 curVal)
{
    if(gCount<curVal)
    {
        printf(".");
        gCount +=  gChunk;
    }
}

/*=============================================================================*/
// This is called when an assert fails
/*=============================================================================*/
extern "C"
UI16 DisplayAssertMessage(char *pMsg)
{
    printf("\n\n\nASSERT/FAIL : %s\n\n", pMsg );
    return 0;
}

/*=============================================================================*/
// This is called when a trace message is to displayed
/*=============================================================================*/
extern "C"
VOID DisplayTraceMessage(char *pMsg)
{
    printf("\n\n\nTRACE : %s\n\n", pMsg );
}

/******************************************************************************/
// END OF FILE
/******************************************************************************/

