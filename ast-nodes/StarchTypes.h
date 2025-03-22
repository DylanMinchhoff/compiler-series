#ifndef STARCHTYPES
#define STARCHTYPES

// what type of enum it is
enum StarchNodeTypes {
    CONTROLFLOW,
    OPERATOR,
    BASE_TYPE
};

struct StarchNode
{
    void* node;
    enum StarchNodeTypes type;
};


// types for starch types
enum StarchNodeOperators {
    ADD,
    SUBTRACT,
    MULTIPLY,
    DIVIDE,
    GTEQ,
    GT,
    LT,
    LTEQ,
    EQ,
    PTR
};

enum StarchControlFlowTypes {
    IF,
    ELSE_IF,
    ELSE,
    SWITCH,
    WHILE,
    FOR,
    FUNCTION
};

enum StarchNodeBaseTypes {
    VOID,
    INT,
    BOOL,
    FLOAT,
    LONG_N, // by default the value of long_n is 1
    BYTE_N, // by default the valuse of lbyte_n is 1
    OBJECT,
    STRUCT,
    ENUM,
    CHAR
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