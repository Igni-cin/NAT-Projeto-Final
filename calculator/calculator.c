#include <stdio.h>
#include <assert.h>

// Funções da calculadora
int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

int multiply(int a, int b) {
    return a * b;
}

int divide(int a, int b) {
    if (b == 0) {
        return 0; // Evitar erro na divisão por zero
    }
    return a / b;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

int is_even(int a) {
    return (a % 2) == 0;
}

// Funções de teste
void test_add() {
    assert(add(2, 3) == 5);
    assert(add(-1, 1) == 0);
    assert(add(0, 0) == 0);
    printf("Teste add: OK\n");
}

void test_subtract() {
    assert(subtract(5, 3) == 2);
    assert(subtract(3, 5) == -2);
    assert(subtract(0, 0) == 0);
    printf("Teste subtract: OK\n");
}

void test_multiply() {
    assert(multiply(2, 3) == 6);
    assert(multiply(-2, 3) == -6);
    assert(multiply(0, 5) == 0);
    printf("Teste multiply: OK\n");
}

void test_divide() {
    assert(divide(6, 3) == 2);
    assert(divide(5, 2) == 2); // Divisão inteira
    assert(divide(0, 5) == 0);
    assert(divide(5, 0) == 0); // Caso de erro
    printf("Teste divide: OK\n");
}

void test_max() {
    assert(max(5, 3) == 5);
    assert(max(3, 5) == 5);
    assert(max(5, 5) == 5);
    assert(max(-5, -10) == -5);
    printf("Teste max: OK\n");
}

void test_is_even() {
    assert(is_even(2) == 1);
    assert(is_even(3) == 0);
    assert(is_even(0) == 1);
    assert(is_even(-2) == 1);
    assert(is_even(-3) == 0);
    printf("Teste is_even: OK\n");
}

// Função principal
int main() {
    printf("Iniciando testes...\n");

    test_add();
    test_subtract();
    test_multiply();
    test_divide();
    test_max();
    test_is_even();

    printf("Todos os testes passaram!\n");
    return 0;
}