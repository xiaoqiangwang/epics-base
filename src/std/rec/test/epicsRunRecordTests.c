/*************************************************************************\
* Copyright (c) 2012 UChicago Argonne LLC, as Operator of Argonne
*     National Laboratory.
* EPICS BASE is distributed subject to a Software License Agreement found
* in file LICENSE that is included with this distribution.
\*************************************************************************/

/*
 * Run tests as a batch.
 */

#include "epicsUnitTest.h"
#include "epicsExit.h"

int analogMonitorTest(void);
int compressTest(void);
int arrayOpTest(void);
int asTest(void);
int linkRetargetLinkTest(void);

void epicsRunRecordTests(void)
{
    testHarness();

    runTest(analogMonitorTest);

    runTest(compressTest);

    runTest(arrayOpTest);

    runTest(asTest);

    runTest(linkRetargetLinkTest);

    epicsExit(0);   /* Trigger test harness */
}
