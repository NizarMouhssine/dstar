/*
	* dstar.
	* Copyright (C) 2018 Jacopo De Luca
	*
	* This program is free software: you can redistribute it and/or modify
	* it under the terms of the GNU General Public License as published by
	* the Free Software Foundation, either version 3 of the License, or
	* (at your option) any later version.
	* This program is distributed in the hope that it will be useful,
	* but WITHOUT ANY WARRANTY; without even the implied warranty of
	* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
	* GNU General Public License for more details.
	* You should have received a copy of the GNU General Public License
	* along with this program. If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef DSTAR_CORE_H
#define DSTAR_CORE_H

#include <thread>
#include <list>
#include <string>
#include <spark.h>

#include <PacketInfo.h>
#include <DhcpAction.h>

#define SOCK_BUFSIZE    2048

class DhcpAction;

class Core {
private:
    std::thread thActions;
    std::list<DhcpAction *> actions;
    SpkSock *sock;
    unsigned char *buf;

    void executeActions();

    void recvDhcp();

public:
    bool stop = false;

    void openSocket(const std::string &interface);

    int sendDhcpMsg(DhcpPacket *message, unsigned short len, PacketInfo *pktInfo);

    void registerAction(DhcpAction *action);
};


#endif //DSTAR_CORE_H