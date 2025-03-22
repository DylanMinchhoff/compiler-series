#include "StarchTypes.h"
#include "utility/UtilityTypes.h"
#include "Starch.h"
#include <stddef.h>
#include <stdbool.h>

void* starchDoOp(struct StarchNodeType* node1, struct StarchNodeType* node2, int opType) {
    struct StarchNodeBaseType* a = StarchAST(node1);
    struct StarchNodeBaseType* b = StarchAST(node2);
    // cast type
    // VOID,
    // INT,
    // BOOL,
    // FLOAT,
    // LONG_N, // by default the value of long_n is 1
    // BYTE_N, // by default the valuse of lbyte_n is 1
    // OBJECT,
    // STRUCT,
    // ENUM,
    // CHAR
    
    // the type is set within the macro

    struct StarchNodeBaseType* baseTypeNode = (struct StarchNodeBaseType*) malloc(sizeof(struct StarchNodeBaseType*));
    if(opType == ADD) {CAST_AND_DO_OPERATION(a, b, +);}
    else if(opType == SUBTRACT) {CAST_AND_DO_OPERATION(a, b, -);}
    else if(opType == MULTIPLY) {CAST_AND_DO_OPERATION(a, b, *);}
    else if(opType == DIVIDE) {CAST_AND_DO_OPERATION(a, b, /);}
    else return NULL; //not a type

    // remove previous nodes
    // values are malloc'd
    free(a->node);
    free(b->node);
    free(node1);
    free(node2);
    return baseTypeNode;
}

struct StarchNodeBaseType* starchOperatorAST(struct StarchNodeOperator* op) {
    if(op->type == ADD) {
        struct StarchAdd* add = (struct StarchAdd*) op;
        if (canOeration(add->a->type, add->b->type)) {
            struct StarchNodeBaseType* res = starchDoOp(add->a, add->b, op->type);
            free(add);
            return res;
        }
        else return NULL; // cannot do operation between types
    }
    else if(op->type == SUBTRACT) {
        struct StarchAdd* sub = (struct StarchAdd*) op;
        if (canOeration(sub->a->type, sub->b->type)) {
            struct StarchNodeBaseType* res = starchDoOp(sub->a, sub->b, op->type);
            free(sub);
            return res;
        }
        else return NULL; // cannot do operation between types
    }
    else if(op->type == MULTIPLY) {
        struct StarchAdd* mult = (struct StarchMultiply*) op;
        if (canOeration(mult->a->type, mult->b->type)) {
            struct StarchNodeBaseType* res = starchDoOp(mult->a, mult->b, op->type);
            free(mult);
            return res;
        }
        else return NULL; // cannot do operation between types
    }
    else if(op->type == DIVIDE) {
        struct StarchDivide* divide = (struct StarchDivide*) op;
        if (canOeration(divide->a->type, divide->b->type)) {
            struct StarchNodeBaseType* res = starchDoOp(divide->a, divide->b, op->type);
            free(divide);
            return res;
        }
        else return NULL; // cannot do operation between types
    }
    else if(op->type == GTEQ) {

    }
    else if(op->type == GT) {

    }
    else if(op->type == LT) {

    }
    else if(op->type == LTEQ) {

    }
    else if(op->type == EQ) {

    }
    else {
        return NULL;
    }
}


struct StarchNodeBaseType* starchControlFlowAST(struct StarchNodeControlFlow* cf) {
    if(cf->type == IF) {

    }
    else if(cf->type == ELSE_IF) {

    }
    else if(cf->type == ELSE) {

    }
    else if(cf->type == SWITCH) {

    }
    else if(cf->type == WHILE) {

    }
    else if(cf->type == FOR) {

    }
    else if (cf->type == FUNCTION) {

    }
    else // raise not a control flow type error

    return NULL;
}

struct StarchNodeBaseType* starchBaseTypeAST(struct StarchNodeOperator* op) {
    
}





struct StarchNodeBaseType* StarchAST(struct StarchNode* ast) {
    // evaluate the ast

    if(ast->type == BASE_TYPE) {
        struct StarchNodeBaseType* node = (struct StarchNodeBaseType*) ast->node;
        return node;
    }
    else if(ast->type == OPERATOR) {
        struct StarchNodeOperator* node = (struct StarchNodeOperator*) ast->node;
        return starchOperatorAST(node);
    }
    else if(ast->type == CONTROLFLOW) {
        struct StarchControlFlow* node = (struct StarchNodeControlFlow*) ast->node;
        return starchControlFlowAst(node);
    }
    else {
        // raise error
        // not a type of ast node
    }


}
