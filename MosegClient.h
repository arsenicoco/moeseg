#pragma once

/****************************************************************************
** Copyright (c) onbudgetandtime.com All rights reserved.
**
** This file is part of the Moseg Engine
**
** This file may be distributed under the terms of the onbudgetandtime.com
** license as defined by onbudgetandtime.com and appearing in the file
** LICENSE included in the packaging of this file.
**
** This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING THE
** WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
**
** See http://www.onbudgetandtime.com for more information.
** 
** Usage example:
      CString strSettingsFilename; // get filename of the setting file here
		FIX::Message msg; // construct FIX message here
		CMosegClient client;
		client.ApplySettings(strSettingsFilename);
		if (IfMessageValid(Green))
		{
			client.SendMessage(message);
		}
** 
****************************************************************************/

#ifndef MOSEG_CLIENT
#define MOSEG_CLIENT

#ifdef _MSC_VER
#pragma warning( disable: 4786 )
#endif

#include <Message.h>
#include "Moseg.h"

using namespace std;


class CMosegClient
{
public:

	// ApplySettings initialize parameters of the class with values from 
	// configuration file.
	void ApplySettings( CString fileName );
	
	// GetValidEthicalAttributes verifies Message instance agains requirements of ethical modules 
	// installed in the system. Method returns collection of ethical attibutes which are met 
	// for given message.
	EthicalAttributeCollection GetValidEthicalAttributes( FIX::Message );

	// IsMessageValid verifies Message instance agains requirements of ethical module defined 
	// by given attribute. 
	BOOL IsMessageValid( FIX::Message, EthicalAttribute );

	// SendMessage sends FIX message to FIX engine without ethical attributes verification.
	// Verifiication could be done by IfMessageValid or GetValidEthicalAttributes methods
	void SendMessage( FIX::Message);

	// SendMessage sends FIX message to FIX engine. Message processing is defined by
	// ethical attributes.
	void SendMessage( FIX::Message, EthicalAttributeCollection );

	// OnCreate gets called when quickfix creates a new session. A session comes into and
	// remains in existence for the life of the application. Sessions exist 
	// whether or not a counter party is connected to it. As soon as a session
	// is created, you can begin sending messages to it. If no one is logged 
	// on, the messages will be sent at the time a connection is established 
	// with the counterparty. 
	void OnCreate( const FIX::SessionID& );

	// OnLogon notifies when a valid logon has been established with a 
	// counter party. This is called when a connection has been established and 
	// the FIX logon process has completed with both parties exchanging 
	// valid logon messages. 
	void OnLogon( const FIX::SessionID& );

	// OnLogout notifies when an FIX session is no longer online. This could happen 
	// during a normal logout exchange or because of a forced termination 
	// or a loss of network connection.  
	void OnLogout( const FIX::SessionID& );

	// OnMessageSent notifies  wheb FIX session end recieving a message successfully.
	void OnMessageSent(const FIX::SessionID& );
};


#endif // MOSEG_CLIENT