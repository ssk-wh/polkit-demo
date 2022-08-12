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

#include <QDBusInterface>
#include <QDBusConnection>

int main(int argv,char **argc){

    QCoreApplication app(argv, argc);
    QDBusInterface interface("com.deepin.dde.pokit.demo"
                             , "/com/deepin/dde/pokit/demo"
                             , "com.deepin.dde.pokit.demo"
                             , QDBusConnection::systemBus());

    // 通过DBus调用com.deepin.dde.pokit.demo的"DobyRoot"方法，
    // 服务的提供者为polkit_server进程，以root身份的身份运行，才可以做到很多普通进程无法做到的事情
    interface.call("DobyRoot");

    return app.exec();
}
