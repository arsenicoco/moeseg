#pragma once

/****************************************************************************
** Copyright (c) onbudgetandtime.com All rights reserved.
**
** This file is part of the Moeseg Engine
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
**
****************************************************************************/

#ifndef MOESEG_DEF
#define MOESEG_DEF

// Type for Ethic related attribute
typedef int EthicalAttribute;

// Type for std string 
typedef std::string CString;

// type for collection of ethical attributes
typedef std::vector<EthicalAttribute> EthicalAttributeCollection;

// Ethical attribute values
//Green
const EthicalAttribute Green	= 1;
// Vegan
const EthicalAttribute Vegan	= 2;
// Halal
const EthicalAttribute Halal	= 4;
// Kosher
const EthicalAttribute Kosher	= 8;
// Custom attribute
const EthicalAttribute Custom	= 16;

#endif //MOESEG_DEF