// Basic types.

typedef struct struct_name {
	char x;
	int y;
} struct_type;

typedef enum enum_name {
	A = 1,
	B = 2,
} enum_type;

// Basic type                                            xxxx
//                                     00 00 00 00 00 00

long long v_0000;
void v_0001;
char v_0002;
short v_0003;
int v_0004;
long v_0005;
float v_0006;
double v_0007;
struct_type v_0008;
//? v_0009;
enum_type v_000A;
//? v_000B;
unsigned char v_000C;
unsigned short v_000D;
unsigned int v_000E;
unsigned long v_000F;

// Derived types.

// Basic type                                            xxxx
//    pointer                                         01
//                                     00 00 00 00 00

long long * v_0010;
void * v_0011;
char * v_0012;
short * v_0013;
int * v_0014;
long * v_0015;
float * v_0016;
double * v_0017;
struct_type * v_0018;
//? * v_0019;
enum_type * v_001A;
//? * v_001B;
unsigned char * v_001C;
unsigned short * v_001D;
unsigned int * v_001E;
unsigned long * v_001F;

// Basic type                                            xxxx
//    function                                        10
//                                     00 00 00 00 00

long long f_0020() {}
void f_0021() {}
char f_0022() {}
short f_0023() {}
int f_0024() {}
long f_0025() {}
float f_0026() {}
double f_0027() {}
struct_type f_0028() {}
//? f_0029() {}
enum_type f_002A() {}
//? f_002B() {}
unsigned char f_002C() {}
unsigned short f_002D() {}
unsigned int f_002E() {}
unsigned long f_002F() {}

// Basic type                                            xxxx
//    array                                           11
//                                     00 00 00 00 00

long long v_0030[1];
//void v_0031[1];
char v_0032[1];
short v_0033[1];
int v_0034[1];
long v_0035[1];
float v_0036[1];
double v_0037[1];
struct_type v_0038[1];
//? v_0039[1];
enum_type v_003A[1];
//? v_003B[1];
unsigned char v_003C[1];
unsigned short v_003D[1];
unsigned int v_003E[1];
unsigned long v_003F[1];

// Basic type                                            xxxx
//    pointer                                         01
//        pointer                                  01
//                                     00 00 00 00

long long ** v_0050;
void ** v_0051;
char ** v_0052;
short ** v_0053;
int ** v_0054;
long ** v_0055;
float ** v_0056;
double ** v_0057;
struct_type ** v_0058;
//? ** v_0059;
enum_type ** v_005A;
//? ** v_005B;
unsigned char ** v_005C;
unsigned short ** v_005D;
unsigned int ** v_005E;
unsigned long ** v_005F;

// Basic type                                            xxxx
//    function                                        10
//        pointer                                  01
//                                     00 00 00 00

long long * f_0060() {}
void * f_0061() {}
char * f_0062() {}
short * f_0063() {}
int * f_0064() {}
long * f_0065() {}
float * f_0066() {}
double * f_0067() {}
struct_type * f_0068() {}
//? * f_0069() {}
enum_type * f_006A() {}
//? * f_006B() {}
unsigned char * f_006C() {}
unsigned short * f_006D() {}
unsigned int * f_006E() {}
unsigned long * f_006F() {}

// Basic type                                            xxxx
//    array                                           11
//        pointer                                  01
//                                     00 00 00 00

long long * v_0070[1];
void * v_0071[1];
char * v_0072[1];
short * v_0073[1];
int * v_0074[1];
long * v_0075[1];
float * v_0076[1];
double * v_0077[1];
struct_type * v_0078[1];
//? * v_0079[1];
enum_type * v_007A[1];
//? * v_007B[1];
unsigned char * v_007C[1];
unsigned short * v_007D[1];
unsigned int * v_007E[1];
unsigned long * v_007F[1];

// Basic type                                            xxxx
//    pointer                                         01
//        function                                 10
//                                     00 00 00 00

long long (*v_0090)();
void (*v_0091)();
char (*v_0092)();
short (*v_0093)();
int (*v_0094)();
long (*v_0095)();
float (*v_0096)();
double (*v_0097)();
struct_type (*v_0098)();
//? (*v_0099)();
enum_type (*v_009A)();
//? (*v_009B)();
unsigned char (*v_009C)();
unsigned short (*v_009D)();
unsigned int (*v_009E)();
unsigned long (*v_009F)();

// Basic type                                            xxxx
//    function                                        10
//        function                                 10
//                                     00 00 00 00

// Basic type                                            xxxx
//    array                                           11
//        function                                 10
//                                     00 00 00 00

// Basic type                                            xxxx
//    pointer                                         01
//        array                                    11
//                                     00 00 00 00

// Basic type                                            xxxx
//    function                                        10
//        array                                    11
//                                     00 00 00 00

// Basic type                                            xxxx
//    array                                           11
//        array                                    11
//                                     00 00 00 00

long long v_00F0[1][2];
//void v_00F1[1][2];
char v_00F2[1][2];
short v_00F3[1][2];
int v_00F4[1][2];
long v_00F5[1][2];
float v_00F6[1][2];
double v_00F7[1][2];
struct_type v_00F8[1][2];
//? v_00F9[1][2];
enum_type v_00FA[1][2];
//? v_00FB[1][2];
unsigned char v_00FC[1][2];
unsigned short v_00FD[1][2];
unsigned int v_00FE[1][2];
unsigned long v_00FF[1][2];

// etc.

// Basic type                                            xxxx
//    array                                           11
//       array                                     11
//          array                               11
//             array                         11
//                array                   11
//                   array             11

long long v_FFF0[1][2][3][4][5][6];
//void v_FFF1[1][2][3][4][5][6];
char v_FFF2[1][2][3][4][5][6];
short v_FFF3[1][2][3][4][5][6];
int v_FFF4[1][2][3][4][5][6];
long v_FFF5[1][2][3][4][5][6];
float v_FFF6[1][2][3][4][5][6];
double v_FFF7[1][2][3][4][5][6];
struct_type v_FFF8[1][2][3][4][5][6];
//? v_FFF9[1][2][3][4][5][6];
enum_type v_FFFA[1][2][3][4][5][6];
//? v_FFFB[1][2][3][4][5][6];
unsigned char v_FFFC[1][2][3][4][5][6];
unsigned short v_FFFD[1][2][3][4][5][6];
unsigned int v_FFFE[1][2][3][4][5][6];
unsigned long v_FFFF[1][2][3][4][5][6];
