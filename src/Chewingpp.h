/* @(#)Chewingpp.h
 */

#ifndef _CHEWINGPP_H
#define _CHEWINGPP_H 1

#include "chewing/chewing.h"

class Chewing
{
  ChewingData   *cd;
  ChewingOutput *co;
  ChewingConf   *cf;
  ConfigData    config;
  char*         selkey;

  char*         hash;
  char*         data;
  int           kbLayout;

 public:
  Chewing();
  virtual ~Chewing();
  Chewing(char *dataDir, char *hashDir, int keyLayout=KB_DEFAULT);

  void SetKeyboardLayout(int kb);
  void SetHsuSelectionKeyType(int type);

  // Debugging-only retuine.
  void Dump();

  int Space();
  int Esc();
  int Enter();
  int Delete();
  int Backspace();
  int Tab();
  int ShiftLeft();
  int ShiftRight();
  int ShiftSpace();
  int Right();
  int Left();
  int Up();
  int Down();
  int Home();
  int End();
  int Capslock();
  int Key(unsigned int code);
  int CtrlNum(unsigned int code);
  int CtrlOption(unsigned int code);
  int DoubleTab();

  // Return the i-th selection key, i >= 0.
  char SelKey(int i);
  void SelKey(char* selkey);

  char* ZuinStr();
  char* CommitStr();
  char* CommitStr(int from);
  char* CommitStr(int from, int to);
  int   CommitReady();

  char* Buffer();
  char* Buffer(int from);
  char* Buffer(int from,int to);
  int   BufferLen();

  int CursorPos();
  int PointStart();
  int PointEnd();
  int KeystrokeRtn();
  int KeystrokeIgnore();

  int ChineseMode();

  // CandidateWindow-related routines
  int Candidate();
  int ChoicePerPage();
  int TotalChoice();
  int TotalPage();
  int CurrentPage();

  // Return the i-th selection wchar, i >= 0.
  char* Selection(int i);

};

#endif /* _CHEWING_H */

