#ifndef STARCHTYPES
#define STARCHTYPES

// what type of enum it is
enum StarchNodeTypes {
    STARCH_CONTROLFLOW,
    STARCH_OPERATOR,
    STARCH_BASE_TYPE,
};

struct StarchNode
{
    void* node;
    enum StarchNodeTypes type;
};


// types for starch types
enum StarchNodeOperators {
    STARCH_ADD,
    STARCH_SUBTRACT,
    STARCH_MULTIPLY,
    STARCH_DIVIDE,
    STARCH_GTEQ,
    STARCH_GT,
    STARCH_LT,
    STARCH_LTEQ,
    STARCH_EQ,
    STARCH_PTR,
};

enum StarchControlFlowTypes {
    STARCH_IF,
    STARCH_ELSE_IF,
    STARCH_ELSE,
    STARCH_SWITCH,
    STARCH_WHILE,
    STARCH_FOR,
    STARCH_FUNCTION,
};

enum StarchNodeBaseTypes {
    STARCH_VOID,
    STARCH_INT,
    STARCH_BOOL,
    STARCH_FLOAT,
    STARCH_LONG_N, // by default the value of long_n is 1
    STARCH_BYTE_N, // by default the valuse of lbyte_n is 1
    STARCH_OBJECT,
    STARCH_STRUCT,
    STARCH_ENUM,
    STARCH_CHAR,
};


struct StarchNodeControlFlow
{
    void* node;
    enum StarchControlFlowTypes type;
};

struct StarchNodeOperator {
    void* node;
    enum StarchNodeOperators type;
};

struct StarchNodeBaseType {
    void* node;
    enum StarchNodeTypes type;
};

struct StarchAdd { struct StarchNodeBaseType* a; struct StarchNodeBaseType* b;};
struct StarchSubtreact { struct StarchNodeBaseType* a; struct StarchNodeBaseType* b;};
struct StarchMultiply { struct StarchNodeBaseType* a; struct StarchNodeBaseType* b;};
struct StarchDivide { struct StarchNodeBaseType* a; struct StarchNodeBaseType* b;};




#endif