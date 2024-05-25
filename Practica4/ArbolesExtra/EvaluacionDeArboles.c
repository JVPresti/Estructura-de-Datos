// Algoritmo para la creacion de arboles por evaluacion de expresiones
// Arboles de expresiones

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct exprNode {
    char operator;           
    double value;            // Valor del nodo (si es un operando)
    struct exprNode* left;   // Subarbol izquierdo
    struct exprNode* right;  // Subarbol derecho
} exprNode;

// Funcion para crear un nodo con un operador
exprNode* createOperatorNode(char operator, exprNode* left, exprNode* right) {
    exprNode* node = (exprNode*)malloc(sizeof(exprNode));
    node->operator = operator;
    node->left = left;
    node->right = right;
    node->value = 0; 
    return node;
}

// Funcion para crear un nodo con un operando
exprNode* createOperandNode(double value) {
    exprNode* node = (exprNode*)malloc(sizeof(exprNode));
    node->operator = '\0'; // No es un operador
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Evaluacion del arbol de expresion
double evaluate(exprNode* root) {
    if (root == NULL) {
        return 0;
    }
    if (root->operator == '\0') {
        return root->value; 
    }

    double leftVal = evaluate(root->left);
    double rightVal = evaluate(root->right);

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
        case '√':
            return sqrt(rightVal); 
        default:
            return 0; 
    }
}

void freeTree(exprNode* root) {
    if (root == NULL) {
        return;
    }
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main() {
    // 5 * 6 - 4 + 8 * 3 ^ (4 - 2) * √3
    
    exprNode* root = createOperatorNode('+', createOperatorNode('-', createOperatorNode('*', createOperandNode(5), createOperandNode(6)), createOperandNode(4)), 
        createOperatorNode('*', createOperatorNode('*', createOperandNode(8),createOperatorNode('^', createOperandNode(3), createOperandNode(2))),  // ^(4 - 2)) 
            createOperatorNode('√', NULL, createOperandNode(3))  // √3
        ));

    double result = evaluate(root);
    printf("Resultado: %.2f\n", result);
    freeTree(root);

    return 0;
}
