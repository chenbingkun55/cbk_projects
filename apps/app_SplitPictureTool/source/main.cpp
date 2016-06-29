#include <cbk/cbkprec.h>
#include <lib_SplitPictureTool.h>

int main()
{
	printf("Hello World from t1 Main!\n");

	cbk::SplitPictureTool* sp = new cbk::SplitPictureTool("geen_00.png", "./" ,"setup.xml");
	
	{ //string Process
		sp->initialize();
		sp->splitProcess();
		sp->offsetProcess();
		sp->finishingFlush();
	}

	return 0;
}