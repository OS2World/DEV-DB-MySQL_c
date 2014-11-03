/***************************************************************************/
/* F r e e C o d e                                                         */
/*                                                                         */
/* THIS CODE IS FREEWARE AND AS SUCH YOU ARE PERMITTED TO DO WHAT YOU WISH */
/* WITH IT. THESE PROGRAMS ARE PROVIDED AS IS WITHOUT ANY WARRANTY,        */
/* EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO FITNESS FOR ANY      */
/* PARTICULAR PURPOSE.                                                     */
/*                                                                         */
/* However, we would appriciate if you shared any enhancements to us       */
/* Please send them to www.jmast.se/free/ and we will include them in      */
/* future distributions.                                                   */
/*                                                                         */
/***************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <direct.h>

void strreplace(char *szText, char sLookFor, char sReplaceWith);
char *OemToAnsi(char *szOemText);
char *AnsiToOem(char *szAnsiText);

/*-----------------------------------------------------------------------------
   strreplace: Replaces all sLookFor with sReplaceWith.
-----------------------------------------------------------------------------*/
void strreplace(char *szText, char sLookFor, char sReplaceWith)
     {
     char       *pchFound;

     if (szText == NULL)
        return;

     if (strlen(szText) == 0)
        return;

     if (sLookFor == sReplaceWith)
        return;

     /* Change all sLookFor to sReplaceWith ones */
     pchFound = strrchr(szText, sLookFor);
     while (pchFound != 0)
           {
           (*pchFound) = sReplaceWith;
           pchFound = strrchr(szText, sLookFor);
           }
     }

/*-----------------------------------------------------------------------------
   OemToAnsi: Converts from 850 to ANSI.
-----------------------------------------------------------------------------*/
char *OemToAnsi(char *szOemText)
     {
     static char       szAnsiText[1024] = "";


     if (szOemText == NULL)
        return (NULL);

     if (strlen(szOemText) == 0)
        return (szOemText);

     memset(szAnsiText, 0, 1024);
     strcpy(szAnsiText, szOemText);

     strreplace(szAnsiText, 'è', '≈');
     strreplace(szAnsiText, 'é', 'ƒ');
     strreplace(szAnsiText, 'ô', '÷');
     strreplace(szAnsiText, 'Ü', 'Â');
     strreplace(szAnsiText, 'Ñ', '‰');
     strreplace(szAnsiText, 'î', 'ˆ');
     strreplace(szAnsiText, 'ö', '‹');
     strreplace(szAnsiText, 'Å', '¸');
     strreplace(szAnsiText, 'ê', '…');
     strreplace(szAnsiText, 'Ç', 'È');

     return(szAnsiText);
     }


/*-----------------------------------------------------------------------------
   AnsiToOem: Converts from ANSI to 850
-----------------------------------------------------------------------------*/
char *AnsiToOem(char *szAnsiText)
     {
     static char       szOemText[1024] = "";


     if (szAnsiText == NULL)
        return (NULL);

  
     if (strlen(szAnsiText) == 0)
        return (szAnsiText);

     memset(szOemText, 0, 1024);
     strcpy(szOemText, szAnsiText);

     strreplace(szOemText, '≈', 'è');
     strreplace(szOemText, 'ƒ', 'é');
     strreplace(szOemText, '÷', 'ô');
     strreplace(szOemText, 'Â', 'Ü');
     strreplace(szOemText, '‰', 'Ñ');
     strreplace(szOemText, 'ˆ', 'î');
     strreplace(szOemText, '‹', 'ö');
     strreplace(szOemText, '¸', 'Å');
     strreplace(szOemText, '…', 'ê');
     strreplace(szOemText, 'È', 'Ç');

     return(szOemText);
     }
