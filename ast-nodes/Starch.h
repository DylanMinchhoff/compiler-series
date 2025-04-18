#ifndef STARCH
#define STARCH


#define CAST_AND_DO_OPERATION(a, b, op) \
    if (a->type == STARCH_INT && b->type == STARCH_INT) { int* res = malloc(sizeof(int)); *res = *(int*)a->node + *(int*) b->node; baseTypeNode->node = (void*) res; baseTypeNode->type = STARCH_INT;} \
    else if (a->type == STARCH_FLOAT && b->type == STARCH_FLOAT) { int* res = malloc(sizeof(float)); *res = *(float*)a->node + *(float*) b->node; baseTypeNode->node = (void*) res; baseTypeNode->type = STARCH_FLOAT;} \
    else if (a->type == STARCH_FLOAT && b->type == STARCH_INT) { int* res = malloc(sizeof(float)); *res = *(float*)a->node + *(int*) b->node; baseTypeNode->node = (void*) res; baseTypeNode->type = STARCH_FLOAT;} \
    else if (a->type == STARCH_INT && b->type == STARCH_FLOAT) { int* res = malloc(sizeof(float)); *res = *(int*)a->node + *(float*) b->node; baseTypeNode->node = (void*) res; baseTypeNode->type = STARCH_FLOAT;} \
    else return NULL;\



#endif