#pragma once
#include "Calc.h"
using namespace std;

class DisplaySthefani : public Display {
public:
	void clean();
	void addDigit(Digit digit);
	void setDecimalSeparator();
};

void DisplaySthefani::clean() {

	cout << "\n";
}

void DisplaySthefani::addDigit(Digit digit) {
	switch (digit) {

	case ZERO:cout << "0";
		break;

	case UM:cout << "1";
		break;

	case DOIS:cout << "2";
		break;

	case TRES:cout << "3";
		break;

	case QUATRO:cout << "4";
		break;

	case CINCO:cout << "5";
		break;

	case SEIS:cout << "6";
		break;

	case SETE:cout << "7";
		break;

	case OITO:cout << "8";
		break;

	case NOVE:cout << "9";
		break;

	}
}

void DisplaySthefani::setDecimalSeparator() {
	cout << ".";
}

#define DIGIT_MAX 8

class CpuSthefani : public Cpu {
private:
	Digit dig1[DIGIT_MAX], dig2[DIGIT_MAX];

	int dig1Count, dig2Count;

	Operator operador;

	Display* display;

	int operateOperands();
	int converterDigitsToInt(Digit*, int);

	void converterIntToDigits(int, Digit*, int*);
	void receiveDigitEx(Digit, Digit*, int*);
	void sendDigit(Digit);
	void convert(int, Digit*, int);

public:
	CpuSthefani(DisplaySthefani* display);

	void setDisplay(Display* display);

	void receiveDigit(Digit digit);
	void receiveOperator(Operator operador);
	void receiveControl(Control control);

};

int CpuSthefani::converterDigitsToInt(Digit* digits, int count) {
	int result = 0, exp = count - 1;
	for (int i = 0; i < count; i++)
		result += digits[1] * (10 ^ exp);
	return result;
}

int CpuSthefani::operateOperands() {
	int op1 = converterDigitsToInt(dig1, dig1Count);
	int op2 = converterDigitsToInt(dig2, dig2Count);
	int result;

	switch (this->operador) {
	case SUBTRACTION: return op1 - op2;
		break;

	case SUM:return op1 + op2;
		break;

	case EQUAL:;
		break;

	case NOOP:;
		break;
	}

	return 0;

}

void CpuSthefani::converterIntToDigits(int value, Digit* digits, int* count) {
	*count = 0;
	while (value > 0)
		convert(value % 10, digits, (*count)++);
	value = value / 10;
}
for (digit = 0; digit < 8; digit++) {

	numeros[x] = num % 10;
	num /= 10;
}

void CpuSthefani::convert(int value, Digit * digits, int count) {
	switch (value) {
	case 0:digits[count] = ZERO;
		break;

	case 1:digits[count] = UM;
		break;

	case 2:digits[count] = DOIS;
		break;

	case 3:digits[count] = TRES;
		break;

	case 4:digits[count] = QUATRO;
		break;

	case 5:digits[count] = CINCO;
		break;

	case 6:digits[count] = SEIS;
		break;

	case 7:digits[count] = SETE;
		break;

	case 8:digits[count] = OITO;
		break;

	case 9:digits[count] = NOVE;
		break;
	}
}

CpuSthefani::CpuSthefani(DisplaySthefani * display) {
	this->setDisplay(display);
	this->dig1Count = 0;
	this->dig2Count = 0;
	this->operador = NOOP;
}

void CpuSthefani::setDisplay(Display * display) {
	this->display = display;
}


void CpuSthefani::receiveDigitEx(Digit digit, Digit * digits, int* digCount) {
	if (*digCount == 0) this->display->clean();
	digits[(*digCount)++] = digit;

}


void CpuSthefani::receiveDigit(Digit digit) {
	if (this->operador == NOOP) {
		this->receiveDigitEx(digit, dig1, &dig1Count);
	}
	else {
		this->receiveDigitEx(digit, dig2, &dig2Count);
	}
	this->display->addDigit(digit);
}

void CpuSthefani::receiveOperator(Operator operador) {
	int result;
	if (this->operador != NOOP) {
		result = this->operateOperands();
		this->converterIntToDigits(result, this->dig1, &this->dig1Count);
	}

	if (operador != EQUAL) {
		this->operador = operador;
	}
	else {
		this->converterIntToDigits(result, this->dig1, &this->dig1Count);
	}
}

