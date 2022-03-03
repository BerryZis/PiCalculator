#include <ansi_c.h>
#include <cvirte.h>		
#include <userint.h>
#include "PiCalculator.h"

static int panelHandle;

static double pi[1000000];

int main (int argc, char *argv[])
{
	if (InitCVIRTE (0, argv, 0) == 0)
		return -1;	/* out of memory */
	if ((panelHandle = LoadPanel (0, "PiCalculator.uir", PANEL)) < 0)
		return -1;
	DisplayPanel (panelHandle);
	
	RunUserInterface ();
	DiscardPanel (panelHandle);
	return 0;
}

int CVICALLBACK Exitq (int panel, int event, void *callbackData,
					   int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_GOT_FOCUS:

			break;
		case EVENT_LOST_FOCUS:

			break;
		case EVENT_CLOSE:
			QuitUserInterface (0);
			break;
	}
	return 0;
}

int CVICALLBACK Function (int panel, int control, int event,
						  void *callbackData, int eventData1, int eventData2)
{
	double x,y,radius,truePi;
	int counter=0,i;
	truePi = 3.141592;
	switch (event)
	{
		case EVENT_COMMIT:
			
			srand(time(0));
			
			for(i=0; i<(pow (10, 6)) ; i++)
			{
				x=-1+2*(double)rand()/RAND_MAX;
				y=-1+2*(double)rand()/RAND_MAX;
				
				radius = sqrt(pow(x,2) + pow(y,2));
				
				if(radius <= 1)
					counter++;
					
				pi[i] = 4*(counter/pow(10,6));
				
			}
			
			PlotLine (panelHandle, PANEL_GRAPH, 999999, truePi, VAL_DOUBLE, truePi, VAL_BLACK);
			PlotY (panelHandle, PANEL_GRAPH, pi, i, VAL_DOUBLE, VAL_THIN_LINE, VAL_SOLID_CIRCLE, VAL_SOLID, 1, VAL_RED);
			
			pi[counter] = 4*(counter/pow(10,6));
			SetCtrlVal (panelHandle, PANEL_NUMERIC, pi[counter]);

			break;
	}
	return 0;
}

void CVICALLBACK About (int menuBar, int menuItem, void *callbackData,
						int panel)
{
	MessagePopup ("About", "Features:\n- Graph showing the approximation to Pi in relation to number of points calculated\n- Line showing the True Pi number\n- Zooming option\n- Cursor showing every calculation with X & Y\n- Menu Bar with About and Questions & Answers\n\n\n Created By: Berry Ziskind");
}

int CVICALLBACK Cursor (int panel, int control, int event,
						void *callbackData, int eventData1, int eventData2)
{
	double xcurs,ycurs;
	switch (event)
	{
		case EVENT_MOUSE_POINTER_MOVE:
			
			 GetGraphCursor (panelHandle, PANEL_GRAPH, 1, &xcurs, &ycurs);
			
			 SetCtrlVal(panelHandle, PANEL_XCURS, xcurs);
			 SetCtrlVal(panelHandle, PANEL_YCURS, ycurs);

			break;
	}
	return 0;
}

void CVICALLBACK QA (int menuBar, int menuItem, void *callbackData,
					 int panel)
{
	MessagePopup ("Answers","	Precision:\n   The precision is depending on number of points we inserted, more points = more precise.\n   Becouse we are getting random numbers there is a big chance to get the same coardinates more then once, this will lower our precision.\nRadius:\n   If the radius will be smaller, The precision will get higher as we have same number of points covering smaller area.");  
}
