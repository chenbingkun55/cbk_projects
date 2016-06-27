#include <stdio.h>
#include <lib_SplitPictureTool.h>

int main()
{
	printf("Hello World from t1 Main!\n");

	cbk::SplitPictureTool* sp = new cbk::SplitPictureTool("geen_00.png", "./" ,"setup.xml");
	
	{ //string Process
		sp->Initialize();
		sp->SplitProcess();
		sp->OffsetProcess();
		sp->FinishingFlush();
	}

	return 0;
}