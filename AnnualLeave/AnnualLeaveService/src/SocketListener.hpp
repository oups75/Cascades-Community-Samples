/*
 * Copyright (c) 2014 BlackBerry Limited.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef SOCKETLISTENER_HPP_
#define SOCKETLISTENER_HPP_

#include "common.hpp"
#include <Operations.hpp>

#include <QObject>
#include <QtNetwork/QLocalSocket>
#include <QtNetwork/QLocalServer>

class SocketListener
	: public QObject
{
	Q_OBJECT

public:
	virtual ~SocketListener();
    static SocketListener *getInstance(QObject *parent);
	void listen();

private slots:
	void onNewConnection();
	void onDisconnected();
	void onReadyRead();
	void onMessageForUi(const QVariant &text);

private:
	SocketListener(QObject *parent = NULL);
    static SocketListener *_instance;
	void disconnectSocket();
	bool socketIsConnected();

	QLocalServer *_server;
	QLocalSocket *_socket;
    Operations *_ops;
};

#endif /* SOCKETLISTENER_HPP_ */
