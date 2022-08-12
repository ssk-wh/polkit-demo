/*
 * Copyright (C) 2019 ~ 2022 Uniontech Technology Co., Ltd.
 *
 * Author:     fanpengcheng <fanpengcheng@uniontech.com>
 *
 * Maintainer: fanpengcheng <fanpengcheng@uniontech.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "dbus_manager.h"

#include <QLibrary>
#include <QDebug>
#include <QDir>
#include <QTimer>
#include <QLoggingCategory>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonParseError>
#include <QDBusServiceWatcher>
#include <QDBusConnection>
#include <QDBusConnectionInterface>

#include <polkit-qt5-1/PolkitQt1/Authority>

using namespace PolkitQt1;

DBusManager::DBusManager(QObject *parent)
    : QObject(parent)

{

}

void DBusManager::DobyRoot()
{
    uint pid = connection().interface()->servicePid(message().service());
    qDebug() << "caller pid:" << pid;

    Authority::Result result;
    result = Authority::instance()->checkAuthorizationSync("com.deepin.polkit.demo.fun1"
                                                           , UnixProcessSubject(pid)// 注意这里传递的是调用者的pid
                                                           , Authority::AllowUserInteraction);
    if (result == Authority::Yes) {
        qDebug() << "Now, we can do anything!";

        // 接口调用者身份可信，允许此操作执行

        qDebug() << "Done, good job!";
    }else{
        qWarning() << "Permission denied!";
    }
}

