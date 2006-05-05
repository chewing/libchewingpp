
#include <stdio.h>
#include <stdlib.h>

#include "Chewingpp.h"


#define KEY_SLEFT 896
#define KEY_SRIGHT 897	
#define KEY_LEFT 898
#define KEY_RIGHT 899	
#define KEY_UP 990 
#define KEY_DOWN 991
#define KEY_SPACE ' '
#define KEY_ENTER 992
#define KEY_BACKSPACE 993
#define KEY_ESC	994
#define KEY_DELETE 995
#define KEY_HOME 996
#define KEY_END 997
#define KEY_TAB 998
#define KEY_CAPSLOCK 999
#define KEY_CTRL_BASE 1000
#define END 2000

#ifdef DEBUG
FILE *fp_g;
#endif

int get_keystroke() {
  char ch;
  int result;
  int flag = 0;
  while ( ( ch = getchar() ) != EOF ) {
    if ( ( ch != '<' ) && ( flag != 1 ) ) {
      return (int) ch;
    } else if ( ch == '>' ) {
      flag = 0;
      return result;
    } else {
      flag = 1;
      ch = getchar();
      switch ( ch ) {
      case 'L':
	result = KEY_LEFT;
	break;
      case 'R':
	result = KEY_RIGHT;
	break;
      case 'U':
	result = KEY_UP;
	break;
      case 'D':
	if ( ( ch = getchar() ) == '>' )
	  return result = KEY_DOWN;
	else {
	  getchar();
	  return result = KEY_DELETE;
	}
	break;
      case 'E':
	if ( ( ch = getchar() ) == '>' )
	  return result = KEY_ENTER;
	else if ( ch == 'E' )
	  result = KEY_ESC;
	else
	  result = KEY_END;
	break;
      case 'C':
	if ( ( ch = getchar() ) != '>' ) {
	  if ( ( ch == 'B' ))
	    result = ( KEY_CAPSLOCK );
	  else
	    result = ( KEY_CTRL_BASE + ch );
	}
	break;
      case 'B':
	result = KEY_BACKSPACE;
	break;
      case 'H':
	result = KEY_HOME;
	break;
      case 'S':
	if ( ( ch = getchar() ) == 'L' )
	  result = KEY_SLEFT;
	else
	  result = KEY_SRIGHT;
	break;
      case 'T':
	result = KEY_TAB;
	break;
      }
    }
  }
  return result = END;
}



int
main(void) {
  int i;
  int ctrl_shifted;
  char *s;

  // Init;
  Chewing::Init("/usr/local/share/chewing","/tmp");

  Chewing *im = new Chewing();

  while(1) {
    i = get_keystroke();
    switch(i) {
    case KEY_LEFT:
      im->Left();
      break;
    case KEY_RIGHT:
      im->Right();
      break;
    case KEY_UP:
      im->Up();
      break;
    case KEY_DOWN:
      im->Down();
      break;
    case KEY_SPACE:
      im->Space();
      break;
    case KEY_ENTER:
      im->Enter();
      break;
    case KEY_BACKSPACE:
      im->Backspace();
      break;
    case KEY_ESC:
      im->Esc();
      break;
    case KEY_DELETE:
      im->Delete();
      break;
    case KEY_HOME:
      im->Home();
      break;
    case KEY_END:
      im->End();
      break;
    case KEY_TAB:
      im->Tab();
      break;			
#if 0
    case XK_Caps_Lock:
      im->Capslock();
      break;
#endif
    case KEY_CAPSLOCK:
      im->Capslock();
      break;
    case END:
      goto end;
    default:
      ctrl_shifted = ( i - KEY_CTRL_BASE );
      if ( ( ctrl_shifted >= '0' ) && ( ctrl_shifted <= '9' ) ) {
	im->CtrlNum( ctrl_shifted );
      } else {
	im->Key( i );
      }
      break;
    }
    im->Dump();
  }

 end:
  Chewing::Terminate();
  delete im;
  return 0;
}
