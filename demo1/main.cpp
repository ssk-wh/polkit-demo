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

#include <QDebug>

#include <polkit-qt5-1/PolkitQt1/Authority>

using namespace PolkitQt1;
int main(int argc, char **argv)
{
    (void)(argc);
    (void)(argv);
    Authority::Result result;
    // 请求验证"com.deepin.polkit.demo.fun1"的操作执行权限
    result = Authority::instance()->checkAuthorizationSync("com.deepin.polkit.demo.fun1"
                                                           , UnixProcessSubject(getpid())
                                                           , Authority::AllowUserInteraction);
    if (result == Authority::Yes) {
        qDebug() << "Now, we can do anything!";

        // 接口调用者身份可信，允许此操作执行，但我们只是一个普通权限的进程，实际也做不了什么，正式用法可以看demo2

        qDebug() << "Done, good job!";
        exit(0);
    }else{
        qWarning() << "So sad, permission denied!";
        exit(-1);
    }
}
