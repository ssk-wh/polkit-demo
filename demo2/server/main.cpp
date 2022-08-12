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

#include <QCoreApplication>
#include <QDBusConnection>
#include <QDebug>
#include "dbus_manager.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    DBusManager manager;

    // 注册system级别的com.deepin.dde.pokit.demo服务
    if (!QDBusConnection::systemBus().registerService("com.deepin.dde.pokit.demo")) {
        qDebug() << "DBus register failed,  error message:" << QDBusConnection::systemBus().lastError().message();
        exit(-1);
    }

    // 导出DobyRoot方法，供其他进程调用
    QDBusConnection::systemBus().registerObject("/com/deepin/dde/pokit/demo"
                                                , "com.deepin.dde.pokit.demo"
                                                , &manager
                                                , QDBusConnection::ExportAllSlots | QDBusConnection::ExportAllSignals);
    return a.exec();
}
