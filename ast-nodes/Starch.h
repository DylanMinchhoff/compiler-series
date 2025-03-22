#ifndef STARCH
#define STARCH


#define CAST_AND_DO_OPERATION(a, b, op) \
    if (a->type == INT && b->type == INT) { int* res = malloc(sizeof(int)); *res = *(int*)a->node + *(int*) b->node; baseTypeNode->node = (void*) res; baseTypeNode->type = INT;} \
    else if (a->type == FLOAT && b->type == FLOAT) { int* res = malloc(sizeof(float)); *res = *(float*)a->node + *(float*) b->node; baseTypeNode->node = (void*) res; baseTypeNode->type = FLOAT;} \
    else if (a->type == FLOAT && b->type == INT) { int* res = malloc(sizeof(float)); *res = *(float*)a->node + *(int*) b->node; baseTypeNode->node = (void*) res; baseTypeNode->type = FLOAT;} \
    else if (a->type == INT && b->type == FLOAT) { int* res = malloc(sizeof(float)); *res = *(int*)a->node + *(float*) b->node; baseTypeNode->node = (void*) res; baseTypeNode->type = FLOAT;} \
    else return NULL;\



#endif