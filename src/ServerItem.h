/*
 * ServerItem.h
 *
 *  Created on: Mar 27, 2015
 *      Author: zaqc
 */

#ifndef SERVERITEM_H_
#define SERVERITEM_H_

#include "XThread.h"

class ServerItem {
public:
	ServerItem();
	virtual ~ServerItem();
};

class ServerThread {
public:
	ServerThread();
	virtual ~ServerThread();
};

#endif /* SERVERITEM_H_ */
