/**************************************************************************/
/* LabWindows/CVI User Interface Resource (UIR) Include File              */
/*                                                                        */
/* WARNING: Do not add to, delete from, or otherwise modify the contents  */
/*          of this include file.                                         */
/**************************************************************************/

#include <userint.h>

#ifdef __cplusplus
    extern "C" {
#endif

     /* Panels and Controls: */

#define  PANEL                            1       /* callback function: Exitq */
#define  PANEL_COMMANDBUTTON              2       /* control type: command, callback function: Function */
#define  PANEL_NUMERIC                    3       /* control type: numeric, callback function: (none) */
#define  PANEL_GRAPH                      4       /* control type: graph, callback function: Cursor */
#define  PANEL_YCURS                      5       /* control type: numeric, callback function: (none) */
#define  PANEL_XCURS                      6       /* control type: numeric, callback function: (none) */
#define  PANEL_TEXT                       7       /* control type: textMsg, callback function: (none) */
#define  PANEL_TEXT_2                     8       /* control type: textMsg, callback function: (none) */


     /* Control Arrays: */

          /* (no control arrays in the resource file) */


     /* Menu Bars, Menus, and Menu Items: */

#define  MENUBAR                          1
#define  MENUBAR_MENU1                    2       /* callback function: About */
#define  MENUBAR_MENU1_2                  3       /* callback function: QA */


     /* Callback Prototypes: */

void CVICALLBACK About(int menubar, int menuItem, void *callbackData, int panel);
int  CVICALLBACK Cursor(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK Exitq(int panel, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK Function(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
void CVICALLBACK QA(int menubar, int menuItem, void *callbackData, int panel);


#ifdef __cplusplus
    }
#endif
