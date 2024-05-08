// Algoritmo para la creacion de arboles por evaluacion de expresiones
// Arboles de expresiones

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct exprNode {
    char operator;           
    int value;               // Valor del nodo (si es un operando)
    struct exprNode* left;   // Subarbol izquierdo
    struct exprNode* right;  // Subarbol derecho
} exprNode;

// Funcion para crear un nodo con un operador
exprNode* createOperatorNode(char operator, exprNode* left, exprNode* right) {
    exprNode* node = (exprNode*)malloc(sizeof(exprNode));
    node->operator = operator;
    node->left = left;
    node->right = right;
    node->value = 0; // No tiene valor específico, es un operador
    return node;
}

// Funcion para crear un nodo con un operando
exprNode* createOperandNode(int value) {
    exprNode* node = (exprNode*)malloc(sizeof(exprNode));
    node->operator = '\0'; // No es un operador
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Evaluacion del arbol de expresion
int evaluate(exprNode* root) {
    if (root == NULL) {
        return 0; 
    }
    if (root->operator == '\0') {
        return root->value; // Si es un operando, regresamos su valor
    }

    // Evaluamos subarboles
    int leftVal = evaluate(root->left);
    int rightVal = evaluate(root->right);

    // Aplicamos la operacion
    switch (root->operator) {
        case '+':
            return leftVal + rightVal;
        case '-':
            return leftVal - rightVal;
        case '*':
            return leftVal * rightVal;
        case '/':
            return leftVal / rightVal;
        case '^':
            return pow(leftVal, rightVal); 
        case '%':
            return leftVal % rightVal;
        default:
            return 0; 
    }
}

// Liberar memoria del arbol
void freeTree(exprNode* root) {
    if (root == NULL) {
        return;
    }
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main() {
    // (3 + 5) * (2 - 1)
    int n1 = 3, n2 = 5, n3 = 2, n4 = 1;
    exprNode* left = createOperatorNode('+', createOperandNode(n1), createOperandNode(n2)); //Primer parentesis
    exprNode* right = createOperatorNode('-', createOperandNode(n3), createOperandNode(n4)); //Segundo parentesis
    exprNode* root = createOperatorNode('*', left, right); // Evaluacion final

    int result = evaluate(root);
    printf("Resultado: %d\n", result);
    freeTree(root);

    return 0;
}
