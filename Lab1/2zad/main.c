#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//--------------------------------------//
//---------Unary_Function class---------//
struct Unary_Function {
    int lower_bound;
    int upper_bound;
    struct Unary_Function_vTable *virtual_Functions;
};

struct Unary_Function_vTable {
    double (*value_at)(struct Unary_Function*, double);
    double (*negative_value_at)(struct Unary_Function*, double);
};

double negative_value_at(struct Unary_Function* this, double x) {
    return -this->virtual_Functions->value_at(this, x);
}

void tabulate(struct Unary_Function* this) {
    for(int x = this->lower_bound; x <= this->upper_bound; x++) {
        printf("f(%d)=%lf\n", x, this->virtual_Functions->value_at(this, x));
    }
};

static bool same_functions_for_ints(struct Unary_Function* f1, struct Unary_Function* f2, double tolerance) {
    if(f1->lower_bound != f2->lower_bound) return false;
    if(f1->upper_bound != f2->upper_bound) return false;
    for(int x = f1->lower_bound; x <= f1->upper_bound; x++) {
        double delta = f1->virtual_Functions->value_at(f1, x) - f2->virtual_Functions->value_at(f2, x);
        if(delta < 0) delta = -delta;
        if(delta > tolerance) return false;
    }
    return true;
};

//virtualne funkcije//
struct Unary_Function_vTable *unary_table = {NULL, &negative_value_at};
//------------------//

//------Konstruktor------//
void construct_Unary_Function(struct Unary_Function* this, int lb, int ub) {
    this->virtual_Functions = &unary_table;
    this->lower_bound = lb;
    this->upper_bound = ub;

}
struct Unary_Function* create_Unary_Function(int lb, int ub) {
    struct Unary_Function* this = (struct Unary_Function*)malloc(sizeof(struct Unary_Function));
    construct_Unary_Function(this, lb, ub);
    return this;
}
//-----------------------//

//--------------------------------------//
//--------------------------------------//


//------------------------------//
//---------Square class---------//
struct Square {
    int lower_bound;
    int upper_bound;
    struct Unary_Function_vTable *virtual_Functions;
};

double square_value_at(struct Unary_Function* this, double x) {
    return x*x;
}

//virtualne funkcije//
struct Unary_Function_vTable *square_table = {&square_value_at, &negative_value_at};
//------------------//

//------Konstruktor------//
void construct_Square(struct Square* this, int lb, int ub) {
    construct_Unary_Function((struct Unary_Function*)this, lb, ub);
    ((struct Unary_Function*)this)->virtual_Functions = &square_table;
}
struct Unary_Function* create_Square(int lb, int ub) {
    struct Square* this = (struct Square*)malloc(sizeof(struct Square));
    construct_Square(this, lb, ub);
    return (struct Unary_Function *) this;
}
//-----------------------//

// ------------------------------//
// ------------------------------//

//------------------------------//
//---------Linear class---------//
struct Linear {
    int lower_bound;
    int upper_bound;
    struct Linear_Function_vTable *virtual_Functions;

    double a;
    double b;
};

double linear_value_at(struct Linear* this, double x) {
    return this->a*x + this->b;
}

//virtualne funkcije//
struct Unary_Function_vTable linear_table = {(double (*)(struct Unary_Function*, double)) &linear_value_at, &negative_value_at};
//------------------//

//------Konstruktor------//
void construct_Linear(struct Linear* this, int lb, int ub, double a_coef, double b_coef) {
    construct_Unary_Function((struct Unary_Function*)this, lb, ub);
    ((struct Unary_Function*)this)->virtual_Functions = &linear_table;
    this->a = a_coef;
    this->b = b_coef;
}
struct Unary_Function* create_Linear(int lb, int ub, double a_coef, double b_coef) {
    struct Linear* this = (struct Linear*)malloc(sizeof(struct Linear));
    construct_Linear(this, lb, ub, a_coef, b_coef);
    return (struct Unary_Function *) this;
}
//-----------------------//

// ------------------------------//
// ------------------------------//


int main() {
    struct Unary_Function *f1 = create_Square(-2, 2);
    tabulate(f1);
    struct Unary_Function *f2 = create_Linear(-2, 2, 5, -2);
    tabulate(f2);
    printf("f1==f2: %s\n", same_functions_for_ints(f1, f2, 1E-6) ? "DA" : "NE");
    printf("neg_val f2(1) = %lf\n", f2->virtual_Functions->negative_value_at(f2, 1.0));
    free(f1);
    free(f2);
    return 0;
}