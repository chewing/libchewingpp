#include <string.h>

#include "Chewingpp.h"

// Class Methods: Init and Terminate

void Chewing::Init(const char *dataDir, const char *hashDir) {
    chewing_Init(dataDir, hashDir);
}

void Chewing::Terminate() {
    chewing_Terminate();
}


// Object methods. All delegate to chewing context api.
Chewing::Chewing() {
    char selKey_define[ 12 ] = "1234567890\0";

    ctx = chewing_new();
    chewing_set_KBType( ctx, chewing_KBStr2Num( "KB_DEFAULT" ) );

    /* Fill the configuration values */
    config.selectAreaLen = 20;
    config.maxChiSymbolLen = 16;
    
    for ( int i = 0; i < 10; i++ )
        config.selKey[ i ] = selKey_define[ i ];
    /* Enable configurations */
    chewing_Configure( ctx, &config );
}

Chewing::~Chewing() {
    chewing_free(ctx);
}

void Chewing::SetHsuSelectionKeyType(int type)
{
}

void Chewing::SetKeyboardLayout(int kb)
{
    chewing_set_KBType(ctx, kb);

#if 0
    kbLayout = kb;
    if (kb==KB_HSU) {
        if(cd->config.hsuSelKeyType == HSU_SELKEY_TYPE2) {
            SelKey("asdfzxcv89");
        } else {
            SelKey("asdfjkl789");
        }
    } else if (kb==KB_DVORAK_HSU) SelKey("aoeuhtn789");
    else SelKey("1234567890");
    // Always use space as candidate key for SpaceChewing style.
#endif

    chewing_Configure( ctx, &config );
}

/*
 * Return i-th selection-key. i starts from 0.
 */
char Chewing::SelKey(int i) {
  if(0 <= i && i < 10)
    return config.selKey[i];
  return 0;
}

void Chewing::SelKey(char *selkey) {
  for (int i = 0; i < 10;i++ ) config.selKey[ i ] = selkey[i];
  chewing_Configure( ctx, &config );
}

int Chewing::Space()      { return chewing_handle_Space( ctx ); }
int Chewing::Enter()      { return chewing_handle_Enter( ctx ); }
int Chewing::Delete()     { return chewing_handle_Del( ctx ); }
int Chewing::Backspace()  { return chewing_handle_Backspace( ctx ); }
int Chewing::Tab()        { return chewing_handle_Tab( ctx ); }
int Chewing::ShiftLeft()  { return chewing_handle_ShiftLeft( ctx ); }
int Chewing::ShiftRight() { return chewing_handle_ShiftRight( ctx ); }
int Chewing::ShiftSpace() { return chewing_handle_ShiftSpace( ctx ); }
int Chewing::Right()      { return chewing_handle_Right( ctx );}
int Chewing::Left()       { return chewing_handle_Left( ctx );}
int Chewing::Up()         { return chewing_handle_Up( ctx );}
int Chewing::Down()       { return chewing_handle_Down( ctx );}
int Chewing::Home()       { return chewing_handle_Home( ctx );}
int Chewing::End()        { return chewing_handle_End( ctx );}
int Chewing::Capslock()   { return chewing_handle_Capslock( ctx );}
int Chewing::DoubleTab()  { return chewing_handle_DblTab( ctx );}
int Chewing::Esc()        { return chewing_handle_Esc( ctx ); }

int Chewing::CtrlOption(int code) { return chewing_handle_CtrlOption(ctx, code); }
int Chewing::CtrlNum(int code)    { return chewing_handle_CtrlNum(ctx, code); }
int Chewing::Key(int code) { return chewing_handle_Default(ctx, code); }

/*
  CommitReady() returns TRUE if it currnet input state
  is at the "end-of-a-char".
 */
int Chewing::CommitReady() {
    return chewing_commit_Check( ctx );
}

/*
  CommitString() retrun currnet commit string, regardless
  current input state.

  Alwasy returns a char pointer, caller must free it.
 */

char* Chewing::CommitString() {
    return chewing_commit_String( ctx );
}

/*
  Always returns a char pointer, caller must free it.
 */
char* Chewing::ZuinString(int *zuin_count) {
    return chewing_zuin_String( ctx, zuin_count);
}

int Chewing::CursorPos() {
    return (int)chewing_cursor_Current( ctx );
}

int Chewing::KeystrokeRtn() {
  return ctx->output->keystrokeRtn;
}

int Chewing::KeystrokeIgnore() {
    return chewing_keystroke_CheckIgnore(ctx);
}

int Chewing::ChineseMode() {
  return (ctx->data->bChiSym == CHINESE_MODE);
}

int Chewing::Candidate() {
  return (ctx->output->pci->nPage);
}

int Chewing::ChoicePerPage() {
  return (ctx->output->pci->nChoicePerPage);
}

int Chewing::TotalChoice() {
  return (ctx->output->pci->nTotalChoice);
}

int Chewing::TotalPage() {
    return (ctx->output->pci->nPage);
}

int Chewing::CurrentPage() {
    return (ctx->output->pci->pageNo);
}

/*
 * Return the i-th candidate wchar (WCH_SIZE bytes), i starts from 0.
 * User MUST free() the return value of this sub-routine,
 * even if it's a false value.
 */
char* Chewing::Selection(int i) {
  char *s;
  int no = ctx->output->pci->pageNo * ChoicePerPage() + i;

  if(i >=0 && no < ctx->output->pci->nTotalChoice)
    s = strdup(ctx->output->pci->totalChoiceStr[no]);
  else
    s = strdup("");

  return s;
}

// A debugging purpose Dumping routing. Output current inputed Zuin
// and Commit string.
void Chewing::Dump() {
    char *s;
    int c;
    fprintf(stderr,"nCommitStr = %d\n",ctx->output->nCommitStr);

    fprintf(stderr,"zuin: ");
    s = ZuinString(&c);
    fprintf(stderr, "%s\n", s);
    free(s);
   
    fprintf(stderr,"commit: ");
    s = CommitString();
    fprintf(stderr, "%s\n-----\n", s);
    free(s);
}