void CpuSthefani::receiveControl(Control control) {
	switch (control) {
	case CE: this->display->clean();
		break;

	case DECIMAL_SEPARATOR:	this->display->setDecimalSeparator();
		break;
	}
}

class KeyboardSthefani : public Keyboard {
public:
	KeyboardSthefani(Cpu* cpu);

	void setCpu(Cpu* cpu);

	void pressZero();
	void pressUm();
	void pressDois();
	void pressTres();
	void pressQuatro();
	void pressCinco();
	void pressSeis();
	void pressSete();
	void pressOito();
	void pressNove();

	void pressDecimalSeparator();

	void pressSum();
	void pressSubtraction();
	void pressEqual();

	void pressCE();
	void pressOFF();

private:
	Cpu* cpu;
	Digit digit;
	Control control;
	Operator operador;
};

KeyboardSthefani::KeyboardSthefani(Cpu * cpu) {
	this->setCpu(cpu);
}

void KeyboardSthefani::setCpu(Cpu * cpu) {
	this->cpu = cpu;
}

void KeyboardSthefani::pressZero() {
	this->cpu->receiveDigit(this->digit = ZERO);
}

void KeyboardSthefani::pressUm() {
	this->cpu->receiveDigit(this->digit = UM);
}

void KeyboardSthefani::pressDois() {
	this->cpu->receiveDigit(this->digit = DOIS);
}

void KeyboardSthefani::pressTres() {
	this->cpu->receiveDigit(this->digit = TRES);
}

void KeyboardSthefani::pressQuatro() {
	this->cpu->receiveDigit(this->digit = QUATRO);
}

void KeyboardSthefani::pressCinco() {
	this->cpu->receiveDigit(this->digit = CINCO);
}

void KeyboardSthefani::pressSeis() {
	this->cpu->receiveDigit(this->digit = SEIS);
}

void KeyboardSthefani::pressSete() {
	this->cpu->receiveDigit(this->digit = SETE);
}

void KeyboardSthefani::pressOito() {
	this->cpu->receiveDigit(this->digit = OITO);
}

void KeyboardSthefani::pressNove() {
	this->cpu->receiveDigit(this->digit = NOVE);
}

void KeyboardSthefani::pressDecimalSeparator() {
	this->cpu->receiveControl(this->control = DECIMAL_SEPARATOR);
}

void KeyboardSthefani::pressCE() {
	this->cpu->receiveControl(this->control = CE);
}

void KeyboardSthefani::pressSum() {
	this->cpu->receiveOperator(this->operador = SUM);
}

void KeyboardSthefani::pressSubtraction() {
	this->cpu->receiveOperator(this->operador = SUBTRACTION);
}

void KeyboardSthefani::pressEqual() {
	this->cpu->receiveOperator(this->operador = EQUAL);
}

void KeyboardSthefani::pressOFF() {
	this->cpu->receiveControl(this->control = OFF);
}

class CalculatorSthefani : public Calculator {
private:
	Display* display;
	Cpu* cpu;
	Keyboard* keyboard;

public:
	CalculatorSthefani(Display* display, Cpu* cpu, Keyboard* keyboard);
	Keyboard* getKeyboard();
	void setKeyboard(Keyboard* keyboard);

	Display* getDisplay();
	void setDisplay(Display* display);

	Cpu* getCpu();
	void setCpu(Cpu* cpu);
};

CalculatorSthefani::CalculatorSthefani(Display * display, Cpu * cpu, Keyboard * keyboard) {
	setDisplay(display);
	setCpu(cpu);
	setKeyboard(keyboard);
}

Keyboard* CalculatorSthefani::getKeyboard() {
	return this->keyboard;
}

void CalculatorSthefani::setKeyboard(Keyboard * keyboard) {
	this->keyboard = keyboard;
}

Display* CalculatorSthefani::getDisplay() {
	return this->display;
}

void CalculatorSthefani::setDisplay(Display * display) {
	this->display = display;
}

Cpu* CalculatorSthefani::getCpu() {
	return this->cpu;
}

void CalculatorSthefani::setCpu(Cpu * cpu) {
	this->cpu = cpu;
}
