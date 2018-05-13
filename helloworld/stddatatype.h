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


#define CHECK(x) \
       if(x) \
       {\
           cout<<"error"<<endl;\
           return ;\
       }

#endif // STDDATATYPE_H
