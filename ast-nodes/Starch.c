#include "StarchTypes.h"
#include "utility/UtilityTypes.h"

struct StarchBaseType* starchOperatorAST(struct StarchNodeOperator* op) {

}


struct StarchBaseType* starchControlFlowAST(struct StarchNodeControlFlow* cf) {
    
}





struct StarchBaseType* StarchAST(struct StarchNode* ast) {
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
