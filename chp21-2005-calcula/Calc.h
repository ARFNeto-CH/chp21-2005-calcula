#pragma once
#include<iostream>
#include<string>

enum Operator { SUBTRACTION, SUM, EQUAL, NOOP };
enum Digit { ZERO, UM, DOIS, TRES, QUATRO, CINCO, SEIS, SETE, OITO, NOVE };
enum Control { CE, DECIMAL_SEPARATOR, OFF, MRC, MEMORY_SUBTRACTION, MEMORY_SUM };

class Display {
public:
    virtual void clean() = 0;
    virtual void addDigit(Digit digit) = 0;
    virtual void setDecimalSeparator() = 0;
};

class Cpu {
public:
    virtual void setDisplay(Display* display) = 0;

    virtual void receiveDigit(Digit digit) = 0;
    virtual void receiveOperator(Operator operator_) = 0;
    virtual void receiveControl(Control control) = 0;
};

class Keyboard {
public:
    virtual void setCpu(Cpu* cpu) = 0;

    virtual void pressZero() = 0;
    virtual void pressUm() = 0;
    virtual void pressDois() = 0;
    virtual void pressTres() = 0;
    virtual void pressQuatro() = 0;
    virtual void pressCinco() = 0;
    virtual void pressSeis() = 0;
    virtual void pressSete() = 0;
    virtual void pressOito() = 0;
    virtual void pressNove() = 0;

    virtual void pressDecimalSeparator() = 0;

    virtual void pressSum() = 0;
    virtual void pressSubtraction() = 0;
    virtual void pressEqual() = 0;

    virtual void pressCE() = 0;
    virtual void pressOFF() = 0;
};

class Calculator {
public:
    virtual Keyboard* getKeyboard() = 0;
    virtual void setKeyboard(Keyboard* keyboard) = 0;

    virtual Display* getDisplay() = 0;
    virtual void setDisplay(Display* display) = 0;

    virtual Cpu* getCpu() = 0;
    virtual void setCpu(Cpu* cpu) = 0;
};

