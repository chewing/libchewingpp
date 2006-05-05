/* @(#)Chewingpp.h
 */

#ifndef _CHEWINGPP_H
#define _CHEWINGPP_H 1

#include "chewing/chewing.h"

class Chewing
{
  ChewingContext *ctx;
  ChewingConfigData config;
  int kbLayout;

 public:
  // Class Methods. Can be called only once per process.
  static void Init(const char *dataDir, const char *hashDir);
  static void Terminate();

  // Object methods.
  Chewing();
  virtual ~Chewing();

  // Configuration
  void SetKeyboardLayout(int kb);
  void SetHsuSelectionKeyType(int type);

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
  int Key(int code);
  int CtrlNum(int code);
  int CtrlOption(int code);
  int DoubleTab();

  // Return the i-th selection key, i >= 0.
  char SelKey(int i);
  void SelKey(char* selkey);

  char* ZuinString(int *zuin_count);
  char* CommitString();
  int   CommitReady();

  char* Buffer();
  char* Buffer(int from);
  char* Buffer(int from,int to);
  int   BufferLen();

  int CursorPos();
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


  // Debugging routine
  void Dump();
};

#endif /* _CHEWINGPP_H */

