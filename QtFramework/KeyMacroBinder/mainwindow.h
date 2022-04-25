#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QSerialPort>
#include <QSerialPortInfo>

#include <QPushButton>
#include <QStringListModel>
#include <map>

using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QSerialPort *port;

    map<string, QPushButton*> btns;

    map<string, QMetaObject::Connection> conns;
    map<int,vector<int>> macro;


    void mappingButtons();
    void connection();

    void serialConenct();
    void serialDisconenct();
    void macroBtnClick(QPushButton*);
    void btnReset();
    void btnConfirm();
    void btnLoad();


private slots:
    void btnClick();
    void serialReceived();
};


static map<int, QString> KeyMap = {
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

#endif // MAINWINDOW_H
