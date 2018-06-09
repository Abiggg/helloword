#ifndef STDDATATYPE_H
#define STDDATATYPE_H

#ifndef uint32
#define uint32 unsigned int
#endif

#ifndef uint16
#define uint16 unsigned short int
#endif

#ifndef uint8
#define uint8 unsigned char
#endif

#ifndef OK
#define OK 0
#endif

#ifndef ERROR
#define ERROR 1
#endif

#define Lock 0
#define unLock 1

#define PI 3.14

#define CHECK(x) \
       if(x) \
       {\
           cout<<"error"<<endl;\
           return ;\
       }

#define CHECK_CODE(x,code) \
    if(x) \
    {\
         cout<<"error is "<< x << endl;\
         return ((x<<4) | code); \
    }

/*maxmum*/
#define MAXVALUE(x,y) \
    (x>y?x:y);

/*minnum*/
#define MINVALUE(x,y) \
    (x<y?x:y)

#define RADIAN(x) (x * 3.14 / 180)

typedef enum ERROR_CODE
{
    ERROR_CODE_0 = 1,
    ERROR_CODE_1,
    ERROR_CODE_2,
    ERROR_CODE_3,
    ERROR_CODE_4,
    ERROR_CODE_5,
    ERROR_CODE_6,
    ERROR_CODE_7,
    ERROR_CODE_8,
    ERROR_CODE_9,
    ERROR_CODE_10,
    ERROR_CODE_11,
    ERROR_CODE_12,
    ERROR_CODE_13,
    ERROR_CODE_14,
    ERROR_CODE_15,
    ERROR_CODE_16,
}ERROR_CODE_E;

#endif // STDDATATYPE_H
