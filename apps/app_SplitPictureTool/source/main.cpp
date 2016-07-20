#include <cbk/cbkprec.h>
#include <lib_SplitPictureTool.h>

int main()
{
	NS_CBK_FILE::printWorld();
	NS_CBK_STRING::printWorld();

	NS_CBK::SplitPictureTool* sp = new NS_CBK::SplitPictureTool("test.png","./","setup.xml");
	sp->initialize();
	sp->process();
	sp->finishingFlush();

	return 0;
}