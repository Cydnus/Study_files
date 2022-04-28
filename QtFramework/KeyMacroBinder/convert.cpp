#include "convert.h"


Convert* Convert::convert = nullptr;

Convert::Convert()
{
    codeMap = {
        {" " , 32} ,
        {"!" , 33} ,
        {"\"", 34} ,
        {"#" , 35} ,
        {"$" , 36} ,
        {"%" , 37} ,
        {"&" , 38} ,
        {"\'" , 39} ,
        {"(" , 40} ,
        {")" , 41} ,
        {"*" , 42} ,
        {"+" , 43} ,
        {"," , 44} ,
        {"-" , 45} ,
        {"." , 46} ,
        {"/" , 47} ,
        {"0" , 48} ,
        {"1" , 49} ,
        {"2" , 50} ,
        {"3" , 51} ,
        {"4" , 52} ,
        {"5" , 53} ,
        {"6" , 54} ,
        {"7" , 55} ,
        {"8" , 56} ,
        {"9" , 57} ,
        {":" , 58} ,
        {";" , 59} ,
        {"<" , 60} ,
        {"=" , 61} ,
        {">" , 62} ,
        {"?" , 63} ,
        {"@" , 64} ,
        {"A" , 65} ,
        {"B" , 66} ,
        {"C" , 67} ,
        {"D" , 68} ,
        {"E" , 69} ,
        {"F" , 70} ,
        {"G" , 71} ,
        {"H" , 72} ,
        {"I" , 73} ,
        {"J" , 74} ,
        {"K" , 75} ,
        {"L" , 76} ,
        {"M" , 77} ,
        {"N" , 78} ,
        {"O" , 79} ,
        {"P" , 80} ,
        {"Q" , 81} ,
        {"R" , 82} ,
        {"S" , 83} ,
        {"T" , 84} ,
        {"U" , 85} ,
        {"V" , 86} ,
        {"W" , 87} ,
        {"X" , 88} ,
        {"Y" , 89} ,
        {"Z" , 90} ,
        {"[" , 91} ,
        {"\\" , 92} ,
        {"]" , 93} ,
        {"^" , 94} ,
        {"_" , 95} ,
        {"`" , 96} ,
        {"a" , 97} ,
        {"b" , 98} ,
        {"c" , 99} ,
        {"d" , 100} ,
        {"e" , 101} ,
        {"f" , 102} ,
        {"g" , 103} ,
        {"h" , 104} ,
        {"i" , 105} ,
        {"j" , 106} ,
        {"k" , 107} ,
        {"l" , 108} ,
        {"m" , 109} ,
        {"n" , 110} ,
        {"o" , 111} ,
        {"p" , 112} ,
        {"q" , 113} ,
        {"r" , 114} ,
        {"s" , 115} ,
        {"t" , 116} ,
        {"u" , 117} ,
        {"v" , 118} ,
        {"w" , 119} ,
        {"x" , 120} ,
        {"y" , 121} ,
        {"z" , 122} ,
        {"{" , 123} ,
        {"|" , 124} ,
        {"}" , 125} ,
        {"~" , 126} ,
        {"KEY_LEFT_CTRL" , 128 },
        {"KEY_LEFT_SHIFT" , 129} ,
        {"KEY_LEFT_ALT" , 130} ,
        {"KEY_LEFT_GUI" , 131} ,
        {"KEY_LEFT_WINDOWS" , 132} ,
        {"KEY_RIGHT_CTRL" , 133} ,
        {"KEY_RIGHT_SHIFT" , 134} ,
        {"KEY_RIGHT_ALT" , 135} ,
        {"KEY_RIGHT_GUI" , 136} ,
        {"KEY_RIGHT_WINDOWS" , 137} ,
        {"KEY_ENTER" , 138} ,
        {"KEY_ESC" , 139} ,
        {"KEY_BACKSPACE" , 140} ,
        {"KEY_TAB" , 141} ,
        {"KEY_SPACE" , 142} ,
        {"KEY_MINUS" , 143} ,
        {"KEY_EQUAL" , 144} ,
        {"KEY_LEFT_BRACE" , 145} ,
        {"KEY_RIGHT_BRACE" , 146} ,
        {"KEY_BACKSLASH" , 147} ,
        {"KEY_NON_US_NUM" , 148} ,
        {"KEY_SEMICOLON" , 149} ,
        {"KEY_QUOTE" , 150} ,
        {"KEY_TILDE" , 151} ,
        {"KEY_COMMA" , 152} ,
        {"KEY_PERIOD" , 153} ,
        {"KEY_SLASH" , 154} ,
        {"KEY_CAPS_LOCK" , 155} ,
        {"KEY_F1" , 156} ,
        {"KEY_F2" , 157} ,
        {"KEY_F3" , 158} ,
        {"KEY_F4" , 159} ,
        {"KEY_F5" , 160} ,
        {"KEY_F6" , 161} ,
        {"KEY_F7" , 162} ,
        {"KEY_F8" , 163} ,
        {"KEY_F9" , 164} ,
        {"KEY_F10" , 165} ,
        {"KEY_F11" , 166} ,
        {"KEY_F12" , 167} ,
        {"KEY_PRINTSCREEN" , 168} ,
        {"KEY_SCROLL_LOCK" , 169} ,
        {"KEY_PAUSE" , 170} ,
        {"KEY_INSERT" , 171} ,
        {"KEY_HOME" , 172} ,
        {"KEY_PAGE_UP" , 173} ,
        {"KEY_DELETE" , 174} ,
        {"KEY_END" , 175} ,
        {"KEY_PAGE_DOWN" , 176} ,
        {"KEY_RIGHT_ARROW" , 177} ,
        {"KEY_LEFT_ARROW" , 178} ,
        {"KEY_DOWN_ARROW" , 179} ,
        {"KEY_UP_ARROW" , 180} ,
        {"KEY_RIGHT" , 181} ,
        {"KEY_LEFT" , 182} ,
        {"KEY_DOWN" , 183} ,
        {"KEY_UP" , 184} ,
        {"KEY_NUM_LOCK" , 185} ,
        {"KEYPAD_DIVIDE" , 186} ,
        {"KEYPAD_MULTIPLY" , 187} ,
        {"KEYPAD_SUBTRACT" , 188} ,
        {"KEYPAD_ADD" , 189} ,
        {"KEYPAD_ENTER" , 190} ,
        {"KEYPAD_1" , 191} ,
        {"KEYPAD_2" , 192} ,
        {"KEYPAD_3" , 193} ,
        {"KEYPAD_4" , 194} ,
        {"KEYPAD_5" , 195} ,
        {"KEYPAD_6" , 196} ,
        {"KEYPAD_7" , 197} ,
        {"KEYPAD_8" , 198} ,
        {"KEYPAD_9" , 199} ,
        {"KEYPAD_0" , 200} ,
        {"KEYPAD_DOT" , 201} ,
        {"KEY_NON_US" , 202} ,
        {"MEDIA_STOP" , 203} ,
        {"MEDIA_PREVIOUS" , 204} ,
        {"MEDIA_PLAY_PAUSE" , 205} ,
        {"MEDIA_NEXT" , 206} ,
        {"KEY_PRINTSCREEN" , 207} ,
        {"releaseAll" , 250} };
    keyMap = {
            { 32 , " " },
            { 33 , "!" },
            { 34 , "\"" },
            { 35 , "#" },
            { 36 , "$" },
            { 37 , "%" },
            { 38 , "&" },
            { 39 , "\'" },
            { 40 , "(" },
            { 41 , ")" },
            { 42 , "*" },
            { 43 , "+" },
            { 44 , "," },
            { 45 , "-" },
            { 46 , "." },
            { 47 , "/" },
            { 48 , "0" },
            { 49 , "1" },
            { 50 , "2" },
            { 51 , "3" },
            { 52 , "4" },
            { 53 , "5" },
            { 54 , "6" },
            { 55 , "7" },
            { 56 , "8" },
            { 57 , "9" },
            { 58 , ":" },
            { 59 , ";" },
            { 60 , "<" },
            { 61 , "=" },
            { 62 , ">" },
            { 63 , "?" },
            { 64 , "@" },
            { 65 , "A" },
            { 66 , "B" },
            { 67 , "C" },
            { 68 , "D" },
            { 69 , "E" },
            { 70 , "F" },
            { 71 , "G" },
            { 72 , "H" },
            { 73 , "I" },
            { 74 , "J" },
            { 75 , "K" },
            { 76 , "L" },
            { 77 , "M" },
            { 78 , "N" },
            { 79 , "O" },
            { 80 , "P" },
            { 81 , "Q" },
            { 82 , "R" },
            { 83 , "S" },
            { 84 , "T" },
            { 85 , "U" },
            { 86 , "V" },
            { 87 , "W" },
            { 88 , "X" },
            { 89 , "Y" },
            { 90 , "Z" },
            { 91 , "[" },
            { 92 , "\\" },
            { 93 , "]" },
            { 94 , "^" },
            { 95 , "_" },
            { 96 , "`" },
            { 97 , "a" },
            { 98 , "b" },
            { 99 , "c" },
            { 100 , "d" },
            { 101 , "e" },
            { 102 , "f" },
            { 103 , "g" },
            { 104 , "h" },
            { 105 , "i" },
            { 106 , "j" },
            { 107 , "k" },
            { 108 , "l" },
            { 109 , "m" },
            { 110 , "n" },
            { 111 , "o" },
            { 112 , "p" },
            { 113 , "q" },
            { 114 , "r" },
            { 115 , "s" },
            { 116 , "t" },
            { 117 , "u" },
            { 118 , "v" },
            { 119 , "w" },
            { 120 , "x" },
            { 121 , "y" },
            { 122 , "z" },
            { 123 , "{" },
            { 124 , "|" },
            { 125 , "}" },
            { 126 , "~" },
            { 128 , "KEY_LEFT_CTRL"},
            { 129 , "KEY_LEFT_SHIFT"} ,
            { 130 , "KEY_LEFT_ALT"} ,
            { 131 , "KEY_LEFT_GUI"} ,
            { 132 , "KEY_LEFT_WINDOWS"} ,
            { 133 , "KEY_RIGHT_CTRL"} ,
            { 134 , "KEY_RIGHT_SHIFT"} ,
            { 135 , "KEY_RIGHT_ALT"} ,
            { 136 , "KEY_RIGHT_GUI"} ,
            { 137 , "KEY_RIGHT_WINDOWS"} ,
            { 138 , "KEY_ENTER"} ,
            { 139 , "KEY_ESC"} ,
            { 140 , "KEY_BACKSPACE"} ,
            { 141 , "KEY_TAB"} ,
            { 142 , "KEY_SPACE"} ,
            { 143 , "KEY_MINUS"} ,
            { 144 , "KEY_EQUAL"} ,
            { 145 , "KEY_LEFT_BRACE"} ,
            { 146 , "KEY_RIGHT_BRACE"} ,
            { 147 , "KEY_BACKSLASH"} ,
            { 148 , "KEY_NON_US_NUM"} ,
            { 149 , "KEY_SEMICOLON"} ,
            { 150 , "KEY_QUOTE"} ,
            { 151 , "KEY_TILDE"} ,
            { 152 , "KEY_COMMA"} ,
            { 153 , "KEY_PERIOD"} ,
            { 154 , "KEY_SLASH"} ,
            { 155 , "KEY_CAPS_LOCK"} ,
            { 156 , "KEY_F1"} ,
            { 157 , "KEY_F2"} ,
            { 158 , "KEY_F3"} ,
            { 159 , "KEY_F4"} ,
            { 160 , "KEY_F5"} ,
            { 161 , "KEY_F6"} ,
            { 162 , "KEY_F7"} ,
            { 163 , "KEY_F8"} ,
            { 164 , "KEY_F9"} ,
            { 165 , "KEY_F10"} ,
            { 166 , "KEY_F11"} ,
            { 167 , "KEY_F12"} ,
            { 168 , "KEY_PRINTSCREEN"} ,
            { 169 , "KEY_SCROLL_LOCK"} ,
            { 170 , "KEY_PAUSE"} ,
            { 171 , "KEY_INSERT"} ,
            { 172 , "KEY_HOME"} ,
            { 173 , "KEY_PAGE_UP"} ,
            { 174 , "KEY_DELETE"} ,
            { 175 , "KEY_END"} ,
            { 176 , "KEY_PAGE_DOWN"} ,
            { 177 , "KEY_RIGHT_ARROW"} ,
            { 178 , "KEY_LEFT_ARROW"} ,
            { 179 , "KEY_DOWN_ARROW"} ,
            { 180 , "KEY_UP_ARROW"} ,
            { 181 , "KEY_RIGHT"} ,
            { 182 , "KEY_LEFT"} ,
            { 183 , "KEY_DOWN"} ,
            { 184 , "KEY_UP"} ,
            { 185 , "KEY_NUM_LOCK"} ,
            { 186 , "KEYPAD_DIVIDE"} ,
            { 187 , "KEYPAD_MULTIPLY"} ,
            { 188 , "KEYPAD_SUBTRACT"} ,
            { 189 , "KEYPAD_ADD"} ,
            { 190 , "KEYPAD_ENTER"} ,
            { 191 , "KEYPAD_1"} ,
            { 192 , "KEYPAD_2"} ,
            { 193 , "KEYPAD_3"} ,
            { 194 , "KEYPAD_4"} ,
            { 195 , "KEYPAD_5"} ,
            { 196 , "KEYPAD_6"} ,
            { 197 , "KEYPAD_7"} ,
            { 198 , "KEYPAD_8"} ,
            { 199 , "KEYPAD_9"} ,
            { 200 , "KEYPAD_0"} ,
            { 201 , "KEYPAD_DOT"} ,
            { 202 , "KEY_NON_US"} ,
            { 203 , "MEDIA_STOP"} ,
            { 204 , "MEDIA_PREVIOUS"} ,
            { 205 , "MEDIA_PLAY_PAUSE"} ,
            { 206 , "MEDIA_NEXT"} ,
            { 207 , "KEY_PRINTSCREEN"} ,
            { 250 , "releaseAll"}
        };
    keyStrings = {" ",                  "!",                  "\"",                  "{",                  "$",
                  "%",                  "&",                  "\'",                  "(",                  ")",
                  "*",                  "+",                  "{",                  "-",                  ".",
                  "/",                  "0",                  "1",                  "2",                  "3",
                  "4",                  "5",                  "6",                  "7",
                  "8",                  "9",                  ":",                  ";",
                  "<",                  "=",                  ">",                  "?",
                  "@",                  "A",                  "B",                  "C",
                  "D",                  "E",                  "F",                  "G",
                  "H",                  "I",                  "J",                  "K",
                  "L",                  "M",                  "N",                  "O",
                  "P",                  "Q",                  "R",                  "S",
                  "T",                  "U",                  "V",                  "W",
                  "X",                  "Y",                  "Z",                  "[",
                  "\\",                  "]",                 "^",
                  "_",                  "`",                  "a",                  "b",
                  "c",                  "d",                  "e",                  "f",
                  "g",                  "h",                  "i",                  "j",
                  "k",                  "l",                  "m",                  "n",
                  "o",                  "p",                  "q",                  "r",
                  "s",                  "t",                  "u",                  "v",
                  "w",                  "x",                  "y",                  "z",
                  "{",                  "|",                  "}",                  "~",
                  "KEY_LEFT_CTRL",                  "KEY_LEFT_SHIFT",
                  "KEY_LEFT_ALT",                  "KEY_LEFT_GUI",
                  "KEY_LEFT_WINDOWS",                  "KEY_RIGHT_CTRL",
                  "KEY_RIGHT_SHIFT",                  "KEY_RIGHT_ALT",
                  "KEY_RIGHT_GUI",                  "KEY_RIGHT_WINDOWS",
                  "KEY_ENTER",                  "KEY_ESC",                  "KEY_BACKSPACE",
                  "KEY_TAB",                  "KEY_SPACE",
                  "KEY_MINUS",                  "KEY_EQUAL",
                  "KEY_LEFT_BRACE",                  "KEY_RIGHT_BRACE",
                  "KEY_BACKSLASH",                  "KEY_NON_US_NUM",
                  "KEY_SEMICOLON",                  "KEY_QUOTE",
                  "KEY_TILDE",                  "KEY_COMMA",
                  "KEY_PERIOD",                  "KEY_SLASH",
                  "KEY_CAPS_LOCK",                  "KEY_F1",
                  "KEY_F2",                  "KEY_F3",
                  "KEY_F4",                  "KEY_F5",
                  "KEY_F6",                  "KEY_F7",
                  "KEY_F8",                  "KEY_F9",
                  "KEY_F10",                  "KEY_F11",
                  "KEY_F12",                  "KEY_PRINTSCREEN",
                  "KEY_SCROLL_LOCK",                  "KEY_PAUSE",
                  "KEY_INSERT",                  "KEY_HOME",
                  "KEY_PAGE_UP",                  "KEY_DELETE",
                  "KEY_END",                  "KEY_PAGE_DOWN",
                  "KEY_RIGHT_ARROW",                  "KEY_LEFT_ARROW",
                  "KEY_DOWN_ARROW",                  "KEY_UP_ARROW",
                  "KEY_RIGHT",                  "KEY_LEFT",                  "KEY_DOWN",
                  "KEY_UP",                  "KEY_NUM_LOCK",
                  "KEYPAD_DIVIDE",                  "KEYPAD_MULTIPLY",
                  "KEYPAD_SUBTRACT",                  "KEYPAD_ADD",
                  "KEYPAD_ENTER",                  "KEYPAD_1",
                  "KEYPAD_2",                  "KEYPAD_3",
                  "KEYPAD_4",                  "KEYPAD_5",
                  "KEYPAD_6",                  "KEYPAD_7",
                  "KEYPAD_8",                  "KEYPAD_9",
                  "KEYPAD_0",                  "KEYPAD_DOT",
                  "KEY_NON_US",                  "MEDIA_STOP",
                  "MEDIA_PREVIOUS",                  "MEDIA_PLAY_PAUSE",
                  "MEDIA_NEXT",                  "KEY_PRINTSCREEN",
                  "releaseAll"};

}
Convert* Convert::getInstance()
{
    if(convert == nullptr)
    {
        convert = new Convert();
    }
    return convert;
}


int Convert::getKeyCode(QString Key)
{
    return  codeMap[Key];

}
QString Convert::getKeyString(int keycode)
{
    return keyMap[keycode];
}

QStringList Convert::getKeyStrings()
{
    return keyStrings;
}