

/*  $Id$
 *
 *                    L O S  A L A M O S
 *              Los Alamos National Laboratory
 *               Los Alamos, New Mexico 87545
 *
 *  Copyright, 1986, The Regents of the University of California.
 *
 *  Author: Jeff Hill
 */

#include <float.h>

#include "iocinf.h"

cacChannelIO::cacChannelIO ( cacChannel &chanIn ) :
    chan ( chanIn ) 
{
}

cacChannelIO::~cacChannelIO ()
{
    this->chan.pChannelIO = 0;
}

cacLocalChannelIO::cacLocalChannelIO ( cac &cacCtxIn, cacChannel &chan ) :
  cacChannelIO ( chan ), cacCtx ( cacCtxIn ) {};

cacLocalChannelIO::~cacLocalChannelIO ()
{
    this->cacCtx.uninstallLocalChannel ( *this );
}

void cacChannelIO::connectNotify ()
{
    this->chan.connectNotify ();
}

void cacChannelIO::disconnectNotify ()
{
    this->chan.disconnectNotify ();
}

void cacChannelIO::connectTimeoutNotify ()
{
    this->chan.connectTimeoutNotify ();
}

void cacChannelIO::accessRightsNotify ( caar ar )
{
    this->chan.accessRightsNotify ( ar );
}

void cacChannelIO::ioReleaseNotify ()
{
    this->chan.ioReleaseNotify ();
}

channel_state cacChannelIO::state () const 
{
    return cs_conn;
}

caar cacChannelIO::accessRights () const 
{
    // static here avoids undefined memory read warning from
    // error checking codes
    static caar ar = { true, true };
    return ar;
}

unsigned cacChannelIO::searchAttempts () const 
{
    return 0u;
}

double cacChannelIO::beaconPeriod () const 
{
    return - DBL_MAX;
}

bool cacChannelIO::ca_v42_ok () const 
{
    return true;
}

bool cacChannelIO::connected () const 
{
    return true;
}

unsigned cacChannelIO::readSequence () const 
{
    return 0u;
}

void cacChannelIO::hostName ( char *pBuf, unsigned bufLength ) const 
{
    if ( bufLength ) {
        localHostNameAtLoadTime.copy (pBuf, bufLength );
    }
}

// deprecated - please do not use
const char * cacChannelIO::pHostName () const
{
    return localHostNameAtLoadTime.pointer ();
}

void cacChannelIO::incrementOutstandingIO ()
{
}

void cacChannelIO::decrementOutstandingIO ()
{
}

void cacChannelIO::lockOutstandingIO () const
{
}

void cacChannelIO::unlockOutstandingIO () const
{
}


