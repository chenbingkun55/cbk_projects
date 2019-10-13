#include "XmppClient.h"


XmppClient::XmppClient()
{
    //ctor
}

XmppClient::~XmppClient()
{
    //dtor
}

void XmppClient::start()
{
        JID jid( "chenbk@localhost");
		Client* j = new Client( jid, "chenbk88");
		j->registerConnectionListener( this );
		// j->registerMessageSessionHandler( this, 0 );
		//j->disco()->setVersion( "XmppClient", GLOOX_VERSION, "Linux" );
		//j->disco()->setIdentity( "client", "bot" );
		//j->disco()->addFeature( XMLNS_CHAT_STATES );
		StringList ca;
		ca.push_back( "/path/to/cacert.crt" );
		j->setCACerts( ca );

		j->logInstance().registerLogHandler( LogLevelDebug, LogAreaAll, this );

		//非阻塞方式连接，需自主调用recv()接收数据
		if( j->connect( false ) )
		{
			ConnectionError ce = ConnNoError;
			//无限循环S监听
			while( ce == ConnNoError )
			{
				ce = j->recv(10000000);
			}
		}

    delete( j );
}


void XmppClient::onConnect()
{
		printf( "==================连接成功==================\n" );
        m_bIsConnected = true;
}

bool XmppClient::onTLSConnect(const struct gloox::CertInfo&)
{
	printf( "==================TLS 成功==================\n" );

	return true;
}

 void XmppClient::onDisconnect(enum gloox::ConnectionError)
 {
	printf( "==================连接失败==================\n" );
 }

 void XmppClient::handleLog( LogLevel level, LogArea area, const std::string& message )
{
            printf("log: level: %d, area: %d, %s\n", level, area, message.c_str() );
};
