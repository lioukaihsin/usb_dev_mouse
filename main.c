#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "driverlib/debug.h"
#include "driverlib/sysctl.h"
#include "grlib/grlib.h"
#include "drivers/cfal96x64x16.h"

extern const unsigned char g_pucImage[];
tContext sContext;
tRectangle sRect;
void ClrScreen();

#ifdef DEBUG
void
__error__(char* pcFilename, unsigned logn ulLine)
{

}
#endif

int main()
{
	SysCtlClockSet(SYSCTL_SYSDIV_4|SYSCTL_USE_PLL|SYSCTL_OSC_MAIN|SYSCTL_XTAL_16MHZ);

	CFAL96x64x16Init();

	GrContextInit(&sContext, &g_sCFAL96x64x16);

	ClrScreen();

	GrImageDraw(&sContext, g_pucImage, 0, 0);

	GrFlush(&sContext);

	SysCtlDelay(SysCtlClockGet());

	ClrScreen();

	sRect.sXMin = 1;
	sRect.sYMin = 1;
	sRect.sXMax = 95;
	sRect.sYMax = 63;
	GrContextForegroundSet(&sContext, ClrBlue);
	GrContextFontSet(&sContext, &g_sFontFixed6x8);
	GrStringDraw(&sContext, "¤¤¤å", -1, 32, 10, 0);
	GrStringDraw(&sContext, "Instruments", -1, 16, 20, 0);
	GrStringDraw(&sContext, "Graphics", -1, 27, 40, 0);
	GrStringDraw(&sContext, "Lab", -1, 40, 50, 0);
	GrContextForegroundSet(&sContext, ClrWhite);
	GrRectDraw(&sContext, &sRect);
	GrFlush(&sContext);

	SysCtlDelay(SysCtlClockGet());

	ClrScreen();

	GrContextForegroundSet(&sContext, ClrYellow);
	GrCircleDraw(&sContext, 30, 30, 20);

	sRect.sXMin = 55;
	sRect.sYMin = 10;
	sRect.sXMax = 90;
	sRect.sYMax = 50;
	GrContextForegroundSet(&sContext, ClrGreen);
	GrRectDraw(&sContext, &sRect);

	GrPixelDraw(&sContext, 30, 30);
	GrLineDrawH(&sContext, 10, 90, 55);
	GrLineDrawV(&sContext, 53, 10, 50);
	GrFlush(&sContext);

	SysCtlDelay(SysCtlClockGet());

	GrContextForegroundSet(&sContext, ClrYellow);
	GrCircleFill(&sContext, 30, 30, 20);
	GrContextForegroundSet(&sContext, ClrGreen);
	GrRectFill(&sContext, &sRect);
	GrFlush(&sContext);

	SysCtlDelay(SysCtlClockGet());


	while(1)
	{

	}
}

void ClrScreen()
{
	sRect.sXMin = 0;
	sRect.sYMin = 0;
	sRect.sXMax = 95;
	sRect.sYMax = 63;
	GrContextForegroundSet(&sContext, ClrBlack);
	GrRectFill(&sContext, &sRect);
	GrFlush(&sContext);

}
