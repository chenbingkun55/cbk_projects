#include "gloox.h"
#include "client.h"
#include "clientbase.h"
#include "connectionlistener.h"
#include "loghandler.h"

using namespace gloox;

class XmppClient : public  ConnectionListener, LogHandler
{
    public:
        XmppClient();
        virtual ~XmppClient();

        void start();

        virtual void onConnect() override;
        virtual void onDisconnect(enum gloox::ConnectionError) override;
        virtual bool onTLSConnect(const struct gloox::CertInfo&) override;

       virtual void handleLog( LogLevel level, LogArea area, const std::string& message ) override;

    private:
        bool m_bIsConnected;
};
