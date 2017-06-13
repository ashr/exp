#define __int8 char
struct _GUID;

typedef struct _GUID IID;
#define __int16 short
#define __int32 int
#define __int64 long long

struct HWND__;
struct _RTL_CRITICAL_SECTION_DEBUG;
struct tagWNDCLASSEXA;
struct HINSTANCE__;
struct HICON__;
struct HBRUSH__;
struct _iobuf;
struct _EXCEPTION_RECORD;
struct _EXCEPTION_POINTERS;
struct _CONTEXT;
struct ITypeInfo;
struct ITypeInfoVtbl;
struct tagTYPEATTR;
struct tagTYPEDESC;
struct ITypeComp;
struct ITypeCompVtbl;
union tagBINDPTR;
struct tagFUNCDESC;
struct tagELEMDESC;
struct tagPARAMDESCEX;
struct tagVARIANT;
struct IUnknown;
struct IUnknownVtbl;
struct IDispatch;
struct IDispatchVtbl;
struct tagDISPPARAMS;
struct tagEXCEPINFO;
struct tagSAFEARRAY;
struct tagDEC;
struct IRecordInfo;
struct IRecordInfoVtbl;
struct tagVARDESC;
struct ITypeLib;
struct ITypeLibVtbl;
struct tagTLIBATTR;
struct MonsterType;
struct SoundFile;
struct IDirectSoundBufferVtbl;
struct _DSBCAPS;
struct tWAVEFORMATEX;
struct IDirectSound;
struct _DSBUFFERDESC;
struct _DDBLTFX;
struct _DDCOLORKEY;
struct _DDBLTBATCH;
struct _DDSURFACEDESC;
struct _DDPIXELFORMAT;
struct _DDSCAPS;
struct IDirectDrawClipper;
struct HDC__;
struct IDirectDrawPalette;
struct _DDOVERLAYFX;
struct IDirectSoundVtbl;
struct _DSCAPS;
struct _DDCAPS;
struct ServerCommand;
struct tagVS_FIXEDFILEINFO;
struct IDirectDrawPaletteVtbl;

/* 1 */
struct _SCOPETABLE_ENTRY
{
  int EnclosingLevel;
  void *FilterFunc;
  void *HandlerFunc;
};

typedef struct _SCOPETABLE_ENTRY _SCOPETABLE_ENTRY;


/* 2 */
typedef struct _SCOPETABLE_ENTRY *PSCOPETABLE_ENTRY;

/* 36 */
typedef void *PVOID;

/* 15 */
typedef unsigned __int32 DWORD;

/* 3 */
struct _EH3_EXCEPTION_REGISTRATION
{
  struct _EH3_EXCEPTION_REGISTRATION *Next;
  PVOID ExceptionHandler;
  PSCOPETABLE_ENTRY ScopeTable;
  DWORD TryLevel;
};

typedef struct _EH3_EXCEPTION_REGISTRATION _EH3_EXCEPTION_REGISTRATION;


/* 4 */
typedef struct _EH3_EXCEPTION_REGISTRATION EH3_EXCEPTION_REGISTRATION;

/* 5 */
typedef struct _EH3_EXCEPTION_REGISTRATION *PEH3_EXCEPTION_REGISTRATION;

/* 119 */
typedef struct _EXCEPTION_POINTERS EXCEPTION_POINTERS;

/* 6 */
struct CPPEH_RECORD
{
  DWORD old_esp;
  EXCEPTION_POINTERS *exc_ptr;
  struct _EH3_EXCEPTION_REGISTRATION registration;
};

typedef struct CPPEH_RECORD CPPEH_RECORD;


/* 8 */
typedef __int32 LONG;

/* 7 */
struct tagRECT
{
  LONG left;
  LONG top;
  LONG right;
  LONG bottom;
};

typedef struct tagRECT tagRECT;


/* 10 */
typedef struct HWND__ *HWND;

/* 12 */
typedef unsigned int UINT;

typedef UINT* PUINT;

/* 13 */
typedef UINT WPARAM;

/* 14 */
typedef LONG LPARAM;

/* 17 */
struct tagPOINT
{
  LONG x;
  LONG y;
};

typedef struct tagPOINT tagPOINT;


/* 16 */
typedef tagPOINT POINT;

/* 9 */
struct tagMSG
{
  HWND hwnd;
  UINT message;
  WPARAM wParam;
  LPARAM lParam;
  DWORD time;
  POINT pt;
};

typedef struct tagMSG tagMSG;


/* 11 */
struct HWND__
{
  int unused;
};

typedef struct HWND__ HWND__;


/* 21 */
typedef unsigned __int16 WORD;

typedef WORD* LPWORD;

/* 20 */
/* 19 */
/* 22 */
typedef void *LPVOID;

typedef const void *LPCVOID;

/* 18 */
struct _SYSTEM_INFO
{
  union
  {
    DWORD dwOemId;
    struct
    {
      WORD wProcessorArchitecture;
      WORD wReserved;
    };
  };
  DWORD dwPageSize;
  LPVOID lpMinimumApplicationAddress;
  LPVOID lpMaximumApplicationAddress;
  DWORD dwActiveProcessorMask;
  DWORD dwNumberOfProcessors;
  DWORD dwProcessorType;
  DWORD dwAllocationGranularity;
  WORD wProcessorLevel;
  WORD wProcessorRevision;
};

typedef struct _SYSTEM_INFO _SYSTEM_INFO;


/* 25 */
typedef char CHAR;

/* 24 */
typedef CHAR *LPSTR;

/* 27 */
typedef unsigned __int8 BYTE;

/* 26 */
typedef BYTE *LPBYTE;

/* 28 */
typedef void *HANDLE;

typedef HANDLE HMODULE;

/* 23 */
struct _STARTUPINFOA
{
  DWORD cb;
  LPSTR lpReserved;
  LPSTR lpDesktop;
  LPSTR lpTitle;
  DWORD dwX;
  DWORD dwY;
  DWORD dwXSize;
  DWORD dwYSize;
  DWORD dwXCountChars;
  DWORD dwYCountChars;
  DWORD dwFillAttribute;
  DWORD dwFlags;
  WORD wShowWindow;
  WORD cbReserved2;
  LPBYTE lpReserved2;
  HANDLE hStdInput;
  HANDLE hStdOutput;
  HANDLE hStdError;
};

typedef struct _STARTUPINFOA _STARTUPINFOA;


/* 29 */
struct _PROCESS_INFORMATION
{
  HANDLE hProcess;
  HANDLE hThread;
  DWORD dwProcessId;
  DWORD dwThreadId;
};

typedef struct _PROCESS_INFORMATION _PROCESS_INFORMATION;


/* 31 */
typedef struct _RTL_CRITICAL_SECTION_DEBUG *PRTL_CRITICAL_SECTION_DEBUG;

/* 30 */
struct _RTL_CRITICAL_SECTION
{
  PRTL_CRITICAL_SECTION_DEBUG DebugInfo;
  LONG LockCount;
  LONG RecursionCount;
  HANDLE OwningThread;
  HANDLE LockSemaphore;
  DWORD SpinCount;
};

typedef struct _RTL_CRITICAL_SECTION _RTL_CRITICAL_SECTION;


/* 34 */
struct _LIST_ENTRY
{
  struct _LIST_ENTRY *Flink;
  struct _LIST_ENTRY *Blink;
};

typedef struct _LIST_ENTRY _LIST_ENTRY;


/* 33 */
typedef _LIST_ENTRY LIST_ENTRY;

/* 32 */
struct _RTL_CRITICAL_SECTION_DEBUG
{
  WORD Type;
  WORD CreatorBackTraceIndex;
  struct _RTL_CRITICAL_SECTION*CriticalSection;
  LIST_ENTRY ProcessLocksList;
  DWORD EntryCount;
  DWORD ContentionCount;
  DWORD Spare[2];
};

typedef struct _RTL_CRITICAL_SECTION_DEBUG _RTL_CRITICAL_SECTION_DEBUG;


/* 38 */
typedef unsigned __int32 UINT_PTR;

/* 37 */
typedef UINT_PTR SIZE_T;

/* 35 */
struct _MEMORY_BASIC_INFORMATION
{
  PVOID BaseAddress;
  PVOID AllocationBase;
  DWORD AllocationProtect;
  SIZE_T RegionSize;
  DWORD State;
  DWORD Protect;
  DWORD Type;
};

typedef struct _MEMORY_BASIC_INFORMATION _MEMORY_BASIC_INFORMATION;


/* 41 */
struct _FILETIME
{
  DWORD dwLowDateTime;
  DWORD dwHighDateTime;
};

typedef struct _FILETIME _FILETIME;


/* 40 */
typedef _FILETIME FILETIME;

/* 39 */
struct _WIN32_FIND_DATAA
{
  DWORD dwFileAttributes;
  FILETIME ftCreationTime;
  FILETIME ftLastAccessTime;
  FILETIME ftLastWriteTime;
  DWORD nFileSizeHigh;
  DWORD nFileSizeLow;
  DWORD dwReserved0;
  DWORD dwReserved1;
  CHAR cFileName[260];
  CHAR cAlternateFileName[14];
};

typedef struct _WIN32_FIND_DATAA _WIN32_FIND_DATAA;


/* 42 */
typedef struct tagWNDCLASSEXA WNDCLASSEXA;

/* 45 */
typedef LONG LRESULT;

/* 44 */
typedef LRESULT (__stdcall *WNDPROC)(HWND, UINT, WPARAM, LPARAM);

/* 46 */
typedef struct HINSTANCE__ *HINSTANCE;

/* 48 */
typedef struct HICON__ *HICON;

/* 50 */
typedef HICON HCURSOR;

/* 51 */
typedef struct HBRUSH__ *HBRUSH;

/* 53 */
typedef const CHAR *LPCSTR;

/* 43 */
struct tagWNDCLASSEXA
{
  UINT cbSize;
  UINT style;
  WNDPROC lpfnWndProc;
  int cbClsExtra;
  int cbWndExtra;
  HINSTANCE hInstance;
  HICON hIcon;
  HCURSOR hCursor;
  HBRUSH hbrBackground;
  LPCSTR lpszMenuName;
  LPCSTR lpszClassName;
  HICON hIconSm;
};

typedef struct tagWNDCLASSEXA tagWNDCLASSEXA;


/* 47 */
struct HINSTANCE__
{
  int unused;
};

typedef struct HINSTANCE__ HINSTANCE__;


/* 49 */
struct HICON__
{
  int unused;
};

typedef struct HICON__ HICON__;


/* 52 */
struct HBRUSH__
{
  int unused;
};

typedef struct HBRUSH__ HBRUSH__;


/* 54 */
typedef tagMSG MSG;

/* 55 */
struct _SYSTEMTIME
{
  WORD wYear;
  WORD wMonth;
  WORD wDayOfWeek;
  WORD wDay;
  WORD wHour;
  WORD wMinute;
  WORD wSecond;
  WORD wMilliseconds;
};

typedef struct _SYSTEMTIME _SYSTEMTIME;


/* 56 */
struct tagPALETTEENTRY
{
  BYTE peRed;
  BYTE peGreen;
  BYTE peBlue;
  BYTE peFlags;
};

typedef struct tagPALETTEENTRY tagPALETTEENTRY;


/* 57 */
struct _OFSTRUCT
{
  BYTE cBytes;
  BYTE fFixedDisk;
  WORD nErrCode;
  WORD Reserved1;
  WORD Reserved2;
  CHAR szPathName[128];
};

typedef struct _OFSTRUCT _OFSTRUCT;


/* 58 */
struct _OSVERSIONINFOA
{
  DWORD dwOSVersionInfoSize;
  DWORD dwMajorVersion;
  DWORD dwMinorVersion;
  DWORD dwBuildNumber;
  DWORD dwPlatformId;
  CHAR szCSDVersion[128];
};

typedef struct _OSVERSIONINFOA _OSVERSIONINFOA;


/* 61 */
typedef unsigned __int16 wchar_t;

/* 60 */
typedef wchar_t WCHAR;

/* 62 */
typedef _SYSTEMTIME SYSTEMTIME;

/* 59 */
struct _TIME_ZONE_INFORMATION
{
  LONG Bias;
  WCHAR StandardName[32];
  SYSTEMTIME StandardDate;
  LONG StandardBias;
  WCHAR DaylightName[32];
  SYSTEMTIME DaylightDate;
  LONG DaylightBias;
};

typedef struct _TIME_ZONE_INFORMATION _TIME_ZONE_INFORMATION;


/* 63 */
struct _cpinfo
{
  UINT MaxCharSize;
  BYTE DefaultChar[2];
  BYTE LeadByte[12];
};

typedef struct _cpinfo _cpinfo;


/* 65 */
typedef int BOOL;

/* 64 */
struct _SECURITY_ATTRIBUTES
{
  DWORD nLength;
  LPVOID lpSecurityDescriptor;
  BOOL bInheritHandle;
};

typedef struct _SECURITY_ATTRIBUTES _SECURITY_ATTRIBUTES;


/* 67 */
typedef __int32 time_t;

/* 68 */
typedef unsigned __int32 _fsize_t;

/* 66 */

struct _finddata_t
{
  unsigned int attrib;
  time_t time_create;
  time_t time_access;
  time_t time_write;
  _fsize_t size;
  char name[260];
};

typedef struct _finddata_t _finddata_t;



/* 69 */
typedef struct _iobuf FILE;

/* 70 */

struct _iobuf
{
  char *_ptr;
  int _cnt;
  char *_base;
  int _flag;
  int _file;
  int _charbuf;
  int _bufsiz;
  char *_tmpfname;
};

typedef struct _iobuf _iobuf;



/* 71 */
struct type_info;

/* 72 */
enum MACRO_FORMAT_MESSAGE
{
  FORMAT_MESSAGE_ALLOCATE_BUFFER = 0x100,
  FORMAT_MESSAGE_IGNORE_INSERTS = 0x200,
  FORMAT_MESSAGE_FROM_STRING = 0x400,
  FORMAT_MESSAGE_FROM_HMODULE = 0x800,
  FORMAT_MESSAGE_FROM_SYSTEM = 0x1000,
  FORMAT_MESSAGE_ARGUMENT_ARRAY = 0x2000,
  FORMAT_MESSAGE_MAX_WIDTH_MASK = 0xFF,
};

typedef enum MACRO_FORMAT_MESSAGE MACRO_FORMAT_MESSAGE;


/* 73 */
enum MACRO_LOCALE
{
  LOCALE_NAME_MAX_LENGTH = 85,
  LANG_SYSTEM_DEFAULT = 2048,
  LANG_USER_DEFAULT = 1024,
  LOCALE_SYSTEM_DEFAULT = 2048,
  LOCALE_USER_DEFAULT = 1024,
  LOCALE_CUSTOM_DEFAULT = 3072,
  LOCALE_CUSTOM_UNSPECIFIED = 4096,
  LOCALE_CUSTOM_UI_DEFAULT = 5120,
  LOCALE_NEUTRAL = 0,
  LOCALE_INVARIANT = 127,
};

typedef enum MACRO_LOCALE MACRO_LOCALE;


/* 74 */
typedef signed char int8_t;

/* 75 */
typedef __int16 int16_t;

/* 76 */
typedef int int32_t;

/* 77 */
typedef unsigned __int8 uint8_t;

/* 78 */
typedef unsigned __int16 uint16_t;

/* 79 */
typedef unsigned int uint32_t;

/* 80 */
typedef unsigned __int64 uint64_t;

/* 81 */
typedef char int8;

/* 82 */
typedef __int16 int16;

/* 83 */
typedef int int32;

/* 84 */
typedef __int64 int64;

/* 85 */
typedef unsigned __int8 uint8;

/* 86 */
typedef unsigned __int16 uint16;

/* 87 */
typedef unsigned int uint32;

/* 88 */
typedef unsigned __int64 uint64;

/* 89 */
enum MACRO_FALSE
{
  FALSE = 0,
  TRUE = 1,
};

typedef enum MACRO_FALSE MACRO_FALSE;


/* 91 */
enum MACRO_SW
{
  SW_HIDE = 0,
  SW_SHOWNORMAL = 1,
};

typedef enum MACRO_SW MACRO_SW;


/* 92 */
enum MACRO_NULL
{
  NULL = 0,
};

typedef enum MACRO_NULL MACRO_NULL;


/* 93 */
enum MACRO_DRIVERVERSION
{
  DRIVERVERSION = 0,
  TECHNOLOGY = 2,
  HORZSIZE = 4,
  VERTSIZE = 6,
  HORZRES = 8,
  VERTRES = 10,
  BITSPIXEL = 12,
  PLANES = 14,
  NUMBRUSHES = 16,
  NUMPENS = 18,
  NUMMARKERS = 20,
  NUMFONTS = 22,
  NUMCOLORS = 24,
  PDEVICESIZE = 26,
  CURVECAPS = 28,
  LINECAPS = 30,
  POLYGONALCAPS = 32,
  TEXTCAPS = 34,
  CLIPCAPS = 36,
  RASTERCAPS = 38,
  ASPECTX = 40,
  ASPECTY = 42,
  ASPECTXY = 44,
  LOGPIXELSX = 88,
  LOGPIXELSY = 90,
  SIZEPALETTE = 104,
  NUMRESERVED = 106,
  COLORRES = 108,
  PHYSICALWIDTH = 110,
  PHYSICALHEIGHT = 111,
  PHYSICALOFFSETX = 112,
  PHYSICALOFFSETY = 113,
  SCALINGFACTORX = 114,
  SCALINGFACTORY = 115,
  VREFRESH = 116,
  DESKTOPVERTRES = 117,
  DESKTOPHORZRES = 118,
  BLTALIGNMENT = 119,
  SHADEBLENDCAPS = 120,
  COLORMGMTCAPS = 121,
};

typedef enum MACRO_DRIVERVERSION MACRO_DRIVERVERSION;


/* 94 */
enum MACRO_HWND_TOP
{
  HWND_TOP = 0,
  HWND_BOTTOM = 1,
  HWND_TOPMOST = -1,
};

typedef enum MACRO_HWND_TOP MACRO_HWND_TOP;


/* 95 */
typedef tagRECT RECT;

/* 96 */
enum MACRO_WM
{
  WM_NULL = 0x0,
  WM_CREATE = 0x1,
  WM_DESTROY = 0x2,
  WM_MOVE = 0x3,
  WM_SIZEWAIT = 0x4,
  WM_SIZE = 0x5,
  WM_ACTIVATE = 0x6,
  WM_SETFOCUS = 0x7,
  WM_KILLFOCUS = 0x8,
  WM_SETVISIBLE = 0x9,
  WM_ENABLE = 0xA,
  WM_SETREDRAW = 0xB,
  WM_SETTEXT = 0xC,
  WM_GETTEXT = 0xD,
  WM_GETTEXTLENGTH = 0xE,
  WM_PAINT = 0xF,
  WM_CLOSE = 0x10,
  WM_QUERYENDSESSION = 0x11,
  WM_QUIT = 0x12,
  WM_QUERYOPEN = 0x13,
  WM_ERASEBKGND = 0x14,
  WM_SYSCOLORCHANGE = 0x15,
  WM_ENDSESSION = 0x16,
  WM_SYSTEMERROR = 0x17,
  WM_SHOWWINDOW = 0x18,
  WM_CTLCOLOR = 0x19,
  WM_WININICHANGE = 0x1A,
  WM_DEVMODECHANGE = 0x1B,
  WM_ACTIVATEAPP = 0x1C,
  WM_FONTCHANGE = 0x1D,
  WM_TIMECHANGE = 0x1E,
  WM_CANCELMODE = 0x1F,
  WM_SETCURSOR = 0x20,
  WM_MOUSEACTIVATE = 0x21,
  WM_CHILDACTIVATE = 0x22,
  WM_QUEUESYNC = 0x23,
  WM_GETMINMAXINFO = 0x24,
  WM_LOGOFF = 0x25,
  WM_PAINTICON = 0x26,
  WM_ICONERASEBKGND = 0x27,
  WM_NEXTDLGCTL = 0x28,
  WM_ALTTABACTIVE = 0x29,
  WM_SPOOLERSTATUS = 0x2A,
  WM_DRAWITEM = 0x2B,
  WM_MEASUREITEM = 0x2C,
  WM_DELETEITEM = 0x2D,
  WM_VKEYTOITEM = 0x2E,
  WM_CHARTOITEM = 0x2F,
  WM_SETFONT = 0x30,
  WM_GETFONT = 0x31,
  WM_SETHOTKEY = 0x32,
  WM_GETHOTKEY = 0x33,
  WM_FILESYSCHANGE = 0x34,
  WM_ISACTIVEICON = 0x35,
  WM_QUERYPARKICON = 0x36,
  WM_QUERYDRAGICON = 0x37,
  WM_WINHELP = 0x38,
  WM_COMPAREITEM = 0x39,
  WM_FULLSCREEN = 0x3A,
  WM_CLIENTSHUTDOWN = 0x3B,
  WM_DDEMLEVENT = 0x3C,
  WM_GETOBJECT = 0x3D,
  MM_CALCSCROLL = 0x3F,
  WM_TESTING = 0x40,
  WM_COMPACTING = 0x41,
  WM_OTHERWINDOWCREATED = 0x42,
  WM_OTHERWINDOWDESTROYED = 0x43,
  WM_COMMNOTIFY = 0x44,
  WM_MEDIASTATUSCHANGE = 0x45,
  WM_WINDOWPOSCHANGING = 0x46,
  WM_WINDOWPOSCHANGED = 0x47,
  WM_POWER = 0x48,
  WM_COPYGLOBALDATA = 0x49,
  WM_COPYDATA = 0x4A,
  WM_CANCELJOURNAL = 0x4B,
  WM_LOGONNOTIFY = 0x4C,
  WM_KEYF1 = 0x4D,
  WM_NOTIFY = 0x4E,
  WM_ACCESS_WINDOW = 0x4F,
  WM_INPUTLANGCHANGEREQUEST = 0x50,
  WM_INPUTLANGCHANGE = 0x51,
  WM_TCARD = 0x52,
  WM_HELP = 0x53,
  WM_USERCHANGED = 0x54,
  WM_NOTIFYFORMAT = 0x55,
  WM_QM_ACTIVATE = 0x60,
  WM_HOOK_DO_CALLBACK = 0x61,
  WM_SYSCOPYDATA = 0x62,
  WM_FINALDESTROY = 0x70,
  WM_MEASUREITEM_CLIENTDATA = 0x71,
  WM_CONTEXTMENU = 0x7B,
  WM_STYLECHANGING = 0x7C,
  WM_STYLECHANGED = 0x7D,
  WM_DISPLAYCHANGE = 0x7E,
  WM_GETICON = 0x7F,
  WM_SETICON = 0x80,
  WM_NCCREATE = 0x81,
  WM_NCDESTROY = 0x82,
  WM_NCCALCSIZE = 0x83,
  WM_NCHITTEST = 0x84,
  WM_NCPAINT = 0x85,
  WM_NCACTIVATE = 0x86,
  WM_GETDLGCODE = 0x87,
  WM_SYNCPAINT = 0x88,
  WM_SYNCTASK = 0x89,
  WM_NCMOUSEMOVE = 0xA0,
  WM_NCLBUTTONDOWN = 0xA1,
  WM_NCLBUTTONUP = 0xA2,
  WM_NCLBUTTONDBLCLK = 0xA3,
  WM_NCRBUTTONDOWN = 0xA4,
  WM_NCRBUTTONUP = 0xA5,
  WM_NCRBUTTONDBLCLK = 0xA6,
  WM_NCMBUTTONDOWN = 0xA7,
  WM_NCMBUTTONUP = 0xA8,
  WM_NCMBUTTONDBLCLK = 0xA9,
  WM_NCXBUTTONDOWN = 0xAB,
  WM_NCXBUTTONUP = 0xAC,
  WM_NCXBUTTONDBLCLK = 0xAD,
  EM_GETSEL = 0xB0,
  EM_SETSEL = 0xB1,
  EM_GETRECT = 0xB2,
  EM_SETRECT = 0xB3,
  EM_SETRECTNP = 0xB4,
  EM_SCROLL = 0xB5,
  EM_LINESCROLL = 0xB6,
  EM_SCROLLCARET = 0xB7,
  EM_GETMODIFY = 0xB8,
  EM_SETMODIFY = 0xB9,
  EM_GETLINECOUNT = 0xBA,
  EM_LINEINDEX = 0xBB,
  EM_SETHANDLE = 0xBC,
  EM_GETHANDLE = 0xBD,
  EM_GETTHUMB = 0xBE,
  EM_LINELENGTH = 0xC1,
  EM_REPLACESEL = 0xC2,
  EM_SETFONT = 0xC3,
  EM_GETLINE = 0xC4,
  EM_SETLIMITTEXT = 0xC5,
  EM_CANUNDO = 0xC6,
  EM_UNDO = 0xC7,
  EM_FMTLINES = 0xC8,
  EM_LINEFROMCHAR = 0xC9,
  EM_SETWORDBREAK = 0xCA,
  EM_SETTABSTOPS = 0xCB,
  EM_SETPASSWORDCHAR = 0xCC,
  EM_EMPTYUNDOBUFFER = 0xCD,
  EM_GETFIRSTVISIBLELINE = 0xCE,
  EM_SETREADONLY = 0xCF,
  EM_SETWORDBREAKPROC = 0xD0,
  EM_GETWORDBREAKPROC = 0xD1,
  EM_GETPASSWORDCHAR = 0xD2,
  EM_SETMARGINS = 0xD3,
  EM_GETMARGINS = 0xD4,
  EM_POSFROMCHAR = 0xD5,
  EM_CHARFROMPOS = 0xD6,
  EM_SETIMESTATUS = 0xD8,
  EM_GETIMESTATUS = 0xD9,
  SBM_SETPOS = 0xE0,
  SBM_GETPOS = 0xE1,
  SBM_SETRANGE = 0xE2,
  SBM_GETRANGE = 0xE3,
  SBM_ENABLE_ARROWS = 0xE4,
  SBM_SETRANGEREDRAW = 0xE6,
  SBM_SETSCROLLINFO = 0xE9,
  SBM_GETSCROLLINFO = 0xEA,
  SBM_GETSCROLLBARINFO = 0xEB,
  BM_GETCHECK = 0xF0,
  BM_SETCHECK = 0xF1,
  BM_GETSTATE = 0xF2,
  BM_SETSTATE = 0xF3,
  BM_SETSTYLE = 0xF4,
  BM_CLICK = 0xF5,
  BM_GETIMAGE = 0xF6,
  BM_SETIMAGE = 0xF7,
  BM_SETDONTCLICK = 0xF8,
  WM_INPUT = 0xFF,
  WM_KEYFIRST = 0x100,
  WM_KEYUP = 0x101,
  WM_CHAR = 0x102,
  WM_DEADCHAR = 0x103,
  WM_SYSKEYDOWN = 0x104,
  WM_SYSKEYUP = 0x105,
  WM_SYSCHAR = 0x106,
  WM_SYSDEADCHAR = 0x107,
  WM_YOMICHAR = 0x108,
  WM_UNICHAR = 0x109,
  WM_CONVERTREQUEST = 0x10A,
  WM_CONVERTRESULT = 0x10B,
  WM_IM_INFO = 0x10C,
  WM_IME_STARTCOMPOSITION = 0x10D,
  WM_IME_ENDCOMPOSITION = 0x10E,
  WM_IME_KEYLAST = 0x10F,
  WM_INITDIALOG = 0x110,
  WM_COMMAND = 0x111,
  WM_SYSCOMMAND = 0x112,
  WM_TIMER = 0x113,
  WM_HSCROLL = 0x114,
  WM_VSCROLL = 0x115,
  WM_INITMENU = 0x116,
  WM_INITMENUPOPUP = 0x117,
  WM_SYSTIMER = 0x118,
  WM_MENUSELECT = 0x11F,
  WM_MENUCHAR = 0x120,
  WM_ENTERIDLE = 0x121,
  WM_MENURBUTTONUP = 0x122,
  WM_MENUDRAG = 0x123,
  WM_MENUGETOBJECT = 0x124,
  WM_UNINITMENUPOPUP = 0x125,
  WM_MENUCOMMAND = 0x126,
  WM_CHANGEUISTATE = 0x127,
  WM_UPDATEUISTATE = 0x128,
  WM_QUERYUISTATE = 0x129,
  WM_LBTRACKPOINT = 0x131,
  WM_CTLCOLORMSGBOX = 0x132,
  WM_CTLCOLOREDIT = 0x133,
  WM_CTLCOLORLISTBOX = 0x134,
  WM_CTLCOLORBTN = 0x135,
  WM_CTLCOLORDLG = 0x136,
  WM_CTLCOLORSCROLLBAR = 0x137,
  WM_CTLCOLORSTATIC = 0x138,
  CB_GETEDITSEL = 0x140,
  CB_LIMITTEXT = 0x141,
  CB_SETEDITSEL = 0x142,
  CB_ADDSTRING = 0x143,
  CB_DELETESTRING = 0x144,
  CB_DIR = 0x145,
  CB_GETCOUNT = 0x146,
  CB_GETCURSEL = 0x147,
  CB_GETLBTEXT = 0x148,
  CB_GETLBTEXTLEN = 0x149,
  CB_INSERTSTRING = 0x14A,
  CB_RESETCONTENT = 0x14B,
  CB_FINDSTRING = 0x14C,
  CB_SELECTSTRING = 0x14D,
  CB_SETCURSEL = 0x14E,
  CB_SHOWDROPDOWN = 0x14F,
  CB_GETITEMDATA = 0x150,
  CB_SETITEMDATA = 0x151,
  CB_GETDROPPEDCONTROLRECT = 0x152,
  CB_SETITEMHEIGHT = 0x153,
  CB_GETITEMHEIGHT = 0x154,
  CB_SETEXTENDEDUI = 0x155,
  CB_GETEXTENDEDUI = 0x156,
  CB_GETDROPPEDSTATE = 0x157,
  CB_FINDSTRINGEXACT = 0x158,
  CB_SETLOCALE = 0x159,
  CB_GETLOCALE = 0x15A,
  CB_GETTOPINDEX = 0x15B,
  CB_SETTOPINDEX = 0x15C,
  CB_GETHORIZONTALEXTENT = 0x15D,
  CB_SETHORIZONTALEXTENT = 0x15E,
  CB_GETDROPPEDWIDTH = 0x15F,
  CB_SETDROPPEDWIDTH = 0x160,
  CB_INITSTORAGE = 0x161,
  CB_GETCOMBOBOXINFO = 0x164,
  STM_SETICON = 0x170,
  STM_GETICON = 0x171,
  STM_SETIMAGE = 0x172,
  STM_GETIMAGE = 0x173,
  LB_ADDSTRING = 0x180,
  LB_INSERTSTRING = 0x181,
  LB_DELETESTRING = 0x182,
  LB_SELITEMRANGEEX = 0x183,
  LB_RESETCONTENT = 0x184,
  LB_SETSEL = 0x185,
  LB_SETCURSEL = 0x186,
  LB_GETSEL = 0x187,
  LB_GETCURSEL = 0x188,
  LB_GETTEXT = 0x189,
  LB_GETTEXTLEN = 0x18A,
  LB_GETCOUNT = 0x18B,
  LB_SELECTSTRING = 0x18C,
  LB_DIR = 0x18D,
  LB_GETTOPINDEX = 0x18E,
  LB_FINDSTRING = 0x18F,
  LB_GETSELCOUNT = 0x190,
  LB_GETSELITEMS = 0x191,
  LB_SETTABSTOPS = 0x192,
  LB_GETHORIZONTALEXTENT = 0x193,
  LB_SETHORIZONTALEXTENT = 0x194,
  LB_SETCOLUMNWIDTH = 0x195,
  LB_ADDFILE = 0x196,
  LB_SETTOPINDEX = 0x197,
  LB_GETITEMRECT = 0x198,
  LB_GETITEMDATA = 0x199,
  LB_SETITEMDATA = 0x19A,
  LB_SELITEMRANGE = 0x19B,
  LB_SETANCHORINDEX = 0x19C,
  LB_GETANCHORINDEX = 0x19D,
  LB_SETCARETINDEX = 0x19E,
  LB_GETCARETINDEX = 0x19F,
  LB_SETITEMHEIGHT = 0x1A0,
  LB_GETITEMHEIGHT = 0x1A1,
  LB_FINDSTRINGEXACT = 0x1A2,
  LBCB_CARETON = 0x1A3,
  LBCB_CARETOFF = 0x1A4,
  LB_SETLOCALE = 0x1A5,
  LB_GETLOCALE = 0x1A6,
  LB_SETCOUNT = 0x1A7,
  LB_INITSTORAGE = 0x1A8,
  LB_ITEMFROMPOINT = 0x1A9,
  LB_INSERTSTRINGUPPER = 0x1AA,
  LB_INSERTSTRINGLOWER = 0x1AB,
  LB_ADDSTRINGUPPER = 0x1AC,
  LB_ADDSTRINGLOWER = 0x1AD,
  LB_GETLISTBOXINFO = 0x1B2,
  MN_SETHMENU = 0x1E0,
  MN_GETHMENU = 0x1E1,
  MN_SIZEWINDOW = 0x1E2,
  MN_OPENHIERARCHY = 0x1E3,
  MN_CLOSEHIERARCHY = 0x1E4,
  MN_SELECTITEM = 0x1E5,
  MN_CANCELMENUS = 0x1E6,
  MN_SELECTFIRSTVALIDITEM = 0x1E7,
  MN_GETPPOPUPMENU = 0x1EA,
  MN_FINDMENUWINDOWFROMPOINT = 0x1EB,
  MN_SHOWPOPUPWINDOW = 0x1EC,
  MN_BUTTONDOWN = 0x1ED,
  MN_MOUSEMOVE = 0x1EE,
  MN_BUTTONUP = 0x1EF,
  MN_SETTIMERTOOPENHIERARCHY = 0x1F0,
  MN_DBLCLK = 0x1F1,
  WM_MOUSEMOVE = 0x200,
  WM_LBUTTONDOWN = 0x201,
  WM_LBUTTONUP = 0x202,
  WM_LBUTTONDBLCLK = 0x203,
  WM_RBUTTONDOWN = 0x204,
  WM_RBUTTONUP = 0x205,
  WM_RBUTTONDBLCLK = 0x206,
  WM_MBUTTONDOWN = 0x207,
  WM_MBUTTONUP = 0x208,
  WM_MBUTTONDBLCLK = 0x209,
  WM_MOUSEWHEEL = 0x20A,
  WM_XBUTTONDOWN = 0x20B,
  WM_XBUTTONUP = 0x20C,
  WM_XBUTTONDBLCLK = 0x20D,
  WM_MOUSEHWHEEL = 0x20E,
  WM_PARENTNOTIFY = 0x210,
  WM_ENTERMENULOOP = 0x211,
  WM_EXITMENULOOP = 0x212,
  WM_NEXTMENU = 0x213,
  WM_SIZING = 0x214,
  WM_CAPTURECHANGED = 0x215,
  WM_MOVING = 0x216,
  WM_POWERBROADCAST = 0x218,
  WM_DEVICECHANGE = 0x219,
  WM_MDICREATE = 0x220,
  WM_MDIDESTROY = 0x221,
  WM_MDIACTIVATE = 0x222,
  WM_MDIRESTORE = 0x223,
  WM_MDINEXT = 0x224,
  WM_MDIMAXIMIZE = 0x225,
  WM_MDITILE = 0x226,
  WM_MDICASCADE = 0x227,
  WM_MDIICONARRANGE = 0x228,
  WM_MDIGETACTIVE = 0x229,
  WM_DROPOBJECT = 0x22A,
  WM_QUERYDROPOBJECT = 0x22B,
  WM_BEGINDRAG = 0x22C,
  WM_DRAGLOOP = 0x22D,
  WM_DRAGSELECT = 0x22E,
  WM_DRAGMOVE = 0x22F,
  WM_MDISETMENU = 0x230,
  WM_ENTERSIZEMOVE = 0x231,
  WM_EXITSIZEMOVE = 0x232,
  WM_DROPFILES = 0x233,
  WM_MDIREFRESHMENU = 0x234,
  WM_TOUCH = 0x240,
  WM_KANJIFIRST = 0x280,
  WM_IME_SETCONTEXT = 0x281,
  WM_IME_NOTIFY = 0x282,
  WM_IME_CONTROL = 0x283,
  WM_IME_COMPOSITIONFULL = 0x284,
  WM_IME_SELECT = 0x285,
  WM_IME_CHAR = 0x286,
  WM_IME_SYSTEM = 0x287,
  WM_IME_REQUEST = 0x288,
  WM_IME_KEYDOWN = 0x290,
  WM_IME_KEYUP = 0x291,
  WM_KANJILAST = 0x29F,
  WM_NCMOUSEHOVER = 0x2A0,
  WM_MOUSEHOVER = 0x2A1,
  WM_NCMOUSELEAVE = 0x2A2,
  WM_MOUSELEAVE = 0x2A3,
  WM_TRACKMOUSEEVENT_LAST = 0x2AF,
  WM_WTSSESSION_CHANGE = 0x2B1,
  WM_TABLET_FIRST = 0x2C0,
  WM_TABLET_LAST = 0x2DF,
  WM_CUT = 0x300,
  WM_COPY = 0x301,
  WM_PASTE = 0x302,
  WM_CLEAR = 0x303,
  WM_UNDO = 0x304,
  WM_RENDERFORMAT = 0x305,
  WM_RENDERALLFORMATS = 0x306,
  WM_DESTROYCLIPBOARD = 0x307,
  WM_DRAWCLIPBOARD = 0x308,
  WM_PAINTCLIPBOARD = 0x309,
  WM_VSCROLLCLIPBOARD = 0x30A,
  WM_SIZECLIPBOARD = 0x30B,
  WM_ASKCBFORMATNAME = 0x30C,
  WM_CHANGECBCHAIN = 0x30D,
  WM_HSCROLLCLIPBOARD = 0x30E,
  WM_QUERYNEWPALETTE = 0x30F,
  WM_PALETTEISCHANGING = 0x310,
  WM_PALETTECHANGED = 0x311,
  WM_HOTKEY = 0x312,
  WM_SYSMENU = 0x313,
  WM_HOOKMSG = 0x314,
  WM_EXITPROCESS = 0x315,
  WM_WAKETHREAD = 0x316,
  WM_PRINT = 0x317,
  WM_PRINTCLIENT = 0x318,
  WM_APPCOMMAND = 0x319,
  WM_THEMECHANGED = 0x31A,
  WM_CLIPBOARDUPDATE = 0x31D,
  WM_DWMCOMPOSITIONCHANGED = 0x31E,
  WM_DWMNCRENDERINGCHANGED = 0x31F,
  WM_DWMCOLORIZATIONCOLORCHANGED = 0x320,
  WM_DWMWINDOWMAXIMIZEDCHANGE = 0x321,
  WM_DWMSENDICONICTHUMBNAIL = 0x323,
  WM_DWMSENDICONICLIVEPREVIEWBITMAP = 0x326,
  WM_GETTITLEBARINFOEX = 0x33F,
  WM_HANDHELDFIRST = 0x358,
  WM_HANDHELDLAST = 0x35F,
  WM_AFXFIRST = 0x360,
  WM_AFXLAST = 0x37F,
  WM_PENWINFIRST = 0x380,
  WM_PENWINLAST = 0x38F,
  WM_INTERNAL_COALESCE_FIRST = 0x390,
  WM_COALESCE_LAST = 0x39F,
  WM_MM_RESERVED_FIRST = 0x3A0,
  WM_MM_RESERVED_LAST = 0x3DF,
  WM_DDE_INITIATE = 0x3E0,
  WM_DDE_TERMINATE = 0x3E1,
  WM_DDE_ADVISE = 0x3E2,
  WM_DDE_UNADVISE = 0x3E3,
  WM_DDE_ACK = 0x3E4,
  WM_DDE_DATA = 0x3E5,
  WM_DDE_REQUEST = 0x3E6,
  WM_DDE_POKE = 0x3E7,
  WM_DDE_EXECUTE = 0x3E8,
  WM_DBNOTIFICATION = 0x3FD,
  WM_NETCONNECT = 0x3FE,
  WM_HIBERNATE = 0x3FF,
  WM_USER = 0x400,
  WM_APP = 0x8000,
};

typedef enum MACRO_WM MACRO_WM;


/* 97 */
enum template_id
{
  TEMPLATE_ID_DX_INIT_ERROR = 104,
  TEMPLATE_ID_OUT_OF_MEMORY_ERROR = 105,
  TEMPLATE_ID_FILE_NOT_FOUND_ERROR = 106,
  TEMPLATE_ID_DDRAW_DLL_NOT_FOUND_ERROR = 107,
  TEMPLATE_ID_DSOUND_DLL_NOT_FOUND_ERROR = 108,
  TEMPLATE_ID_DISK_SPACE_ERROR = 110,
  TEMPLATE_ID_SWITCH_VIDEO_MODE_ERROR = 111,
  TEMPLATE_ID_INSERT_CD_ERROR = 112,
  TEMPLATE_ID_RESTRICTED_USER_ERROR = 113,
  TEMPLATE_ID_READ_ONLY_DIRECTORY_ERROR = 114,
};

typedef enum template_id template_id;


/* 99 */
union __m64
{
  unsigned __int64 m64_u64;
  float m64_f32[2];
  __int8 m64_i8[8];
  __int16 m64_i16[4];
  __int32 m64_i32[2];
  __int64 m64_i64;
  unsigned __int8 m64_u8[8];
  unsigned __int16 m64_u16[4];
  unsigned __int32 m64_u32[2];
};

/* 100 */
union __m128
{
  float m128_f32[4];
  unsigned __int64 m128_u64[2];
  __int8 m128_i8[16];
  __int16 m128_i16[8];
  __int32 m128_i32[4];
  __int64 m128_i64[2];
  unsigned __int8 m128_u8[16];
  unsigned __int16 m128_u16[8];
  unsigned __int32 m128_u32[4];
};

/* 101 */
struct __m128d
{
  double m128d_f64[2];
};

typedef struct __m128d __m128d;


/* 102 */
union __m128i
{
  __int8 m128i_i8[16];
  __int16 m128i_i16[8];
  __int32 m128i_i32[4];
  __int64 m128i_i64[2];
  unsigned __int8 m128i_u8[16];
  unsigned __int16 m128i_u16[8];
  unsigned __int32 m128i_u32[4];
  unsigned __int64 m128i_u64[2];
};

/* 106 */
struct _GUID
{
  unsigned __int32 Data1;
  unsigned __int16 Data2;
  unsigned __int16 Data3;
  unsigned __int8 Data4[8];
};

typedef struct _GUID _GUID;


/* 107 */
typedef __int32 HRESULT;

/* 108 */
typedef unsigned __int32 ULONG;

/* 109 */
typedef DWORD *LPDWORD;

/* 110 */
typedef tagPALETTEENTRY *LPPALETTEENTRY;

/* 111 */
struct IDirectDrawVtbl;

typedef struct IDirectDrawVtbl *LPDIRECTDRAW;

/* 115 */
typedef tagPALETTEENTRY PALETTEENTRY;

/* 117 */
typedef struct _EXCEPTION_RECORD EXCEPTION_RECORD;

/* 118 */
struct _EXCEPTION_RECORD
{
  DWORD ExceptionCode;
  DWORD ExceptionFlags;
  struct _EXCEPTION_RECORD *ExceptionRecord;
  PVOID ExceptionAddress;
  DWORD NumberParameters;
  UINT_PTR ExceptionInformation[15];
};

typedef struct _EXCEPTION_RECORD _EXCEPTION_RECORD;


/* 121 */
typedef EXCEPTION_RECORD *PEXCEPTION_RECORD;

/* 123 */
typedef struct _CONTEXT CONTEXT;

/* 122 */
typedef CONTEXT *PCONTEXT;

/* 120 */
struct _EXCEPTION_POINTERS
{
  PEXCEPTION_RECORD ExceptionRecord;
  PCONTEXT ContextRecord;
};

typedef struct _EXCEPTION_POINTERS _EXCEPTION_POINTERS;


/* 126 */
struct _FLOATING_SAVE_AREA
{
  DWORD ControlWord;
  DWORD StatusWord;
  DWORD TagWord;
  DWORD ErrorOffset;
  DWORD ErrorSelector;
  DWORD DataOffset;
  DWORD DataSelector;
  BYTE RegisterArea[80];
  DWORD Cr0NpxState;
};

typedef struct _FLOATING_SAVE_AREA _FLOATING_SAVE_AREA;


/* 125 */
typedef _FLOATING_SAVE_AREA FLOATING_SAVE_AREA;

/* 124 */
struct _CONTEXT
{
  DWORD ContextFlags;
  DWORD Dr0;
  DWORD Dr1;
  DWORD Dr2;
  DWORD Dr3;
  DWORD Dr6;
  DWORD Dr7;
  FLOATING_SAVE_AREA FloatSave;
  DWORD SegGs;
  DWORD SegFs;
  DWORD SegEs;
  DWORD SegDs;
  DWORD Edi;
  DWORD Esi;
  DWORD Ebx;
  DWORD Edx;
  DWORD Ecx;
  DWORD Eax;
  DWORD Ebp;
  DWORD Eip;
  DWORD SegCs;
  DWORD EFlags;
  DWORD Esp;
  DWORD SegSs;
  BYTE ExtendedRegisters[512];
};

typedef struct _CONTEXT _CONTEXT;


/* 129 */
typedef DWORD LCID;

/* 221 */
typedef WCHAR *LPWSTR;

typedef WCHAR *LPCWSTR;

/* 135 */
typedef LONG DISPID;

/* 184 */
typedef struct tagDISPPARAMS DISPPARAMS;

/* 165 */
typedef struct tagVARIANT VARIANT;

/* 186 */
typedef struct tagEXCEPINFO EXCEPINFO;

/* 137 */
typedef WCHAR OLECHAR;

/* 179 */
typedef OLECHAR *BSTR;

/* 222 */
typedef BSTR *PBSTR;

/* 223 */
typedef BOOL *PBOOL;

/* 128 */
struct MenuItemVtbl
{
  HRESULT (__stdcall *QueryInterface)(struct MenuItemVtbl *This, const IID *const riid, void **ppvObject);
  ULONG (__stdcall *AddRef)(struct MenuItemVtbl *This);
  ULONG (__stdcall *Release)(struct MenuItemVtbl *This);
  HRESULT (__stdcall *GetTypeInfoCount)(struct MenuItemVtbl *This, UINT *pctinfo);
  HRESULT (__stdcall *GetTypeInfo)(struct MenuItemVtbl *This, UINT iTInfo, LCID lcid, struct ITypeInfo **ppTInfo);
  HRESULT (__stdcall *GetIDsOfNames)(struct MenuItemVtbl *This, const IID *const riid, LPWSTR *rgszNames, UINT cNames, LCID lcid, DISPID *rgDispId);
  HRESULT (__stdcall *Invoke)(struct MenuItemVtbl *This, DISPID dispIdMember, const IID *const riid, LCID lcid, WORD wFlags, DISPPARAMS *pDispParams, VARIANT *pVarResult, EXCEPINFO *pExcepInfo, UINT *puArgErr);
  HRESULT (__stdcall *get_DisplayName)(struct MenuItemVtbl *This, PBSTR DisplayName);
  HRESULT (__stdcall *get_LanguageIndependentName)(struct MenuItemVtbl *This, PBSTR LanguageIndependentName);
  HRESULT (__stdcall *get_Path)(struct MenuItemVtbl *This, PBSTR Path);
  HRESULT (__stdcall *get_LanguageIndependentPath)(struct MenuItemVtbl *This, PBSTR LanguageIndependentPath);
  HRESULT (__stdcall *Execute)(struct MenuItemVtbl *This);
  HRESULT (__stdcall *get_Enabled)(struct MenuItemVtbl *This, PBOOL Enabled);
};

typedef struct MenuItemVtbl MenuItemVtbl;


/* 130 */

struct ITypeInfo
{
  struct ITypeInfoVtbl *lpVtbl;
};

typedef struct ITypeInfo ITypeInfo;



/* 132 */
typedef struct tagTYPEATTR TYPEATTR;

/* 154 */
typedef struct tagFUNCDESC FUNCDESC;

/* 210 */
typedef struct tagVARDESC VARDESC;

/* 134 */
typedef DISPID MEMBERID;

/* 143 */
typedef DWORD HREFTYPE;

/* 192 */
typedef int INT;

/* 136 */
typedef OLECHAR *LPOLESTR;

/* 207 */
enum tagINVOKEKIND
{
  INVOKE_FUNC = 0x1,
  INVOKE_PROPERTYGET = 0x2,
  INVOKE_PROPERTYPUT = 0x4,
  INVOKE_PROPERTYPUTREF = 0x8,
};

typedef enum tagINVOKEKIND tagINVOKEKIND;


/* 206 */
typedef tagINVOKEKIND INVOKEKIND;

/* 131 */

struct ITypeInfoVtbl
{
  HRESULT (__stdcall *QueryInterface)(ITypeInfo *This, const IID *const riid, void **ppvObject);
  ULONG (__stdcall *AddRef)(ITypeInfo *This);
  ULONG (__stdcall *Release)(ITypeInfo *This);
  HRESULT (__stdcall *GetTypeAttr)(ITypeInfo *This, TYPEATTR **ppTypeAttr);
  HRESULT (__stdcall *GetTypeComp)(ITypeInfo *This, struct ITypeComp **ppTComp);
  HRESULT (__stdcall *GetFuncDesc)(ITypeInfo *This, UINT index, FUNCDESC **ppFuncDesc);
  HRESULT (__stdcall *GetVarDesc)(ITypeInfo *This, UINT index, VARDESC **ppVarDesc);
  HRESULT (__stdcall *GetNames)(ITypeInfo *This, MEMBERID memid, BSTR *rgBstrNames, UINT cMaxNames, UINT *pcNames);
  HRESULT (__stdcall *GetRefTypeOfImplType)(ITypeInfo *This, UINT index, HREFTYPE *pRefType);
  HRESULT (__stdcall *GetImplTypeFlags)(ITypeInfo *This, UINT index, INT *pImplTypeFlags);
  HRESULT (__stdcall *GetIDsOfNames)(ITypeInfo *This, LPOLESTR *rgszNames, UINT cNames, MEMBERID *pMemId);
  HRESULT (__stdcall *Invoke)(ITypeInfo *This, PVOID pvInstance, MEMBERID memid, WORD wFlags, DISPPARAMS *pDispParams, VARIANT *pVarResult, EXCEPINFO *pExcepInfo, UINT *puArgErr);
  HRESULT (__stdcall *GetDocumentation)(ITypeInfo *This, MEMBERID memid, BSTR *pBstrName, BSTR *pBstrDocString, DWORD *pdwHelpContext, BSTR *pBstrHelpFile);
  HRESULT (__stdcall *GetDllEntry)(ITypeInfo *This, MEMBERID memid, INVOKEKIND invKind, BSTR *pBstrDllName, BSTR *pBstrName, WORD *pwOrdinal);
  HRESULT (__stdcall *GetRefTypeInfo)(ITypeInfo *This, HREFTYPE hRefType, ITypeInfo **ppTInfo);
  HRESULT (__stdcall *AddressOfMember)(ITypeInfo *This, MEMBERID memid, INVOKEKIND invKind, PVOID *ppv);
  HRESULT (__stdcall *CreateInstance)(ITypeInfo *This, struct IUnknown *pUnkOuter, const IID *const riid, PVOID *ppvObj);
  HRESULT (__stdcall *GetMops)(ITypeInfo *This, MEMBERID memid, BSTR *pBstrMops);
  HRESULT (__stdcall *GetContainingTypeLib)(ITypeInfo *This, struct ITypeLib **ppTLib, UINT *pIndex);
  void (__stdcall *ReleaseTypeAttr)(ITypeInfo *This, TYPEATTR *pTypeAttr);
  void (__stdcall *ReleaseFuncDesc)(ITypeInfo *This, FUNCDESC *pFuncDesc);
  void (__stdcall *ReleaseVarDesc)(ITypeInfo *This, VARDESC *pVarDesc);
};

typedef struct ITypeInfoVtbl ITypeInfoVtbl;



/* 139 */
enum tagTYPEKIND
{
  TKIND_ENUM = 0x0,
  TKIND_RECORD = 0x1,
  TKIND_MODULE = 0x2,
  TKIND_INTERFACE = 0x3,
  TKIND_DISPATCH = 0x4,
  TKIND_COCLASS = 0x5,
  TKIND_ALIAS = 0x6,
  TKIND_UNION = 0x7,
  TKIND_MAX = 0x8,
};

typedef enum tagTYPEKIND tagTYPEKIND;


/* 138 */
typedef tagTYPEKIND TYPEKIND;

/* 142 */


/* 144 */
typedef unsigned __int16 VARTYPE;

/* 141 */

struct tagTYPEDESC
{

  union
  {
    struct tagTYPEDESC *lptdesc;
    struct tagARRAYDESC*lpadesc;
    HREFTYPE hreftype;
  };

  VARTYPE vt;
};

typedef struct tagTYPEDESC tagTYPEDESC;



/* 140 */
typedef tagTYPEDESC TYPEDESC;

/* 147 */
typedef unsigned __int16 USHORT;

/* 146 */

struct tagIDLDESC
{
  ULONG dwReserved;
  USHORT wIDLFlags;
};

typedef struct tagIDLDESC tagIDLDESC;



/* 145 */
typedef tagIDLDESC IDLDESC;

/* 133 */

struct tagTYPEATTR
{
  _GUID guid;
  LCID lcid;
  DWORD dwReserved;
  MEMBERID memidConstructor;
  MEMBERID memidDestructor;
  LPOLESTR lpstrSchema;
  ULONG cbSizeInstance;
  TYPEKIND typekind;
  WORD cFuncs;
  WORD cVars;
  WORD cImplTypes;
  WORD cbSizeVft;
  WORD cbAlignment;
  WORD wTypeFlags;
  WORD wMajorVerNum;
  WORD wMinorVerNum;
  TYPEDESC tdescAlias;
  IDLDESC idldescType;
};

typedef struct tagTYPEATTR tagTYPEATTR;



/* 148 */

struct ITypeComp
{
  struct ITypeCompVtbl *lpVtbl;
};

typedef struct ITypeComp ITypeComp;



/* 151 */
enum tagDESCKIND
{
  DESCKIND_NONE = 0x0,
  DESCKIND_FUNCDESC = 0x1,
  DESCKIND_VARDESC = 0x2,
  DESCKIND_TYPECOMP = 0x3,
  DESCKIND_IMPLICITAPPOBJ = 0x4,
  DESCKIND_MAX = 0x5,
};

typedef enum tagDESCKIND tagDESCKIND;


/* 150 */
typedef tagDESCKIND DESCKIND;

/* 152 */
typedef union tagBINDPTR BINDPTR;

/* 149 */

struct ITypeCompVtbl
{
  HRESULT (__stdcall *QueryInterface)(ITypeComp *This, const IID *const riid, void **ppvObject);
  ULONG (__stdcall *AddRef)(ITypeComp *This);
  ULONG (__stdcall *Release)(ITypeComp *This);
  HRESULT (__stdcall *Bind)(ITypeComp *This, LPOLESTR szName, ULONG lHashVal, WORD wFlags, ITypeInfo **ppTInfo, DESCKIND *pDescKind, BINDPTR *pBindPtr);
  HRESULT (__stdcall *BindType)(ITypeComp *This, LPOLESTR szName, ULONG lHashVal, ITypeInfo **ppTInfo, ITypeComp **ppTComp);
};

typedef struct ITypeCompVtbl ITypeCompVtbl;



/* 153 */

union tagBINDPTR
{
  FUNCDESC *lpfuncdesc;
  VARDESC *lpvardesc;
  ITypeComp *lptcomp;
};


/* 156 */
typedef LONG SCODE;

/* 157 */
typedef struct tagELEMDESC ELEMDESC;

/* 205 */
enum tagFUNCKIND
{
  FUNC_VIRTUAL = 0x0,
  FUNC_PUREVIRTUAL = 0x1,
  FUNC_NONVIRTUAL = 0x2,
  FUNC_STATIC = 0x3,
  FUNC_DISPATCH = 0x4,
};

typedef enum tagFUNCKIND tagFUNCKIND;


/* 204 */
typedef tagFUNCKIND FUNCKIND;

/* 209 */
enum tagCALLCONV
{
  CC_FASTCALL = 0x0,
  CC_CDECL = 0x1,
  CC_MSCPASCAL = 0x2,
  CC_PASCAL = 0x2,
  CC_MACPASCAL = 0x3,
  CC_STDCALL = 0x4,
  CC_FPFASTCALL = 0x5,
  CC_SYSCALL = 0x6,
  CC_MPWCDECL = 0x7,
  CC_MPWPASCAL = 0x8,
  CC_MAX = 0x9,
};

typedef enum tagCALLCONV tagCALLCONV;


/* 208 */
typedef tagCALLCONV CALLCONV;

/* 170 */
typedef __int16 SHORT;

/* 162 */
typedef struct tagPARAMDESCEX *LPPARAMDESCEX;

/* 161 */

struct tagPARAMDESC
{
  LPPARAMDESCEX pparamdescex;
  USHORT wParamFlags;
};

typedef struct tagPARAMDESC tagPARAMDESC;



/* 160 */
typedef tagPARAMDESC PARAMDESC;

/* 159 */


/* 158 */

struct tagELEMDESC
{
  TYPEDESC tdesc;

  union
  {
    IDLDESC idldesc;
    PARAMDESC paramdesc;
  };

};

typedef struct tagELEMDESC tagELEMDESC;



/* 155 */

struct tagFUNCDESC
{
  MEMBERID memid;
  SCODE *lprgscode;
  ELEMDESC *lprgelemdescParam;
  FUNCKIND funckind;
  INVOKEKIND invkind;
  CALLCONV callconv;
  SHORT cParams;
  SHORT cParamsOpt;
  SHORT oVft;
  SHORT cScodes;
  ELEMDESC elemdescFunc;
  WORD wFuncFlags;
};

typedef struct tagFUNCDESC tagFUNCDESC;



/* 171 */
typedef float FLOAT;

/* 172 */
typedef double DOUBLE;

/* 173 */
typedef __int16 VARIANT_BOOL;

/* 176 */


/* 177 */
typedef __int64 LONGLONG;

/* 175 */

union tagCY
{

  struct
  {
    unsigned __int32 Lo;
    __int32 Hi;
  };

  LONGLONG int64;
};


/* 174 */
typedef union tagCY CY;

/* 178 */
typedef double DATE;

/* 188 */
typedef struct tagSAFEARRAY SAFEARRAY;

/* 193 */
typedef struct tagDEC DECIMAL;

/* 200 */


/* 169 */


/* 168 */


/* 196 */


/* 195 */


/* 198 */


/* 199 */
typedef unsigned __int64 ULONGLONG;

/* 197 */


/* 194 */

struct tagDEC
{
  USHORT wReserved;

  union
  {

    struct
    {
      BYTE scale;
      BYTE sign;
    };

    USHORT signscale;
  };

  ULONG Hi32;

  union
  {

    struct
    {
      ULONG Lo32;
      ULONG Mid32;
    };

    ULONGLONG Lo64;
  };

};

typedef struct tagDEC tagDEC;



/* 167 */


/* 166 */

struct tagVARIANT
{

  union
  {

    struct
    {
      VARTYPE vt;
      WORD wReserved1;
      WORD wReserved2;
      WORD wReserved3;

      union
      {
        LONG lVal;
        BYTE bVal;
        SHORT iVal;
        FLOAT fltVal;
        DOUBLE dblVal;
        VARIANT_BOOL boolVal;
        SCODE scode;
        CY cyVal;
        DATE date;
        BSTR bstrVal;
        struct IUnknown *punkVal;
        struct IDispatch *pdispVal;
        SAFEARRAY *parray;
        BYTE *pbVal;
        SHORT *piVal;
        LONG *plVal;
        FLOAT *pfltVal;
        DOUBLE *pdblVal;
        VARIANT_BOOL *pboolVal;
        SCODE *pscode;
        CY *pcyVal;
        DATE *pdate;
        BSTR *pbstrVal;
        struct IUnknown **ppunkVal;
        struct IDispatch **ppdispVal;
        SAFEARRAY **pparray;
        VARIANT *pvarVal;
        PVOID byref;
        CHAR cVal;
        USHORT uiVal;
        ULONG ulVal;
        INT intVal;
        UINT uintVal;
        DECIMAL *pdecVal;
        CHAR *pcVal;
        USHORT *puiVal;
        ULONG *pulVal;
        INT *pintVal;
        UINT *puintVal;

        struct
        {
          PVOID pvRecord;
          struct IRecordInfo *pRecInfo;
        };

      };

    };

    DECIMAL decVal;
  };

};

typedef struct tagVARIANT tagVARIANT;



/* 164 */
typedef VARIANT VARIANTARG;

/* 163 */

struct tagPARAMDESCEX
{
  ULONG cBytes;
  VARIANTARG varDefaultValue;
};

typedef struct tagPARAMDESCEX tagPARAMDESCEX;



/* 180 */

struct IUnknown
{
  struct IUnknownVtbl *lpVtbl;
};

typedef struct IUnknown IUnknown;



/* 181 */

struct IUnknownVtbl
{
  HRESULT (__stdcall *QueryInterface)(IUnknown *This, const IID *const riid, void **ppvObject);
  ULONG (__stdcall *AddRef)(IUnknown *This);
  ULONG (__stdcall *Release)(IUnknown *This);
};

typedef struct IUnknownVtbl IUnknownVtbl;



/* 182 */

struct IDispatch
{
  struct IDispatchVtbl *lpVtbl;
};

typedef struct IDispatch IDispatch;



/* 183 */

struct IDispatchVtbl
{
  HRESULT (__stdcall *QueryInterface)(IDispatch *This, const IID *const riid, void **ppvObject);
  ULONG (__stdcall *AddRef)(IDispatch *This);
  ULONG (__stdcall *Release)(IDispatch *This);
  HRESULT (__stdcall *GetTypeInfoCount)(IDispatch *This, UINT *pctinfo);
  HRESULT (__stdcall *GetTypeInfo)(IDispatch *This, UINT iTInfo, LCID lcid, ITypeInfo **ppTInfo);
  HRESULT (__stdcall *GetIDsOfNames)(IDispatch *This, const IID *const riid, LPOLESTR *rgszNames, UINT cNames, LCID lcid, DISPID *rgDispId);
  HRESULT (__stdcall *Invoke)(IDispatch *This, DISPID dispIdMember, const IID *const riid, LCID lcid, WORD wFlags, DISPPARAMS *pDispParams, VARIANT *pVarResult, EXCEPINFO *pExcepInfo, UINT *puArgErr);
};

typedef struct IDispatchVtbl IDispatchVtbl;



/* 185 */

struct tagDISPPARAMS
{
  VARIANTARG *rgvarg;
  DISPID *rgdispidNamedArgs;
  UINT cArgs;
  UINT cNamedArgs;
};

typedef struct tagDISPPARAMS tagDISPPARAMS;



/* 187 */

struct tagEXCEPINFO
{
  WORD wCode;
  WORD wReserved;
  BSTR bstrSource;
  BSTR bstrDescription;
  BSTR bstrHelpFile;
  DWORD dwHelpContext;
  PVOID pvReserved;
  HRESULT (__stdcall *pfnDeferredFillIn)(struct tagEXCEPINFO *);
  SCODE scode;
};

typedef struct tagEXCEPINFO tagEXCEPINFO;



/* 191 */

struct tagSAFEARRAYBOUND
{
  ULONG cElements;
  LONG lLbound;
};

typedef struct tagSAFEARRAYBOUND tagSAFEARRAYBOUND;



/* 190 */
typedef tagSAFEARRAYBOUND SAFEARRAYBOUND;

/* 189 */

struct tagSAFEARRAY
{
  USHORT cDims;
  USHORT fFeatures;
  ULONG cbElements;
  ULONG cLocks;
  PVOID pvData;
  SAFEARRAYBOUND rgsabound[1];
};

typedef struct tagSAFEARRAY tagSAFEARRAY;



/* 201 */

struct IRecordInfo
{
  struct IRecordInfoVtbl *lpVtbl;
};

typedef struct IRecordInfo IRecordInfo;



/* 203 */
typedef const OLECHAR *LPCOLESTR;

/* 202 */

struct IRecordInfoVtbl
{
  HRESULT (__stdcall *QueryInterface)(IRecordInfo *This, const IID *const riid, void **ppvObject);
  ULONG (__stdcall *AddRef)(IRecordInfo *This);
  ULONG (__stdcall *Release)(IRecordInfo *This);
  HRESULT (__stdcall *RecordInit)(IRecordInfo *This, PVOID pvNew);
  HRESULT (__stdcall *RecordClear)(IRecordInfo *This, PVOID pvExisting);
  HRESULT (__stdcall *RecordCopy)(IRecordInfo *This, PVOID pvExisting, PVOID pvNew);
  HRESULT (__stdcall *GetGuid)(IRecordInfo *This, _GUID *pguid);
  HRESULT (__stdcall *GetName)(IRecordInfo *This, BSTR *pbstrName);
  HRESULT (__stdcall *GetSize)(IRecordInfo *This, ULONG *pcbSize);
  HRESULT (__stdcall *GetTypeInfo)(IRecordInfo *This, ITypeInfo **ppTypeInfo);
  HRESULT (__stdcall *GetField)(IRecordInfo *This, PVOID pvData, LPCOLESTR szFieldName, VARIANT *pvarField);
  HRESULT (__stdcall *GetFieldNoCopy)(IRecordInfo *This, PVOID pvData, LPCOLESTR szFieldName, VARIANT *pvarField, PVOID *ppvDataCArray);
  HRESULT (__stdcall *PutField)(IRecordInfo *This, ULONG wFlags, PVOID pvData, LPCOLESTR szFieldName, VARIANT *pvarField);
  HRESULT (__stdcall *PutFieldNoCopy)(IRecordInfo *This, ULONG wFlags, PVOID pvData, LPCOLESTR szFieldName, VARIANT *pvarField);
  HRESULT (__stdcall *GetFieldNames)(IRecordInfo *This, ULONG *pcNames, BSTR *rgBstrNames);
  BOOL (__stdcall *IsMatchingType)(IRecordInfo *This, IRecordInfo *pRecordInfo);
  PVOID (__stdcall *RecordCreate)(IRecordInfo *This);
  HRESULT (__stdcall *RecordCreateCopy)(IRecordInfo *This, PVOID pvSource, PVOID *ppvDest);
  HRESULT (__stdcall *RecordDestroy)(IRecordInfo *This, PVOID pvRecord);
};

typedef struct IRecordInfoVtbl IRecordInfoVtbl;



/* 212 */


/* 214 */
enum tagVARKIND
{
  VAR_PERINSTANCE = 0x0,
  VAR_STATIC = 0x1,
  VAR_CONST = 0x2,
  VAR_DISPATCH = 0x3,
};

typedef enum tagVARKIND tagVARKIND;


/* 213 */
typedef tagVARKIND VARKIND;

/* 211 */

struct tagVARDESC
{
  MEMBERID memid;
  LPOLESTR lpstrSchema;

  union
  {
    ULONG oInst;
    VARIANT *lpvarValue;
  };

  ELEMDESC elemdescVar;
  WORD wVarFlags;
  VARKIND varkind;
};

typedef struct tagVARDESC tagVARDESC;



/* 215 */

struct ITypeLib
{
  struct ITypeLibVtbl *lpVtbl;
};

typedef struct ITypeLib ITypeLib;



/* 217 */
typedef struct tagTLIBATTR TLIBATTR;

/* 216 */

struct ITypeLibVtbl
{
  HRESULT (__stdcall *QueryInterface)(ITypeLib *This, const IID *const riid, void **ppvObject);
  ULONG (__stdcall *AddRef)(ITypeLib *This);
  ULONG (__stdcall *Release)(ITypeLib *This);
  UINT (__stdcall *GetTypeInfoCount)(ITypeLib *This);
  HRESULT (__stdcall *GetTypeInfo)(ITypeLib *This, UINT index, ITypeInfo **ppTInfo);
  HRESULT (__stdcall *GetTypeInfoType)(ITypeLib *This, UINT index, TYPEKIND *pTKind);
  HRESULT (__stdcall *GetTypeInfoOfGuid)(ITypeLib *This, const _GUID *const guid, ITypeInfo **ppTinfo);
  HRESULT (__stdcall *GetLibAttr)(ITypeLib *This, TLIBATTR **ppTLibAttr);
  HRESULT (__stdcall *GetTypeComp)(ITypeLib *This, ITypeComp **ppTComp);
  HRESULT (__stdcall *GetDocumentation)(ITypeLib *This, INT index, BSTR *pBstrName, BSTR *pBstrDocString, DWORD *pdwHelpContext, BSTR *pBstrHelpFile);
  HRESULT (__stdcall *IsName)(ITypeLib *This, LPOLESTR szNameBuf, ULONG lHashVal, BOOL *pfName);
  HRESULT (__stdcall *FindName)(ITypeLib *This, LPOLESTR szNameBuf, ULONG lHashVal, ITypeInfo **ppTInfo, MEMBERID *rgMemId, USHORT *pcFound);
  void (__stdcall *ReleaseTLibAttr)(ITypeLib *This, TLIBATTR *pTLibAttr);
};

typedef struct ITypeLibVtbl ITypeLibVtbl;



/* 220 */
enum tagSYSKIND
{
  SYS_WIN16 = 0x0,
  SYS_WIN32 = 0x1,
  SYS_MAC = 0x2,
};

typedef enum tagSYSKIND tagSYSKIND;


/* 219 */
typedef tagSYSKIND SYSKIND;

/* 218 */

struct tagTLIBATTR
{
  _GUID guid;
  LCID lcid;
  SYSKIND syskind;
  WORD wMajorVerNum;
  WORD wMinorVerNum;
  WORD wLibFlags;
};

typedef struct tagTLIBATTR tagTLIBATTR;



/* 230 */
enum bool32_t
{
  FALSE_32 = 0,
  TRUE_32 = 1,
};

typedef enum bool32_t bool32_t;


/* 227 */
struct MenuItem
{
  uint32_t flags;
  char *name;
  void (__fastcall *func)(bool32_t a1);
};

typedef struct MenuItem MenuItem;


/* 468 */
enum direction
{
  DIRECTION_SOUTH = 0,
  DIRECTION_SOUTH_WEST = 1,
  DIRECTION_WEST = 2,
  DIRECTION_NORTH_WEST = 3,
  DIRECTION_NORTH = 4,
  DIRECTION_NORTH_EAST = 5,
  DIRECTION_EAST = 6,
  DIRECTION_SOUTH_EAST = 7,
  DIRECTION_OMNI = 8,
};

typedef enum direction direction;


/* 438 */
enum spell_type
{
  SPELL_TYPE_SKILL = 0,
  SPELL_TYPE_SPELL = 1,
  SPELL_TYPE_SCROLL = 2,
  SPELL_TYPE_CHARGES = 3,
  SPELL_TYPE_INVALID = 4,
};

typedef enum spell_type spell_type;


/* 310 */
enum bool8_t
{
  FALSE_8 = 0,
  TRUE_8 = 1,
};

typedef enum bool8_t bool8_t;


/* 369 */
enum player_class
{
  PLAYER_CLASS_WARRIOR = 0,
  PLAYER_CLASS_ROGUE = 1,
  PLAYER_CLASS_SORCEROR = 2,
};

typedef enum player_class player_class;


/* 488 */
enum drop_state
{
  DROP_STATE_STARTED = 0,
  DROP_STATE_COMPLETE = 1,
  DROP_STATE_GLIMMERING = 2,
  DROP_STATE_UNKNOWN = 3,
};

typedef enum drop_state drop_state;


/* 471 */
enum item_quality
{
  ITEM_QUALITY_NORMAL = 0,
  ITEM_QUALITY_MAGIC = 1,
  ITEM_QUALITY_UNIQUE = 2,
};

typedef enum item_quality item_quality;


/* 484 */
enum item_code
{
  ITEM_CODE_NONE = 0,
  ITEM_CODE_1 = 1,
  ITEM_CODE_POTION_OF_FULL_HEALING = 2,
  ITEM_CODE_POTION_OF_HEALING = 3,
  ITEM_CODE_4 = 4,
  ITEM_CODE_5 = 5,
  ITEM_CODE_POTION_OF_MANA = 6,
  ITEM_CODE_POTION_OF_FULL_MANA = 7,
  ITEM_CODE_8 = 8,
  ITEM_CODE_9 = 9,
  ITEM_CODE_ELIXIR_OF_STRENGTH = 10,
  ITEM_CODE_ELIXIR_OF_MAGIC = 11,
  ITEM_CODE_ELIXIR_OF_DEXTERITY = 12,
  ITEM_CODE_ELIXIR_OF_VITALITY = 13,
  ITEM_CODE_14 = 14,
  ITEM_CODE_15 = 15,
  ITEM_CODE_16 = 16,
  ITEM_CODE_17 = 17,
  ITEM_CODE_POTION_OF_REJUVENATION = 18,
  ITEM_CODE_POTION_OF_FULL_REJUVENATION = 19,
  ITEM_CODE_20 = 20,
  ITEM_CODE_SCROLL_1 = 21,
  ITEM_CODE_SCROLL_2 = 22,
  ITEM_CODE_STAFF = 23,
  ITEM_CODE_BOOK = 24,
  ITEM_CODE_RING = 25,
  ITEM_CODE_AMULET = 26,
  ITEM_CODE_UNIQUE = 27,
  ITEM_CODE_28 = 28,
  ITEM_CODE_MAP_OF_THE_STARS = 42,
  ITEM_CODE_HEART = 43,
  ITEM_CODE_SPECTRAL_ELIXIR = 44,
  ITEM_CODE_INVALID = -1,
};

typedef enum item_code item_code;


/* 460 */
enum unique_item_id
{
  UNIQUE_ITEM_ID_THE_BUTCHERS_CLEAVER = 0,
  UNIQUE_ITEM_ID_THE_UNDEAD_CROWN = 1,
  UNIQUE_ITEM_ID_EMPYREAN_BAND = 2,
  UNIQUE_ITEM_ID_OPTIC_AMULET = 3,
  UNIQUE_ITEM_ID_RING_OF_TRUTH = 4,
  UNIQUE_ITEM_ID_HARLEQUIN_CREST = 5,
  UNIQUE_ITEM_ID_VEIL_OF_STEEL = 6,
  UNIQUE_ITEM_ID_ARKAINES_VALOR = 7,
  UNIQUE_ITEM_ID_GRISWOLDS_EDGE = 8,
  UNIQUE_ITEM_ID_LIGHTFORGE = 9,
  UNIQUE_ITEM_ID_THE_RIFT_BOW = 10,
  UNIQUE_ITEM_ID_THE_NEEDLER = 11,
  UNIQUE_ITEM_ID_THE_CELESTIAL_BOW = 12,
  UNIQUE_ITEM_ID_DEADLY_HUNTER = 13,
  UNIQUE_ITEM_ID_BOW_OF_THE_DEAD = 14,
  UNIQUE_ITEM_ID_THE_BLACKOAK_BOW = 15,
  UNIQUE_ITEM_ID_FLAMEDART = 16,
  UNIQUE_ITEM_ID_FLESHSTINGER = 17,
  UNIQUE_ITEM_ID_WINDFORCE = 18,
  UNIQUE_ITEM_ID_EAGLEHORN = 19,
  UNIQUE_ITEM_ID_GONNAGALS_DIRK = 20,
  UNIQUE_ITEM_ID_THE_DEFENDER = 21,
  UNIQUE_ITEM_ID_GRYPHONS_CLAW = 22,
  UNIQUE_ITEM_ID_BLACK_RAZOR = 23,
  UNIQUE_ITEM_ID_GIBBOUS_MOON = 24,
  UNIQUE_ITEM_ID_ICE_SHANK = 25,
  UNIQUE_ITEM_ID_THE_EXECUTIONERS_BLADE = 26,
  UNIQUE_ITEM_ID_THE_BONESAW = 27,
  UNIQUE_ITEM_ID_SHADOWHAWK = 28,
  UNIQUE_ITEM_ID_WIZARDSPIKE = 29,
  UNIQUE_ITEM_ID_LIGHTSABRE = 30,
  UNIQUE_ITEM_ID_THE_FALCONS_TALON = 31,
  UNIQUE_ITEM_ID_INFERNO = 32,
  UNIQUE_ITEM_ID_DOOMBRINGER = 33,
  UNIQUE_ITEM_ID_THE_GRIZZLY = 34,
  UNIQUE_ITEM_ID_THE_GRANDFATHER = 35,
  UNIQUE_ITEM_ID_THE_MANGLER = 36,
  UNIQUE_ITEM_ID_SHARP_BEAK = 37,
  UNIQUE_ITEM_ID_BLOODSLAYER = 38,
  UNIQUE_ITEM_ID_THE_CELESTIAL_AXE = 39,
  UNIQUE_ITEM_ID_WICKED_AXE = 40,
  UNIQUE_ITEM_ID_STONECLEAVER = 41,
  UNIQUE_ITEM_ID_AGUINARAS_HATCHET = 42,
  UNIQUE_ITEM_ID_HELLSLAYER = 43,
  UNIQUE_ITEM_ID_MESSERSCHMIDTS_REAVER = 44,
  UNIQUE_ITEM_ID_CRACKRUST = 45,
  UNIQUE_ITEM_ID_HAMMER_OF_JHOLM = 46,
  UNIQUE_ITEM_ID_CIVERBS_CUDGEL = 47,
  UNIQUE_ITEM_ID_THE_CELESTIAL_STAR = 48,
  UNIQUE_ITEM_ID_BARANARS_STAR = 49,
  UNIQUE_ITEM_ID_GNARLED_ROOT = 50,
  UNIQUE_ITEM_ID_THE_CRANIUM_BASHER = 51,
  UNIQUE_ITEM_ID_SCHAEFERS_HAMMER = 52,
  UNIQUE_ITEM_ID_DREAMFLANGE = 53,
  UNIQUE_ITEM_ID_STAFF_OF_SHADOWS = 54,
  UNIQUE_ITEM_ID_IMMOLATOR = 55,
  UNIQUE_ITEM_ID_STORM_SPIRE = 56,
  UNIQUE_ITEM_ID_GLEAMSONG = 57,
  UNIQUE_ITEM_ID_THUNDERCALL = 58,
  UNIQUE_ITEM_ID_THE_PROTECTOR = 59,
  UNIQUE_ITEM_ID_NAJS_PUZZLER = 60,
  UNIQUE_ITEM_ID_MINDCRY = 61,
  UNIQUE_ITEM_ID_ROD_OF_ONAN = 62,
  UNIQUE_ITEM_ID_HELM_OF_SPRITS = 63,
  UNIQUE_ITEM_ID_THINKING_CAP = 64,
  UNIQUE_ITEM_ID_OVERLORDS_HELM = 65,
  UNIQUE_ITEM_ID_FOOLS_CREST = 66,
  UNIQUE_ITEM_ID_GOTTERDAMERUNG = 67,
  UNIQUE_ITEM_ID_ROYAL_CIRCLET = 68,
  UNIQUE_ITEM_ID_TORN_FLESH_OF_SOULS = 69,
  UNIQUE_ITEM_ID_THE_GLADIATORS_BANE = 70,
  UNIQUE_ITEM_ID_THE_RAINBOW_CLOAK = 71,
  UNIQUE_ITEM_ID_LEATHER_OF_AUT = 72,
  UNIQUE_ITEM_ID_WISDOMS_WRAP = 73,
  UNIQUE_ITEM_ID_SPARKING_MAIL = 74,
  UNIQUE_ITEM_ID_SCAVENGER_CARAPACE = 75,
  UNIQUE_ITEM_ID_NIGHTSCAPE = 76,
  UNIQUE_ITEM_ID_NAJS_LIGHT_PLATE = 77,
  UNIQUE_ITEM_ID_DEMONSPIKE_COAT = 78,
  UNIQUE_ITEM_ID_THE_DEFLECTOR = 79,
  UNIQUE_ITEM_ID_SPLIT_SKULL_SHIELD = 80,
  UNIQUE_ITEM_ID_DRAGONS_BREACH = 81,
  UNIQUE_ITEM_ID_BLACKOAK_SHIELD = 82,
  UNIQUE_ITEM_ID_HOLY_DEFENDER = 83,
  UNIQUE_ITEM_ID_STORMSHIELD = 84,
  UNIQUE_ITEM_ID_BRAMBLE = 85,
  UNIQUE_ITEM_ID_RING_OF_REGHA = 86,
  UNIQUE_ITEM_ID_THE_BLEEDER = 87,
  UNIQUE_ITEM_ID_CONSTRICTING_RING = 88,
  UNIQUE_ITEM_ID_RING_OF_ENGAGEMENT = 89,
  UNIQUE_ITEM_ID_NULL = 90,
};

typedef enum unique_item_id unique_item_id;


/* 457 */
enum item_id
{
  ITEM_ID_GOLD = 0,
  ITEM_ID_SHORT_SWORD = 1,
  ITEM_ID_BUCKLER = 2,
  ITEM_ID_CLUB = 3,
  ITEM_ID_SHORT_BOW = 4,
  ITEM_ID_SHORT_STAFF_OF_CHARGED_BOLT = 5,
  ITEM_ID_CLEAVER = 6,
  ITEM_ID_THE_UNDEAD_CROWN = 7,
  ITEM_ID_EMPYREAN_BAND = 8,
  ITEM_ID_MAGIC_ROCK = 9,
  ITEM_ID_OPTIC_AMULET = 10,
  ITEM_ID_RING_OF_TRUTH = 11,
  ITEM_ID_TAVERN_SIGN = 12,
  ITEM_ID_HARLEQUIN_CREST = 13,
  ITEM_ID_VEIL_OF_STEEL = 14,
  ITEM_ID_GOLDEN_ELIXIR = 15,
  ITEM_ID_ANVIL_OF_FURY = 16,
  ITEM_ID_BLACK_MUSHROOM = 17,
  ITEM_ID_BRAIN = 18,
  ITEM_ID_FUNGAL_TOME = 19,
  ITEM_ID_SPECTRAL_ELIXIR = 20,
  ITEM_ID_BLOOD_STONE = 21,
  ITEM_ID_MAP_OF_THE_STARS = 22,
  ITEM_ID_HEART = 23,
  ITEM_ID_POTION_OF_HEALING = 24,
  ITEM_ID_POTION_OF_MANA = 25,
  ITEM_ID_SCROLL_OF_IDENTIFY = 26,
  ITEM_ID_SCROLL_OF_TOWN_PORTAL = 27,
  ITEM_ID_ARKAINES_VALOR = 28,
  ITEM_ID_POTION_OF_FULL_HEALING = 29,
  ITEM_ID_POTION_OF_FULL_MANA = 30,
  ITEM_ID_GRISWOLDS_EDGE = 31,
  ITEM_ID_LIGHTFORGE = 32,
  ITEM_ID_STAFF_OF_LAZARUS = 33,
  ITEM_ID_SCROLL_OF_RESURRECT = 34,
  ITEM_ID_NULL_1 = 35,
  ITEM_ID_NULL_2 = 36,
  ITEM_ID_NULL_3 = 37,
  ITEM_ID_NULL_4 = 38,
  ITEM_ID_NULL_5 = 39,
  ITEM_ID_NULL_6 = 40,
  ITEM_ID_NULL_7 = 41,
  ITEM_ID_NULL_8 = 42,
  ITEM_ID_NULL_9 = 43,
  ITEM_ID_NULL_10 = 44,
  ITEM_ID_NULL_11 = 45,
  ITEM_ID_NULL_12 = 46,
  ITEM_ID_NULL_13 = 47,
  ITEM_ID_BASE_CAP = 48,
  ITEM_ID_BASE_SKULL_CAP = 49,
  ITEM_ID_BASE_HELM = 50,
  ITEM_ID_BASE_FULL_HELM = 51,
  ITEM_ID_BASE_CROWN = 52,
  ITEM_ID_BASE_GREAT_HELM = 53,
  ITEM_ID_BASE_CAPE = 54,
  ITEM_ID_BASE_RAGS = 55,
  ITEM_ID_BASE_CLOAK = 56,
  ITEM_ID_BASE_ROBE = 57,
  ITEM_ID_BASE_QUILTED_ARMOR = 58,
  ITEM_ID_BASE_LEATHER_ARMOR = 59,
  ITEM_ID_BASE_HARD_LEATHER_ARMOR = 60,
  ITEM_ID_BASE_STUDDED_LEATHER_ARMOR = 61,
  ITEM_ID_BASE_RING_MAIL = 62,
  ITEM_ID_BASE_CHAIN_MAIL = 63,
  ITEM_ID_BASE_SCALE_MAIL = 64,
  ITEM_ID_BASE_BREAST_PLATE = 65,
  ITEM_ID_BASE_SPLINT_MAIL = 66,
  ITEM_ID_BASE_PLATE_MAIL = 67,
  ITEM_ID_BASE_FIELD_PLATE = 68,
  ITEM_ID_BASE_GOTHIC_PLATE = 69,
  ITEM_ID_BASE_FULL_PLATE_MAIL = 70,
  ITEM_ID_BASE_BUCKLER = 71,
  ITEM_ID_BASE_SMALL_SHIELD = 72,
  ITEM_ID_BASE_LARGE_SHIELD = 73,
  ITEM_ID_BASE_KITE_SHIELD = 74,
  ITEM_ID_BASE_TOWER_SHIELD = 75,
  ITEM_ID_BASE_GOTHIC_SHIELD = 76,
  ITEM_ID_BASE_POTION_OF_HEALING = 77,
  ITEM_ID_BASE_POTION_OF_FULL_HEALING = 78,
  ITEM_ID_BASE_POTION_OF_MANA = 79,
  ITEM_ID_BASE_POTION_OF_FULL_MANA = 80,
  ITEM_ID_BASE_POTION_OF_REJUVENATION = 81,
  ITEM_ID_BASE_POTION_OF_FULL_REJUVENATION = 82,
  ITEM_ID_BASE_ELIXIR_OF_STRENGTH = 83,
  ITEM_ID_BASE_ELIXIR_OF_MAGIC = 84,
  ITEM_ID_BASE_ELIXIR_OF_DEXTERITY = 85,
  ITEM_ID_BASE_ELIXIR_OF_VITALITY = 86,
  ITEM_ID_BASE_SCROLL_OF_HEALING = 87,
  ITEM_ID_BASE_SCROLL_OF_LIGHTNING = 88,
  ITEM_ID_BASE_SCROLL_OF_IDENTIFY = 89,
  ITEM_ID_BASE_SCROLL_OF_RESURRECT = 90,
  ITEM_ID_BASE_SCROLL_OF_FIRE_WALL = 91,
  ITEM_ID_BASE_SCROLL_OF_INFERNO = 92,
  ITEM_ID_BASE_SCROLL_OF_TOWN_PORTAL = 93,
  ITEM_ID_BASE_SCROLL_OF_FLASH = 94,
  ITEM_ID_BASE_SCROLL_OF_INFRAVISION = 95,
  ITEM_ID_BASE_SCROLL_OF_PHASING = 96,
  ITEM_ID_BASE_SCROLL_OF_MANA_SHIELD = 97,
  ITEM_ID_BASE_SCROLL_OF_FLAME_WAVE = 98,
  ITEM_ID_BASE_SCROLL_OF_FIREBALL = 99,
  ITEM_ID_BASE_SCROLL_OF_STONE_CURSE = 100,
  ITEM_ID_BASE_SCROLL_OF_CHAIN_LIGHTNING = 101,
  ITEM_ID_BASE_SCROLL_OF_GUARDIAN = 102,
  ITEM_ID_BASE_NON_ITEM = 103,
  ITEM_ID_BASE_SCROLL_OF_NOVA = 104,
  ITEM_ID_BASE_SCROLL_OF_GOLEM = 105,
  ITEM_ID_BASE_SCROLL_OF_NONE = 106,
  ITEM_ID_BASE_SCROLL_OF_TELEPORT = 107,
  ITEM_ID_BASE_SCROLL_OF_APOCALYPSE = 108,
  ITEM_ID_BASE_BOOK_QLVL_2 = 109,
  ITEM_ID_BASE_BOOK_QLVL_8 = 110,
  ITEM_ID_BASE_BOOK_QLVL_14 = 111,
  ITEM_ID_BASE_BOOK_QLVL_20 = 112,
  ITEM_ID_BASE_DAGGER = 113,
  ITEM_ID_BASE_SHORT_SWORD = 114,
  ITEM_ID_BASE_FALCHION = 115,
  ITEM_ID_BASE_SCIMITAR = 116,
  ITEM_ID_BASE_CLAYMORE = 117,
  ITEM_ID_BASE_BLADE = 118,
  ITEM_ID_BASE_SABRE = 119,
  ITEM_ID_BASE_LONG_SWORD = 120,
  ITEM_ID_BASE_BROAD_SWORD = 121,
  ITEM_ID_BASE_BASTARD_SWORD = 122,
  ITEM_ID_BASE_TWO_HANDED_SWORD = 123,
  ITEM_ID_BASE_GREAT_SWORD = 124,
  ITEM_ID_BASE_SMALL_AXE = 125,
  ITEM_ID_BASE_AXE = 126,
  ITEM_ID_BASE_LARGE_AXE = 127,
  ITEM_ID_BASE_BROAD_AXE = 128,
  ITEM_ID_BASE_BATTLE_AXE = 129,
  ITEM_ID_BASE_GREAT_AXE = 130,
  ITEM_ID_BASE_MACE = 131,
  ITEM_ID_BASE_MORNING_STAR = 132,
  ITEM_ID_BASE_WAR_HAMMER = 133,
  ITEM_ID_BASE_SPIKED_CLUB = 134,
  ITEM_ID_BASE_CLUB = 135,
  ITEM_ID_BASE_FLAIL = 136,
  ITEM_ID_BASE_MAUL = 137,
  ITEM_ID_BASE_SHORT_BOW = 138,
  ITEM_ID_BASE_HUNTERS_BOW = 139,
  ITEM_ID_BASE_LONG_BOW = 140,
  ITEM_ID_BASE_COMPOSITE_BOW = 141,
  ITEM_ID_BASE_SHORT_BATTLE_BOW = 142,
  ITEM_ID_BASE_LONG_BATTLE_BOW = 143,
  ITEM_ID_BASE_SHORT_WAR_BOW = 144,
  ITEM_ID_BASE_LONG_WAR_BOW = 145,
  ITEM_ID_BASE_SHORT_STAFF = 146,
  ITEM_ID_BASE_LONG_STAFF = 147,
  ITEM_ID_BASE_COMPOSITE_STAFF = 148,
  ITEM_ID_BASE_QUARTER_STAFF = 149,
  ITEM_ID_BASE_WAR_STAFF = 150,
  ITEM_ID_BASE_RING_QLVL_5 = 151,
  ITEM_ID_BASE_RING_QLVL_10 = 152,
  ITEM_ID_BASE_RING_QLVL_15 = 153,
  ITEM_ID_BASE_AMULET_QLVL_8 = 154,
  ITEM_ID_BASE_AMULET_QLVL_16 = 155,
  ITEM_ID_NULL_14 = 156,
};

typedef enum item_id item_id;


/* 234 */
struct Item
{
  int32_t seed;
  uint16_t wCF;
  char reserved_0006[2];
  int item_type;
  int col;
  int row;
  int item_drop_anim_update;
  void *item_drop_cel;
  int nitem_drop_frames;
  int cur_item_drop_frame;
  int item_drop_width;
  int item_drop_x_offset;
  int inactive;
  drop_state drop_state : 8;
  char reserved_0031[3];
  bool32_t draw_quest_item;
  bool32_t identified;
  item_quality item_quality : 8;
  char normal_name[64];
  char magic_name[64];
  int8_t equip_type;
  int8_t item_group;
  char reserved_00BF;
  int item_graphic_id;
  int gold_price_min;
  int gold_price_max;
  int damage_min;
  int damage_max;
  int armor_class;
  uint32_t special_effects;
  item_code item_code;
  int spell_id;
  int charges_cur;
  int charges_max;
  int cur_durability;
  int durability_max;
  int enhanced_damage;
  int chance_to_hit;
  int enhanced_defence;
  int str;
  int mag;
  int dex;
  int vit;
  int fire_resistance;
  int lightning_resistance;
  int magic_resistance;
  int MP;
  int HP;
  int damage;
  int damage_from_enemies;
  int light_radius;
  char spell_levels;
  bool8_t held_in_hand;
  char reserved_0132[2];
  unique_item_id unique_item_id : 32;
  int fire_damage_min;
  int fire_damage_max;
  int lightning_damage_min;
  int lightning_damage_max;
  int chance_to_hit_bonus;
  int8_t ability_type_primary;
  int8_t ability_type_secondary;
  char reserved_014E[2];
  int prefix_gold_price;
  int prefix_gold_price_multiplier;
  int suffix_gold_price;
  int suffix_gold_price_multiplier;
  int8_t str_req;
  int8_t mag_req;
  int8_t dex_req;
  int8_t vit_req;
  bool32_t equipable;
  item_id item_id : 32;
  int reserved_016C;
};

typedef struct Item Item;


/* 228 */
struct Player
{
  int mode;
  int8_t steps[25];
  int daction;
  int param1;
  int param2;
  BYTE gap2C[8];
  int dlvl;
  int col;
  int row;
  int col_new;
  int row_new;
  int target_col;
  int target_row;
  BYTE gap50[8];
  int field_58;
  int field_5C;
  int field_60;
  int field_64;
  BYTE gap68[8];
  direction direction;
  int anim_id;
  int field_7C;
  int field_80;
  int field_84;
  int field_88;
  int field_8C;
  int field_90;
  int field_94;
  BYTE gap98[12];
  int cast_spell_id;
  spell_type cast_spell_type;
  char field_A9;
  int cast_skill_id;
  char field_B0;
  int active_spell_id;
  spell_type active_spell_type;
  BYTE gapB9[8];
  int8_t spell_lvl_from_spell_id[64];
  uint32_t known_spells[2];
  uint32_t known_skills[2];
  uint32_t known_scroll[2];
  uint8_t missile_flags;
  int field_124;
  int field_128;
  int field_12C;
  BYTE gap130[8];
  int field_138;
  int8_t block_something;
  bool8_t invalid;
  char field_13E;
  int8_t field_13F;
  char name[32];
  player_class player_class;
  int cur_str;
  int base_str;
  int cur_mag;
  int base_mag;
  int cur_dex;
  int base_dex;
  int vit_cur;
  int vit_base;
  int points;
  int melee_character_damage;
  int chance_to_block_bonus;
  int hp_base_cur;
  int hp_base_max;
  int hp_cur;
  int hp_max;
  int hp_ratio;
  int mp_base_cur;
  int mp_base_max;
  int mp_cur;
  int mp_max;
  int mp_ratio;
  int8_t clvl;
  char field_1B9;
  int exp;
  int field_1C0;
  int exp_limit;
  char field_1C8;
  int8_t magic_resistance;
  int8_t fire_resistance;
  int8_t lightning_resistance;
  int gold_total;
  bool32_t has_infravision;
  int player_var1;
  int player_var2;
  int player_var3;
  int player_var4;
  int player_var5;
  int player_var6;
  int player_var7;
  int player_var8;
  bool8_t dlvl_visited[17];
  bool8_t quest_level_visited[6];
  BYTE gap20B[13];
  uint32_t anim_loaded;
  void *stand_cl2_hdrs[8];
  int stand_action_frame;
  int stand_frame_width;
  void *walk_cl2_hdrs[8];
  int walk_action_frame;
  int walk_frame_width;
  void *attack_cl2_hdrs[8];
  int attack_action_frame;
  int attack_frame_width;
  int field_294;
  void *lightning_magic_cl2_hdrs[8];
  void *fire_magic_cl2_hdrs[8];
  void *q_magic_cl2_hdrs[8];
  int spell_action_frame;
  int spell_frame_width;
  int field_300;
  void *hit_cl2_hdrs[8];
  int hit_action_frame;
  int hit_frame_width;
  void *death_cl2_hdrs[8];
  int death_action_frame;
  int death_frame_width;
  void *block_cl2_hdrs[8];
  int block_action_frame;
  int block_frame_width;
  Item body_items[7];
  Item inv_items[40];
  int ninv_items;
  int8_t inv_num_from_inv_grid[40];
  Item belt_items[8];
  Item cursor_item;
  BYTE gap5428[4];
  int field_542C;
  int field_5430;
  int field_5434;
  int field_5438;
  int field_543C;
  int field_5440;
  uint32_t known_charges[2];
  uint32_t special_effect;
  int8_t spell_lvls;
  int8_t spell_cost_percent;
  BYTE gap545A[10];
  int field_5464;
  int field_5468;
  int field_546C;
  int field_5470;
  char field_5478;
  uint8_t dungeon_msgs;
  char sound_something;
  char field_547B;
  char field_547C;
  char field_547D;
  char field_547E;
  char field_547F;
  __int16 field_5480;
  __int16 field_5482;
  __int16 field_5484;
  __int16 field_5486;
  __int16 field_5488;
  __int16 field_548A;
  __int16 field_548C;
  __int16 field_548E;
  int difficulty;
  int field_5494;
  int field_5498;
  int field_549C;
  int field_54A0;
  int field_54A4;
  int field_54A8;
  int field_54AC;
  void *stand_cl2;
  void *walk_cl2;
  void *attack_cl2;
  void *lightning_magic_cl2;
  void *fire_magic_cl2;
  void *q_magic_cl2;
  void *hit_cl2;
  void *death_cl2;
  void *block_cl2;
  BYTE gap54D4[3];
  char field_54D7;
};

typedef struct Player Player;


/* 229 */
struct MonsterData
{
  int frame_width;
  char *cl2_path;
  bool32_t has_special_attack;
  char *wav_path;
  bool32_t has_special_sound;
  bool32_t has_trn;
  char *trn_path;
  int last_stand_frame;
  int last_walk_frame;
  int last_attack_frame;
  int last_hit_frame;
  int last_death_frame;
  int last_special_frame;
  BYTE gap38[24];
  char *name;
  int8_t dlvl_min;
  int8_t dlvl_max;
  int8_t monster_lvl;
  int hp_min;
  int hp_max;
  int8_t monster_AI_id;
  uint32_t monster_flag;
  int8_t intelligence_factor;
  int8_t chance_to_hit;
  int8_t hit_frame;
  int8_t damage_min;
  int8_t damage_max;
  int8_t chance_to_hit_special;
  int8_t special_frame;
  int8_t damage_min_special;
  int8_t damage_max_special;
  int8_t armor_class;
  uint16_t resistance_and_immunity;
  uint16_t resistance_and_immunity_hell;
  uint16_t item_drop_flag;
  char field_7A;
  uint16_t exp_base;
  BYTE gap7E[1];
  char field_7F;
};

typedef struct MonsterData MonsterData;


/* 434 */
enum towner_id
{
  TOWNER_ID_GRISWOLD = 0,
  TOWNER_ID_PEPIN = 1,
  TOWNER_ID_WOUNDED_TOWNSMAN = 2,
  TOWNER_ID_OGDEN = 3,
  TOWNER_ID_CAIN = 4,
  TOWNER_ID_FARNHAM = 5,
  TOWNER_ID_ADRIA = 6,
  TOWNER_ID_GILLIAN = 7,
  TOWNER_ID_WIRT = 8,
  TOWNER_ID_COW = 9,
};

typedef enum towner_id towner_id;


/* 455 */
enum towner_anim_seq_id
{
  TOWNER_ANIM_SEQ_ID_GRISWOLD = 0,
  TOWNER_ANIM_SEQ_ID_PEPIN = 1,
  TOWNER_ANIM_SEQ_ID_CAIN = 2,
  TOWNER_ANIM_SEQ_ID_OGDEN = 3,
  TOWNER_ANIM_SEQ_ID_FARNHAM = 4,
  TOWNER_ANIM_SEQ_ID_ADRIA = 5,
  TOWNER_ANIM_SEQ_ID_NONE = -1,
};

typedef enum towner_anim_seq_id towner_anim_seq_id;


/* 447 */
enum quest_id
{
  QUEST_ID_THE_MAGIC_ROCK = 0,
  QUEST_ID_BLACK_MUSHROOM = 1,
  QUEST_ID_GHARBAD_THE_WEAK = 2,
  QUEST_ID_ZHAR_THE_MAD = 3,
  QUEST_ID_LACHDANAN = 4,
  QUEST_ID_DIABLO = 5,
  QUEST_ID_THE_BUTCHER = 6,
  QUEST_ID_OGDENS_SIGN = 7,
  QUEST_ID_HALLS_OF_THE_BLIND = 8,
  QUEST_ID_VALOR = 9,
  QUEST_ID_ANVIL_OF_FURY = 10,
  QUEST_ID_WARLORD_OF_BLOOD = 11,
  QUEST_ID_THE_CURSE_OF_KING_LEORIC = 12,
  QUEST_ID_POISONED_WATER_SUPPLY = 13,
  QUEST_ID_THE_CHAMBER_OF_BONE = 14,
  QUEST_ID_ARCHBISHOP_LAZARUS = 15,
  QUEST_ID_INVALID = -1,
};

typedef enum quest_id quest_id;


/* 451 */
struct Gossip
{
  quest_id quest_id;
  int8_t speech_id;
  bool8_t active;
};

typedef struct Gossip Gossip;


/* 231 */
struct Towner
{
  BYTE gap0[4];
  towner_id towner_id;
  int col;
  int row;
  BYTE gap10[20];
  void *active_cel;
  int nticks_per_frame;
  int cur_tick;
  int nframes;
  int cur_frame;
  int cur_frame_index;
  towner_anim_seq_id towner_anim_seq_id;
  int frame_width;
  int field_44;
  int unused;
  int field_50;
  bool32_t targetable;
  bool32_t field_58;
  Gossip gossip[16];
  int32_t seed;
  int interacting_player_num;
  int field_94;
  BYTE gap98[8];
  char name[32];
  void *cel_from_direction[8];
  int field_E0;
  void *towner_cel;
};

typedef struct Towner Towner;


/* 444 */
enum speech_id
{
  SPEECH_ID_TOWNERS_STORYT01_WAV_AHH_THE_STORY_OF_OUR_KING_IS_IT = 0,
  SPEECH_ID_TOWNERS_TAVOWN21_WAV_THE_VILLAGE_NEEDS_YOUR_HELP_GOOD_MASTER = 1,
  SPEECH_ID_TOWNERS_TAVOWN22_WAV_AS_I_TOLD_YOU_GOOD_MASTER_THE_KING_WAS_ENTOMBED = 2,
  SPEECH_ID_TOWNERS_TAVOWN23_WAV_THE_CURSE_OF_OUR_KING_HAS_PASSED_BUT_I_FEAR = 3,
  SPEECH_ID_TOWNERS_HEALER01_WAV_THE_LOSS_OF_HIS_SON_WAS_TOO_MUCH_FOR_KING = 4,
  SPEECH_ID_TOWNERS_BMAID01_WAV_I_DONT_LIKE_TO_THINK_ABOUT_HOW_THE_KING_DIED = 5,
  SPEECH_ID_TOWNERS_BSMITH01_WAV_I_MADE_MANY_OF_THE_WEAPONS_AND_MOST_OF_THE = 6,
  SPEECH_ID_TOWNERS_DRUNK01_WAV_I_DONT_CARE_ABOUT_THAT = 7,
  SPEECH_ID_TOWNERS_WITCH01_WAV_THE_DEAD_WHO_WALK_AMONG_THE_LIVING_FOLLOW_THE_CURSED = 8,
  SPEECH_ID_TOWNERS_PEGBOY01_WAV_LOOK_IM_RUNNING_A_BUSINESS_HERE = 9,
  SPEECH_ID_MONSTERS_SKING01_WAV_THE_WARMTH_OF_LIFE_HAS_ENTERED_MY_TOMB = 10,
  SPEECH_ID_TOWNERS_STORYT02_WAV_I_SEE_THAT_THIS_STRANGE_BEHAVIOR_PUZZLES_YOU_AS_WELL = 11,
  SPEECH_ID_TOWNERS_TAVOWN24_WAV_MASTER_I_HAVE_A_STRANGE_EXPERIENCE_TO_RELATE = 12,
  SPEECH_ID_TOWNERS_TAVOWN25_WAV_OH_YOU_DIDNT_HAVE_TO_BRING_BACK_MY_SIGN_BUT = 13,
  SPEECH_ID_TOWNERS_HEALER02_WAV_MY_GOODNESS_DEMONS_RUNNING_ABOUT_THE_VILLAGE_AT_NIGHT_PILLAGING = 14,
  SPEECH_ID_TOWNERS_BMAID02_WAV_OH_MY = 15,
  SPEECH_ID_TOWNERS_BSMITH02_WAV_DEMONS_STOLE_OGDENS_SIGN_YOU_SAY = 16,
  SPEECH_ID_TOWNERS_DRUNK02_WAV_YOU_KNOW_WHAT_I_THINK = 17,
  SPEECH_ID_TOWNERS_WITCH02_WAV_NO_MORTAL_CAN_TRULY_UNDERSTAND_THE_MIND_OF_THE_DEMON = 18,
  SPEECH_ID_TOWNERS_PEGBOY02_WAV_WHAT = 19,
  SPEECH_ID_MONSTERS_SNOT01_WAV_HEY = 20,
  SPEECH_ID_MONSTERS_SNOT02_WAV_YOU_KILL_UGLIES_GET_BANNER = 21,
  SPEECH_ID_MONSTERS_SNOT03_WAV_YOU_GIVE = 22,
  SPEECH_ID_TOWNERS_STORYT36_WAV_THIS_DOES_NOT_BODE_WELL_FOR_IT_CONFIRMS_MY_DARKEST = 23,
  SPEECH_ID_TOWNERS_STORYT37_WAV_YOU_MUST_HURRY_AND_RESCUE_ALBRECHT_FROM_THE_HANDS_OF = 24,
  SPEECH_ID_TOWNERS_STORYT38_WAV_YOUR_STORY_IS_QUITE_GRIM_MY_FRIEND_1 = 25,
  SPEECH_ID_TOWNERS_TAVOWN01_WAV_LAZARUS_WAS_THE_ARCHBISHOP_WHO_LED_MANY_OF_THE_TOWNSPEOPLE = 26,
  SPEECH_ID_TOWNERS_STORYT38_WAV_YOUR_STORY_IS_QUITE_GRIM_MY_FRIEND_2 = 27,
  SPEECH_ID_TOWNERS_STORYT38_WAV_YOUR_STORY_IS_QUITE_GRIM_MY_FRIEND_3 = 28,
  SPEECH_ID_TOWNERS_HEALER03_WAV_I_WAS_SHOCKED_WHEN_I_HEARD_OF_WHAT_THE_TOWNSPEOPLE = 29,
  SPEECH_ID_TOWNERS_BMAID03_WAV_I_REMEMBER_LAZARUS_AS_BEING_A_VERY_KIND_AND_GIVING = 30,
  SPEECH_ID_TOWNERS_BSMITH03_WAV_I_WAS_THERE_WHEN_LAZARUS_LED_US_INTO_THE_LABYRINTH = 31,
  SPEECH_ID_TOWNERS_DRUNK03_WAV_THEY_STAB_THEN_BITE_THEN_THEYRE_ALL_AROUND_YOU = 32,
  SPEECH_ID_TOWNERS_WITCH03_WAV_I_DID_NOT_KNOW_THIS_LAZARUS_OF_WHOM_YOU_SPEAK = 33,
  SPEECH_ID_TOWNERS_PEGBOY03_WAV_YES_THE_RIGHTEOUS_LAZARUS_WHO_WAS_SOOO_EFFECTIVE_AGAINST_THOSE = 34,
  SPEECH_ID_MONSTERS_LAZ01_WAV_ABANDON_YOUR_FOOLISH_QUEST_1 = 35,
  SPEECH_ID_MONSTERS_LAZ01_WAV_ABANDON_YOUR_FOOLISH_QUEST_2 = 36,
  SPEECH_ID_TOWNERS_STORYT04_WAV_HMM_I_DONT_KNOW_WHAT_I_CAN_REALLY_TELL_YOU = 37,
  SPEECH_ID_TOWNERS_TAVOWN02_WAV_I_HAVE_ALWAYS_TRIED_TO_KEEP_A_LARGE_SUPPLY_OF = 38,
  SPEECH_ID_TOWNERS_HEALER20_WAV_IM_GLAD_I_CAUGHT_UP_TO_YOU_IN_TIME = 39,
  SPEECH_ID_TOWNERS_HEALER21_WAV_PLEASE_YOU_MUST_HURRY = 40,
  SPEECH_ID_TOWNERS_HEALER22_WAV_WHATS_THAT_YOU_SAY = 41,
  SPEECH_ID_TOWNERS_BMAID04_WAV_MY_GRANDMOTHER_IS_VERY_WEAK_AND_GARDA_SAYS_THAT_WE = 42,
  SPEECH_ID_TOWNERS_BSMITH04_WAV_PEPIN_HAS_TOLD_YOU_THE_TRUTH = 43,
  SPEECH_ID_TOWNERS_DRUNK04_WAV_YOU_DRINK_WATER = 44,
  SPEECH_ID_TOWNERS_WITCH04_WAV_THE_PEOPLE_OF_TRISTRAM_WILL_DIE_IF_YOU_CANNOT_RESTORE = 45,
  SPEECH_ID_TOWNERS_PEGBOY04_WAV_FOR_ONCE_IM_WITH_YOU = 46,
  SPEECH_ID_TOWNERS_STORYT07_WAV_A_BOOK_THAT_SPEAKS_OF_A_CHAMBER_OF_HUMAN_BONES = 47,
  SPEECH_ID_TOWNERS_TAVOWN05_WAV_I_AM_AFRAID_THAT_I_DONT_KNOW_ANYTHING_ABOUT_THAT = 48,
  SPEECH_ID_TOWNERS_HEALER05_WAV_THIS_SOUNDS_LIKE_A_VERY_DANGEROUS_PLACE = 49,
  SPEECH_ID_TOWNERS_BMAID06_WAV_I_AM_AFRAID_THAT_I_HAVENT_HEARD_ANYTHING_ABOUT_THAT = 50,
  SPEECH_ID_TOWNERS_BSMITH07_WAV_I_KNOW_NOTHING_OF_THIS_PLACE_BUT_YOU_MAY_TRY = 51,
  SPEECH_ID_TOWNERS_DRUNK07_WAV_OKAY_SO_LISTEN = 52,
  SPEECH_ID_TOWNERS_WITCH07_WAV_YOU_WILL_BECOME_AN_ETERNAL_SERVANT_OF_THE_DARK_LORDS = 53,
  SPEECH_ID_TOWNERS_PEGBOY07_WAV_A_VAST_AND_MYSTERIOUS_TREASURE_YOU_SAY = 54,
  SPEECH_ID_TOWNERS_STORYT10_WAV_IT_SEEMS_THAT_THE_ARCHBISHOP_LAZARUS_GOADED_MANY_OF_THE = 55,
  SPEECH_ID_TOWNERS_TAVOWN08_WAV_YES_FARNHAM_HAS_MUMBLED_SOMETHING_ABOUT_A_HULKING_BRUTE_WHO = 56,
  SPEECH_ID_TOWNERS_HEALER08_WAV_BY_THE_LIGHT_I_KNOW_OF_THIS_VILE_DEMON = 57,
  SPEECH_ID_TOWNERS_BMAID08_WAV_WHEN_FARNHAM_SAID_SOMETHING_ABOUT_A_BUTCHER_KILLING_PEOPLE_I = 58,
  SPEECH_ID_TOWNERS_BSMITH10_WAV_I_SAW_WHAT_FARNHAM_CALLS_THE_BUTCHER_AS_IT_SWATHED = 59,
  SPEECH_ID_TOWNERS_DRUNK10_WAV_BIG = 60,
  SPEECH_ID_TOWNERS_WITCH10_WAV_THE_BUTCHER_IS_A_SADISTIC_CREATURE_THAT_DELIGHTS_IN_THE = 61,
  SPEECH_ID_TOWNERS_PEGBOY10_WAV_I_KNOW_MORE_THAN_YOUD_THINK_ABOUT_THAT_GRISLY_FIEND = 62,
  SPEECH_ID_TOWNERS_WOUND01_WAV_PLEASE_LISTEN_TO_ME = 63,
  SPEECH_ID_MONSTERS_BUTCHER_WAV = 64,
  SPEECH_ID_TOWNERS_STORYT12_WAV_YOU_RECITE_AN_INTERESTING_RHYME_WRITTEN_IN_A_STYLE_THAT = 65,
  SPEECH_ID_TOWNERS_TAVOWN10_WAV_I_NEVER_MUCH_CARED_FOR_POETRY = 66,
  SPEECH_ID_TOWNERS_HEALER10_WAV_THIS_DOES_SEEM_FAMILIAR_SOMEHOW = 67,
  SPEECH_ID_TOWNERS_BMAID10_WAV_IF_YOU_HAVE_QUESTIONS_ABOUT_BLINDNESS_YOU_SHOULD_TALK_TO = 68,
  SPEECH_ID_TOWNERS_BSMITH12_WAV_I_AM_AFRAID_THAT_I_HAVE_NEITHER_HEARD_NOR_SEEN = 69,
  SPEECH_ID_TOWNERS_DRUNK12_WAV_LOOK_HERE = 70,
  SPEECH_ID_TOWNERS_WITCH12_WAV_THIS_IS_A_PLACE_OF_GREAT_ANGUISH_AND_TERROR_AND = 71,
  SPEECH_ID_TOWNERS_PEGBOY11_WAV_LETS_SEE_AM_I_SELLING_YOU_SOMETHING = 72,
  SPEECH_ID_TOWNERS_STORYT13_WAV_YOU_CLAIM_TO_HAVE_SPOKEN_WITH_LACHDANAN = 73,
  SPEECH_ID_TOWNERS_TAVOWN11_WAV_YOU_SPEAK_OF_A_BRAVE_WARRIOR_LONG_DEAD = 74,
  SPEECH_ID_TOWNERS_HEALER11_WAV_A_GOLDEN_ELIXIR_YOU_SAY = 75,
  SPEECH_ID_TOWNERS_BMAID11_WAV_IVE_NEVER_HEARD_OF_A_LACHDANAN_BEFORE = 76,
  SPEECH_ID_TOWNERS_BSMITH13_WAV_IF_IT_IS_ACTUALLY_LACHDANAN_THAT_YOU_HAVE_MET_THEN = 77,
  SPEECH_ID_TOWNERS_DRUNK13_WAV_LACHDANAN_IS_DEAD = 78,
  SPEECH_ID_TOWNERS_WITCH13_WAV_YOU_MAY_MEET_PEOPLE_WHO_ARE_TRAPPED_WITHIN_THE_LABYRINTH = 79,
  SPEECH_ID_TOWNERS_PEGBOY12_WAV_WAIT_LET_ME_GUESS = 80,
  SPEECH_ID_MONSTERS_LACH01_WAV_PLEASE_DONT_KILL_ME_JUST_HEAR_ME_OUT = 81,
  SPEECH_ID_MONSTERS_LACH02_WAV_YOU_HAVE_NOT_FOUND_THE_GOLDEN_ELIXIR = 82,
  SPEECH_ID_MONSTERS_LACH03_WAV_YOU_HAVE_SAVED_MY_SOUL_FROM_DAMNATION_AND_FOR_THAT = 83,
  SPEECH_ID_TOWNERS_STORYT14_WAV_GRISWOLD_SPEAKS_OF_THE_ANVIL_OF_FURY = 84,
  SPEECH_ID_TOWNERS_TAVOWN12_WAV_DONT_YOU_THINK_THAT_GRISWOLD_WOULD_BE_A_BETTER_PERSON = 85,
  SPEECH_ID_TOWNERS_HEALER12_WAV_IF_YOU_HAD_BEEN_LOOKING_FOR_INFORMATION_ON_THE_PESTLE = 86,
  SPEECH_ID_TOWNERS_BMAID12_WAV_GRISWOLDS_FATHER_USED_TO_TELL_SOME_OF_US_WHEN_WE = 87,
  SPEECH_ID_TOWNERS_BSMITH21_WAV_GREETINGS = 88,
  SPEECH_ID_TOWNERS_BSMITH22_WAV_NOTHING_YET_EH = 89,
  SPEECH_ID_TOWNERS_BSMITH23_WAV_I_CAN_HARDLY_BELIEVE_IT = 90,
  SPEECH_ID_TOWNERS_DRUNK14_WAV_GRISWOLD_CANT_SELL_HIS_ANVIL = 91,
  SPEECH_ID_TOWNERS_WITCH14_WAV_THERE_ARE_MANY_ARTIFACTS_WITHIN_THE_LABYRINTH_THAT_HOLD_POWERS = 92,
  SPEECH_ID_TOWNERS_PEGBOY13_WAV_IF_YOU_WERE_TO_FIND_THIS_ARTIFACT_FOR_GRISWOLD_IT = 93,
  SPEECH_ID_TOWNERS_STORYT15_WAV_THE_GATEWAY_OF_BLOOD_AND_THE_HALLS_OF_FIRE_ARE = 94,
  SPEECH_ID_TOWNERS_TAVOWN13_WAV_EVERY_CHILD_HEARS_THE_STORY_OF_THE_WARRIOR_ARKAINE_AND = 95,
  SPEECH_ID_TOWNERS_HEALER13_WAV_HMM = 96,
  SPEECH_ID_TOWNERS_BMAID13_WAV_THE_STORY_OF_THE_MAGIC_ARMOR_CALLED_VALOR_IS_SOMETHING = 97,
  SPEECH_ID_TOWNERS_BSMITH14_WAV_THE_ARMOR_KNOWN_AS_VALOR_COULD_BE_WHAT_TIPS_THE = 98,
  SPEECH_ID_TOWNERS_DRUNK15_WAV_ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ = 99,
  SPEECH_ID_TOWNERS_WITCH15_WAV_SHOULD_YOU_FIND_THESE_STONES_OF_BLOOD_USE_THEM_CAREFULLY = 100,
  SPEECH_ID_TOWNERS_PEGBOY14_WAV_YOU_INTEND_TO_FIND_THE_ARMOR_KNOWN_AS_VALOR = 101,
  SPEECH_ID_TOWNERS_STORYT18_WAV_I_KNOW_OF_ONLY_ONE_LEGEND_THAT_SPEAKS_OF_SUCH = 102,
  SPEECH_ID_TOWNERS_TAVOWN16_WAV_I_AM_AFRAID_THAT_I_HAVENT_HEARD_ANYTHING_ABOUT_SUCH = 103,
  SPEECH_ID_TOWNERS_HEALER16_WAV_CAIN_WOULD_BE_ABLE_TO_TELL_YOU_MUCH_MORE_ABOUT = 104,
  SPEECH_ID_TOWNERS_BMAID16_WAV_IF_YOU_ARE_TO_BATTLE_SUCH_A_FIERCE_OPPONENT_MAY = 105,
  SPEECH_ID_TOWNERS_BSMITH17_WAV_DARK_AND_WICKED_LEGENDS_SURROUNDS_THE_ONE_WARLORD_OF_BLOOD = 106,
  SPEECH_ID_TOWNERS_DRUNK17_WAV_ALWAYS_YOU_GOTTA_TALK_ABOUT_BLOOD = 107,
  SPEECH_ID_TOWNERS_WITCH18_WAV_HIS_PROWESS_WITH_THE_BLADE_IS_AWESOME_AND_HE_HAS = 108,
  SPEECH_ID_TOWNERS_PEGBOY17_WAV_I_HAVENT_EVER_DEALT_WITH_THIS_WARLORD_YOU_SPEAK_OF = 109,
  SPEECH_ID_MONSTERS_WARLRD01_WAV_MY_BLADE_SINGS_FOR_YOUR_BLOOD_MORTAL_AND_BY_MY = 110,
  SPEECH_ID_TOWNERS_STORYT20_WAV_GRISWOLD_SPEAKS_OF_THE_HEAVEN_STONE_THAT_WAS_DESTINED_FOR = 111,
  SPEECH_ID_TOWNERS_TAVOWN18_WAV_THE_CARAVAN_STOPPED_HERE_TO_TAKE_ON_SOME_SUPPLIES_FOR = 112,
  SPEECH_ID_TOWNERS_HEALER18_WAV_I_DONT_KNOW_WHAT_IT_IS_THAT_THEY_THOUGHT_THEY = 113,
  SPEECH_ID_TOWNERS_BMAID18_WAV_WELL_A_CARAVAN_OF_SOME_VERY_IMPORTANT_PEOPLE_DID_STOP = 114,
  SPEECH_ID_TOWNERS_BSMITH24_WAV_STAY_FOR_A_MOMENT = 115,
  SPEECH_ID_TOWNERS_BSMITH25_WAV_I_AM_STILL_WAITING_FOR_YOU_TO_BRING_ME_THAT = 116,
  SPEECH_ID_TOWNERS_BSMITH26_WAV_LET_ME_SEE_THAT = 117,
  SPEECH_ID_TOWNERS_DRUNK19_WAV_I_USED_TO_HAVE_A_NICE_RING = 118,
  SPEECH_ID_TOWNERS_WITCH20_WAV_THE_HEAVEN_STONE_IS_VERY_POWERFUL_AND_WERE_IT_ANY = 119,
  SPEECH_ID_TOWNERS_PEGBOY18_WAV_IF_ANYONE_CAN_MAKE_SOMETHING_OUT_OF_THAT_ROCK_GRISWOLD = 120,
  SPEECH_ID_TOWNERS_STORYT21_WAV_THE_WITCH_ADRIA_SEEKS_A_BLACK_MUSHROOM = 121,
  SPEECH_ID_TOWNERS_TAVOWN19_WAV_LET_ME_JUST_SAY_THIS = 122,
  SPEECH_ID_TOWNERS_HEALER26_WAV_THE_WITCH_TOLD_ME_THAT_YOU_WERE_SEARCHING_FOR_THE = 123,
  SPEECH_ID_TOWNERS_HEALER27_WAV_EXCELLENT_THIS_IS_JUST_WHAT_I_HAD_IN_MIND = 124,
  SPEECH_ID_TOWNERS_BMAID19_WAV_I_THINK_OGDEN_MIGHT_HAVE_SOME_MUSHROOMS_IN_THE_STORAGE = 125,
  SPEECH_ID_TOWNERS_BSMITH19_WAV_IF_ADRIA_DOESNT_HAVE_ONE_OF_THESE_YOU_CAN_BET = 126,
  SPEECH_ID_TOWNERS_DRUNK20_WAV_OGDEN_MIXES_A_MEAN_BLACK_MUSHROOM_BUT_I_GET_SICK = 127,
  SPEECH_ID_TOWNERS_WITCH22_WAV_WHAT_DO_WE_HAVE_HERE = 128,
  SPEECH_ID_TOWNERS_WITCH23_WAV_ITS_A_BIG_BLACK_MUSHROOM_THAT_I_NEED = 129,
  SPEECH_ID_TOWNERS_WITCH24_WAV_YES_THIS_WILL_BE_PERFECT_FOR_A_BREW_THAT_I = 130,
  SPEECH_ID_TOWNERS_WITCH25_WAV_WHY_HAVE_YOU_BROUGHT_THAT_HERE = 131,
  SPEECH_ID_TOWNERS_WITCH26_WAV_WHAT = 132,
  SPEECH_ID_TOWNERS_PEGBOY19_WAV_I_DONT_HAVE_ANY_MUSHROOMS_OF_ANY_SIZE_OR_COLOR = 133,
  SPEECH_ID_TOWNERS_STORYT22_WAV_SO_THE_LEGEND_OF_THE_MAP_IS_REAL = 134,
  SPEECH_ID_TOWNERS_STORYT23_WAV_OUR_TIME_IS_RUNNING_SHORT = 135,
  SPEECH_ID_TOWNERS_STORYT24_WAV_I_AM_SURE_THAT_YOU_TRIED_YOUR_BEST_BUT_I = 136,
  SPEECH_ID_TOWNERS_TAVOWN20_WAV_IF_THE_WITCH_CANT_HELP_YOU_AND_SUGGESTS_YOU_SEE = 137,
  SPEECH_ID_TOWNERS_HEALER19_WAV_I_CANT_MAKE_MUCH_OF_THE_WRITING_ON_THIS_MAP = 138,
  SPEECH_ID_TOWNERS_BMAID20_WAV_THE_BEST_PERSON_TO_ASK_ABOUT_THAT_SORT_OF_THING = 139,
  SPEECH_ID_TOWNERS_BSMITH20_WAV_I_HAVE_NEVER_SEEN_A_MAP_OF_THIS_SORT_BEFORE = 140,
  SPEECH_ID_TOWNERS_DRUNK21_WAV_LISTEN_HERE_COME_CLOSE = 141,
  SPEECH_ID_TOWNERS_WITCH21_WAV_OH_IM_AFRAID_THIS_DOES_NOT_BODE_WELL_AT_ALL = 142,
  SPEECH_ID_TOWNERS_PEGBOY20_WAV_IVE_BEEN_LOOKING_FOR_A_MAP_BUT_THAT_CERTAINLY_ISNT = 143,
  SPEECH_ID_MONSTERS_GARBUD01_WAV_PLEEEEASE_NO_HURT = 144,
  SPEECH_ID_MONSTERS_GARBUD02_WAV_SOMETHING_FOR_YOU_I_AM_MAKING = 145,
  SPEECH_ID_MONSTERS_GARBUD03_WAV_NOTHING_YET = 146,
  SPEECH_ID_MONSTERS_GARBUD04_WAV_THIS_TOO_GOOD_FOR_YOU = 147,
  SPEECH_ID_MONSTERS_ZHAR01_WAV_WHAT = 148,
  SPEECH_ID_MONSTERS_ZHAR02_WAV_ARRRRGH = 149,
  SPEECH_ID_TOWNERS_STORYT25_WAV_HELLO_MY_FRIEND = 150,
  SPEECH_ID_TOWNERS_STORYT26_WAV_WHILE_YOU_ARE_VENTURING_DEEPER_INTO_THE_LABYRINTH_YOU_MAY = 151,
  SPEECH_ID_TOWNERS_STORYT27_WAV_I_KNOW_OF_MANY_MYTHS_AND_LEGENDS_THAT_MAY_CONTAIN = 152,
  SPEECH_ID_TOWNERS_STORYT28_WAV_GRISWOLD = 153,
  SPEECH_ID_TOWNERS_STORYT29_WAV_OGDEN_HAS_OWNED_AND_RUN_THE_RISING_SUN_INN_AND = 154,
  SPEECH_ID_TOWNERS_STORYT30_WAV_POOR_FARNHAM = 155,
  SPEECH_ID_TOWNERS_STORYT31_WAV_THE_WITCH_ADRIA_IS_AN_ANOMALY_HERE_IN_TRISTRAM = 156,
  SPEECH_ID_TOWNERS_STORYT33_WAV_THE_STORY_OF_WIRT_IS_A_FRIGHTENING_AND_TRAGIC_ONE = 157,
  SPEECH_ID_TOWNERS_STORYT34_WAV_AH_PEPIN = 158,
  SPEECH_ID_TOWNERS_STORYT35_WAV_GILLIAN_IS_A_FINE_WOMAN = 159,
  SPEECH_ID_TOWNERS_TAVOWN36_WAV_GREETINGS_GOOD_MASTER = 160,
  SPEECH_ID_TOWNERS_TAVOWN37_WAV_MANY_ADVENTURERS_HAVE_GRACED_THE_TABLES_OF_MY_TAVERN_AND = 161,
  SPEECH_ID_TOWNERS_TAVOWN38_WAV_GRISWOLD_THE_BLACKSMITH_IS_EXTREMELY_KNOWLEDGEABLE_ABOUT_WEAPONS_AND_ARMOR = 162,
  SPEECH_ID_TOWNERS_TAVOWN39_WAV_FARNHAM_SPENDS_FAR_TOO_MUCH_TIME_HERE_DROWNING_HIS_SORROWS = 163,
  SPEECH_ID_TOWNERS_TAVOWN40_WAV_ADRIA_IS_WISE_BEYOND_HER_YEARS_BUT_I_MUST_ADMIT = 164,
  SPEECH_ID_TOWNERS_TAVOWN41_WAV_IF_YOU_WANT_TO_KNOW_MORE_ABOUT_THE_HISTORY_OF = 165,
  SPEECH_ID_TOWNERS_TAVOWN43_WAV_WIRT_IS_A_RAPSCALLION_AND_A_LITTLE_SCOUNDREL = 166,
  SPEECH_ID_TOWNERS_TAVOWN44_WAV_PEPIN_IS_A_GOOD_MAN = 167,
  SPEECH_ID_TOWNERS_TAVOWN45_WAV_GILLIAN_MY_BARMAID = 168,
  SPEECH_ID_TOWNERS_HEALER37_WAV_WHAT_AILS_YOU_MY_FRIEND = 169,
  SPEECH_ID_TOWNERS_HEALER38_WAV_I_HAVE_MADE_A_VERY_INTERESTING_DISCOVERY = 170,
  SPEECH_ID_TOWNERS_HEALER39_WAV_BEFORE_IT_WAS_TAKEN_OVER_BY_WELL_WHATEVER_LURKS_BELOW = 171,
  SPEECH_ID_TOWNERS_HEALER40_WAV_GRISWOLD_KNOWS_AS_MUCH_ABOUT_THE_ART_OF_WAR_AS = 172,
  SPEECH_ID_TOWNERS_HEALER41_WAV_CAIN_IS_A_TRUE_FRIEND_AND_A_WISE_SAGE = 173,
  SPEECH_ID_TOWNERS_HEALER42_WAV_EVEN_MY_SKILLS_HAVE_BEEN_UNABLE_TO_FULLY_HEAL_FARNHAM = 174,
  SPEECH_ID_TOWNERS_HEALER43_WAV_WHILE_I_USE_SOME_LIMITED_FORMS_OF_MAGIC_TO_CREATE = 175,
  SPEECH_ID_TOWNERS_HEALER45_WAV_POOR_WIRT = 176,
  SPEECH_ID_TOWNERS_HEALER46_WAV_I_REALLY_DONT_UNDERSTAND_WHY_OGDEN_STAYS_HERE_IN_TRISTRAM = 177,
  SPEECH_ID_TOWNERS_HEALER47_WAV_OGDENS_BARMAID_IS_A_SWEET_GIRL = 178,
  SPEECH_ID_TOWNERS_BMAID31_WAV_GOOD_DAY = 179,
  SPEECH_ID_TOWNERS_BMAID32_WAV_MY_GRANDMOTHER_HAD_A_DREAM_THAT_YOU_WOULD_COME_AND = 180,
  SPEECH_ID_TOWNERS_BMAID33_WAV_THE_WOMAN_AT_THE_EDGE_OF_TOWN_IS_A_WITCH = 181,
  SPEECH_ID_TOWNERS_BMAID34_WAV_OUR_BLACKSMITH_IS_A_POINT_OF_PRIDE_TO_THE_PEOPLE = 182,
  SPEECH_ID_TOWNERS_BMAID35_WAV_CAIN_HAS_BEEN_THE_STORYTELLER_OF_TRISTRAM_FOR_AS_LONG = 183,
  SPEECH_ID_TOWNERS_BMAID36_WAV_FARNHAM_IS_A_DRUNKARD_WHO_FILLS_HIS_BELLY_WITH_ALE = 184,
  SPEECH_ID_TOWNERS_BMAID37_WAV_PEPIN_SAVED_MY_GRANDMOTHERS_LIFE_AND_I_KNOW_THAT_I = 185,
  SPEECH_ID_TOWNERS_BMAID39_WAV_I_GREW_UP_WITH_WIRTS_MOTHER_CANACE = 186,
  SPEECH_ID_TOWNERS_BMAID40_WAV_OGDEN_AND_HIS_WIFE_HAVE_TAKEN_ME_AND_MY_GRANDMOTHER = 187,
  SPEECH_ID_TOWNERS_BSMITH44_WAV_WELL_WHAT_CAN_I_DO_FOR_YA = 188,
  SPEECH_ID_TOWNERS_BSMITH45_WAV_IF_YOURE_LOOKING_FOR_A_GOOD_WEAPON_LET_ME_SHOW = 189,
  SPEECH_ID_TOWNERS_BSMITH46_WAV_THE_AXE = 190,
  SPEECH_ID_TOWNERS_BSMITH47_WAV_LOOK_AT_THAT_EDGE_THAT_BALANCE = 191,
  SPEECH_ID_TOWNERS_BSMITH48_WAV_YOUR_WEAPONS_AND_ARMOR_WILL_SHOW_THE_SIGNS_OF_YOUR = 192,
  SPEECH_ID_TOWNERS_BSMITH49_WAV_WHILE_I_HAVE_TO_PRACTICALLY_SMUGGLE_IN_THE_METALS_AND = 193,
  SPEECH_ID_TOWNERS_BSMITH50_WAV_GILLIAN_IS_A_NICE_LASS = 194,
  SPEECH_ID_TOWNERS_BSMITH51_WAV_SOMETIMES_I_THINK_THAT_CAIN_TALKS_TOO_MUCH_BUT_I = 195,
  SPEECH_ID_TOWNERS_BSMITH52_WAV_I_WAS_WITH_FARNHAM_THAT_NIGHT_THAT_LAZARUS_LED_US = 196,
  SPEECH_ID_TOWNERS_BSMITH53_WAV_A_GOOD_MAN_WHO_PUTS_THE_NEEDS_OF_OTHERS_ABOVE = 197,
  SPEECH_ID_TOWNERS_BSMITH55_WAV_THAT_LAD_IS_GOING_TO_GET_HIMSELF_INTO_SERIOUS_TROUBLE = 198,
  SPEECH_ID_TOWNERS_BSMITH56_WAV_THE_INNKEEPER_HAS_LITTLE_BUSINESS_AND_NO_REAL_WAY_OF = 199,
  SPEECH_ID_TOWNERS_DRUNK27_WAV_CANT_A_FELLA_DRINK_IN_PEACE = 200,
  SPEECH_ID_TOWNERS_DRUNK28_WAV_THE_GAL_WHO_BRINGS_THE_DRINKS = 201,
  SPEECH_ID_TOWNERS_DRUNK29_WAV_WHY_DONT_THAT_OLD_CRONE_DO_SOMETHIN_FOR_A_CHANGE = 202,
  SPEECH_ID_TOWNERS_DRUNK30_WAV_CAIN_ISNT_WHAT_HE_SAYS_HE_IS = 203,
  SPEECH_ID_TOWNERS_DRUNK31_WAV_GRISWOLD = 204,
  SPEECH_ID_TOWNERS_DRUNK32_WAV_HEHEHE_I_LIKE_PEPIN = 205,
  SPEECH_ID_TOWNERS_DRUNK34_WAV_WIRT_IS_A_KID_WITH_MORE_PROBLEMS_THAN_EVEN_ME = 206,
  SPEECH_ID_TOWNERS_DRUNK35_WAV_OGDEN_IS_THE_BEST_MAN_IN_TOWN = 207,
  SPEECH_ID_TOWNERS_DRUNK23_WAV_I_WANNA_TELL_YA_SUMTHIN_CAUSE_I_KNOW_ALL_ABOUT = 208,
  SPEECH_ID_TOWNERS_DRUNK24_WAV_NO_ONE_EVER_LIS = 209,
  SPEECH_ID_TOWNERS_DRUNK25_WAV_I_KNOW_YOU_GOTS_YOUR_OWN_IDEAS_AND_I_KNOW = 210,
  SPEECH_ID_TOWNERS_DRUNK26_WAV_IF_I_WAS_YOU = 211,
  SPEECH_ID_TOWNERS_WITCH38_WAV_I_SENSE_A_SOUL_IN_SEARCH_OF_ANSWERS = 212,
  SPEECH_ID_TOWNERS_WITCH39_WAV_WISDOM_IS_EARNED_NOT_GIVEN = 213,
  SPEECH_ID_TOWNERS_WITCH40_WAV_THE_GREATEST_POWER_IS_OFTEN_THE_SHORTEST_LIVED = 214,
  SPEECH_ID_TOWNERS_WITCH41_WAV_THOUGH_THE_HEAT_OF_THE_SUN_IS_BEYOND_MEASURE_THE = 215,
  SPEECH_ID_TOWNERS_WITCH42_WAV_THE_SUM_OF_OUR_KNOWLEDGE_IS_IN_THE_SUM_OF = 216,
  SPEECH_ID_TOWNERS_WITCH43_WAV_TO_A_MAN_WHO_ONLY_KNOWS_IRON_THERE_IS_NO = 217,
  SPEECH_ID_TOWNERS_WITCH44_WAV_CORRUPTION_HAS_THE_STRENGTH_OF_DECEIT_BUT_INNOCENCE_HOLDS_THE = 218,
  SPEECH_ID_TOWNERS_WITCH45_WAV_A_CHEST_OPENED_IN_DARKNESS_HOLDS_NO_GREATER_TREASURE_THAN = 219,
  SPEECH_ID_TOWNERS_WITCH46_WAV_THE_HIGHER_YOU_PLACE_YOUR_FAITH_IN_ONE_MAN_THE = 220,
  SPEECH_ID_TOWNERS_WITCH47_WAV_THE_HAND_THE_HEART_AND_THE_MIND_CAN_PERFORM_MIRACLES = 221,
  SPEECH_ID_TOWNERS_WITCH49_WAV_THERE_IS_MUCH_ABOUT_THE_FUTURE_WE_CANNOT_SEE_BUT = 222,
  SPEECH_ID_TOWNERS_WITCH50_WAV_EARTHEN_WALLS_AND_THATCHED_CANOPY_DO_NOT_A_HOME_CREATE = 223,
  SPEECH_ID_TOWNERS_PEGBOY32_WAV_PSSST = 224,
  SPEECH_ID_TOWNERS_PEGBOY33_WAV_NOT_EVERYONE_IN_TRISTRAM_HAS_A_USE = 225,
  SPEECH_ID_TOWNERS_PEGBOY34_WAV_DONT_TRUST_EVERYTHING_THE_DRUNK_SAYS = 226,
  SPEECH_ID_TOWNERS_PEGBOY35_WAV_IN_CASE_YOU_HAVENT_NOTICED_I_DONT_BUY_ANYTHING_FROM = 227,
  SPEECH_ID_TOWNERS_PEGBOY36_WAV_I_GUESS_I_OWE_THE_BLACKSMITH_MY_LIFE = 228,
  SPEECH_ID_TOWNERS_PEGBOY37_WAV_IF_I_WERE_A_FEW_YEARS_OLDER_I_WOULD_SHOWER = 229,
  SPEECH_ID_TOWNERS_PEGBOY38_WAV_CAIN_KNOWS_TOO_MUCH = 230,
  SPEECH_ID_TOWNERS_PEGBOY39_WAV_FARNHAM = 231,
  SPEECH_ID_TOWNERS_PEGBOY40_WAV_AS_LONG_AS_YOU_DONT_NEED_ANYTHING_REATTACHED_OLD_PEPIN = 232,
  SPEECH_ID_TOWNERS_PEGBOY42_WAV_ADRIA_TRULY_BOTHERS_ME = 233,
  SPEECH_ID_TOWNERS_PEGBOY43_WAV_OGDEN_IS_A_FOOL_FOR_STAYING_HERE = 234,
  SPEECH_ID_WARRIOR_WARIOR01_WAV_BEYOND_THE_HALL_OF_HEROES_LIES_THE_CHAMBER_OF_BONE = 235,
  SPEECH_ID_WARRIOR_WARIOR10_WAV = 236,
  SPEECH_ID_WARRIOR_WARIOR11_WAV_I_CAN_SEE_WHAT_YOU_SEE_NOT = 237,
  SPEECH_ID_WARRIOR_WARIOR12_WAV_THE_ARMORIES_OF_HELL_ARE_HOME_TO_THE_WARLORD_OF = 238,
  SPEECH_ID_SORCEROR_MAGE01_WAV_BEYOND_THE_HALL_OF_HEROES_LIES_THE_CHAMBER_OF_BONE = 239,
  SPEECH_ID_SORCEROR_MAGE10_WAV = 240,
  SPEECH_ID_SORCEROR_MAGE11_WAV_I_CAN_SEE_WHAT_YOU_SEE_NOT = 241,
  SPEECH_ID_SORCEROR_MAGE12_WAV_THE_ARMORIES_OF_HELL_ARE_HOME_TO_THE_WARLORD_OF = 242,
  SPEECH_ID_ROGUE_ROGUE01_WAV_BEYOND_THE_HALL_OF_HEROES_LIES_THE_CHAMBER_OF_BONE = 243,
  SPEECH_ID_ROGUE_ROGUE10_WAV = 244,
  SPEECH_ID_ROGUE_ROGUE11_WAV_I_CAN_SEE_WHAT_YOU_SEE_NOT = 245,
  SPEECH_ID_ROGUE_ROGUE12_WAV_THE_ARMORIES_OF_HELL_ARE_HOME_TO_THE_WARLORD_OF = 246,
  SPEECH_ID_TOWNERS_COW1_WAV = 247,
  SPEECH_ID_TOWNERS_COW2_WAV = 248,
  SPEECH_ID_NARRATOR_NAR01_WAV_TAKE_HEED_AND_BEAR_WITNESS_TO_THE_TRUTHS_THAT_LIE = 249,
  SPEECH_ID_NARRATOR_NAR02_WAV_TAKE_HEED_AND_BEAR_WITNESS_TO_THE_TRUTHS_THAT_LIE = 250,
  SPEECH_ID_NARRATOR_NAR03_WAV_TAKE_HEED_AND_BEAR_WITNESS_TO_THE_TRUTHS_THAT_LIE = 251,
  SPEECH_ID_NARRATOR_NAR04_WAV_SO_IT_CAME_TO_BE_THAT_THERE_WAS_A_GREAT = 252,
  SPEECH_ID_NARRATOR_NAR05_WAV_MANY_DEMONS_TRAVELED_TO_THE_MORTAL_REALM_IN_SEARCH_OF = 253,
  SPEECH_ID_NARRATOR_NAR06_WAV_SO_IT_CAME_TO_BE_THAT_THE_THREE_PRIME_EVILS = 254,
  SPEECH_ID_NARRATOR_NAR07_WAV_ALL_PRAISES_TO_DIABLO = 255,
  SPEECH_ID_NARRATOR_NAR08_WAV_GLORY_AND_APPROBATION_TO_DIABLO = 256,
  SPEECH_ID_NARRATOR_NAR09_WAV_HAIL_AND_SACRIFICE_TO_DIABLO = 257,
  SPEECH_ID_TOWNERS_TAVOWN00_WAV_THANK_GOODNESS_YOUVE_RETURNED = 258,
  SPEECH_ID_INVALID = -1,
};

typedef enum speech_id speech_id;


/* 232 */
struct GossipData
{
  speech_id the_magic_rock;
  speech_id black_mushroom;
  speech_id gharbad_the_weak;
  speech_id zhar_the_mad;
  speech_id lachdanan;
  speech_id diablo;
  speech_id the_butcher;
  speech_id ogdens_sign;
  speech_id halls_of_the_blind;
  speech_id valor;
  speech_id anvil_of_fury;
  speech_id warlord_of_blood;
  speech_id the_curse_of_king_leoric;
  speech_id poisoned_water_supply;
  speech_id the_chamber_of_bone;
  speech_id archbishop_lazarus;
};

typedef struct GossipData GossipData;


/* 233 */
enum MACRO_PM
{
  PM_NOREMOVE = 0x0,
  PM_REMOVE = 0x1,
  PM_NOYIELD = 0x2,
};

typedef enum MACRO_PM MACRO_PM;


/* 458 */
enum drop_rate
{
  DROP_RATE_NEVER = 0,
  DROP_RATE_REGULAR = 1,
  DROP_RATE_DOUBLE = 2,
};

typedef enum drop_rate drop_rate;


/* 474 */
enum item_type
{
  ITEM_TYPE_MISC = 0,
  ITEM_TYPE_SWORD = 1,
  ITEM_TYPE_AXE = 2,
  ITEM_TYPE_BOW = 3,
  ITEM_TYPE_MACE = 4,
  ITEM_TYPE_SHIELD = 5,
  ITEM_TYPE_LIGHT_ARMOR = 6,
  ITEM_TYPE_HELM = 7,
  ITEM_TYPE_MEDIUM_ARMOR = 8,
  ITEM_TYPE_HEAVY_ARMOR = 9,
  ITEM_TYPE_STAFF = 10,
  ITEM_TYPE_GOLD = 11,
  ITEM_TYPE_RING = 12,
  ITEM_TYPE_AMULET = 13,
  ITEM_TYPE_14 = 14,
  ITEM_TYPE_NONE = -1,
};

typedef enum item_type item_type;


/* 235 */
struct ItemData
{
  drop_rate drop_rate;
  int8_t item_group;
  int8_t equip_type;
  int item_graphic_id;
  item_type item_type;
  int8_t unique_item_base;
  char *name;
  BYTE gap14[4];
  int8_t quality_lvl;
  int durability;
  int damage_min;
  int damage_max;
  int armor_class;
  int field_2C;
  int8_t str_req;
  int8_t mag_req;
  int8_t dex_req;
  int8_t vit_req;
  int field_34;
  item_code item_code;
  int spell_id;
  bool32_t consumable;
  int gold_price_min;
  BYTE gap48[3];
  char field_4B;
};

typedef struct ItemData ItemData;


/* 236 */
struct Lighting
{
  int col;
  int row;
  int light_radius;
  int field_C;
  bool32_t inactive;
  bool32_t visible;
  BYTE gap18[4];
  int col_prev;
  int row_prev;
  int light_radius_prev;
  int x_offset;
  int y_offset;
  int field_30;
};

typedef struct Lighting Lighting;


/* 440 */
enum sfx_id
{
  SFX_ID_MISC_WALK1_WAV = 0,
  SFX_ID_MISC_WALK2_WAV = 1,
  SFX_ID_MISC_WALK3_WAV = 2,
  SFX_ID_MISC_WALK4_WAV = 3,
  SFX_ID_MISC_BFIRE_WAV = 4,
  SFX_ID_MISC_FMAG_WAV = 5,
  SFX_ID_MISC_TMAG_WAV = 6,
  SFX_ID_MISC_LGHIT_WAV = 7,
  SFX_ID_MISC_LGHIT1_WAV = 8,
  SFX_ID_MISC_SWING_WAV = 9,
  SFX_ID_MISC_SWING2_WAV = 10,
  SFX_ID_MISC_DEAD_WAV = 11,
  SFX_ID_MISC_QUESTDON_WAV = 12,
  SFX_ID_ITEMS_ARMRFKD_WAV = 13,
  SFX_ID_ITEMS_BARLFIRE_WAV = 14,
  SFX_ID_ITEMS_BARREL_WAV = 15,
  SFX_ID_ITEMS_BHIT_WAV = 16,
  SFX_ID_ITEMS_BHIT1_WAV = 17,
  SFX_ID_ITEMS_CHEST_WAV = 18,
  SFX_ID_ITEMS_DOORCLOS_WAV = 19,
  SFX_ID_ITEMS_DOOROPEN_WAV = 20,
  SFX_ID_ITEMS_FLIPANVL_WAV = 21,
  SFX_ID_ITEMS_FLIPAXE_WAV = 22,
  SFX_ID_ITEMS_FLIPBLST_WAV = 23,
  SFX_ID_ITEMS_FLIPBODY_WAV = 24,
  SFX_ID_ITEMS_FLIPBOOK_WAV = 25,
  SFX_ID_ITEMS_FLIPBOW_WAV = 26,
  SFX_ID_ITEMS_FLIPCAP_WAV = 27,
  SFX_ID_ITEMS_FLIPHARM_WAV = 28,
  SFX_ID_ITEMS_FLIPLARM_WAV = 29,
  SFX_ID_ITEMS_FLIPMAG_WAV = 30,
  SFX_ID_ITEMS_FLIPMAG1_WAV = 31,
  SFX_ID_ITEMS_FLIPMUSH_WAV = 32,
  SFX_ID_ITEMS_FLIPPOT_WAV = 33,
  SFX_ID_ITEMS_FLIPRING_WAV = 34,
  SFX_ID_ITEMS_FLIPROCK_WAV = 35,
  SFX_ID_ITEMS_FLIPSCRL_WAV = 36,
  SFX_ID_ITEMS_FLIPSHLD_WAV = 37,
  SFX_ID_ITEMS_FLIPSIGN_WAV = 38,
  SFX_ID_ITEMS_FLIPSTAF_WAV = 39,
  SFX_ID_ITEMS_FLIPSWOR_WAV = 40,
  SFX_ID_ITEMS_GOLD_WAV = 41,
  SFX_ID_ITEMS_HLMTFKD_WAV = 42,
  SFX_ID_ITEMS_INVANVL_WAV = 43,
  SFX_ID_ITEMS_INVAXE_WAV = 44,
  SFX_ID_ITEMS_INVBLST_WAV = 45,
  SFX_ID_ITEMS_INVBODY_WAV = 46,
  SFX_ID_ITEMS_INVBOOK_WAV = 47,
  SFX_ID_ITEMS_INVBOW_WAV = 48,
  SFX_ID_ITEMS_INVCAP_WAV = 49,
  SFX_ID_ITEMS_INVGRAB_WAV = 50,
  SFX_ID_ITEMS_INVHARM_WAV = 51,
  SFX_ID_ITEMS_INVLARM_WAV = 52,
  SFX_ID_ITEMS_INVMUSH_WAV = 53,
  SFX_ID_ITEMS_INVPOT_WAV = 54,
  SFX_ID_ITEMS_INVRING_WAV = 55,
  SFX_ID_ITEMS_INVROCK_WAV = 56,
  SFX_ID_ITEMS_INVSCROL_WAV = 57,
  SFX_ID_ITEMS_INVSHIEL_WAV = 58,
  SFX_ID_ITEMS_INVSIGN_WAV = 59,
  SFX_ID_ITEMS_INVSTAF_WAV = 60,
  SFX_ID_ITEMS_INVSWORD_WAV = 61,
  SFX_ID_ITEMS_LEVER_WAV = 62,
  SFX_ID_ITEMS_MAGIC_WAV = 63,
  SFX_ID_ITEMS_MAGIC1_WAV = 64,
  SFX_ID_ITEMS_READBOOK_WAV = 65,
  SFX_ID_ITEMS_SARC_WAV = 66,
  SFX_ID_ITEMS_SHIELFKD_WAV = 67,
  SFX_ID_ITEMS_SWRDFKD_WAV = 68,
  SFX_ID_ITEMS_TITLEMOV_WAV = 69,
  SFX_ID_ITEMS_TITLSLCT_WAV = 70,
  SFX_ID_MISC_BLANK_WAV = 71,
  SFX_ID_ITEMS_TRAP_WAV = 72,
  SFX_ID_MISC_CAST1_WAV = 73,
  SFX_ID_MISC_CAST10_WAV = 74,
  SFX_ID_MISC_CAST12_WAV = 75,
  SFX_ID_MISC_CAST2_WAV = 76,
  SFX_ID_MISC_CAST3_WAV = 77,
  SFX_ID_MISC_CAST4_WAV = 78,
  SFX_ID_MISC_CAST5_WAV = 79,
  SFX_ID_MISC_CAST6_WAV = 80,
  SFX_ID_MISC_CAST7_WAV = 81,
  SFX_ID_MISC_CAST8_WAV = 82,
  SFX_ID_MISC_CAST9_WAV = 83,
  SFX_ID_MISC_HEALING_WAV = 84,
  SFX_ID_MISC_REPAIR_WAV = 85,
  SFX_ID_MISC_ACIDS1_WAV = 86,
  SFX_ID_MISC_ACIDS2_WAV = 87,
  SFX_ID_MISC_APOC_WAV = 88,
  SFX_ID_MISC_ARROWALL_WAV = 89,
  SFX_ID_MISC_BLDBOIL_WAV = 90,
  SFX_ID_MISC_BLODSTAR_WAV = 91,
  SFX_ID_MISC_BLSIMPT_WAV = 92,
  SFX_ID_MISC_BONESP_WAV = 93,
  SFX_ID_MISC_BSIMPCT_WAV = 94,
  SFX_ID_MISC_CALDRON_WAV = 95,
  SFX_ID_MISC_CBOLT_WAV = 96,
  SFX_ID_MISC_CHLTNING_WAV = 97,
  SFX_ID_MISC_DSERP_WAV = 98,
  SFX_ID_MISC_ELECIMP1_WAV = 99,
  SFX_ID_MISC_ELEMENTL_WAV = 100,
  SFX_ID_MISC_ETHEREAL_WAV = 101,
  SFX_ID_MISC_FBALL_WAV = 102,
  SFX_ID_MISC_FBOLT1_WAV = 103,
  SFX_ID_MISC_FBOLT2_WAV = 104,
  SFX_ID_MISC_FIRIMP1_WAV = 105,
  SFX_ID_MISC_FIRIMP2_WAV = 106,
  SFX_ID_MISC_FLAMWAVE_WAV = 107,
  SFX_ID_MISC_FLASH_WAV = 108,
  SFX_ID_MISC_FOUNTAIN_WAV = 109,
  SFX_ID_MISC_GOLUM_WAV = 110,
  SFX_ID_MISC_GOLUMDED_WAV = 111,
  SFX_ID_MISC_GSHRINE_WAV = 112,
  SFX_ID_MISC_GUARD_WAV = 113,
  SFX_ID_MISC_GRDLANCH_WAV = 114,
  SFX_ID_MISC_HOLYBOLT_WAV = 115,
  SFX_ID_MISC_HYPER_WAV = 116,
  SFX_ID_MISC_INFRAVIS_WAV = 117,
  SFX_ID_MISC_INVISIBL_WAV = 118,
  SFX_ID_MISC_INVPOT_WAV = 119,
  SFX_ID_MISC_LNING1_WAV = 120,
  SFX_ID_MISC_LTNING_WAV = 121,
  SFX_ID_MISC_MSHIELD_WAV = 122,
  SFX_ID_MISC_NOVA_WAV = 123,
  SFX_ID_MISC_PORTAL_WAV = 124,
  SFX_ID_MISC_PUDDLE_WAV = 125,
  SFX_ID_MISC_RESUR_WAV = 126,
  SFX_ID_MISC_SCURSE_WAV = 127,
  SFX_ID_MISC_SCURIMP_WAV = 128,
  SFX_ID_MISC_SENTINEL_WAV = 129,
  SFX_ID_MISC_SHATTER_WAV = 130,
  SFX_ID_MISC_SOULFIRE_WAV = 131,
  SFX_ID_MISC_SPOUTLOP_WAV = 132,
  SFX_ID_MISC_SPOUTSTR_WAV = 133,
  SFX_ID_MISC_STORM_WAV = 134,
  SFX_ID_MISC_TRAPDIS_WAV = 135,
  SFX_ID_MISC_TELEPORT_WAV = 136,
  SFX_ID_MISC_VTHEFT_WAV = 137,
  SFX_ID_MISC_WALLLOOP_WAV = 138,
  SFX_ID_MISC_WALLSTRT_WAV = 139,
  SFX_ID_TOWNERS_BMAID01_WAV_I_DONT_LIKE_TO_THINK_ABOUT_HOW_THE_KING_DIED = 140,
  SFX_ID_TOWNERS_BMAID02_WAV_OH_MY = 141,
  SFX_ID_TOWNERS_BMAID03_WAV_I_REMEMBER_LAZARUS_AS_BEING_A_VERY_KIND_AND_GIVING = 142,
  SFX_ID_TOWNERS_BMAID04_WAV_MY_GRANDMOTHER_IS_VERY_WEAK_AND_GARDA_SAYS_THAT_WE = 143,
  SFX_ID_TOWNERS_BMAID05_WAV = 144,
  SFX_ID_TOWNERS_BMAID06_WAV_I_AM_AFRAID_THAT_I_HAVENT_HEARD_ANYTHING_ABOUT_THAT = 145,
  SFX_ID_TOWNERS_BMAID07_WAV = 146,
  SFX_ID_TOWNERS_BMAID08_WAV_WHEN_FARNHAM_SAID_SOMETHING_ABOUT_A_BUTCHER_KILLING_PEOPLE_I = 147,
  SFX_ID_TOWNERS_BMAID09_WAV = 148,
  SFX_ID_TOWNERS_BMAID10_WAV_IF_YOU_HAVE_QUESTIONS_ABOUT_BLINDNESS_YOU_SHOULD_TALK_TO = 149,
  SFX_ID_TOWNERS_BMAID11_WAV_IVE_NEVER_HEARD_OF_A_LACHDANAN_BEFORE = 150,
  SFX_ID_TOWNERS_BMAID12_WAV_GRISWOLDS_FATHER_USED_TO_TELL_SOME_OF_US_WHEN_WE = 151,
  SFX_ID_TOWNERS_BMAID13_WAV_THE_STORY_OF_THE_MAGIC_ARMOR_CALLED_VALOR_IS_SOMETHING = 152,
  SFX_ID_TOWNERS_BMAID14_WAV = 153,
  SFX_ID_TOWNERS_BMAID15_WAV = 154,
  SFX_ID_TOWNERS_BMAID16_WAV_IF_YOU_ARE_TO_BATTLE_SUCH_A_FIERCE_OPPONENT_MAY = 155,
  SFX_ID_TOWNERS_BMAID17_WAV = 156,
  SFX_ID_TOWNERS_BMAID18_WAV_WELL_A_CARAVAN_OF_SOME_VERY_IMPORTANT_PEOPLE_DID_STOP = 157,
  SFX_ID_TOWNERS_BMAID19_WAV_I_THINK_OGDEN_MIGHT_HAVE_SOME_MUSHROOMS_IN_THE_STORAGE = 158,
  SFX_ID_TOWNERS_BMAID20_WAV_THE_BEST_PERSON_TO_ASK_ABOUT_THAT_SORT_OF_THING = 159,
  SFX_ID_TOWNERS_BMAID21_WAV = 160,
  SFX_ID_TOWNERS_BMAID22_WAV = 161,
  SFX_ID_TOWNERS_BMAID23_WAV = 162,
  SFX_ID_TOWNERS_BMAID24_WAV = 163,
  SFX_ID_TOWNERS_BMAID25_WAV = 164,
  SFX_ID_TOWNERS_BMAID26_WAV = 165,
  SFX_ID_TOWNERS_BMAID27_WAV = 166,
  SFX_ID_TOWNERS_BMAID28_WAV = 167,
  SFX_ID_TOWNERS_BMAID29_WAV = 168,
  SFX_ID_TOWNERS_BMAID30_WAV = 169,
  SFX_ID_TOWNERS_BMAID31_WAV_GOOD_DAY = 170,
  SFX_ID_TOWNERS_BMAID32_WAV_MY_GRANDMOTHER_HAD_A_DREAM_THAT_YOU_WOULD_COME_AND = 171,
  SFX_ID_TOWNERS_BMAID33_WAV_THE_WOMAN_AT_THE_EDGE_OF_TOWN_IS_A_WITCH = 172,
  SFX_ID_TOWNERS_BMAID34_WAV_OUR_BLACKSMITH_IS_A_POINT_OF_PRIDE_TO_THE_PEOPLE = 173,
  SFX_ID_TOWNERS_BMAID35_WAV_CAIN_HAS_BEEN_THE_STORYTELLER_OF_TRISTRAM_FOR_AS_LONG = 174,
  SFX_ID_TOWNERS_BMAID36_WAV_FARNHAM_IS_A_DRUNKARD_WHO_FILLS_HIS_BELLY_WITH_ALE = 175,
  SFX_ID_TOWNERS_BMAID37_WAV_PEPIN_SAVED_MY_GRANDMOTHERS_LIFE_AND_I_KNOW_THAT_I = 176,
  SFX_ID_TOWNERS_BMAID38_WAV = 177,
  SFX_ID_TOWNERS_BMAID39_WAV_I_GREW_UP_WITH_WIRTS_MOTHER_CANACE = 178,
  SFX_ID_TOWNERS_BMAID40_WAV_OGDEN_AND_HIS_WIFE_HAVE_TAKEN_ME_AND_MY_GRANDMOTHER = 179,
  SFX_ID_TOWNERS_BSMITH01_WAV_I_MADE_MANY_OF_THE_WEAPONS_AND_MOST_OF_THE = 180,
  SFX_ID_TOWNERS_BSMITH02_WAV_DEMONS_STOLE_OGDENS_SIGN_YOU_SAY = 181,
  SFX_ID_TOWNERS_BSMITH03_WAV_I_WAS_THERE_WHEN_LAZARUS_LED_US_INTO_THE_LABYRINTH = 182,
  SFX_ID_TOWNERS_BSMITH04_WAV_PEPIN_HAS_TOLD_YOU_THE_TRUTH = 183,
  SFX_ID_TOWNERS_BSMITH05_WAV = 184,
  SFX_ID_TOWNERS_BSMITH06_WAV = 185,
  SFX_ID_TOWNERS_BSMITH07_WAV_I_KNOW_NOTHING_OF_THIS_PLACE_BUT_YOU_MAY_TRY = 186,
  SFX_ID_TOWNERS_BSMITH08_WAV = 187,
  SFX_ID_TOWNERS_BSMITH09_WAV = 188,
  SFX_ID_TOWNERS_BSMITH10_WAV_I_SAW_WHAT_FARNHAM_CALLS_THE_BUTCHER_AS_IT_SWATHED = 189,
  SFX_ID_TOWNERS_BSMITH11_WAV = 190,
  SFX_ID_TOWNERS_BSMITH12_WAV_I_AM_AFRAID_THAT_I_HAVE_NEITHER_HEARD_NOR_SEEN = 191,
  SFX_ID_TOWNERS_BSMITH13_WAV_IF_IT_IS_ACTUALLY_LACHDANAN_THAT_YOU_HAVE_MET_THEN = 192,
  SFX_ID_TOWNERS_BSMITH14_WAV_THE_ARMOR_KNOWN_AS_VALOR_COULD_BE_WHAT_TIPS_THE = 193,
  SFX_ID_TOWNERS_BSMITH15_WAV = 194,
  SFX_ID_TOWNERS_BSMITH16_WAV = 195,
  SFX_ID_TOWNERS_BSMITH17_WAV_DARK_AND_WICKED_LEGENDS_SURROUNDS_THE_ONE_WARLORD_OF_BLOOD = 196,
  SFX_ID_TOWNERS_BSMITH18_WAV = 197,
  SFX_ID_TOWNERS_BSMITH19_WAV_IF_ADRIA_DOESNT_HAVE_ONE_OF_THESE_YOU_CAN_BET = 198,
  SFX_ID_TOWNERS_BSMITH20_WAV_I_HAVE_NEVER_SEEN_A_MAP_OF_THIS_SORT_BEFORE = 199,
  SFX_ID_TOWNERS_BSMITH21_WAV_GREETINGS = 200,
  SFX_ID_TOWNERS_BSMITH22_WAV_NOTHING_YET_EH = 201,
  SFX_ID_TOWNERS_BSMITH23_WAV_I_CAN_HARDLY_BELIEVE_IT = 202,
  SFX_ID_TOWNERS_BSMITH24_WAV_STAY_FOR_A_MOMENT = 203,
  SFX_ID_TOWNERS_BSMITH25_WAV_I_AM_STILL_WAITING_FOR_YOU_TO_BRING_ME_THAT = 204,
  SFX_ID_TOWNERS_BSMITH26_WAV_LET_ME_SEE_THAT = 205,
  SFX_ID_TOWNERS_BSMITH27_WAV = 206,
  SFX_ID_TOWNERS_BSMITH28_WAV = 207,
  SFX_ID_TOWNERS_BSMITH29_WAV = 208,
  SFX_ID_TOWNERS_BSMITH30_WAV = 209,
  SFX_ID_TOWNERS_BSMITH31_WAV = 210,
  SFX_ID_TOWNERS_BSMITH32_WAV = 211,
  SFX_ID_TOWNERS_BSMITH33_WAV = 212,
  SFX_ID_TOWNERS_BSMITH34_WAV = 213,
  SFX_ID_TOWNERS_BSMITH35_WAV = 214,
  SFX_ID_TOWNERS_BSMITH36_WAV = 215,
  SFX_ID_TOWNERS_BSMITH37_WAV = 216,
  SFX_ID_TOWNERS_BSMITH38_WAV = 217,
  SFX_ID_TOWNERS_BSMITH39_WAV = 218,
  SFX_ID_TOWNERS_BSMITH40_WAV = 219,
  SFX_ID_TOWNERS_BSMITH41_WAV = 220,
  SFX_ID_TOWNERS_BSMITH42_WAV = 221,
  SFX_ID_TOWNERS_BSMITH43_WAV = 222,
  SFX_ID_TOWNERS_BSMITH44_WAV_WELL_WHAT_CAN_I_DO_FOR_YA = 223,
  SFX_ID_TOWNERS_BSMITH45_WAV_IF_YOURE_LOOKING_FOR_A_GOOD_WEAPON_LET_ME_SHOW = 224,
  SFX_ID_TOWNERS_BSMITH46_WAV_THE_AXE = 225,
  SFX_ID_TOWNERS_BSMITH47_WAV_LOOK_AT_THAT_EDGE_THAT_BALANCE = 226,
  SFX_ID_TOWNERS_BSMITH48_WAV_YOUR_WEAPONS_AND_ARMOR_WILL_SHOW_THE_SIGNS_OF_YOUR = 227,
  SFX_ID_TOWNERS_BSMITH49_WAV_WHILE_I_HAVE_TO_PRACTICALLY_SMUGGLE_IN_THE_METALS_AND = 228,
  SFX_ID_TOWNERS_BSMITH50_WAV_GILLIAN_IS_A_NICE_LASS = 229,
  SFX_ID_TOWNERS_BSMITH51_WAV_SOMETIMES_I_THINK_THAT_CAIN_TALKS_TOO_MUCH_BUT_I = 230,
  SFX_ID_TOWNERS_BSMITH52_WAV_I_WAS_WITH_FARNHAM_THAT_NIGHT_THAT_LAZARUS_LED_US = 231,
  SFX_ID_TOWNERS_BSMITH53_WAV_A_GOOD_MAN_WHO_PUTS_THE_NEEDS_OF_OTHERS_ABOVE = 232,
  SFX_ID_TOWNERS_BSMITH54_WAV = 233,
  SFX_ID_TOWNERS_BSMITH55_WAV_THAT_LAD_IS_GOING_TO_GET_HIMSELF_INTO_SERIOUS_TROUBLE = 234,
  SFX_ID_TOWNERS_BSMITH56_WAV_THE_INNKEEPER_HAS_LITTLE_BUSINESS_AND_NO_REAL_WAY_OF = 235,
  SFX_ID_TOWNERS_COW1_WAV = 236,
  SFX_ID_TOWNERS_COW2_WAV = 237,
  SFX_ID_TOWNERS_DEADGUY2_WAV = 238,
  SFX_ID_TOWNERS_DRUNK01_WAV_I_DONT_CARE_ABOUT_THAT = 239,
  SFX_ID_TOWNERS_DRUNK02_WAV_YOU_KNOW_WHAT_I_THINK = 240,
  SFX_ID_TOWNERS_DRUNK03_WAV_THEY_STAB_THEN_BITE_THEN_THEYRE_ALL_AROUND_YOU = 241,
  SFX_ID_TOWNERS_DRUNK04_WAV_YOU_DRINK_WATER = 242,
  SFX_ID_TOWNERS_DRUNK05_WAV = 243,
  SFX_ID_TOWNERS_DRUNK06_WAV = 244,
  SFX_ID_TOWNERS_DRUNK07_WAV_OKAY_SO_LISTEN = 245,
  SFX_ID_TOWNERS_DRUNK08_WAV = 246,
  SFX_ID_TOWNERS_DRUNK09_WAV = 247,
  SFX_ID_TOWNERS_DRUNK10_WAV_BIG = 248,
  SFX_ID_TOWNERS_DRUNK11_WAV = 249,
  SFX_ID_TOWNERS_DRUNK12_WAV_LOOK_HERE = 250,
  SFX_ID_TOWNERS_DRUNK13_WAV_LACHDANAN_IS_DEAD = 251,
  SFX_ID_TOWNERS_DRUNK14_WAV_GRISWOLD_CANT_SELL_HIS_ANVIL = 252,
  SFX_ID_TOWNERS_DRUNK15_WAV_ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ = 253,
  SFX_ID_TOWNERS_DRUNK16_WAV = 254,
  SFX_ID_TOWNERS_DRUNK17_WAV_ALWAYS_YOU_GOTTA_TALK_ABOUT_BLOOD = 255,
  SFX_ID_TOWNERS_DRUNK18_WAV = 256,
  SFX_ID_TOWNERS_DRUNK19_WAV_I_USED_TO_HAVE_A_NICE_RING = 257,
  SFX_ID_TOWNERS_DRUNK20_WAV_OGDEN_MIXES_A_MEAN_BLACK_MUSHROOM_BUT_I_GET_SICK = 258,
  SFX_ID_TOWNERS_DRUNK21_WAV_LISTEN_HERE_COME_CLOSE = 259,
  SFX_ID_TOWNERS_DRUNK22_WAV = 260,
  SFX_ID_TOWNERS_DRUNK23_WAV_I_WANNA_TELL_YA_SUMTHIN_CAUSE_I_KNOW_ALL_ABOUT = 261,
  SFX_ID_TOWNERS_DRUNK24_WAV_NO_ONE_EVER_LIS = 262,
  SFX_ID_TOWNERS_DRUNK25_WAV_I_KNOW_YOU_GOTS_YOUR_OWN_IDEAS_AND_I_KNOW = 263,
  SFX_ID_TOWNERS_DRUNK26_WAV_IF_I_WAS_YOU = 264,
  SFX_ID_TOWNERS_DRUNK27_WAV_CANT_A_FELLA_DRINK_IN_PEACE = 265,
  SFX_ID_TOWNERS_DRUNK28_WAV_THE_GAL_WHO_BRINGS_THE_DRINKS = 266,
  SFX_ID_TOWNERS_DRUNK29_WAV_WHY_DONT_THAT_OLD_CRONE_DO_SOMETHIN_FOR_A_CHANGE = 267,
  SFX_ID_TOWNERS_DRUNK30_WAV_CAIN_ISNT_WHAT_HE_SAYS_HE_IS = 268,
  SFX_ID_TOWNERS_DRUNK31_WAV_GRISWOLD = 269,
  SFX_ID_TOWNERS_DRUNK32_WAV_HEHEHE_I_LIKE_PEPIN = 270,
  SFX_ID_TOWNERS_DRUNK33_WAV = 271,
  SFX_ID_TOWNERS_DRUNK34_WAV_WIRT_IS_A_KID_WITH_MORE_PROBLEMS_THAN_EVEN_ME = 272,
  SFX_ID_TOWNERS_DRUNK35_WAV_OGDEN_IS_THE_BEST_MAN_IN_TOWN = 273,
  SFX_ID_TOWNERS_HEALER01_WAV_THE_LOSS_OF_HIS_SON_WAS_TOO_MUCH_FOR_KING = 274,
  SFX_ID_TOWNERS_HEALER02_WAV_MY_GOODNESS_DEMONS_RUNNING_ABOUT_THE_VILLAGE_AT_NIGHT_PILLAGING = 275,
  SFX_ID_TOWNERS_HEALER03_WAV_I_WAS_SHOCKED_WHEN_I_HEARD_OF_WHAT_THE_TOWNSPEOPLE = 276,
  SFX_ID_TOWNERS_HEALER04_WAV = 277,
  SFX_ID_TOWNERS_HEALER05_WAV_THIS_SOUNDS_LIKE_A_VERY_DANGEROUS_PLACE = 278,
  SFX_ID_TOWNERS_HEALER06_WAV = 279,
  SFX_ID_TOWNERS_HEALER07_WAV = 280,
  SFX_ID_TOWNERS_HEALER08_WAV_BY_THE_LIGHT_I_KNOW_OF_THIS_VILE_DEMON = 281,
  SFX_ID_TOWNERS_HEALER09_WAV = 282,
  SFX_ID_TOWNERS_HEALER10_WAV_THIS_DOES_SEEM_FAMILIAR_SOMEHOW = 283,
  SFX_ID_TOWNERS_HEALER11_WAV_A_GOLDEN_ELIXIR_YOU_SAY = 284,
  SFX_ID_TOWNERS_HEALER12_WAV_IF_YOU_HAD_BEEN_LOOKING_FOR_INFORMATION_ON_THE_PESTLE = 285,
  SFX_ID_TOWNERS_HEALER13_WAV_HMM = 286,
  SFX_ID_TOWNERS_HEALER14_WAV = 287,
  SFX_ID_TOWNERS_HEALER15_WAV = 288,
  SFX_ID_TOWNERS_HEALER16_WAV_CAIN_WOULD_BE_ABLE_TO_TELL_YOU_MUCH_MORE_ABOUT = 289,
  SFX_ID_TOWNERS_HEALER17_WAV = 290,
  SFX_ID_TOWNERS_HEALER18_WAV_I_DONT_KNOW_WHAT_IT_IS_THAT_THEY_THOUGHT_THEY = 291,
  SFX_ID_TOWNERS_HEALER19_WAV_I_CANT_MAKE_MUCH_OF_THE_WRITING_ON_THIS_MAP = 292,
  SFX_ID_TOWNERS_HEALER20_WAV_IM_GLAD_I_CAUGHT_UP_TO_YOU_IN_TIME = 293,
  SFX_ID_TOWNERS_HEALER21_WAV_PLEASE_YOU_MUST_HURRY = 294,
  SFX_ID_TOWNERS_HEALER22_WAV_WHATS_THAT_YOU_SAY = 295,
  SFX_ID_TOWNERS_HEALER23_WAV = 296,
  SFX_ID_TOWNERS_HEALER24_WAV = 297,
  SFX_ID_TOWNERS_HEALER25_WAV = 298,
  SFX_ID_TOWNERS_HEALER26_WAV_THE_WITCH_TOLD_ME_THAT_YOU_WERE_SEARCHING_FOR_THE = 299,
  SFX_ID_TOWNERS_HEALER27_WAV_EXCELLENT_THIS_IS_JUST_WHAT_I_HAD_IN_MIND = 300,
  SFX_ID_TOWNERS_HEALER28_WAV = 301,
  SFX_ID_TOWNERS_HEALER29_WAV = 302,
  SFX_ID_TOWNERS_HEALER30_WAV = 303,
  SFX_ID_TOWNERS_HEALER31_WAV = 304,
  SFX_ID_TOWNERS_HEALER32_WAV = 305,
  SFX_ID_TOWNERS_HEALER33_WAV = 306,
  SFX_ID_TOWNERS_HEALER34_WAV = 307,
  SFX_ID_TOWNERS_HEALER35_WAV = 308,
  SFX_ID_TOWNERS_HEALER36_WAV = 309,
  SFX_ID_TOWNERS_HEALER37_WAV_WHAT_AILS_YOU_MY_FRIEND = 310,
  SFX_ID_TOWNERS_HEALER38_WAV_I_HAVE_MADE_A_VERY_INTERESTING_DISCOVERY = 311,
  SFX_ID_TOWNERS_HEALER39_WAV_BEFORE_IT_WAS_TAKEN_OVER_BY_WELL_WHATEVER_LURKS_BELOW = 312,
  SFX_ID_TOWNERS_HEALER40_WAV_GRISWOLD_KNOWS_AS_MUCH_ABOUT_THE_ART_OF_WAR_AS = 313,
  SFX_ID_TOWNERS_HEALER41_WAV_CAIN_IS_A_TRUE_FRIEND_AND_A_WISE_SAGE = 314,
  SFX_ID_TOWNERS_HEALER42_WAV_EVEN_MY_SKILLS_HAVE_BEEN_UNABLE_TO_FULLY_HEAL_FARNHAM = 315,
  SFX_ID_TOWNERS_HEALER43_WAV_WHILE_I_USE_SOME_LIMITED_FORMS_OF_MAGIC_TO_CREATE = 316,
  SFX_ID_TOWNERS_HEALER44_WAV = 317,
  SFX_ID_TOWNERS_HEALER45_WAV_POOR_WIRT = 318,
  SFX_ID_TOWNERS_HEALER46_WAV_I_REALLY_DONT_UNDERSTAND_WHY_OGDEN_STAYS_HERE_IN_TRISTRAM = 319,
  SFX_ID_TOWNERS_HEALER47_WAV_OGDENS_BARMAID_IS_A_SWEET_GIRL = 320,
  SFX_ID_TOWNERS_PEGBOY01_WAV_LOOK_IM_RUNNING_A_BUSINESS_HERE = 321,
  SFX_ID_TOWNERS_PEGBOY02_WAV_WHAT = 322,
  SFX_ID_TOWNERS_PEGBOY03_WAV_YES_THE_RIGHTEOUS_LAZARUS_WHO_WAS_SOOO_EFFECTIVE_AGAINST_THOSE = 323,
  SFX_ID_TOWNERS_PEGBOY04_WAV_FOR_ONCE_IM_WITH_YOU = 324,
  SFX_ID_TOWNERS_PEGBOY05_WAV = 325,
  SFX_ID_TOWNERS_PEGBOY06_WAV = 326,
  SFX_ID_TOWNERS_PEGBOY07_WAV_A_VAST_AND_MYSTERIOUS_TREASURE_YOU_SAY = 327,
  SFX_ID_TOWNERS_PEGBOY08_WAV = 328,
  SFX_ID_TOWNERS_PEGBOY09_WAV = 329,
  SFX_ID_TOWNERS_PEGBOY10_WAV_I_KNOW_MORE_THAN_YOUD_THINK_ABOUT_THAT_GRISLY_FIEND = 330,
  SFX_ID_TOWNERS_PEGBOY11_WAV_LETS_SEE_AM_I_SELLING_YOU_SOMETHING = 331,
  SFX_ID_TOWNERS_PEGBOY12_WAV_WAIT_LET_ME_GUESS = 332,
  SFX_ID_TOWNERS_PEGBOY13_WAV_IF_YOU_WERE_TO_FIND_THIS_ARTIFACT_FOR_GRISWOLD_IT = 333,
  SFX_ID_TOWNERS_PEGBOY14_WAV_YOU_INTEND_TO_FIND_THE_ARMOR_KNOWN_AS_VALOR = 334,
  SFX_ID_TOWNERS_PEGBOY15_WAV = 335,
  SFX_ID_TOWNERS_PEGBOY16_WAV = 336,
  SFX_ID_TOWNERS_PEGBOY17_WAV_I_HAVENT_EVER_DEALT_WITH_THIS_WARLORD_YOU_SPEAK_OF = 337,
  SFX_ID_TOWNERS_PEGBOY18_WAV_IF_ANYONE_CAN_MAKE_SOMETHING_OUT_OF_THAT_ROCK_GRISWOLD = 338,
  SFX_ID_TOWNERS_PEGBOY19_WAV_I_DONT_HAVE_ANY_MUSHROOMS_OF_ANY_SIZE_OR_COLOR = 339,
  SFX_ID_TOWNERS_PEGBOY20_WAV_IVE_BEEN_LOOKING_FOR_A_MAP_BUT_THAT_CERTAINLY_ISNT = 340,
  SFX_ID_TOWNERS_PEGBOY21_WAV = 341,
  SFX_ID_TOWNERS_PEGBOY22_WAV = 342,
  SFX_ID_TOWNERS_PEGBOY23_WAV = 343,
  SFX_ID_TOWNERS_PEGBOY24_WAV = 344,
  SFX_ID_TOWNERS_PEGBOY25_WAV = 345,
  SFX_ID_TOWNERS_PEGBOY26_WAV = 346,
  SFX_ID_TOWNERS_PEGBOY27_WAV = 347,
  SFX_ID_TOWNERS_PEGBOY28_WAV = 348,
  SFX_ID_TOWNERS_PEGBOY29_WAV = 349,
  SFX_ID_TOWNERS_PEGBOY30_WAV = 350,
  SFX_ID_TOWNERS_PEGBOY31_WAV = 351,
  SFX_ID_TOWNERS_PEGBOY32_WAV_PSSST = 352,
  SFX_ID_TOWNERS_PEGBOY33_WAV_NOT_EVERYONE_IN_TRISTRAM_HAS_A_USE = 353,
  SFX_ID_TOWNERS_PEGBOY34_WAV_DONT_TRUST_EVERYTHING_THE_DRUNK_SAYS = 354,
  SFX_ID_TOWNERS_PEGBOY35_WAV_IN_CASE_YOU_HAVENT_NOTICED_I_DONT_BUY_ANYTHING_FROM = 355,
  SFX_ID_TOWNERS_PEGBOY36_WAV_I_GUESS_I_OWE_THE_BLACKSMITH_MY_LIFE = 356,
  SFX_ID_TOWNERS_PEGBOY37_WAV_IF_I_WERE_A_FEW_YEARS_OLDER_I_WOULD_SHOWER = 357,
  SFX_ID_TOWNERS_PEGBOY38_WAV_CAIN_KNOWS_TOO_MUCH = 358,
  SFX_ID_TOWNERS_PEGBOY39_WAV_FARNHAM = 359,
  SFX_ID_TOWNERS_PEGBOY40_WAV_AS_LONG_AS_YOU_DONT_NEED_ANYTHING_REATTACHED_OLD_PEPIN = 360,
  SFX_ID_TOWNERS_PEGBOY41_WAV = 361,
  SFX_ID_TOWNERS_PEGBOY42_WAV_ADRIA_TRULY_BOTHERS_ME = 362,
  SFX_ID_TOWNERS_PEGBOY43_WAV_OGDEN_IS_A_FOOL_FOR_STAYING_HERE = 363,
  SFX_ID_TOWNERS_PRIEST00_WAV = 364,
  SFX_ID_TOWNERS_PRIEST01_WAV = 365,
  SFX_ID_TOWNERS_PRIEST02_WAV = 366,
  SFX_ID_TOWNERS_PRIEST03_WAV = 367,
  SFX_ID_TOWNERS_PRIEST04_WAV = 368,
  SFX_ID_TOWNERS_PRIEST05_WAV = 369,
  SFX_ID_TOWNERS_PRIEST06_WAV = 370,
  SFX_ID_TOWNERS_PRIEST07_WAV = 371,
  SFX_ID_TOWNERS_STORYT00_WAV = 372,
  SFX_ID_TOWNERS_STORYT01_WAV_AHH_THE_STORY_OF_OUR_KING_IS_IT = 373,
  SFX_ID_TOWNERS_STORYT02_WAV_I_SEE_THAT_THIS_STRANGE_BEHAVIOR_PUZZLES_YOU_AS_WELL = 374,
  SFX_ID_TOWNERS_STORYT03_WAV = 375,
  SFX_ID_TOWNERS_STORYT04_WAV_HMM_I_DONT_KNOW_WHAT_I_CAN_REALLY_TELL_YOU = 376,
  SFX_ID_TOWNERS_STORYT05_WAV = 377,
  SFX_ID_TOWNERS_STORYT06_WAV = 378,
  SFX_ID_TOWNERS_STORYT07_WAV_A_BOOK_THAT_SPEAKS_OF_A_CHAMBER_OF_HUMAN_BONES = 379,
  SFX_ID_TOWNERS_STORYT08_WAV = 380,
  SFX_ID_TOWNERS_STORYT09_WAV = 381,
  SFX_ID_TOWNERS_STORYT10_WAV_IT_SEEMS_THAT_THE_ARCHBISHOP_LAZARUS_GOADED_MANY_OF_THE = 382,
  SFX_ID_TOWNERS_STORYT11_WAV = 383,
  SFX_ID_TOWNERS_STORYT12_WAV_YOU_RECITE_AN_INTERESTING_RHYME_WRITTEN_IN_A_STYLE_THAT = 384,
  SFX_ID_TOWNERS_STORYT13_WAV_YOU_CLAIM_TO_HAVE_SPOKEN_WITH_LACHDANAN = 385,
  SFX_ID_TOWNERS_STORYT14_WAV_GRISWOLD_SPEAKS_OF_THE_ANVIL_OF_FURY = 386,
  SFX_ID_TOWNERS_STORYT15_WAV_THE_GATEWAY_OF_BLOOD_AND_THE_HALLS_OF_FIRE_ARE = 387,
  SFX_ID_TOWNERS_STORYT16_WAV = 388,
  SFX_ID_TOWNERS_STORYT17_WAV = 389,
  SFX_ID_TOWNERS_STORYT18_WAV_I_KNOW_OF_ONLY_ONE_LEGEND_THAT_SPEAKS_OF_SUCH = 390,
  SFX_ID_TOWNERS_STORYT19_WAV = 391,
  SFX_ID_TOWNERS_STORYT20_WAV_GRISWOLD_SPEAKS_OF_THE_HEAVEN_STONE_THAT_WAS_DESTINED_FOR = 392,
  SFX_ID_TOWNERS_STORYT21_WAV_THE_WITCH_ADRIA_SEEKS_A_BLACK_MUSHROOM = 393,
  SFX_ID_TOWNERS_STORYT22_WAV_SO_THE_LEGEND_OF_THE_MAP_IS_REAL = 394,
  SFX_ID_TOWNERS_STORYT23_WAV_OUR_TIME_IS_RUNNING_SHORT = 395,
  SFX_ID_TOWNERS_STORYT24_WAV_I_AM_SURE_THAT_YOU_TRIED_YOUR_BEST_BUT_I = 396,
  SFX_ID_TOWNERS_STORYT25_WAV_HELLO_MY_FRIEND = 397,
  SFX_ID_TOWNERS_STORYT26_WAV_WHILE_YOU_ARE_VENTURING_DEEPER_INTO_THE_LABYRINTH_YOU_MAY = 398,
  SFX_ID_TOWNERS_STORYT27_WAV_I_KNOW_OF_MANY_MYTHS_AND_LEGENDS_THAT_MAY_CONTAIN = 399,
  SFX_ID_TOWNERS_STORYT28_WAV_GRISWOLD = 400,
  SFX_ID_TOWNERS_STORYT29_WAV_OGDEN_HAS_OWNED_AND_RUN_THE_RISING_SUN_INN_AND = 401,
  SFX_ID_TOWNERS_STORYT30_WAV_POOR_FARNHAM = 402,
  SFX_ID_TOWNERS_STORYT31_WAV_THE_WITCH_ADRIA_IS_AN_ANOMALY_HERE_IN_TRISTRAM = 403,
  SFX_ID_TOWNERS_STORYT32_WAV = 404,
  SFX_ID_TOWNERS_STORYT33_WAV_THE_STORY_OF_WIRT_IS_A_FRIGHTENING_AND_TRAGIC_ONE = 405,
  SFX_ID_TOWNERS_STORYT34_WAV_AH_PEPIN = 406,
  SFX_ID_TOWNERS_STORYT35_WAV_GILLIAN_IS_A_FINE_WOMAN = 407,
  SFX_ID_TOWNERS_STORYT36_WAV_THIS_DOES_NOT_BODE_WELL_FOR_IT_CONFIRMS_MY_DARKEST = 408,
  SFX_ID_TOWNERS_STORYT37_WAV_YOU_MUST_HURRY_AND_RESCUE_ALBRECHT_FROM_THE_HANDS_OF = 409,
  SFX_ID_TOWNERS_STORYT38_WAV_YOUR_STORY_IS_QUITE_GRIM_MY_FRIEND = 410,
  SFX_ID_TOWNERS_TAVOWN00_WAV_THANK_GOODNESS_YOUVE_RETURNED = 411,
  SFX_ID_TOWNERS_TAVOWN01_WAV_LAZARUS_WAS_THE_ARCHBISHOP_WHO_LED_MANY_OF_THE_TOWNSPEOPLE = 412,
  SFX_ID_TOWNERS_TAVOWN02_WAV_I_HAVE_ALWAYS_TRIED_TO_KEEP_A_LARGE_SUPPLY_OF = 413,
  SFX_ID_TOWNERS_TAVOWN03_WAV = 414,
  SFX_ID_TOWNERS_TAVOWN04_WAV = 415,
  SFX_ID_TOWNERS_TAVOWN05_WAV_I_AM_AFRAID_THAT_I_DONT_KNOW_ANYTHING_ABOUT_THAT = 416,
  SFX_ID_TOWNERS_TAVOWN06_WAV = 417,
  SFX_ID_TOWNERS_TAVOWN07_WAV = 418,
  SFX_ID_TOWNERS_TAVOWN08_WAV_YES_FARNHAM_HAS_MUMBLED_SOMETHING_ABOUT_A_HULKING_BRUTE_WHO = 419,
  SFX_ID_TOWNERS_TAVOWN09_WAV = 420,
  SFX_ID_TOWNERS_TAVOWN10_WAV_I_NEVER_MUCH_CARED_FOR_POETRY = 421,
  SFX_ID_TOWNERS_TAVOWN11_WAV_YOU_SPEAK_OF_A_BRAVE_WARRIOR_LONG_DEAD = 422,
  SFX_ID_TOWNERS_TAVOWN12_WAV_DONT_YOU_THINK_THAT_GRISWOLD_WOULD_BE_A_BETTER_PERSON = 423,
  SFX_ID_TOWNERS_TAVOWN13_WAV_EVERY_CHILD_HEARS_THE_STORY_OF_THE_WARRIOR_ARKAINE_AND = 424,
  SFX_ID_TOWNERS_TAVOWN14_WAV = 425,
  SFX_ID_TOWNERS_TAVOWN15_WAV = 426,
  SFX_ID_TOWNERS_TAVOWN16_WAV_I_AM_AFRAID_THAT_I_HAVENT_HEARD_ANYTHING_ABOUT_SUCH = 427,
  SFX_ID_TOWNERS_TAVOWN17_WAV = 428,
  SFX_ID_TOWNERS_TAVOWN18_WAV_THE_CARAVAN_STOPPED_HERE_TO_TAKE_ON_SOME_SUPPLIES_FOR = 429,
  SFX_ID_TOWNERS_TAVOWN19_WAV_LET_ME_JUST_SAY_THIS = 430,
  SFX_ID_TOWNERS_TAVOWN20_WAV_IF_THE_WITCH_CANT_HELP_YOU_AND_SUGGESTS_YOU_SEE = 431,
  SFX_ID_TOWNERS_TAVOWN21_WAV_THE_VILLAGE_NEEDS_YOUR_HELP_GOOD_MASTER = 432,
  SFX_ID_TOWNERS_TAVOWN22_WAV_AS_I_TOLD_YOU_GOOD_MASTER_THE_KING_WAS_ENTOMBED = 433,
  SFX_ID_TOWNERS_TAVOWN23_WAV_THE_CURSE_OF_OUR_KING_HAS_PASSED_BUT_I_FEAR = 434,
  SFX_ID_TOWNERS_TAVOWN24_WAV_MASTER_I_HAVE_A_STRANGE_EXPERIENCE_TO_RELATE = 435,
  SFX_ID_TOWNERS_TAVOWN25_WAV_OH_YOU_DIDNT_HAVE_TO_BRING_BACK_MY_SIGN_BUT = 436,
  SFX_ID_TOWNERS_TAVOWN26_WAV = 437,
  SFX_ID_TOWNERS_TAVOWN27_WAV = 438,
  SFX_ID_TOWNERS_TAVOWN28_WAV = 439,
  SFX_ID_TOWNERS_TAVOWN29_WAV = 440,
  SFX_ID_TOWNERS_TAVOWN30_WAV = 441,
  SFX_ID_TOWNERS_TAVOWN31_WAV = 442,
  SFX_ID_TOWNERS_TAVOWN32_WAV = 443,
  SFX_ID_TOWNERS_TAVOWN33_WAV = 444,
  SFX_ID_TOWNERS_TAVOWN34_WAV = 445,
  SFX_ID_TOWNERS_TAVOWN35_WAV = 446,
  SFX_ID_TOWNERS_TAVOWN36_WAV_GREETINGS_GOOD_MASTER = 447,
  SFX_ID_TOWNERS_TAVOWN37_WAV_MANY_ADVENTURERS_HAVE_GRACED_THE_TABLES_OF_MY_TAVERN_AND = 448,
  SFX_ID_TOWNERS_TAVOWN38_WAV_GRISWOLD_THE_BLACKSMITH_IS_EXTREMELY_KNOWLEDGEABLE_ABOUT_WEAPONS_AND_ARMOR = 449,
  SFX_ID_TOWNERS_TAVOWN39_WAV_FARNHAM_SPENDS_FAR_TOO_MUCH_TIME_HERE_DROWNING_HIS_SORROWS = 450,
  SFX_ID_TOWNERS_TAVOWN40_WAV_ADRIA_IS_WISE_BEYOND_HER_YEARS_BUT_I_MUST_ADMIT = 451,
  SFX_ID_TOWNERS_TAVOWN41_WAV_IF_YOU_WANT_TO_KNOW_MORE_ABOUT_THE_HISTORY_OF = 452,
  SFX_ID_TOWNERS_TAVOWN42_WAV = 453,
  SFX_ID_TOWNERS_TAVOWN43_WAV_WIRT_IS_A_RAPSCALLION_AND_A_LITTLE_SCOUNDREL = 454,
  SFX_ID_TOWNERS_TAVOWN44_WAV_PEPIN_IS_A_GOOD_MAN = 455,
  SFX_ID_TOWNERS_TAVOWN45_WAV_GILLIAN_MY_BARMAID = 456,
  SFX_ID_TOWNERS_WITCH01_WAV_THE_DEAD_WHO_WALK_AMONG_THE_LIVING_FOLLOW_THE_CURSED = 457,
  SFX_ID_TOWNERS_WITCH02_WAV_NO_MORTAL_CAN_TRULY_UNDERSTAND_THE_MIND_OF_THE_DEMON = 458,
  SFX_ID_TOWNERS_WITCH03_WAV_I_DID_NOT_KNOW_THIS_LAZARUS_OF_WHOM_YOU_SPEAK = 459,
  SFX_ID_TOWNERS_WITCH04_WAV_THE_PEOPLE_OF_TRISTRAM_WILL_DIE_IF_YOU_CANNOT_RESTORE = 460,
  SFX_ID_TOWNERS_WITCH05_WAV = 461,
  SFX_ID_TOWNERS_WITCH06_WAV = 462,
  SFX_ID_TOWNERS_WITCH07_WAV_YOU_WILL_BECOME_AN_ETERNAL_SERVANT_OF_THE_DARK_LORDS = 463,
  SFX_ID_TOWNERS_WITCH08_WAV = 464,
  SFX_ID_TOWNERS_WITCH09_WAV = 465,
  SFX_ID_TOWNERS_WITCH10_WAV_THE_BUTCHER_IS_A_SADISTIC_CREATURE_THAT_DELIGHTS_IN_THE = 466,
  SFX_ID_TOWNERS_WITCH11_WAV = 467,
  SFX_ID_TOWNERS_WITCH12_WAV_THIS_IS_A_PLACE_OF_GREAT_ANGUISH_AND_TERROR_AND = 468,
  SFX_ID_TOWNERS_WITCH13_WAV_YOU_MAY_MEET_PEOPLE_WHO_ARE_TRAPPED_WITHIN_THE_LABYRINTH = 469,
  SFX_ID_TOWNERS_WITCH14_WAV_THERE_ARE_MANY_ARTIFACTS_WITHIN_THE_LABYRINTH_THAT_HOLD_POWERS = 470,
  SFX_ID_TOWNERS_WITCH15_WAV_SHOULD_YOU_FIND_THESE_STONES_OF_BLOOD_USE_THEM_CAREFULLY = 471,
  SFX_ID_TOWNERS_WITCH16_WAV = 472,
  SFX_ID_TOWNERS_WITCH17_WAV = 473,
  SFX_ID_TOWNERS_WITCH18_WAV_HIS_PROWESS_WITH_THE_BLADE_IS_AWESOME_AND_HE_HAS = 474,
  SFX_ID_TOWNERS_WITCH19_WAV = 475,
  SFX_ID_TOWNERS_WITCH20_WAV_THE_HEAVEN_STONE_IS_VERY_POWERFUL_AND_WERE_IT_ANY = 476,
  SFX_ID_TOWNERS_WITCH21_WAV_OH_IM_AFRAID_THIS_DOES_NOT_BODE_WELL_AT_ALL = 477,
  SFX_ID_TOWNERS_WITCH22_WAV_WHAT_DO_WE_HAVE_HERE = 478,
  SFX_ID_TOWNERS_WITCH23_WAV_ITS_A_BIG_BLACK_MUSHROOM_THAT_I_NEED = 479,
  SFX_ID_TOWNERS_WITCH24_WAV_YES_THIS_WILL_BE_PERFECT_FOR_A_BREW_THAT_I = 480,
  SFX_ID_TOWNERS_WITCH25_WAV_WHY_HAVE_YOU_BROUGHT_THAT_HERE = 481,
  SFX_ID_TOWNERS_WITCH26_WAV_WHAT = 482,
  SFX_ID_TOWNERS_WITCH27_WAV = 483,
  SFX_ID_TOWNERS_WITCH28_WAV = 484,
  SFX_ID_TOWNERS_WITCH29_WAV = 485,
  SFX_ID_TOWNERS_WITCH30_WAV = 486,
  SFX_ID_TOWNERS_WITCH31_WAV = 487,
  SFX_ID_TOWNERS_WITCH32_WAV = 488,
  SFX_ID_TOWNERS_WITCH33_WAV = 489,
  SFX_ID_TOWNERS_WITCH34_WAV = 490,
  SFX_ID_TOWNERS_WITCH35_WAV = 491,
  SFX_ID_TOWNERS_WITCH36_WAV = 492,
  SFX_ID_TOWNERS_WITCH37_WAV = 493,
  SFX_ID_TOWNERS_WITCH38_WAV_I_SENSE_A_SOUL_IN_SEARCH_OF_ANSWERS = 494,
  SFX_ID_TOWNERS_WITCH39_WAV_WISDOM_IS_EARNED_NOT_GIVEN = 495,
  SFX_ID_TOWNERS_WITCH40_WAV_THE_GREATEST_POWER_IS_OFTEN_THE_SHORTEST_LIVED = 496,
  SFX_ID_TOWNERS_WITCH41_WAV_THOUGH_THE_HEAT_OF_THE_SUN_IS_BEYOND_MEASURE_THE = 497,
  SFX_ID_TOWNERS_WITCH42_WAV_THE_SUM_OF_OUR_KNOWLEDGE_IS_IN_THE_SUM_OF = 498,
  SFX_ID_TOWNERS_WITCH43_WAV_TO_A_MAN_WHO_ONLY_KNOWS_IRON_THERE_IS_NO = 499,
  SFX_ID_TOWNERS_WITCH44_WAV_CORRUPTION_HAS_THE_STRENGTH_OF_DECEIT_BUT_INNOCENCE_HOLDS_THE = 500,
  SFX_ID_TOWNERS_WITCH45_WAV_A_CHEST_OPENED_IN_DARKNESS_HOLDS_NO_GREATER_TREASURE_THAN = 501,
  SFX_ID_TOWNERS_WITCH46_WAV_THE_HIGHER_YOU_PLACE_YOUR_FAITH_IN_ONE_MAN_THE = 502,
  SFX_ID_TOWNERS_WITCH47_WAV_THE_HAND_THE_HEART_AND_THE_MIND_CAN_PERFORM_MIRACLES = 503,
  SFX_ID_TOWNERS_WITCH48_WAV = 504,
  SFX_ID_TOWNERS_WITCH49_WAV_THERE_IS_MUCH_ABOUT_THE_FUTURE_WE_CANNOT_SEE_BUT = 505,
  SFX_ID_TOWNERS_WITCH50_WAV_EARTHEN_WALLS_AND_THATCHED_CANOPY_DO_NOT_A_HOME_CREATE = 506,
  SFX_ID_TOWNERS_WOUND01_WAV_PLEASE_LISTEN_TO_ME = 507,
  SFX_ID_SORCEROR_MAGE01_WAV_BEYOND_THE_HALL_OF_HEROES_LIES_THE_CHAMBER_OF_BONE = 508,
  SFX_ID_SORCEROR_MAGE02_WAV = 509,
  SFX_ID_SORCEROR_MAGE03_WAV = 510,
  SFX_ID_SORCEROR_MAGE04_WAV = 511,
  SFX_ID_SORCEROR_MAGE05_WAV = 512,
  SFX_ID_SORCEROR_MAGE06_WAV = 513,
  SFX_ID_SORCEROR_MAGE07_WAV = 514,
  SFX_ID_SORCEROR_MAGE08_WAV = 515,
  SFX_ID_SORCEROR_MAGE09_WAV = 516,
  SFX_ID_SORCEROR_MAGE10_WAV = 517,
  SFX_ID_SORCEROR_MAGE11_WAV_I_CAN_SEE_WHAT_YOU_SEE_NOT = 518,
  SFX_ID_SORCEROR_MAGE12_WAV_THE_ARMORIES_OF_HELL_ARE_HOME_TO_THE_WARLORD_OF = 519,
  SFX_ID_SORCEROR_MAGE13_WAV = 520,
  SFX_ID_SORCEROR_MAGE14_WAV = 521,
  SFX_ID_SORCEROR_MAGE15_WAV = 522,
  SFX_ID_SORCEROR_MAGE16_WAV = 523,
  SFX_ID_SORCEROR_MAGE17_WAV = 524,
  SFX_ID_SORCEROR_MAGE18_WAV = 525,
  SFX_ID_SORCEROR_MAGE19_WAV = 526,
  SFX_ID_SORCEROR_MAGE20_WAV = 527,
  SFX_ID_SORCEROR_MAGE21_WAV = 528,
  SFX_ID_SORCEROR_MAGE22_WAV = 529,
  SFX_ID_SORCEROR_MAGE23_WAV = 530,
  SFX_ID_SORCEROR_MAGE24_WAV = 531,
  SFX_ID_SORCEROR_MAGE25_WAV = 532,
  SFX_ID_SORCEROR_MAGE26_WAV = 533,
  SFX_ID_SORCEROR_MAGE27_WAV = 534,
  SFX_ID_SORCEROR_MAGE28_WAV = 535,
  SFX_ID_SORCEROR_MAGE29_WAV = 536,
  SFX_ID_SORCEROR_MAGE30_WAV = 537,
  SFX_ID_SORCEROR_MAGE31_WAV = 538,
  SFX_ID_SORCEROR_MAGE32_WAV = 539,
  SFX_ID_SORCEROR_MAGE33_WAV = 540,
  SFX_ID_SORCEROR_MAGE34_WAV = 541,
  SFX_ID_SORCEROR_MAGE35_WAV = 542,
  SFX_ID_SORCEROR_MAGE36_WAV = 543,
  SFX_ID_SORCEROR_MAGE37_WAV = 544,
  SFX_ID_SORCEROR_MAGE38_WAV = 545,
  SFX_ID_SORCEROR_MAGE39_WAV = 546,
  SFX_ID_SORCEROR_MAGE40_WAV = 547,
  SFX_ID_SORCEROR_MAGE41_WAV = 548,
  SFX_ID_SORCEROR_MAGE42_WAV = 549,
  SFX_ID_SORCEROR_MAGE43_WAV = 550,
  SFX_ID_SORCEROR_MAGE44_WAV = 551,
  SFX_ID_SORCEROR_MAGE45_WAV = 552,
  SFX_ID_SORCEROR_MAGE46_WAV = 553,
  SFX_ID_SORCEROR_MAGE47_WAV = 554,
  SFX_ID_SORCEROR_MAGE48_WAV = 555,
  SFX_ID_SORCEROR_MAGE49_WAV = 556,
  SFX_ID_SORCEROR_MAGE50_WAV = 557,
  SFX_ID_SORCEROR_MAGE51_WAV = 558,
  SFX_ID_SORCEROR_MAGE52_WAV = 559,
  SFX_ID_SORCEROR_MAGE53_WAV = 560,
  SFX_ID_SORCEROR_MAGE54_WAV = 561,
  SFX_ID_SORCEROR_MAGE55_WAV = 562,
  SFX_ID_SORCEROR_MAGE56_WAV = 563,
  SFX_ID_SORCEROR_MAGE57_WAV = 564,
  SFX_ID_SORCEROR_MAGE58_WAV = 565,
  SFX_ID_SORCEROR_MAGE59_WAV = 566,
  SFX_ID_SORCEROR_MAGE60_WAV = 567,
  SFX_ID_SORCEROR_MAGE61_WAV = 568,
  SFX_ID_SORCEROR_MAGE62_WAV = 569,
  SFX_ID_SORCEROR_MAGE63_WAV = 570,
  SFX_ID_SORCEROR_MAGE64_WAV = 571,
  SFX_ID_SORCEROR_MAGE65_WAV = 572,
  SFX_ID_SORCEROR_MAGE66_WAV = 573,
  SFX_ID_SORCEROR_MAGE67_WAV = 574,
  SFX_ID_SORCEROR_MAGE68_WAV = 575,
  SFX_ID_SORCEROR_MAGE69_WAV = 576,
  SFX_ID_SORCEROR_MAGE69B_WAV = 577,
  SFX_ID_SORCEROR_MAGE70_WAV = 578,
  SFX_ID_SORCEROR_MAGE71_WAV = 579,
  SFX_ID_SORCEROR_MAGE72_WAV = 580,
  SFX_ID_SORCEROR_MAGE73_WAV = 581,
  SFX_ID_SORCEROR_MAGE74_WAV = 582,
  SFX_ID_SORCEROR_MAGE75_WAV = 583,
  SFX_ID_SORCEROR_MAGE76_WAV = 584,
  SFX_ID_SORCEROR_MAGE77_WAV = 585,
  SFX_ID_SORCEROR_MAGE78_WAV = 586,
  SFX_ID_SORCEROR_MAGE79_WAV = 587,
  SFX_ID_SORCEROR_MAGE80_WAV = 588,
  SFX_ID_SORCEROR_MAGE81_WAV = 589,
  SFX_ID_SORCEROR_MAGE82_WAV = 590,
  SFX_ID_SORCEROR_MAGE83_WAV = 591,
  SFX_ID_SORCEROR_MAGE84_WAV = 592,
  SFX_ID_SORCEROR_MAGE85_WAV = 593,
  SFX_ID_SORCEROR_MAGE86_WAV = 594,
  SFX_ID_SORCEROR_MAGE87_WAV = 595,
  SFX_ID_SORCEROR_MAGE88_WAV = 596,
  SFX_ID_SORCEROR_MAGE89_WAV = 597,
  SFX_ID_SORCEROR_MAGE90_WAV = 598,
  SFX_ID_SORCEROR_MAGE91_WAV = 599,
  SFX_ID_SORCEROR_MAGE92_WAV = 600,
  SFX_ID_SORCEROR_MAGE93_WAV = 601,
  SFX_ID_SORCEROR_MAGE94_WAV = 602,
  SFX_ID_SORCEROR_MAGE95_WAV = 603,
  SFX_ID_SORCEROR_MAGE96_WAV = 604,
  SFX_ID_SORCEROR_MAGE97_WAV = 605,
  SFX_ID_SORCEROR_MAGE98_WAV = 606,
  SFX_ID_SORCEROR_MAGE99_WAV = 607,
  SFX_ID_SORCEROR_MAGE100_WAV = 608,
  SFX_ID_SORCEROR_MAGE101_WAV = 609,
  SFX_ID_SORCEROR_MAGE102_WAV = 610,
  SFX_ID_ROGUE_ROGUE01_WAV_BEYOND_THE_HALL_OF_HEROES_LIES_THE_CHAMBER_OF_BONE = 611,
  SFX_ID_ROGUE_ROGUE02_WAV = 612,
  SFX_ID_ROGUE_ROGUE03_WAV = 613,
  SFX_ID_ROGUE_ROGUE04_WAV = 614,
  SFX_ID_ROGUE_ROGUE05_WAV = 615,
  SFX_ID_ROGUE_ROGUE06_WAV = 616,
  SFX_ID_ROGUE_ROGUE07_WAV = 617,
  SFX_ID_ROGUE_ROGUE08_WAV = 618,
  SFX_ID_ROGUE_ROGUE09_WAV = 619,
  SFX_ID_ROGUE_ROGUE10_WAV = 620,
  SFX_ID_ROGUE_ROGUE11_WAV_I_CAN_SEE_WHAT_YOU_SEE_NOT = 621,
  SFX_ID_ROGUE_ROGUE12_WAV_THE_ARMORIES_OF_HELL_ARE_HOME_TO_THE_WARLORD_OF = 622,
  SFX_ID_ROGUE_ROGUE13_WAV = 623,
  SFX_ID_ROGUE_ROGUE14_WAV = 624,
  SFX_ID_ROGUE_ROGUE15_WAV = 625,
  SFX_ID_ROGUE_ROGUE16_WAV = 626,
  SFX_ID_ROGUE_ROGUE17_WAV = 627,
  SFX_ID_ROGUE_ROGUE18_WAV = 628,
  SFX_ID_ROGUE_ROGUE19_WAV = 629,
  SFX_ID_ROGUE_ROGUE20_WAV = 630,
  SFX_ID_ROGUE_ROGUE21_WAV = 631,
  SFX_ID_ROGUE_ROGUE22_WAV = 632,
  SFX_ID_ROGUE_ROGUE23_WAV = 633,
  SFX_ID_ROGUE_ROGUE24_WAV = 634,
  SFX_ID_ROGUE_ROGUE25_WAV = 635,
  SFX_ID_ROGUE_ROGUE26_WAV = 636,
  SFX_ID_ROGUE_ROGUE27_WAV = 637,
  SFX_ID_ROGUE_ROGUE28_WAV = 638,
  SFX_ID_ROGUE_ROGUE29_WAV = 639,
  SFX_ID_ROGUE_ROGUE30_WAV = 640,
  SFX_ID_ROGUE_ROGUE31_WAV = 641,
  SFX_ID_ROGUE_ROGUE32_WAV = 642,
  SFX_ID_ROGUE_ROGUE33_WAV = 643,
  SFX_ID_ROGUE_ROGUE34_WAV = 644,
  SFX_ID_ROGUE_ROGUE35_WAV = 645,
  SFX_ID_ROGUE_ROGUE36_WAV = 646,
  SFX_ID_ROGUE_ROGUE37_WAV = 647,
  SFX_ID_ROGUE_ROGUE38_WAV = 648,
  SFX_ID_ROGUE_ROGUE39_WAV = 649,
  SFX_ID_ROGUE_ROGUE40_WAV = 650,
  SFX_ID_ROGUE_ROGUE41_WAV = 651,
  SFX_ID_ROGUE_ROGUE42_WAV = 652,
  SFX_ID_ROGUE_ROGUE43_WAV = 653,
  SFX_ID_ROGUE_ROGUE44_WAV = 654,
  SFX_ID_ROGUE_ROGUE45_WAV = 655,
  SFX_ID_ROGUE_ROGUE46_WAV = 656,
  SFX_ID_ROGUE_ROGUE47_WAV = 657,
  SFX_ID_ROGUE_ROGUE48_WAV = 658,
  SFX_ID_ROGUE_ROGUE49_WAV = 659,
  SFX_ID_ROGUE_ROGUE50_WAV = 660,
  SFX_ID_ROGUE_ROGUE51_WAV = 661,
  SFX_ID_ROGUE_ROGUE52_WAV = 662,
  SFX_ID_ROGUE_ROGUE53_WAV = 663,
  SFX_ID_ROGUE_ROGUE54_WAV = 664,
  SFX_ID_ROGUE_ROGUE55_WAV = 665,
  SFX_ID_ROGUE_ROGUE56_WAV = 666,
  SFX_ID_ROGUE_ROGUE57_WAV = 667,
  SFX_ID_ROGUE_ROGUE58_WAV = 668,
  SFX_ID_ROGUE_ROGUE59_WAV = 669,
  SFX_ID_ROGUE_ROGUE60_WAV = 670,
  SFX_ID_ROGUE_ROGUE61_WAV = 671,
  SFX_ID_ROGUE_ROGUE62_WAV = 672,
  SFX_ID_ROGUE_ROGUE63_WAV = 673,
  SFX_ID_ROGUE_ROGUE64_WAV = 674,
  SFX_ID_ROGUE_ROGUE65_WAV = 675,
  SFX_ID_ROGUE_ROGUE66_WAV = 676,
  SFX_ID_ROGUE_ROGUE67_WAV = 677,
  SFX_ID_ROGUE_ROGUE68_WAV = 678,
  SFX_ID_ROGUE_ROGUE69_WAV = 679,
  SFX_ID_ROGUE_ROGUE69B_WAV = 680,
  SFX_ID_ROGUE_ROGUE70_WAV = 681,
  SFX_ID_ROGUE_ROGUE71_WAV = 682,
  SFX_ID_ROGUE_ROGUE72_WAV = 683,
  SFX_ID_ROGUE_ROGUE73_WAV = 684,
  SFX_ID_ROGUE_ROGUE74_WAV = 685,
  SFX_ID_ROGUE_ROGUE75_WAV = 686,
  SFX_ID_ROGUE_ROGUE76_WAV = 687,
  SFX_ID_ROGUE_ROGUE77_WAV = 688,
  SFX_ID_ROGUE_ROGUE78_WAV = 689,
  SFX_ID_ROGUE_ROGUE79_WAV = 690,
  SFX_ID_ROGUE_ROGUE80_WAV = 691,
  SFX_ID_ROGUE_ROGUE81_WAV = 692,
  SFX_ID_ROGUE_ROGUE82_WAV = 693,
  SFX_ID_ROGUE_ROGUE83_WAV = 694,
  SFX_ID_ROGUE_ROGUE84_WAV = 695,
  SFX_ID_ROGUE_ROGUE85_WAV = 696,
  SFX_ID_ROGUE_ROGUE86_WAV = 697,
  SFX_ID_ROGUE_ROGUE87_WAV = 698,
  SFX_ID_ROGUE_ROGUE88_WAV = 699,
  SFX_ID_ROGUE_ROGUE89_WAV = 700,
  SFX_ID_ROGUE_ROGUE90_WAV = 701,
  SFX_ID_ROGUE_ROGUE91_WAV = 702,
  SFX_ID_ROGUE_ROGUE92_WAV = 703,
  SFX_ID_ROGUE_ROGUE93_WAV = 704,
  SFX_ID_ROGUE_ROGUE94_WAV = 705,
  SFX_ID_ROGUE_ROGUE95_WAV = 706,
  SFX_ID_ROGUE_ROGUE96_WAV = 707,
  SFX_ID_ROGUE_ROGUE97_WAV = 708,
  SFX_ID_ROGUE_ROGUE98_WAV = 709,
  SFX_ID_ROGUE_ROGUE99_WAV = 710,
  SFX_ID_ROGUE_ROGUE100_WAV = 711,
  SFX_ID_ROGUE_ROGUE101_WAV = 712,
  SFX_ID_ROGUE_ROGUE102_WAV = 713,
  SFX_ID_WARRIOR_WARIOR01_WAV_BEYOND_THE_HALL_OF_HEROES_LIES_THE_CHAMBER_OF_BONE = 714,
  SFX_ID_WARRIOR_WARIOR02_WAV = 715,
  SFX_ID_WARRIOR_WARIOR03_WAV = 716,
  SFX_ID_WARRIOR_WARIOR04_WAV = 717,
  SFX_ID_WARRIOR_WARIOR05_WAV = 718,
  SFX_ID_WARRIOR_WARIOR06_WAV = 719,
  SFX_ID_WARRIOR_WARIOR07_WAV = 720,
  SFX_ID_WARRIOR_WARIOR08_WAV = 721,
  SFX_ID_WARRIOR_WARIOR09_WAV = 722,
  SFX_ID_WARRIOR_WARIOR10_WAV = 723,
  SFX_ID_WARRIOR_WARIOR11_WAV_I_CAN_SEE_WHAT_YOU_SEE_NOT = 724,
  SFX_ID_WARRIOR_WARIOR12_WAV_THE_ARMORIES_OF_HELL_ARE_HOME_TO_THE_WARLORD_OF = 725,
  SFX_ID_WARRIOR_WARIOR13_WAV = 726,
  SFX_ID_WARRIOR_WARIOR14_WAV = 727,
  SFX_ID_WARRIOR_WARIO14B_WAV = 728,
  SFX_ID_WARRIOR_WARIO14C_WAV = 729,
  SFX_ID_WARRIOR_WARIOR15_WAV = 730,
  SFX_ID_WARRIOR_WARIO15B_WAV = 731,
  SFX_ID_WARRIOR_WARIO15C_WAV = 732,
  SFX_ID_WARRIOR_WARIOR16_WAV = 733,
  SFX_ID_WARRIOR_WARIO16B_WAV = 734,
  SFX_ID_WARRIOR_WARIO16C_WAV = 735,
  SFX_ID_WARRIOR_WARIOR17_WAV = 736,
  SFX_ID_WARRIOR_WARIOR18_WAV = 737,
  SFX_ID_WARRIOR_WARIOR19_WAV = 738,
  SFX_ID_WARRIOR_WARIOR20_WAV = 739,
  SFX_ID_WARRIOR_WARIOR21_WAV = 740,
  SFX_ID_WARRIOR_WARIOR22_WAV = 741,
  SFX_ID_WARRIOR_WARIOR23_WAV = 742,
  SFX_ID_WARRIOR_WARIOR24_WAV = 743,
  SFX_ID_WARRIOR_WARIOR25_WAV = 744,
  SFX_ID_WARRIOR_WARIOR26_WAV = 745,
  SFX_ID_WARRIOR_WARIOR27_WAV = 746,
  SFX_ID_WARRIOR_WARIOR28_WAV = 747,
  SFX_ID_WARRIOR_WARIOR29_WAV = 748,
  SFX_ID_WARRIOR_WARIOR30_WAV = 749,
  SFX_ID_WARRIOR_WARIOR31_WAV = 750,
  SFX_ID_WARRIOR_WARIOR32_WAV = 751,
  SFX_ID_WARRIOR_WARIOR33_WAV = 752,
  SFX_ID_WARRIOR_WARIOR34_WAV = 753,
  SFX_ID_WARRIOR_WARIOR35_WAV = 754,
  SFX_ID_WARRIOR_WARIOR36_WAV = 755,
  SFX_ID_WARRIOR_WARIOR37_WAV = 756,
  SFX_ID_WARRIOR_WARIOR38_WAV = 757,
  SFX_ID_WARRIOR_WARIOR39_WAV = 758,
  SFX_ID_WARRIOR_WARIOR40_WAV = 759,
  SFX_ID_WARRIOR_WARIOR41_WAV = 760,
  SFX_ID_WARRIOR_WARIOR42_WAV = 761,
  SFX_ID_WARRIOR_WARIOR43_WAV = 762,
  SFX_ID_WARRIOR_WARIOR44_WAV = 763,
  SFX_ID_WARRIOR_WARIOR45_WAV = 764,
  SFX_ID_WARRIOR_WARIOR46_WAV = 765,
  SFX_ID_WARRIOR_WARIOR47_WAV = 766,
  SFX_ID_WARRIOR_WARIOR48_WAV = 767,
  SFX_ID_WARRIOR_WARIOR49_WAV = 768,
  SFX_ID_WARRIOR_WARIOR50_WAV = 769,
  SFX_ID_WARRIOR_WARIOR51_WAV = 770,
  SFX_ID_WARRIOR_WARIOR52_WAV = 771,
  SFX_ID_WARRIOR_WARIOR53_WAV = 772,
  SFX_ID_WARRIOR_WARIOR54_WAV = 773,
  SFX_ID_WARRIOR_WARIOR55_WAV = 774,
  SFX_ID_WARRIOR_WARIOR56_WAV = 775,
  SFX_ID_WARRIOR_WARIOR57_WAV = 776,
  SFX_ID_WARRIOR_WARIOR58_WAV = 777,
  SFX_ID_WARRIOR_WARIOR59_WAV = 778,
  SFX_ID_WARRIOR_WARIOR60_WAV = 779,
  SFX_ID_WARRIOR_WARIOR61_WAV = 780,
  SFX_ID_WARRIOR_WARIOR62_WAV = 781,
  SFX_ID_WARRIOR_WARIOR63_WAV = 782,
  SFX_ID_WARRIOR_WARIOR64_WAV = 783,
  SFX_ID_WARRIOR_WARIOR65_WAV = 784,
  SFX_ID_WARRIOR_WARIOR66_WAV = 785,
  SFX_ID_WARRIOR_WARIOR67_WAV = 786,
  SFX_ID_WARRIOR_WARIOR68_WAV = 787,
  SFX_ID_WARRIOR_WARIOR69_WAV = 788,
  SFX_ID_WARRIOR_WARIO69B_WAV = 789,
  SFX_ID_WARRIOR_WARIOR70_WAV = 790,
  SFX_ID_WARRIOR_WARIOR71_WAV = 791,
  SFX_ID_WARRIOR_WARIOR72_WAV = 792,
  SFX_ID_WARRIOR_WARIOR73_WAV = 793,
  SFX_ID_WARRIOR_WARIOR74_WAV = 794,
  SFX_ID_WARRIOR_WARIOR75_WAV = 795,
  SFX_ID_WARRIOR_WARIOR76_WAV = 796,
  SFX_ID_WARRIOR_WARIOR77_WAV = 797,
  SFX_ID_WARRIOR_WARIOR78_WAV = 798,
  SFX_ID_WARRIOR_WARIOR79_WAV = 799,
  SFX_ID_WARRIOR_WARIOR80_WAV = 800,
  SFX_ID_WARRIOR_WARIOR81_WAV = 801,
  SFX_ID_WARRIOR_WARIOR82_WAV = 802,
  SFX_ID_WARRIOR_WARIOR83_WAV = 803,
  SFX_ID_WARRIOR_WARIOR84_WAV = 804,
  SFX_ID_WARRIOR_WARIOR85_WAV = 805,
  SFX_ID_WARRIOR_WARIOR86_WAV = 806,
  SFX_ID_WARRIOR_WARIOR87_WAV = 807,
  SFX_ID_WARRIOR_WARIOR88_WAV = 808,
  SFX_ID_WARRIOR_WARIOR89_WAV = 809,
  SFX_ID_WARRIOR_WARIOR90_WAV = 810,
  SFX_ID_WARRIOR_WARIOR91_WAV = 811,
  SFX_ID_WARRIOR_WARIOR92_WAV = 812,
  SFX_ID_WARRIOR_WARIOR93_WAV = 813,
  SFX_ID_WARRIOR_WARIOR94_WAV = 814,
  SFX_ID_WARRIOR_WARIOR95_WAV = 815,
  SFX_ID_WARRIOR_WARIO95B_WAV = 816,
  SFX_ID_WARRIOR_WARIO95C_WAV = 817,
  SFX_ID_WARRIOR_WARIO95D_WAV = 818,
  SFX_ID_WARRIOR_WARIO95E_WAV = 819,
  SFX_ID_WARRIOR_WARIO95F_WAV = 820,
  SFX_ID_WARRIOR_WARIO96B_WAV = 821,
  SFX_ID_WARRIOR_WARIO97_WAV = 822,
  SFX_ID_WARRIOR_WARIO98_WAV = 823,
  SFX_ID_WARRIOR_WARIOR99_WAV = 824,
  SFX_ID_WARRIOR_WARIO100_WAV = 825,
  SFX_ID_WARRIOR_WARIO101_WAV = 826,
  SFX_ID_WARRIOR_WARIO102_WAV = 827,
  SFX_ID_NARRATOR_NAR01_WAV_TAKE_HEED_AND_BEAR_WITNESS_TO_THE_TRUTHS_THAT_LIE = 828,
  SFX_ID_NARRATOR_NAR02_WAV_TAKE_HEED_AND_BEAR_WITNESS_TO_THE_TRUTHS_THAT_LIE = 829,
  SFX_ID_NARRATOR_NAR03_WAV_TAKE_HEED_AND_BEAR_WITNESS_TO_THE_TRUTHS_THAT_LIE = 830,
  SFX_ID_NARRATOR_NAR04_WAV_SO_IT_CAME_TO_BE_THAT_THERE_WAS_A_GREAT = 831,
  SFX_ID_NARRATOR_NAR05_WAV_MANY_DEMONS_TRAVELED_TO_THE_MORTAL_REALM_IN_SEARCH_OF = 832,
  SFX_ID_NARRATOR_NAR06_WAV_SO_IT_CAME_TO_BE_THAT_THE_THREE_PRIME_EVILS = 833,
  SFX_ID_NARRATOR_NAR07_WAV_ALL_PRAISES_TO_DIABLO = 834,
  SFX_ID_NARRATOR_NAR08_WAV_GLORY_AND_APPROBATION_TO_DIABLO = 835,
  SFX_ID_NARRATOR_NAR09_WAV_HAIL_AND_SACRIFICE_TO_DIABLO = 836,
  SFX_ID_MISC_LVL16INT_WAV = 837,
  SFX_ID_MONSTERS_BUTCHER_WAV = 838,
  SFX_ID_MONSTERS_GARBUD01_WAV_PLEEEEASE_NO_HURT = 839,
  SFX_ID_MONSTERS_GARBUD02_WAV_SOMETHING_FOR_YOU_I_AM_MAKING = 840,
  SFX_ID_MONSTERS_GARBUD03_WAV_NOTHING_YET = 841,
  SFX_ID_MONSTERS_GARBUD04_WAV_THIS_TOO_GOOD_FOR_YOU = 842,
  SFX_ID_MONSTERS_IZUAL01_WAV = 843,
  SFX_ID_MONSTERS_LACH01_WAV_PLEASE_DONT_KILL_ME_JUST_HEAR_ME_OUT = 844,
  SFX_ID_MONSTERS_LACH02_WAV_YOU_HAVE_NOT_FOUND_THE_GOLDEN_ELIXIR = 845,
  SFX_ID_MONSTERS_LACH03_WAV_YOU_HAVE_SAVED_MY_SOUL_FROM_DAMNATION_AND_FOR_THAT = 846,
  SFX_ID_MONSTERS_LAZ01_WAV_ABANDON_YOUR_FOOLISH_QUEST = 847,
  SFX_ID_MONSTERS_LAZ02_WAV = 848,
  SFX_ID_MONSTERS_SKING01_WAV_THE_WARMTH_OF_LIFE_HAS_ENTERED_MY_TOMB = 849,
  SFX_ID_MONSTERS_SNOT01_WAV_HEY = 850,
  SFX_ID_MONSTERS_SNOT02_WAV_YOU_KILL_UGLIES_GET_BANNER = 851,
  SFX_ID_MONSTERS_SNOT03_WAV_YOU_GIVE = 852,
  SFX_ID_MONSTERS_WARLRD01_WAV_MY_BLADE_SINGS_FOR_YOUR_BLOOD_MORTAL_AND_BY_MY = 853,
  SFX_ID_MONSTERS_WLOCK01_WAV = 854,
  SFX_ID_MONSTERS_ZHAR01_WAV_WHAT = 855,
  SFX_ID_MONSTERS_ZHAR02_WAV_ARRRRGH = 856,
  SFX_ID_MONSTERS_DIABLOD_WAV = 857,
  SFX_ID_INVALID = -1,
};

typedef enum sfx_id sfx_id;


/* 237 */
struct SpeechData
{
  char *text;
  bool32_t display_text;
  int speed;
  sfx_id sfx_id;
};

typedef struct SpeechData SpeechData;


/* 238 */
struct MissileGraphicData
{
  BYTE gap0[1];
  int8_t nanims;
  char *cl2_name;
  uint32_t flags;
  void *cl2_from_orientation[16];
  int8_t something1_from_orientation[16];
  int8_t something2_from_orientation[16];
  int frame_width_from_orientation[16];
  int something4_from_orientation[16];
};

typedef struct MissileGraphicData MissileGraphicData;


/* 453 */
enum missile_graphic_id
{
  MISSILE_GRAPHIC_ID_ARROW = 0,
  MISSILE_GRAPHIC_ID_FIRE_BALL = 1,
  MISSILE_GRAPHIC_ID_GUARDIAN = 2,
  MISSILE_GRAPHIC_ID_LIGHTNING = 3,
  MISSILE_GRAPHIC_ID_FIRE_WALL = 4,
  MISSILE_GRAPHIC_ID_MAGIC_BLOSSOM = 5,
  MISSILE_GRAPHIC_ID_PORTAL = 6,
  MISSILE_GRAPHIC_ID_BLUE_EXPLOSION_FRONT = 7,
  MISSILE_GRAPHIC_ID_BLUE_EXPLOSION_BACK = 8,
  MISSILE_GRAPHIC_ID_MANA_SHIELD = 9,
  MISSILE_GRAPHIC_ID_BLOOD = 10,
  MISSILE_GRAPHIC_ID_BONE = 11,
  MISSILE_GRAPHIC_ID_METAL_HIT = 12,
  MISSILE_GRAPHIC_ID_FIRE_ARROW = 13,
  MISSILE_GRAPHIC_ID_DOOM_SERPENT = 14,
  MISSILE_GRAPHIC_ID_SPACE = 15,
  MISSILE_GRAPHIC_ID_BLOOD_BURST = 16,
  MISSILE_GRAPHIC_ID_EXPLOSION = 17,
  MISSILE_GRAPHIC_ID_SHATTER = 18,
  MISSILE_GRAPHIC_ID_BIG_EXPLOSION = 19,
  MISSILE_GRAPHIC_ID_INFERNO = 20,
  MISSILE_GRAPHIC_ID_THIN_LIGHTNING = 21,
  MISSILE_GRAPHIC_ID_FLARE = 22,
  MISSILE_GRAPHIC_ID_FLARE_EXPLOSION = 23,
  MISSILE_GRAPHIC_ID_MAGIC_BALL = 24,
  MISSILE_GRAPHIC_ID_KRULL = 25,
  MISSILE_GRAPHIC_ID_MINI_LIGHTNING = 26,
  MISSILE_GRAPHIC_ID_HOLY_BOLT = 27,
  MISSILE_GRAPHIC_ID_HOLY_EXPLOSION = 28,
  MISSILE_GRAPHIC_ID_LIGHTNING_ARROW = 29,
  MISSILE_GRAPHIC_ID_FIRE_ARROW_EXPLOSION = 30,
  MISSILE_GRAPHIC_ID_ACID_BALL = 31,
  MISSILE_GRAPHIC_ID_ACID_SPLASH = 32,
  MISSILE_GRAPHIC_ID_ACID_PUDDLE = 33,
  MISSILE_GRAPHIC_ID_ETHEREAL_SHIELD = 34,
  MISSILE_GRAPHIC_ID_ELEMENTAL = 35,
  MISSILE_GRAPHIC_ID_RESURRECT = 36,
  MISSILE_GRAPHIC_ID_SKULL_BALL = 37,
  MISSILE_GRAPHIC_ID_RED_PORTAL = 38,
  MISSILE_GRAPHIC_ID_FIRE_PILLAR = 39,
  MISSILE_GRAPHIC_ID_BLUE_FLARE = 40,
  MISSILE_GRAPHIC_ID_BLUE_FLARE_EXPLOSION = 41,
  MISSILE_GRAPHIC_ID_YELLOW_FLARE = 42,
  MISSILE_GRAPHIC_ID_YELLOW_FLARE_EXPLOSION = 43,
  MISSILE_GRAPHIC_ID_RED_FLARE = 44,
  MISSILE_GRAPHIC_ID_RED_FLARE_EXPLOSION = 45,
  MISSILE_GRAPHIC_ID_NULL = 46,
  MISSILE_GRAPHIC_ID_INVALID = -1,
};

typedef enum missile_graphic_id missile_graphic_id;


/* 239 */
struct Missile
{
  int missile_id;
  int col;
  int row;
  int field_C;
  int field_10;
  int field_14;
  int field_18;
  int field_1C;
  int field_20;
  int field_24;
  int field_28;
  int direction_and_orientation_something;
  int field_30;
  bool32_t inactive;
  missile_graphic_id missile_graphic_id;
  int field_3C;
  int field_40;
  int field_44;
  int field_48;
  int frame_width;
  int field_50;
  int field_54;
  int field_58;
  int cur_frame;
  bool32_t missile_data_field_C;
  int field_64;
  int field_68;
  int field_6C;
  int ticks_left;
  int caster_num;
  int field_78;
  int field_7C;
  int field_80;
  int field_84;
  int missile_lighting_num;
  int field_8C;
  int var1;
  int var2;
  int field_98;
  int field_9C;
  int field_A0;
  int field_A4;
  int field_A8;
  int field_AC;
};

typedef struct Missile Missile;


/* 454 */
enum damage_type
{
  DAMAGE_TYPE_NONE = 0,
  DAMAGE_TYPE_FIRE = 1,
  DAMAGE_TYPE_LIGHTNING = 2,
  DAMAGE_TYPE_MAGIC = 3,
  DAMAGE_TYPE_ACID = 4,
};

typedef enum damage_type damage_type;


/* 240 */
struct MissileData
{
  int missile_id;
  void (__fastcall *cast_func)(int missile_num, int col, int row, int target_col, int target_row, int facing, int target_num, int caster_num, int damage);
  void (__fastcall *impact_func)(int missile_num);
  bool32_t field_C;
  char field_10;
  int8_t damage_type; // damage_type
  int8_t missile_graphic_id; // missile_graphic_id
  char reserved_0013;
  sfx_id cast_sfx_id;
  sfx_id impact_sfx_id;
};

typedef struct MissileData MissileData;


/* 241 */
struct Monster
{
  int monster_type_num;
  int mode;
  char field_8;
  int field_C;
  BYTE gap10[16];
  int col;
  int row;
  int col_new;
  int row_new;
  int field_30;
  int field_34;
  int field_38;
  int field_3C;
  int field_40;
  int field_44;
  direction direction;
  int target_num;
  int8_t target_col_new;
  int8_t target_row_new;
  void *cur_cl2_buf;
  BYTE gap58[4];
  int field_5C;
  int last_frame;
  int cur_frame;
  BYTE gap68[4];
  int field_6C;
  int monster_var1;
  int monster_var2;
  int monster_var3;
  int monster_var4;
  int monster_var5;
  int monster_var6;
  int monster_var7;
  int monster_var8;
  int field_90;
  int hp_cur;
  int8_t monster_AI_id;
  int8_t intelligence_factor;
  uint32_t flags;
  char activity_threshold;
  BYTE gapA1[7];
  int field_A8;
  int field_AC;
  int field_B0;
  int32_t seed;
  BYTE gapB8[4];
  int8_t unique_monster_id_plus_1;
  char field_BD;
  char field_BE;
  uint8_t player_num_bitfield;
  int8_t monster_lvl;
  char field_C4;
  char field_C5;
  char field_C6;
  BYTE gapC7[3];
  char field_CA;
  __int16 field_CC;
  int speech_id;
  char field_D4;
  char field_D5;
  char field_D6;
  int8_t field_D7;
  char *name;
  struct MonsterType *monster_type;
  MonsterData *monster_data;
};

typedef struct Monster Monster;


/* 242 */
enum MACRO_VK_KANJI
{
  VK_KANJI = 0x19,
  VK_ESCAPE = 0x1B,
  VK_CONVERT = 0x1C,
  VK_NONCONVERT = 0x1D,
  VK_ACCEPT = 0x1E,
  VK_MODECHANGE = 0x1F,
  VK_SPACE = 0x20,
  VK_PRIOR = 0x21,
  VK_NEXT = 0x22,
  VK_END = 0x23,
  VK_HOME = 0x24,
  VK_LEFT = 0x25,
  VK_UP = 0x26,
  VK_RIGHT = 0x27,
  VK_DOWN = 0x28,
  VK_SELECT = 0x29,
  VK_PRINT = 0x2A,
  VK_EXECUTE = 0x2B,
  VK_SNAPSHOT = 0x2C,
  VK_INSERT = 0x2D,
  VK_DELETE = 0x2E,
  VK_HELP = 0x2F,
  VK_LWIN = 0x5B,
  VK_RWIN = 0x5C,
  VK_APPS = 0x5D,
  VK_SLEEP = 0x5F,
  VK_NUMPAD0 = 0x60,
  VK_NUMPAD1 = 0x61,
  VK_NUMPAD2 = 0x62,
  VK_NUMPAD3 = 0x63,
  VK_NUMPAD4 = 0x64,
  VK_NUMPAD5 = 0x65,
  VK_NUMPAD6 = 0x66,
  VK_NUMPAD7 = 0x67,
  VK_NUMPAD8 = 0x68,
  VK_NUMPAD9 = 0x69,
  VK_MULTIPLY = 0x6A,
  VK_ADD = 0x6B,
  VK_SEPARATOR = 0x6C,
  VK_SUBTRACT = 0x6D,
  VK_DECIMAL = 0x6E,
  VK_DIVIDE = 0x6F,
  VK_F1 = 0x70,
  VK_F2 = 0x71,
  VK_F3 = 0x72,
  VK_F4 = 0x73,
  VK_F5 = 0x74,
  VK_F6 = 0x75,
  VK_F7 = 0x76,
  VK_F8 = 0x77,
  VK_F9 = 0x78,
  VK_F10 = 0x79,
  VK_F11 = 0x7A,
  VK_F12 = 0x7B,
  VK_F13 = 0x7C,
  VK_F14 = 0x7D,
  VK_F15 = 0x7E,
  VK_F16 = 0x7F,
  VK_F17 = 0x80,
  VK_F18 = 0x81,
  VK_F19 = 0x82,
  VK_F20 = 0x83,
  VK_F21 = 0x84,
  VK_F22 = 0x85,
  VK_F23 = 0x86,
  VK_F24 = 0x87,
  VK_NUMLOCK = 0x90,
  VK_SCROLL = 0x91,
  VK_OEM_NEC_EQUAL = 0x92,
};

typedef enum MACRO_VK_KANJI MACRO_VK_KANJI;


/* 243 */
enum MACRO_VK
{
  VK_LBUTTON = 0x1,
  VK_RBUTTON = 0x2,
  VK_CANCEL = 0x3,
  VK_MBUTTON = 0x4,
  VK_XBUTTON1 = 0x5,
  VK_XBUTTON2 = 0x6,
  VK_BACK = 0x8,
  VK_TAB = 0x9,
  VK_CLEAR = 0xC,
  VK_RETURN = 0xD,
  VK_SHIFT = 0x10,
  VK_CONTROL = 0x11,
  VK_MENU = 0x12,
  VK_PAUSE = 0x13,
  VK_CAPITAL = 0x14,
  VK_KANA = 0x15,
};

typedef enum MACRO_VK MACRO_VK;


/* 245 */
struct PacketHeader
{
  int8_t col;
  int8_t row;
  char target_col;
  char target_row;
  int hp_cur;
  int hp_max;
  char str_base;
  char mag_base;
  char dex_base;
  __int16 pkt_type;
  int16_t len;
};

typedef struct PacketHeader PacketHeader;


/* 246 */
struct Packet
{
  PacketHeader hdr;
  char data[493];
};

typedef struct Packet Packet;


/* 248 */
enum msg_cmd
{
  MSG_CMD_0 = 0,
  MSG_CMD_1 = 1,
  MSG_CMD_2 = 2,
  MSG_CMD_3 = 3,
  MSG_CMD_4 = 4,
  MSG_CMD_5 = 5,
  MSG_CMD_6 = 6,
  MSG_CMD_7 = 7,
  MSG_CMD_8 = 8,
  MSG_CMD_9 = 9,
  MSG_CMD_10 = 10,
  MSG_CMD_11 = 11,
  MSG_CMD_12 = 12,
  MSG_CMD_13 = 13,
  MSG_CMD_14 = 14,
  MSG_CMD_15 = 15,
  MSG_CMD_16 = 16,
  MSG_CMD_17 = 17,
  MSG_CMD_18 = 18,
  MSG_CMD_19 = 19,
  MSG_CMD_20 = 20,
  MSG_CMD_21 = 21,
  MSG_CMD_22 = 22,
  MSG_CMD_23 = 23,
  MSG_CMD_24 = 24,
  MSG_CMD_25 = 25,
  MSG_CMD_26 = 26,
  MSG_CMD_27 = 27,
  MSG_CMD_28 = 28,
  MSG_CMD_29 = 29,
  MSG_CMD_30 = 30,
  MSG_CMD_31 = 31,
  MSG_CMD_32 = 32,
  MSG_CMD_33 = 33,
  MSG_CMD_34 = 34,
  MSG_CMD_35 = 35,
  MSG_CMD_36 = 36,
  MSG_CMD_37 = 37,
  MSG_CMD_38 = 38,
  MSG_CMD_39 = 39,
  MSG_CMD_40 = 40,
  MSG_CMD_41 = 41,
  MSG_CMD_42 = 42,
  MSG_CMD_43 = 43,
  MSG_CMD_44 = 44,
  MSG_CMD_45 = 45,
  MSG_CMD_46 = 46,
  MSG_CMD_47 = 47,
  MSG_CMD_48 = 48,
  MSG_CMD_49 = 49,
  MSG_CMD_50 = 50,
  MSG_CMD_51 = 51,
  MSG_CMD_52 = 52,
  MSG_CMD_53 = 53,
  MSG_CMD_54 = 54,
  MSG_CMD_55 = 55,
  MSG_CMD_56 = 56,
  MSG_CMD_57 = 57,
  MSG_CMD_58 = 58,
  MSG_CMD_59 = 59,
  MSG_CMD_60 = 60,
  MSG_CMD_61 = 61,
  MSG_CMD_62 = 62,
  MSG_CMD_63 = 63,
  MSG_CMD_64 = 64,
  MSG_CMD_65 = 65,
  MSG_CMD_66 = 66,
  MSG_CMD_67 = 67,
  MSG_CMD_68 = 68,
  MSG_CMD_69 = 69,
  MSG_CMD_70 = 70,
  MSG_CMD_71 = 71,
  MSG_CMD_72 = 72,
  MSG_CMD_73 = 73,
  MSG_CMD_74 = 74,
  MSG_CMD_75 = 75,
  MSG_CMD_76 = 76,
  MSG_CMD_77 = 77,
  MSG_CMD_78 = 78,
  MSG_CMD_MODIFY_STR = 79,
  MSG_CMD_MODIFY_MAG = 80,
  MSG_CMD_MODIFY_DEX = 81,
  MSG_CMD_82 = 82,
  MSG_CMD_RESTART_IN_TOWN = 83,
  MSG_CMD_84 = 84,
  MSG_CMD_85 = 85,
  MSG_CMD_86 = 86,
  MSG_CMD_87 = 87,
  MSG_CMD_88 = 88,
  MSG_CMD_89 = 89,
  MSG_CMD_90 = 90,
  MSG_CMD_91 = 91,
  MSG_CMD_92 = 92,
  MSG_CMD_IMPACT_MANA_SHIELD = 93,
};

typedef enum msg_cmd msg_cmd;


/* 466 */
enum dtype
{
  DTYPE_TRISTRAM = 0,
  DTYPE_CATHEDRAL = 1,
  DTYPE_CATACOMBS = 2,
  DTYPE_CAVES = 3,
  DTYPE_HELL = 4,
  DTYPE_NONE = -1,
};

typedef enum dtype dtype;


/* 481 */
enum quest_level
{
  QUEST_LEVEL_NONE = 0,
  QUEST_LEVEL_SKELETON_KINGS_LAIR = 1,
  QUEST_LEVEL_BONE_CHAMBER = 2,
  QUEST_LEVEL_MAZE = 3,
  QUEST_LEVEL_POISONED_WATER_SUPPLY = 4,
  QUEST_LEVEL_ARCHBISHOP_LAZARUS_LAIR = 5,
};

typedef enum quest_level quest_level;


/* 249 */
struct Portal
{
  int8_t col;
  int8_t row;
  int8_t dlvl;
  dtype dtype;
  quest_level quest_lvl;
};

typedef struct Portal Portal;


/* 250 */
struct SavePortal
{
  bool32_t active;
  int col;
  int row;
  int level;
  int dtype;
  int field_14;
};

typedef struct SavePortal SavePortal;


/* 251 */
struct Quest
{
  char dlvl;
  quest_id quest_id;
  bool8_t quest_active;
  int enterance_col;
  int enterance_row;
  quest_level quest_level;
  uint8_t speech_id;
  char var1;
  char field_10;
  bool32_t speech_spoken;
};

typedef struct Quest Quest;


/* 252 */
struct QuestData
{
  char field_0;
  char field_1;
  char field_2;
  char field_3;
  BYTE gap4[1];
  char field_5;
  char field_8;
  char field_C;
  char *name;
};

typedef struct QuestData QuestData;


/* 254 */
struct HeroItem
{
  int32_t seed;
  uint16_t wCF;
  int16_t item_id;
  int8_t identified_and_item_quality;
  int8_t durability_cur;
  int8_t durability_max;
  int8_t charges_min;
  int8_t charges_max;
  int16_t gold_price;
  int only_used_by_ear;
};

typedef struct HeroItem HeroItem;


/* 253 */
struct Hero
{
  BYTE gap0[8];
  int8_t daction;
  int8_t param1;
  int8_t param2;
  int8_t dlvl;
  int8_t col;
  int8_t row;
  int8_t target_col;
  int8_t target_row;
  char name[32];
  int8_t class;
  int8_t str_base;
  int8_t mag_base;
  int8_t dex_base;
  int8_t vit_base;
  int8_t clvl;
  int8_t points;
  int exp;
  int gold_total;
  int hp_base_cur;
  int hp_base_max;
  int mp_base_cur;
  int mp_base_max;
  int8_t spell_lvl_from_spell_id[37];
  uint32_t known_spells[2];
  HeroItem body_items[6];
  BYTE gapEE[19];
  HeroItem inv_items[39];
  BYTE gap3E6[19];
  int8_t inv_num_from_inv_grid[40];
  int8_t ninv_items;
  HeroItem belt_items[7];
  BYTE gap4A7[22];
  char field_4BD;
  char field_4BE;
  BYTE gap4BF[19];
  int difficulty;
  BYTE gap4D6[27];
  char field_4F1;
};

typedef struct Hero Hero;


/* 255 */
struct ScreenRow
{
  uint8_t col_unused_1[64];
  uint8_t pixels[640];
  uint8_t col_unused_2[64];
};

typedef struct ScreenRow ScreenRow;


/* 256 */
struct Screen
{
  ScreenRow row_unused_1[160];
  ScreenRow row[480];
  ScreenRow row_unused_2[16];
};

typedef struct Screen Screen;


/* 257 */
struct SHA1Context
{
  uint32_t state[5];
  uint32_t count[2];
  uint8_t buffer[64];
};

typedef struct SHA1Context SHA1Context;


/* 436 */
enum spell_id
{
  SPELL_ID_NULL = 0,
  SPELL_ID_FIREBOLT = 1,
  SPELL_ID_HEALING = 2,
  SPELL_ID_LIGHTNING = 3,
  SPELL_ID_FLASH = 4,
  SPELL_ID_IDENTIFY = 5,
  SPELL_ID_FIRE_WALL = 6,
  SPELL_ID_TOWN_PORTAL = 7,
  SPELL_ID_STONE_CURSE = 8,
  SPELL_ID_INFRAVISION = 9,
  SPELL_ID_PHASING = 10,
  SPELL_ID_MANA_SHIELD = 11,
  SPELL_ID_FIREBALL = 12,
  SPELL_ID_GUARDIAN = 13,
  SPELL_ID_CHAIN_LIGHTNING = 14,
  SPELL_ID_FLAME_WAVE = 15,
  SPELL_ID_DOOM_SERPENTS = 16,
  SPELL_ID_BLOOD_RITUAL = 17,
  SPELL_ID_NOVA = 18,
  SPELL_ID_INVISIBILITY = 19,
  SPELL_ID_INFERNO = 20,
  SPELL_ID_GOLEM = 21,
  SPELL_ID_BLOOD_BOIL = 22,
  SPELL_ID_TELEPORT = 23,
  SPELL_ID_APOCALYPSE = 24,
  SPELL_ID_ETHEREALIZE = 25,
  SPELL_ID_ITEM_REPAIR = 26,
  SPELL_ID_STAFF_RECHARGE = 27,
  SPELL_ID_TRAP_DISARM = 28,
  SPELL_ID_ELEMENTAL = 29,
  SPELL_ID_CHARGED_BOLT = 30,
  SPELL_ID_HOLY_BOLT = 31,
  SPELL_ID_RESURRECT = 32,
  SPELL_ID_TELEKINESIS = 33,
  SPELL_ID_HEAL_OTHER = 34,
  SPELL_ID_BLOOD_STAR = 35,
  SPELL_ID_BONE_SPIRIT = 36,
  SPELL_ID_INVALID = -1,
};

typedef enum spell_id spell_id;


/* 258 */
struct SpellData
{
  spell_id spell_id;
  int8_t mana_cost_start;
  char magic_type;
  char *spell_name;
  char *skill_name;
  int quality_lvl;
  int quality_lvl_staff;
  int field_14;
  bool32_t town_castable;
  int8_t mag_req;
  int8_t sfx_id;
  int8_t missile_ids[3];
  int8_t mana_dec_per_spell_lvl;
  int8_t mana_cost_min;
  int charges_min;
  int charges_max;
  int gold_price;
  int field_34;
};

typedef struct SpellData SpellData;


/* 259 */
struct Theme
{
  int8_t theme_id;
  char field_4;
  BYTE gap5[2];
  char field_7;
};

typedef struct Theme Theme;


/* 261 */
struct MapCol_i8
{
  int8_t row[112];
};

typedef struct MapCol_i8 MapCol_i8;


/* 260 */
struct Map_i8
{
  MapCol_i8 col[112];
};

typedef struct Map_i8 Map_i8;


/* 263 */
struct MapCol_i32
{
  int32_t row[112];
};

typedef struct MapCol_i32 MapCol_i32;


/* 262 */
struct Map_i32
{
  MapCol_i32 col[112];
};

typedef struct Map_i32 Map_i32;


/* 264 */
struct HeroInfo
{
  char field_0;
  char name[16];
  int16_t clvl;
  char field_16;
  int8_t difficulty;
  int16_t str_cur;
  int16_t mag_cur;
  int16_t dex_cur;
  int16_t vit_cur;
  int gold_total;
  bool32_t valid_save;
  int field_28;
};

typedef struct HeroInfo HeroInfo;


/* 265 */
struct ChatCmd
{
  int field_0;
  struct ServerCommand *extern_msgs[2];
};

typedef struct ChatCmd ChatCmd;


/* 267 */
struct QMapCol
{
  int8_t qrow[40];
};

typedef struct QMapCol QMapCol;


/* 266 */
struct QMap
{
  QMapCol qcol[40];
};

typedef struct QMap QMap;


/* 268 */
struct Shadow
{
  int8_t bottom_base_tile_id;
  int8_t top_base_tile_id;
  int8_t right_base_tile_id;
  int8_t left_base_tile_id;
  int8_t top_shadow_tile_id;
  int8_t right_shadow_tile_id;
  int8_t left_shadow_tile_id;
};

typedef struct Shadow Shadow;


/* 269 */
struct Point
{
  int32_t x;
  int32_t y;
};

typedef struct Point Point;


/* 271 */
struct ItemAbility
{
  int32_t ability_type;
  int32_t min;
  int32_t max;
};

typedef struct ItemAbility ItemAbility;


/* 270 */
struct ItemAffixData
{
  char *name;
  ItemAbility ability;
  int32_t quality_lvl;
  uint32_t occurrence;
  uint32_t compatible_1;
  uint32_t compatible_2;
  bool32_t positive;
  int32_t gold_effect_min;
  int32_t gold_effect_max;
  int32_t gold_price_multiplier;
};

typedef struct ItemAffixData ItemAffixData;


/* 464 */
enum unique_base_item
{
  UNIQUE_BASE_ITEM_NONE = 0,
  UNIQUE_BASE_ITEM_SHORT_BOW = 1,
  UNIQUE_BASE_ITEM_LONG_BOW = 2,
  UNIQUE_BASE_ITEM_HUNTERS_BOW = 3,
  UNIQUE_BASE_ITEM_COMPOSITE_BOW = 4,
  UNIQUE_BASE_ITEM_LONG_WAR_BOW = 5,
  UNIQUE_BASE_ITEM_LONG_BATTLE_BOW = 6,
  UNIQUE_BASE_ITEM_DAGGER = 7,
  UNIQUE_BASE_ITEM_FALCHION = 8,
  UNIQUE_BASE_ITEM_CLAYMORE = 9,
  UNIQUE_BASE_ITEM_BROAD_SWORD = 10,
  UNIQUE_BASE_ITEM_SABRE = 11,
  UNIQUE_BASE_ITEM_SCIMITAR = 12,
  UNIQUE_BASE_ITEM_LONG_SWORD = 13,
  UNIQUE_BASE_ITEM_BASTARD_SWORD = 14,
  UNIQUE_BASE_ITEM_TWO_HANDED_SWORD = 15,
  UNIQUE_BASE_ITEM_GREAT_SWORD = 16,
  UNIQUE_BASE_ITEM_CLEAVER = 17,
  UNIQUE_BASE_ITEM_LARGE_AXE = 18,
  UNIQUE_BASE_ITEM_BROAD_AXE = 19,
  UNIQUE_BASE_ITEM_SMALL_AXE = 20,
  UNIQUE_BASE_ITEM_BATTLE_AXE = 21,
  UNIQUE_BASE_ITEM_GREAT_AXE = 22,
  UNIQUE_BASE_ITEM_MACE = 23,
  UNIQUE_BASE_ITEM_MORNING_STAR = 24,
  UNIQUE_BASE_ITEM_SPIKED_CLUB = 25,
  UNIQUE_BASE_ITEM_MAUL = 26,
  UNIQUE_BASE_ITEM_WAR_HAMMER = 27,
  UNIQUE_BASE_ITEM_FLAIL = 28,
  UNIQUE_BASE_ITEM_LONG_STAFF = 29,
  UNIQUE_BASE_ITEM_SHORT_STAFF = 30,
  UNIQUE_BASE_ITEM_COMPOSITE_STAFF = 31,
  UNIQUE_BASE_ITEM_QUARTER_STAFF = 32,
  UNIQUE_BASE_ITEM_WAR_STAFF = 33,
  UNIQUE_BASE_ITEM_SKULL_CAP = 34,
  UNIQUE_BASE_ITEM_HELM = 35,
  UNIQUE_BASE_ITEM_GREAT_HELM = 36,
  UNIQUE_BASE_ITEM_CROWN = 37,
  UNIQUE_BASE_ITEM_RAGS = 39,
  UNIQUE_BASE_ITEM_STUDDED_LEATHER_ARMOR = 40,
  UNIQUE_BASE_ITEM_CLOAK = 41,
  UNIQUE_BASE_ITEM_ROBE = 42,
  UNIQUE_BASE_ITEM_CHAIN_MAIL = 43,
  UNIQUE_BASE_ITEM_LEATHER_ARMOR = 44,
  UNIQUE_BASE_ITEM_BREAST_PLATE = 45,
  UNIQUE_BASE_ITEM_CAPE = 46,
  UNIQUE_BASE_ITEM_PLATE_MAIL = 47,
  UNIQUE_BASE_ITEM_FULL_PLATE_MAIL = 48,
  UNIQUE_BASE_ITEM_BUCKLER = 49,
  UNIQUE_BASE_ITEM_SMALL_SHIELD = 50,
  UNIQUE_BASE_ITEM_LARGE_SHIELD = 51,
  UNIQUE_BASE_ITEM_KITE_SHIELD = 52,
  UNIQUE_BASE_ITEM_GOTHIC_SHIELD = 53,
  UNIQUE_BASE_ITEM_RING = 54,
  UNIQUE_BASE_ITEM_AMULET = 56,
  UNIQUE_BASE_ITEM_THE_UNDEAD_CROWN = 57,
  UNIQUE_BASE_ITEM_EMPYREAN_BAND = 58,
  UNIQUE_BASE_ITEM_OPTIC_AMULET = 59,
  UNIQUE_BASE_ITEM_RING_OF_TRUTH = 60,
  UNIQUE_BASE_ITEM_HARLEQUIN_CREST = 61,
  UNIQUE_BASE_ITEM_MAP_OF_THE_STARS = 62,
  UNIQUE_BASE_ITEM_ELIXIR = 63,
  UNIQUE_BASE_ITEM_ARKAINES_VALOR = 64,
  UNIQUE_BASE_ITEM_VEIL_OF_STEEL = 65,
  UNIQUE_BASE_ITEM_GRISWOLDS_EDGE = 66,
  UNIQUE_BASE_ITEM_LIGHTFORGE = 67,
  UNIQUE_BASE_ITEM_STAFF_OF_LAZARUS = 68,
  UNIQUE_BASE_ITEM_INVALID = -1,
};

typedef enum unique_base_item unique_base_item;


/* 272 */
struct UniqueItemData
{
  char *name;
  unique_base_item unique_base_item;
  int8_t quality_lvl;
  int8_t nabilities;
  char reserved_0007;
  int32_t gold_price;
  ItemAbility abilities[6];
};

typedef struct UniqueItemData UniqueItemData;


/* 273 */
struct PlayerMsg
{
  uint32_t start_tc;
  int8_t player_num;
  char text[144];
  char reserved_0095[3];
};

typedef struct PlayerMsg PlayerMsg;


/* 401 */
enum sfx_flag
{
  SFX_FLAG_STREAM = 0x1,
  SFX_FLAG_MISC = 0x2,
  SFX_FLAG_4 = 0x4,
  SFX_FLAG_8 = 0x8,
  SFX_FLAG_16 = 0x10,
  SFX_FLAG_32 = 0x20,
  SFX_FLAG_64 = 0x40,
  SFX_FLAG_128 = 0x80,
};

typedef enum sfx_flag sfx_flag;


/* 274 */
struct SfxData
{
  sfx_flag sfx_flag;
  char *sound_path;
  struct SoundFile *sound_file;
};

typedef struct SfxData SfxData;


/* 275 */
struct PCXHeader
{
  char manufacturer;
  char version;
  char encoding;
  char bits_per_pixel;
  __int16 x_min;
  __int16 y_min;
  __int16 x_max;
  __int16 y_max;
  __int16 horiz_dpi;
  __int16 vert_dpi;
  char colormap[48];
  char reserved_0040;
  char nplanes;
  __int16 bytes_per_line;
  __int16 palette_info;
  __int16 horiz_screen_size;
  __int16 vert_screen_size;
  char filler[54];
};

typedef struct PCXHeader PCXHeader;


/* 476 */
enum monster_id
{
  MONSTER_ID_ZOMBIE = 0,
  MONSTER_ID_GHOUL = 1,
  MONSTER_ID_ROTTING_CARCASS = 2,
  MONSTER_ID_BLACK_DEATH = 3,
  MONSTER_ID_FALLEN_ONE_SPEAR = 4,
  MONSTER_ID_CARVER_SPEAR = 5,
  MONSTER_ID_DEVIL_KIN_SPEAR = 6,
  MONSTER_ID_DARK_ONE_SPEAR = 7,
  MONSTER_ID_SKELETON_AXE = 8,
  MONSTER_ID_CORPSE_AXE = 9,
  MONSTER_ID_BURNING_DEAD_AXE = 10,
  MONSTER_ID_HORROR_AXE = 11,
  MONSTER_ID_FALLEN_ONE_SWORD = 12,
  MONSTER_ID_CARVER_SWORD = 13,
  MONSTER_ID_DEVIL_KIN_SWORD = 14,
  MONSTER_ID_DARK_ONE_SWORD = 15,
  MONSTER_ID_SCAVENGER = 16,
  MONSTER_ID_PLAGUE_EATER = 17,
  MONSTER_ID_SHADOW_BEAST = 18,
  MONSTER_ID_BONE_GASHER = 19,
  MONSTER_ID_SKELETON_BOW = 20,
  MONSTER_ID_CORPSE_BOW = 21,
  MONSTER_ID_BURNING_DEAD_BOW = 22,
  MONSTER_ID_HORROR_BOW = 23,
  MONSTER_ID_SKELETON_CAPTAIN = 24,
  MONSTER_ID_CORPSE_CAPTAIN = 25,
  MONSTER_ID_BURNING_DEAD_CAPTAIN = 26,
  MONSTER_ID_HORROR_CAPTAIN = 27,
  MONSTER_ID_INVISIBLE_LORD = 28,
  MONSTER_ID_HIDDEN = 29,
  MONSTER_ID_STALKER = 30,
  MONSTER_ID_UNSEEN = 31,
  MONSTER_ID_ILLUSION_WEAVER = 32,
  MONSTER_ID_LORD_SAYTER = 33,
  MONSTER_ID_FLESH_CLAN_MACE = 34,
  MONSTER_ID_STONE_CLAN_MACE = 35,
  MONSTER_ID_FIRE_CLAN_MACE = 36,
  MONSTER_ID_NIGHT_CLAN_MACE = 37,
  MONSTER_ID_FIEND = 38,
  MONSTER_ID_BLINK = 39,
  MONSTER_ID_GLOOM = 40,
  MONSTER_ID_FAMILIAR = 41,
  MONSTER_ID_FLESH_CLAN_BOW = 42,
  MONSTER_ID_STONE_CLAN_BOW = 43,
  MONSTER_ID_FIRE_CLAN_BOW = 44,
  MONSTER_ID_NIGHT_CLAN_BOW = 45,
  MONSTER_ID_ACID_BEAST = 46,
  MONSTER_ID_POISON_SPITTER = 47,
  MONSTER_ID_PIT_BEAST = 48,
  MONSTER_ID_LAVA_MAW = 49,
  MONSTER_ID_SKELETON_KING = 50,
  MONSTER_ID_THE_BUTCHER = 51,
  MONSTER_ID_OVERLORD = 52,
  MONSTER_ID_MUD_MAN = 53,
  MONSTER_ID_TOAD_DEMON = 54,
  MONSTER_ID_FLAYED_ONE = 55,
  MONSTER_ID_WYRM = 56,
  MONSTER_ID_CAVE_SLUG = 57,
  MONSTER_ID_DEVIL_WYRM = 58,
  MONSTER_ID_DEVOURER = 59,
  MONSTER_ID_MAGMA_DEMON = 60,
  MONSTER_ID_BLOOD_STONE = 61,
  MONSTER_ID_HELL_STONE = 62,
  MONSTER_ID_LAVA_LORD = 63,
  MONSTER_ID_HORNED_DEMON = 64,
  MONSTER_ID_MUD_RUNNER = 65,
  MONSTER_ID_FROST_CHARGER = 66,
  MONSTER_ID_OBSIDIAN_LORD = 67,
  MONSTER_ID_BONE_DEMON = 68,
  MONSTER_ID_RED_DEATH = 69,
  MONSTER_ID_LITCH_DEMON = 70,
  MONSTER_ID_UNDEAD_BALROG = 71,
  MONSTER_ID_INCINERATOR = 72,
  MONSTER_ID_FLAME_LORD = 73,
  MONSTER_ID_DOOM_FIRE = 74,
  MONSTER_ID_HELL_BURNER = 75,
  MONSTER_ID_RED_STORM = 76,
  MONSTER_ID_STORM_RIDER = 77,
  MONSTER_ID_STORM_LORD = 78,
  MONSTER_ID_MAELSTORM = 79,
  MONSTER_ID_DEVIL_KIN_BRUTE = 80,
  MONSTER_ID_WINGED_DEMON = 81,
  MONSTER_ID_GARGOYLE = 82,
  MONSTER_ID_BLOOD_CLAW = 83,
  MONSTER_ID_DEATH_WING = 84,
  MONSTER_ID_SLAYER = 85,
  MONSTER_ID_GUARDIAN = 86,
  MONSTER_ID_VORTEX_LORD = 87,
  MONSTER_ID_BALROG = 88,
  MONSTER_ID_CAVE_VIPER = 89,
  MONSTER_ID_FIRE_DRAKE = 90,
  MONSTER_ID_GOLD_VIPER = 91,
  MONSTER_ID_AZURE_DRAKE = 92,
  MONSTER_ID_BLACK_KNIGHT = 93,
  MONSTER_ID_DOOM_GUARD = 94,
  MONSTER_ID_STEEL_LORD = 95,
  MONSTER_ID_BLOOD_KNIGHT = 96,
  MONSTER_ID_UNRAVELER = 97,
  MONSTER_ID_HOLLOW_ONE = 98,
  MONSTER_ID_PAIN_MASTER = 99,
  MONSTER_ID_REALITY_WEAVER = 100,
  MONSTER_ID_SUCCUBUS = 101,
  MONSTER_ID_SNOW_WITCH = 102,
  MONSTER_ID_HELL_SPAWN = 103,
  MONSTER_ID_SOUL_BURNER = 104,
  MONSTER_ID_COUNSELOR = 105,
  MONSTER_ID_MAGISTRATE = 106,
  MONSTER_ID_CABALIST = 107,
  MONSTER_ID_ADVOCATE = 108,
  MONSTER_ID_GOLEM = 109,
  MONSTER_ID_THE_DARK_LORD = 110,
  MONSTER_ID_THE_ARCH_LITCH_MALIGNUS = 111,
  MONSTER_ID_NONE = -1,
};

typedef enum monster_id monster_id;


/* 302 */
struct Animation
{
  void *cl2_archive;
  void *cl2_from_direction[8];
  int last_frame;
  int anim_speed;
};

typedef struct Animation Animation;


/* 276 */
struct MonsterType
{
  monster_id monster_id;
  char field_1;
  Animation anim_from_monster_anim_mode[6];
  struct SoundFile *sound_files[4][2];
  int frame_width;
  int x_offset;
  int8_t hp_min;
  int8_t hp_max;
  bool32_t has_special_attack;
  int8_t hit_frame;
  MonsterData *monster_data;
  void *trn_buf;
};

typedef struct MonsterType MonsterType;


/* 278 */
struct MessageVtbl
{
  HRESULT (__stdcall *QueryInterface)(struct MessageVtbl *This, const IID *const riid, void **ppvObject);
  ULONG (__stdcall *AddRef)(struct MessageVtbl *This);
  ULONG (__stdcall *Release)(struct MessageVtbl *This);
  HRESULT (__stdcall *GetTypeInfoCount)(struct MessageVtbl *This, UINT *pctinfo);
  HRESULT (__stdcall *GetTypeInfo)(struct MessageVtbl *This, UINT iTInfo, LCID lcid, ITypeInfo **ppTInfo);
  HRESULT (__stdcall *GetIDsOfNames)(struct MessageVtbl *This, const IID *const riid, LPOLESTR *rgszNames, UINT cNames, LCID lcid, DISPID *rgDispId);
  HRESULT (__stdcall *Invoke)(struct MessageVtbl *This, DISPID dispIdMember, const IID *const riid, LCID lcid, WORD wFlags, DISPPARAMS *pDispParams, VARIANT *pVarResult, EXCEPINFO *pExcepInfo, UINT *puArgErr);
  HRESULT (__stdcall *get_Application)(struct MessageVtbl *This, VARIANT *varApplication);
  HRESULT (__stdcall *get_Parent)(struct MessageVtbl *This, VARIANT *varParent);
  HRESULT (__stdcall *get_Session)(struct MessageVtbl *This, VARIANT *varSession);
  HRESULT (__stdcall *get_Class)(struct MessageVtbl *This, __int32 *varClass);
  HRESULT (__stdcall *get_Size)(struct MessageVtbl *This, __int32 *varSize);
  HRESULT (__stdcall *get_Importance)(struct MessageVtbl *This, __int32 *pImportance);
  HRESULT (__stdcall *put_Importance)(struct MessageVtbl *This, __int32 varImportance);
  HRESULT (__stdcall *get_Subject)(struct MessageVtbl *This, BSTR *pSubject);
  HRESULT (__stdcall *put_Subject)(struct MessageVtbl *This, BSTR varSubject);
  HRESULT (__stdcall *get_Sender)(struct MessageVtbl *This, VARIANT *varSender);
  HRESULT (__stdcall *get_TimeSent)(struct MessageVtbl *This, VARIANT *varTimeSent);
  HRESULT (__stdcall *put_TimeSent)(struct MessageVtbl *This, VARIANT varTimeSent);
  HRESULT (__stdcall *get_TimeReceived)(struct MessageVtbl *This, VARIANT *varTimeReceived);
  HRESULT (__stdcall *put_TimeReceived)(struct MessageVtbl *This, VARIANT varTimeReceived);
  HRESULT (__stdcall *get_Text)(struct MessageVtbl *This, VARIANT *varText);
  HRESULT (__stdcall *put_Text)(struct MessageVtbl *This, VARIANT varText);
  HRESULT (__stdcall *get_HTMLText)(struct MessageVtbl *This, VARIANT *varHTMLText);
  HRESULT (__stdcall *put_HTMLText)(struct MessageVtbl *This, VARIANT varHTMLText);
  HRESULT (__stdcall *get_Recipients)(struct MessageVtbl *This, VARIANT *varRecipients);
  HRESULT (__stdcall *put_Recipients)(struct MessageVtbl *This, VARIANT varRecipients);
  HRESULT (__stdcall *get_Attachments)(struct MessageVtbl *This, VARIANT *varAttachments);
  HRESULT (__stdcall *put_MessageFormat)(struct MessageVtbl *This, __int32 MIDL_0011);
  HRESULT (__stdcall *get_ContentLocation)(struct MessageVtbl *This, VARIANT *varContentLocation);
  HRESULT (__stdcall *put_ContentLocation)(struct MessageVtbl *This, VARIANT varContentLocation);
  HRESULT (__stdcall *get_ContentBase)(struct MessageVtbl *This, VARIANT *varContentBase);
  HRESULT (__stdcall *put_ContentBase)(struct MessageVtbl *This, VARIANT varContentBase);
  HRESULT (__stdcall *get_ContentID)(struct MessageVtbl *This, VARIANT *varContentID);
  HRESULT (__stdcall *put_ContentID)(struct MessageVtbl *This, VARIANT varContentID);
  HRESULT (__stdcall *Delete)(struct MessageVtbl *This);
  HRESULT (__stdcall *Send)(struct MessageVtbl *This);
};

typedef struct MessageVtbl MessageVtbl;


/* 281 */
struct MessageItem
{
  BYTE gap0[21];
  char field_15;
};

typedef struct MessageItem MessageItem;


/* 282 */
struct MessageMonster
{
  BYTE gap0[8];
  char field_8;
};

typedef struct MessageMonster MessageMonster;


/* 280 */
struct Message
{
  MessageItem items[127];
  int8_t cmd_from_msg_object_num[127];
  MessageMonster monsters[200];
};

typedef struct Message Message;


/* 283 */
struct PanelButton
{
  int x;
  int y;
  int width;
  int height;
  int unused;
};

typedef struct PanelButton PanelButton;


/* 284 */
enum MACRO_SC
{
  SC_SIZE = 0xF000,
  SC_MOVE = 0xF010,
  SC_MINIMIZE = 0xF020,
  SC_MAXIMIZE = 0xF030,
  SC_NEXTWINDOW = 0xF040,
  SC_PREVWINDOW = 0xF050,
  SC_CLOSE = 0xF060,
  SC_VSCROLL = 0xF070,
  SC_HSCROLL = 0xF080,
  SC_MOUSEMENU = 0xF090,
  SC_KEYMENU = 0xF100,
  SC_ARRANGE = 0xF110,
  SC_RESTORE = 0xF120,
  SC_TASKLIST = 0xF130,
  SC_SCREENSAVE = 0xF140,
  SC_HOTKEY = 0xF150,
  SC_DEFAULT = 0xF160,
  SC_MONITORPOWER = 0xF170,
  SC_CONTEXTHELP = 0xF180,
};

typedef enum MACRO_SC MACRO_SC;


/* 285 */
struct SoundFile
{
  BYTE gap0[20];
  int32_t len;
  int32_t offset;
  char *sound_path;
  struct IDirectSoundBufferVtbl **DSB;
  uint32_t start_tc;
};

typedef struct SoundFile SoundFile;


/* 288 */
typedef struct _DSBCAPS *LPDSBCAPS;

/* 290 */
typedef struct tWAVEFORMATEX *LPWAVEFORMATEX;

/* 292 */
typedef __int32 *LPLONG;

/* 293 */
typedef struct IDirectSound *LPDIRECTSOUND;

/* 296 */
typedef struct _DSBUFFERDESC DSBUFFERDESC;

/* 295 */
typedef const DSBUFFERDESC *LPCDSBUFFERDESC;

/* 299 */
typedef struct tWAVEFORMATEX WAVEFORMATEX;

/* 298 */
typedef const WAVEFORMATEX *LPCWAVEFORMATEX;

/* 287 */
struct IDirectSoundBufferVtbl
{
  HRESULT (__stdcall *QueryInterface)(struct IDirectSoundBufferVtbl *This, const IID *const , LPVOID *);
  ULONG (__stdcall *AddRef)(struct IDirectSoundBufferVtbl *This);
  ULONG (__stdcall *Release)(struct IDirectSoundBufferVtbl *This);
  HRESULT (__stdcall *GetCaps)(struct IDirectSoundBufferVtbl *This, LPDSBCAPS);
  HRESULT (__stdcall *GetCurrentPosition)(struct IDirectSoundBufferVtbl *This, LPDWORD, LPDWORD);
  HRESULT (__stdcall *GetFormat)(struct IDirectSoundBufferVtbl *This, LPWAVEFORMATEX, DWORD, LPDWORD);
  HRESULT (__stdcall *GetVolume)(struct IDirectSoundBufferVtbl *This, LPLONG);
  HRESULT (__stdcall *GetPan)(struct IDirectSoundBufferVtbl *This, LPLONG);
  HRESULT (__stdcall *GetFrequency)(struct IDirectSoundBufferVtbl *This, LPDWORD);
  HRESULT (__stdcall *GetStatus)(struct IDirectSoundBufferVtbl *This, LPDWORD);
  HRESULT (__stdcall *Initialize)(struct IDirectSoundBufferVtbl *This, LPDIRECTSOUND, LPCDSBUFFERDESC);
  HRESULT (__stdcall *Lock)(struct IDirectSoundBufferVtbl *This, DWORD, DWORD, LPVOID *, LPDWORD, LPVOID *, LPDWORD, DWORD);
  HRESULT (__stdcall *Play)(struct IDirectSoundBufferVtbl *This, DWORD, DWORD, DWORD);
  HRESULT (__stdcall *SetCurrentPosition)(struct IDirectSoundBufferVtbl *This, DWORD);
  HRESULT (__stdcall *SetFormat)(struct IDirectSoundBufferVtbl *This, LPCWAVEFORMATEX);
  HRESULT (__stdcall *SetVolume)(struct IDirectSoundBufferVtbl *This, LONG);
  HRESULT (__stdcall *SetPan)(struct IDirectSoundBufferVtbl *This, LONG);
  HRESULT (__stdcall *SetFrequency)(struct IDirectSoundBufferVtbl *This, DWORD);
  HRESULT (__stdcall *Stop)(struct IDirectSoundBufferVtbl *This);
  HRESULT (__stdcall *Unlock)(struct IDirectSoundBufferVtbl *This, LPVOID, DWORD, LPVOID, DWORD);
  HRESULT (__stdcall *Restore)(struct IDirectSoundBufferVtbl *This);
};

typedef struct IDirectSoundBufferVtbl IDirectSoundBufferVtbl;


/* 289 */
struct _DSBCAPS
{
  DWORD dwSize;
  DWORD dwFlags;
  DWORD dwBufferBytes;
  DWORD dwUnlockTransferRate;
  DWORD dwPlayCpuOverhead;
};

typedef struct _DSBCAPS _DSBCAPS;


/* 291 */

struct tWAVEFORMATEX
{
  WORD wFormatTag;
  WORD nChannels;
  DWORD nSamplesPerSec;
  DWORD nAvgBytesPerSec;
  WORD nBlockAlign;
  WORD wBitsPerSample;
  WORD cbSize;
};

typedef struct tWAVEFORMATEX tWAVEFORMATEX;



/* 294 */
struct IDirectSound
{
  struct IDirectSoundVtbl *lpVtbl;
};

typedef struct IDirectSound IDirectSound;


/* 297 */
struct _DSBUFFERDESC
{
  DWORD dwSize;
  DWORD dwFlags;
  DWORD dwBufferBytes;
  DWORD dwReserved;
  LPWAVEFORMATEX lpwfxFormat;
};

typedef struct _DSBUFFERDESC _DSBUFFERDESC;


/* 300 */
struct IDirectSoundBuffer
{
  IDirectSoundBufferVtbl *lpVtbl;
};

typedef struct IDirectSoundBuffer IDirectSoundBuffer;


/* 301 */
enum MACRO_DSBSTATUS
{
  DSBSTATUS_PLAYING = 0x1,
  DSBSTATUS_BUFFERLOST = 0x2,
  DSBSTATUS_LOOPING = 0x4,
};

typedef enum MACRO_DSBSTATUS MACRO_DSBSTATUS;


/* 303 */
struct UniqueMonsterData
{
  monster_id base_monster_id;
  char reserved_0001[3];
  char *name;
  char *trn_name;
  int16_t dlvl;
  int16_t hp;
  int8_t monster_AI_id;
  int8_t intelligence_factor;
  int8_t damage_min;
  int8_t damage_max;
  uint16_t resistance_and_immunity;
  uint16_t pack_trigger;
  int pack_modifier;
  int speech_id;
};

typedef struct UniqueMonsterData UniqueMonsterData;


/* 304 */
struct Rectangle
{
  int x;
  int y;
  int width;
  int height;
};

typedef struct Rectangle Rectangle;


/* 306 */
struct Coord_i8
{
  int8_t col;
  int8_t row;
};

typedef struct Coord_i8 Coord_i8;


/* 305 */
struct MissileLightingCoords
{
  int8_t n_1;
  Coord_i8 coords_1[1];
  int8_t n_4;
  Coord_i8 coords_4[4];
  int8_t n_16;
  Coord_i8 coords_16[16];
  int8_t n_24;
  Coord_i8 coords_24[24];
  int8_t n_32;
  Coord_i8 coords_32[32];
  int8_t n_40;
  Coord_i8 coords_40[40];
  int8_t n_48;
  Coord_i8 coords_48[48];
  int8_t n_56;
  Coord_i8 coords_56[56];
  int8_t n_64;
  Coord_i8 coords_64[64];
  int8_t n_72;
  Coord_i8 coords_72[72];
  int8_t n_80;
  Coord_i8 coords_80[80];
  int8_t n_88;
  Coord_i8 coords_88[88];
  int8_t n_96;
  Coord_i8 coords_96[96];
  int8_t n_104;
  Coord_i8 coords_104[104];
  int8_t n_112;
  Coord_i8 coords_112[112];
  int8_t n_120;
  Coord_i8 coords_120[120];
  int8_t n_128;
  Coord_i8 coords_128[128];
  int8_t n_136;
  Coord_i8 coords_136[136];
  int8_t n_144;
  Coord_i8 coords_144[144];
};

typedef struct MissileLightingCoords MissileLightingCoords;


/* 308 */
struct WalkOffset
{
  int _short;
  int medium;
  int _long;
};

typedef struct WalkOffset WalkOffset;


/* 309 */
struct ObjectData
{
  int8_t object_load;
  int8_t object_cel_id;
  int8_t dlvl_start;
  int8_t dlvl_end;
  dtype dtype;
  int8_t theme_id;
  quest_id quest_id;
  bool32_t animated;
  int ticks_per_frame_or_first_frame_if_not_animated;
  int last_frame;
  int frame_width;
  bool32_t collision;
  bool32_t missile_can_pass;
  BYTE gap20[4];
  bool8_t hittable;
  int8_t object_interact;
  bool32_t possible_traphole;
};

typedef struct ObjectData ObjectData;


/* 311 */
struct Object
{
  int object_id;
  int col;
  int row;
  BYTE gapC[8];
  void *object_cel;
  BYTE gap18[12];
  int field_24;
  BYTE gap28[12];
  char field_34;
  BYTE gap35[7];
  int field_3C;
  char field_40;
  BYTE gap41[19];
  int seed;
  int object_var1;
  int object_var2;
  int object_var3;
  int object_var4;
  BYTE gap68[15];
  char field_77;
};

typedef struct Object Object;


/* 312 */
enum MACRO_DDERR_OUTOFMEMORY
{
  DDERR_OUTOFMEMORY = -2147024882,
  DDERR_OUTOFVIDEOMEMORY = -2005532292,
  DDERR_OVERLAYCANTCLIP = -2005532290,
  DDERR_OVERLAYCOLORKEYONLYONEACTIVE = -2005532288,
  DDERR_PALETTEBUSY = -2005532285,
  DDERR_COLORKEYNOTSET = -2005532272,
  DDERR_SURFACEALREADYATTACHED = -2005532262,
  DDERR_SURFACEALREADYDEPENDENT = -2005532252,
  DDERR_SURFACEBUSY = -2005532242,
  DDERR_CANTLOCKSURFACE = -2005532237,
  DDERR_SURFACEISOBSCURED = -2005532232,
  DDERR_SURFACELOST = -2005532222,
  DDERR_SURFACENOTATTACHED = -2005532212,
  DDERR_TOOBIGHEIGHT = -2005532202,
  DDERR_TOOBIGSIZE = -2005532192,
  DDERR_TOOBIGWIDTH = -2005532182,
};

typedef enum MACRO_DDERR_OUTOFMEMORY MACRO_DDERR_OUTOFMEMORY;


/* 313 */
struct BookText
{
  int dlvl4_speech_id;
  int dlvl8_speech_id;
  int dlvl12_speech_id;
};

typedef struct BookText BookText;


/* 314 */
struct PathStep
{
  int8_t cost_something1;
  int8_t cost_something2;
  char cost_something3;
  int col_something;
  int row_something;
  void *field_C;
  int field_10;
  BYTE gap14[28];
  struct PathStep *field_30;
};

typedef struct PathStep PathStep;


/* 315 */
struct ActionFrame
{
  int8_t dungeon_stand_frame;
  int8_t attack_frame;
  int8_t dungeon_walk_frame;
  int8_t block_frame;
  int8_t death_frame;
  int8_t spell_frame;
  int8_t hit_frame;
  int8_t town_stand_frame;
  int8_t town_walk_frame;
  int8_t field_9;
  int8_t field_A;
};

typedef struct ActionFrame ActionFrame;


/* 318 */
struct IDirectDrawSurfaceVtbl;

typedef struct IDirectDrawSurfaceVtbl *LPDIRECTDRAWSURFACE;

/* 319 */
typedef tagRECT *LPRECT;

/* 321 */
typedef struct _DDBLTFX DDBLTFX;

/* 320 */
typedef DDBLTFX *LPDDBLTFX;

/* 331 */
typedef struct _DDBLTBATCH DDBLTBATCH;

/* 330 */
typedef DDBLTBATCH *LPDDBLTBATCH;

/* 334 */
typedef struct _DDSURFACEDESC *LPDDSURFACEDESC;

/* 333 */
typedef HRESULT (__stdcall *LPDDENUMSURFACESCALLBACK)(LPDIRECTDRAWSURFACE, LPDDSURFACEDESC, LPVOID);

/* 345 */
typedef struct _DDSCAPS DDSCAPS;

/* 347 */
typedef DDSCAPS *LPDDSCAPS;

/* 348 */
typedef struct IDirectDrawClipper *LPDIRECTDRAWCLIPPER;

/* 328 */
typedef struct _DDCOLORKEY DDCOLORKEY;

/* 350 */
typedef DDCOLORKEY *LPDDCOLORKEY;

/* 351 */
typedef struct HDC__ *HDC;

/* 353 */
typedef struct IDirectDrawPalette *LPDIRECTDRAWPALETTE;

/* 338 */
typedef struct _DDPIXELFORMAT DDPIXELFORMAT;

/* 355 */
typedef DDPIXELFORMAT *LPDDPIXELFORMAT;

/* 357 */
typedef struct _DDOVERLAYFX DDOVERLAYFX;

/* 356 */
typedef DDOVERLAYFX *LPDDOVERLAYFX;

/* 316 */
struct IDirectDrawSurfaceVtbl
{
  HRESULT (__stdcall *QueryInterface)(struct IDirectDrawSurfaceVtbl *This, const IID *const riid, LPVOID *ppvObj);
  ULONG (__stdcall *AddRef)(struct IDirectDrawSurfaceVtbl *This);
  ULONG (__stdcall *Release)(struct IDirectDrawSurfaceVtbl *This);
  HRESULT (__stdcall *AddAttachedSurface)(struct IDirectDrawSurfaceVtbl *This, LPDIRECTDRAWSURFACE);
  HRESULT (__stdcall *AddOverlayDirtyRect)(struct IDirectDrawSurfaceVtbl *This, LPRECT);
  HRESULT (__stdcall *Blt)(struct IDirectDrawSurfaceVtbl *This, LPRECT, LPDIRECTDRAWSURFACE, LPRECT, DWORD, LPDDBLTFX);
  HRESULT (__stdcall *BltBatch)(struct IDirectDrawSurfaceVtbl *This, LPDDBLTBATCH, DWORD, DWORD);
  HRESULT (__stdcall *BltFast)(struct IDirectDrawSurfaceVtbl *This, DWORD, DWORD, LPDIRECTDRAWSURFACE, LPRECT, DWORD);
  HRESULT (__stdcall *DeleteAttachedSurface)(struct IDirectDrawSurfaceVtbl *This, DWORD, LPDIRECTDRAWSURFACE);
  HRESULT (__stdcall *EnumAttachedSurfaces)(struct IDirectDrawSurfaceVtbl *This, LPVOID, LPDDENUMSURFACESCALLBACK);
  HRESULT (__stdcall *EnumOverlayZOrders)(struct IDirectDrawSurfaceVtbl *This, DWORD, LPVOID, LPDDENUMSURFACESCALLBACK);
  HRESULT (__stdcall *Flip)(struct IDirectDrawSurfaceVtbl *This, LPDIRECTDRAWSURFACE, DWORD);
  HRESULT (__stdcall *GetAttachedSurface)(struct IDirectDrawSurfaceVtbl *This, LPDDSCAPS, LPDIRECTDRAWSURFACE *);
  HRESULT (__stdcall *GetBltStatus)(struct IDirectDrawSurfaceVtbl *This, DWORD);
  HRESULT (__stdcall *GetCaps)(struct IDirectDrawSurfaceVtbl *This, LPDDSCAPS);
  HRESULT (__stdcall *GetClipper)(struct IDirectDrawSurfaceVtbl *This, LPDIRECTDRAWCLIPPER *);
  HRESULT (__stdcall *GetColorKey)(struct IDirectDrawSurfaceVtbl *This, DWORD, LPDDCOLORKEY);
  HRESULT (__stdcall *GetDC)(struct IDirectDrawSurfaceVtbl *This, HDC *);
  HRESULT (__stdcall *GetFlipStatus)(struct IDirectDrawSurfaceVtbl *This, DWORD);
  HRESULT (__stdcall *GetOverlayPosition)(struct IDirectDrawSurfaceVtbl *This, LPLONG, LPLONG);
  HRESULT (__stdcall *GetPalette)(struct IDirectDrawSurfaceVtbl *This, LPDIRECTDRAWPALETTE *);
  HRESULT (__stdcall *GetPixelFormat)(struct IDirectDrawSurfaceVtbl *This, LPDDPIXELFORMAT);
  HRESULT (__stdcall *GetSurfaceDesc)(struct IDirectDrawSurfaceVtbl *This, LPDDSURFACEDESC);
  HRESULT (__stdcall *Initialize)(struct IDirectDrawSurfaceVtbl *This, LPDIRECTDRAW, LPDDSURFACEDESC);
  HRESULT (__stdcall *IsLost)(struct IDirectDrawSurfaceVtbl *This);
  HRESULT (__stdcall *Lock)(struct IDirectDrawSurfaceVtbl *This, LPRECT, LPDDSURFACEDESC, DWORD, HANDLE);
  HRESULT (__stdcall *ReleaseDC)(struct IDirectDrawSurfaceVtbl *This, HDC);
  HRESULT (__stdcall *Restore)(struct IDirectDrawSurfaceVtbl *This);
  HRESULT (__stdcall *SetClipper)(struct IDirectDrawSurfaceVtbl *This, LPDIRECTDRAWCLIPPER);
  HRESULT (__stdcall *SetColorKey)(struct IDirectDrawSurfaceVtbl *This, DWORD, LPDDCOLORKEY);
  HRESULT (__stdcall *SetOverlayPosition)(struct IDirectDrawSurfaceVtbl *This, LONG, LONG);
  HRESULT (__stdcall *SetPalette)(struct IDirectDrawSurfaceVtbl *This, LPDIRECTDRAWPALETTE);
  HRESULT (__stdcall *Unlock)(struct IDirectDrawSurfaceVtbl *This, LPVOID);
  HRESULT (__stdcall *UpdateOverlay)(struct IDirectDrawSurfaceVtbl *This, LPRECT, LPDIRECTDRAWSURFACE, LPRECT, DWORD, LPDDOVERLAYFX);
  HRESULT (__stdcall *UpdateOverlayDisplay)(struct IDirectDrawSurfaceVtbl *This, DWORD);
  HRESULT (__stdcall *UpdateOverlayZOrder)(struct IDirectDrawSurfaceVtbl *This, DWORD, LPDIRECTDRAWSURFACE);
};

typedef struct IDirectDrawSurfaceVtbl IDirectDrawSurfaceVtbl;


/* 323 */
/* 324 */
/* 325 */
/* 326 */
/* 327 */
/* 329 */
struct _DDCOLORKEY
{
  DWORD dwColorSpaceLowValue;
  DWORD dwColorSpaceHighValue;
};

typedef struct _DDCOLORKEY _DDCOLORKEY;


/* 322 */
struct _DDBLTFX
{
  DWORD dwSize;
  DWORD dwDDFX;
  DWORD dwROP;
  DWORD dwDDROP;
  DWORD dwRotationAngle;
  DWORD dwZBufferOpCode;
  DWORD dwZBufferLow;
  DWORD dwZBufferHigh;
  DWORD dwZBufferBaseDest;
  DWORD dwZDestConstBitDepth;
  union
  {
    DWORD dwZDestConst;
    LPDIRECTDRAWSURFACE lpDDSZBufferDest;
  };
  DWORD dwZSrcConstBitDepth;
  union
  {
    DWORD dwZSrcConst;
    LPDIRECTDRAWSURFACE lpDDSZBufferSrc;
  };
  DWORD dwAlphaEdgeBlendBitDepth;
  DWORD dwAlphaEdgeBlend;
  DWORD dwReserved;
  DWORD dwAlphaDestConstBitDepth;
  union
  {
    DWORD dwAlphaDestConst;
    LPDIRECTDRAWSURFACE lpDDSAlphaDest;
  };
  DWORD dwAlphaSrcConstBitDepth;
  union
  {
    DWORD dwAlphaSrcConst;
    LPDIRECTDRAWSURFACE lpDDSAlphaSrc;
  };
  union
  {
    DWORD dwFillColor;
    DWORD dwFillDepth;
    DWORD dwFillPixel;
    LPDIRECTDRAWSURFACE lpDDSPattern;
  };
  DDCOLORKEY ddckDestColorkey;
  DDCOLORKEY ddckSrcColorkey;
};

typedef struct _DDBLTFX _DDBLTFX;


/* 332 */
struct _DDBLTBATCH
{
  LPRECT lprDest;
  LPDIRECTDRAWSURFACE lpDDSSrc;
  LPRECT lprSrc;
  DWORD dwFlags;
  LPDDBLTFX lpDDBltFx;
};

typedef struct _DDBLTBATCH _DDBLTBATCH;


/* 336 */
/* 337 */
/* 340 */
/* 341 */
/* 342 */
/* 343 */
/* 344 */
/* 339 */
struct _DDPIXELFORMAT
{
  DWORD dwSize;
  DWORD dwFlags;
  DWORD dwFourCC;
  union
  {
    DWORD dwRGBBitCount;
    DWORD dwYUVBitCount;
    DWORD dwZBufferBitDepth;
    DWORD dwAlphaBitDepth;
  };
  union
  {
    DWORD dwRBitMask;
    DWORD dwYBitMask;
  };
  union
  {
    DWORD dwGBitMask;
    DWORD dwUBitMask;
  };
  union
  {
    DWORD dwBBitMask;
    DWORD dwVBitMask;
  };
  union
  {
    DWORD dwRGBAlphaBitMask;
    DWORD dwYUVAlphaBitMask;
    DWORD dwRGBZBitMask;
    DWORD dwYUVZBitMask;
  };
};

typedef struct _DDPIXELFORMAT _DDPIXELFORMAT;


/* 346 */
struct _DDSCAPS
{
  DWORD dwCaps;
};

typedef struct _DDSCAPS _DDSCAPS;


/* 335 */
struct _DDSURFACEDESC
{
  DWORD dwSize;
  DWORD dwFlags;
  DWORD dwHeight;
  DWORD dwWidth;
  union
  {
    LONG lPitch;
    DWORD dwLinearSize;
  };
  DWORD dwBackBufferCount;
  union
  {
    DWORD dwMipMapCount;
    DWORD dwZBufferBitDepth;
    DWORD dwRefreshRate;
  };
  DWORD dwAlphaBitDepth;
  DWORD dwReserved;
  LPVOID lpSurface;
  DDCOLORKEY ddckCKDestOverlay;
  DDCOLORKEY ddckCKDestBlt;
  DDCOLORKEY ddckCKSrcOverlay;
  DDCOLORKEY ddckCKSrcBlt;
  DDPIXELFORMAT ddpfPixelFormat;
  DDSCAPS ddsCaps;
};

typedef struct _DDSURFACEDESC _DDSURFACEDESC;


/* 349 */
struct IDirectDrawClipper
{
  struct IDirectDrawClipperVtbl*lpVtbl;
};

typedef struct IDirectDrawClipper IDirectDrawClipper;


/* 352 */
struct HDC__
{
  int unused;
};

typedef struct HDC__ HDC__;


/* 354 */
struct IDirectDrawPaletteVtbl;

struct IDirectDrawPalette
{
  struct IDirectDrawPaletteVtbl *lpVtbl;
};

typedef struct IDirectDrawPalette IDirectDrawPalette;


/* 359 */
/* 360 */
/* 358 */
struct _DDOVERLAYFX
{
  DWORD dwSize;
  DWORD dwAlphaEdgeBlendBitDepth;
  DWORD dwAlphaEdgeBlend;
  DWORD dwReserved;
  DWORD dwAlphaDestConstBitDepth;
  union
  {
    DWORD dwAlphaDestConst;
    LPDIRECTDRAWSURFACE lpDDSAlphaDest;
  };
  DWORD dwAlphaSrcConstBitDepth;
  union
  {
    DWORD dwAlphaSrcConst;
    LPDIRECTDRAWSURFACE lpDDSAlphaSrc;
  };
  DDCOLORKEY dckDestColorkey;
  DDCOLORKEY dckSrcColorkey;
  DWORD dwDDFX;
  DWORD dwFlags;
};

typedef struct _DDOVERLAYFX _DDOVERLAYFX;


/* 361 */
struct Dead
{
  void *cl2_from_direction[8];
  int field_20;
  int field_24;
  int field_28;
  char field_2C;
  BYTE gap2D[2];
  char field_2F;
};

typedef struct Dead Dead;


/* 363 */
struct Piece
{
  int16_t blocks[16];
};

typedef struct Piece Piece;


/* 364 */
struct Tile
{
  int16_t top_piece_id;
  int16_t right_piece_id;
  int16_t left_piece_id;
  int16_t bottom_piece_id;
};

typedef struct Tile Tile;


/* 366 */
typedef _RTL_CRITICAL_SECTION RTL_CRITICAL_SECTION;

/* 365 */
typedef RTL_CRITICAL_SECTION CRITICAL_SECTION;

/* 367 */
enum text_color
{
  TEXT_COLOR_GREY = 0,
  TEXT_COLOR_BLUE = 1,
  TEXT_COLOR_RED = 2,
  TEXT_COLOR_GOLD = 3,
};

typedef enum text_color text_color;


/* 368 */
struct Stats
{
  int str;
  int mag;
  int dex;
  int vit;
};

typedef struct Stats Stats;


/* 370 */
enum MACRO_MB_ICONWARNING
{
  MB_ICONWARNING = 48,
};

typedef enum MACRO_MB_ICONWARNING MACRO_MB_ICONWARNING;


/* 372 */
enum l1_square
{
  L1_SQUARE_NONE = 0,
  L1_SQUARE_WALL_SW = 1,
  L1_SQUARE_WALL_SE = 2,
  L1_SQUARE_ARCH_NE_ARCH_NW = 3,
  L1_SQUARE_WALL_SW_WALL_SE = 4,
  L1_SQUARE_ARCH_SW_ARCH_SE = 5,
  L1_SQUARE_WALL_END_SW = 6,
  L1_SQUARE_WALL_END_SE = 7,
  L1_SQUARE_ARCH_END_SW = 8,
  L1_SQUARE_ARCH_END_SE = 9,
  L1_SQUARE_WALL_SW_ARCH_SE = 10,
  L1_SQUARE_ARCH_SW = 11,
  L1_SQUARE_ARCH_SE = 12,
  L1_SQUARE_FLOOR = 13,
  L1_SQUARE_ARCH_SW_WALL_SE = 14,
  L1_SQUARE_COLUMN = 15,
  L1_SQUARE_ARCH_END_NE = 16,
  L1_SQUARE_ARCH_END_NW = 17,
  L1_SQUARE_DIRT_WALL_SW = 18,
  L1_SQUARE_DIRT_WALL_SE = 19,
  L1_SQUARE_DIRT_WALL_NE_WALL_NW = 20,
  L1_SQUARE_DIRT_WALL_SW_WALL_SE = 21,
  L1_SQUARE_DIRT = 22,
  L1_SQUARE_DIRT_WALL_END_SW = 23,
  L1_SQUARE_DIRT_WALL_END_SE = 24,
  L1_SQUARE_DOOR_SW = 25,
  L1_SQUARE_DOOR_SE = 26,
  L1_SQUARE_WALL_SW_BAR_SE = 27,
  L1_SQUARE_DOOR_SW_DOOR_SE = 28,
  L1_SQUARE_BAR_SW_BAR_SE = 29,
  L1_SQUARE_DOOR_END_SW = 30,
  L1_SQUARE_DOOR_END_SE = 31,
  L1_SQUARE_BAR_END_SW = 32,
  L1_SQUARE_BAR_END_SE = 33,
  L1_SQUARE_DOOR_SW_BAR_SE = 34,
  L1_SQUARE_BAR_SW = 35,
  L1_SQUARE_BAR_SE = 36,
  L1_SQUARE_BAR_SW_WALL_SE = 37,
  L1_SQUARE_BAR_SW_ARCH_SE = 38,
  L1_SQUARE_BAR_SW_DOOR_SE = 39,
  L1_SQUARE_DOOR_SW_ARCH_SE = 40,
  L1_SQUARE_DOOR_SW_WALL_SE = 41,
  L1_SQUARE_ARCH_SW_DOOR_SE = 42,
  L1_SQUARE_WALL_SW_DOOR_SE = 43,
  L1_SQUARE_ARCH_SW_BAR_SE = 44,
  L1_SQUARE_CIRCLE_MARKING_1 = 45,
  L1_SQUARE_CIRCLE_MARKING_2 = 46,
  L1_SQUARE_CIRCLE_MARKING_3 = 47,
  L1_SQUARE_CIRCLE_MARKING_4 = 48,
  L1_SQUARE_CIRCLE_MARKING_5 = 49,
  L1_SQUARE_CIRCLE_MARKING_6 = 50,
  L1_SQUARE_CIRCLE_MARKING_7 = 51,
  L1_SQUARE_CIRCLE_MARKING_8 = 52,
  L1_SQUARE_CIRCLE_MARKING_9 = 53,
  L1_SQUARE_CIRCLE_MARKING_10 = 54,
  L1_SQUARE_CIRCLE_MARKING_11 = 55,
  L1_SQUARE_CIRCLE_MARKING_12 = 56,
  L1_SQUARE_STAIR_A_1 = 57,
  L1_SQUARE_STAIR_A_2 = 58,
  L1_SQUARE_STAIR_A_3 = 59,
  L1_SQUARE_STAIR_A_4 = 60,
  L1_SQUARE_STAIR_A_5 = 61,
  L1_SQUARE_STAIR_A_6 = 62,
  L1_SQUARE_STAIR_B_1 = 63,
  L1_SQUARE_STAIR_B_2 = 64,
  L1_SQUARE_STAIR_B_3 = 65,
  L1_SQUARE_STAIR_B_4 = 66,
  L1_SQUARE_STAIR_B_5 = 67,
  L1_SQUARE_STAIR_B_6 = 68,
  L1_SQUARE_TOMB_1 = 69,
  L1_SQUARE_TOMB_2 = 70,
  L1_SQUARE_TOMB_3 = 71,
  L1_SQUARE_TOMB_4 = 72,
  L1_SQUARE_TOMB_5 = 73,
  L1_SQUARE_TOMB_6 = 74,
  L1_SQUARE_TOMB_7 = 75,
  L1_SQUARE_TOMB_8 = 76,
  L1_SQUARE_TOMB_9 = 77,
  L1_SQUARE_TOMB_10 = 78,
  L1_SQUARE_WALL_SW_2 = 79,
  L1_SQUARE_WALL_SE_2 = 80,
  L1_SQUARE_WALL_NE_WALL_NW = 81,
  L1_SQUARE_WALL_SW_WALL_SE_2 = 82,
  L1_SQUARE_WALL_SW_3 = 83,
  L1_SQUARE_WALL_END_SW_2 = 84,
  L1_SQUARE_WALL_END_SE_2 = 85,
  L1_SQUARE_WALL_END_NE = 86,
  L1_SQUARE_WALL_END_NW = 87,
  L1_SQUARE_WALL_SE_3 = 88,
  L1_SQUARE_TAPESTRY_WALL_SW_1 = 89,
  L1_SQUARE_TAPESTRY_WALL_SW_2 = 90,
  L1_SQUARE_TAPESTRY_WALL_SE_1 = 91,
  L1_SQUARE_TAPESTRY_WALL_SE_2 = 92,
  L1_SQUARE_WALL_SW_4 = 93,
  L1_SQUARE_TOMB_WALL_SW = 94,
  L1_SQUARE_TOMB_WALL_SE = 95,
  L1_SQUARE_WALL_SE_4 = 96,
  L1_SQUARE_BLOOD_WALL_SE_1 = 97,
  L1_SQUARE_BLOOD_WALL_SE_2 = 98,
  L1_SQUARE_BLOOD_WALL_SE_3 = 99,
  L1_SQUARE_BLOOD_WALL_SW_1 = 100,
  L1_SQUARE_BLOOD_WALL_SW_2 = 101,
  L1_SQUARE_BLOOD_ARCH_SW = 102,
  L1_SQUARE_BLOOD_DOOR_SW = 103,
  L1_SQUARE_BLOOD_FLOOR_1 = 104,
  L1_SQUARE_BLOOD_FLOOR_2 = 105,
  L1_SQUARE_BLOOD_FLOOR_3 = 106,
  L1_SQUARE_CROSS_WALL_SW = 107,
  L1_SQUARE_CROSS_WALL_SE = 108,
  L1_SQUARE_NICHE_WALL_SW = 109,
  L1_SQUARE_NICHE_WALL_SE = 110,
  L1_SQUARE_STATUE_WALL_SW = 111,
  L1_SQUARE_STATUE_WALL_SE = 112,
  L1_SQUARE_TORCH_WALL_SW = 113,
  L1_SQUARE_TORCH_WALL_SE = 114,
  L1_SQUARE_BROKEN_WALL_SE_1 = 115,
  L1_SQUARE_BROKEN_WALL_SE_2 = 116,
  L1_SQUARE_BROKEN_WALL_SE_3 = 117,
  L1_SQUARE_BROKEN_ARCH_SE = 118,
  L1_SQUARE_BROKEN_ENTERANCE_SE_1 = 119,
  L1_SQUARE_BROKEN_ENTERANCE_SE_2 = 120,
  L1_SQUARE_BROKEN_ARCH_SW_1 = 121,
  L1_SQUARE_BROKEN_WALL_SW_1 = 122,
  L1_SQUARE_BROKEN_ARCH_SW_2 = 123,
  L1_SQUARE_BROKEN_WALL_SW_2 = 124,
  L1_SQUARE_BROKEN_FLOOR_1 = 125,
  L1_SQUARE_BROKEN_ENTERANCE_SW_1 = 126,
  L1_SQUARE_BROKEN_ENTERANCE_SW_2 = 127,
  L1_SQUARE_CANDLESTICK_1 = 128,
  L1_SQUARE_CANDLESTICK_2 = 129,
  L1_SQUARE_CANDLESTICK_3 = 130,
  L1_SQUARE_SARCOPHAGUS_1 = 131,
  L1_SQUARE_SARCOPHAGUS_2 = 132,
  L1_SQUARE_BROKEN_FLOOR_2 = 133,
  L1_SQUARE_BROKEN_FLOOR_3 = 134,
  L1_SQUARE_BROKEN_FLOOR_4 = 135,
  L1_SQUARE_BROKEN_FLOOR_5 = 136,
  L1_SQUARE_BROKEN_FLOOR_6 = 137,
  L1_SQUARE_BROKEN_FLOOR_7 = 138,
  L1_SQUARE_FLOOR_SHADOW_ARCH_SW_RIGHT = 139,
  L1_SQUARE_FLOOR_SHADOW_ARCH_SE_LEFT = 140,
  L1_SQUARE_FLOOR_SHADOW_BAR_SW_RIGHT = 141,
  L1_SQUARE_FLOOR_SHADOW_SHAFT_RIGHT = 142,
  L1_SQUARE_FLOOR_SHADOW_ARCH_SE_LEFT_SHAFT_BOTTOM = 143,
  L1_SQUARE_FLOOR_SHADOW_SHAFT_BOTTOM_1 = 144,
  L1_SQUARE_FLOOR_SHADOW_COLUMN_BOTTOM = 145,
  L1_SQUARE_WALL_SW_SHADOW_ARCH_SE_LEFT = 146,
  L1_SQUARE_ARCH_SW_SHADOW_ARCH_SE_LEFT = 147,
  L1_SQUARE_WALL_SE_SHADOW_ARCH_SW_RIGHT = 148,
  L1_SQUARE_ARCH_SE_SHADOW_ARCH_SW_RIGHT = 149,
  L1_SQUARE_FLOOR_SHADOW_ARCH_SE_LEFT_ARCH_SW_RIGHT = 150,
  L1_SQUARE_FLOOR_SHADOW_SHAFT_BOTTOM_ARCH_SW_RIGHT = 151,
  L1_SQUARE_FLOOR_SHADOW_SHAFT_BOTTOM_2 = 152,
  L1_SQUARE_ARCH_SE_SHADOW_BAR_SW_RIGHT = 153,
  L1_SQUARE_WALL_SE_SHADOW_BAR_SW_RIGHT = 154,
  L1_SQUARE_WALL_SW_3_SHADOW_ARCH_SE_LEFT = 155,
  L1_SQUARE_WALL_SE_3_SHADOW_ARCH_SW_RIGHT = 156,
  L1_SQUARE_WALL_SE_3_SHADOW_BAR_SW_RIGHT = 157,
  L1_SQUARE_WALL_SW_WALL_SE_3 = 158,
  L1_SQUARE_ARCH_SW_WALL_SE_3 = 159,
  L1_SQUARE_WALL_SW_3_WALL_SE = 160,
  L1_SQUARE_WALL_SW_3_ARCH_SE = 161,
  L1_SQUARE_FLOOR_2 = 162,
  L1_SQUARE_FLOOR_3 = 163,
  L1_SQUARE_DOOR_SW_WALL_SE_3 = 164,
  L1_SQUARE_WALL_SW_3_DOOR_SE = 165,
  L1_SQUARE_BLOOD_WALL_SW_3 = 166,
  L1_SQUARE_BLOOD_WALL_SW_4 = 167,
  L1_SQUARE_BLOOD_WALL_SW_WALL_SE = 168,
  L1_SQUARE_BLOOD_WALL_SE_4 = 169,
  L1_SQUARE_BLOOD_WALL_SE_5 = 170,
  L1_SQUARE_BLOOD_FLOOR_4 = 171,
  L1_SQUARE_BLOOD_FLOOR_5 = 172,
  L1_SQUARE_BLOOD_FLOOR_6 = 173,
  L1_SQUARE_BLOOD_FLOOR_7 = 174,
  L1_SQUARE_OPEN_DOOR_SW = 175,
  L1_SQUARE_OPEN_DOOR_SE = 176,
  L1_SQUARE_OPEN_DOOR_SW_OPEN_DOOR_SE = 177,
  L1_SQUARE_OPEN_DOOR_END_SW = 178,
  L1_SQUARE_OPEN_DOOR_END_SE = 179,
  L1_SQUARE_OPEN_DOOR_SW_BAR_SE = 180,
  L1_SQUARE_BAR_SW_OPEN_DOOR_SE = 181,
  L1_SQUARE_OPEN_DOOR_SW_ARCH_SE = 182,
  L1_SQUARE_OPEN_DOOR_SW_WALL_SE = 183,
  L1_SQUARE_ARCH_SW_OPEN_DOOR_SE = 184,
  L1_SQUARE_WALL_SW_OPEN_DOOR_SE = 185,
  L1_SQUARE_OPEN_BLOOD_DOOR_SW = 186,
  L1_SQUARE_OPEN_DOOR_SW_WALL_SE_3 = 187,
  L1_SQUARE_WALL_SW_3_OPEN_DOOR_SE = 188,
  L1_SQUARE_OPEN_DOOR_SW_DOOR_SE = 189,
  L1_SQUARE_DOOR_SW_OPEN_DOOR_SE = 190,
  L1_SQUARE_WALL_SW_5 = 191,
  L1_SQUARE_WALL_SE_5 = 192,
  L1_SQUARE_ENTERANCE_SW_1 = 193,
  L1_SQUARE_ENTERANCE_SE_1 = 194,
  L1_SQUARE_DIRT_FLOOR_SHADOW = 195,
  L1_SQUARE_DIRT_FLOOR_SHADOW_ARCH_SW_RIGHT = 196,
  L1_SQUARE_ENTERANCE_SW_2 = 197,
  L1_SQUARE_ENTERANCE_SE_2 = 198,
  L1_SQUARE_DIRT_WALL_SW_DIRT = 199,
  L1_SQUARE_DIRT_WALL_SE_DIRT = 200,
  L1_SQUARE_DIRT_WALL_NE_WALL_NW_DIRT = 201,
  L1_SQUARE_DIRT_WALL_SW_WALL_SE_DIRT = 202,
  L1_SQUARE_DIRT_DIRT = 203,
  L1_SQUARE_DIRT_WALL_END_SW_DIRT = 204,
  L1_SQUARE_DIRT_WALL_END_SE_DIRT = 205,
  L1_SQUARE_BROKEN_ENTERANCE_SE_3 = 206,
};

typedef enum l1_square l1_square;


/* 373 */
enum l2_square
{
  L2_SQUARE_1 = 1,
  L2_SQUARE_2 = 2,
  L2_SQUARE_3 = 3,
  L2_SQUARE_4 = 4,
  L2_SQUARE_5 = 5,
  L2_SQUARE_6 = 6,
  L2_SQUARE_7 = 7,
  L2_SQUARE_8 = 8,
  L2_SQUARE_9 = 9,
  L2_SQUARE_10 = 10,
  L2_SQUARE_11 = 11,
  L2_SQUARE_12 = 12,
  L2_SQUARE_13 = 13,
  L2_SQUARE_14 = 14,
  L2_SQUARE_15 = 15,
  L2_SQUARE_16 = 16,
  L2_SQUARE_17 = 17,
  L2_SQUARE_18 = 18,
  L2_SQUARE_19 = 19,
  L2_SQUARE_20 = 20,
  L2_SQUARE_21 = 21,
  L2_SQUARE_22 = 22,
  L2_SQUARE_23 = 23,
  L2_SQUARE_24 = 24,
  L2_SQUARE_25 = 25,
  L2_SQUARE_26 = 26,
  L2_SQUARE_27 = 27,
  L2_SQUARE_28 = 28,
  L2_SQUARE_29 = 29,
  L2_SQUARE_30 = 30,
  L2_SQUARE_31 = 31,
  L2_SQUARE_32 = 32,
  L2_SQUARE_33 = 33,
  L2_SQUARE_34 = 34,
  L2_SQUARE_35 = 35,
  L2_SQUARE_36 = 36,
  L2_SQUARE_37 = 37,
  L2_SQUARE_38 = 38,
  L2_SQUARE_39 = 39,
  L2_SQUARE_40 = 40,
  L2_SQUARE_41 = 41,
  L2_SQUARE_42 = 42,
  L2_SQUARE_43 = 43,
  L2_SQUARE_44 = 44,
  L2_SQUARE_45 = 45,
  L2_SQUARE_46 = 46,
  L2_SQUARE_47 = 47,
  L2_SQUARE_48 = 48,
  L2_SQUARE_49 = 49,
  L2_SQUARE_50 = 50,
  L2_SQUARE_51 = 51,
  L2_SQUARE_52 = 52,
  L2_SQUARE_53 = 53,
  L2_SQUARE_54 = 54,
  L2_SQUARE_55 = 55,
  L2_SQUARE_56 = 56,
  L2_SQUARE_57 = 57,
  L2_SQUARE_58 = 58,
  L2_SQUARE_59 = 59,
  L2_SQUARE_60 = 60,
  L2_SQUARE_61 = 61,
  L2_SQUARE_62 = 62,
  L2_SQUARE_63 = 63,
  L2_SQUARE_64 = 64,
  L2_SQUARE_65 = 65,
  L2_SQUARE_66 = 66,
  L2_SQUARE_67 = 67,
  L2_SQUARE_68 = 68,
  L2_SQUARE_69 = 69,
  L2_SQUARE_70 = 70,
  L2_SQUARE_71 = 71,
  L2_SQUARE_72 = 72,
  L2_SQUARE_73 = 73,
  L2_SQUARE_74 = 74,
  L2_SQUARE_75 = 75,
  L2_SQUARE_76 = 76,
  L2_SQUARE_77 = 77,
  L2_SQUARE_78 = 78,
  L2_SQUARE_79 = 79,
  L2_SQUARE_80 = 80,
  L2_SQUARE_81 = 81,
  L2_SQUARE_82 = 82,
  L2_SQUARE_83 = 83,
  L2_SQUARE_84 = 84,
  L2_SQUARE_85 = 85,
  L2_SQUARE_86 = 86,
  L2_SQUARE_87 = 87,
  L2_SQUARE_88 = 88,
  L2_SQUARE_89 = 89,
  L2_SQUARE_90 = 90,
  L2_SQUARE_91 = 91,
  L2_SQUARE_92 = 92,
  L2_SQUARE_93 = 93,
  L2_SQUARE_94 = 94,
  L2_SQUARE_95 = 95,
  L2_SQUARE_96 = 96,
  L2_SQUARE_97 = 97,
  L2_SQUARE_98 = 98,
  L2_SQUARE_99 = 99,
  L2_SQUARE_100 = 100,
  L2_SQUARE_101 = 101,
  L2_SQUARE_102 = 102,
  L2_SQUARE_103 = 103,
  L2_SQUARE_104 = 104,
  L2_SQUARE_105 = 105,
  L2_SQUARE_106 = 106,
  L2_SQUARE_107 = 107,
  L2_SQUARE_108 = 108,
  L2_SQUARE_109 = 109,
  L2_SQUARE_110 = 110,
  L2_SQUARE_111 = 111,
  L2_SQUARE_112 = 112,
  L2_SQUARE_113 = 113,
  L2_SQUARE_114 = 114,
  L2_SQUARE_115 = 115,
  L2_SQUARE_116 = 116,
  L2_SQUARE_117 = 117,
  L2_SQUARE_118 = 118,
  L2_SQUARE_119 = 119,
  L2_SQUARE_120 = 120,
  L2_SQUARE_121 = 121,
  L2_SQUARE_122 = 122,
  L2_SQUARE_123 = 123,
  L2_SQUARE_124 = 124,
  L2_SQUARE_125 = 125,
  L2_SQUARE_126 = 126,
  L2_SQUARE_127 = 127,
  L2_SQUARE_128 = 128,
  L2_SQUARE_129 = 129,
  L2_SQUARE_130 = 130,
  L2_SQUARE_131 = 131,
  L2_SQUARE_132 = 132,
  L2_SQUARE_133 = 133,
  L2_SQUARE_134 = 134,
  L2_SQUARE_135 = 135,
  L2_SQUARE_136 = 136,
  L2_SQUARE_137 = 137,
  L2_SQUARE_138 = 138,
  L2_SQUARE_139 = 139,
  L2_SQUARE_140 = 140,
  L2_SQUARE_141 = 141,
  L2_SQUARE_142 = 142,
  L2_SQUARE_143 = 143,
  L2_SQUARE_144 = 144,
  L2_SQUARE_145 = 145,
  L2_SQUARE_146 = 146,
  L2_SQUARE_147 = 147,
  L2_SQUARE_148 = 148,
  L2_SQUARE_149 = 149,
  L2_SQUARE_150 = 150,
  L2_SQUARE_151 = 151,
  L2_SQUARE_152 = 152,
  L2_SQUARE_153 = 153,
  L2_SQUARE_154 = 154,
  L2_SQUARE_155 = 155,
  L2_SQUARE_156 = 156,
  L2_SQUARE_157 = 157,
  L2_SQUARE_158 = 158,
  L2_SQUARE_159 = 159,
  L2_SQUARE_160 = 160,
};

typedef enum l2_square l2_square;


/* 375 */
enum l3_square
{
  L3_SQUARE_1 = 1,
  L3_SQUARE_2 = 2,
  L3_SQUARE_3 = 3,
  L3_SQUARE_4 = 4,
  L3_SQUARE_5 = 5,
  L3_SQUARE_6 = 6,
  L3_SQUARE_7 = 7,
  L3_SQUARE_8 = 8,
  L3_SQUARE_9 = 9,
  L3_SQUARE_10 = 10,
  L3_SQUARE_11 = 11,
  L3_SQUARE_12 = 12,
  L3_SQUARE_13 = 13,
  L3_SQUARE_14 = 14,
  L3_SQUARE_15 = 15,
  L3_SQUARE_16 = 16,
  L3_SQUARE_17 = 17,
  L3_SQUARE_18 = 18,
  L3_SQUARE_19 = 19,
  L3_SQUARE_20 = 20,
  L3_SQUARE_21 = 21,
  L3_SQUARE_22 = 22,
  L3_SQUARE_23 = 23,
  L3_SQUARE_24 = 24,
  L3_SQUARE_25 = 25,
  L3_SQUARE_26 = 26,
  L3_SQUARE_27 = 27,
  L3_SQUARE_28 = 28,
  L3_SQUARE_29 = 29,
  L3_SQUARE_30 = 30,
  L3_SQUARE_31 = 31,
  L3_SQUARE_32 = 32,
  L3_SQUARE_33 = 33,
  L3_SQUARE_34 = 34,
  L3_SQUARE_35 = 35,
  L3_SQUARE_36 = 36,
  L3_SQUARE_37 = 37,
  L3_SQUARE_38 = 38,
  L3_SQUARE_39 = 39,
  L3_SQUARE_40 = 40,
  L3_SQUARE_41 = 41,
  L3_SQUARE_42 = 42,
  L3_SQUARE_43 = 43,
  L3_SQUARE_44 = 44,
  L3_SQUARE_45 = 45,
  L3_SQUARE_46 = 46,
  L3_SQUARE_47 = 47,
  L3_SQUARE_48 = 48,
  L3_SQUARE_49 = 49,
  L3_SQUARE_50 = 50,
  L3_SQUARE_51 = 51,
  L3_SQUARE_52 = 52,
  L3_SQUARE_53 = 53,
  L3_SQUARE_54 = 54,
  L3_SQUARE_55 = 55,
  L3_SQUARE_56 = 56,
  L3_SQUARE_57 = 57,
  L3_SQUARE_58 = 58,
  L3_SQUARE_59 = 59,
  L3_SQUARE_60 = 60,
  L3_SQUARE_61 = 61,
  L3_SQUARE_62 = 62,
  L3_SQUARE_63 = 63,
  L3_SQUARE_64 = 64,
  L3_SQUARE_65 = 65,
  L3_SQUARE_66 = 66,
  L3_SQUARE_67 = 67,
  L3_SQUARE_68 = 68,
  L3_SQUARE_69 = 69,
  L3_SQUARE_70 = 70,
  L3_SQUARE_71 = 71,
  L3_SQUARE_72 = 72,
  L3_SQUARE_73 = 73,
  L3_SQUARE_74 = 74,
  L3_SQUARE_75 = 75,
  L3_SQUARE_76 = 76,
  L3_SQUARE_77 = 77,
  L3_SQUARE_78 = 78,
  L3_SQUARE_79 = 79,
  L3_SQUARE_80 = 80,
  L3_SQUARE_81 = 81,
  L3_SQUARE_82 = 82,
  L3_SQUARE_83 = 83,
  L3_SQUARE_84 = 84,
  L3_SQUARE_85 = 85,
  L3_SQUARE_86 = 86,
  L3_SQUARE_87 = 87,
  L3_SQUARE_88 = 88,
  L3_SQUARE_89 = 89,
  L3_SQUARE_90 = 90,
  L3_SQUARE_91 = 91,
  L3_SQUARE_92 = 92,
  L3_SQUARE_93 = 93,
  L3_SQUARE_94 = 94,
  L3_SQUARE_95 = 95,
  L3_SQUARE_96 = 96,
  L3_SQUARE_97 = 97,
  L3_SQUARE_98 = 98,
  L3_SQUARE_99 = 99,
  L3_SQUARE_100 = 100,
  L3_SQUARE_101 = 101,
  L3_SQUARE_102 = 102,
  L3_SQUARE_103 = 103,
  L3_SQUARE_104 = 104,
  L3_SQUARE_105 = 105,
  L3_SQUARE_106 = 106,
  L3_SQUARE_107 = 107,
  L3_SQUARE_108 = 108,
  L3_SQUARE_109 = 109,
  L3_SQUARE_110 = 110,
  L3_SQUARE_111 = 111,
  L3_SQUARE_112 = 112,
  L3_SQUARE_113 = 113,
  L3_SQUARE_114 = 114,
  L3_SQUARE_115 = 115,
  L3_SQUARE_116 = 116,
  L3_SQUARE_117 = 117,
  L3_SQUARE_118 = 118,
  L3_SQUARE_119 = 119,
  L3_SQUARE_120 = 120,
  L3_SQUARE_121 = 121,
  L3_SQUARE_122 = 122,
  L3_SQUARE_123 = 123,
  L3_SQUARE_124 = 124,
  L3_SQUARE_125 = 125,
  L3_SQUARE_126 = 126,
  L3_SQUARE_127 = 127,
  L3_SQUARE_128 = 128,
  L3_SQUARE_129 = 129,
  L3_SQUARE_130 = 130,
  L3_SQUARE_131 = 131,
  L3_SQUARE_132 = 132,
  L3_SQUARE_133 = 133,
  L3_SQUARE_134 = 134,
  L3_SQUARE_135 = 135,
  L3_SQUARE_136 = 136,
  L3_SQUARE_137 = 137,
  L3_SQUARE_138 = 138,
  L3_SQUARE_139 = 139,
  L3_SQUARE_140 = 140,
  L3_SQUARE_141 = 141,
  L3_SQUARE_142 = 142,
  L3_SQUARE_143 = 143,
  L3_SQUARE_144 = 144,
  L3_SQUARE_145 = 145,
  L3_SQUARE_146 = 146,
  L3_SQUARE_147 = 147,
  L3_SQUARE_148 = 148,
  L3_SQUARE_149 = 149,
  L3_SQUARE_150 = 150,
  L3_SQUARE_151 = 151,
  L3_SQUARE_152 = 152,
  L3_SQUARE_153 = 153,
  L3_SQUARE_154 = 154,
  L3_SQUARE_155 = 155,
  L3_SQUARE_156 = 156,
};

typedef enum l3_square l3_square;


/* 377 */
enum $97B5A60DBAC48E5E5B97A23ECA216963
{
  L4_SQUARE_1 = 0x1,
  L4_SQUARE_2 = 0x2,
  L4_SQUARE_3 = 0x3,
  L4_SQUARE_4 = 0x4,
  L4_SQUARE_5 = 0x5,
  L4_SQUARE_6 = 0x6,
  L4_SQUARE_7 = 0x7,
  L4_SQUARE_8 = 0x8,
  L4_SQUARE_9 = 0x9,
  L4_SQUARE_10 = 0xA,
  L4_SQUARE_11 = 0xB,
  L4_SQUARE_12 = 0xC,
  L4_SQUARE_13 = 0xD,
  L4_SQUARE_14 = 0xE,
  L4_SQUARE_15 = 0xF,
  L4_SQUARE_16 = 0x10,
  L4_SQUARE_17 = 0x11,
  L4_SQUARE_18 = 0x12,
  L4_SQUARE_19 = 0x13,
  L4_SQUARE_20 = 0x14,
  L4_SQUARE_21 = 0x15,
  L4_SQUARE_22 = 0x16,
  L4_SQUARE_23 = 0x17,
  L4_SQUARE_24 = 0x18,
  L4_SQUARE_25 = 0x19,
  L4_SQUARE_26 = 0x1A,
  L4_SQUARE_27 = 0x1B,
  L4_SQUARE_28 = 0x1C,
  L4_SQUARE_29 = 0x1D,
  L4_SQUARE_30 = 0x1E,
  L4_SQUARE_31 = 0x1F,
  L4_SQUARE_32 = 0x20,
  L4_SQUARE_33 = 0x21,
  L4_SQUARE_34 = 0x22,
  L4_SQUARE_35 = 0x23,
  L4_SQUARE_36 = 0x24,
  L4_SQUARE_37 = 0x25,
  L4_SQUARE_38 = 0x26,
  L4_SQUARE_39 = 0x27,
  L4_SQUARE_40 = 0x28,
  L4_SQUARE_41 = 0x29,
  L4_SQUARE_42 = 0x2A,
  L4_SQUARE_43 = 0x2B,
  L4_SQUARE_44 = 0x2C,
  L4_SQUARE_45 = 0x2D,
  L4_SQUARE_46 = 0x2E,
  L4_SQUARE_47 = 0x2F,
  L4_SQUARE_48 = 0x30,
  L4_SQUARE_49 = 0x31,
  L4_SQUARE_50 = 0x32,
  L4_SQUARE_51 = 0x33,
  L4_SQUARE_52 = 0x34,
  L4_SQUARE_53 = 0x35,
  L4_SQUARE_54 = 0x36,
  L4_SQUARE_55 = 0x37,
  L4_SQUARE_56 = 0x38,
  L4_SQUARE_57 = 0x39,
  L4_SQUARE_58 = 0x3A,
  L4_SQUARE_59 = 0x3B,
  L4_SQUARE_60 = 0x3C,
  L4_SQUARE_61 = 0x3D,
  L4_SQUARE_62 = 0x3E,
  L4_SQUARE_63 = 0x3F,
  L4_SQUARE_64 = 0x40,
  L4_SQUARE_65 = 0x41,
  L4_SQUARE_66 = 0x42,
  L4_SQUARE_67 = 0x43,
  L4_SQUARE_68 = 0x44,
  L4_SQUARE_69 = 0x45,
  L4_SQUARE_70 = 0x46,
  L4_SQUARE_71 = 0x47,
  L4_SQUARE_72 = 0x48,
  L4_SQUARE_73 = 0x49,
  L4_SQUARE_74 = 0x4A,
  L4_SQUARE_75 = 0x4B,
  L4_SQUARE_76 = 0x4C,
  L4_SQUARE_77 = 0x4D,
  L4_SQUARE_78 = 0x4E,
  L4_SQUARE_79 = 0x4F,
  L4_SQUARE_80 = 0x50,
  L4_SQUARE_81 = 0x51,
  L4_SQUARE_82 = 0x52,
  L4_SQUARE_83 = 0x53,
  L4_SQUARE_84 = 0x54,
  L4_SQUARE_85 = 0x55,
  L4_SQUARE_86 = 0x56,
  L4_SQUARE_87 = 0x57,
  L4_SQUARE_88 = 0x58,
  L4_SQUARE_89 = 0x59,
  L4_SQUARE_90 = 0x5A,
  L4_SQUARE_91 = 0x5B,
  L4_SQUARE_92 = 0x5C,
  L4_SQUARE_93 = 0x5D,
  L4_SQUARE_94 = 0x5E,
  L4_SQUARE_95 = 0x5F,
  L4_SQUARE_96 = 0x60,
  L4_SQUARE_97 = 0x61,
  L4_SQUARE_98 = 0x62,
  L4_SQUARE_99 = 0x63,
  L4_SQUARE_100 = 0x64,
  L4_SQUARE_101 = 0x65,
  L4_SQUARE_102 = 0x66,
  L4_SQUARE_103 = 0x67,
  L4_SQUARE_104 = 0x68,
  L4_SQUARE_105 = 0x69,
  L4_SQUARE_106 = 0x6A,
  L4_SQUARE_107 = 0x6B,
  L4_SQUARE_108 = 0x6C,
  L4_SQUARE_109 = 0x6D,
  L4_SQUARE_110 = 0x6E,
  L4_SQUARE_111 = 0x6F,
  L4_SQUARE_112 = 0x70,
  L4_SQUARE_113 = 0x71,
  L4_SQUARE_114 = 0x72,
  L4_SQUARE_115 = 0x73,
  L4_SQUARE_116 = 0x74,
  L4_SQUARE_117 = 0x75,
  L4_SQUARE_118 = 0x76,
  L4_SQUARE_119 = 0x77,
  L4_SQUARE_120 = 0x78,
  L4_SQUARE_121 = 0x79,
  L4_SQUARE_122 = 0x7A,
  L4_SQUARE_123 = 0x7B,
  L4_SQUARE_124 = 0x7C,
  L4_SQUARE_125 = 0x7D,
  L4_SQUARE_126 = 0x7E,
  L4_SQUARE_127 = 0x7F,
  L4_SQUARE_128 = 0x80,
  L4_SQUARE_129 = 0x81,
  L4_SQUARE_130 = 0x82,
  L4_SQUARE_131 = 0x83,
  L4_SQUARE_132 = 0x84,
  L4_SQUARE_133 = 0x85,
  L4_SQUARE_134 = 0x86,
  L4_SQUARE_135 = 0x87,
  L4_SQUARE_136 = 0x88,
  L4_SQUARE_137 = 0x89,
};

typedef enum $97B5A60DBAC48E5E5B97A23ECA216963 $97B5A60DBAC48E5E5B97A23ECA216963;


/* 378 */
typedef enum $97B5A60DBAC48E5E5B97A23ECA216963 l4_square;

/* 379 */
enum MACRO_DSERR_NOAGGREGATION
{
  DSERR_NOAGGREGATION = -2147221232,
  DSERR_BUFFERLOST = -2005401450,
  DSERR_OTHERAPPHASPRIO = -2005401440,
  DSERR_UNINITIALIZED = -2005401430,
};

typedef enum MACRO_DSERR_NOAGGREGATION MACRO_DSERR_NOAGGREGATION;


/* 381 */
typedef IDirectSoundBuffer *LPDIRECTSOUNDBUFFER;

/* 382 */
typedef IUnknown *LPUNKNOWN;

/* 383 */
typedef struct _DSCAPS *LPDSCAPS;

/* 385 */
typedef _GUID *LPGUID;

/* 380 */
struct IDirectSoundVtbl
{
  HRESULT (__stdcall *QueryInterface)(IDirectSound *This, const IID *const , LPVOID *);
  ULONG (__stdcall *AddRef)(IDirectSound *This);
  ULONG (__stdcall *Release)(IDirectSound *This);
  HRESULT (__stdcall *CreateSoundBuffer)(IDirectSound *This, LPCDSBUFFERDESC, LPDIRECTSOUNDBUFFER *, LPUNKNOWN);
  HRESULT (__stdcall *GetCaps)(IDirectSound *This, LPDSCAPS);
  HRESULT (__stdcall *DuplicateSoundBuffer)(IDirectSound *This, LPDIRECTSOUNDBUFFER, LPDIRECTSOUNDBUFFER *);
  HRESULT (__stdcall *SetCooperativeLevel)(IDirectSound *This, HWND, DWORD);
  HRESULT (__stdcall *Compact)(IDirectSound *This);
  HRESULT (__stdcall *GetSpeakerConfig)(IDirectSound *This, LPDWORD);
  HRESULT (__stdcall *SetSpeakerConfig)(IDirectSound *This, DWORD);
  HRESULT (__stdcall *Initialize)(IDirectSound *This, LPGUID);
};

typedef struct IDirectSoundVtbl IDirectSoundVtbl;


/* 384 */
struct _DSCAPS
{
  DWORD dwSize;
  DWORD dwFlags;
  DWORD dwMinSecondarySampleRate;
  DWORD dwMaxSecondarySampleRate;
  DWORD dwPrimaryBuffers;
  DWORD dwMaxHwMixingAllBuffers;
  DWORD dwMaxHwMixingStaticBuffers;
  DWORD dwMaxHwMixingStreamingBuffers;
  DWORD dwFreeHwMixingAllBuffers;
  DWORD dwFreeHwMixingStaticBuffers;
  DWORD dwFreeHwMixingStreamingBuffers;
  DWORD dwMaxHw3DAllBuffers;
  DWORD dwMaxHw3DStaticBuffers;
  DWORD dwMaxHw3DStreamingBuffers;
  DWORD dwFreeHw3DAllBuffers;
  DWORD dwFreeHw3DStaticBuffers;
  DWORD dwFreeHw3DStreamingBuffers;
  DWORD dwTotalHwMemBytes;
  DWORD dwFreeHwMemBytes;
  DWORD dwMaxContigFreeHwMemBytes;
  DWORD dwUnlockTransferRateHwBuffers;
  DWORD dwPlayCpuOverheadSwBuffers;
  DWORD dwReserved1;
  DWORD dwReserved2;
};

typedef struct _DSCAPS _DSCAPS;


/* 386 */
enum sound_cpp
{
  VOLUME_GET = 1,
  VOLUME_MIN = -1600,
};

typedef enum sound_cpp sound_cpp;


/* 387 */
enum game_info
{
  GAME_INFO_NAME = 1,
  GAME_INFO_PASS = 2,
};

typedef enum game_info game_info;


/* 388 */
struct Caps
{
  int32_t size;
  BYTE gap4[4];
  int max_msg_size;
  BYTE gapC[4];
  int32_t max_players;
  int field_14;
  BYTE gap18[4];
  int field_1C;
  int nturns_in_transit;
};

typedef struct Caps Caps;


/* 389 */
struct ClientInfo
{
  int32_t size;
  char *release_name;
  char *version;
  uint32_t release_id;
  int field_10;
  BYTE gap14[4];
  int field_18;
  int32_t *multi_seed;
  int field_20;
  BYTE gap24[4];
  int field_28;
  BYTE gap2C[12];
  int languageID;
};

typedef struct ClientInfo ClientInfo;


/* 390 */
struct UserInfo
{
  int32_t size;
  BYTE gap4[11];
  char field_F;
};

typedef struct UserInfo UserInfo;


/* 391 */
struct UiInfo
{
  int32_t size;
  HWND hFrameWnd;
  int UiArtCallback;
  int UiAuthCallback;
  int UiCreateGameCallback;
  int UiDrawDescCallback;
  int UiMessageBoxCallback;
  int UiSoundCallback;
  BYTE gap28[4];
  int UiGetDataCallback;
  int UiCategoryCallback;
  BYTE gap34[8];
  int UiProfileCallback;
  int UiProfileGetString;
  int UiProfileDraw;
  int mainmenu_select_hero_dialog;
  int field_4C;
};

typedef struct UiInfo UiInfo;


/* 392 */
struct FileInfo
{
  int32_t size;
  char *version;
  char *diablo_exe_path;
  char *diabdat_mpq_path;
  char *patch_mpq_path;
};

typedef struct FileInfo FileInfo;


/* 394 */

/* 395 */
enum MACRO_FS
{
  FS_CASE_IS_PRESERVED = 2,
  FS_CASE_SENSITIVE = 1,
  FS_UNICODE_STORED_ON_DISK = 4,
  FS_PERSISTENT_ACLS = 8,
  FS_VOL_IS_COMPRESSED = 32768,
  FS_FILE_COMPRESSION = 16,
  FS_FILE_ENCRYPTION = 131072,
  FILE_MAP_COPY = 1,
  FILE_MAP_WRITE = 2,
  FILE_MAP_READ = 4,
  FILE_MAP_ALL_ACCESS = 983071,
  FILE_MAP_EXECUTE = 32,
};

typedef enum MACRO_FS MACRO_FS;


/* 396 */
enum MACRO_ERROR
{
  ERROR_SUCCESS = 0,
  ERROR_INVALID_FUNCTION = 1,
  ERROR_FILE_NOT_FOUND = 2,
  ERROR_PATH_NOT_FOUND = 3,
  ERROR_TOO_MANY_OPEN_FILES = 4,
  ERROR_ACCESS_DENIED = 5,
  ERROR_INVALID_HANDLE = 6,
  ERROR_ARENA_TRASHED = 7,
  ERROR_NOT_ENOUGH_MEMORY = 8,
  ERROR_INVALID_BLOCK = 9,
  ERROR_BAD_ENVIRONMENT = 10,
  ERROR_BAD_FORMAT = 11,
  ERROR_INVALID_ACCESS = 12,
  ERROR_INVALID_DATA = 13,
  ERROR_OUTOFMEMORY = 14,
  ERROR_INVALID_DRIVE = 15,
  ERROR_CURRENT_DIRECTORY = 16,
  ERROR_NOT_SAME_DEVICE = 17,
  ERROR_NO_MORE_FILES = 18,
  ERROR_WRITE_PROTECT = 19,
  ERROR_BAD_UNIT = 20,
  ERROR_NOT_READY = 21,
  ERROR_BAD_COMMAND = 22,
  ERROR_CRC = 23,
  ERROR_BAD_LENGTH = 24,
  ERROR_SEEK = 25,
  ERROR_NOT_DOS_DISK = 26,
  ERROR_SECTOR_NOT_FOUND = 27,
  ERROR_OUT_OF_PAPER = 28,
  ERROR_WRITE_FAULT = 29,
  ERROR_READ_FAULT = 30,
  ERROR_GEN_FAILURE = 31,
  ERROR_SHARING_VIOLATION = 32,
  ERROR_LOCK_VIOLATION = 33,
  ERROR_WRONG_DISK = 34,
  ERROR_SHARING_BUFFER_EXCEEDED = 36,
  ERROR_HANDLE_EOF = 38,
  ERROR_HANDLE_DISK_FULL = 39,
  ERROR_NOT_SUPPORTED = 50,
  ERROR_REM_NOT_LIST = 51,
  ERROR_DUP_NAME = 52,
  ERROR_BAD_NETPATH = 53,
  ERROR_NETWORK_BUSY = 54,
  ERROR_DEV_NOT_EXIST = 55,
  ERROR_TOO_MANY_CMDS = 56,
  ERROR_ADAP_HDW_ERR = 57,
  ERROR_BAD_NET_RESP = 58,
  ERROR_UNEXP_NET_ERR = 59,
  ERROR_BAD_REM_ADAP = 60,
  ERROR_PRINTQ_FULL = 61,
  ERROR_NO_SPOOL_SPACE = 62,
  ERROR_PRINT_CANCELLED = 63,
  ERROR_NETNAME_DELETED = 64,
  ERROR_NETWORK_ACCESS_DENIED = 65,
  ERROR_BAD_DEV_TYPE = 66,
  ERROR_BAD_NET_NAME = 67,
  ERROR_TOO_MANY_NAMES = 68,
  ERROR_TOO_MANY_SESS = 69,
  ERROR_SHARING_PAUSED = 70,
  ERROR_REQ_NOT_ACCEP = 71,
  ERROR_REDIR_PAUSED = 72,
  ERROR_FILE_EXISTS = 80,
  ERROR_CANNOT_MAKE = 82,
  ERROR_FAIL_I24 = 83,
  ERROR_OUT_OF_STRUCTURES = 84,
  ERROR_ALREADY_ASSIGNED = 85,
  ERROR_INVALID_PASSWORD = 86,
  ERROR_INVALID_PARAMETER = 87,
  ERROR_NET_WRITE_FAULT = 88,
  ERROR_NO_PROC_SLOTS = 89,
  ERROR_TOO_MANY_SEMAPHORES = 100,
  ERROR_EXCL_SEM_ALREADY_OWNED = 101,
  ERROR_SEM_IS_SET = 102,
  ERROR_TOO_MANY_SEM_REQUESTS = 103,
  ERROR_INVALID_AT_INTERRUPT_TIME = 104,
  ERROR_SEM_OWNER_DIED = 105,
  ERROR_SEM_USER_LIMIT = 106,
  ERROR_DISK_CHANGE = 107,
  ERROR_DRIVE_LOCKED = 108,
  ERROR_BROKEN_PIPE = 109,
  ERROR_OPEN_FAILED = 110,
  ERROR_BUFFER_OVERFLOW = 111,
  ERROR_DISK_FULL = 112,
  ERROR_NO_MORE_SEARCH_HANDLES = 113,
  ERROR_INVALID_TARGET_HANDLE = 114,
  ERROR_INVALID_CATEGORY = 117,
  ERROR_INVALID_VERIFY_SWITCH = 118,
  ERROR_BAD_DRIVER_LEVEL = 119,
  ERROR_CALL_NOT_IMPLEMENTED = 120,
  ERROR_SEM_TIMEOUT = 121,
  ERROR_INSUFFICIENT_BUFFER = 122,
  ERROR_INVALID_NAME = 123,
  ERROR_INVALID_LEVEL = 124,
  ERROR_NO_VOLUME_LABEL = 125,
  ERROR_MOD_NOT_FOUND = 126,
  ERROR_PROC_NOT_FOUND = 127,
  ERROR_WAIT_NO_CHILDREN = 128,
  ERROR_CHILD_NOT_COMPLETE = 129,
  ERROR_DIRECT_ACCESS_HANDLE = 130,
  ERROR_NEGATIVE_SEEK = 131,
  ERROR_SEEK_ON_DEVICE = 132,
  ERROR_IS_JOIN_TARGET = 133,
  ERROR_IS_JOINED = 134,
  ERROR_IS_SUBSTED = 135,
  ERROR_NOT_JOINED = 136,
  ERROR_NOT_SUBSTED = 137,
  ERROR_JOIN_TO_JOIN = 138,
  ERROR_SUBST_TO_SUBST = 139,
  ERROR_JOIN_TO_SUBST = 140,
  ERROR_SUBST_TO_JOIN = 141,
  ERROR_BUSY_DRIVE = 142,
  ERROR_SAME_DRIVE = 143,
  ERROR_DIR_NOT_ROOT = 144,
  ERROR_DIR_NOT_EMPTY = 145,
  ERROR_IS_SUBST_PATH = 146,
  ERROR_IS_JOIN_PATH = 147,
  ERROR_PATH_BUSY = 148,
  ERROR_IS_SUBST_TARGET = 149,
  ERROR_SYSTEM_TRACE = 150,
  ERROR_INVALID_EVENT_COUNT = 151,
  ERROR_TOO_MANY_MUXWAITERS = 152,
  ERROR_INVALID_LIST_FORMAT = 153,
  ERROR_LABEL_TOO_LONG = 154,
  ERROR_TOO_MANY_TCBS = 155,
  ERROR_SIGNAL_REFUSED = 156,
  ERROR_DISCARDED = 157,
  ERROR_NOT_LOCKED = 158,
  ERROR_BAD_THREADID_ADDR = 159,
  ERROR_BAD_ARGUMENTS = 160,
  ERROR_BAD_PATHNAME = 161,
  ERROR_SIGNAL_PENDING = 162,
  ERROR_MAX_THRDS_REACHED = 164,
  ERROR_LOCK_FAILED = 167,
  ERROR_BUSY = 170,
  ERROR_CANCEL_VIOLATION = 173,
  ERROR_ATOMIC_LOCKS_NOT_SUPPORTED = 174,
  ERROR_INVALID_SEGMENT_NUMBER = 180,
  ERROR_INVALID_ORDINAL = 182,
  ERROR_ALREADY_EXISTS = 183,
  ERROR_INVALID_FLAG_NUMBER = 186,
  ERROR_SEM_NOT_FOUND = 187,
  ERROR_INVALID_STARTING_CODESEG = 188,
  ERROR_INVALID_STACKSEG = 189,
  ERROR_INVALID_MODULETYPE = 190,
  ERROR_INVALID_EXE_SIGNATURE = 191,
  ERROR_EXE_MARKED_INVALID = 192,
  ERROR_BAD_EXE_FORMAT = 193,
  ERROR_ITERATED_DATA_EXCEEDS_64k = 194,
  ERROR_INVALID_MINALLOCSIZE = 195,
  ERROR_DYNLINK_FROM_INVALID_RING = 196,
  ERROR_IOPL_NOT_ENABLED = 197,
  ERROR_INVALID_SEGDPL = 198,
  ERROR_AUTODATASEG_EXCEEDS_64k = 199,
  ERROR_RING2SEG_MUST_BE_MOVABLE = 200,
  ERROR_RELOC_CHAIN_XEEDS_SEGLIM = 201,
  ERROR_INFLOOP_IN_RELOC_CHAIN = 202,
  ERROR_ENVVAR_NOT_FOUND = 203,
  ERROR_NO_SIGNAL_SENT = 205,
  ERROR_FILENAME_EXCED_RANGE = 206,
  ERROR_RING2_STACK_IN_USE = 207,
  ERROR_META_EXPANSION_TOO_LONG = 208,
  ERROR_INVALID_SIGNAL_NUMBER = 209,
  ERROR_THREAD_1_INACTIVE = 210,
  ERROR_LOCKED = 212,
  ERROR_TOO_MANY_MODULES = 214,
  ERROR_NESTING_NOT_ALLOWED = 215,
  ERROR_EXE_MACHINE_TYPE_MISMATCH = 216,
  ERROR_EXE_CANNOT_MODIFY_SIGNED_BINARY = 217,
  ERROR_EXE_CANNOT_MODIFY_STRONG_SIGNED_BINARY = 218,
  ERROR_FILE_CHECKED_OUT = 220,
  ERROR_CHECKOUT_REQUIRED = 221,
  ERROR_BAD_FILE_TYPE = 222,
  ERROR_FILE_TOO_LARGE = 223,
  ERROR_FORMS_AUTH_REQUIRED = 224,
  ERROR_VIRUS_INFECTED = 225,
  ERROR_VIRUS_DELETED = 226,
  ERROR_PIPE_LOCAL = 229,
  ERROR_BAD_PIPE = 230,
  ERROR_PIPE_BUSY = 231,
  ERROR_NO_DATA = 232,
  ERROR_PIPE_NOT_CONNECTED = 233,
  ERROR_MORE_DATA = 234,
  ERROR_VC_DISCONNECTED = 240,
  ERROR_INVALID_EA_NAME = 254,
  ERROR_EA_LIST_INCONSISTENT = 255,
  WAIT_TIMEOUT = 258,
  ERROR_NO_MORE_ITEMS = 259,
  ERROR_CANNOT_COPY = 266,
  ERROR_DIRECTORY = 267,
  ERROR_EAS_DIDNT_FIT = 275,
  ERROR_EA_FILE_CORRUPT = 276,
  ERROR_EA_TABLE_FULL = 277,
  ERROR_INVALID_EA_HANDLE = 278,
  ERROR_EAS_NOT_SUPPORTED = 282,
  ERROR_NOT_OWNER = 288,
  ERROR_TOO_MANY_POSTS = 298,
  ERROR_PARTIAL_COPY = 299,
  ERROR_OPLOCK_NOT_GRANTED = 300,
  ERROR_INVALID_OPLOCK_PROTOCOL = 301,
  ERROR_DISK_TOO_FRAGMENTED = 302,
  ERROR_DELETE_PENDING = 303,
  ERROR_INCOMPATIBLE_WITH_GLOBAL_SHORT_NAME_REGISTRY_SETTING = 304,
  ERROR_SHORT_NAMES_NOT_ENABLED_ON_VOLUME = 305,
  ERROR_SECURITY_STREAM_IS_INCONSISTENT = 306,
  ERROR_INVALID_LOCK_RANGE = 307,
  ERROR_IMAGE_SUBSYSTEM_NOT_PRESENT = 308,
  ERROR_NOTIFICATION_GUID_ALREADY_DEFINED = 309,
  ERROR_MR_MID_NOT_FOUND = 317,
  ERROR_SCOPE_NOT_FOUND = 318,
  ERROR_FAIL_NOACTION_REBOOT = 350,
  ERROR_FAIL_SHUTDOWN = 351,
  ERROR_FAIL_RESTART = 352,
  ERROR_MAX_SESSIONS_REACHED = 353,
  ERROR_THREAD_MODE_ALREADY_BACKGROUND = 400,
  ERROR_THREAD_MODE_NOT_BACKGROUND = 401,
  ERROR_PROCESS_MODE_ALREADY_BACKGROUND = 402,
  ERROR_PROCESS_MODE_NOT_BACKGROUND = 403,
  ERROR_INVALID_ADDRESS = 487,
  ERROR_USER_PROFILE_LOAD = 500,
  ERROR_ARITHMETIC_OVERFLOW = 534,
  ERROR_PIPE_CONNECTED = 535,
  ERROR_PIPE_LISTENING = 536,
  ERROR_VERIFIER_STOP = 537,
  ERROR_ABIOS_ERROR = 538,
  ERROR_WX86_WARNING = 539,
  ERROR_WX86_ERROR = 540,
  ERROR_TIMER_NOT_CANCELED = 541,
  ERROR_UNWIND = 542,
  ERROR_BAD_STACK = 543,
  ERROR_INVALID_UNWIND_TARGET = 544,
  ERROR_INVALID_PORT_ATTRIBUTES = 545,
  ERROR_PORT_MESSAGE_TOO_LONG = 546,
  ERROR_INVALID_QUOTA_LOWER = 547,
  ERROR_DEVICE_ALREADY_ATTACHED = 548,
  ERROR_INSTRUCTION_MISALIGNMENT = 549,
  ERROR_PROFILING_NOT_STARTED = 550,
  ERROR_PROFILING_NOT_STOPPED = 551,
  ERROR_COULD_NOT_INTERPRET = 552,
  ERROR_PROFILING_AT_LIMIT = 553,
  ERROR_CANT_WAIT = 554,
  ERROR_CANT_TERMINATE_SELF = 555,
  ERROR_UNEXPECTED_MM_CREATE_ERR = 556,
  ERROR_UNEXPECTED_MM_MAP_ERROR = 557,
  ERROR_UNEXPECTED_MM_EXTEND_ERR = 558,
  ERROR_BAD_FUNCTION_TABLE = 559,
  ERROR_NO_GUID_TRANSLATION = 560,
  ERROR_INVALID_LDT_SIZE = 561,
  ERROR_INVALID_LDT_OFFSET = 563,
  ERROR_INVALID_LDT_DESCRIPTOR = 564,
  ERROR_TOO_MANY_THREADS = 565,
  ERROR_THREAD_NOT_IN_PROCESS = 566,
  ERROR_PAGEFILE_QUOTA_EXCEEDED = 567,
  ERROR_LOGON_SERVER_CONFLICT = 568,
  ERROR_SYNCHRONIZATION_REQUIRED = 569,
  ERROR_NET_OPEN_FAILED = 570,
  ERROR_IO_PRIVILEGE_FAILED = 571,
  ERROR_CONTROL_C_EXIT = 572,
  ERROR_MISSING_SYSTEMFILE = 573,
  ERROR_UNHANDLED_EXCEPTION = 574,
  ERROR_APP_INIT_FAILURE = 575,
  ERROR_PAGEFILE_CREATE_FAILED = 576,
  ERROR_INVALID_IMAGE_HASH = 577,
  ERROR_NO_PAGEFILE = 578,
  ERROR_ILLEGAL_FLOAT_CONTEXT = 579,
  ERROR_NO_EVENT_PAIR = 580,
  ERROR_DOMAIN_CTRLR_CONFIG_ERROR = 581,
  ERROR_ILLEGAL_CHARACTER = 582,
  ERROR_UNDEFINED_CHARACTER = 583,
  ERROR_FLOPPY_VOLUME = 584,
  ERROR_BIOS_FAILED_TO_CONNECT_INTERRUPT = 585,
  ERROR_BACKUP_CONTROLLER = 586,
  ERROR_MUTANT_LIMIT_EXCEEDED = 587,
  ERROR_FS_DRIVER_REQUIRED = 588,
  ERROR_CANNOT_LOAD_REGISTRY_FILE = 589,
  ERROR_DEBUG_ATTACH_FAILED = 590,
  ERROR_SYSTEM_PROCESS_TERMINATED = 591,
  ERROR_DATA_NOT_ACCEPTED = 592,
  ERROR_VDM_HARD_ERROR = 593,
  ERROR_DRIVER_CANCEL_TIMEOUT = 594,
  ERROR_REPLY_MESSAGE_MISMATCH = 595,
  ERROR_LOST_WRITEBEHIND_DATA = 596,
  ERROR_CLIENT_SERVER_PARAMETERS_INVALID = 597,
  ERROR_NOT_TINY_STREAM = 598,
  ERROR_STACK_OVERFLOW_READ = 599,
  ERROR_CONVERT_TO_LARGE = 600,
  ERROR_FOUND_OUT_OF_SCOPE = 601,
  ERROR_ALLOCATE_BUCKET = 602,
  ERROR_MARSHALL_OVERFLOW = 603,
  ERROR_INVALID_VARIANT = 604,
  ERROR_BAD_COMPRESSION_BUFFER = 605,
  ERROR_AUDIT_FAILED = 606,
  ERROR_TIMER_RESOLUTION_NOT_SET = 607,
  ERROR_INSUFFICIENT_LOGON_INFO = 608,
  ERROR_BAD_DLL_ENTRYPOINT = 609,
  ERROR_BAD_SERVICE_ENTRYPOINT = 610,
  ERROR_IP_ADDRESS_CONFLICT1 = 611,
  ERROR_IP_ADDRESS_CONFLICT2 = 612,
  ERROR_REGISTRY_QUOTA_LIMIT = 613,
  ERROR_NO_CALLBACK_ACTIVE = 614,
  ERROR_PWD_TOO_SHORT = 615,
  ERROR_PWD_TOO_RECENT = 616,
  ERROR_PWD_HISTORY_CONFLICT = 617,
  ERROR_UNSUPPORTED_COMPRESSION = 618,
  ERROR_INVALID_HW_PROFILE = 619,
  ERROR_INVALID_PLUGPLAY_DEVICE_PATH = 620,
  ERROR_QUOTA_LIST_INCONSISTENT = 621,
  ERROR_EVALUATION_EXPIRATION = 622,
  ERROR_ILLEGAL_DLL_RELOCATION = 623,
  ERROR_DLL_INIT_FAILED_LOGOFF = 624,
  ERROR_VALIDATE_CONTINUE = 625,
  ERROR_NO_MORE_MATCHES = 626,
  ERROR_RANGE_LIST_CONFLICT = 627,
  ERROR_SERVER_SID_MISMATCH = 628,
  ERROR_CANT_ENABLE_DENY_ONLY = 629,
  ERROR_FLOAT_MULTIPLE_FAULTS = 630,
  ERROR_FLOAT_MULTIPLE_TRAPS = 631,
  ERROR_NOINTERFACE = 632,
  ERROR_DRIVER_FAILED_SLEEP = 633,
  ERROR_CORRUPT_SYSTEM_FILE = 634,
  ERROR_COMMITMENT_MINIMUM = 635,
  ERROR_PNP_RESTART_ENUMERATION = 636,
  ERROR_SYSTEM_IMAGE_BAD_SIGNATURE = 637,
  ERROR_PNP_REBOOT_REQUIRED = 638,
  ERROR_INSUFFICIENT_POWER = 639,
  ERROR_MULTIPLE_FAULT_VIOLATION = 640,
  ERROR_SYSTEM_SHUTDOWN = 641,
  ERROR_PORT_NOT_SET = 642,
  ERROR_DS_VERSION_CHECK_FAILURE = 643,
  ERROR_RANGE_NOT_FOUND = 644,
  ERROR_NOT_SAFE_MODE_DRIVER = 646,
  ERROR_FAILED_DRIVER_ENTRY = 647,
  ERROR_DEVICE_ENUMERATION_ERROR = 648,
  ERROR_MOUNT_POINT_NOT_RESOLVED = 649,
  ERROR_INVALID_DEVICE_OBJECT_PARAMETER = 650,
  ERROR_MCA_OCCURED = 651,
  ERROR_DRIVER_DATABASE_ERROR = 652,
  ERROR_SYSTEM_HIVE_TOO_LARGE = 653,
  ERROR_DRIVER_FAILED_PRIOR_UNLOAD = 654,
  ERROR_VOLSNAP_PREPARE_HIBERNATE = 655,
  ERROR_HIBERNATION_FAILURE = 656,
  ERROR_FILE_SYSTEM_LIMITATION = 665,
  ERROR_ASSERTION_FAILURE = 668,
  ERROR_ACPI_ERROR = 669,
  ERROR_WOW_ASSERTION = 670,
  ERROR_PNP_BAD_MPS_TABLE = 671,
  ERROR_PNP_TRANSLATION_FAILED = 672,
  ERROR_PNP_IRQ_TRANSLATION_FAILED = 673,
  ERROR_PNP_INVALID_ID = 674,
  ERROR_WAKE_SYSTEM_DEBUGGER = 675,
  ERROR_HANDLES_CLOSED = 676,
  ERROR_EXTRANEOUS_INFORMATION = 677,
  ERROR_RXACT_COMMIT_NECESSARY = 678,
  ERROR_MEDIA_CHECK = 679,
  ERROR_GUID_SUBSTITUTION_MADE = 680,
  ERROR_STOPPED_ON_SYMLINK = 681,
  ERROR_LONGJUMP = 682,
  ERROR_PLUGPLAY_QUERY_VETOED = 683,
  ERROR_UNWIND_CONSOLIDATE = 684,
  ERROR_REGISTRY_HIVE_RECOVERED = 685,
  ERROR_DLL_MIGHT_BE_INSECURE = 686,
  ERROR_DLL_MIGHT_BE_INCOMPATIBLE = 687,
  ERROR_DBG_EXCEPTION_NOT_HANDLED = 688,
  ERROR_DBG_REPLY_LATER = 689,
  ERROR_DBG_UNABLE_TO_PROVIDE_HANDLE = 690,
  ERROR_DBG_TERMINATE_THREAD = 691,
  ERROR_DBG_TERMINATE_PROCESS = 692,
  ERROR_DBG_CONTROL_C = 693,
  ERROR_DBG_PRINTEXCEPTION_C = 694,
  ERROR_DBG_RIPEXCEPTION = 695,
  ERROR_DBG_CONTROL_BREAK = 696,
  ERROR_DBG_COMMAND_EXCEPTION = 697,
  ERROR_OBJECT_NAME_EXISTS = 698,
  ERROR_THREAD_WAS_SUSPENDED = 699,
  ERROR_IMAGE_NOT_AT_BASE = 700,
  ERROR_RXACT_STATE_CREATED = 701,
  ERROR_SEGMENT_NOTIFICATION = 702,
  ERROR_BAD_CURRENT_DIRECTORY = 703,
  ERROR_FT_READ_RECOVERY_FROM_BACKUP = 704,
  ERROR_FT_WRITE_RECOVERY = 705,
  ERROR_IMAGE_MACHINE_TYPE_MISMATCH = 706,
  ERROR_RECEIVE_PARTIAL = 707,
  ERROR_RECEIVE_EXPEDITED = 708,
  ERROR_RECEIVE_PARTIAL_EXPEDITED = 709,
  ERROR_EVENT_DONE = 710,
  ERROR_EVENT_PENDING = 711,
  ERROR_CHECKING_FILE_SYSTEM = 712,
  ERROR_FATAL_APP_EXIT = 713,
  ERROR_PREDEFINED_HANDLE = 714,
  ERROR_WAS_UNLOCKED = 715,
  ERROR_SERVICE_NOTIFICATION = 716,
  ERROR_WAS_LOCKED = 717,
  ERROR_LOG_HARD_ERROR = 718,
  ERROR_ALREADY_WIN32 = 719,
  ERROR_IMAGE_MACHINE_TYPE_MISMATCH_EXE = 720,
  ERROR_NO_YIELD_PERFORMED = 721,
  ERROR_TIMER_RESUME_IGNORED = 722,
  ERROR_ARBITRATION_UNHANDLED = 723,
  ERROR_CARDBUS_NOT_SUPPORTED = 724,
  ERROR_MP_PROCESSOR_MISMATCH = 725,
  ERROR_HIBERNATED = 726,
  ERROR_RESUME_HIBERNATION = 727,
  ERROR_FIRMWARE_UPDATED = 728,
  ERROR_DRIVERS_LEAKING_LOCKED_PAGES = 729,
  ERROR_WAKE_SYSTEM = 730,
  ERROR_WAIT_1 = 731,
  ERROR_WAIT_2 = 732,
  ERROR_WAIT_3 = 733,
  ERROR_WAIT_63 = 734,
  ERROR_ABANDONED_WAIT_0 = 735,
  ERROR_ABANDONED_WAIT_63 = 736,
  ERROR_USER_APC = 737,
  ERROR_KERNEL_APC = 738,
  ERROR_ALERTED = 739,
  ERROR_ELEVATION_REQUIRED = 740,
  ERROR_REPARSE = 741,
  ERROR_OPLOCK_BREAK_IN_PROGRESS = 742,
  ERROR_VOLUME_MOUNTED = 743,
  ERROR_RXACT_COMMITTED = 744,
  ERROR_NOTIFY_CLEANUP = 745,
  ERROR_PRIMARY_TRANSPORT_CONNECT_FAILED = 746,
  ERROR_PAGE_FAULT_TRANSITION = 747,
  ERROR_PAGE_FAULT_DEMAND_ZERO = 748,
  ERROR_PAGE_FAULT_COPY_ON_WRITE = 749,
  ERROR_PAGE_FAULT_GUARD_PAGE = 750,
  ERROR_PAGE_FAULT_PAGING_FILE = 751,
  ERROR_CACHE_PAGE_LOCKED = 752,
  ERROR_CRASH_DUMP = 753,
  ERROR_BUFFER_ALL_ZEROS = 754,
  ERROR_REPARSE_OBJECT = 755,
  ERROR_RESOURCE_REQUIREMENTS_CHANGED = 756,
  ERROR_TRANSLATION_COMPLETE = 757,
  ERROR_NOTHING_TO_TERMINATE = 758,
  ERROR_PROCESS_NOT_IN_JOB = 759,
  ERROR_PROCESS_IN_JOB = 760,
  ERROR_VOLSNAP_HIBERNATE_READY = 761,
  ERROR_FSFILTER_OP_COMPLETED_SUCCESSFULLY = 762,
  ERROR_INTERRUPT_VECTOR_ALREADY_CONNECTED = 763,
  ERROR_INTERRUPT_STILL_CONNECTED = 764,
  ERROR_WAIT_FOR_OPLOCK = 765,
  ERROR_DBG_EXCEPTION_HANDLED = 766,
  ERROR_DBG_CONTINUE = 767,
  ERROR_CALLBACK_POP_STACK = 768,
  ERROR_COMPRESSION_DISABLED = 769,
  ERROR_CANTFETCHBACKWARDS = 770,
  ERROR_CANTSCROLLBACKWARDS = 771,
  ERROR_ROWSNOTRELEASED = 772,
  ERROR_BAD_ACCESSOR_FLAGS = 773,
  ERROR_ERRORS_ENCOUNTERED = 774,
  ERROR_NOT_CAPABLE = 775,
  ERROR_REQUEST_OUT_OF_SEQUENCE = 776,
  ERROR_VERSION_PARSE_ERROR = 777,
  ERROR_BADSTARTPOSITION = 778,
  ERROR_MEMORY_HARDWARE = 779,
  ERROR_DISK_REPAIR_DISABLED = 780,
  ERROR_INSUFFICIENT_RESOURCE_FOR_SPECIFIED_SHARED_SECTION_SIZE = 781,
  ERROR_SYSTEM_POWERSTATE_TRANSITION = 782,
  ERROR_SYSTEM_POWERSTATE_COMPLEX_TRANSITION = 783,
  ERROR_MCA_EXCEPTION = 784,
  ERROR_ACCESS_AUDIT_BY_POLICY = 785,
  ERROR_ACCESS_DISABLED_NO_SAFER_UI_BY_POLICY = 786,
  ERROR_ABANDON_HIBERFILE = 787,
  ERROR_LOST_WRITEBEHIND_DATA_NETWORK_DISCONNECTED = 788,
  ERROR_LOST_WRITEBEHIND_DATA_NETWORK_SERVER_ERROR = 789,
  ERROR_LOST_WRITEBEHIND_DATA_LOCAL_DISK_ERROR = 790,
  ERROR_BAD_MCFG_TABLE = 791,
  ERROR_OPLOCK_SWITCHED_TO_NEW_HANDLE = 800,
  ERROR_CANNOT_GRANT_REQUESTED_OPLOCK = 801,
  ERROR_CANNOT_BREAK_OPLOCK = 802,
  ERROR_OPLOCK_HANDLE_CLOSED = 803,
  ERROR_NO_ACE_CONDITION = 804,
  ERROR_INVALID_ACE_CONDITION = 805,
  ERROR_EA_ACCESS_DENIED = 994,
  ERROR_OPERATION_ABORTED = 995,
  ERROR_IO_INCOMPLETE = 996,
  ERROR_IO_PENDING = 997,
  ERROR_NOACCESS = 998,
  ERROR_SWAPERROR = 999,
  ERROR_STACK_OVERFLOW = 1001,
  ERROR_INVALID_MESSAGE = 1002,
  ERROR_CAN_NOT_COMPLETE = 1003,
  ERROR_INVALID_FLAGS = 1004,
  ERROR_UNRECOGNIZED_VOLUME = 1005,
  ERROR_FILE_INVALID = 1006,
  ERROR_FULLSCREEN_MODE = 1007,
  ERROR_NO_TOKEN = 1008,
  ERROR_BADDB = 1009,
  ERROR_BADKEY = 1010,
  ERROR_CANTOPEN = 1011,
  ERROR_CANTREAD = 1012,
  ERROR_CANTWRITE = 1013,
  ERROR_REGISTRY_RECOVERED = 1014,
  ERROR_REGISTRY_CORRUPT = 1015,
  ERROR_REGISTRY_IO_FAILED = 1016,
  ERROR_NOT_REGISTRY_FILE = 1017,
  ERROR_KEY_DELETED = 1018,
  ERROR_NO_LOG_SPACE = 1019,
  ERROR_KEY_HAS_CHILDREN = 1020,
  ERROR_CHILD_MUST_BE_VOLATILE = 1021,
  ERROR_NOTIFY_ENUM_DIR = 1022,
  ERROR_DEPENDENT_SERVICES_RUNNING = 1051,
  ERROR_INVALID_SERVICE_CONTROL = 1052,
  ERROR_SERVICE_REQUEST_TIMEOUT = 1053,
  ERROR_SERVICE_NO_THREAD = 1054,
  ERROR_SERVICE_DATABASE_LOCKED = 1055,
  ERROR_SERVICE_ALREADY_RUNNING = 1056,
  ERROR_INVALID_SERVICE_ACCOUNT = 1057,
  ERROR_SERVICE_DISABLED = 1058,
  ERROR_CIRCULAR_DEPENDENCY = 1059,
  ERROR_SERVICE_DOES_NOT_EXIST = 1060,
  ERROR_SERVICE_CANNOT_ACCEPT_CTRL = 1061,
  ERROR_SERVICE_NOT_ACTIVE = 1062,
  ERROR_FAILED_SERVICE_CONTROLLER_CONNECT = 1063,
  ERROR_EXCEPTION_IN_SERVICE = 1064,
  ERROR_DATABASE_DOES_NOT_EXIST = 1065,
  ERROR_SERVICE_SPECIFIC_ERROR = 1066,
  ERROR_PROCESS_ABORTED = 1067,
  ERROR_SERVICE_DEPENDENCY_FAIL = 1068,
  ERROR_SERVICE_LOGON_FAILED = 1069,
  ERROR_SERVICE_START_HANG = 1070,
  ERROR_INVALID_SERVICE_LOCK = 1071,
  ERROR_SERVICE_MARKED_FOR_DELETE = 1072,
  ERROR_SERVICE_EXISTS = 1073,
  ERROR_ALREADY_RUNNING_LKG = 1074,
  ERROR_SERVICE_DEPENDENCY_DELETED = 1075,
  ERROR_BOOT_ALREADY_ACCEPTED = 1076,
  ERROR_SERVICE_NEVER_STARTED = 1077,
  ERROR_DUPLICATE_SERVICE_NAME = 1078,
  ERROR_DIFFERENT_SERVICE_ACCOUNT = 1079,
  ERROR_CANNOT_DETECT_DRIVER_FAILURE = 1080,
  ERROR_CANNOT_DETECT_PROCESS_ABORT = 1081,
  ERROR_NO_RECOVERY_PROGRAM = 1082,
  ERROR_SERVICE_NOT_IN_EXE = 1083,
  ERROR_NOT_SAFEBOOT_SERVICE = 1084,
  ERROR_END_OF_MEDIA = 1100,
  ERROR_FILEMARK_DETECTED = 1101,
  ERROR_BEGINNING_OF_MEDIA = 1102,
  ERROR_SETMARK_DETECTED = 1103,
  ERROR_NO_DATA_DETECTED = 1104,
  ERROR_PARTITION_FAILURE = 1105,
  ERROR_INVALID_BLOCK_LENGTH = 1106,
  ERROR_DEVICE_NOT_PARTITIONED = 1107,
  ERROR_UNABLE_TO_LOCK_MEDIA = 1108,
  ERROR_UNABLE_TO_UNLOAD_MEDIA = 1109,
  ERROR_MEDIA_CHANGED = 1110,
  ERROR_BUS_RESET = 1111,
  ERROR_NO_MEDIA_IN_DRIVE = 1112,
  ERROR_NO_UNICODE_TRANSLATION = 1113,
  ERROR_DLL_INIT_FAILED = 1114,
  ERROR_SHUTDOWN_IN_PROGRESS = 1115,
  ERROR_NO_SHUTDOWN_IN_PROGRESS = 1116,
  ERROR_IO_DEVICE = 1117,
  ERROR_SERIAL_NO_DEVICE = 1118,
  ERROR_IRQ_BUSY = 1119,
  ERROR_MORE_WRITES = 1120,
  ERROR_COUNTER_TIMEOUT = 1121,
  ERROR_FLOPPY_ID_MARK_NOT_FOUND = 1122,
  ERROR_FLOPPY_WRONG_CYLINDER = 1123,
  ERROR_FLOPPY_UNKNOWN_ERROR = 1124,
  ERROR_FLOPPY_BAD_REGISTERS = 1125,
  ERROR_DISK_RECALIBRATE_FAILED = 1126,
  ERROR_DISK_OPERATION_FAILED = 1127,
  ERROR_DISK_RESET_FAILED = 1128,
  ERROR_EOM_OVERFLOW = 1129,
  ERROR_NOT_ENOUGH_SERVER_MEMORY = 1130,
  ERROR_POSSIBLE_DEADLOCK = 1131,
  ERROR_MAPPED_ALIGNMENT = 1132,
  ERROR_SET_POWER_STATE_VETOED = 1140,
  ERROR_SET_POWER_STATE_FAILED = 1141,
  ERROR_TOO_MANY_LINKS = 1142,
  ERROR_OLD_WIN_VERSION = 1150,
  ERROR_APP_WRONG_OS = 1151,
  ERROR_SINGLE_INSTANCE_APP = 1152,
  ERROR_RMODE_APP = 1153,
  ERROR_INVALID_DLL = 1154,
  ERROR_NO_ASSOCIATION = 1155,
  ERROR_DDE_FAIL = 1156,
  ERROR_DLL_NOT_FOUND = 1157,
  ERROR_NO_MORE_USER_HANDLES = 1158,
  ERROR_MESSAGE_SYNC_ONLY = 1159,
  ERROR_SOURCE_ELEMENT_EMPTY = 1160,
  ERROR_DESTINATION_ELEMENT_FULL = 1161,
  ERROR_ILLEGAL_ELEMENT_ADDRESS = 1162,
  ERROR_MAGAZINE_NOT_PRESENT = 1163,
  ERROR_DEVICE_REINITIALIZATION_NEEDED = 1164,
  ERROR_DEVICE_REQUIRES_CLEANING = 1165,
  ERROR_DEVICE_DOOR_OPEN = 1166,
  ERROR_DEVICE_NOT_CONNECTED = 1167,
  ERROR_NOT_FOUND = 1168,
  ERROR_NO_MATCH = 1169,
  ERROR_SET_NOT_FOUND = 1170,
  ERROR_POINT_NOT_FOUND = 1171,
  ERROR_NO_TRACKING_SERVICE = 1172,
  ERROR_NO_VOLUME_ID = 1173,
  ERROR_UNABLE_TO_REMOVE_REPLACED = 1175,
  ERROR_UNABLE_TO_MOVE_REPLACEMENT = 1176,
  ERROR_UNABLE_TO_MOVE_REPLACEMENT_2 = 1177,
  ERROR_JOURNAL_DELETE_IN_PROGRESS = 1178,
  ERROR_JOURNAL_NOT_ACTIVE = 1179,
  ERROR_POTENTIAL_FILE_FOUND = 1180,
  ERROR_JOURNAL_ENTRY_DELETED = 1181,
  ERROR_SHUTDOWN_IS_SCHEDULED = 1190,
  ERROR_SHUTDOWN_USERS_LOGGED_ON = 1191,
  ERROR_BAD_DEVICE = 1200,
  ERROR_CONNECTION_UNAVAIL = 1201,
  ERROR_DEVICE_ALREADY_REMEMBERED = 1202,
  ERROR_NO_NET_OR_BAD_PATH = 1203,
  ERROR_BAD_PROVIDER = 1204,
  ERROR_CANNOT_OPEN_PROFILE = 1205,
  ERROR_BAD_PROFILE = 1206,
  ERROR_NOT_CONTAINER = 1207,
  ERROR_EXTENDED_ERROR = 1208,
  ERROR_INVALID_GROUPNAME = 1209,
  ERROR_INVALID_COMPUTERNAME = 1210,
  ERROR_INVALID_EVENTNAME = 1211,
  ERROR_INVALID_DOMAINNAME = 1212,
  ERROR_INVALID_SERVICENAME = 1213,
  ERROR_INVALID_NETNAME = 1214,
  ERROR_INVALID_SHARENAME = 1215,
  ERROR_INVALID_PASSWORDNAME = 1216,
  ERROR_INVALID_MESSAGENAME = 1217,
  ERROR_INVALID_MESSAGEDEST = 1218,
  ERROR_SESSION_CREDENTIAL_CONFLICT = 1219,
  ERROR_REMOTE_SESSION_LIMIT_EXCEEDED = 1220,
  ERROR_DUP_DOMAINNAME = 1221,
  ERROR_NO_NETWORK = 1222,
  ERROR_CANCELLED = 1223,
  ERROR_USER_MAPPED_FILE = 1224,
  ERROR_CONNECTION_REFUSED = 1225,
  ERROR_GRACEFUL_DISCONNECT = 1226,
  ERROR_ADDRESS_ALREADY_ASSOCIATED = 1227,
  ERROR_ADDRESS_NOT_ASSOCIATED = 1228,
  ERROR_CONNECTION_INVALID = 1229,
  ERROR_CONNECTION_ACTIVE = 1230,
  ERROR_NETWORK_UNREACHABLE = 1231,
  ERROR_HOST_UNREACHABLE = 1232,
  ERROR_PROTOCOL_UNREACHABLE = 1233,
  ERROR_PORT_UNREACHABLE = 1234,
  ERROR_REQUEST_ABORTED = 1235,
  ERROR_CONNECTION_ABORTED = 1236,
  ERROR_RETRY = 1237,
  ERROR_CONNECTION_COUNT_LIMIT = 1238,
  ERROR_LOGIN_TIME_RESTRICTION = 1239,
  ERROR_LOGIN_WKSTA_RESTRICTION = 1240,
  ERROR_INCORRECT_ADDRESS = 1241,
  ERROR_ALREADY_REGISTERED = 1242,
  ERROR_SERVICE_NOT_FOUND = 1243,
  ERROR_NOT_AUTHENTICATED = 1244,
  ERROR_NOT_LOGGED_ON = 1245,
  ERROR_CONTINUE = 1246,
  ERROR_ALREADY_INITIALIZED = 1247,
  ERROR_NO_MORE_DEVICES = 1248,
  ERROR_NO_SUCH_SITE = 1249,
  ERROR_DOMAIN_CONTROLLER_EXISTS = 1250,
  ERROR_ONLY_IF_CONNECTED = 1251,
  ERROR_OVERRIDE_NOCHANGES = 1252,
  ERROR_BAD_USER_PROFILE = 1253,
  ERROR_NOT_SUPPORTED_ON_SBS = 1254,
  ERROR_SERVER_SHUTDOWN_IN_PROGRESS = 1255,
  ERROR_HOST_DOWN = 1256,
  ERROR_NON_ACCOUNT_SID = 1257,
  ERROR_NON_DOMAIN_SID = 1258,
  ERROR_APPHELP_BLOCK = 1259,
  ERROR_ACCESS_DISABLED_BY_POLICY = 1260,
  ERROR_REG_NAT_CONSUMPTION = 1261,
  ERROR_CSCSHARE_OFFLINE = 1262,
  ERROR_PKINIT_FAILURE = 1263,
  ERROR_SMARTCARD_SUBSYSTEM_FAILURE = 1264,
  ERROR_DOWNGRADE_DETECTED = 1265,
  ERROR_MACHINE_LOCKED = 1271,
  ERROR_CALLBACK_SUPPLIED_INVALID_DATA = 1273,
  ERROR_SYNC_FOREGROUND_REFRESH_REQUIRED = 1274,
  ERROR_DRIVER_BLOCKED = 1275,
  ERROR_INVALID_IMPORT_OF_NON_DLL = 1276,
  ERROR_ACCESS_DISABLED_WEBBLADE = 1277,
  ERROR_ACCESS_DISABLED_WEBBLADE_TAMPER = 1278,
  ERROR_RECOVERY_FAILURE = 1279,
  ERROR_ALREADY_FIBER = 1280,
  ERROR_ALREADY_THREAD = 1281,
  ERROR_STACK_BUFFER_OVERRUN = 1282,
  ERROR_PARAMETER_QUOTA_EXCEEDED = 1283,
  ERROR_DEBUGGER_INACTIVE = 1284,
  ERROR_DELAY_LOAD_FAILED = 1285,
  ERROR_VDM_DISALLOWED = 1286,
  ERROR_UNIDENTIFIED_ERROR = 1287,
  ERROR_INVALID_CRUNTIME_PARAMETER = 1288,
  ERROR_BEYOND_VDL = 1289,
  ERROR_INCOMPATIBLE_SERVICE_SID_TYPE = 1290,
  ERROR_DRIVER_PROCESS_TERMINATED = 1291,
  ERROR_IMPLEMENTATION_LIMIT = 1292,
  ERROR_PROCESS_IS_PROTECTED = 1293,
  ERROR_SERVICE_NOTIFY_CLIENT_LAGGING = 1294,
  ERROR_DISK_QUOTA_EXCEEDED = 1295,
  ERROR_CONTENT_BLOCKED = 1296,
  ERROR_INCOMPATIBLE_SERVICE_PRIVILEGE = 1297,
  ERROR_APP_HANG = 1298,
  ERROR_INVALID_LABEL = 1299,
  ERROR_NOT_ALL_ASSIGNED = 1300,
  ERROR_SOME_NOT_MAPPED = 1301,
  ERROR_NO_QUOTAS_FOR_ACCOUNT = 1302,
  ERROR_LOCAL_USER_SESSION_KEY = 1303,
  ERROR_NULL_LM_PASSWORD = 1304,
  ERROR_UNKNOWN_REVISION = 1305,
  ERROR_REVISION_MISMATCH = 1306,
  ERROR_INVALID_OWNER = 1307,
  ERROR_INVALID_PRIMARY_GROUP = 1308,
  ERROR_NO_IMPERSONATION_TOKEN = 1309,
  ERROR_CANT_DISABLE_MANDATORY = 1310,
  ERROR_NO_LOGON_SERVERS = 1311,
  ERROR_NO_SUCH_LOGON_SESSION = 1312,
  ERROR_NO_SUCH_PRIVILEGE = 1313,
  ERROR_PRIVILEGE_NOT_HELD = 1314,
  ERROR_INVALID_ACCOUNT_NAME = 1315,
  ERROR_USER_EXISTS = 1316,
  ERROR_NO_SUCH_USER = 1317,
  ERROR_GROUP_EXISTS = 1318,
  ERROR_NO_SUCH_GROUP = 1319,
  ERROR_MEMBER_IN_GROUP = 1320,
  ERROR_MEMBER_NOT_IN_GROUP = 1321,
  ERROR_LAST_ADMIN = 1322,
  ERROR_WRONG_PASSWORD = 1323,
  ERROR_ILL_FORMED_PASSWORD = 1324,
  ERROR_PASSWORD_RESTRICTION = 1325,
  ERROR_LOGON_FAILURE = 1326,
  ERROR_ACCOUNT_RESTRICTION = 1327,
  ERROR_INVALID_LOGON_HOURS = 1328,
  ERROR_INVALID_WORKSTATION = 1329,
  ERROR_PASSWORD_EXPIRED = 1330,
  ERROR_ACCOUNT_DISABLED = 1331,
  ERROR_NONE_MAPPED = 1332,
  ERROR_TOO_MANY_LUIDS_REQUESTED = 1333,
  ERROR_LUIDS_EXHAUSTED = 1334,
  ERROR_INVALID_SUB_AUTHORITY = 1335,
  ERROR_INVALID_ACL = 1336,
  ERROR_INVALID_SID = 1337,
  ERROR_INVALID_SECURITY_DESCR = 1338,
  ERROR_BAD_INHERITANCE_ACL = 1340,
  ERROR_SERVER_DISABLED = 1341,
  ERROR_SERVER_NOT_DISABLED = 1342,
  ERROR_INVALID_ID_AUTHORITY = 1343,
  ERROR_ALLOTTED_SPACE_EXCEEDED = 1344,
  ERROR_INVALID_GROUP_ATTRIBUTES = 1345,
  ERROR_BAD_IMPERSONATION_LEVEL = 1346,
  ERROR_CANT_OPEN_ANONYMOUS = 1347,
  ERROR_BAD_VALIDATION_CLASS = 1348,
  ERROR_BAD_TOKEN_TYPE = 1349,
  ERROR_NO_SECURITY_ON_OBJECT = 1350,
  ERROR_CANT_ACCESS_DOMAIN_INFO = 1351,
  ERROR_INVALID_SERVER_STATE = 1352,
  ERROR_INVALID_DOMAIN_STATE = 1353,
  ERROR_INVALID_DOMAIN_ROLE = 1354,
  ERROR_NO_SUCH_DOMAIN = 1355,
  ERROR_DOMAIN_EXISTS = 1356,
  ERROR_DOMAIN_LIMIT_EXCEEDED = 1357,
  ERROR_INTERNAL_DB_CORRUPTION = 1358,
  ERROR_INTERNAL_ERROR = 1359,
  ERROR_GENERIC_NOT_MAPPED = 1360,
  ERROR_BAD_DESCRIPTOR_FORMAT = 1361,
  ERROR_NOT_LOGON_PROCESS = 1362,
  ERROR_LOGON_SESSION_EXISTS = 1363,
  ERROR_NO_SUCH_PACKAGE = 1364,
  ERROR_BAD_LOGON_SESSION_STATE = 1365,
  ERROR_LOGON_SESSION_COLLISION = 1366,
  ERROR_INVALID_LOGON_TYPE = 1367,
  ERROR_CANNOT_IMPERSONATE = 1368,
  ERROR_RXACT_INVALID_STATE = 1369,
  ERROR_RXACT_COMMIT_FAILURE = 1370,
  ERROR_SPECIAL_ACCOUNT = 1371,
  ERROR_SPECIAL_GROUP = 1372,
  ERROR_SPECIAL_USER = 1373,
  ERROR_MEMBERS_PRIMARY_GROUP = 1374,
  ERROR_TOKEN_ALREADY_IN_USE = 1375,
  ERROR_NO_SUCH_ALIAS = 1376,
  ERROR_MEMBER_NOT_IN_ALIAS = 1377,
  ERROR_MEMBER_IN_ALIAS = 1378,
  ERROR_ALIAS_EXISTS = 1379,
  ERROR_LOGON_NOT_GRANTED = 1380,
  ERROR_TOO_MANY_SECRETS = 1381,
  ERROR_SECRET_TOO_LONG = 1382,
  ERROR_INTERNAL_DB_ERROR = 1383,
  ERROR_TOO_MANY_CONTEXT_IDS = 1384,
  ERROR_LOGON_TYPE_NOT_GRANTED = 1385,
  ERROR_NT_CROSS_ENCRYPTION_REQUIRED = 1386,
  ERROR_NO_SUCH_MEMBER = 1387,
  ERROR_INVALID_MEMBER = 1388,
  ERROR_TOO_MANY_SIDS = 1389,
  ERROR_LM_CROSS_ENCRYPTION_REQUIRED = 1390,
  ERROR_NO_INHERITANCE = 1391,
  ERROR_FILE_CORRUPT = 1392,
  ERROR_DISK_CORRUPT = 1393,
  ERROR_NO_USER_SESSION_KEY = 1394,
  ERROR_LICENSE_QUOTA_EXCEEDED = 1395,
  ERROR_WRONG_TARGET_NAME = 1396,
  ERROR_MUTUAL_AUTH_FAILED = 1397,
  ERROR_TIME_SKEW = 1398,
  ERROR_CURRENT_DOMAIN_NOT_ALLOWED = 1399,
  ERROR_INVALID_WINDOW_HANDLE = 1400,
  ERROR_INVALID_MENU_HANDLE = 1401,
  ERROR_INVALID_CURSOR_HANDLE = 1402,
  ERROR_INVALID_ACCEL_HANDLE = 1403,
  ERROR_INVALID_HOOK_HANDLE = 1404,
  ERROR_INVALID_DWP_HANDLE = 1405,
  ERROR_TLW_WITH_WSCHILD = 1406,
  ERROR_CANNOT_FIND_WND_CLASS = 1407,
  ERROR_WINDOW_OF_OTHER_THREAD = 1408,
  ERROR_HOTKEY_ALREADY_REGISTERED = 1409,
  ERROR_CLASS_ALREADY_EXISTS = 1410,
  ERROR_CLASS_DOES_NOT_EXIST = 1411,
  ERROR_CLASS_HAS_WINDOWS = 1412,
  ERROR_INVALID_INDEX = 1413,
  ERROR_INVALID_ICON_HANDLE = 1414,
  ERROR_PRIVATE_DIALOG_INDEX = 1415,
  ERROR_LISTBOX_ID_NOT_FOUND = 1416,
  ERROR_NO_WILDCARD_CHARACTERS = 1417,
  ERROR_CLIPBOARD_NOT_OPEN = 1418,
  ERROR_HOTKEY_NOT_REGISTERED = 1419,
  ERROR_WINDOW_NOT_DIALOG = 1420,
  ERROR_CONTROL_ID_NOT_FOUND = 1421,
  ERROR_INVALID_COMBOBOX_MESSAGE = 1422,
  ERROR_WINDOW_NOT_COMBOBOX = 1423,
  ERROR_INVALID_EDIT_HEIGHT = 1424,
  ERROR_DC_NOT_FOUND = 1425,
  ERROR_INVALID_HOOK_FILTER = 1426,
  ERROR_INVALID_FILTER_PROC = 1427,
  ERROR_HOOK_NEEDS_HMOD = 1428,
  ERROR_GLOBAL_ONLY_HOOK = 1429,
  ERROR_JOURNAL_HOOK_SET = 1430,
  ERROR_HOOK_NOT_INSTALLED = 1431,
  ERROR_INVALID_LB_MESSAGE = 1432,
  ERROR_SETCOUNT_ON_BAD_LB = 1433,
  ERROR_LB_WITHOUT_TABSTOPS = 1434,
  ERROR_DESTROY_OBJECT_OF_OTHER_THREAD = 1435,
  ERROR_CHILD_WINDOW_MENU = 1436,
  ERROR_NO_SYSTEM_MENU = 1437,
  ERROR_INVALID_MSGBOX_STYLE = 1438,
  ERROR_INVALID_SPI_VALUE = 1439,
  ERROR_SCREEN_ALREADY_LOCKED = 1440,
  ERROR_HWNDS_HAVE_DIFF_PARENT = 1441,
  ERROR_NOT_CHILD_WINDOW = 1442,
  ERROR_INVALID_GW_COMMAND = 1443,
  ERROR_INVALID_THREAD_ID = 1444,
  ERROR_NON_MDICHILD_WINDOW = 1445,
  ERROR_POPUP_ALREADY_ACTIVE = 1446,
  ERROR_NO_SCROLLBARS = 1447,
  ERROR_INVALID_SCROLLBAR_RANGE = 1448,
  ERROR_INVALID_SHOWWIN_COMMAND = 1449,
  ERROR_NO_SYSTEM_RESOURCES = 1450,
  ERROR_NONPAGED_SYSTEM_RESOURCES = 1451,
  ERROR_PAGED_SYSTEM_RESOURCES = 1452,
  ERROR_WORKING_SET_QUOTA = 1453,
  ERROR_PAGEFILE_QUOTA = 1454,
  ERROR_COMMITMENT_LIMIT = 1455,
  ERROR_MENU_ITEM_NOT_FOUND = 1456,
  ERROR_INVALID_KEYBOARD_HANDLE = 1457,
  ERROR_HOOK_TYPE_NOT_ALLOWED = 1458,
  ERROR_REQUIRES_INTERACTIVE_WINDOWSTATION = 1459,
  ERROR_TIMEOUT = 1460,
  ERROR_INVALID_MONITOR_HANDLE = 1461,
  ERROR_INCORRECT_SIZE = 1462,
  ERROR_SYMLINK_CLASS_DISABLED = 1463,
  ERROR_SYMLINK_NOT_SUPPORTED = 1464,
  ERROR_XML_PARSE_ERROR = 1465,
  ERROR_XMLDSIG_ERROR = 1466,
  ERROR_RESTART_APPLICATION = 1467,
  ERROR_WRONG_COMPARTMENT = 1468,
  ERROR_AUTHIP_FAILURE = 1469,
  ERROR_NO_NVRAM_RESOURCES = 1470,
  ERROR_EVENTLOG_FILE_CORRUPT = 1500,
  ERROR_EVENTLOG_CANT_START = 1501,
  ERROR_LOG_FILE_FULL = 1502,
  ERROR_EVENTLOG_FILE_CHANGED = 1503,
  ERROR_INVALID_TASK_NAME = 1550,
  ERROR_INVALID_TASK_INDEX = 1551,
  ERROR_THREAD_ALREADY_IN_TASK = 1552,
  ERROR_INSTALL_SERVICE_FAILURE = 1601,
  ERROR_INSTALL_USEREXIT = 1602,
  ERROR_INSTALL_FAILURE = 1603,
  ERROR_INSTALL_SUSPEND = 1604,
  ERROR_UNKNOWN_PRODUCT = 1605,
  ERROR_UNKNOWN_FEATURE = 1606,
  ERROR_UNKNOWN_COMPONENT = 1607,
  ERROR_UNKNOWN_PROPERTY = 1608,
  ERROR_INVALID_HANDLE_STATE = 1609,
  ERROR_BAD_CONFIGURATION = 1610,
  ERROR_INDEX_ABSENT = 1611,
  ERROR_INSTALL_SOURCE_ABSENT = 1612,
  ERROR_INSTALL_PACKAGE_VERSION = 1613,
  ERROR_PRODUCT_UNINSTALLED = 1614,
  ERROR_BAD_QUERY_SYNTAX = 1615,
  ERROR_INVALID_FIELD = 1616,
  ERROR_DEVICE_REMOVED = 1617,
  ERROR_INSTALL_ALREADY_RUNNING = 1618,
  ERROR_INSTALL_PACKAGE_OPEN_FAILED = 1619,
  ERROR_INSTALL_PACKAGE_INVALID = 1620,
  ERROR_INSTALL_UI_FAILURE = 1621,
  ERROR_INSTALL_LOG_FAILURE = 1622,
  ERROR_INSTALL_LANGUAGE_UNSUPPORTED = 1623,
  ERROR_INSTALL_TRANSFORM_FAILURE = 1624,
  ERROR_INSTALL_PACKAGE_REJECTED = 1625,
  ERROR_FUNCTION_NOT_CALLED = 1626,
  ERROR_FUNCTION_FAILED = 1627,
  ERROR_INVALID_TABLE = 1628,
  ERROR_DATATYPE_MISMATCH = 1629,
  ERROR_UNSUPPORTED_TYPE = 1630,
  ERROR_CREATE_FAILED = 1631,
  ERROR_INSTALL_TEMP_UNWRITABLE = 1632,
  ERROR_INSTALL_PLATFORM_UNSUPPORTED = 1633,
  ERROR_INSTALL_NOTUSED = 1634,
  ERROR_PATCH_PACKAGE_OPEN_FAILED = 1635,
  ERROR_PATCH_PACKAGE_INVALID = 1636,
  ERROR_PATCH_PACKAGE_UNSUPPORTED = 1637,
  ERROR_PRODUCT_VERSION = 1638,
  ERROR_INVALID_COMMAND_LINE = 1639,
  ERROR_INSTALL_REMOTE_DISALLOWED = 1640,
  ERROR_SUCCESS_REBOOT_INITIATED = 1641,
  ERROR_PATCH_TARGET_NOT_FOUND = 1642,
  ERROR_PATCH_PACKAGE_REJECTED = 1643,
  ERROR_INSTALL_TRANSFORM_REJECTED = 1644,
  ERROR_INSTALL_REMOTE_PROHIBITED = 1645,
  ERROR_PATCH_REMOVAL_UNSUPPORTED = 1646,
  ERROR_UNKNOWN_PATCH = 1647,
  ERROR_PATCH_NO_SEQUENCE = 1648,
  ERROR_PATCH_REMOVAL_DISALLOWED = 1649,
  ERROR_INVALID_PATCH_XML = 1650,
  ERROR_PATCH_MANAGED_ADVERTISED_PRODUCT = 1651,
  ERROR_INSTALL_SERVICE_SAFEBOOT = 1652,
  ERROR_FAIL_FAST_EXCEPTION = 1653,
  RPC_S_INVALID_STRING_BINDING = 1700,
  RPC_S_WRONG_KIND_OF_BINDING = 1701,
  RPC_S_INVALID_BINDING = 1702,
  RPC_S_PROTSEQ_NOT_SUPPORTED = 1703,
  RPC_S_INVALID_RPC_PROTSEQ = 1704,
  RPC_S_INVALID_STRING_UUID = 1705,
  RPC_S_INVALID_ENDPOINT_FORMAT = 1706,
  RPC_S_INVALID_NET_ADDR = 1707,
  RPC_S_NO_ENDPOINT_FOUND = 1708,
  RPC_S_INVALID_TIMEOUT = 1709,
  RPC_S_OBJECT_NOT_FOUND = 1710,
  RPC_S_ALREADY_REGISTERED = 1711,
  RPC_S_TYPE_ALREADY_REGISTERED = 1712,
  RPC_S_ALREADY_LISTENING = 1713,
  RPC_S_NO_PROTSEQS_REGISTERED = 1714,
  RPC_S_NOT_LISTENING = 1715,
  RPC_S_UNKNOWN_MGR_TYPE = 1716,
  RPC_S_UNKNOWN_IF = 1717,
  RPC_S_NO_BINDINGS = 1718,
  RPC_S_NO_PROTSEQS = 1719,
  RPC_S_CANT_CREATE_ENDPOINT = 1720,
  RPC_S_OUT_OF_RESOURCES = 1721,
  RPC_S_SERVER_UNAVAILABLE = 1722,
  RPC_S_SERVER_TOO_BUSY = 1723,
  RPC_S_INVALID_NETWORK_OPTIONS = 1724,
  RPC_S_NO_CALL_ACTIVE = 1725,
  RPC_S_CALL_FAILED = 1726,
  RPC_S_CALL_FAILED_DNE = 1727,
  RPC_S_PROTOCOL_ERROR = 1728,
  RPC_S_PROXY_ACCESS_DENIED = 1729,
  RPC_S_UNSUPPORTED_TRANS_SYN = 1730,
  RPC_S_UNSUPPORTED_TYPE = 1732,
  RPC_S_INVALID_TAG = 1733,
  RPC_S_INVALID_BOUND = 1734,
  RPC_S_NO_ENTRY_NAME = 1735,
  RPC_S_INVALID_NAME_SYNTAX = 1736,
  RPC_S_UNSUPPORTED_NAME_SYNTAX = 1737,
  RPC_S_UUID_NO_ADDRESS = 1739,
  RPC_S_DUPLICATE_ENDPOINT = 1740,
  RPC_S_UNKNOWN_AUTHN_TYPE = 1741,
  RPC_S_MAX_CALLS_TOO_SMALL = 1742,
  RPC_S_STRING_TOO_LONG = 1743,
  RPC_S_PROTSEQ_NOT_FOUND = 1744,
  RPC_S_PROCNUM_OUT_OF_RANGE = 1745,
  RPC_S_BINDING_HAS_NO_AUTH = 1746,
  RPC_S_UNKNOWN_AUTHN_SERVICE = 1747,
  RPC_S_UNKNOWN_AUTHN_LEVEL = 1748,
  RPC_S_INVALID_AUTH_IDENTITY = 1749,
  RPC_S_UNKNOWN_AUTHZ_SERVICE = 1750,
  EPT_S_INVALID_ENTRY = 1751,
  EPT_S_CANT_PERFORM_OP = 1752,
  EPT_S_NOT_REGISTERED = 1753,
  RPC_S_NOTHING_TO_EXPORT = 1754,
  RPC_S_INCOMPLETE_NAME = 1755,
  RPC_S_INVALID_VERS_OPTION = 1756,
  RPC_S_NO_MORE_MEMBERS = 1757,
  RPC_S_NOT_ALL_OBJS_UNEXPORTED = 1758,
  RPC_S_INTERFACE_NOT_FOUND = 1759,
  RPC_S_ENTRY_ALREADY_EXISTS = 1760,
  RPC_S_ENTRY_NOT_FOUND = 1761,
  RPC_S_NAME_SERVICE_UNAVAILABLE = 1762,
  RPC_S_INVALID_NAF_ID = 1763,
  RPC_S_CANNOT_SUPPORT = 1764,
  RPC_S_NO_CONTEXT_AVAILABLE = 1765,
  RPC_S_INTERNAL_ERROR = 1766,
  RPC_S_ZERO_DIVIDE = 1767,
  RPC_S_ADDRESS_ERROR = 1768,
  RPC_S_FP_DIV_ZERO = 1769,
  RPC_S_FP_UNDERFLOW = 1770,
  RPC_S_FP_OVERFLOW = 1771,
  RPC_X_NO_MORE_ENTRIES = 1772,
  RPC_X_SS_CHAR_TRANS_OPEN_FAIL = 1773,
  RPC_X_SS_CHAR_TRANS_SHORT_FILE = 1774,
  RPC_X_SS_IN_NULL_CONTEXT = 1775,
  RPC_X_SS_CONTEXT_DAMAGED = 1777,
  RPC_X_SS_HANDLES_MISMATCH = 1778,
  RPC_X_SS_CANNOT_GET_CALL_HANDLE = 1779,
  RPC_X_NULL_REF_POINTER = 1780,
  RPC_X_ENUM_VALUE_OUT_OF_RANGE = 1781,
  RPC_X_BYTE_COUNT_TOO_SMALL = 1782,
  RPC_X_BAD_STUB_DATA = 1783,
  ERROR_INVALID_USER_BUFFER = 1784,
  ERROR_UNRECOGNIZED_MEDIA = 1785,
  ERROR_NO_TRUST_LSA_SECRET = 1786,
  ERROR_NO_TRUST_SAM_ACCOUNT = 1787,
  ERROR_TRUSTED_DOMAIN_FAILURE = 1788,
  ERROR_TRUSTED_RELATIONSHIP_FAILURE = 1789,
  ERROR_TRUST_FAILURE = 1790,
  RPC_S_CALL_IN_PROGRESS = 1791,
  ERROR_NETLOGON_NOT_STARTED = 1792,
  ERROR_ACCOUNT_EXPIRED = 1793,
  ERROR_REDIRECTOR_HAS_OPEN_HANDLES = 1794,
  ERROR_PRINTER_DRIVER_ALREADY_INSTALLED = 1795,
  ERROR_UNKNOWN_PORT = 1796,
  ERROR_UNKNOWN_PRINTER_DRIVER = 1797,
  ERROR_UNKNOWN_PRINTPROCESSOR = 1798,
  ERROR_INVALID_SEPARATOR_FILE = 1799,
  ERROR_INVALID_PRIORITY = 1800,
  ERROR_INVALID_PRINTER_NAME = 1801,
  ERROR_PRINTER_ALREADY_EXISTS = 1802,
  ERROR_INVALID_PRINTER_COMMAND = 1803,
  ERROR_INVALID_DATATYPE = 1804,
  ERROR_INVALID_ENVIRONMENT = 1805,
  RPC_S_NO_MORE_BINDINGS = 1806,
  ERROR_NOLOGON_INTERDOMAIN_TRUST_ACCOUNT = 1807,
  ERROR_NOLOGON_WORKSTATION_TRUST_ACCOUNT = 1808,
  ERROR_NOLOGON_SERVER_TRUST_ACCOUNT = 1809,
  ERROR_DOMAIN_TRUST_INCONSISTENT = 1810,
  ERROR_SERVER_HAS_OPEN_HANDLES = 1811,
  ERROR_RESOURCE_DATA_NOT_FOUND = 1812,
  ERROR_RESOURCE_TYPE_NOT_FOUND = 1813,
  ERROR_RESOURCE_NAME_NOT_FOUND = 1814,
  ERROR_RESOURCE_LANG_NOT_FOUND = 1815,
  ERROR_NOT_ENOUGH_QUOTA = 1816,
  RPC_S_NO_INTERFACES = 1817,
  RPC_S_CALL_CANCELLED = 1818,
  RPC_S_BINDING_INCOMPLETE = 1819,
  RPC_S_COMM_FAILURE = 1820,
  RPC_S_UNSUPPORTED_AUTHN_LEVEL = 1821,
  RPC_S_NO_PRINC_NAME = 1822,
  RPC_S_NOT_RPC_ERROR = 1823,
  RPC_S_UUID_LOCAL_ONLY = 1824,
  RPC_S_SEC_PKG_ERROR = 1825,
  RPC_S_NOT_CANCELLED = 1826,
  RPC_X_INVALID_ES_ACTION = 1827,
  RPC_X_WRONG_ES_VERSION = 1828,
  RPC_X_WRONG_STUB_VERSION = 1829,
  RPC_X_INVALID_PIPE_OBJECT = 1830,
  RPC_X_WRONG_PIPE_ORDER = 1831,
  RPC_X_WRONG_PIPE_VERSION = 1832,
  RPC_S_COOKIE_AUTH_FAILED = 1833,
  RPC_S_GROUP_MEMBER_NOT_FOUND = 1898,
  EPT_S_CANT_CREATE = 1899,
  RPC_S_INVALID_OBJECT = 1900,
  ERROR_INVALID_TIME = 1901,
  ERROR_INVALID_FORM_NAME = 1902,
  ERROR_INVALID_FORM_SIZE = 1903,
  ERROR_ALREADY_WAITING = 1904,
  ERROR_PRINTER_DELETED = 1905,
  ERROR_INVALID_PRINTER_STATE = 1906,
  ERROR_PASSWORD_MUST_CHANGE = 1907,
  ERROR_DOMAIN_CONTROLLER_NOT_FOUND = 1908,
  ERROR_ACCOUNT_LOCKED_OUT = 1909,
  OR_INVALID_OXID = 1910,
  OR_INVALID_OID = 1911,
  OR_INVALID_SET = 1912,
  RPC_S_SEND_INCOMPLETE = 1913,
  RPC_S_INVALID_ASYNC_HANDLE = 1914,
  RPC_S_INVALID_ASYNC_CALL = 1915,
  RPC_X_PIPE_CLOSED = 1916,
  RPC_X_PIPE_DISCIPLINE_ERROR = 1917,
  RPC_X_PIPE_EMPTY = 1918,
  ERROR_NO_SITENAME = 1919,
  ERROR_CANT_ACCESS_FILE = 1920,
  ERROR_CANT_RESOLVE_FILENAME = 1921,
  RPC_S_ENTRY_TYPE_MISMATCH = 1922,
  RPC_S_NOT_ALL_OBJS_EXPORTED = 1923,
  RPC_S_INTERFACE_NOT_EXPORTED = 1924,
  RPC_S_PROFILE_NOT_ADDED = 1925,
  RPC_S_PRF_ELT_NOT_ADDED = 1926,
  RPC_S_PRF_ELT_NOT_REMOVED = 1927,
  RPC_S_GRP_ELT_NOT_ADDED = 1928,
  RPC_S_GRP_ELT_NOT_REMOVED = 1929,
  ERROR_KM_DRIVER_BLOCKED = 1930,
  ERROR_CONTEXT_EXPIRED = 1931,
  ERROR_PER_USER_TRUST_QUOTA_EXCEEDED = 1932,
  ERROR_ALL_USER_TRUST_QUOTA_EXCEEDED = 1933,
  ERROR_USER_DELETE_TRUST_QUOTA_EXCEEDED = 1934,
  ERROR_AUTHENTICATION_FIREWALL_FAILED = 1935,
  ERROR_REMOTE_PRINT_CONNECTIONS_BLOCKED = 1936,
  ERROR_NTLM_BLOCKED = 1937,
  ERROR_INVALID_PIXEL_FORMAT = 2000,
  ERROR_BAD_DRIVER = 2001,
  ERROR_INVALID_WINDOW_STYLE = 2002,
  ERROR_METAFILE_NOT_SUPPORTED = 2003,
  ERROR_TRANSFORM_NOT_SUPPORTED = 2004,
  ERROR_CLIPPING_NOT_SUPPORTED = 2005,
  ERROR_INVALID_CMM = 2010,
  ERROR_INVALID_PROFILE = 2011,
  ERROR_TAG_NOT_FOUND = 2012,
  ERROR_TAG_NOT_PRESENT = 2013,
  ERROR_DUPLICATE_TAG = 2014,
  ERROR_PROFILE_NOT_ASSOCIATED_WITH_DEVICE = 2015,
  ERROR_PROFILE_NOT_FOUND = 2016,
  ERROR_INVALID_COLORSPACE = 2017,
  ERROR_ICM_NOT_ENABLED = 2018,
  ERROR_DELETING_ICM_XFORM = 2019,
  ERROR_INVALID_TRANSFORM = 2020,
  ERROR_COLORSPACE_MISMATCH = 2021,
  ERROR_INVALID_COLORINDEX = 2022,
  ERROR_PROFILE_DOES_NOT_MATCH_DEVICE = 2023,
  ERROR_CONNECTED_OTHER_PASSWORD = 2108,
  ERROR_CONNECTED_OTHER_PASSWORD_DEFAULT = 2109,
  ERROR_BAD_USERNAME = 2202,
  ERROR_NOT_CONNECTED = 2250,
  ERROR_OPEN_FILES = 2401,
  ERROR_ACTIVE_CONNECTIONS = 2402,
  ERROR_DEVICE_IN_USE = 2404,
  ERROR_UNKNOWN_PRINT_MONITOR = 3000,
  ERROR_PRINTER_DRIVER_IN_USE = 3001,
  ERROR_SPOOL_FILE_NOT_FOUND = 3002,
  ERROR_SPL_NO_STARTDOC = 3003,
  ERROR_SPL_NO_ADDJOB = 3004,
  ERROR_PRINT_PROCESSOR_ALREADY_INSTALLED = 3005,
  ERROR_PRINT_MONITOR_ALREADY_INSTALLED = 3006,
  ERROR_INVALID_PRINT_MONITOR = 3007,
  ERROR_PRINT_MONITOR_IN_USE = 3008,
  ERROR_PRINTER_HAS_JOBS_QUEUED = 3009,
  ERROR_SUCCESS_REBOOT_REQUIRED = 3010,
  ERROR_SUCCESS_RESTART_REQUIRED = 3011,
  ERROR_PRINTER_NOT_FOUND = 3012,
  ERROR_PRINTER_DRIVER_WARNED = 3013,
  ERROR_PRINTER_DRIVER_BLOCKED = 3014,
  ERROR_PRINTER_DRIVER_PACKAGE_IN_USE = 3015,
  ERROR_CORE_DRIVER_PACKAGE_NOT_FOUND = 3016,
  ERROR_FAIL_REBOOT_REQUIRED = 3017,
  ERROR_FAIL_REBOOT_INITIATED = 3018,
  ERROR_PRINTER_DRIVER_DOWNLOAD_NEEDED = 3019,
  ERROR_PRINT_JOB_RESTART_REQUIRED = 3020,
  ERROR_IO_REISSUE_AS_CACHED = 3950,
  ERROR_WINS_INTERNAL = 4000,
  ERROR_CAN_NOT_DEL_LOCAL_WINS = 4001,
  ERROR_STATIC_INIT = 4002,
  ERROR_INC_BACKUP = 4003,
  ERROR_FULL_BACKUP = 4004,
  ERROR_REC_NON_EXISTENT = 4005,
  ERROR_RPL_NOT_ALLOWED = 4006,
  PEERDIST_ERROR_CONTENTINFO_VERSION_UNSUPPORTED = 4050,
  PEERDIST_ERROR_CANNOT_PARSE_CONTENTINFO = 4051,
  PEERDIST_ERROR_MISSING_DATA = 4052,
  PEERDIST_ERROR_NO_MORE = 4053,
  PEERDIST_ERROR_NOT_INITIALIZED = 4054,
  PEERDIST_ERROR_ALREADY_INITIALIZED = 4055,
  PEERDIST_ERROR_SHUTDOWN_IN_PROGRESS = 4056,
  PEERDIST_ERROR_INVALIDATED = 4057,
  PEERDIST_ERROR_ALREADY_EXISTS = 4058,
  PEERDIST_ERROR_OPERATION_NOTFOUND = 4059,
  PEERDIST_ERROR_ALREADY_COMPLETED = 4060,
  PEERDIST_ERROR_OUT_OF_BOUNDS = 4061,
  PEERDIST_ERROR_VERSION_UNSUPPORTED = 4062,
  PEERDIST_ERROR_INVALID_CONFIGURATION = 4063,
  PEERDIST_ERROR_NOT_LICENSED = 4064,
  PEERDIST_ERROR_SERVICE_UNAVAILABLE = 4065,
  ERROR_DHCP_ADDRESS_CONFLICT = 4100,
  ERROR_WMI_GUID_NOT_FOUND = 4200,
  ERROR_WMI_INSTANCE_NOT_FOUND = 4201,
  ERROR_WMI_ITEMID_NOT_FOUND = 4202,
  ERROR_WMI_TRY_AGAIN = 4203,
  ERROR_WMI_DP_NOT_FOUND = 4204,
  ERROR_WMI_UNRESOLVED_INSTANCE_REF = 4205,
  ERROR_WMI_ALREADY_ENABLED = 4206,
  ERROR_WMI_GUID_DISCONNECTED = 4207,
  ERROR_WMI_SERVER_UNAVAILABLE = 4208,
  ERROR_WMI_DP_FAILED = 4209,
  ERROR_WMI_INVALID_MOF = 4210,
  ERROR_WMI_INVALID_REGINFO = 4211,
  ERROR_WMI_ALREADY_DISABLED = 4212,
  ERROR_WMI_READ_ONLY = 4213,
  ERROR_WMI_SET_FAILURE = 4214,
  ERROR_INVALID_MEDIA = 4300,
  ERROR_INVALID_LIBRARY = 4301,
  ERROR_INVALID_MEDIA_POOL = 4302,
  ERROR_DRIVE_MEDIA_MISMATCH = 4303,
  ERROR_MEDIA_OFFLINE = 4304,
  ERROR_LIBRARY_OFFLINE = 4305,
  ERROR_EMPTY = 4306,
  ERROR_NOT_EMPTY = 4307,
  ERROR_MEDIA_UNAVAILABLE = 4308,
  ERROR_RESOURCE_DISABLED = 4309,
  ERROR_INVALID_CLEANER = 4310,
  ERROR_UNABLE_TO_CLEAN = 4311,
  ERROR_OBJECT_NOT_FOUND = 4312,
  ERROR_DATABASE_FAILURE = 4313,
  ERROR_DATABASE_FULL = 4314,
  ERROR_MEDIA_INCOMPATIBLE = 4315,
  ERROR_RESOURCE_NOT_PRESENT = 4316,
  ERROR_INVALID_OPERATION = 4317,
  ERROR_MEDIA_NOT_AVAILABLE = 4318,
  ERROR_DEVICE_NOT_AVAILABLE = 4319,
  ERROR_REQUEST_REFUSED = 4320,
  ERROR_INVALID_DRIVE_OBJECT = 4321,
  ERROR_LIBRARY_FULL = 4322,
  ERROR_MEDIUM_NOT_ACCESSIBLE = 4323,
  ERROR_UNABLE_TO_LOAD_MEDIUM = 4324,
  ERROR_UNABLE_TO_INVENTORY_DRIVE = 4325,
  ERROR_UNABLE_TO_INVENTORY_SLOT = 4326,
  ERROR_UNABLE_TO_INVENTORY_TRANSPORT = 4327,
  ERROR_TRANSPORT_FULL = 4328,
  ERROR_CONTROLLING_IEPORT = 4329,
  ERROR_UNABLE_TO_EJECT_MOUNTED_MEDIA = 4330,
  ERROR_CLEANER_SLOT_SET = 4331,
  ERROR_CLEANER_SLOT_NOT_SET = 4332,
  ERROR_CLEANER_CARTRIDGE_SPENT = 4333,
  ERROR_UNEXPECTED_OMID = 4334,
  ERROR_CANT_DELETE_LAST_ITEM = 4335,
  ERROR_MESSAGE_EXCEEDS_MAX_SIZE = 4336,
  ERROR_VOLUME_CONTAINS_SYS_FILES = 4337,
  ERROR_INDIGENOUS_TYPE = 4338,
  ERROR_NO_SUPPORTING_DRIVES = 4339,
  ERROR_CLEANER_CARTRIDGE_INSTALLED = 4340,
  ERROR_IEPORT_FULL = 4341,
  ERROR_FILE_OFFLINE = 4350,
  ERROR_REMOTE_STORAGE_NOT_ACTIVE = 4351,
  ERROR_REMOTE_STORAGE_MEDIA_ERROR = 4352,
  ERROR_NOT_A_REPARSE_POINT = 4390,
  ERROR_REPARSE_ATTRIBUTE_CONFLICT = 4391,
  ERROR_INVALID_REPARSE_DATA = 4392,
  ERROR_REPARSE_TAG_INVALID = 4393,
  ERROR_REPARSE_TAG_MISMATCH = 4394,
  ERROR_VOLUME_NOT_SIS_ENABLED = 4500,
  ERROR_DEPENDENT_RESOURCE_EXISTS = 5001,
  ERROR_DEPENDENCY_NOT_FOUND = 5002,
  ERROR_DEPENDENCY_ALREADY_EXISTS = 5003,
  ERROR_RESOURCE_NOT_ONLINE = 5004,
  ERROR_HOST_NODE_NOT_AVAILABLE = 5005,
  ERROR_RESOURCE_NOT_AVAILABLE = 5006,
  ERROR_RESOURCE_NOT_FOUND = 5007,
  ERROR_SHUTDOWN_CLUSTER = 5008,
  ERROR_CANT_EVICT_ACTIVE_NODE = 5009,
  ERROR_OBJECT_ALREADY_EXISTS = 5010,
  ERROR_OBJECT_IN_LIST = 5011,
  ERROR_GROUP_NOT_AVAILABLE = 5012,
  ERROR_GROUP_NOT_FOUND = 5013,
  ERROR_GROUP_NOT_ONLINE = 5014,
  ERROR_HOST_NODE_NOT_RESOURCE_OWNER = 5015,
  ERROR_HOST_NODE_NOT_GROUP_OWNER = 5016,
  ERROR_RESMON_CREATE_FAILED = 5017,
  ERROR_RESMON_ONLINE_FAILED = 5018,
  ERROR_RESOURCE_ONLINE = 5019,
  ERROR_QUORUM_RESOURCE = 5020,
  ERROR_NOT_QUORUM_CAPABLE = 5021,
  ERROR_CLUSTER_SHUTTING_DOWN = 5022,
  ERROR_INVALID_STATE = 5023,
  ERROR_RESOURCE_PROPERTIES_STORED = 5024,
  ERROR_NOT_QUORUM_CLASS = 5025,
  ERROR_CORE_RESOURCE = 5026,
  ERROR_QUORUM_RESOURCE_ONLINE_FAILED = 5027,
  ERROR_QUORUMLOG_OPEN_FAILED = 5028,
  ERROR_CLUSTERLOG_CORRUPT = 5029,
  ERROR_CLUSTERLOG_RECORD_EXCEEDS_MAXSIZE = 5030,
  ERROR_CLUSTERLOG_EXCEEDS_MAXSIZE = 5031,
  ERROR_CLUSTERLOG_CHKPOINT_NOT_FOUND = 5032,
  ERROR_CLUSTERLOG_NOT_ENOUGH_SPACE = 5033,
  ERROR_QUORUM_OWNER_ALIVE = 5034,
  ERROR_NETWORK_NOT_AVAILABLE = 5035,
  ERROR_NODE_NOT_AVAILABLE = 5036,
  ERROR_ALL_NODES_NOT_AVAILABLE = 5037,
  ERROR_RESOURCE_FAILED = 5038,
  ERROR_CLUSTER_INVALID_NODE = 5039,
  ERROR_CLUSTER_NODE_EXISTS = 5040,
  ERROR_CLUSTER_JOIN_IN_PROGRESS = 5041,
  ERROR_CLUSTER_NODE_NOT_FOUND = 5042,
  ERROR_CLUSTER_LOCAL_NODE_NOT_FOUND = 5043,
  ERROR_CLUSTER_NETWORK_EXISTS = 5044,
  ERROR_CLUSTER_NETWORK_NOT_FOUND = 5045,
  ERROR_CLUSTER_NETINTERFACE_EXISTS = 5046,
  ERROR_CLUSTER_NETINTERFACE_NOT_FOUND = 5047,
  ERROR_CLUSTER_INVALID_REQUEST = 5048,
  ERROR_CLUSTER_INVALID_NETWORK_PROVIDER = 5049,
  ERROR_CLUSTER_NODE_DOWN = 5050,
  ERROR_CLUSTER_NODE_UNREACHABLE = 5051,
  ERROR_CLUSTER_NODE_NOT_MEMBER = 5052,
  ERROR_CLUSTER_JOIN_NOT_IN_PROGRESS = 5053,
  ERROR_CLUSTER_INVALID_NETWORK = 5054,
  ERROR_CLUSTER_NODE_UP = 5056,
  ERROR_CLUSTER_IPADDR_IN_USE = 5057,
  ERROR_CLUSTER_NODE_NOT_PAUSED = 5058,
  ERROR_CLUSTER_NO_SECURITY_CONTEXT = 5059,
  ERROR_CLUSTER_NETWORK_NOT_INTERNAL = 5060,
  ERROR_CLUSTER_NODE_ALREADY_UP = 5061,
  ERROR_CLUSTER_NODE_ALREADY_DOWN = 5062,
  ERROR_CLUSTER_NETWORK_ALREADY_ONLINE = 5063,
  ERROR_CLUSTER_NETWORK_ALREADY_OFFLINE = 5064,
  ERROR_CLUSTER_NODE_ALREADY_MEMBER = 5065,
  ERROR_CLUSTER_LAST_INTERNAL_NETWORK = 5066,
  ERROR_CLUSTER_NETWORK_HAS_DEPENDENTS = 5067,
  ERROR_INVALID_OPERATION_ON_QUORUM = 5068,
  ERROR_DEPENDENCY_NOT_ALLOWED = 5069,
  ERROR_CLUSTER_NODE_PAUSED = 5070,
  ERROR_NODE_CANT_HOST_RESOURCE = 5071,
  ERROR_CLUSTER_NODE_NOT_READY = 5072,
  ERROR_CLUSTER_NODE_SHUTTING_DOWN = 5073,
  ERROR_CLUSTER_JOIN_ABORTED = 5074,
  ERROR_CLUSTER_INCOMPATIBLE_VERSIONS = 5075,
  ERROR_CLUSTER_MAXNUM_OF_RESOURCES_EXCEEDED = 5076,
  ERROR_CLUSTER_SYSTEM_CONFIG_CHANGED = 5077,
  ERROR_CLUSTER_RESOURCE_TYPE_NOT_FOUND = 5078,
  ERROR_CLUSTER_RESTYPE_NOT_SUPPORTED = 5079,
  ERROR_CLUSTER_RESNAME_NOT_FOUND = 5080,
  ERROR_CLUSTER_NO_RPC_PACKAGES_REGISTERED = 5081,
  ERROR_CLUSTER_OWNER_NOT_IN_PREFLIST = 5082,
  ERROR_CLUSTER_DATABASE_SEQMISMATCH = 5083,
  ERROR_RESMON_INVALID_STATE = 5084,
  ERROR_CLUSTER_GUM_NOT_LOCKER = 5085,
  ERROR_QUORUM_DISK_NOT_FOUND = 5086,
  ERROR_DATABASE_BACKUP_CORRUPT = 5087,
  ERROR_CLUSTER_NODE_ALREADY_HAS_DFS_ROOT = 5088,
  ERROR_RESOURCE_PROPERTY_UNCHANGEABLE = 5089,
  ERROR_CLUSTER_MEMBERSHIP_INVALID_STATE = 5890,
  ERROR_CLUSTER_QUORUMLOG_NOT_FOUND = 5891,
  ERROR_CLUSTER_MEMBERSHIP_HALT = 5892,
  ERROR_CLUSTER_INSTANCE_ID_MISMATCH = 5893,
  ERROR_CLUSTER_NETWORK_NOT_FOUND_FOR_IP = 5894,
  ERROR_CLUSTER_PROPERTY_DATA_TYPE_MISMATCH = 5895,
  ERROR_CLUSTER_EVICT_WITHOUT_CLEANUP = 5896,
  ERROR_CLUSTER_PARAMETER_MISMATCH = 5897,
  ERROR_NODE_CANNOT_BE_CLUSTERED = 5898,
  ERROR_CLUSTER_WRONG_OS_VERSION = 5899,
  ERROR_CLUSTER_CANT_CREATE_DUP_CLUSTER_NAME = 5900,
  ERROR_CLUSCFG_ALREADY_COMMITTED = 5901,
  ERROR_CLUSCFG_ROLLBACK_FAILED = 5902,
  ERROR_CLUSCFG_SYSTEM_DISK_DRIVE_LETTER_CONFLICT = 5903,
  ERROR_CLUSTER_OLD_VERSION = 5904,
  ERROR_CLUSTER_MISMATCHED_COMPUTER_ACCT_NAME = 5905,
  ERROR_CLUSTER_NO_NET_ADAPTERS = 5906,
  ERROR_CLUSTER_POISONED = 5907,
  ERROR_CLUSTER_GROUP_MOVING = 5908,
  ERROR_CLUSTER_RESOURCE_TYPE_BUSY = 5909,
  ERROR_RESOURCE_CALL_TIMED_OUT = 5910,
  ERROR_INVALID_CLUSTER_IPV6_ADDRESS = 5911,
  ERROR_CLUSTER_INTERNAL_INVALID_FUNCTION = 5912,
  ERROR_CLUSTER_PARAMETER_OUT_OF_BOUNDS = 5913,
  ERROR_CLUSTER_PARTIAL_SEND = 5914,
  ERROR_CLUSTER_REGISTRY_INVALID_FUNCTION = 5915,
  ERROR_CLUSTER_INVALID_STRING_TERMINATION = 5916,
  ERROR_CLUSTER_INVALID_STRING_FORMAT = 5917,
  ERROR_CLUSTER_DATABASE_TRANSACTION_IN_PROGRESS = 5918,
  ERROR_CLUSTER_DATABASE_TRANSACTION_NOT_IN_PROGRESS = 5919,
  ERROR_CLUSTER_NULL_DATA = 5920,
  ERROR_CLUSTER_PARTIAL_READ = 5921,
  ERROR_CLUSTER_PARTIAL_WRITE = 5922,
  ERROR_CLUSTER_CANT_DESERIALIZE_DATA = 5923,
  ERROR_DEPENDENT_RESOURCE_PROPERTY_CONFLICT = 5924,
  ERROR_CLUSTER_NO_QUORUM = 5925,
  ERROR_CLUSTER_INVALID_IPV6_NETWORK = 5926,
  ERROR_CLUSTER_INVALID_IPV6_TUNNEL_NETWORK = 5927,
  ERROR_QUORUM_NOT_ALLOWED_IN_THIS_GROUP = 5928,
  ERROR_DEPENDENCY_TREE_TOO_COMPLEX = 5929,
  ERROR_EXCEPTION_IN_RESOURCE_CALL = 5930,
  ERROR_CLUSTER_RHS_FAILED_INITIALIZATION = 5931,
  ERROR_CLUSTER_NOT_INSTALLED = 5932,
  ERROR_CLUSTER_RESOURCES_MUST_BE_ONLINE_ON_THE_SAME_NODE = 5933,
  ERROR_CLUSTER_MAX_NODES_IN_CLUSTER = 5934,
  ERROR_CLUSTER_TOO_MANY_NODES = 5935,
  ERROR_CLUSTER_OBJECT_ALREADY_USED = 5936,
  ERROR_NONCORE_GROUPS_FOUND = 5937,
  ERROR_FILE_SHARE_RESOURCE_CONFLICT = 5938,
  ERROR_CLUSTER_EVICT_INVALID_REQUEST = 5939,
  ERROR_CLUSTER_SINGLETON_RESOURCE = 5940,
  ERROR_CLUSTER_GROUP_SINGLETON_RESOURCE = 5941,
  ERROR_CLUSTER_RESOURCE_PROVIDER_FAILED = 5942,
  ERROR_CLUSTER_RESOURCE_CONFIGURATION_ERROR = 5943,
  ERROR_CLUSTER_GROUP_BUSY = 5944,
  ERROR_CLUSTER_NOT_SHARED_VOLUME = 5945,
  ERROR_CLUSTER_INVALID_SECURITY_DESCRIPTOR = 5946,
  ERROR_CLUSTER_SHARED_VOLUMES_IN_USE = 5947,
  ERROR_CLUSTER_USE_SHARED_VOLUMES_API = 5948,
  ERROR_CLUSTER_BACKUP_IN_PROGRESS = 5949,
  ERROR_NON_CSV_PATH = 5950,
  ERROR_CSV_VOLUME_NOT_LOCAL = 5951,
  ERROR_CLUSTER_WATCHDOG_TERMINATING = 5952,
  ERROR_ENCRYPTION_FAILED = 6000,
  ERROR_DECRYPTION_FAILED = 6001,
  ERROR_FILE_ENCRYPTED = 6002,
  ERROR_NO_RECOVERY_POLICY = 6003,
  ERROR_NO_EFS = 6004,
  ERROR_WRONG_EFS = 6005,
  ERROR_NO_USER_KEYS = 6006,
  ERROR_FILE_NOT_ENCRYPTED = 6007,
  ERROR_NOT_EXPORT_FORMAT = 6008,
  ERROR_FILE_READ_ONLY = 6009,
  ERROR_DIR_EFS_DISALLOWED = 6010,
  ERROR_EFS_SERVER_NOT_TRUSTED = 6011,
  ERROR_BAD_RECOVERY_POLICY = 6012,
  ERROR_EFS_ALG_BLOB_TOO_BIG = 6013,
  ERROR_VOLUME_NOT_SUPPORT_EFS = 6014,
  ERROR_EFS_DISABLED = 6015,
  ERROR_EFS_VERSION_NOT_SUPPORT = 6016,
  ERROR_CS_ENCRYPTION_INVALID_SERVER_RESPONSE = 6017,
  ERROR_CS_ENCRYPTION_UNSUPPORTED_SERVER = 6018,
  ERROR_CS_ENCRYPTION_EXISTING_ENCRYPTED_FILE = 6019,
  ERROR_CS_ENCRYPTION_NEW_ENCRYPTED_FILE = 6020,
  ERROR_CS_ENCRYPTION_FILE_NOT_CSE = 6021,
  ERROR_ENCRYPTION_POLICY_DENIES_OPERATION = 6022,
  ERROR_NO_BROWSER_SERVERS_FOUND = 6118,
  SCHED_E_SERVICE_NOT_LOCALSYSTEM = 6200,
  ERROR_LOG_SECTOR_INVALID = 6600,
  ERROR_LOG_SECTOR_PARITY_INVALID = 6601,
  ERROR_LOG_SECTOR_REMAPPED = 6602,
  ERROR_LOG_BLOCK_INCOMPLETE = 6603,
  ERROR_LOG_INVALID_RANGE = 6604,
  ERROR_LOG_BLOCKS_EXHAUSTED = 6605,
  ERROR_LOG_READ_CONTEXT_INVALID = 6606,
  ERROR_LOG_RESTART_INVALID = 6607,
  ERROR_LOG_BLOCK_VERSION = 6608,
  ERROR_LOG_BLOCK_INVALID = 6609,
  ERROR_LOG_READ_MODE_INVALID = 6610,
  ERROR_LOG_NO_RESTART = 6611,
  ERROR_LOG_METADATA_CORRUPT = 6612,
  ERROR_LOG_METADATA_INVALID = 6613,
  ERROR_LOG_METADATA_INCONSISTENT = 6614,
  ERROR_LOG_RESERVATION_INVALID = 6615,
  ERROR_LOG_CANT_DELETE = 6616,
  ERROR_LOG_CONTAINER_LIMIT_EXCEEDED = 6617,
  ERROR_LOG_START_OF_LOG = 6618,
  ERROR_LOG_POLICY_ALREADY_INSTALLED = 6619,
  ERROR_LOG_POLICY_NOT_INSTALLED = 6620,
  ERROR_LOG_POLICY_INVALID = 6621,
  ERROR_LOG_POLICY_CONFLICT = 6622,
  ERROR_LOG_PINNED_ARCHIVE_TAIL = 6623,
  ERROR_LOG_RECORD_NONEXISTENT = 6624,
  ERROR_LOG_RECORDS_RESERVED_INVALID = 6625,
  ERROR_LOG_SPACE_RESERVED_INVALID = 6626,
  ERROR_LOG_TAIL_INVALID = 6627,
  ERROR_LOG_FULL = 6628,
  ERROR_COULD_NOT_RESIZE_LOG = 6629,
  ERROR_LOG_MULTIPLEXED = 6630,
  ERROR_LOG_DEDICATED = 6631,
  ERROR_LOG_ARCHIVE_NOT_IN_PROGRESS = 6632,
  ERROR_LOG_ARCHIVE_IN_PROGRESS = 6633,
  ERROR_LOG_EPHEMERAL = 6634,
  ERROR_LOG_NOT_ENOUGH_CONTAINERS = 6635,
  ERROR_LOG_CLIENT_ALREADY_REGISTERED = 6636,
  ERROR_LOG_CLIENT_NOT_REGISTERED = 6637,
  ERROR_LOG_FULL_HANDLER_IN_PROGRESS = 6638,
  ERROR_LOG_CONTAINER_READ_FAILED = 6639,
  ERROR_LOG_CONTAINER_WRITE_FAILED = 6640,
  ERROR_LOG_CONTAINER_OPEN_FAILED = 6641,
  ERROR_LOG_CONTAINER_STATE_INVALID = 6642,
  ERROR_LOG_STATE_INVALID = 6643,
  ERROR_LOG_PINNED = 6644,
  ERROR_LOG_METADATA_FLUSH_FAILED = 6645,
  ERROR_LOG_INCONSISTENT_SECURITY = 6646,
  ERROR_LOG_APPENDED_FLUSH_FAILED = 6647,
  ERROR_LOG_PINNED_RESERVATION = 6648,
  ERROR_INVALID_TRANSACTION = 6700,
  ERROR_TRANSACTION_NOT_ACTIVE = 6701,
  ERROR_TRANSACTION_REQUEST_NOT_VALID = 6702,
  ERROR_TRANSACTION_NOT_REQUESTED = 6703,
  ERROR_TRANSACTION_ALREADY_ABORTED = 6704,
  ERROR_TRANSACTION_ALREADY_COMMITTED = 6705,
  ERROR_TM_INITIALIZATION_FAILED = 6706,
  ERROR_RESOURCEMANAGER_READ_ONLY = 6707,
  ERROR_TRANSACTION_NOT_JOINED = 6708,
  ERROR_TRANSACTION_SUPERIOR_EXISTS = 6709,
  ERROR_CRM_PROTOCOL_ALREADY_EXISTS = 6710,
  ERROR_TRANSACTION_PROPAGATION_FAILED = 6711,
  ERROR_CRM_PROTOCOL_NOT_FOUND = 6712,
  ERROR_TRANSACTION_INVALID_MARSHALL_BUFFER = 6713,
  ERROR_CURRENT_TRANSACTION_NOT_VALID = 6714,
  ERROR_TRANSACTION_NOT_FOUND = 6715,
  ERROR_RESOURCEMANAGER_NOT_FOUND = 6716,
  ERROR_ENLISTMENT_NOT_FOUND = 6717,
  ERROR_TRANSACTIONMANAGER_NOT_FOUND = 6718,
  ERROR_TRANSACTIONMANAGER_NOT_ONLINE = 6719,
  ERROR_TRANSACTIONMANAGER_RECOVERY_NAME_COLLISION = 6720,
  ERROR_TRANSACTION_NOT_ROOT = 6721,
  ERROR_TRANSACTION_OBJECT_EXPIRED = 6722,
  ERROR_TRANSACTION_RESPONSE_NOT_ENLISTED = 6723,
  ERROR_TRANSACTION_RECORD_TOO_LONG = 6724,
  ERROR_IMPLICIT_TRANSACTION_NOT_SUPPORTED = 6725,
  ERROR_TRANSACTION_INTEGRITY_VIOLATED = 6726,
  ERROR_TRANSACTIONMANAGER_IDENTITY_MISMATCH = 6727,
  ERROR_RM_CANNOT_BE_FROZEN_FOR_SNAPSHOT = 6728,
  ERROR_TRANSACTION_MUST_WRITETHROUGH = 6729,
  ERROR_TRANSACTION_NO_SUPERIOR = 6730,
  ERROR_HEURISTIC_DAMAGE_POSSIBLE = 6731,
  ERROR_TRANSACTIONAL_CONFLICT = 6800,
  ERROR_RM_NOT_ACTIVE = 6801,
  ERROR_RM_METADATA_CORRUPT = 6802,
  ERROR_DIRECTORY_NOT_RM = 6803,
  ERROR_TRANSACTIONS_UNSUPPORTED_REMOTE = 6805,
  ERROR_LOG_RESIZE_INVALID_SIZE = 6806,
  ERROR_OBJECT_NO_LONGER_EXISTS = 6807,
  ERROR_STREAM_MINIVERSION_NOT_FOUND = 6808,
  ERROR_STREAM_MINIVERSION_NOT_VALID = 6809,
  ERROR_MINIVERSION_INACCESSIBLE_FROM_SPECIFIED_TRANSACTION = 6810,
  ERROR_CANT_OPEN_MINIVERSION_WITH_MODIFY_INTENT = 6811,
  ERROR_CANT_CREATE_MORE_STREAM_MINIVERSIONS = 6812,
  ERROR_REMOTE_FILE_VERSION_MISMATCH = 6814,
  ERROR_HANDLE_NO_LONGER_VALID = 6815,
  ERROR_NO_TXF_METADATA = 6816,
  ERROR_LOG_CORRUPTION_DETECTED = 6817,
  ERROR_CANT_RECOVER_WITH_HANDLE_OPEN = 6818,
  ERROR_RM_DISCONNECTED = 6819,
  ERROR_ENLISTMENT_NOT_SUPERIOR = 6820,
  ERROR_RECOVERY_NOT_NEEDED = 6821,
  ERROR_RM_ALREADY_STARTED = 6822,
  ERROR_FILE_IDENTITY_NOT_PERSISTENT = 6823,
  ERROR_CANT_BREAK_TRANSACTIONAL_DEPENDENCY = 6824,
  ERROR_CANT_CROSS_RM_BOUNDARY = 6825,
  ERROR_TXF_DIR_NOT_EMPTY = 6826,
  ERROR_INDOUBT_TRANSACTIONS_EXIST = 6827,
  ERROR_TM_VOLATILE = 6828,
  ERROR_ROLLBACK_TIMER_EXPIRED = 6829,
  ERROR_TXF_ATTRIBUTE_CORRUPT = 6830,
  ERROR_EFS_NOT_ALLOWED_IN_TRANSACTION = 6831,
  ERROR_TRANSACTIONAL_OPEN_NOT_ALLOWED = 6832,
  ERROR_LOG_GROWTH_FAILED = 6833,
  ERROR_TRANSACTED_MAPPING_UNSUPPORTED_REMOTE = 6834,
  ERROR_TXF_METADATA_ALREADY_PRESENT = 6835,
  ERROR_TRANSACTION_SCOPE_CALLBACKS_NOT_SET = 6836,
  ERROR_TRANSACTION_REQUIRED_PROMOTION = 6837,
  ERROR_CANNOT_EXECUTE_FILE_IN_TRANSACTION = 6838,
  ERROR_TRANSACTIONS_NOT_FROZEN = 6839,
  ERROR_TRANSACTION_FREEZE_IN_PROGRESS = 6840,
  ERROR_NOT_SNAPSHOT_VOLUME = 6841,
  ERROR_NO_SAVEPOINT_WITH_OPEN_FILES = 6842,
  ERROR_DATA_LOST_REPAIR = 6843,
  ERROR_SPARSE_NOT_ALLOWED_IN_TRANSACTION = 6844,
  ERROR_TM_IDENTITY_MISMATCH = 6845,
  ERROR_FLOATED_SECTION = 6846,
  ERROR_CANNOT_ACCEPT_TRANSACTED_WORK = 6847,
  ERROR_CANNOT_ABORT_TRANSACTIONS = 6848,
  ERROR_BAD_CLUSTERS = 6849,
  ERROR_COMPRESSION_NOT_ALLOWED_IN_TRANSACTION = 6850,
  ERROR_VOLUME_DIRTY = 6851,
  ERROR_NO_LINK_TRACKING_IN_TRANSACTION = 6852,
  ERROR_OPERATION_NOT_SUPPORTED_IN_TRANSACTION = 6853,
  ERROR_EXPIRED_HANDLE = 6854,
  ERROR_TRANSACTION_NOT_ENLISTED = 6855,
  ERROR_CTX_WINSTATION_NAME_INVALID = 7001,
  ERROR_CTX_INVALID_PD = 7002,
  ERROR_CTX_PD_NOT_FOUND = 7003,
  ERROR_CTX_WD_NOT_FOUND = 7004,
  ERROR_CTX_CANNOT_MAKE_EVENTLOG_ENTRY = 7005,
  ERROR_CTX_SERVICE_NAME_COLLISION = 7006,
  ERROR_CTX_CLOSE_PENDING = 7007,
  ERROR_CTX_NO_OUTBUF = 7008,
  ERROR_CTX_MODEM_INF_NOT_FOUND = 7009,
  ERROR_CTX_INVALID_MODEMNAME = 7010,
  ERROR_CTX_MODEM_RESPONSE_ERROR = 7011,
  ERROR_CTX_MODEM_RESPONSE_TIMEOUT = 7012,
  ERROR_CTX_MODEM_RESPONSE_NO_CARRIER = 7013,
  ERROR_CTX_MODEM_RESPONSE_NO_DIALTONE = 7014,
  ERROR_CTX_MODEM_RESPONSE_BUSY = 7015,
  ERROR_CTX_MODEM_RESPONSE_VOICE = 7016,
  ERROR_CTX_TD_ERROR = 7017,
  ERROR_CTX_WINSTATION_NOT_FOUND = 7022,
  ERROR_CTX_WINSTATION_ALREADY_EXISTS = 7023,
  ERROR_CTX_WINSTATION_BUSY = 7024,
  ERROR_CTX_BAD_VIDEO_MODE = 7025,
  ERROR_CTX_GRAPHICS_INVALID = 7035,
  ERROR_CTX_LOGON_DISABLED = 7037,
  ERROR_CTX_NOT_CONSOLE = 7038,
  ERROR_CTX_CLIENT_QUERY_TIMEOUT = 7040,
  ERROR_CTX_CONSOLE_DISCONNECT = 7041,
  ERROR_CTX_CONSOLE_CONNECT = 7042,
  ERROR_CTX_SHADOW_DENIED = 7044,
  ERROR_CTX_WINSTATION_ACCESS_DENIED = 7045,
  ERROR_CTX_INVALID_WD = 7049,
  ERROR_CTX_SHADOW_INVALID = 7050,
  ERROR_CTX_SHADOW_DISABLED = 7051,
  ERROR_CTX_CLIENT_LICENSE_IN_USE = 7052,
  ERROR_CTX_CLIENT_LICENSE_NOT_SET = 7053,
  ERROR_CTX_LICENSE_NOT_AVAILABLE = 7054,
  ERROR_CTX_LICENSE_CLIENT_INVALID = 7055,
  ERROR_CTX_LICENSE_EXPIRED = 7056,
  ERROR_CTX_SHADOW_NOT_RUNNING = 7057,
  ERROR_CTX_SHADOW_ENDED_BY_MODE_CHANGE = 7058,
  ERROR_ACTIVATION_COUNT_EXCEEDED = 7059,
  ERROR_CTX_WINSTATIONS_DISABLED = 7060,
  ERROR_CTX_ENCRYPTION_LEVEL_REQUIRED = 7061,
  ERROR_CTX_SESSION_IN_USE = 7062,
  ERROR_CTX_NO_FORCE_LOGOFF = 7063,
  ERROR_CTX_ACCOUNT_RESTRICTION = 7064,
  ERROR_RDP_PROTOCOL_ERROR = 7065,
  ERROR_CTX_CDM_CONNECT = 7066,
  ERROR_CTX_CDM_DISCONNECT = 7067,
  ERROR_CTX_SECURITY_LAYER_ERROR = 7068,
  ERROR_TS_INCOMPATIBLE_SESSIONS = 7069,
  ERROR_TS_VIDEO_SUBSYSTEM_ERROR = 7070,
  FRS_ERR_INVALID_API_SEQUENCE = 8001,
  FRS_ERR_STARTING_SERVICE = 8002,
  FRS_ERR_STOPPING_SERVICE = 8003,
  FRS_ERR_INTERNAL_API = 8004,
  FRS_ERR_INTERNAL = 8005,
  FRS_ERR_SERVICE_COMM = 8006,
  FRS_ERR_INSUFFICIENT_PRIV = 8007,
  FRS_ERR_AUTHENTICATION = 8008,
  FRS_ERR_PARENT_INSUFFICIENT_PRIV = 8009,
  FRS_ERR_PARENT_AUTHENTICATION = 8010,
  FRS_ERR_CHILD_TO_PARENT_COMM = 8011,
  FRS_ERR_PARENT_TO_CHILD_COMM = 8012,
  FRS_ERR_SYSVOL_POPULATE = 8013,
  FRS_ERR_SYSVOL_POPULATE_TIMEOUT = 8014,
  FRS_ERR_SYSVOL_IS_BUSY = 8015,
  FRS_ERR_SYSVOL_DEMOTE = 8016,
  FRS_ERR_INVALID_SERVICE_PARAMETER = 8017,
  DS_S_SUCCESS = 0,
  ERROR_DS_NOT_INSTALLED = 8200,
  ERROR_DS_MEMBERSHIP_EVALUATED_LOCALLY = 8201,
  ERROR_DS_NO_ATTRIBUTE_OR_VALUE = 8202,
  ERROR_DS_INVALID_ATTRIBUTE_SYNTAX = 8203,
  ERROR_DS_ATTRIBUTE_TYPE_UNDEFINED = 8204,
  ERROR_DS_ATTRIBUTE_OR_VALUE_EXISTS = 8205,
  ERROR_DS_BUSY = 8206,
  ERROR_DS_UNAVAILABLE = 8207,
  ERROR_DS_NO_RIDS_ALLOCATED = 8208,
  ERROR_DS_NO_MORE_RIDS = 8209,
  ERROR_DS_INCORRECT_ROLE_OWNER = 8210,
  ERROR_DS_RIDMGR_INIT_ERROR = 8211,
  ERROR_DS_OBJ_CLASS_VIOLATION = 8212,
  ERROR_DS_CANT_ON_NON_LEAF = 8213,
  ERROR_DS_CANT_ON_RDN = 8214,
  ERROR_DS_CANT_MOD_OBJ_CLASS = 8215,
  ERROR_DS_CROSS_DOM_MOVE_ERROR = 8216,
  ERROR_DS_GC_NOT_AVAILABLE = 8217,
  ERROR_SHARED_POLICY = 8218,
  ERROR_POLICY_OBJECT_NOT_FOUND = 8219,
  ERROR_POLICY_ONLY_IN_DS = 8220,
  ERROR_PROMOTION_ACTIVE = 8221,
  ERROR_NO_PROMOTION_ACTIVE = 8222,
  ERROR_DS_OPERATIONS_ERROR = 8224,
  ERROR_DS_PROTOCOL_ERROR = 8225,
  ERROR_DS_TIMELIMIT_EXCEEDED = 8226,
  ERROR_DS_SIZELIMIT_EXCEEDED = 8227,
  ERROR_DS_ADMIN_LIMIT_EXCEEDED = 8228,
  ERROR_DS_COMPARE_FALSE = 8229,
  ERROR_DS_COMPARE_TRUE = 8230,
  ERROR_DS_AUTH_METHOD_NOT_SUPPORTED = 8231,
  ERROR_DS_STRONG_AUTH_REQUIRED = 8232,
  ERROR_DS_INAPPROPRIATE_AUTH = 8233,
  ERROR_DS_AUTH_UNKNOWN = 8234,
  ERROR_DS_REFERRAL = 8235,
  ERROR_DS_UNAVAILABLE_CRIT_EXTENSION = 8236,
  ERROR_DS_CONFIDENTIALITY_REQUIRED = 8237,
  ERROR_DS_INAPPROPRIATE_MATCHING = 8238,
  ERROR_DS_CONSTRAINT_VIOLATION = 8239,
  ERROR_DS_NO_SUCH_OBJECT = 8240,
  ERROR_DS_ALIAS_PROBLEM = 8241,
  ERROR_DS_INVALID_DN_SYNTAX = 8242,
  ERROR_DS_IS_LEAF = 8243,
  ERROR_DS_ALIAS_DEREF_PROBLEM = 8244,
  ERROR_DS_UNWILLING_TO_PERFORM = 8245,
  ERROR_DS_LOOP_DETECT = 8246,
  ERROR_DS_NAMING_VIOLATION = 8247,
  ERROR_DS_OBJECT_RESULTS_TOO_LARGE = 8248,
  ERROR_DS_AFFECTS_MULTIPLE_DSAS = 8249,
  ERROR_DS_SERVER_DOWN = 8250,
  ERROR_DS_LOCAL_ERROR = 8251,
  ERROR_DS_ENCODING_ERROR = 8252,
  ERROR_DS_DECODING_ERROR = 8253,
  ERROR_DS_FILTER_UNKNOWN = 8254,
  ERROR_DS_PARAM_ERROR = 8255,
  ERROR_DS_NOT_SUPPORTED = 8256,
  ERROR_DS_NO_RESULTS_RETURNED = 8257,
  ERROR_DS_CONTROL_NOT_FOUND = 8258,
  ERROR_DS_CLIENT_LOOP = 8259,
  ERROR_DS_REFERRAL_LIMIT_EXCEEDED = 8260,
  ERROR_DS_SORT_CONTROL_MISSING = 8261,
  ERROR_DS_OFFSET_RANGE_ERROR = 8262,
  ERROR_DS_ROOT_MUST_BE_NC = 8301,
  ERROR_DS_ADD_REPLICA_INHIBITED = 8302,
  ERROR_DS_ATT_NOT_DEF_IN_SCHEMA = 8303,
  ERROR_DS_MAX_OBJ_SIZE_EXCEEDED = 8304,
  ERROR_DS_OBJ_STRING_NAME_EXISTS = 8305,
  ERROR_DS_NO_RDN_DEFINED_IN_SCHEMA = 8306,
  ERROR_DS_RDN_DOESNT_MATCH_SCHEMA = 8307,
  ERROR_DS_NO_REQUESTED_ATTS_FOUND = 8308,
  ERROR_DS_USER_BUFFER_TO_SMALL = 8309,
  ERROR_DS_ATT_IS_NOT_ON_OBJ = 8310,
  ERROR_DS_ILLEGAL_MOD_OPERATION = 8311,
  ERROR_DS_OBJ_TOO_LARGE = 8312,
  ERROR_DS_BAD_INSTANCE_TYPE = 8313,
  ERROR_DS_MASTERDSA_REQUIRED = 8314,
  ERROR_DS_OBJECT_CLASS_REQUIRED = 8315,
  ERROR_DS_MISSING_REQUIRED_ATT = 8316,
  ERROR_DS_ATT_NOT_DEF_FOR_CLASS = 8317,
  ERROR_DS_ATT_ALREADY_EXISTS = 8318,
  ERROR_DS_CANT_ADD_ATT_VALUES = 8320,
  ERROR_DS_SINGLE_VALUE_CONSTRAINT = 8321,
  ERROR_DS_RANGE_CONSTRAINT = 8322,
  ERROR_DS_ATT_VAL_ALREADY_EXISTS = 8323,
  ERROR_DS_CANT_REM_MISSING_ATT = 8324,
  ERROR_DS_CANT_REM_MISSING_ATT_VAL = 8325,
  ERROR_DS_ROOT_CANT_BE_SUBREF = 8326,
  ERROR_DS_NO_CHAINING = 8327,
  ERROR_DS_NO_CHAINED_EVAL = 8328,
  ERROR_DS_NO_PARENT_OBJECT = 8329,
  ERROR_DS_PARENT_IS_AN_ALIAS = 8330,
  ERROR_DS_CANT_MIX_MASTER_AND_REPS = 8331,
  ERROR_DS_CHILDREN_EXIST = 8332,
  ERROR_DS_OBJ_NOT_FOUND = 8333,
  ERROR_DS_ALIASED_OBJ_MISSING = 8334,
  ERROR_DS_BAD_NAME_SYNTAX = 8335,
  ERROR_DS_ALIAS_POINTS_TO_ALIAS = 8336,
  ERROR_DS_CANT_DEREF_ALIAS = 8337,
  ERROR_DS_OUT_OF_SCOPE = 8338,
  ERROR_DS_OBJECT_BEING_REMOVED = 8339,
  ERROR_DS_CANT_DELETE_DSA_OBJ = 8340,
  ERROR_DS_GENERIC_ERROR = 8341,
  ERROR_DS_DSA_MUST_BE_INT_MASTER = 8342,
  ERROR_DS_CLASS_NOT_DSA = 8343,
  ERROR_DS_INSUFF_ACCESS_RIGHTS = 8344,
  ERROR_DS_ILLEGAL_SUPERIOR = 8345,
  ERROR_DS_ATTRIBUTE_OWNED_BY_SAM = 8346,
  ERROR_DS_NAME_TOO_MANY_PARTS = 8347,
  ERROR_DS_NAME_TOO_LONG = 8348,
  ERROR_DS_NAME_VALUE_TOO_LONG = 8349,
  ERROR_DS_NAME_UNPARSEABLE = 8350,
  ERROR_DS_NAME_TYPE_UNKNOWN = 8351,
  ERROR_DS_NOT_AN_OBJECT = 8352,
  ERROR_DS_SEC_DESC_TOO_SHORT = 8353,
  ERROR_DS_SEC_DESC_INVALID = 8354,
  ERROR_DS_NO_DELETED_NAME = 8355,
  ERROR_DS_SUBREF_MUST_HAVE_PARENT = 8356,
  ERROR_DS_NCNAME_MUST_BE_NC = 8357,
  ERROR_DS_CANT_ADD_SYSTEM_ONLY = 8358,
  ERROR_DS_CLASS_MUST_BE_CONCRETE = 8359,
  ERROR_DS_INVALID_DMD = 8360,
  ERROR_DS_OBJ_GUID_EXISTS = 8361,
  ERROR_DS_NOT_ON_BACKLINK = 8362,
  ERROR_DS_NO_CROSSREF_FOR_NC = 8363,
  ERROR_DS_SHUTTING_DOWN = 8364,
  ERROR_DS_UNKNOWN_OPERATION = 8365,
  ERROR_DS_INVALID_ROLE_OWNER = 8366,
  ERROR_DS_COULDNT_CONTACT_FSMO = 8367,
  ERROR_DS_CROSS_NC_DN_RENAME = 8368,
  ERROR_DS_CANT_MOD_SYSTEM_ONLY = 8369,
  ERROR_DS_REPLICATOR_ONLY = 8370,
  ERROR_DS_OBJ_CLASS_NOT_DEFINED = 8371,
  ERROR_DS_OBJ_CLASS_NOT_SUBCLASS = 8372,
  ERROR_DS_NAME_REFERENCE_INVALID = 8373,
  ERROR_DS_CROSS_REF_EXISTS = 8374,
  ERROR_DS_CANT_DEL_MASTER_CROSSREF = 8375,
  ERROR_DS_SUBTREE_NOTIFY_NOT_NC_HEAD = 8376,
  ERROR_DS_NOTIFY_FILTER_TOO_COMPLEX = 8377,
  ERROR_DS_DUP_RDN = 8378,
  ERROR_DS_DUP_OID = 8379,
  ERROR_DS_DUP_MAPI_ID = 8380,
  ERROR_DS_DUP_SCHEMA_ID_GUID = 8381,
  ERROR_DS_DUP_LDAP_DISPLAY_NAME = 8382,
  ERROR_DS_SEMANTIC_ATT_TEST = 8383,
  ERROR_DS_SYNTAX_MISMATCH = 8384,
  ERROR_DS_EXISTS_IN_MUST_HAVE = 8385,
  ERROR_DS_EXISTS_IN_MAY_HAVE = 8386,
  ERROR_DS_NONEXISTENT_MAY_HAVE = 8387,
  ERROR_DS_NONEXISTENT_MUST_HAVE = 8388,
  ERROR_DS_AUX_CLS_TEST_FAIL = 8389,
  ERROR_DS_NONEXISTENT_POSS_SUP = 8390,
  ERROR_DS_SUB_CLS_TEST_FAIL = 8391,
  ERROR_DS_BAD_RDN_ATT_ID_SYNTAX = 8392,
  ERROR_DS_EXISTS_IN_AUX_CLS = 8393,
  ERROR_DS_EXISTS_IN_SUB_CLS = 8394,
  ERROR_DS_EXISTS_IN_POSS_SUP = 8395,
  ERROR_DS_RECALCSCHEMA_FAILED = 8396,
  ERROR_DS_TREE_DELETE_NOT_FINISHED = 8397,
  ERROR_DS_CANT_DELETE = 8398,
  ERROR_DS_ATT_SCHEMA_REQ_ID = 8399,
  ERROR_DS_BAD_ATT_SCHEMA_SYNTAX = 8400,
  ERROR_DS_CANT_CACHE_ATT = 8401,
  ERROR_DS_CANT_CACHE_CLASS = 8402,
  ERROR_DS_CANT_REMOVE_ATT_CACHE = 8403,
  ERROR_DS_CANT_REMOVE_CLASS_CACHE = 8404,
  ERROR_DS_CANT_RETRIEVE_DN = 8405,
  ERROR_DS_MISSING_SUPREF = 8406,
  ERROR_DS_CANT_RETRIEVE_INSTANCE = 8407,
  ERROR_DS_CODE_INCONSISTENCY = 8408,
  ERROR_DS_DATABASE_ERROR = 8409,
  ERROR_DS_GOVERNSID_MISSING = 8410,
  ERROR_DS_MISSING_EXPECTED_ATT = 8411,
  ERROR_DS_NCNAME_MISSING_CR_REF = 8412,
  ERROR_DS_SECURITY_CHECKING_ERROR = 8413,
  ERROR_DS_SCHEMA_NOT_LOADED = 8414,
  ERROR_DS_SCHEMA_ALLOC_FAILED = 8415,
  ERROR_DS_ATT_SCHEMA_REQ_SYNTAX = 8416,
  ERROR_DS_GCVERIFY_ERROR = 8417,
  ERROR_DS_DRA_SCHEMA_MISMATCH = 8418,
  ERROR_DS_CANT_FIND_DSA_OBJ = 8419,
  ERROR_DS_CANT_FIND_EXPECTED_NC = 8420,
  ERROR_DS_CANT_FIND_NC_IN_CACHE = 8421,
  ERROR_DS_CANT_RETRIEVE_CHILD = 8422,
  ERROR_DS_SECURITY_ILLEGAL_MODIFY = 8423,
  ERROR_DS_CANT_REPLACE_HIDDEN_REC = 8424,
  ERROR_DS_BAD_HIERARCHY_FILE = 8425,
  ERROR_DS_BUILD_HIERARCHY_TABLE_FAILED = 8426,
  ERROR_DS_CONFIG_PARAM_MISSING = 8427,
  ERROR_DS_COUNTING_AB_INDICES_FAILED = 8428,
  ERROR_DS_HIERARCHY_TABLE_MALLOC_FAILED = 8429,
  ERROR_DS_INTERNAL_FAILURE = 8430,
  ERROR_DS_UNKNOWN_ERROR = 8431,
  ERROR_DS_ROOT_REQUIRES_CLASS_TOP = 8432,
  ERROR_DS_REFUSING_FSMO_ROLES = 8433,
  ERROR_DS_MISSING_FSMO_SETTINGS = 8434,
  ERROR_DS_UNABLE_TO_SURRENDER_ROLES = 8435,
  ERROR_DS_DRA_GENERIC = 8436,
  ERROR_DS_DRA_INVALID_PARAMETER = 8437,
  ERROR_DS_DRA_BUSY = 8438,
  ERROR_DS_DRA_BAD_DN = 8439,
  ERROR_DS_DRA_BAD_NC = 8440,
  ERROR_DS_DRA_DN_EXISTS = 8441,
  ERROR_DS_DRA_INTERNAL_ERROR = 8442,
  ERROR_DS_DRA_INCONSISTENT_DIT = 8443,
  ERROR_DS_DRA_CONNECTION_FAILED = 8444,
  ERROR_DS_DRA_BAD_INSTANCE_TYPE = 8445,
  ERROR_DS_DRA_OUT_OF_MEM = 8446,
  ERROR_DS_DRA_MAIL_PROBLEM = 8447,
  ERROR_DS_DRA_REF_ALREADY_EXISTS = 8448,
  ERROR_DS_DRA_REF_NOT_FOUND = 8449,
  ERROR_DS_DRA_OBJ_IS_REP_SOURCE = 8450,
  ERROR_DS_DRA_DB_ERROR = 8451,
  ERROR_DS_DRA_NO_REPLICA = 8452,
  ERROR_DS_DRA_ACCESS_DENIED = 8453,
  ERROR_DS_DRA_NOT_SUPPORTED = 8454,
  ERROR_DS_DRA_RPC_CANCELLED = 8455,
  ERROR_DS_DRA_SOURCE_DISABLED = 8456,
  ERROR_DS_DRA_SINK_DISABLED = 8457,
  ERROR_DS_DRA_NAME_COLLISION = 8458,
  ERROR_DS_DRA_SOURCE_REINSTALLED = 8459,
  ERROR_DS_DRA_MISSING_PARENT = 8460,
  ERROR_DS_DRA_PREEMPTED = 8461,
  ERROR_DS_DRA_ABANDON_SYNC = 8462,
  ERROR_DS_DRA_SHUTDOWN = 8463,
  ERROR_DS_DRA_INCOMPATIBLE_PARTIAL_SET = 8464,
  ERROR_DS_DRA_SOURCE_IS_PARTIAL_REPLICA = 8465,
  ERROR_DS_DRA_EXTN_CONNECTION_FAILED = 8466,
  ERROR_DS_INSTALL_SCHEMA_MISMATCH = 8467,
  ERROR_DS_DUP_LINK_ID = 8468,
  ERROR_DS_NAME_ERROR_RESOLVING = 8469,
  ERROR_DS_NAME_ERROR_NOT_FOUND = 8470,
  ERROR_DS_NAME_ERROR_NOT_UNIQUE = 8471,
  ERROR_DS_NAME_ERROR_NO_MAPPING = 8472,
  ERROR_DS_NAME_ERROR_DOMAIN_ONLY = 8473,
  ERROR_DS_NAME_ERROR_NO_SYNTACTICAL_MAPPING = 8474,
  ERROR_DS_CONSTRUCTED_ATT_MOD = 8475,
  ERROR_DS_WRONG_OM_OBJ_CLASS = 8476,
  ERROR_DS_DRA_REPL_PENDING = 8477,
  ERROR_DS_DS_REQUIRED = 8478,
  ERROR_DS_INVALID_LDAP_DISPLAY_NAME = 8479,
  ERROR_DS_NON_BASE_SEARCH = 8480,
  ERROR_DS_CANT_RETRIEVE_ATTS = 8481,
  ERROR_DS_BACKLINK_WITHOUT_LINK = 8482,
  ERROR_DS_EPOCH_MISMATCH = 8483,
  ERROR_DS_SRC_NAME_MISMATCH = 8484,
  ERROR_DS_SRC_AND_DST_NC_IDENTICAL = 8485,
  ERROR_DS_DST_NC_MISMATCH = 8486,
  ERROR_DS_NOT_AUTHORITIVE_FOR_DST_NC = 8487,
  ERROR_DS_SRC_GUID_MISMATCH = 8488,
  ERROR_DS_CANT_MOVE_DELETED_OBJECT = 8489,
  ERROR_DS_PDC_OPERATION_IN_PROGRESS = 8490,
  ERROR_DS_CROSS_DOMAIN_CLEANUP_REQD = 8491,
  ERROR_DS_ILLEGAL_XDOM_MOVE_OPERATION = 8492,
  ERROR_DS_CANT_WITH_ACCT_GROUP_MEMBERSHPS = 8493,
  ERROR_DS_NC_MUST_HAVE_NC_PARENT = 8494,
  ERROR_DS_CR_IMPOSSIBLE_TO_VALIDATE = 8495,
  ERROR_DS_DST_DOMAIN_NOT_NATIVE = 8496,
  ERROR_DS_MISSING_INFRASTRUCTURE_CONTAINER = 8497,
  ERROR_DS_CANT_MOVE_ACCOUNT_GROUP = 8498,
  ERROR_DS_CANT_MOVE_RESOURCE_GROUP = 8499,
  ERROR_DS_INVALID_SEARCH_FLAG = 8500,
  ERROR_DS_NO_TREE_DELETE_ABOVE_NC = 8501,
  ERROR_DS_COULDNT_LOCK_TREE_FOR_DELETE = 8502,
  ERROR_DS_COULDNT_IDENTIFY_OBJECTS_FOR_TREE_DELETE = 8503,
  ERROR_DS_SAM_INIT_FAILURE = 8504,
  ERROR_DS_SENSITIVE_GROUP_VIOLATION = 8505,
  ERROR_DS_CANT_MOD_PRIMARYGROUPID = 8506,
  ERROR_DS_ILLEGAL_BASE_SCHEMA_MOD = 8507,
  ERROR_DS_NONSAFE_SCHEMA_CHANGE = 8508,
  ERROR_DS_SCHEMA_UPDATE_DISALLOWED = 8509,
  ERROR_DS_CANT_CREATE_UNDER_SCHEMA = 8510,
  ERROR_DS_INSTALL_NO_SRC_SCH_VERSION = 8511,
  ERROR_DS_INSTALL_NO_SCH_VERSION_IN_INIFILE = 8512,
  ERROR_DS_INVALID_GROUP_TYPE = 8513,
  ERROR_DS_NO_NEST_GLOBALGROUP_IN_MIXEDDOMAIN = 8514,
  ERROR_DS_NO_NEST_LOCALGROUP_IN_MIXEDDOMAIN = 8515,
  ERROR_DS_GLOBAL_CANT_HAVE_LOCAL_MEMBER = 8516,
  ERROR_DS_GLOBAL_CANT_HAVE_UNIVERSAL_MEMBER = 8517,
  ERROR_DS_UNIVERSAL_CANT_HAVE_LOCAL_MEMBER = 8518,
  ERROR_DS_GLOBAL_CANT_HAVE_CROSSDOMAIN_MEMBER = 8519,
  ERROR_DS_LOCAL_CANT_HAVE_CROSSDOMAIN_LOCAL_MEMBER = 8520,
  ERROR_DS_HAVE_PRIMARY_MEMBERS = 8521,
  ERROR_DS_STRING_SD_CONVERSION_FAILED = 8522,
  ERROR_DS_NAMING_MASTER_GC = 8523,
  ERROR_DS_DNS_LOOKUP_FAILURE = 8524,
  ERROR_DS_COULDNT_UPDATE_SPNS = 8525,
  ERROR_DS_CANT_RETRIEVE_SD = 8526,
  ERROR_DS_KEY_NOT_UNIQUE = 8527,
  ERROR_DS_WRONG_LINKED_ATT_SYNTAX = 8528,
  ERROR_DS_SAM_NEED_BOOTKEY_PASSWORD = 8529,
  ERROR_DS_SAM_NEED_BOOTKEY_FLOPPY = 8530,
  ERROR_DS_CANT_START = 8531,
  ERROR_DS_INIT_FAILURE = 8532,
  ERROR_DS_NO_PKT_PRIVACY_ON_CONNECTION = 8533,
  ERROR_DS_SOURCE_DOMAIN_IN_FOREST = 8534,
  ERROR_DS_DESTINATION_DOMAIN_NOT_IN_FOREST = 8535,
  ERROR_DS_DESTINATION_AUDITING_NOT_ENABLED = 8536,
  ERROR_DS_CANT_FIND_DC_FOR_SRC_DOMAIN = 8537,
  ERROR_DS_SRC_OBJ_NOT_GROUP_OR_USER = 8538,
  ERROR_DS_SRC_SID_EXISTS_IN_FOREST = 8539,
  ERROR_DS_SRC_AND_DST_OBJECT_CLASS_MISMATCH = 8540,
  ERROR_SAM_INIT_FAILURE = 8541,
  ERROR_DS_DRA_SCHEMA_INFO_SHIP = 8542,
  ERROR_DS_DRA_SCHEMA_CONFLICT = 8543,
  ERROR_DS_DRA_EARLIER_SCHEMA_CONFLICT = 8544,
  ERROR_DS_DRA_OBJ_NC_MISMATCH = 8545,
  ERROR_DS_NC_STILL_HAS_DSAS = 8546,
  ERROR_DS_GC_REQUIRED = 8547,
  ERROR_DS_LOCAL_MEMBER_OF_LOCAL_ONLY = 8548,
  ERROR_DS_NO_FPO_IN_UNIVERSAL_GROUPS = 8549,
  ERROR_DS_CANT_ADD_TO_GC = 8550,
  ERROR_DS_NO_CHECKPOINT_WITH_PDC = 8551,
  ERROR_DS_SOURCE_AUDITING_NOT_ENABLED = 8552,
  ERROR_DS_CANT_CREATE_IN_NONDOMAIN_NC = 8553,
  ERROR_DS_INVALID_NAME_FOR_SPN = 8554,
  ERROR_DS_FILTER_USES_CONTRUCTED_ATTRS = 8555,
  ERROR_DS_UNICODEPWD_NOT_IN_QUOTES = 8556,
  ERROR_DS_MACHINE_ACCOUNT_QUOTA_EXCEEDED = 8557,
  ERROR_DS_MUST_BE_RUN_ON_DST_DC = 8558,
  ERROR_DS_SRC_DC_MUST_BE_SP4_OR_GREATER = 8559,
  ERROR_DS_CANT_TREE_DELETE_CRITICAL_OBJ = 8560,
  ERROR_DS_INIT_FAILURE_CONSOLE = 8561,
  ERROR_DS_SAM_INIT_FAILURE_CONSOLE = 8562,
  ERROR_DS_FOREST_VERSION_TOO_HIGH = 8563,
  ERROR_DS_DOMAIN_VERSION_TOO_HIGH = 8564,
  ERROR_DS_FOREST_VERSION_TOO_LOW = 8565,
  ERROR_DS_DOMAIN_VERSION_TOO_LOW = 8566,
  ERROR_DS_INCOMPATIBLE_VERSION = 8567,
  ERROR_DS_LOW_DSA_VERSION = 8568,
  ERROR_DS_NO_BEHAVIOR_VERSION_IN_MIXEDDOMAIN = 8569,
  ERROR_DS_NOT_SUPPORTED_SORT_ORDER = 8570,
  ERROR_DS_NAME_NOT_UNIQUE = 8571,
  ERROR_DS_MACHINE_ACCOUNT_CREATED_PRENT4 = 8572,
  ERROR_DS_OUT_OF_VERSION_STORE = 8573,
  ERROR_DS_INCOMPATIBLE_CONTROLS_USED = 8574,
  ERROR_DS_NO_REF_DOMAIN = 8575,
  ERROR_DS_RESERVED_LINK_ID = 8576,
  ERROR_DS_LINK_ID_NOT_AVAILABLE = 8577,
  ERROR_DS_AG_CANT_HAVE_UNIVERSAL_MEMBER = 8578,
  ERROR_DS_MODIFYDN_DISALLOWED_BY_INSTANCE_TYPE = 8579,
  ERROR_DS_NO_OBJECT_MOVE_IN_SCHEMA_NC = 8580,
  ERROR_DS_MODIFYDN_DISALLOWED_BY_FLAG = 8581,
  ERROR_DS_MODIFYDN_WRONG_GRANDPARENT = 8582,
  ERROR_DS_NAME_ERROR_TRUST_REFERRAL = 8583,
  ERROR_NOT_SUPPORTED_ON_STANDARD_SERVER = 8584,
  ERROR_DS_CANT_ACCESS_REMOTE_PART_OF_AD = 8585,
  ERROR_DS_CR_IMPOSSIBLE_TO_VALIDATE_V2 = 8586,
  ERROR_DS_THREAD_LIMIT_EXCEEDED = 8587,
  ERROR_DS_NOT_CLOSEST = 8588,
  ERROR_DS_CANT_DERIVE_SPN_WITHOUT_SERVER_REF = 8589,
  ERROR_DS_SINGLE_USER_MODE_FAILED = 8590,
  ERROR_DS_NTDSCRIPT_SYNTAX_ERROR = 8591,
  ERROR_DS_NTDSCRIPT_PROCESS_ERROR = 8592,
  ERROR_DS_DIFFERENT_REPL_EPOCHS = 8593,
  ERROR_DS_DRS_EXTENSIONS_CHANGED = 8594,
  ERROR_DS_REPLICA_SET_CHANGE_NOT_ALLOWED_ON_DISABLED_CR = 8595,
  ERROR_DS_NO_MSDS_INTID = 8596,
  ERROR_DS_DUP_MSDS_INTID = 8597,
  ERROR_DS_EXISTS_IN_RDNATTID = 8598,
  ERROR_DS_AUTHORIZATION_FAILED = 8599,
  ERROR_DS_INVALID_SCRIPT = 8600,
  ERROR_DS_REMOTE_CROSSREF_OP_FAILED = 8601,
  ERROR_DS_CROSS_REF_BUSY = 8602,
  ERROR_DS_CANT_DERIVE_SPN_FOR_DELETED_DOMAIN = 8603,
  ERROR_DS_CANT_DEMOTE_WITH_WRITEABLE_NC = 8604,
  ERROR_DS_DUPLICATE_ID_FOUND = 8605,
  ERROR_DS_INSUFFICIENT_ATTR_TO_CREATE_OBJECT = 8606,
  ERROR_DS_GROUP_CONVERSION_ERROR = 8607,
  ERROR_DS_CANT_MOVE_APP_BASIC_GROUP = 8608,
  ERROR_DS_CANT_MOVE_APP_QUERY_GROUP = 8609,
  ERROR_DS_ROLE_NOT_VERIFIED = 8610,
  ERROR_DS_WKO_CONTAINER_CANNOT_BE_SPECIAL = 8611,
  ERROR_DS_DOMAIN_RENAME_IN_PROGRESS = 8612,
  ERROR_DS_EXISTING_AD_CHILD_NC = 8613,
  ERROR_DS_REPL_LIFETIME_EXCEEDED = 8614,
  ERROR_DS_DISALLOWED_IN_SYSTEM_CONTAINER = 8615,
  ERROR_DS_LDAP_SEND_QUEUE_FULL = 8616,
  ERROR_DS_DRA_OUT_SCHEDULE_WINDOW = 8617,
  ERROR_DS_POLICY_NOT_KNOWN = 8618,
  ERROR_NO_SITE_SETTINGS_OBJECT = 8619,
  ERROR_NO_SECRETS = 8620,
  ERROR_NO_WRITABLE_DC_FOUND = 8621,
  ERROR_DS_NO_SERVER_OBJECT = 8622,
  ERROR_DS_NO_NTDSA_OBJECT = 8623,
  ERROR_DS_NON_ASQ_SEARCH = 8624,
  ERROR_DS_AUDIT_FAILURE = 8625,
  ERROR_DS_INVALID_SEARCH_FLAG_SUBTREE = 8626,
  ERROR_DS_INVALID_SEARCH_FLAG_TUPLE = 8627,
  ERROR_DS_HIERARCHY_TABLE_TOO_DEEP = 8628,
  ERROR_DS_DRA_CORRUPT_UTD_VECTOR = 8629,
  ERROR_DS_DRA_SECRETS_DENIED = 8630,
  ERROR_DS_RESERVED_MAPI_ID = 8631,
  ERROR_DS_MAPI_ID_NOT_AVAILABLE = 8632,
  ERROR_DS_DRA_MISSING_KRBTGT_SECRET = 8633,
  ERROR_DS_DOMAIN_NAME_EXISTS_IN_FOREST = 8634,
  ERROR_DS_FLAT_NAME_EXISTS_IN_FOREST = 8635,
  ERROR_INVALID_USER_PRINCIPAL_NAME = 8636,
  ERROR_DS_OID_MAPPED_GROUP_CANT_HAVE_MEMBERS = 8637,
  ERROR_DS_OID_NOT_FOUND = 8638,
  ERROR_DS_DRA_RECYCLED_TARGET = 8639,
};

typedef enum MACRO_ERROR MACRO_ERROR;


/* 397 */
enum MACRO_IGNORE
{
  IGNORE = 0,
  INFINITE = -1,
};

typedef enum MACRO_IGNORE MACRO_IGNORE;


/* 398 */
enum MACRO_CSIDL
{
  CSIDL_DESKTOP = 0x0,
  CSIDL_INTERNET = 0x1,
  CSIDL_PROGRAMS = 0x2,
  CSIDL_CONTROLS = 0x3,
  CSIDL_PRINTERS = 0x4,
  CSIDL_PERSONAL = 0x5,
  CSIDL_FAVORITES = 0x6,
  CSIDL_STARTUP = 0x7,
  CSIDL_RECENT = 0x8,
  CSIDL_SENDTO = 0x9,
  CSIDL_BITBUCKET = 0xA,
  CSIDL_STARTMENU = 0xB,
};

typedef enum MACRO_CSIDL MACRO_CSIDL;


/* 400 */
enum event_type
{
  EVENT_TYPE_1 = 1,
  EVENT_TYPE_2 = 2,
  EVENT_TYPE_PLAYER_LEAVE_GAME = 3,
  EVENT_TYPE_PLAYER_MESSAGE = 4,
  EVENT_TYPE_5 = 5,
  EVENT_TYPE_6 = 6,
  EVENT_TYPE_7 = 7,
  EVENT_TYPE_8 = 8,
  EVENT_TYPE_9 = 9,
  EVENT_TYPE_10 = 10,
  EVENT_TYPE_11 = 11,
  EVENT_TYPE_12 = 12,
  EVENT_TYPE_13 = 13,
  EVENT_TYPE_14 = 14,
  EVENT_TYPE_15 = 15,
};

typedef enum event_type event_type;


/* 399 */
struct Event
{
  event_type event_type;
  int player_num;
  void *data;
  int data_len;
};

typedef struct Event Event;


/* 404 */
typedef _GUID GUID;

/* 405 */
enum MACRO_DDERR_UNSUPPORTED
{
  DDERR_UNSUPPORTED = -2147467263,
  DDERR_UNSUPPORTEDFORMAT = -2005532162,
  DDERR_UNSUPPORTEDMASK = -2005532152,
  DDERR_INVALIDSTREAM = -2005532151,
  DDERR_VERTICALBLANKINPROGRESS = -2005532135,
  DDERR_WASSTILLDRAWING = -2005532132,
  DDERR_DDSCAPSCOMPLEXREQUIRED = -2005532130,
  DDERR_XALIGN = -2005532112,
  DDERR_INVALIDDIRECTDRAWGUID = -2005532111,
  DDERR_DIRECTDRAWALREADYCREATED = -2005532110,
  DDERR_NODIRECTDRAWHW = -2005532109,
  DDERR_PRIMARYSURFACEALREADYEXISTS = -2005532108,
  DDERR_NOEMULATION = -2005532107,
  DDERR_REGIONTOOSMALL = -2005532106,
  DDERR_CLIPPERISUSINGHWND = -2005532105,
  DDERR_NOCLIPPERATTACHED = -2005532104,
  DDERR_NOHWND = -2005532103,
  DDERR_HWNDSUBCLASSED = -2005532102,
  DDERR_HWNDALREADYSET = -2005532101,
  DDERR_NOPALETTEATTACHED = -2005532100,
  DDERR_NOPALETTEHW = -2005532099,
  DDERR_BLTFASTCANTCLIP = -2005532098,
  DDERR_NOBLTHW = -2005532097,
  DDERR_NODDROPSHW = -2005532096,
  DDERR_OVERLAYNOTVISIBLE = -2005532095,
  DDERR_NOOVERLAYDEST = -2005532094,
  DDERR_INVALIDPOSITION = -2005532093,
  DDERR_NOTAOVERLAYSURFACE = -2005532092,
  DDERR_EXCLUSIVEMODEALREADYSET = -2005532091,
  DDERR_NOTFLIPPABLE = -2005532090,
  DDERR_CANTDUPLICATE = -2005532089,
  DDERR_NOTLOCKED = -2005532088,
  DDERR_CANTCREATEDC = -2005532087,
  DDERR_NODC = -2005532086,
  DDERR_WRONGMODE = -2005532085,
  DDERR_IMPLICITLYCREATED = -2005532084,
  DDERR_NOTPALETTIZED = -2005532083,
  DDERR_UNSUPPORTEDMODE = -2005532082,
  DDERR_NOMIPMAPHW = -2005532081,
  DDERR_INVALIDSURFACETYPE = -2005532080,
  DDERR_NOOPTIMIZEHW = -2005532072,
  DDERR_NOTLOADED = -2005532071,
  DDERR_NOFOCUSWINDOW = -2005532070,
  DDERR_NOTONMIPMAPSUBLEVEL = -2005532069,
  DDERR_DCALREADYCREATED = -2005532052,
  DDERR_NONONLOCALVIDMEM = -2005532042,
  DDERR_CANTPAGELOCK = -2005532032,
  DDERR_CANTPAGEUNLOCK = -2005532012,
  DDERR_NOTPAGELOCKED = -2005531992,
  DDERR_MOREDATA = -2005531982,
  DDERR_EXPIRED = -2005531981,
  DDERR_TESTFINISHED = -2005531980,
  DDERR_NEWMODE = -2005531979,
  DDERR_D3DNOTINITIALIZED = -2005531978,
  DDERR_VIDEONOTACTIVE = -2005531977,
  DDERR_NOMONITORINFORMATION = -2005531976,
  DDERR_NODRIVERSUPPORT = -2005531975,
  DDERR_DEVICEDOESNTOWNSURFACE = -2005531973,
};

typedef enum MACRO_DDERR_UNSUPPORTED MACRO_DDERR_UNSUPPORTED;


/* 408 */
typedef HRESULT (__stdcall *LPDDENUMMODESCALLBACK)(LPDDSURFACEDESC, LPVOID);

/* 410 */
typedef struct _DDCAPS DDCAPS;

/* 409 */
typedef DDCAPS *LPDDCAPS;

/* 412 */
typedef BOOL *LPBOOL;

/* 406 */
struct IDirectDrawVtbl
{
  HRESULT (__stdcall *QueryInterface)(struct IDirectDrawVtbl *This, const IID *const riid, LPVOID *ppvObj);
  ULONG (__stdcall *AddRef)(struct IDirectDrawVtbl *This);
  ULONG (__stdcall *Release)(struct IDirectDrawVtbl *This);
  HRESULT (__stdcall *Compact)(struct IDirectDrawVtbl *This);
  HRESULT (__stdcall *CreateClipper)(struct IDirectDrawVtbl *This, DWORD, LPDIRECTDRAWCLIPPER *, IUnknown *);
  HRESULT (__stdcall *CreatePalette)(struct IDirectDrawVtbl *This, DWORD, LPPALETTEENTRY, LPDIRECTDRAWPALETTE *, IUnknown *);
  HRESULT (__stdcall *CreateSurface)(struct IDirectDrawVtbl *This, LPDDSURFACEDESC, LPDIRECTDRAWSURFACE *, IUnknown *);
  HRESULT (__stdcall *DuplicateSurface)(struct IDirectDrawVtbl *This, LPDIRECTDRAWSURFACE, LPDIRECTDRAWSURFACE *);
  HRESULT (__stdcall *EnumDisplayModes)(struct IDirectDrawVtbl *This, DWORD, LPDDSURFACEDESC, LPVOID, LPDDENUMMODESCALLBACK);
  HRESULT (__stdcall *EnumSurfaces)(struct IDirectDrawVtbl *This, DWORD, LPDDSURFACEDESC, LPVOID, LPDDENUMSURFACESCALLBACK);
  HRESULT (__stdcall *FlipToGDISurface)(struct IDirectDrawVtbl *This);
  HRESULT (__stdcall *GetCaps)(struct IDirectDrawVtbl *This, LPDDCAPS, LPDDCAPS);
  HRESULT (__stdcall *GetDisplayMode)(struct IDirectDrawVtbl *This, LPDDSURFACEDESC);
  HRESULT (__stdcall *GetFourCCCodes)(struct IDirectDrawVtbl *This, LPDWORD, LPDWORD);
  HRESULT (__stdcall *GetGDISurface)(struct IDirectDrawVtbl *This, LPDIRECTDRAWSURFACE *);
  HRESULT (__stdcall *GetMonitorFrequency)(struct IDirectDrawVtbl *This, LPDWORD);
  HRESULT (__stdcall *GetScanLine)(struct IDirectDrawVtbl *This, LPDWORD);
  HRESULT (__stdcall *GetVerticalBlankStatus)(struct IDirectDrawVtbl *This, LPBOOL);
  HRESULT (__stdcall *Initialize)(struct IDirectDrawVtbl *This, GUID *);
  HRESULT (__stdcall *RestoreDisplayMode)(struct IDirectDrawVtbl *This);
  HRESULT (__stdcall *SetCooperativeLevel)(struct IDirectDrawVtbl *This, HWND, DWORD);
  HRESULT (__stdcall *SetDisplayMode)(struct IDirectDrawVtbl *This, DWORD, DWORD, DWORD);
  HRESULT (__stdcall *WaitForVerticalBlank)(struct IDirectDrawVtbl *This, DWORD, HANDLE);
};

typedef struct IDirectDrawVtbl IDirectDrawVtbl;


/* 411 */
struct _DDCAPS
{
  DWORD dwSize;
  DWORD dwCaps;
  DWORD dwCaps2;
  DWORD dwCKeyCaps;
  DWORD dwFXCaps;
  DWORD dwFXAlphaCaps;
  DWORD dwPalCaps;
  DWORD dwSVCaps;
  DWORD dwAlphaBltConstBitDepths;
  DWORD dwAlphaBltPixelBitDepths;
  DWORD dwAlphaBltSurfaceBitDepths;
  DWORD dwAlphaOverlayConstBitDepths;
  DWORD dwAlphaOverlayPixelBitDepths;
  DWORD dwAlphaOverlaySurfaceBitDepths;
  DWORD dwZBufferBitDepths;
  DWORD dwVidMemTotal;
  DWORD dwVidMemFree;
  DWORD dwMaxVisibleOverlays;
  DWORD dwCurrVisibleOverlays;
  DWORD dwNumFourCCCodes;
  DWORD dwAlignBoundarySrc;
  DWORD dwAlignSizeSrc;
  DWORD dwAlignBoundaryDest;
  DWORD dwAlignSizeDest;
  DWORD dwAlignStrideAlign;
  DWORD dwRops[8];
  DDSCAPS ddsCaps;
  DWORD dwMinOverlayStretch;
  DWORD dwMaxOverlayStretch;
  DWORD dwMinLiveVideoStretch;
  DWORD dwMaxLiveVideoStretch;
  DWORD dwMinHwCodecStretch;
  DWORD dwMaxHwCodecStretch;
  DWORD dwReserved1;
  DWORD dwReserved2;
  DWORD dwReserved3;
  DWORD dwSVBCaps;
  DWORD dwSVBCKeyCaps;
  DWORD dwSVBFXCaps;
  DWORD dwSVBRops[8];
  DWORD dwVSBCaps;
  DWORD dwVSBCKeyCaps;
  DWORD dwVSBFXCaps;
  DWORD dwVSBRops[8];
  DWORD dwSSBCaps;
  DWORD dwSSBCKeyCaps;
  DWORD dwSSBFXCaps;
  DWORD dwSSBRops[8];
  DWORD dwMaxVideoPorts;
  DWORD dwCurrVideoPorts;
  DWORD dwSVBCaps2;
  DWORD dwNLVBCaps;
  DWORD dwNLVBCaps2;
  DWORD dwNLVBCKeyCaps;
  DWORD dwNLVBFXCaps;
  DWORD dwNLVBRops[8];
};

typedef struct _DDCAPS _DDCAPS;


/* 413 */
enum MACRO_DDSCL
{
  DDSCL_FULLSCREEN = 0x1,
  DDSCL_ALLOWREBOOT = 0x2,
  DDSCL_NOWINDOWCHANGES = 0x4,
  DDSCL_NORMAL = 0x8,
  DDSCL_EXCLUSIVE = 0x10,
  DDSCL_ALLOWMODEX = 0x40,
  DDSCL_SETFOCUSWINDOW = 0x80,
  DDSCL_SETDEVICEWINDOW = 0x100,
  DDSCL_CREATEDEVICEWINDOW = 0x200,
  DDSCL_MULTITHREADED = 0x400,
  DDSCL_FPUSETUP = 0x800,
  DDSCL_FPUPRESERVE = 0x1000,
};

typedef enum MACRO_DDSCL MACRO_DDSCL;


/* 414 */
enum MACRO_SM
{
  SM_CXSCREEN = 0,
  SM_CYSCREEN = 1,
  SM_CXVSCROLL = 2,
  SM_CYHSCROLL = 3,
  SM_CYCAPTION = 4,
  SM_CXBORDER = 5,
  SM_CYBORDER = 6,
  SM_CXDLGFRAME = 7,
  SM_CYDLGFRAME = 8,
  SM_CYVTHUMB = 9,
  SM_CXHTHUMB = 10,
  SM_CXICON = 11,
  SM_CYICON = 12,
  SM_CXCURSOR = 13,
  SM_CYCURSOR = 14,
  SM_CYMENU = 15,
  SM_CXFULLSCREEN = 16,
  SM_CYFULLSCREEN = 17,
  SM_CYKANJIWINDOW = 18,
  SM_MOUSEPRESENT = 19,
  SM_CYVSCROLL = 20,
  SM_CXHSCROLL = 21,
  SM_DEBUG = 22,
  SM_SWAPBUTTON = 23,
  SM_RESERVED1 = 24,
  SM_RESERVED2 = 25,
  SM_RESERVED3 = 26,
  SM_RESERVED4 = 27,
  SM_CXMIN = 28,
  SM_CYMIN = 29,
  SM_CXSIZE = 30,
  SM_CYSIZE = 31,
  SM_CXFRAME = 32,
  SM_CYFRAME = 33,
  SM_CXMINTRACK = 34,
  SM_CYMINTRACK = 35,
  SM_CXDOUBLECLK = 36,
  SM_CYDOUBLECLK = 37,
  SM_CXICONSPACING = 38,
  SM_CYICONSPACING = 39,
  SM_MENUDROPALIGNMENT = 40,
  SM_PENWINDOWS = 41,
  SM_DBCSENABLED = 42,
  SM_CMOUSEBUTTONS = 43,
};

typedef enum MACRO_SM MACRO_SM;


/* 415 */
typedef _DDSURFACEDESC DDSURFACEDESC;

/* 416 */
enum MACRO_DDSD
{
  DDSD_CAPS = 0x1,
  DDSD_HEIGHT = 0x2,
  DDSD_WIDTH = 0x4,
  DDSD_PITCH = 0x8,
  DDSD_BACKBUFFERCOUNT = 0x20,
  DDSD_ZBUFFERBITDEPTH = 0x40,
  DDSD_ALPHABITDEPTH = 0x80,
  DDSD_LPSURFACE = 0x800,
  DDSD_PIXELFORMAT = 0x1000,
  DDSD_CKDESTOVERLAY = 0x2000,
  DDSD_CKDESTBLT = 0x4000,
  DDSD_CKSRCOVERLAY = 0x8000,
  DDSD_CKSRCBLT = 0x10000,
  DDSD_MIPMAPCOUNT = 0x20000,
  DDSD_REFRESHRATE = 0x40000,
  DDSD_LINEARSIZE = 0x80000,
  DDSD_TEXTURESTAGE = 0x100000,
  DDSD_FVF = 0x200000,
  DDSD_SRCVBHANDLE = 0x400000,
  DDSD_DEPTH = 0x800000,
  DDSD_ALL = 0xFFF9EE,
};

typedef enum MACRO_DDSD MACRO_DDSD;


/* 417 */
enum MACRO_DDSCAPS
{
  DDSCAPS_RESERVED1 = 0x1,
  DDSCAPS_ALPHA = 0x2,
  DDSCAPS_BACKBUFFER = 0x4,
  DDSCAPS_COMPLEX = 0x8,
  DDSCAPS_FLIP = 0x10,
  DDSCAPS_FRONTBUFFER = 0x20,
  DDSCAPS_OFFSCREENPLAIN = 0x40,
  DDSCAPS_OVERLAY = 0x80,
  DDSCAPS_PALETTE = 0x100,
  DDSCAPS_PRIMARYSURFACE = 0x200,
  DDSCAPS_RESERVED3 = 0x400,
};

typedef enum MACRO_DDSCAPS MACRO_DDSCAPS;


/* 418 */
struct IDirectDrawSurface
{
  IDirectDrawSurfaceVtbl *lpVtbl;
};

typedef struct IDirectDrawSurface IDirectDrawSurface;


/* 419 */
struct IDirectDraw
{
  IDirectDrawVtbl *lpVtbl;
};

typedef struct IDirectDraw IDirectDraw;


/* 420 */
struct ServerCommand
{
  int field_0;
  int field_4;
  char command[128];
};

typedef struct ServerCommand ServerCommand;


/* 421 */
typedef _DSCAPS DSCAPS;

/* 422 */
enum MACRO_DSSCL
{
  DSSCL_NORMAL = 0x1,
  DSSCL_PRIORITY = 0x2,
  DSSCL_EXCLUSIVE = 0x3,
  DSSCL_WRITEPRIMARY = 0x4,
};

typedef enum MACRO_DSSCL MACRO_DSSCL;


/* 423 */
typedef struct tagVS_FIXEDFILEINFO VS_FIXEDFILEINFO;

/* 424 */
struct tagVS_FIXEDFILEINFO
{
  DWORD dwSignature;
  DWORD dwStrucVersion;
  DWORD dwFileVersionMS;
  DWORD dwFileVersionLS;
  DWORD dwProductVersionMS;
  DWORD dwProductVersionLS;
  DWORD dwFileFlagsMask;
  DWORD dwFileFlags;
  DWORD dwFileOS;
  DWORD dwFileType;
  DWORD dwFileSubtype;
  DWORD dwFileDateMS;
  DWORD dwFileDateLS;
};

typedef struct tagVS_FIXEDFILEINFO tagVS_FIXEDFILEINFO;


/* 425 */
enum MACRO_FILE_SHARE
{
  FILE_SHARE_READ = 1,
  FILE_SHARE_WRITE = 2,
  FILE_SHARE_DELETE = 4,
};

typedef enum MACRO_FILE_SHARE MACRO_FILE_SHARE;


/* 426 */
enum MACRO_FILE_FLAG
{
  FILE_FLAG_WRITE_THROUGH = 0x80000000,
  FILE_FLAG_OVERLAPPED = 0x40000000,
  FILE_FLAG_NO_BUFFERING = 0x20000000,
  FILE_FLAG_RANDOM_ACCESS = 0x10000000,
  FILE_FLAG_SEQUENTIAL_SCAN = 0x8000000,
  FILE_FLAG_DELETE_ON_CLOSE = 0x4000000,
  FILE_FLAG_BACKUP_SEMANTICS = 0x2000000,
  FILE_FLAG_POSIX_SEMANTICS = 0x1000000,
  FILE_FLAG_OPEN_REPARSE_POINT = 0x200000,
  FILE_FLAG_OPEN_NO_RECALL = 0x100000,
  FILE_FLAG_FIRST_PIPE_INSTANCE = 0x80000,
};

typedef enum MACRO_FILE_FLAG MACRO_FILE_FLAG;


/* 427 */
enum MACRO_FILE_ATTRIBUTE
{
  FILE_ATTRIBUTE_READONLY = 0x1,
  FILE_ATTRIBUTE_HIDDEN = 0x2,
  FILE_ATTRIBUTE_SYSTEM = 0x4,
  FILE_ATTRIBUTE_DIRECTORY = 0x10,
  FILE_ATTRIBUTE_ARCHIVE = 0x20,
  FILE_ATTRIBUTE_DEVICE = 0x40,
  FILE_ATTRIBUTE_NORMAL = 0x80,
  FILE_ATTRIBUTE_TEMPORARY = 0x100,
  FILE_ATTRIBUTE_SPARSE_FILE = 0x200,
  FILE_ATTRIBUTE_REPARSE_POINT = 0x400,
  FILE_ATTRIBUTE_COMPRESSED = 0x800,
  FILE_ATTRIBUTE_OFFLINE = 0x1000,
  FILE_ATTRIBUTE_NOT_CONTENT_INDEXED = 0x2000,
  FILE_ATTRIBUTE_ENCRYPTED = 0x4000,
  FILE_ATTRIBUTE_VIRTUAL = 0x10000,
};

typedef enum MACRO_FILE_ATTRIBUTE MACRO_FILE_ATTRIBUTE;


/* 428 */
enum MACRO_INVALID_FILE_ATTRIBUTES
{
  INVALID_FILE_ATTRIBUTES = -1,
};

typedef enum MACRO_INVALID_FILE_ATTRIBUTES MACRO_INVALID_FILE_ATTRIBUTES;


/* 429 */
enum mpqapi_cpp
{
  BLOCK_TABLE_OFFSET = 0x68,
  HASH_ENTRIES = 0x800,
  BLOCK_TABLE_SIZE = 0x8000,
  HASH_TABLE_SIZE = 0x8000,
  HASH_TABLE_OFFSET = 0x8068,
};

typedef enum mpqapi_cpp mpqapi_cpp;


/* 430 */
struct EncData
{
  int hash_first_word;
  char field_4;
  char size;
  __int16 field_6;
  char data[1];
};

typedef struct EncData EncData;


/* 431 */
enum MACRO_PAGE
{
  PAGE_NOACCESS = 0x1,
  PAGE_READONLY = 0x2,
  PAGE_READWRITE = 0x4,
  PAGE_WRITECOPY = 0x8,
  PAGE_EXECUTE = 0x10,
  PAGE_EXECUTE_READ = 0x20,
  PAGE_EXECUTE_READWRITE = 0x40,
  PAGE_EXECUTE_WRITECOPY = 0x80,
  PAGE_GUARD = 0x100,
  PAGE_NOCACHE = 0x200,
  PAGE_WRITECOMBINE = 0x400,
  MEM_COMMIT = 0x1000,
  MEM_RESERVE = 0x2000,
  MEM_DECOMMIT = 0x4000,
  MEM_RELEASE = 0x8000,
  MEM_FREE = 0x10000,
  MEM_PRIVATE = 0x20000,
  MEM_MAPPED = 0x40000,
  MEM_RESET = 0x80000,
  MEM_TOP_DOWN = 0x100000,
  MEM_WRITE_WATCH = 0x200000,
  MEM_PHYSICAL = 0x400000,
  MEM_ROTATE = 0x800000,
  MEM_LARGE_PAGES = 0x20000000,
  MEM_4MB_PAGES = 0x80000000,
};

typedef enum MACRO_PAGE MACRO_PAGE;


/* 432 */
enum MACRO_GW
{
  GW_HWNDFIRST = 0,
  GW_HWNDLAST = 1,
  GW_HWNDNEXT = 2,
  GW_HWNDPREV = 3,
  GW_OWNER = 4,
  GW_CHILD = 5,
  GW_ENABLEDPOPUP = 6,
};

typedef enum MACRO_GW MACRO_GW;


/* 433 */
enum MACRO_DEBUG
{
  DEBUG_PROCESS = 0x1,
  DEBUG_ONLY_THIS_PROCESS = 0x2,
  CREATE_SUSPENDED = 0x4,
  DETACHED_PROCESS = 0x8,
  CREATE_NEW_CONSOLE = 0x10,
  NORMAL_PRIORITY_CLASS = 0x20,
  IDLE_PRIORITY_CLASS = 0x40,
  HIGH_PRIORITY_CLASS = 0x80,
  REALTIME_PRIORITY_CLASS = 0x100,
  CREATE_NEW_PROCESS_GROUP = 0x200,
  CREATE_UNICODE_ENVIRONMENT = 0x400,
  CREATE_SEPARATE_WOW_VDM = 0x800,
  CREATE_SHARED_WOW_VDM = 0x1000,
  CREATE_FORCEDOS = 0x2000,
  BELOW_NORMAL_PRIORITY_CLASS = 0x4000,
  ABOVE_NORMAL_PRIORITY_CLASS = 0x8000,
  INHERIT_PARENT_AFFINITY = 0x10000,
  INHERIT_CALLER_PRIORITY = 0x20000,
  CREATE_PROTECTED_PROCESS = 0x40000,
  EXTENDED_STARTUPINFO_PRESENT = 0x80000,
  PROCESS_MODE_BACKGROUND_BEGIN = 0x100000,
  PROCESS_MODE_BACKGROUND_END = 0x200000,
  CREATE_BREAKAWAY_FROM_JOB = 0x1000000,
  CREATE_PRESERVE_CODE_AUTHZ_LEVEL = 0x2000000,
  CREATE_DEFAULT_ERROR_MODE = 0x4000000,
  CREATE_NO_WINDOW = 0x8000000,
  PROFILE_USER = 0x10000000,
  PROFILE_KERNEL = 0x20000000,
  PROFILE_SERVER = 0x40000000,
  CREATE_IGNORE_SYSTEM_DEFAULT = 0x80000000,
};

typedef enum MACRO_DEBUG MACRO_DEBUG;


/* 435 */

/* 437 */

/* 439 */

/* 441 */

/* 442 */
enum text_entry_id
{
  TEXT_ENTRY_ID_TOWNERS_STORYT01_WAV_AHH_THE_STORY_OF_OUR_KING_IS_IT = 0,
  TEXT_ENTRY_ID_TOWNERS_TAVOWN21_WAV_THE_VILLAGE_NEEDS_YOUR_HELP_GOOD_MASTER = 1,
  TEXT_ENTRY_ID_TOWNERS_TAVOWN22_WAV_AS_I_TOLD_YOU_GOOD_MASTER_THE_KING_WAS_ENTOMBED = 2,
  TEXT_ENTRY_ID_TOWNERS_TAVOWN23_WAV_THE_CURSE_OF_OUR_KING_HAS_PASSED_BUT_I_FEAR = 3,
  TEXT_ENTRY_ID_TOWNERS_HEALER01_WAV_THE_LOSS_OF_HIS_SON_WAS_TOO_MUCH_FOR_KING = 4,
  TEXT_ENTRY_ID_TOWNERS_BMAID01_WAV_I_DONT_LIKE_TO_THINK_ABOUT_HOW_THE_KING_DIED = 5,
  TEXT_ENTRY_ID_TOWNERS_BSMITH01_WAV_I_MADE_MANY_OF_THE_WEAPONS_AND_MOST_OF_THE = 6,
  TEXT_ENTRY_ID_TOWNERS_DRUNK01_WAV_I_DONT_CARE_ABOUT_THAT = 7,
  TEXT_ENTRY_ID_TOWNERS_WITCH01_WAV_THE_DEAD_WHO_WALK_AMONG_THE_LIVING_FOLLOW_THE_CURSED = 8,
  TEXT_ENTRY_ID_TOWNERS_PEGBOY01_WAV_LOOK_IM_RUNNING_A_BUSINESS_HERE = 9,
  TEXT_ENTRY_ID_MONSTERS_SKING01_WAV_THE_WARMTH_OF_LIFE_HAS_ENTERED_MY_TOMB = 10,
  TEXT_ENTRY_ID_TOWNERS_STORYT02_WAV_I_SEE_THAT_THIS_STRANGE_BEHAVIOR_PUZZLES_YOU_AS_WELL = 11,
  TEXT_ENTRY_ID_TOWNERS_TAVOWN24_WAV_MASTER_I_HAVE_A_STRANGE_EXPERIENCE_TO_RELATE = 12,
  TEXT_ENTRY_ID_TOWNERS_TAVOWN25_WAV_OH_YOU_DIDNT_HAVE_TO_BRING_BACK_MY_SIGN_BUT = 13,
  TEXT_ENTRY_ID_TOWNERS_HEALER02_WAV_MY_GOODNESS_DEMONS_RUNNING_ABOUT_THE_VILLAGE_AT_NIGHT_PILLAGING = 14,
  TEXT_ENTRY_ID_TOWNERS_BMAID02_WAV_OH_MY = 15,
  TEXT_ENTRY_ID_TOWNERS_BSMITH02_WAV_DEMONS_STOLE_OGDENS_SIGN_YOU_SAY = 16,
  TEXT_ENTRY_ID_TOWNERS_DRUNK02_WAV_YOU_KNOW_WHAT_I_THINK = 17,
  TEXT_ENTRY_ID_TOWNERS_WITCH02_WAV_NO_MORTAL_CAN_TRULY_UNDERSTAND_THE_MIND_OF_THE_DEMON = 18,
  TEXT_ENTRY_ID_TOWNERS_PEGBOY02_WAV_WHAT = 19,
  TEXT_ENTRY_ID_MONSTERS_SNOT01_WAV_HEY = 20,
  TEXT_ENTRY_ID_MONSTERS_SNOT02_WAV_YOU_KILL_UGLIES_GET_BANNER = 21,
  TEXT_ENTRY_ID_MONSTERS_SNOT03_WAV_YOU_GIVE = 22,
  TEXT_ENTRY_ID_TOWNERS_STORYT36_WAV_THIS_DOES_NOT_BODE_WELL_FOR_IT_CONFIRMS_MY_DARKEST = 23,
  TEXT_ENTRY_ID_TOWNERS_STORYT37_WAV_YOU_MUST_HURRY_AND_RESCUE_ALBRECHT_FROM_THE_HANDS_OF = 24,
  TEXT_ENTRY_ID_TOWNERS_STORYT38_WAV_YOUR_STORY_IS_QUITE_GRIM_MY_FRIEND_1 = 25,
  TEXT_ENTRY_ID_TOWNERS_TAVOWN01_WAV_LAZARUS_WAS_THE_ARCHBISHOP_WHO_LED_MANY_OF_THE_TOWNSPEOPLE = 26,
  TEXT_ENTRY_ID_TOWNERS_STORYT38_WAV_YOUR_STORY_IS_QUITE_GRIM_MY_FRIEND_2 = 27,
  TEXT_ENTRY_ID_TOWNERS_STORYT38_WAV_YOUR_STORY_IS_QUITE_GRIM_MY_FRIEND_3 = 28,
  TEXT_ENTRY_ID_TOWNERS_HEALER03_WAV_I_WAS_SHOCKED_WHEN_I_HEARD_OF_WHAT_THE_TOWNSPEOPLE = 29,
  TEXT_ENTRY_ID_TOWNERS_BMAID03_WAV_I_REMEMBER_LAZARUS_AS_BEING_A_VERY_KIND_AND_GIVING = 30,
  TEXT_ENTRY_ID_TOWNERS_BSMITH03_WAV_I_WAS_THERE_WHEN_LAZARUS_LED_US_INTO_THE_LABYRINTH = 31,
  TEXT_ENTRY_ID_TOWNERS_DRUNK03_WAV_THEY_STAB_THEN_BITE_THEN_THEYRE_ALL_AROUND_YOU = 32,
  TEXT_ENTRY_ID_TOWNERS_WITCH03_WAV_I_DID_NOT_KNOW_THIS_LAZARUS_OF_WHOM_YOU_SPEAK = 33,
  TEXT_ENTRY_ID_TOWNERS_PEGBOY03_WAV_YES_THE_RIGHTEOUS_LAZARUS_WHO_WAS_SOOO_EFFECTIVE_AGAINST_THOSE = 34,
  TEXT_ENTRY_ID_MONSTERS_LAZ01_WAV_ABANDON_YOUR_FOOLISH_QUEST_1 = 35,
  TEXT_ENTRY_ID_MONSTERS_LAZ01_WAV_ABANDON_YOUR_FOOLISH_QUEST_2 = 36,
  TEXT_ENTRY_ID_TOWNERS_STORYT04_WAV_HMM_I_DONT_KNOW_WHAT_I_CAN_REALLY_TELL_YOU = 37,
  TEXT_ENTRY_ID_TOWNERS_TAVOWN02_WAV_I_HAVE_ALWAYS_TRIED_TO_KEEP_A_LARGE_SUPPLY_OF = 38,
  TEXT_ENTRY_ID_TOWNERS_HEALER20_WAV_IM_GLAD_I_CAUGHT_UP_TO_YOU_IN_TIME = 39,
  TEXT_ENTRY_ID_TOWNERS_HEALER21_WAV_PLEASE_YOU_MUST_HURRY = 40,
  TEXT_ENTRY_ID_TOWNERS_HEALER22_WAV_WHATS_THAT_YOU_SAY = 41,
  TEXT_ENTRY_ID_TOWNERS_BMAID04_WAV_MY_GRANDMOTHER_IS_VERY_WEAK_AND_GARDA_SAYS_THAT_WE = 42,
  TEXT_ENTRY_ID_TOWNERS_BSMITH04_WAV_PEPIN_HAS_TOLD_YOU_THE_TRUTH = 43,
  TEXT_ENTRY_ID_TOWNERS_DRUNK04_WAV_YOU_DRINK_WATER = 44,
  TEXT_ENTRY_ID_TOWNERS_WITCH04_WAV_THE_PEOPLE_OF_TRISTRAM_WILL_DIE_IF_YOU_CANNOT_RESTORE = 45,
  TEXT_ENTRY_ID_TOWNERS_PEGBOY04_WAV_FOR_ONCE_IM_WITH_YOU = 46,
  TEXT_ENTRY_ID_TOWNERS_STORYT07_WAV_A_BOOK_THAT_SPEAKS_OF_A_CHAMBER_OF_HUMAN_BONES = 47,
  TEXT_ENTRY_ID_TOWNERS_TAVOWN05_WAV_I_AM_AFRAID_THAT_I_DONT_KNOW_ANYTHING_ABOUT_THAT = 48,
  TEXT_ENTRY_ID_TOWNERS_HEALER05_WAV_THIS_SOUNDS_LIKE_A_VERY_DANGEROUS_PLACE = 49,
  TEXT_ENTRY_ID_TOWNERS_BMAID06_WAV_I_AM_AFRAID_THAT_I_HAVENT_HEARD_ANYTHING_ABOUT_THAT = 50,
  TEXT_ENTRY_ID_TOWNERS_BSMITH07_WAV_I_KNOW_NOTHING_OF_THIS_PLACE_BUT_YOU_MAY_TRY = 51,
  TEXT_ENTRY_ID_TOWNERS_DRUNK07_WAV_OKAY_SO_LISTEN = 52,
  TEXT_ENTRY_ID_TOWNERS_WITCH07_WAV_YOU_WILL_BECOME_AN_ETERNAL_SERVANT_OF_THE_DARK_LORDS = 53,
  TEXT_ENTRY_ID_TOWNERS_PEGBOY07_WAV_A_VAST_AND_MYSTERIOUS_TREASURE_YOU_SAY = 54,
  TEXT_ENTRY_ID_TOWNERS_STORYT10_WAV_IT_SEEMS_THAT_THE_ARCHBISHOP_LAZARUS_GOADED_MANY_OF_THE = 55,
  TEXT_ENTRY_ID_TOWNERS_TAVOWN08_WAV_YES_FARNHAM_HAS_MUMBLED_SOMETHING_ABOUT_A_HULKING_BRUTE_WHO = 56,
  TEXT_ENTRY_ID_TOWNERS_HEALER08_WAV_BY_THE_LIGHT_I_KNOW_OF_THIS_VILE_DEMON = 57,
  TEXT_ENTRY_ID_TOWNERS_BMAID08_WAV_WHEN_FARNHAM_SAID_SOMETHING_ABOUT_A_BUTCHER_KILLING_PEOPLE_I = 58,
  TEXT_ENTRY_ID_TOWNERS_BSMITH10_WAV_I_SAW_WHAT_FARNHAM_CALLS_THE_BUTCHER_AS_IT_SWATHED = 59,
  TEXT_ENTRY_ID_TOWNERS_DRUNK10_WAV_BIG = 60,
  TEXT_ENTRY_ID_TOWNERS_WITCH10_WAV_THE_BUTCHER_IS_A_SADISTIC_CREATURE_THAT_DELIGHTS_IN_THE = 61,
  TEXT_ENTRY_ID_TOWNERS_PEGBOY10_WAV_I_KNOW_MORE_THAN_YOUD_THINK_ABOUT_THAT_GRISLY_FIEND = 62,
  TEXT_ENTRY_ID_TOWNERS_WOUND01_WAV_PLEASE_LISTEN_TO_ME = 63,
  TEXT_ENTRY_ID_MONSTERS_BUTCHER_WAV = 64,
  TEXT_ENTRY_ID_TOWNERS_STORYT12_WAV_YOU_RECITE_AN_INTERESTING_RHYME_WRITTEN_IN_A_STYLE_THAT = 65,
  TEXT_ENTRY_ID_TOWNERS_TAVOWN10_WAV_I_NEVER_MUCH_CARED_FOR_POETRY = 66,
  TEXT_ENTRY_ID_TOWNERS_HEALER10_WAV_THIS_DOES_SEEM_FAMILIAR_SOMEHOW = 67,
  TEXT_ENTRY_ID_TOWNERS_BMAID10_WAV_IF_YOU_HAVE_QUESTIONS_ABOUT_BLINDNESS_YOU_SHOULD_TALK_TO = 68,
  TEXT_ENTRY_ID_TOWNERS_BSMITH12_WAV_I_AM_AFRAID_THAT_I_HAVE_NEITHER_HEARD_NOR_SEEN = 69,
  TEXT_ENTRY_ID_TOWNERS_DRUNK12_WAV_LOOK_HERE = 70,
  TEXT_ENTRY_ID_TOWNERS_WITCH12_WAV_THIS_IS_A_PLACE_OF_GREAT_ANGUISH_AND_TERROR_AND = 71,
  TEXT_ENTRY_ID_TOWNERS_PEGBOY11_WAV_LETS_SEE_AM_I_SELLING_YOU_SOMETHING = 72,
  TEXT_ENTRY_ID_TOWNERS_STORYT13_WAV_YOU_CLAIM_TO_HAVE_SPOKEN_WITH_LACHDANAN = 73,
  TEXT_ENTRY_ID_TOWNERS_TAVOWN11_WAV_YOU_SPEAK_OF_A_BRAVE_WARRIOR_LONG_DEAD = 74,
  TEXT_ENTRY_ID_TOWNERS_HEALER11_WAV_A_GOLDEN_ELIXIR_YOU_SAY = 75,
  TEXT_ENTRY_ID_TOWNERS_BMAID11_WAV_IVE_NEVER_HEARD_OF_A_LACHDANAN_BEFORE = 76,
  TEXT_ENTRY_ID_TOWNERS_BSMITH13_WAV_IF_IT_IS_ACTUALLY_LACHDANAN_THAT_YOU_HAVE_MET_THEN = 77,
  TEXT_ENTRY_ID_TOWNERS_DRUNK13_WAV_LACHDANAN_IS_DEAD = 78,
  TEXT_ENTRY_ID_TOWNERS_WITCH13_WAV_YOU_MAY_MEET_PEOPLE_WHO_ARE_TRAPPED_WITHIN_THE_LABYRINTH = 79,
  TEXT_ENTRY_ID_TOWNERS_PEGBOY12_WAV_WAIT_LET_ME_GUESS = 80,
  TEXT_ENTRY_ID_MONSTERS_LACH01_WAV_PLEASE_DONT_KILL_ME_JUST_HEAR_ME_OUT = 81,
  TEXT_ENTRY_ID_MONSTERS_LACH02_WAV_YOU_HAVE_NOT_FOUND_THE_GOLDEN_ELIXIR = 82,
  TEXT_ENTRY_ID_MONSTERS_LACH03_WAV_YOU_HAVE_SAVED_MY_SOUL_FROM_DAMNATION_AND_FOR_THAT = 83,
  TEXT_ENTRY_ID_TOWNERS_STORYT14_WAV_GRISWOLD_SPEAKS_OF_THE_ANVIL_OF_FURY = 84,
  TEXT_ENTRY_ID_TOWNERS_TAVOWN12_WAV_DONT_YOU_THINK_THAT_GRISWOLD_WOULD_BE_A_BETTER_PERSON = 85,
  TEXT_ENTRY_ID_TOWNERS_HEALER12_WAV_IF_YOU_HAD_BEEN_LOOKING_FOR_INFORMATION_ON_THE_PESTLE = 86,
  TEXT_ENTRY_ID_TOWNERS_BMAID12_WAV_GRISWOLDS_FATHER_USED_TO_TELL_SOME_OF_US_WHEN_WE = 87,
  TEXT_ENTRY_ID_TOWNERS_BSMITH21_WAV_GREETINGS = 88,
  TEXT_ENTRY_ID_TOWNERS_BSMITH22_WAV_NOTHING_YET_EH = 89,
  TEXT_ENTRY_ID_TOWNERS_BSMITH23_WAV_I_CAN_HARDLY_BELIEVE_IT = 90,
  TEXT_ENTRY_ID_TOWNERS_DRUNK14_WAV_GRISWOLD_CANT_SELL_HIS_ANVIL = 91,
  TEXT_ENTRY_ID_TOWNERS_WITCH14_WAV_THERE_ARE_MANY_ARTIFACTS_WITHIN_THE_LABYRINTH_THAT_HOLD_POWERS = 92,
  TEXT_ENTRY_ID_TOWNERS_PEGBOY13_WAV_IF_YOU_WERE_TO_FIND_THIS_ARTIFACT_FOR_GRISWOLD_IT = 93,
  TEXT_ENTRY_ID_TOWNERS_STORYT15_WAV_THE_GATEWAY_OF_BLOOD_AND_THE_HALLS_OF_FIRE_ARE = 94,
  TEXT_ENTRY_ID_TOWNERS_TAVOWN13_WAV_EVERY_CHILD_HEARS_THE_STORY_OF_THE_WARRIOR_ARKAINE_AND = 95,
  TEXT_ENTRY_ID_TOWNERS_HEALER13_WAV_HMM = 96,
  TEXT_ENTRY_ID_TOWNERS_BMAID13_WAV_THE_STORY_OF_THE_MAGIC_ARMOR_CALLED_VALOR_IS_SOMETHING = 97,
  TEXT_ENTRY_ID_TOWNERS_BSMITH14_WAV_THE_ARMOR_KNOWN_AS_VALOR_COULD_BE_WHAT_TIPS_THE = 98,
  TEXT_ENTRY_ID_TOWNERS_DRUNK15_WAV_ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ = 99,
  TEXT_ENTRY_ID_TOWNERS_WITCH15_WAV_SHOULD_YOU_FIND_THESE_STONES_OF_BLOOD_USE_THEM_CAREFULLY = 100,
  TEXT_ENTRY_ID_TOWNERS_PEGBOY14_WAV_YOU_INTEND_TO_FIND_THE_ARMOR_KNOWN_AS_VALOR = 101,
  TEXT_ENTRY_ID_TOWNERS_STORYT18_WAV_I_KNOW_OF_ONLY_ONE_LEGEND_THAT_SPEAKS_OF_SUCH = 102,
  TEXT_ENTRY_ID_TOWNERS_TAVOWN16_WAV_I_AM_AFRAID_THAT_I_HAVENT_HEARD_ANYTHING_ABOUT_SUCH = 103,
  TEXT_ENTRY_ID_TOWNERS_HEALER16_WAV_CAIN_WOULD_BE_ABLE_TO_TELL_YOU_MUCH_MORE_ABOUT = 104,
  TEXT_ENTRY_ID_TOWNERS_BMAID16_WAV_IF_YOU_ARE_TO_BATTLE_SUCH_A_FIERCE_OPPONENT_MAY = 105,
  TEXT_ENTRY_ID_TOWNERS_BSMITH17_WAV_DARK_AND_WICKED_LEGENDS_SURROUNDS_THE_ONE_WARLORD_OF_BLOOD = 106,
  TEXT_ENTRY_ID_TOWNERS_DRUNK17_WAV_ALWAYS_YOU_GOTTA_TALK_ABOUT_BLOOD = 107,
  TEXT_ENTRY_ID_TOWNERS_WITCH18_WAV_HIS_PROWESS_WITH_THE_BLADE_IS_AWESOME_AND_HE_HAS = 108,
  TEXT_ENTRY_ID_TOWNERS_PEGBOY17_WAV_I_HAVENT_EVER_DEALT_WITH_THIS_WARLORD_YOU_SPEAK_OF = 109,
  TEXT_ENTRY_ID_MONSTERS_WARLRD01_WAV_MY_BLADE_SINGS_FOR_YOUR_BLOOD_MORTAL_AND_BY_MY = 110,
  TEXT_ENTRY_ID_TOWNERS_STORYT20_WAV_GRISWOLD_SPEAKS_OF_THE_HEAVEN_STONE_THAT_WAS_DESTINED_FOR = 111,
  TEXT_ENTRY_ID_TOWNERS_TAVOWN18_WAV_THE_CARAVAN_STOPPED_HERE_TO_TAKE_ON_SOME_SUPPLIES_FOR = 112,
  TEXT_ENTRY_ID_TOWNERS_HEALER18_WAV_I_DONT_KNOW_WHAT_IT_IS_THAT_THEY_THOUGHT_THEY = 113,
  TEXT_ENTRY_ID_TOWNERS_BMAID18_WAV_WELL_A_CARAVAN_OF_SOME_VERY_IMPORTANT_PEOPLE_DID_STOP = 114,
  TEXT_ENTRY_ID_TOWNERS_BSMITH24_WAV_STAY_FOR_A_MOMENT = 115,
  TEXT_ENTRY_ID_TOWNERS_BSMITH25_WAV_I_AM_STILL_WAITING_FOR_YOU_TO_BRING_ME_THAT = 116,
  TEXT_ENTRY_ID_TOWNERS_BSMITH26_WAV_LET_ME_SEE_THAT = 117,
  TEXT_ENTRY_ID_TOWNERS_DRUNK19_WAV_I_USED_TO_HAVE_A_NICE_RING = 118,
  TEXT_ENTRY_ID_TOWNERS_WITCH20_WAV_THE_HEAVEN_STONE_IS_VERY_POWERFUL_AND_WERE_IT_ANY = 119,
  TEXT_ENTRY_ID_TOWNERS_PEGBOY18_WAV_IF_ANYONE_CAN_MAKE_SOMETHING_OUT_OF_THAT_ROCK_GRISWOLD = 120,
  TEXT_ENTRY_ID_TOWNERS_STORYT21_WAV_THE_WITCH_ADRIA_SEEKS_A_BLACK_MUSHROOM = 121,
  TEXT_ENTRY_ID_TOWNERS_TAVOWN19_WAV_LET_ME_JUST_SAY_THIS = 122,
  TEXT_ENTRY_ID_TOWNERS_HEALER26_WAV_THE_WITCH_TOLD_ME_THAT_YOU_WERE_SEARCHING_FOR_THE = 123,
  TEXT_ENTRY_ID_TOWNERS_HEALER27_WAV_EXCELLENT_THIS_IS_JUST_WHAT_I_HAD_IN_MIND = 124,
  TEXT_ENTRY_ID_TOWNERS_BMAID19_WAV_I_THINK_OGDEN_MIGHT_HAVE_SOME_MUSHROOMS_IN_THE_STORAGE = 125,
  TEXT_ENTRY_ID_TOWNERS_BSMITH19_WAV_IF_ADRIA_DOESNT_HAVE_ONE_OF_THESE_YOU_CAN_BET = 126,
  TEXT_ENTRY_ID_TOWNERS_DRUNK20_WAV_OGDEN_MIXES_A_MEAN_BLACK_MUSHROOM_BUT_I_GET_SICK = 127,
  TEXT_ENTRY_ID_TOWNERS_WITCH22_WAV_WHAT_DO_WE_HAVE_HERE = 128,
  TEXT_ENTRY_ID_TOWNERS_WITCH23_WAV_ITS_A_BIG_BLACK_MUSHROOM_THAT_I_NEED = 129,
  TEXT_ENTRY_ID_TOWNERS_WITCH24_WAV_YES_THIS_WILL_BE_PERFECT_FOR_A_BREW_THAT_I = 130,
  TEXT_ENTRY_ID_TOWNERS_WITCH25_WAV_WHY_HAVE_YOU_BROUGHT_THAT_HERE = 131,
  TEXT_ENTRY_ID_TOWNERS_WITCH26_WAV_WHAT = 132,
  TEXT_ENTRY_ID_TOWNERS_PEGBOY19_WAV_I_DONT_HAVE_ANY_MUSHROOMS_OF_ANY_SIZE_OR_COLOR = 133,
  TEXT_ENTRY_ID_TOWNERS_STORYT22_WAV_SO_THE_LEGEND_OF_THE_MAP_IS_REAL = 134,
  TEXT_ENTRY_ID_TOWNERS_STORYT23_WAV_OUR_TIME_IS_RUNNING_SHORT = 135,
  TEXT_ENTRY_ID_TOWNERS_STORYT24_WAV_I_AM_SURE_THAT_YOU_TRIED_YOUR_BEST_BUT_I = 136,
  TEXT_ENTRY_ID_TOWNERS_TAVOWN20_WAV_IF_THE_WITCH_CANT_HELP_YOU_AND_SUGGESTS_YOU_SEE = 137,
  TEXT_ENTRY_ID_TOWNERS_HEALER19_WAV_I_CANT_MAKE_MUCH_OF_THE_WRITING_ON_THIS_MAP = 138,
  TEXT_ENTRY_ID_TOWNERS_BMAID20_WAV_THE_BEST_PERSON_TO_ASK_ABOUT_THAT_SORT_OF_THING = 139,
  TEXT_ENTRY_ID_TOWNERS_BSMITH20_WAV_I_HAVE_NEVER_SEEN_A_MAP_OF_THIS_SORT_BEFORE = 140,
  TEXT_ENTRY_ID_TOWNERS_DRUNK21_WAV_LISTEN_HERE_COME_CLOSE = 141,
  TEXT_ENTRY_ID_TOWNERS_WITCH21_WAV_OH_IM_AFRAID_THIS_DOES_NOT_BODE_WELL_AT_ALL = 142,
  TEXT_ENTRY_ID_TOWNERS_PEGBOY20_WAV_IVE_BEEN_LOOKING_FOR_A_MAP_BUT_THAT_CERTAINLY_ISNT = 143,
  TEXT_ENTRY_ID_MONSTERS_GARBUD01_WAV_PLEEEEASE_NO_HURT = 144,
  TEXT_ENTRY_ID_MONSTERS_GARBUD02_WAV_SOMETHING_FOR_YOU_I_AM_MAKING = 145,
  TEXT_ENTRY_ID_MONSTERS_GARBUD03_WAV_NOTHING_YET = 146,
  TEXT_ENTRY_ID_MONSTERS_GARBUD04_WAV_THIS_TOO_GOOD_FOR_YOU = 147,
  TEXT_ENTRY_ID_MONSTERS_ZHAR01_WAV_WHAT = 148,
  TEXT_ENTRY_ID_MONSTERS_ZHAR02_WAV_ARRRRGH = 149,
  TEXT_ENTRY_ID_TOWNERS_STORYT25_WAV_HELLO_MY_FRIEND = 150,
  TEXT_ENTRY_ID_TOWNERS_STORYT26_WAV_WHILE_YOU_ARE_VENTURING_DEEPER_INTO_THE_LABYRINTH_YOU_MAY = 151,
  TEXT_ENTRY_ID_TOWNERS_STORYT27_WAV_I_KNOW_OF_MANY_MYTHS_AND_LEGENDS_THAT_MAY_CONTAIN = 152,
  TEXT_ENTRY_ID_TOWNERS_STORYT28_WAV_GRISWOLD = 153,
  TEXT_ENTRY_ID_TOWNERS_STORYT29_WAV_OGDEN_HAS_OWNED_AND_RUN_THE_RISING_SUN_INN_AND = 154,
  TEXT_ENTRY_ID_TOWNERS_STORYT30_WAV_POOR_FARNHAM = 155,
  TEXT_ENTRY_ID_TOWNERS_STORYT31_WAV_THE_WITCH_ADRIA_IS_AN_ANOMALY_HERE_IN_TRISTRAM = 156,
  TEXT_ENTRY_ID_TOWNERS_STORYT33_WAV_THE_STORY_OF_WIRT_IS_A_FRIGHTENING_AND_TRAGIC_ONE = 157,
  TEXT_ENTRY_ID_TOWNERS_STORYT34_WAV_AH_PEPIN = 158,
  TEXT_ENTRY_ID_TOWNERS_STORYT35_WAV_GILLIAN_IS_A_FINE_WOMAN = 159,
  TEXT_ENTRY_ID_TOWNERS_TAVOWN36_WAV_GREETINGS_GOOD_MASTER = 160,
  TEXT_ENTRY_ID_TOWNERS_TAVOWN37_WAV_MANY_ADVENTURERS_HAVE_GRACED_THE_TABLES_OF_MY_TAVERN_AND = 161,
  TEXT_ENTRY_ID_TOWNERS_TAVOWN38_WAV_GRISWOLD_THE_BLACKSMITH_IS_EXTREMELY_KNOWLEDGEABLE_ABOUT_WEAPONS_AND_ARMOR = 162,
  TEXT_ENTRY_ID_TOWNERS_TAVOWN39_WAV_FARNHAM_SPENDS_FAR_TOO_MUCH_TIME_HERE_DROWNING_HIS_SORROWS = 163,
  TEXT_ENTRY_ID_TOWNERS_TAVOWN40_WAV_ADRIA_IS_WISE_BEYOND_HER_YEARS_BUT_I_MUST_ADMIT = 164,
  TEXT_ENTRY_ID_TOWNERS_TAVOWN41_WAV_IF_YOU_WANT_TO_KNOW_MORE_ABOUT_THE_HISTORY_OF = 165,
  TEXT_ENTRY_ID_TOWNERS_TAVOWN43_WAV_WIRT_IS_A_RAPSCALLION_AND_A_LITTLE_SCOUNDREL = 166,
  TEXT_ENTRY_ID_TOWNERS_TAVOWN44_WAV_PEPIN_IS_A_GOOD_MAN = 167,
  TEXT_ENTRY_ID_TOWNERS_TAVOWN45_WAV_GILLIAN_MY_BARMAID = 168,
  TEXT_ENTRY_ID_TOWNERS_HEALER37_WAV_WHAT_AILS_YOU_MY_FRIEND = 169,
  TEXT_ENTRY_ID_TOWNERS_HEALER38_WAV_I_HAVE_MADE_A_VERY_INTERESTING_DISCOVERY = 170,
  TEXT_ENTRY_ID_TOWNERS_HEALER39_WAV_BEFORE_IT_WAS_TAKEN_OVER_BY_WELL_WHATEVER_LURKS_BELOW = 171,
  TEXT_ENTRY_ID_TOWNERS_HEALER40_WAV_GRISWOLD_KNOWS_AS_MUCH_ABOUT_THE_ART_OF_WAR_AS = 172,
  TEXT_ENTRY_ID_TOWNERS_HEALER41_WAV_CAIN_IS_A_TRUE_FRIEND_AND_A_WISE_SAGE = 173,
  TEXT_ENTRY_ID_TOWNERS_HEALER42_WAV_EVEN_MY_SKILLS_HAVE_BEEN_UNABLE_TO_FULLY_HEAL_FARNHAM = 174,
  TEXT_ENTRY_ID_TOWNERS_HEALER43_WAV_WHILE_I_USE_SOME_LIMITED_FORMS_OF_MAGIC_TO_CREATE = 175,
  TEXT_ENTRY_ID_TOWNERS_HEALER45_WAV_POOR_WIRT = 176,
  TEXT_ENTRY_ID_TOWNERS_HEALER46_WAV_I_REALLY_DONT_UNDERSTAND_WHY_OGDEN_STAYS_HERE_IN_TRISTRAM = 177,
  TEXT_ENTRY_ID_TOWNERS_HEALER47_WAV_OGDENS_BARMAID_IS_A_SWEET_GIRL = 178,
  TEXT_ENTRY_ID_TOWNERS_BMAID31_WAV_GOOD_DAY = 179,
  TEXT_ENTRY_ID_TOWNERS_BMAID32_WAV_MY_GRANDMOTHER_HAD_A_DREAM_THAT_YOU_WOULD_COME_AND = 180,
  TEXT_ENTRY_ID_TOWNERS_BMAID33_WAV_THE_WOMAN_AT_THE_EDGE_OF_TOWN_IS_A_WITCH = 181,
  TEXT_ENTRY_ID_TOWNERS_BMAID34_WAV_OUR_BLACKSMITH_IS_A_POINT_OF_PRIDE_TO_THE_PEOPLE = 182,
  TEXT_ENTRY_ID_TOWNERS_BMAID35_WAV_CAIN_HAS_BEEN_THE_STORYTELLER_OF_TRISTRAM_FOR_AS_LONG = 183,
  TEXT_ENTRY_ID_TOWNERS_BMAID36_WAV_FARNHAM_IS_A_DRUNKARD_WHO_FILLS_HIS_BELLY_WITH_ALE = 184,
  TEXT_ENTRY_ID_TOWNERS_BMAID37_WAV_PEPIN_SAVED_MY_GRANDMOTHERS_LIFE_AND_I_KNOW_THAT_I = 185,
  TEXT_ENTRY_ID_TOWNERS_BMAID39_WAV_I_GREW_UP_WITH_WIRTS_MOTHER_CANACE = 186,
  TEXT_ENTRY_ID_TOWNERS_BMAID40_WAV_OGDEN_AND_HIS_WIFE_HAVE_TAKEN_ME_AND_MY_GRANDMOTHER = 187,
  TEXT_ENTRY_ID_TOWNERS_BSMITH44_WAV_WELL_WHAT_CAN_I_DO_FOR_YA = 188,
  TEXT_ENTRY_ID_TOWNERS_BSMITH45_WAV_IF_YOURE_LOOKING_FOR_A_GOOD_WEAPON_LET_ME_SHOW = 189,
  TEXT_ENTRY_ID_TOWNERS_BSMITH46_WAV_THE_AXE = 190,
  TEXT_ENTRY_ID_TOWNERS_BSMITH47_WAV_LOOK_AT_THAT_EDGE_THAT_BALANCE = 191,
  TEXT_ENTRY_ID_TOWNERS_BSMITH48_WAV_YOUR_WEAPONS_AND_ARMOR_WILL_SHOW_THE_SIGNS_OF_YOUR = 192,
  TEXT_ENTRY_ID_TOWNERS_BSMITH49_WAV_WHILE_I_HAVE_TO_PRACTICALLY_SMUGGLE_IN_THE_METALS_AND = 193,
  TEXT_ENTRY_ID_TOWNERS_BSMITH50_WAV_GILLIAN_IS_A_NICE_LASS = 194,
  TEXT_ENTRY_ID_TOWNERS_BSMITH51_WAV_SOMETIMES_I_THINK_THAT_CAIN_TALKS_TOO_MUCH_BUT_I = 195,
  TEXT_ENTRY_ID_TOWNERS_BSMITH52_WAV_I_WAS_WITH_FARNHAM_THAT_NIGHT_THAT_LAZARUS_LED_US = 196,
  TEXT_ENTRY_ID_TOWNERS_BSMITH53_WAV_A_GOOD_MAN_WHO_PUTS_THE_NEEDS_OF_OTHERS_ABOVE = 197,
  TEXT_ENTRY_ID_TOWNERS_BSMITH55_WAV_THAT_LAD_IS_GOING_TO_GET_HIMSELF_INTO_SERIOUS_TROUBLE = 198,
  TEXT_ENTRY_ID_TOWNERS_BSMITH56_WAV_THE_INNKEEPER_HAS_LITTLE_BUSINESS_AND_NO_REAL_WAY_OF = 199,
  TEXT_ENTRY_ID_TOWNERS_DRUNK27_WAV_CANT_A_FELLA_DRINK_IN_PEACE = 200,
  TEXT_ENTRY_ID_TOWNERS_DRUNK28_WAV_THE_GAL_WHO_BRINGS_THE_DRINKS = 201,
  TEXT_ENTRY_ID_TOWNERS_DRUNK29_WAV_WHY_DONT_THAT_OLD_CRONE_DO_SOMETHIN_FOR_A_CHANGE = 202,
  TEXT_ENTRY_ID_TOWNERS_DRUNK30_WAV_CAIN_ISNT_WHAT_HE_SAYS_HE_IS = 203,
  TEXT_ENTRY_ID_TOWNERS_DRUNK31_WAV_GRISWOLD = 204,
  TEXT_ENTRY_ID_TOWNERS_DRUNK32_WAV_HEHEHE_I_LIKE_PEPIN = 205,
  TEXT_ENTRY_ID_TOWNERS_DRUNK34_WAV_WIRT_IS_A_KID_WITH_MORE_PROBLEMS_THAN_EVEN_ME = 206,
  TEXT_ENTRY_ID_TOWNERS_DRUNK35_WAV_OGDEN_IS_THE_BEST_MAN_IN_TOWN = 207,
  TEXT_ENTRY_ID_TOWNERS_DRUNK23_WAV_I_WANNA_TELL_YA_SUMTHIN_CAUSE_I_KNOW_ALL_ABOUT = 208,
  TEXT_ENTRY_ID_TOWNERS_DRUNK24_WAV_NO_ONE_EVER_LIS = 209,
  TEXT_ENTRY_ID_TOWNERS_DRUNK25_WAV_I_KNOW_YOU_GOTS_YOUR_OWN_IDEAS_AND_I_KNOW = 210,
  TEXT_ENTRY_ID_TOWNERS_DRUNK26_WAV_IF_I_WAS_YOU = 211,
  TEXT_ENTRY_ID_TOWNERS_WITCH38_WAV_I_SENSE_A_SOUL_IN_SEARCH_OF_ANSWERS = 212,
  TEXT_ENTRY_ID_TOWNERS_WITCH39_WAV_WISDOM_IS_EARNED_NOT_GIVEN = 213,
  TEXT_ENTRY_ID_TOWNERS_WITCH40_WAV_THE_GREATEST_POWER_IS_OFTEN_THE_SHORTEST_LIVED = 214,
  TEXT_ENTRY_ID_TOWNERS_WITCH41_WAV_THOUGH_THE_HEAT_OF_THE_SUN_IS_BEYOND_MEASURE_THE = 215,
  TEXT_ENTRY_ID_TOWNERS_WITCH42_WAV_THE_SUM_OF_OUR_KNOWLEDGE_IS_IN_THE_SUM_OF = 216,
  TEXT_ENTRY_ID_TOWNERS_WITCH43_WAV_TO_A_MAN_WHO_ONLY_KNOWS_IRON_THERE_IS_NO = 217,
  TEXT_ENTRY_ID_TOWNERS_WITCH44_WAV_CORRUPTION_HAS_THE_STRENGTH_OF_DECEIT_BUT_INNOCENCE_HOLDS_THE = 218,
  TEXT_ENTRY_ID_TOWNERS_WITCH45_WAV_A_CHEST_OPENED_IN_DARKNESS_HOLDS_NO_GREATER_TREASURE_THAN = 219,
  TEXT_ENTRY_ID_TOWNERS_WITCH46_WAV_THE_HIGHER_YOU_PLACE_YOUR_FAITH_IN_ONE_MAN_THE = 220,
  TEXT_ENTRY_ID_TOWNERS_WITCH47_WAV_THE_HAND_THE_HEART_AND_THE_MIND_CAN_PERFORM_MIRACLES = 221,
  TEXT_ENTRY_ID_TOWNERS_WITCH49_WAV_THERE_IS_MUCH_ABOUT_THE_FUTURE_WE_CANNOT_SEE_BUT = 222,
  TEXT_ENTRY_ID_TOWNERS_WITCH50_WAV_EARTHEN_WALLS_AND_THATCHED_CANOPY_DO_NOT_A_HOME_CREATE = 223,
  TEXT_ENTRY_ID_TOWNERS_PEGBOY32_WAV_PSSST = 224,
  TEXT_ENTRY_ID_TOWNERS_PEGBOY33_WAV_NOT_EVERYONE_IN_TRISTRAM_HAS_A_USE = 225,
  TEXT_ENTRY_ID_TOWNERS_PEGBOY34_WAV_DONT_TRUST_EVERYTHING_THE_DRUNK_SAYS = 226,
  TEXT_ENTRY_ID_TOWNERS_PEGBOY35_WAV_IN_CASE_YOU_HAVENT_NOTICED_I_DONT_BUY_ANYTHING_FROM = 227,
  TEXT_ENTRY_ID_TOWNERS_PEGBOY36_WAV_I_GUESS_I_OWE_THE_BLACKSMITH_MY_LIFE = 228,
  TEXT_ENTRY_ID_TOWNERS_PEGBOY37_WAV_IF_I_WERE_A_FEW_YEARS_OLDER_I_WOULD_SHOWER = 229,
  TEXT_ENTRY_ID_TOWNERS_PEGBOY38_WAV_CAIN_KNOWS_TOO_MUCH = 230,
  TEXT_ENTRY_ID_TOWNERS_PEGBOY39_WAV_FARNHAM = 231,
  TEXT_ENTRY_ID_TOWNERS_PEGBOY40_WAV_AS_LONG_AS_YOU_DONT_NEED_ANYTHING_REATTACHED_OLD_PEPIN = 232,
  TEXT_ENTRY_ID_TOWNERS_PEGBOY42_WAV_ADRIA_TRULY_BOTHERS_ME = 233,
  TEXT_ENTRY_ID_TOWNERS_PEGBOY43_WAV_OGDEN_IS_A_FOOL_FOR_STAYING_HERE = 234,
  TEXT_ENTRY_ID_WARRIOR_WARIOR01_WAV_BEYOND_THE_HALL_OF_HEROES_LIES_THE_CHAMBER_OF_BONE = 235,
  TEXT_ENTRY_ID_WARRIOR_WARIOR10_WAV = 236,
  TEXT_ENTRY_ID_WARRIOR_WARIOR11_WAV_I_CAN_SEE_WHAT_YOU_SEE_NOT = 237,
  TEXT_ENTRY_ID_WARRIOR_WARIOR12_WAV_THE_ARMORIES_OF_HELL_ARE_HOME_TO_THE_WARLORD_OF = 238,
  TEXT_ENTRY_ID_SORCEROR_MAGE01_WAV_BEYOND_THE_HALL_OF_HEROES_LIES_THE_CHAMBER_OF_BONE = 239,
  TEXT_ENTRY_ID_SORCEROR_MAGE10_WAV = 240,
  TEXT_ENTRY_ID_SORCEROR_MAGE11_WAV_I_CAN_SEE_WHAT_YOU_SEE_NOT = 241,
  TEXT_ENTRY_ID_SORCEROR_MAGE12_WAV_THE_ARMORIES_OF_HELL_ARE_HOME_TO_THE_WARLORD_OF = 242,
  TEXT_ENTRY_ID_ROGUE_ROGUE01_WAV_BEYOND_THE_HALL_OF_HEROES_LIES_THE_CHAMBER_OF_BONE = 243,
  TEXT_ENTRY_ID_ROGUE_ROGUE10_WAV = 244,
  TEXT_ENTRY_ID_ROGUE_ROGUE11_WAV_I_CAN_SEE_WHAT_YOU_SEE_NOT = 245,
  TEXT_ENTRY_ID_ROGUE_ROGUE12_WAV_THE_ARMORIES_OF_HELL_ARE_HOME_TO_THE_WARLORD_OF = 246,
  TEXT_ENTRY_ID_TOWNERS_COW1_WAV = 247,
  TEXT_ENTRY_ID_TOWNERS_COW2_WAV = 248,
  TEXT_ENTRY_ID_NARRATOR_NAR01_WAV_TAKE_HEED_AND_BEAR_WITNESS_TO_THE_TRUTHS_THAT_LIE = 249,
  TEXT_ENTRY_ID_NARRATOR_NAR02_WAV_TAKE_HEED_AND_BEAR_WITNESS_TO_THE_TRUTHS_THAT_LIE = 250,
  TEXT_ENTRY_ID_NARRATOR_NAR03_WAV_TAKE_HEED_AND_BEAR_WITNESS_TO_THE_TRUTHS_THAT_LIE = 251,
  TEXT_ENTRY_ID_NARRATOR_NAR04_WAV_SO_IT_CAME_TO_BE_THAT_THERE_WAS_A_GREAT = 252,
  TEXT_ENTRY_ID_NARRATOR_NAR05_WAV_MANY_DEMONS_TRAVELED_TO_THE_MORTAL_REALM_IN_SEARCH_OF = 253,
  TEXT_ENTRY_ID_NARRATOR_NAR06_WAV_SO_IT_CAME_TO_BE_THAT_THE_THREE_PRIME_EVILS = 254,
  TEXT_ENTRY_ID_NARRATOR_NAR07_WAV_ALL_PRAISES_TO_DIABLO = 255,
  TEXT_ENTRY_ID_NARRATOR_NAR08_WAV_GLORY_AND_APPROBATION_TO_DIABLO = 256,
  TEXT_ENTRY_ID_NARRATOR_NAR09_WAV_HAIL_AND_SACRIFICE_TO_DIABLO = 257,
  TEXT_ENTRY_ID_TOWNERS_TAVOWN00_WAV_THANK_GOODNESS_YOUVE_RETURNED = 258,
  TEXT_ENTRY_ID_INVALID = -1,
};

typedef enum text_entry_id text_entry_id;


/* 443 */

/* 445 */
struct Range_i8
{
  Coord_i8 start;
  Coord_i8 end;
};

typedef struct Range_i8 Range_i8;


/* 446 */

/* 448 */
enum $9DB83DF310AE821A8AF058A4B0743E5B
{
  PANEL_BUTTON_ID_CHARACTER_INFORMATION = 0x0,
  PANEL_BUTTON_ID_QUESTS_LOG = 0x1,
  PANEL_BUTTON_ID_AUTOMAP = 0x2,
  PANEL_BUTTON_ID_MAIN_MENU = 0x3,
  PANEL_BUTTON_ID_INVENTORY = 0x4,
  PANEL_BUTTON_ID_SPELL_BOOK = 0x5,
  PANEL_BUTTON_ID_SEND_MESSAGE = 0x6,
  PANEL_BUTTON_ID_PLAYER_ATTACK = 0x7,
};

typedef enum $9DB83DF310AE821A8AF058A4B0743E5B $9DB83DF310AE821A8AF058A4B0743E5B;


/* 449 */
typedef enum $9DB83DF310AE821A8AF058A4B0743E5B panel_button_id;

/* 450 */
struct aa
{
};

typedef struct aa aa;


/* 452 */

/* 456 */

/* 459 */

/* 461 */

/* 462 */
enum unique_item_base
{
  UNIQUE_ITEM_BASE_NONE = 0,
  UNIQUE_ITEM_BASE_SHORT_BOW = 1,
  UNIQUE_ITEM_BASE_LONG_BOW = 2,
  UNIQUE_ITEM_BASE_HUNTERS_BOW = 3,
  UNIQUE_ITEM_BASE_COMPOSITE_BOW = 4,
  UNIQUE_ITEM_BASE_LONG_WAR_BOW = 5,
  UNIQUE_ITEM_BASE_LONG_BATTLE_BOW = 6,
  UNIQUE_ITEM_BASE_DAGGER = 7,
  UNIQUE_ITEM_BASE_FALCHION = 8,
  UNIQUE_ITEM_BASE_CLAYMORE = 9,
  UNIQUE_ITEM_BASE_BROAD_SWORD = 10,
  UNIQUE_ITEM_BASE_SABRE = 11,
  UNIQUE_ITEM_BASE_SCIMITAR = 12,
  UNIQUE_ITEM_BASE_LONG_SWORD = 13,
  UNIQUE_ITEM_BASE_BASTARD_SWORD = 14,
  UNIQUE_ITEM_BASE_TWO_HANDED_SWORD = 15,
  UNIQUE_ITEM_BASE_GREAT_SWORD = 16,
  UNIQUE_ITEM_BASE_CLEAVER = 17,
  UNIQUE_ITEM_BASE_LARGE_AXE = 18,
  UNIQUE_ITEM_BASE_BROAD_AXE = 19,
  UNIQUE_ITEM_BASE_SMALL_AXE = 20,
  UNIQUE_ITEM_BASE_BATTLE_AXE = 21,
  UNIQUE_ITEM_BASE_GREAT_AXE = 22,
  UNIQUE_ITEM_BASE_MACE = 23,
  UNIQUE_ITEM_BASE_MORNING_STAR = 24,
  UNIQUE_ITEM_BASE_SPIKED_CLUB = 25,
  UNIQUE_ITEM_BASE_MAUL = 26,
  UNIQUE_ITEM_BASE_WAR_HAMMER = 27,
  UNIQUE_ITEM_BASE_FLAIL = 28,
  UNIQUE_ITEM_BASE_LONG_STAFF = 29,
  UNIQUE_ITEM_BASE_SHORT_STAFF = 30,
  UNIQUE_ITEM_BASE_COMPOSITE_STAFF = 31,
  UNIQUE_ITEM_BASE_QUARTER_STAFF = 32,
  UNIQUE_ITEM_BASE_WAR_STAFF = 33,
  UNIQUE_ITEM_BASE_SKULL_CAP = 34,
  UNIQUE_ITEM_BASE_HELM = 35,
  UNIQUE_ITEM_BASE_GREAT_HELM = 36,
  UNIQUE_ITEM_BASE_CROWN = 37,
  UNIQUE_ITEM_BASE_RAGS = 39,
  UNIQUE_ITEM_BASE_STUDDED_LEATHER_ARMOR = 40,
  UNIQUE_ITEM_BASE_CLOAK = 41,
  UNIQUE_ITEM_BASE_ROBE = 42,
  UNIQUE_ITEM_BASE_CHAIN_MAIL = 43,
  UNIQUE_ITEM_BASE_LEATHER_ARMOR = 44,
  UNIQUE_ITEM_BASE_BREAST_PLATE = 45,
  UNIQUE_ITEM_BASE_CAPE = 46,
  UNIQUE_ITEM_BASE_PLATE_MAIL = 47,
  UNIQUE_ITEM_BASE_FULL_PLATE_MAIL = 48,
  UNIQUE_ITEM_BASE_BUCKLER = 49,
  UNIQUE_ITEM_BASE_SMALL_SHIELD = 50,
  UNIQUE_ITEM_BASE_LARGE_SHIELD = 51,
  UNIQUE_ITEM_BASE_KITE_SHIELD = 52,
  UNIQUE_ITEM_BASE_GOTHIC_SHIELD = 53,
  UNIQUE_ITEM_BASE_RING = 54,
  UNIQUE_ITEM_BASE_AMULET = 56,
  UNIQUE_ITEM_BASE_THE_UNDEAD_CROWN = 57,
  UNIQUE_ITEM_BASE_EMPYREAN_BAND = 58,
  UNIQUE_ITEM_BASE_OPTIC_AMULET = 59,
  UNIQUE_ITEM_BASE_RING_OF_TRUTH = 60,
  UNIQUE_ITEM_BASE_HARLEQUIN_CREST = 61,
  UNIQUE_ITEM_BASE_MAP_OF_THE_STARS = 62,
  UNIQUE_ITEM_BASE_ELIXIR = 63,
  UNIQUE_ITEM_BASE_ARKAINES_VALOR = 64,
  UNIQUE_ITEM_BASE_VEIL_OF_STEEL = 65,
  UNIQUE_ITEM_BASE_GRISWOLDS_EDGE = 66,
  UNIQUE_ITEM_BASE_LIGHTFORGE = 67,
  UNIQUE_ITEM_BASE_STAFF_OF_LAZARUS = 68,
  UNIQUE_ITEM_BASE_INVALID = -1,
};

typedef enum unique_item_base unique_item_base;


/* 463 */

/* 465 */

/* 467 */

/* 469 */

/* 470 */

/* 472 */
struct DialogueLine
{
  int field_0;
  int y_offset;
  char text[128];
  int field_88;
  text_color text_color;
  char reserved__8D[3];
  int field_90;
  int field_94;
  int gold_price;
};

typedef struct DialogueLine DialogueLine;


/* 473 */

/* 475 */

/* 477 */
enum $D86B1499A3998351956D6DD2FA2F2454
{
  UNIQUE_MONSTER_ID_GHARBAD_THE_WEAK = 0x0,
  UNIQUE_MONSTER_ID_SKELETON_KING = 0x1,
  UNIQUE_MONSTER_ID_ZHAR_THE_MAD = 0x2,
  UNIQUE_MONSTER_ID_SNOTSPILL = 0x3,
  UNIQUE_MONSTER_ID_ARCH_BISHOP_LAZARUS = 0x4,
  UNIQUE_MONSTER_ID_RED_VEX = 0x5,
  UNIQUE_MONSTER_ID_BLACKJADE = 0x6,
  UNIQUE_MONSTER_ID_LACHDANAN = 0x7,
  UNIQUE_MONSTER_ID_WARLORD_OF_BLOOD = 0x8,
  UNIQUE_MONSTER_ID_THE_BUTCHER = 0x9,
  UNIQUE_MONSTER_ID_BONEHEAD_KEENAXE = 0xA,
  UNIQUE_MONSTER_ID_BLADESKIN_THE_SLASHER = 0xB,
  UNIQUE_MONSTER_ID_SOULPUS = 0xC,
  UNIQUE_MONSTER_ID_PUKERAT_THE_UNCLEAN = 0xD,
  UNIQUE_MONSTER_ID_BONERIPPER = 0xE,
  UNIQUE_MONSTER_ID_ROTFEAST_THE_HUNGRY = 0xF,
  UNIQUE_MONSTER_ID_GUTSHANK_THE_QUICK = 0x10,
  UNIQUE_MONSTER_ID_BROKENHEAD_BANGSHIELD = 0x11,
  UNIQUE_MONSTER_ID_BONGO = 0x12,
  UNIQUE_MONSTER_ID_ROTCARNAGE = 0x13,
  UNIQUE_MONSTER_ID_SHADOWBITE = 0x14,
  UNIQUE_MONSTER_ID_DEADEYE = 0x15,
  UNIQUE_MONSTER_ID_MADEYE_THE_DEAD = 0x16,
  UNIQUE_MONSTER_ID_EL_CHUPACABRAS = 0x17,
  UNIQUE_MONSTER_ID_SKULLFIRE = 0x18,
  UNIQUE_MONSTER_ID_WARPSKULL = 0x19,
  UNIQUE_MONSTER_ID_GORETONGUE = 0x1A,
  UNIQUE_MONSTER_ID_PULSECRAWLER = 0x1B,
  UNIQUE_MONSTER_ID_MOONBENDER = 0x1C,
  UNIQUE_MONSTER_ID_WRATHRAVEN = 0x1D,
  UNIQUE_MONSTER_ID_SPINEEATER = 0x1E,
  UNIQUE_MONSTER_ID_BLACKASH_THE_BURNING = 0x1F,
  UNIQUE_MONSTER_ID_SHADOWCROW = 0x20,
  UNIQUE_MONSTER_ID_BLIGHTSTONE_THE_WEAK = 0x21,
  UNIQUE_MONSTER_ID_BILEFROTH_THE_PIT_MASTER = 0x22,
  UNIQUE_MONSTER_ID_BLOODSKIN_DARKBOW = 0x23,
  UNIQUE_MONSTER_ID_FOULWING = 0x24,
  UNIQUE_MONSTER_ID_SHADOWDRINKER = 0x25,
  UNIQUE_MONSTER_ID_HAZESHIFTER = 0x26,
  UNIQUE_MONSTER_ID_DEATHSPIT = 0x27,
  UNIQUE_MONSTER_ID_BLOODGUTTER = 0x28,
  UNIQUE_MONSTER_ID_DEATHSHADE_FLESHMAUL = 0x29,
  UNIQUE_MONSTER_ID_WARMAGGOT_THE_MAD = 0x2A,
  UNIQUE_MONSTER_ID_GLASSKULL_THE_JAGGED = 0x2B,
  UNIQUE_MONSTER_ID_BLIGHTFIRE = 0x2C,
  UNIQUE_MONSTER_ID_NIGHTWING_THE_COLD = 0x2D,
  UNIQUE_MONSTER_ID_GORESTONE = 0x2E,
  UNIQUE_MONSTER_ID_BRONZEFIST_FIRESTONE = 0x2F,
  UNIQUE_MONSTER_ID_WRATHFIRE_THE_DOOMED = 0x30,
  UNIQUE_MONSTER_ID_FIREWOUND_THE_GRIM = 0x31,
  UNIQUE_MONSTER_ID_BARON_SLUDGE = 0x32,
  UNIQUE_MONSTER_ID_BLIGHTHORN_STEELMACE = 0x33,
  UNIQUE_MONSTER_ID_CHAOSHOWLER = 0x34,
  UNIQUE_MONSTER_ID_DOOMGRIN_THE_ROTTING = 0x35,
  UNIQUE_MONSTER_ID_MADBURNER = 0x36,
  UNIQUE_MONSTER_ID_BONESAW_THE_LITCH = 0x37,
  UNIQUE_MONSTER_ID_BREAKSPINE = 0x38,
  UNIQUE_MONSTER_ID_DEVILSKULL_SHARPBONE = 0x39,
  UNIQUE_MONSTER_ID_BROKENSTORM = 0x3A,
  UNIQUE_MONSTER_ID_STORMBANE = 0x3B,
  UNIQUE_MONSTER_ID_OOZEDROOL = 0x3C,
  UNIQUE_MONSTER_ID_GOLDBLIGHT_OF_THE_FLAME = 0x3D,
  UNIQUE_MONSTER_ID_BLACKSTORM = 0x3E,
  UNIQUE_MONSTER_ID_PLAGUEWRATH = 0x3F,
  UNIQUE_MONSTER_ID_THE_FLAYER = 0x40,
  UNIQUE_MONSTER_ID_BLUEHORN = 0x41,
  UNIQUE_MONSTER_ID_WARPFIRE_HELLSPAWN = 0x42,
  UNIQUE_MONSTER_ID_FANGSPEIR = 0x43,
  UNIQUE_MONSTER_ID_FESTERSKULL = 0x44,
  UNIQUE_MONSTER_ID_LIONSKULL_THE_BENT = 0x45,
  UNIQUE_MONSTER_ID_BLACKTONGUE = 0x46,
  UNIQUE_MONSTER_ID_VILETOUCH = 0x47,
  UNIQUE_MONSTER_ID_VIPERFLAME = 0x48,
  UNIQUE_MONSTER_ID_FANGSKIN = 0x49,
  UNIQUE_MONSTER_ID_WITCHFIRE_THE_UNHOLY = 0x4A,
  UNIQUE_MONSTER_ID_BLACKSKULL = 0x4B,
  UNIQUE_MONSTER_ID_SOULSLASH = 0x4C,
  UNIQUE_MONSTER_ID_WINDSPAWN = 0x4D,
  UNIQUE_MONSTER_ID_LORD_OF_THE_PIT = 0x4E,
  UNIQUE_MONSTER_ID_RUSTWEAVER = 0x4F,
  UNIQUE_MONSTER_ID_HOWLINGIRE_THE_SHADE = 0x50,
  UNIQUE_MONSTER_ID_DOOMCLOUD = 0x51,
  UNIQUE_MONSTER_ID_BLOODMOON_SOULFIRE = 0x52,
  UNIQUE_MONSTER_ID_WITCHMOON = 0x53,
  UNIQUE_MONSTER_ID_GOREFEAST = 0x54,
  UNIQUE_MONSTER_ID_GRAYWAR_THE_SLAYER = 0x55,
  UNIQUE_MONSTER_ID_DREADJUDGE = 0x56,
  UNIQUE_MONSTER_ID_STAREYE_THE_WITCH = 0x57,
  UNIQUE_MONSTER_ID_STEELSKULL_THE_HUNTER = 0x58,
  UNIQUE_MONSTER_ID_SIR_GORASH = 0x59,
  UNIQUE_MONSTER_ID_THE_VIZIER = 0x5A,
  UNIQUE_MONSTER_ID_ZAMPHIR = 0x5B,
  UNIQUE_MONSTER_ID_BLOODLUST = 0x5C,
  UNIQUE_MONSTER_ID_WEBWIDOW = 0x5D,
  UNIQUE_MONSTER_ID_FLESHDANCER = 0x5E,
  UNIQUE_MONSTER_ID_GRIMSPIKE = 0x5F,
  UNIQUE_MONSTER_ID_DOOMLOCK = 0x60,
  UNIQUE_MONSTER_ID_NULL = 0x61,
};

typedef enum $D86B1499A3998351956D6DD2FA2F2454 $D86B1499A3998351956D6DD2FA2F2454;


/* 478 */
typedef enum $D86B1499A3998351956D6DD2FA2F2454 unique_monster_id;

/* 479 */

/* 480 */
enum l1_tile_id
{
  L1_TILE_ID_NONE = 0,
  L1_TILE_ID_WALL_SW = 1,
  L1_TILE_ID_WALL_SE = 2,
  L1_TILE_ID_ARCH_NE_ARCH_NW = 3,
  L1_TILE_ID_WALL_SW_WALL_SE = 4,
  L1_TILE_ID_ARCH_SW_ARCH_SE = 5,
  L1_TILE_ID_WALL_END_SW = 6,
  L1_TILE_ID_WALL_END_SE = 7,
  L1_TILE_ID_ARCH_END_SW = 8,
  L1_TILE_ID_ARCH_END_SE = 9,
  L1_TILE_ID_WALL_SW_ARCH_SE = 10,
  L1_TILE_ID_ARCH_SW = 11,
  L1_TILE_ID_ARCH_SE = 12,
  L1_TILE_ID_FLOOR = 13,
  L1_TILE_ID_ARCH_SW_WALL_SE = 14,
  L1_TILE_ID_COLUMN = 15,
  L1_TILE_ID_ARCH_END_NE = 16,
  L1_TILE_ID_ARCH_END_NW = 17,
  L1_TILE_ID_DIRT_WALL_SW = 18,
  L1_TILE_ID_DIRT_WALL_SE = 19,
  L1_TILE_ID_DIRT_WALL_NE_WALL_NW = 20,
  L1_TILE_ID_DIRT_WALL_SW_WALL_SE = 21,
  L1_TILE_ID_DIRT = 22,
  L1_TILE_ID_DIRT_WALL_END_SW = 23,
  L1_TILE_ID_DIRT_WALL_END_SE = 24,
  L1_TILE_ID_DOOR_SW = 25,
  L1_TILE_ID_DOOR_SE = 26,
  L1_TILE_ID_WALL_SW_BAR_SE = 27,
  L1_TILE_ID_DOOR_SW_DOOR_SE = 28,
  L1_TILE_ID_BAR_SW_BAR_SE = 29,
  L1_TILE_ID_DOOR_END_SW = 30,
  L1_TILE_ID_DOOR_END_SE = 31,
  L1_TILE_ID_BAR_END_SW = 32,
  L1_TILE_ID_BAR_END_SE = 33,
  L1_TILE_ID_DOOR_SW_BAR_SE = 34,
  L1_TILE_ID_BAR_SW = 35,
  L1_TILE_ID_BAR_SE = 36,
  L1_TILE_ID_BAR_SW_WALL_SE = 37,
  L1_TILE_ID_BAR_SW_ARCH_SE = 38,
  L1_TILE_ID_BAR_SW_DOOR_SE = 39,
  L1_TILE_ID_DOOR_SW_ARCH_SE = 40,
  L1_TILE_ID_DOOR_SW_WALL_SE = 41,
  L1_TILE_ID_ARCH_SW_DOOR_SE = 42,
  L1_TILE_ID_WALL_SW_DOOR_SE = 43,
  L1_TILE_ID_ARCH_SW_BAR_SE = 44,
  L1_TILE_ID_CIRCLE_MARKING_1 = 45,
  L1_TILE_ID_CIRCLE_MARKING_2 = 46,
  L1_TILE_ID_CIRCLE_MARKING_3 = 47,
  L1_TILE_ID_CIRCLE_MARKING_4 = 48,
  L1_TILE_ID_CIRCLE_MARKING_5 = 49,
  L1_TILE_ID_CIRCLE_MARKING_6 = 50,
  L1_TILE_ID_CIRCLE_MARKING_7 = 51,
  L1_TILE_ID_CIRCLE_MARKING_8 = 52,
  L1_TILE_ID_CIRCLE_MARKING_9 = 53,
  L1_TILE_ID_CIRCLE_MARKING_10 = 54,
  L1_TILE_ID_CIRCLE_MARKING_11 = 55,
  L1_TILE_ID_CIRCLE_MARKING_12 = 56,
  L1_TILE_ID_STAIR_A_1 = 57,
  L1_TILE_ID_STAIR_A_2 = 58,
  L1_TILE_ID_STAIR_A_3 = 59,
  L1_TILE_ID_STAIR_A_4 = 60,
  L1_TILE_ID_STAIR_A_5 = 61,
  L1_TILE_ID_STAIR_A_6 = 62,
  L1_TILE_ID_STAIR_B_1 = 63,
  L1_TILE_ID_STAIR_B_2 = 64,
  L1_TILE_ID_STAIR_B_3 = 65,
  L1_TILE_ID_STAIR_B_4 = 66,
  L1_TILE_ID_STAIR_B_5 = 67,
  L1_TILE_ID_STAIR_B_6 = 68,
  L1_TILE_ID_TOMB_1 = 69,
  L1_TILE_ID_TOMB_2 = 70,
  L1_TILE_ID_TOMB_3 = 71,
  L1_TILE_ID_TOMB_4 = 72,
  L1_TILE_ID_TOMB_5 = 73,
  L1_TILE_ID_TOMB_6 = 74,
  L1_TILE_ID_TOMB_7 = 75,
  L1_TILE_ID_TOMB_8 = 76,
  L1_TILE_ID_TOMB_9 = 77,
  L1_TILE_ID_TOMB_10 = 78,
  L1_TILE_ID_WALL_SW_2 = 79,
  L1_TILE_ID_WALL_SE_2 = 80,
  L1_TILE_ID_WALL_NE_WALL_NW = 81,
  L1_TILE_ID_WALL_SW_WALL_SE_2 = 82,
  L1_TILE_ID_WALL_SW_3 = 83,
  L1_TILE_ID_WALL_END_SW_2 = 84,
  L1_TILE_ID_WALL_END_SE_2 = 85,
  L1_TILE_ID_WALL_END_NE = 86,
  L1_TILE_ID_WALL_END_NW = 87,
  L1_TILE_ID_WALL_SE_3 = 88,
  L1_TILE_ID_TAPESTRY_WALL_SW_1 = 89,
  L1_TILE_ID_TAPESTRY_WALL_SW_2 = 90,
  L1_TILE_ID_TAPESTRY_WALL_SE_1 = 91,
  L1_TILE_ID_TAPESTRY_WALL_SE_2 = 92,
  L1_TILE_ID_WALL_SW_4 = 93,
  L1_TILE_ID_TOMB_WALL_SW = 94,
  L1_TILE_ID_TOMB_WALL_SE = 95,
  L1_TILE_ID_WALL_SE_4 = 96,
  L1_TILE_ID_BLOOD_WALL_SE_1 = 97,
  L1_TILE_ID_BLOOD_WALL_SE_2 = 98,
  L1_TILE_ID_BLOOD_WALL_SE_3 = 99,
  L1_TILE_ID_BLOOD_WALL_SW_1 = 100,
  L1_TILE_ID_BLOOD_WALL_SW_2 = 101,
  L1_TILE_ID_BLOOD_ARCH_SW = 102,
  L1_TILE_ID_BLOOD_DOOR_SW = 103,
  L1_TILE_ID_BLOOD_FLOOR_1 = 104,
  L1_TILE_ID_BLOOD_FLOOR_2 = 105,
  L1_TILE_ID_BLOOD_FLOOR_3 = 106,
  L1_TILE_ID_CROSS_WALL_SW = 107,
  L1_TILE_ID_CROSS_WALL_SE = 108,
  L1_TILE_ID_NICHE_WALL_SW = 109,
  L1_TILE_ID_NICHE_WALL_SE = 110,
  L1_TILE_ID_STATUE_WALL_SW = 111,
  L1_TILE_ID_STATUE_WALL_SE = 112,
  L1_TILE_ID_TORCH_WALL_SW = 113,
  L1_TILE_ID_TORCH_WALL_SE = 114,
  L1_TILE_ID_BROKEN_WALL_SE_1 = 115,
  L1_TILE_ID_BROKEN_WALL_SE_2 = 116,
  L1_TILE_ID_BROKEN_WALL_SE_3 = 117,
  L1_TILE_ID_BROKEN_ARCH_SE = 118,
  L1_TILE_ID_BROKEN_ENTERANCE_SE_1 = 119,
  L1_TILE_ID_BROKEN_ENTERANCE_SE_2 = 120,
  L1_TILE_ID_BROKEN_ARCH_SW_1 = 121,
  L1_TILE_ID_BROKEN_WALL_SW_1 = 122,
  L1_TILE_ID_BROKEN_ARCH_SW_2 = 123,
  L1_TILE_ID_BROKEN_WALL_SW_2 = 124,
  L1_TILE_ID_BROKEN_FLOOR_1 = 125,
  L1_TILE_ID_BROKEN_ENTERANCE_SW_1 = 126,
  L1_TILE_ID_BROKEN_ENTERANCE_SW_2 = 127,
  L1_TILE_ID_CANDLESTICK_1 = 128,
  L1_TILE_ID_CANDLESTICK_2 = 129,
  L1_TILE_ID_CANDLESTICK_3 = 130,
  L1_TILE_ID_SARCOPHAGUS_1 = 131,
  L1_TILE_ID_SARCOPHAGUS_2 = 132,
  L1_TILE_ID_BROKEN_FLOOR_2 = 133,
  L1_TILE_ID_BROKEN_FLOOR_3 = 134,
  L1_TILE_ID_BROKEN_FLOOR_4 = 135,
  L1_TILE_ID_BROKEN_FLOOR_5 = 136,
  L1_TILE_ID_BROKEN_FLOOR_6 = 137,
  L1_TILE_ID_BROKEN_FLOOR_7 = 138,
  L1_TILE_ID_FLOOR_SHADOW_ARCH_SW_RIGHT = 139,
  L1_TILE_ID_FLOOR_SHADOW_ARCH_SE_LEFT = 140,
  L1_TILE_ID_FLOOR_SHADOW_BAR_SW_RIGHT = 141,
  L1_TILE_ID_FLOOR_SHADOW_SHAFT_RIGHT = 142,
  L1_TILE_ID_FLOOR_SHADOW_ARCH_SE_LEFT_SHAFT_BOTTOM = 143,
  L1_TILE_ID_FLOOR_SHADOW_SHAFT_BOTTOM_1 = 144,
  L1_TILE_ID_FLOOR_SHADOW_COLUMN_BOTTOM = 145,
  L1_TILE_ID_WALL_SW_SHADOW_ARCH_SE_LEFT = 146,
  L1_TILE_ID_ARCH_SW_SHADOW_ARCH_SE_LEFT = 147,
  L1_TILE_ID_WALL_SE_SHADOW_ARCH_SW_RIGHT = 148,
  L1_TILE_ID_ARCH_SE_SHADOW_ARCH_SW_RIGHT = 149,
  L1_TILE_ID_FLOOR_SHADOW_ARCH_SE_LEFT_ARCH_SW_RIGHT = 150,
  L1_TILE_ID_FLOOR_SHADOW_SHAFT_BOTTOM_ARCH_SW_RIGHT = 151,
  L1_TILE_ID_FLOOR_SHADOW_SHAFT_BOTTOM_2 = 152,
  L1_TILE_ID_ARCH_SE_SHADOW_BAR_SW_RIGHT = 153,
  L1_TILE_ID_WALL_SE_SHADOW_BAR_SW_RIGHT = 154,
  L1_TILE_ID_WALL_SW_3_SHADOW_ARCH_SE_LEFT = 155,
  L1_TILE_ID_WALL_SE_3_SHADOW_ARCH_SW_RIGHT = 156,
  L1_TILE_ID_WALL_SE_3_SHADOW_BAR_SW_RIGHT = 157,
  L1_TILE_ID_WALL_SW_WALL_SE_3 = 158,
  L1_TILE_ID_ARCH_SW_WALL_SE_3 = 159,
  L1_TILE_ID_WALL_SW_3_WALL_SE = 160,
  L1_TILE_ID_WALL_SW_3_ARCH_SE = 161,
  L1_TILE_ID_FLOOR_2 = 162,
  L1_TILE_ID_FLOOR_3 = 163,
  L1_TILE_ID_DOOR_SW_WALL_SE_3 = 164,
  L1_TILE_ID_WALL_SW_3_DOOR_SE = 165,
  L1_TILE_ID_BLOOD_WALL_SW_3 = 166,
  L1_TILE_ID_BLOOD_WALL_SW_4 = 167,
  L1_TILE_ID_BLOOD_WALL_SW_WALL_SE = 168,
  L1_TILE_ID_BLOOD_WALL_SE_4 = 169,
  L1_TILE_ID_BLOOD_WALL_SE_5 = 170,
  L1_TILE_ID_BLOOD_FLOOR_4 = 171,
  L1_TILE_ID_BLOOD_FLOOR_5 = 172,
  L1_TILE_ID_BLOOD_FLOOR_6 = 173,
  L1_TILE_ID_BLOOD_FLOOR_7 = 174,
  L1_TILE_ID_OPEN_DOOR_SW = 175,
  L1_TILE_ID_OPEN_DOOR_SE = 176,
  L1_TILE_ID_OPEN_DOOR_SW_OPEN_DOOR_SE = 177,
  L1_TILE_ID_OPEN_DOOR_END_SW = 178,
  L1_TILE_ID_OPEN_DOOR_END_SE = 179,
  L1_TILE_ID_OPEN_DOOR_SW_BAR_SE = 180,
  L1_TILE_ID_BAR_SW_OPEN_DOOR_SE = 181,
  L1_TILE_ID_OPEN_DOOR_SW_ARCH_SE = 182,
  L1_TILE_ID_OPEN_DOOR_SW_WALL_SE = 183,
  L1_TILE_ID_ARCH_SW_OPEN_DOOR_SE = 184,
  L1_TILE_ID_WALL_SW_OPEN_DOOR_SE = 185,
  L1_TILE_ID_OPEN_BLOOD_DOOR_SW = 186,
  L1_TILE_ID_OPEN_DOOR_SW_WALL_SE_3 = 187,
  L1_TILE_ID_WALL_SW_3_OPEN_DOOR_SE = 188,
  L1_TILE_ID_OPEN_DOOR_SW_DOOR_SE = 189,
  L1_TILE_ID_DOOR_SW_OPEN_DOOR_SE = 190,
  L1_TILE_ID_WALL_SW_5 = 191,
  L1_TILE_ID_WALL_SE_5 = 192,
  L1_TILE_ID_ENTERANCE_SW_1 = 193,
  L1_TILE_ID_ENTERANCE_SE_1 = 194,
  L1_TILE_ID_DIRT_FLOOR_SHADOW = 195,
  L1_TILE_ID_DIRT_FLOOR_SHADOW_ARCH_SW_RIGHT = 196,
  L1_TILE_ID_ENTERANCE_SW_2 = 197,
  L1_TILE_ID_ENTERANCE_SE_2 = 198,
  L1_TILE_ID_DIRT_WALL_SW_DIRT = 199,
  L1_TILE_ID_DIRT_WALL_SE_DIRT = 200,
  L1_TILE_ID_DIRT_WALL_NE_WALL_NW_DIRT = 201,
  L1_TILE_ID_DIRT_WALL_SW_WALL_SE_DIRT = 202,
  L1_TILE_ID_DIRT_DIRT = 203,
  L1_TILE_ID_DIRT_WALL_END_SW_DIRT = 204,
  L1_TILE_ID_DIRT_WALL_END_SE_DIRT = 205,
  L1_TILE_ID_BROKEN_ENTERANCE_SE_3 = 206,
};

typedef enum l1_tile_id l1_tile_id;


/* 482 */
enum dflag
{
  DFLAG_01 = 0x1,
  DFLAG_02 = 0x2,
  DFLAG_04 = 0x4,
  DFLAG_08 = 0x8,
  DFLAG_MONSTER_LR = 0x10,
  DFLAG_20 = 0x20,
  DFLAG_40 = 0x40,
  DFLAG_80 = 0x80,
};

typedef enum dflag dflag;


/* 483 */
enum MACRO_WS2
{
  WS_POPUP = 0x80000000,
  WS_CHILD = 0x40000000,
  WS_MINIMIZE = 0x20000000,
  WS_VISIBLE = 0x10000000,
  WS_DISABLED = 0x8000000,
  WS_CLIPSIBLINGS = 0x4000000,
  WS_CLIPCHILDREN = 0x2000000,
  WS_MAXIMIZE = 0x1000000,
  WS_CAPTION = 0xC00000,
  WS_BORDER = 0x800000,
  WS_DLGFRAME = 0x400000,
  WS_VSCROLL = 0x200000,
  WS_HSCROLL = 0x100000,
  WS_SYSMENU = 0x80000,
  WS_THICKFRAME = 0x40000,
  WS_GROUP = 0x20000,
  WS_TABSTOP = 0x10000,
  WS_MINIMIZEBOX = 0x20000,
  WS_MAXIMIZEBOX = 0x10000,
  WS_TILED = 0x0,
  WS_ICONIC = 0x20000000,
  WS_SIZEBOX = 0x40000,
  WS_OVERLAPPEDWINDOW = 0xCF0000,
  WS_POPUPWINDOW = 0x80880000,
  WS_CHILDWINDOW = 0x40000000,
  WS_EX_DLGMODALFRAME = 0x1,
};

typedef enum MACRO_WS2 MACRO_WS2;


/* 485 */
enum DBCOMMANDOPENUM
{
  DBOP_scalar_constant = 0x0,
  DBOP_DEFAULT = 0x1,
  DBOP_NULL = 0x2,
  DBOP_bookmark_name = 0x3,
  DBOP_catalog_name = 0x4,
  DBOP_column_name = 0x5,
  DBOP_schema_name = 0x6,
  DBOP_outall_name = 0x7,
  DBOP_qualifier_name = 0x8,
  DBOP_qualified_column_name = 0x9,
  DBOP_table_name = 0xA,
  DBOP_nested_table_name = 0xB,
  DBOP_nested_column_name = 0xC,
  DBOP_row = 0xD,
  DBOP_table = 0xE,
  DBOP_sort = 0xF,
  DBOP_distinct = 0x10,
  DBOP_distinct_order_preserving = 0x11,
  DBOP_alias = 0x12,
  DBOP_cross_join = 0x13,
  DBOP_union_join = 0x14,
  DBOP_inner_join = 0x15,
  DBOP_left_semi_join = 0x16,
  DBOP_right_semi_join = 0x17,
  DBOP_left_anti_semi_join = 0x18,
  DBOP_right_anti_semi_join = 0x19,
  DBOP_left_outer_join = 0x1A,
  DBOP_right_outer_join = 0x1B,
  DBOP_full_outer_join = 0x1C,
  DBOP_natural_join = 0x1D,
  DBOP_natural_left_outer_join = 0x1E,
  DBOP_natural_right_outer_join = 0x1F,
  DBOP_natural_full_outer_join = 0x20,
  DBOP_set_intersection = 0x21,
  DBOP_set_union = 0x22,
  DBOP_set_left_difference = 0x23,
  DBOP_set_right_difference = 0x24,
  DBOP_set_anti_difference = 0x25,
  DBOP_bag_intersection = 0x26,
  DBOP_bag_union = 0x27,
  DBOP_bag_left_difference = 0x28,
  DBOP_bag_right_difference = 0x29,
  DBOP_bag_anti_difference = 0x2A,
  DBOP_division = 0x2B,
  DBOP_relative_sampling = 0x2C,
  DBOP_absolute_sampling = 0x2D,
  DBOP_transitive_closure = 0x2E,
  DBOP_recursive_union = 0x2F,
  DBOP_aggregate = 0x30,
  DBOP_remote_table = 0x31,
  DBOP_select = 0x32,
  DBOP_order_preserving_select = 0x33,
  DBOP_project = 0x34,
  DBOP_project_order_preserving = 0x35,
  DBOP_top = 0x36,
  DBOP_top_percent = 0x37,
  DBOP_top_plus_ties = 0x38,
  DBOP_top_percent_plus_ties = 0x39,
  DBOP_rank = 0x3A,
  DBOP_rank_ties_equally = 0x3B,
  DBOP_rank_ties_equally_and_skip = 0x3C,
  DBOP_navigate = 0x3D,
  DBOP_nesting = 0x3E,
  DBOP_unnesting = 0x3F,
  DBOP_nested_apply = 0x40,
  DBOP_cross_tab = 0x41,
  DBOP_is_NULL = 0x42,
  DBOP_is_NOT_NULL = 0x43,
  DBOP_equal = 0x44,
  DBOP_not_equal = 0x45,
  DBOP_less = 0x46,
  DBOP_less_equal = 0x47,
  DBOP_greater = 0x48,
  DBOP_greater_equal = 0x49,
  DBOP_equal_all = 0x4A,
  DBOP_not_equal_all = 0x4B,
  DBOP_less_all = 0x4C,
  DBOP_less_equal_all = 0x4D,
  DBOP_greater_all = 0x4E,
  DBOP_greater_equal_all = 0x4F,
  DBOP_equal_any = 0x50,
  DBOP_not_equal_any = 0x51,
  DBOP_less_any = 0x52,
  DBOP_less_equal_any = 0x53,
  DBOP_greater_any = 0x54,
  DBOP_greater_equal_any = 0x55,
  DBOP_anybits = 0x56,
  DBOP_allbits = 0x57,
  DBOP_anybits_any = 0x58,
  DBOP_allbits_any = 0x59,
  DBOP_anybits_all = 0x5A,
  DBOP_allbits_all = 0x5B,
  DBOP_between = 0x5C,
  DBOP_between_unordered = 0x5D,
  DBOP_match = 0x5E,
  DBOP_match_unique = 0x5F,
  DBOP_match_partial = 0x60,
  DBOP_match_partial_unique = 0x61,
  DBOP_match_full = 0x62,
  DBOP_match_full_unique = 0x63,
  DBOP_scalar_parameter = 0x64,
  DBOP_scalar_function = 0x65,
  DBOP_plus = 0x66,
  DBOP_minus = 0x67,
  DBOP_times = 0x68,
  DBOP_over = 0x69,
  DBOP_div = 0x6A,
  DBOP_modulo = 0x6B,
  DBOP_power = 0x6C,
  DBOP_like = 0x6D,
  DBOP_sounds_like = 0x6E,
  DBOP_like_any = 0x6F,
  DBOP_like_all = 0x70,
  DBOP_is_INVALID = 0x71,
  DBOP_is_TRUE = 0x72,
  DBOP_is_FALSE = 0x73,
  DBOP_and = 0x74,
  DBOP_or = 0x75,
  DBOP_xor = 0x76,
  DBOP_equivalent = 0x77,
  DBOP_not = 0x78,
  DBOP_implies = 0x79,
  DBOP_overlaps = 0x7A,
  DBOP_case_condition = 0x7B,
  DBOP_case_value = 0x7C,
  DBOP_nullif = 0x7D,
  DBOP_cast = 0x7E,
  DBOP_coalesce = 0x7F,
  DBOP_position = 0x80,
  DBOP_extract = 0x81,
  DBOP_char_length = 0x82,
  DBOP_octet_length = 0x83,
  DBOP_bit_length = 0x84,
  DBOP_substring = 0x85,
  DBOP_upper = 0x86,
  DBOP_lower = 0x87,
  DBOP_trim = 0x88,
  DBOP_translate = 0x89,
  DBOP_convert = 0x8A,
  DBOP_string_concat = 0x8B,
  DBOP_current_date = 0x8C,
  DBOP_current_time = 0x8D,
  DBOP_current_timestamp = 0x8E,
  DBOP_content_select = 0x8F,
  DBOP_content = 0x90,
  DBOP_content_freetext = 0x91,
  DBOP_content_proximity = 0x92,
  DBOP_content_vector_or = 0x93,
  DBOP_delete = 0x94,
  DBOP_update = 0x95,
  DBOP_insert = 0x96,
  DBOP_min = 0x97,
  DBOP_max = 0x98,
  DBOP_count = 0x99,
  DBOP_sum = 0x9A,
  DBOP_avg = 0x9B,
  DBOP_any_sample = 0x9C,
  DBOP_stddev = 0x9D,
  DBOP_stddev_pop = 0x9E,
  DBOP_var = 0x9F,
  DBOP_var_pop = 0xA0,
  DBOP_first = 0xA1,
  DBOP_last = 0xA2,
  DBOP_in = 0xA3,
  DBOP_exists = 0xA4,
  DBOP_unique = 0xA5,
  DBOP_subset = 0xA6,
  DBOP_proper_subset = 0xA7,
  DBOP_superset = 0xA8,
  DBOP_proper_superset = 0xA9,
  DBOP_disjoint = 0xAA,
  DBOP_pass_through = 0xAB,
  DBOP_defined_by_GUID = 0xAC,
  DBOP_text_command = 0xAD,
  DBOP_SQL_select = 0xAE,
  DBOP_prior_command_tree = 0xAF,
  DBOP_add_columns = 0xB0,
  DBOP_column_list_anchor = 0xB1,
  DBOP_column_list_element = 0xB2,
  DBOP_command_list_anchor = 0xB3,
  DBOP_command_list_element = 0xB4,
  DBOP_from_list_anchor = 0xB5,
  DBOP_from_list_element = 0xB6,
  DBOP_project_list_anchor = 0xB7,
  DBOP_project_list_element = 0xB8,
  DBOP_row_list_anchor = 0xB9,
  DBOP_row_list_element = 0xBA,
  DBOP_scalar_list_anchor = 0xBB,
  DBOP_scalar_list_element = 0xBC,
  DBOP_set_list_anchor = 0xBD,
  DBOP_set_list_element = 0xBE,
  DBOP_sort_list_anchor = 0xBF,
  DBOP_sort_list_element = 0xC0,
  DBOP_alter_character_set = 0xC1,
  DBOP_alter_collation = 0xC2,
  DBOP_alter_domain = 0xC3,
  DBOP_alter_index = 0xC4,
  DBOP_alter_procedure = 0xC5,
  DBOP_alter_schema = 0xC6,
  DBOP_alter_table = 0xC7,
  DBOP_alter_trigger = 0xC8,
  DBOP_alter_view = 0xC9,
  DBOP_coldef_list_anchor = 0xCA,
  DBOP_coldef_list_element = 0xCB,
  DBOP_create_assertion = 0xCC,
  DBOP_create_character_set = 0xCD,
  DBOP_create_collation = 0xCE,
  DBOP_create_domain = 0xCF,
  DBOP_create_index = 0xD0,
  DBOP_create_procedure = 0xD1,
  DBOP_create_schema = 0xD2,
  DBOP_create_synonym = 0xD3,
  DBOP_create_table = 0xD4,
  DBOP_create_temporary_table = 0xD5,
  DBOP_create_translation = 0xD6,
  DBOP_create_trigger = 0xD7,
  DBOP_create_view = 0xD8,
  DBOP_drop_assertion = 0xD9,
  DBOP_drop_character_set = 0xDA,
  DBOP_drop_collation = 0xDB,
  DBOP_drop_domain = 0xDC,
  DBOP_drop_index = 0xDD,
  DBOP_drop_procedure = 0xDE,
  DBOP_drop_schema = 0xDF,
  DBOP_drop_synonym = 0xE0,
  DBOP_drop_table = 0xE1,
  DBOP_drop_translation = 0xE2,
  DBOP_drop_trigger = 0xE3,
  DBOP_drop_view = 0xE4,
  DBOP_foreign_key = 0xE5,
  DBOP_grant_privileges = 0xE6,
  DBOP_index_list_anchor = 0xE7,
  DBOP_index_list_element = 0xE8,
  DBOP_primary_key = 0xE9,
  DBOP_property_list_anchor = 0xEA,
  DBOP_property_list_element = 0xEB,
  DBOP_referenced_table = 0xEC,
  DBOP_rename_object = 0xED,
  DBOP_revoke_privileges = 0xEE,
  DBOP_schema_authorization = 0xEF,
  DBOP_unique_key = 0xF0,
  DBOP_scope_list_anchor = 0xF1,
  DBOP_scope_list_element = 0xF2,
  DBOP_content_table = 0xF3,
};

typedef enum DBCOMMANDOPENUM DBCOMMANDOPENUM;


/* 486 */
enum D3D10_FILTER
{
  D3D10_FILTER_MIN_MAG_MIP_POINT = 0x0,
  D3D10_FILTER_MIN_MAG_POINT_MIP_LINEAR = 0x1,
  D3D10_FILTER_MIN_POINT_MAG_LINEAR_MIP_POINT = 0x4,
  D3D10_FILTER_MIN_POINT_MAG_MIP_LINEAR = 0x5,
  D3D10_FILTER_MIN_LINEAR_MAG_MIP_POINT = 0x10,
  D3D10_FILTER_MIN_LINEAR_MAG_POINT_MIP_LINEAR = 0x11,
  D3D10_FILTER_MIN_MAG_LINEAR_MIP_POINT = 0x14,
  D3D10_FILTER_MIN_MAG_MIP_LINEAR = 0x15,
  D3D10_FILTER_ANISOTROPIC = 0x55,
  D3D10_FILTER_COMPARISON_MIN_MAG_MIP_POINT = 0x80,
  D3D10_FILTER_COMPARISON_MIN_MAG_POINT_MIP_LINEAR = 0x81,
  D3D10_FILTER_COMPARISON_MIN_POINT_MAG_LINEAR_MIP_POINT = 0x84,
  D3D10_FILTER_COMPARISON_MIN_POINT_MAG_MIP_LINEAR = 0x85,
  D3D10_FILTER_COMPARISON_MIN_LINEAR_MAG_MIP_POINT = 0x90,
  D3D10_FILTER_COMPARISON_MIN_LINEAR_MAG_POINT_MIP_LINEAR = 0x91,
  D3D10_FILTER_COMPARISON_MIN_MAG_LINEAR_MIP_POINT = 0x94,
  D3D10_FILTER_COMPARISON_MIN_MAG_MIP_LINEAR = 0x95,
  D3D10_FILTER_COMPARISON_ANISOTROPIC = 0xD5,
  D3D10_FILTER_TEXT_1BIT = 0x80000000,
};

typedef enum D3D10_FILTER D3D10_FILTER;


/* 487 */
enum _D3DRENDERSTATETYPE
{
  D3DRS_ZENABLE = 0x7,
  D3DRS_FILLMODE = 0x8,
  D3DRS_SHADEMODE = 0x9,
  D3DRS_ZWRITEENABLE = 0xE,
  D3DRS_ALPHATESTENABLE = 0xF,
  D3DRS_LASTPIXEL = 0x10,
  D3DRS_SRCBLEND = 0x13,
  D3DRS_DESTBLEND = 0x14,
  D3DRS_CULLMODE = 0x16,
  D3DRS_ZFUNC = 0x17,
  D3DRS_ALPHAREF = 0x18,
  D3DRS_ALPHAFUNC = 0x19,
  D3DRS_DITHERENABLE = 0x1A,
  D3DRS_ALPHABLENDENABLE = 0x1B,
  D3DRS_FOGENABLE = 0x1C,
  D3DRS_SPECULARENABLE = 0x1D,
  D3DRS_FOGCOLOR = 0x22,
  D3DRS_FOGTABLEMODE = 0x23,
  D3DRS_FOGSTART = 0x24,
  D3DRS_FOGEND = 0x25,
  D3DRS_FOGDENSITY = 0x26,
  D3DRS_RANGEFOGENABLE = 0x30,
  D3DRS_STENCILENABLE = 0x34,
  D3DRS_STENCILFAIL = 0x35,
  D3DRS_STENCILZFAIL = 0x36,
  D3DRS_STENCILPASS = 0x37,
  D3DRS_STENCILFUNC = 0x38,
  D3DRS_STENCILREF = 0x39,
  D3DRS_STENCILMASK = 0x3A,
  D3DRS_STENCILWRITEMASK = 0x3B,
  D3DRS_TEXTUREFACTOR = 0x3C,
  D3DRS_WRAP0 = 0x80,
  D3DRS_WRAP1 = 0x81,
  D3DRS_WRAP2 = 0x82,
  D3DRS_WRAP3 = 0x83,
  D3DRS_WRAP4 = 0x84,
  D3DRS_WRAP5 = 0x85,
  D3DRS_WRAP6 = 0x86,
  D3DRS_WRAP7 = 0x87,
  D3DRS_CLIPPING = 0x88,
  D3DRS_LIGHTING = 0x89,
  D3DRS_AMBIENT = 0x8B,
  D3DRS_FOGVERTEXMODE = 0x8C,
  D3DRS_COLORVERTEX = 0x8D,
  D3DRS_LOCALVIEWER = 0x8E,
  D3DRS_NORMALIZENORMALS = 0x8F,
  D3DRS_DIFFUSEMATERIALSOURCE = 0x91,
  D3DRS_SPECULARMATERIALSOURCE = 0x92,
  D3DRS_AMBIENTMATERIALSOURCE = 0x93,
  D3DRS_EMISSIVEMATERIALSOURCE = 0x94,
  D3DRS_VERTEXBLEND = 0x97,
  D3DRS_CLIPPLANEENABLE = 0x98,
  D3DRS_POINTSIZE = 0x9A,
  D3DRS_POINTSIZE_MIN = 0x9B,
  D3DRS_POINTSPRITEENABLE = 0x9C,
  D3DRS_POINTSCALEENABLE = 0x9D,
  D3DRS_POINTSCALE_A = 0x9E,
  D3DRS_POINTSCALE_B = 0x9F,
  D3DRS_POINTSCALE_C = 0xA0,
  D3DRS_MULTISAMPLEANTIALIAS = 0xA1,
  D3DRS_MULTISAMPLEMASK = 0xA2,
  D3DRS_PATCHEDGESTYLE = 0xA3,
  D3DRS_DEBUGMONITORTOKEN = 0xA5,
  D3DRS_POINTSIZE_MAX = 0xA6,
  D3DRS_INDEXEDVERTEXBLENDENABLE = 0xA7,
  D3DRS_COLORWRITEENABLE = 0xA8,
  D3DRS_TWEENFACTOR = 0xAA,
  D3DRS_BLENDOP = 0xAB,
  D3DRS_POSITIONDEGREE = 0xAC,
  D3DRS_NORMALDEGREE = 0xAD,
  D3DRS_SCISSORTESTENABLE = 0xAE,
  D3DRS_SLOPESCALEDEPTHBIAS = 0xAF,
  D3DRS_ANTIALIASEDLINEENABLE = 0xB0,
  D3DRS_MINTESSELLATIONLEVEL = 0xB2,
  D3DRS_MAXTESSELLATIONLEVEL = 0xB3,
  D3DRS_ADAPTIVETESS_X = 0xB4,
  D3DRS_ADAPTIVETESS_Y = 0xB5,
  D3DRS_ADAPTIVETESS_Z = 0xB6,
  D3DRS_ADAPTIVETESS_W = 0xB7,
  D3DRS_ENABLEADAPTIVETESSELLATION = 0xB8,
  D3DRS_TWOSIDEDSTENCILMODE = 0xB9,
  D3DRS_CCW_STENCILFAIL = 0xBA,
  D3DRS_CCW_STENCILZFAIL = 0xBB,
  D3DRS_CCW_STENCILPASS = 0xBC,
  D3DRS_CCW_STENCILFUNC = 0xBD,
  D3DRS_COLORWRITEENABLE1 = 0xBE,
  D3DRS_COLORWRITEENABLE2 = 0xBF,
  D3DRS_COLORWRITEENABLE3 = 0xC0,
  D3DRS_BLENDFACTOR = 0xC1,
  D3DRS_SRGBWRITEENABLE = 0xC2,
  D3DRS_DEPTHBIAS = 0xC3,
  D3DRS_WRAP8 = 0xC6,
  D3DRS_WRAP9 = 0xC7,
  D3DRS_WRAP10 = 0xC8,
  D3DRS_WRAP11 = 0xC9,
  D3DRS_WRAP12 = 0xCA,
  D3DRS_WRAP13 = 0xCB,
  D3DRS_WRAP14 = 0xCC,
  D3DRS_WRAP15 = 0xCD,
  D3DRS_SEPARATEALPHABLENDENABLE = 0xCE,
  D3DRS_SRCBLENDALPHA = 0xCF,
  D3DRS_DESTBLENDALPHA = 0xD0,
  D3DRS_BLENDOPALPHA = 0xD1,
  D3DRS_FORCE_DWORD = 0x7FFFFFFF,
};

typedef enum _D3DRENDERSTATETYPE _D3DRENDERSTATETYPE;


/* 490 */
typedef GUID IID;

/* 489 */
struct IDirectDrawPaletteVtbl
{
  HRESULT (__stdcall *QueryInterface)(IDirectDrawPalette *This, const IID *const riid, LPVOID *ppvObj);
  ULONG (__stdcall *AddRef)(IDirectDrawPalette *This);
  ULONG (__stdcall *Release)(IDirectDrawPalette *This);
  HRESULT (__stdcall *GetCaps)(IDirectDrawPalette *This, LPDWORD);
  HRESULT (__stdcall *GetEntries)(IDirectDrawPalette *This, DWORD, DWORD, DWORD, LPPALETTEENTRY);
  HRESULT (__stdcall *Initialize)(IDirectDrawPalette *This, LPDIRECTDRAW, DWORD, LPPALETTEENTRY);
  HRESULT (__stdcall *SetEntries)(IDirectDrawPalette *This, DWORD, DWORD, DWORD, LPPALETTEENTRY);
};

typedef struct IDirectDrawPaletteVtbl IDirectDrawPaletteVtbl;


typedef int LCTYPE;
typedef PALETTEENTRY * HPALETTE;
typedef _SECURITY_ATTRIBUTES * LPSECURITY_ATTRIBUTES;
typedef ULONG * ULONG_PTR;
typedef int errno_t;
typedef char * PCNZCH;
typedef int LSTATUS;
typedef int HGDIOBJ;
typedef char * PCNZWCH;
typedef void * LPCPINFO;
typedef char * LPWCH;
typedef char * LPCH;
typedef int HKEY;
typedef HKEY * PHKEY;
typedef int * LPOVERLAPPED;
typedef void * LPSYSTEMTIME;
typedef _STARTUPINFOA * LPSTARTUPINFOA;
typedef _PROCESS_INFORMATION * LPPROCESS_INFORMATION;
typedef _SYSTEM_INFO * LPSYSTEM_INFO;
typedef CRITICAL_SECTION * LPCRITICAL_SECTION;
typedef _MEMORY_BASIC_INFORMATION * PMEMORY_BASIC_INFORMATION;
typedef _OFSTRUCT * LPOFSTRUCT;
typedef _OSVERSIONINFOA * LPOSVERSIONINFOA;
typedef _WIN32_FIND_DATAA * LPWIN32_FIND_DATAA;
typedef _TIME_ZONE_INFORMATION * LPTIME_ZONE_INFORMATION;
typedef MSG * LPMSG;
typedef INT * INT_PTR;
typedef LONG * PLONG;
typedef int HFILE;
typedef int REGSAM;
typedef void * DLGPROC;
typedef int HMENU;
typedef void * LPFILETIME;
typedef void * LPTHREAD_START_ROUTINE;
typedef void * LPITEMIDLIST;
typedef void * LPCITEMIDLIST;
typedef int ATOM;
typedef void * LPTOP_LEVEL_EXCEPTION_FILTER;
typedef int(*FARPROC)(void);
