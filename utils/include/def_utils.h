/*
 * def_utils.h
 *
 *  Created on: Sep 18, 2022
 *      Author: Majid
 */

#ifndef INCLUDE_DEF_UTILS_H_
#define INCLUDE_DEF_UTILS_H_
#define OPTION uint8_t

#define CASE_TO_STRING(c) case c: return #c;

#define VARCOUNT(...) VARCOUNT_I(__VA_ARGS__,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1)
#define VARCOUNT_I(_,_16,_15,_14,_13,_12,_11,_10,_9,_8,_7,_6,_5,_4,_3,_2,X_,...) X_
#define GLUE(X,Y) GLUE_I(X,Y)
#define GLUE_I(X,Y) X##Y
#define FIRST(X, ...) X
#define TAIL(X, ...) __VA_ARGS__

#define GLUE_U(X) GLUE(_,X)
#define GLUE_U_1(X) GLUE_U(X)
#define GLUE_U_2(...) GLUE_U(FIRST(__VA_ARGS__)), GLUE_U_1(TAIL(__VA_ARGS__))
#define GLUE_U_3(...) GLUE_U(FIRST(__VA_ARGS__)), GLUE_U_2(TAIL(__VA_ARGS__))
#define GLUE_U_4(...) GLUE_U(FIRST(__VA_ARGS__)), GLUE_U_3(TAIL(__VA_ARGS__))
#define GLUE_U_5(...) GLUE_U(FIRST(__VA_ARGS__)), GLUE_U_4(TAIL(__VA_ARGS__))
#define GLUE_U_6(...) GLUE_U(FIRST(__VA_ARGS__)), GLUE_U_5(TAIL(__VA_ARGS__))
#define GLUE_U_7(...) GLUE_U(FIRST(__VA_ARGS__)), GLUE_U_6(TAIL(__VA_ARGS__))
#define GLUE_U_8(...) GLUE_U(FIRST(__VA_ARGS__)), GLUE_U_7(TAIL(__VA_ARGS__))
#define GLUE_U_9(...) GLUE_U(FIRST(__VA_ARGS__)), GLUE_U_8(TAIL(__VA_ARGS__))
#define GLUE_U_10(...) GLUE_U(FIRST(__VA_ARGS__)), GLUE_U_9(TAIL(__VA_ARGS__))
#define GLUE_U_11(...) GLUE_U(FIRST(__VA_ARGS__)), GLUE_U_10(TAIL(__VA_ARGS__))
#define GLUE_U_12(...) GLUE_U(FIRST(__VA_ARGS__)), GLUE_U_11(TAIL(__VA_ARGS__))
#define GLUE_U_13(...) GLUE_U(FIRST(__VA_ARGS__)), GLUE_U_12(TAIL(__VA_ARGS__))
#define GLUE_U_14(...) GLUE_U(FIRST(__VA_ARGS__)), GLUE_U_13(TAIL(__VA_ARGS__))
#define GLUE_U_15(...) GLUE_U(FIRST(__VA_ARGS__)), GLUE_U_14(TAIL(__VA_ARGS__))
#define GLUE_U_16(...) GLUE_U(FIRST(__VA_ARGS__)), GLUE_U_15(TAIL(__VA_ARGS__))


#define QUOT(...) GLUE(QUOT_, VARCOUNT(__VA_ARGS__))(__VA_ARGS__)
#define QUOT_1(x) #x
#define QUOT_2(x, ...) #x, GLUE(QUOT_, VARCOUNT(__VA_ARGS__))(__VA_ARGS__)
#define QUOT_3(x, ...) #x, GLUE(QUOT_, VARCOUNT(__VA_ARGS__))(__VA_ARGS__)
#define QUOT_4(x, ...) #x, GLUE(QUOT_, VARCOUNT(__VA_ARGS__))(__VA_ARGS__)
#define QUOT_5(x, ...) #x, GLUE(QUOT_, VARCOUNT(__VA_ARGS__))(__VA_ARGS__)
#define QUOT_6(x, ...) #x, GLUE(QUOT_, VARCOUNT(__VA_ARGS__))(__VA_ARGS__)
#define QUOT_7(x, ...) #x, GLUE(QUOT_, VARCOUNT(__VA_ARGS__))(__VA_ARGS__)
#define QUOT_8(x, ...) #x, GLUE(QUOT_, VARCOUNT(__VA_ARGS__))(__VA_ARGS__)
#define QUOT_9(x, ...) #x, GLUE(QUOT_, VARCOUNT(__VA_ARGS__))(__VA_ARGS__)
#define QUOT_10(x, ...) #x, GLUE(QUOT_, VARCOUNT(__VA_ARGS__))(__VA_ARGS__)
#define QUOT_11(x, ...) #x, GLUE(QUOT_, VARCOUNT(__VA_ARGS__))(__VA_ARGS__)
#define QUOT_12(x, ...) #x, GLUE(QUOT_, VARCOUNT(__VA_ARGS__))(__VA_ARGS__)
#define QUOT_13(x, ...) #x, GLUE(QUOT_, VARCOUNT(__VA_ARGS__))(__VA_ARGS__)
#define QUOT_14(x, ...) #x, GLUE(QUOT_, VARCOUNT(__VA_ARGS__))(__VA_ARGS__)
#define QUOT_15(x, ...) #x, GLUE(QUOT_, VARCOUNT(__VA_ARGS__))(__VA_ARGS__)
#define QUOT_16(x, ...) #x, GLUE(QUOT_, VARCOUNT(__VA_ARGS__))(__VA_ARGS__)


#define ENUM_STR(name, ...) enum class name:OPTION{FIRST(__VA_ARGS__) = 0, TAIL(__VA_ARGS__)};
#define ENUM_INT(name, ...) enum class name:OPTION{GLUE_U(FIRST(__VA_ARGS__)) = 0, GLUE(GLUE_U_, VARCOUNT(TAIL(__VA_ARGS__)))(TAIL(__VA_ARGS__))};


#define STR_HELPER(x) #x
#define STR(x) STR_HELPER(x)


#endif /* INCLUDE_DEF_UTILS_H_ */
