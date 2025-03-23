#include <stdio.h>
#include <string.h>
#include <assert.h>

// Função para determinar o tipo de triângulo
const char* triangle_type(int a, int b, int c) {
    // Verifica se os lados são válidos
    if (a <= 0 || b <= 0 || c <= 0) {
        return "Not a triangle"; // Lados não podem ser negativos ou zero
    }
    
    // Verifica a desigualdade triangular
    if (a + b <= c || a + c <= b || b + c <= a) {
        return "Not a triangle";
    } else if (a == b && b == c) {
        return "Equilateral";
    } else if (a == b || b == c || a == c) {
        return "Isosceles";
    } else {
        return "Scalene";
    }
}

// Funções de teste
void test_not_a_triangle() {
    // Not a triangle
    assert(strcmp(triangle_type(1, 3, 1), "Not a triangle") == 0);
    assert(strcmp(triangle_type(0, 0, 0), "Not a triangle") == 0);
    assert(strcmp(triangle_type(1, 1, 2), "Not a triangle") == 0);
}

void test_equilateral_triangle() {
    // Equilateral
    assert(strcmp(triangle_type(1, 1, 1), "Equilateral") == 0);
}

void test_isosceles_triangle() {
    // Isosceles (a == b)
    assert(strcmp(triangle_type(2, 2, 3), "Isosceles") == 0);
    // Isosceles (b == c)
    assert(strcmp(triangle_type(3, 2, 2), "Isosceles") == 0);
    // Isosceles (a == c)
    assert(strcmp(triangle_type(2, 3, 2), "Isosceles") == 0);
}

void test_scalene_triangle() {
    // Scalene
    assert(strcmp(triangle_type(3, 4, 5), "Scalene") == 0);
}

// Função principal
int main() {
    test_not_a_triangle();
    test_equilateral_triangle();
    test_isosceles_triangle();
    test_scalene_triangle();

    printf("Todos os testes passaram!\n");
    return 0;
}