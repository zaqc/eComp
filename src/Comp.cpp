/*
 * Copyright (C) Your copyright.
 *
 * Author: zaqc
 *
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * Neither the name of the PG_ORGANIZATION nor the
 *       names of its contributors may be used to endorse or promote products
 *       derived from this software without specific prior written permission.
 * 
 * THIS SOFTWARE IS PROVIDED BY	THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS-IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE 
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE 
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR 
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF 
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS 
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN 
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) 
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE 
 * POSSIBILITY OF SUCH DAMAGE.
 */

#include <stdio.h>
#include <pthread.h>

#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <string.h>

#include <iostream>

#include <stdlib.h>

#include "XThread.h"
#include "XSocket.h"
#include "MessageThread.h"

int m_ServerSocket = -1;

void *thread_proc(void *aParam) {

	usm::XSafeVal<int> val;
	val = 10;
	int v = val;

	m_ServerSocket = socket(AF_INET, SOCK_STREAM, 0);
	std::cout << "Socket handle is : " << m_ServerSocket << std::endl;

	sockaddr_in addr;
	bzero((char*) &addr, sizeof(sockaddr_in));
	addr.sin_family = AF_INET;
	addr.sin_addr.s_addr = INADDR_ANY;
	addr.sin_port = htons(17345);
	if (0 != bind(m_ServerSocket, (sockaddr*) &addr, sizeof(sockaddr_in)))
		throw "Can't bind main server socket...";
	if (0 != listen(m_ServerSocket, 5))
		throw "Can't listen main server socket...";

	sockaddr_in client_addr;
	socklen_t client_addr_len = sizeof(sockaddr_in);
	while (true) {
		int client_sock = accept(m_ServerSocket, (sockaddr*) &client_addr,
				&client_addr_len);

		std::cout << "Client accepted (" << client_sock << ") from address="
				<< inet_ntoa(client_addr.sin_addr) << std::endl;

		if (client_sock < 0) {
			break;
		}
	}

	printf("printing text from thread \n");
	return NULL;
}

int main(void) {
	pthread_t thread;
	pthread_create(&thread, NULL, thread_proc, NULL);

	getchar();

	shutdown(m_ServerSocket, SHUT_RDWR);
	close(m_ServerSocket);

	pthread_join(thread, NULL);

	printf("Hello world !!!\n");
	return 0;
}
