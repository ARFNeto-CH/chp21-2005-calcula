#include "Calc.cpp"

void testCalculator(Calculator* calc);

int main() {

    DisplaySthefani* d1 = new DisplaySthefani();
    CpuSthefani* cpu1 = new CpuSthefani(d1);
    KeyboardSthefani* kb1 = new KeyboardSthefani(cpu1);

    CalculatorSthefani* calc = new CalculatorSthefani(d1, cpu1, kb1);

    testCalculator(calc);

    return 0;
}

void testCalculator(Calculator* calc) {
    calc->getKeyboard()->pressUm();
    calc->getKeyboard()->pressDois();
    calc->getKeyboard()->pressTres();
    calc->getKeyboard()->pressSum();
    calc->getKeyboard()->pressQuatro();
    calc->getKeyboard()->pressCinco();
    calc->getKeyboard()->pressSeis();
    calc->getKeyboard()->pressSum();

    calc->getKeyboard()->pressCE();

    calc->getKeyboard()->pressDois();
    calc->getKeyboard()->pressTres();
    calc->getKeyboard()->pressSum();
    calc->getKeyboard()->pressQuatro();
    calc->getKeyboard()->pressCinco();
    calc->getKeyboard()->pressSubtraction();
    calc->getKeyboard()->pressSeis();
    calc->getKeyboard()->pressSete();
    calc->getKeyboard()->pressEqual();
}

