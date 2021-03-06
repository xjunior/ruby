#include "internal.h"

static VALUE
int_bignum_p(VALUE self)
{
    return RB_TYPE_P(self, T_BIGNUM) ? Qtrue : Qfalse;
}

static VALUE
int_fixnum_p(VALUE self)
{
    return FIXNUM_P(self) ? Qtrue : Qfalse;
}

static VALUE
rb_int_to_bignum(VALUE x)
{
    if (FIXNUM_P(x))
        x = rb_int2big(FIX2LONG(x));
    return x;
}

void
Init_integer(VALUE klass)
{
    rb_define_method(rb_cInteger, "bignum?", int_bignum_p, 0);
    rb_define_method(rb_cInteger, "fixnum?", int_fixnum_p, 0);
    rb_define_method(rb_cInteger, "to_bignum", rb_int_to_bignum, 0);
}
