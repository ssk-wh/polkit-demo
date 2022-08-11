#include <QDebug>

#include <polkit-qt5-1/PolkitQt1/Authority>

using namespace PolkitQt1;
int main(int argc, char **argv)
{
    (void)(argc);
    (void)(argv);
    Authority::Result result;
    result = Authority::instance()->checkAuthorizationSync("com.deepin.polkit.demo.fun1"
                                                           , UnixProcessSubject(getpid())
                                                           , Authority::AllowUserInteraction);
    if (result == Authority::Yes) {
        qDebug() << "We are free, continue";
        // do something
        qDebug() << "Done, good job!";
        exit(0);
    }else{
        qWarning() << "So sad, permission denied!";
        exit(-1);
    }
}
