/*
 * xfreq-gui.h by CyrIng
 *
 * Copyright (C) 2013-2015 CYRIL INGENIERIE
 * Licenses: GPL2
 */


#if defined(FreeBSD)
// Posix fix.
#define	pthread_setname_np pthread_set_name_np
#define	pthread_tryjoin_np(t, r) pthread_timedjoin_np(t, r, 0)
#endif

#define	LOW_TEMP_VALUE		35
#define MED_TEMP_VALUE		45
#define	HIGH_TEMP_VALUE		65

enum {
	BACKGROUND_MAIN,
	FOREGROUND_MAIN,
	BACKGROUND_CORES,
	FOREGROUND_CORES,
	BACKGROUND_CSTATES,
	FOREGROUND_CSTATES,
	BACKGROUND_TEMPS,
	FOREGROUND_TEMPS,
	BACKGROUND_SYSINFO,
	FOREGROUND_SYSINFO,
	BACKGROUND_DUMP,
	FOREGROUND_DUMP,
	COLOR_AXES,
	COLOR_LABEL,
	COLOR_PRINT,
	COLOR_PROMPT,
	COLOR_CURSOR,
	COLOR_DYNAMIC,
	COLOR_GRAPH1,
	COLOR_GRAPH2,
	COLOR_GRAPH3,
	COLOR_INIT_VALUE,
	COLOR_LOW_VALUE,
	COLOR_MED_VALUE,
	COLOR_HIGH_VALUE,
	COLOR_PULSE,
	COLOR_FOCUS,
	COLOR_MDI_SEP,
	COLOR_COUNT
};

#define	_BACKGROUND_GLOBAL	0x11114c
#define	_FOREGROUND_GLOBAL	0x8fcefa
#define	_BACKGROUND_SPLASH	0x000000
#define	_FOREGROUND_SPLASH	0x8fcefa

#define	_BACKGROUND_MAIN	0x11114c
#define	_FOREGROUND_MAIN	0x8fcefa
#define	_BACKGROUND_CORES	0x191970
#define	_FOREGROUND_CORES	0x8fcefa
#define	_BACKGROUND_CSTATES	0x191970
#define	_FOREGROUND_CSTATES	0x8fcefa
#define	_BACKGROUND_TEMPS	0x191970
#define	_FOREGROUND_TEMPS	0x8fcefa
#define	_BACKGROUND_SYSINFO	0x191970
#define	_FOREGROUND_SYSINFO	0x8fcefa
#define	_BACKGROUND_DUMP	0x191970
#define	_FOREGROUND_DUMP	0x8fcefa

#define	_COLOR_AXES		0x404040
#define	_COLOR_LABEL		0xc0c0c0
#define	_COLOR_PRINT		0xf0f0f0
#define	_COLOR_PROMPT		0xffff00
#define	_COLOR_CURSOR		0xfd0000
#define	_COLOR_DYNAMIC		0xdddddd
#define	_COLOR_GRAPH1		0xadadff
#define	_COLOR_GRAPH2		0x50508a
#define	_COLOR_GRAPH3		0x515172
#define	_COLOR_INIT_VALUE	0x6666b0
#define	_COLOR_LOW_VALUE	0x00aa66
#define	_COLOR_MED_VALUE	0xe49400
#define	_COLOR_HIGH_VALUE	0xfd0000
#define	_COLOR_PULSE		0xf0f000
#define	_COLOR_FOCUS		0xffffff
#define	_COLOR_MDI_SEP		0x737373

typedef	struct
{
	unsigned long int	RGB;
	char			*xrmClass,
				*xrmKey;
} COLORS;

enum	{MC_DEFAULT, MC_MOVE, MC_WAIT, MC_COUNT};

#define	ID_MIN		'm'
#define	ID_SAVE		'.'
#define	ID_NORTH	'N'
#define	ID_SOUTH	'S'
#define	ID_EAST		'E'
#define	ID_WEST		'W'
#define	ID_PGUP		'U'
#define	ID_PGDW		'D'
#define	ID_PGHOME	'['
#define	ID_PGEND	']'
#define	ID_CTRLHOME	'{'
#define	ID_CTRLEND	'}'
#define	ID_PAUSE	'I'
#define	ID_STOP		'&'
#define	ID_RESUME	'!'
#define	ID_CHART	'c'
#define	ID_FREQ		'z'
#define	ID_CYCLE	'Y'
#define	ID_RATIO	'R'
#define	ID_SCHED	'T'
#define	ID_CSTATE	'P'
#define	ID_TEMP		't'
#define	ID_WALLBOARD	'B'

#define	RSC_PAUSE	"Pause"
#define	RSC_RESET	"Reset"
#define	RSC_FREQ	"Freq"
#define	RSC_CYCLE	"Cycle"
#define	RSC_CSTATE	"States"
#define	RSC_RATIO	"Ratio"
#define	RSC_SCHED	"Task"
#define	RSC_TSC		"TSC"
#define	RSC_BIOS	"BIOS"
#define	RSC_SPEC	"SPEC"
#define	RSC_ROM		"ROM"
#define	RSC_INCLOOP	"<<"
#define	RSC_DECLOOP	">>"
#define	RSC_WALLBOARD	"Brand"

#define	ICON_LABELS	{{.Label='M'}, {.Label='C'}, {.Label='S'}, {.Label='T'}, {.Label='I'}, {.Label='D'}}

typedef	enum	{DECORATION, SCROLLING, TEXT, ICON} WBTYPE;

typedef	union
{
	char		*Text;
	char		Label;
} RESOURCE;

typedef	struct
{
	Bool32		(*Func)();
	Bool32		*Key;
} WBSTATE;

struct WButton
{
	WBTYPE		Type;
	int		Target;
	int		x,
			y;
	unsigned int	w,
			h;
	void		(*CallBack)();
	void		(*DrawFunc)();
	RESOURCE	Resource;
	WBSTATE		WBState;

	struct	WButton	*Chain;
	char		ID;
};

typedef	struct	WButton	WBUTTON;

enum	{HEAD, TAIL, CHAINS};

#define	WBUTTON_PULSE_US	75000

typedef struct
{
	Window		window;
	struct {
		Pixmap	B,
			F,
			I;
	} pixmap;
	GC		gc;
	int		x,
			y,
			width,
			height,
			border_width;
	struct
	{
	    XCharStruct	overall;
		int	dir,
			ascent,
			descent,
			charWidth,
			charHeight;
	} extents;
	unsigned long	background,
			foreground;
	WBUTTON		*wButton[CHAINS];
} XWINDOW;

typedef struct
{
	Window		window;
	GC		gc;
	Pixmap		bitmap,
			icon;
	int		x, y,
			w, h;
	short int	attributes;
} XSPLASH;

//			L-CTRL		L-ALT		R-CTRL		L-WIN		R-ALTGR
#define	AllModMask	(ControlMask	| Mod1Mask	| Mod3Mask	| Mod4Mask	| Mod5Mask)
#define	BASE_EVENTS	(KeyPressMask | ExposureMask | VisibilityChangeMask | StructureNotifyMask | FocusChangeMask)
#define	MOVE_EVENTS	(ButtonReleaseMask | Button3MotionMask)
#define	CLICK_EVENTS	ButtonPressMask

typedef struct
{
	Bool32		Locked;
	int		S,
			dx,
			dy;
} XTARGET;

#define	DEFAULT_FONT_ASCENT		11
#define	DEFAULT_FONT_DESCENT		2
#define	DEFAULT_FONT_CHAR_WIDTH		6
#define	DEFAULT_FONT_CHAR_HEIGHT	(DEFAULT_FONT_ASCENT + DEFAULT_FONT_DESCENT)
#define	DEFAULT_HEADER_STR		".1.2.3.4.5.6.7.8.9.0.1.2.3.4.5.6.7.8.9.0.1.2.3.4.5.6.7.8.9.0.1.2.3.4.5.6.7.8.9.0.1.2.3.4.5.6.7.8.9.0.1.2.3.4.5.6.7.8.9.0"

typedef enum {MAIN, CORES, CSTATES, TEMPS, SYSINFO, DUMP, WIDGETS} LAYOUTS;

#define	FIRST_WIDGET	(MAIN + 1)
#define	LAST_WIDGET	(WIDGETS - 1)

#define	Quarter_Char_Width(N)		(A->W[N].extents.charWidth >> 2)
#define	Half_Char_Width(N)		(A->W[N].extents.charWidth >> 1)
#define	One_Char_Width(N)		(A->W[N].extents.charWidth)
#define	One_Half_Char_Width(N)		(One_Char_Width(N) + Half_Char_Width(N))
#define	Twice_Char_Width(N)		(A->W[N].extents.charWidth << 1)
#define	Twice_Half_Char_Width(N)	(Twice_Char_Width(N) + Half_Char_Width(N))

#define	Quarter_Char_Height(N)		(A->W[N].extents.charHeight >> 2)
#define	Half_Char_Height(N)		(A->W[N].extents.charHeight >> 1)
#define	One_Char_Height(N)		(A->W[N].extents.charHeight)
#define	One_Half_Char_Height(N)		(One_Char_Height(N) + Half_Char_Height(N))
#define	Twice_Char_Height(N)		(A->W[N].extents.charHeight << 1)
#define	Twice_Half_Char_Height(N)	(Twice_Char_Height(N) + Half_Char_Height(N))

#define	Header_Height(N)		(One_Char_Height(N) + Quarter_Char_Height(N))
#define	Footer_Height(N)		(One_Char_Height(N) + Half_Char_Height(N))

#define	GEOMETRY_MAIN_COLS	84
#define	GEOMETRY_MAIN_ROWS	36
#define	GEOMETRY_CORES_COLS	22
#define	GEOMETRY_CORES_ROWS	8
#define	GEOMETRY_CSTATES_COLS	8
#define	GEOMETRY_CSTATES_ROWS	10
#define	GEOMETRY_TEMPS_COLS	32
#define	GEOMETRY_TEMPS_ROWS	10
#define	GEOMETRY_SYSINFO_COLS	80
#define	GEOMETRY_SYSINFO_ROWS	36

#define	MAIN_TEXT_WIDTH		MAX(GEOMETRY_MAIN_COLS, A->L.Page[MAIN].Geometry.cols)
#define	MAIN_TEXT_HEIGHT	MAX(GEOMETRY_MAIN_ROWS, A->L.Page[MAIN].Geometry.rows)

#define	MAIN_SECTION		_APPNAME" "_MAJOR"."_MINOR"-"_NIGHTLY" CyrIng"

#define	CORES_TEXT_WIDTH	MAX(A->SHM->P.Boost[9], A->L.Page[CORES].Geometry.cols)
#define	CORES_TEXT_HEIGHT	(A->SHM->P.CPU)

#define	CSTATES_TEXT_SPACING	4
#define	CSTATES_TEXT_WIDTH	(MAX(A->SHM->P.CPU, A->L.Page[CSTATES].Geometry.cols) * CSTATES_TEXT_SPACING)
#define	CSTATES_TEXT_HEIGHT	MAX(GEOMETRY_CSTATES_ROWS, A->L.Page[CSTATES].Geometry.rows)

#define	TEMPS_TEXT_WIDTH	MAX(((A->SHM->P.Features.ThreadCount + 1) << 2), A->L.Page[TEMPS].Geometry.cols)
#define	TEMPS_TEXT_HEIGHT	MAX(GEOMETRY_TEMPS_ROWS, A->L.Page[TEMPS].Geometry.rows)

#define	SYSINFO_TEXT_WIDTH	MAX(GEOMETRY_SYSINFO_COLS, A->L.Page[SYSINFO].Geometry.cols)
#define	SYSINFO_TEXT_HEIGHT	MAX(GEOMETRY_SYSINFO_ROWS, A->L.Page[SYSINFO].Geometry.rows)

#define	DUMP_HEX16_STR		16
// BIN64: 16 x 4 digits + '\0'
#define DUMP_BIN64_STR		(16 * 4) + 1
// PRE_TEXT: ##' 'Addr[5]' 'Name&Padding[24]'['
#define DUMP_PRE_TEXT		(2 + 1 + 5 + 1 + DUMP_REG_ALIGN + 1)
// Columns: PRE_TEXT + BIN64 w/ 15 interspaces + '] ' + CoreNum + ScrollButtons
#define	GEOMETRY_DUMP_COLS	(DUMP_PRE_TEXT + DUMP_BIN64_STR + 15 + 2 + 3 + 3)
#define	GEOMETRY_DUMP_ROWS	(DUMP_ARRAY_DIMENSION + 2)
#define	DUMP_TEXT_WIDTH		MAX(GEOMETRY_DUMP_COLS, A->L.Page[DUMP].Geometry.cols)
#define	DUMP_TEXT_HEIGHT	MAX(GEOMETRY_DUMP_ROWS, A->L.Page[DUMP].Geometry.rows)

#define	GEOMETRY_PARSER	"%d:%dx%d%d%d,%n"
#define	GEOMETRY_FORMAT	"%d:%dx%d%+d%+d,"
#define	GEOMETRY_SIZE	strlen("0:640x360+5120+2880,")

#define	MENU_FORMAT	"[F1]      Help             [F2]     Core\n"               \
			"[F3]      C-States         [F4]     Temps \n"             \
			"[F5]      System Info      [F6]     Dump\n"               \
			"KeyPad[+] Faster Loop     KeyPad[-] Slower Loop\n"        \
			"[Pause]   Suspend/Resume display\n"                       \
			"\nWith the [Shift] key :\n"                               \
			"                                  [Up]\n"                 \
			"  Page Scrolling           [Left]      [Right]\n"         \
			"                                 [Down]\n\n"              \
			"[PgDw]   Page Down         [PgUp]   Page Up\n"            \
			"[Home]   Line Begin        [End]    Line End\n"           \
			"\nWith the [Control] key:\n"                              \
			"[Home]   Page start        [End]    Page end\n"           \
			"[L][l]   Refresh page      [Q][q]   Quit\n"               \
			"[Y][y]   Cycles            [W][w]   Wallboard\n"          \
			"[Z][z]   Frequency Hz      [P][p]   C-States %\n"         \
			"[R][r]   Ratio values      [T][t]   Task schedule\n\n"    \
			"Command keys:\n"                                          \
			"[Left] | [Right] | [Home] | [End] Move the cursor insertion\n"  \
			"[Up] | [Down]  Browse forward, backward the commands history\n" \
			"[F12] Substitute command line using the history index\n"        \
			"[Backspace] Remove the character before the cursor\n"           \
			"[Erase]     Remove the character under the cursor\n"            \
			"[Escape]    Cancel the full command line\n"                     \
			"[Enter]     Submit the command line\n"                          \
			"[Tab]       Expand the command line\n\n"                        \
			"Mouse buttons:\n"                                         \
			"[Left]  Activate Button    [Right] Grab & Move Widget\n"  \
			"[Wheel Down] Page Down     [Wheel Up] Page Up\n"

#define	CORE_NUM	"#%-2d"
#define	CORE_FREQ	"%4.0fMHz"
#define	CORE_CYCLES	"%016llu:%016llu"
#define	CORE_DELTA	"%04llu:%04llu %04llu %04llu / %04llu"
#define	CORE_TASK	"%s"
#define	CORE_RATIO	"%-3.1f"
#define	CSTATES_PERCENT	"%6.2f%%     %6.2f%%     %6.2f%%     %6.2f%%"
#define	CSTATES_AVERAGE	"%6.2f      %6.2f      %6.2f      %6.2f"
#define	CSTATES_FOOTER	"~      % Ta        % C0        % C3        % C6"
#define	OVERCLOCK	"%s [%4.0f MHz]"
#define	TEMPERATURE	"%3d"

#define	PROC_FORMAT	"Processor  [%s]\n"									\
			"\n"											\
			"Base Clock [%5.2f MHz]                                 Source [%s]\n"			\
			"\n"											\
			" Family               Model             Stepping             Max# of\n"		\
			"  Code                 No.                 ID                Threads\n"		\
			"[%6X]            [%6X]            [%6d]            [%6d]\n"				\
			"\n"											\
			"Architecture [%s]\n"									\
			"\n"											\
			"Boot Processor features:\n"								\
			"Virtual Mode Extension                                        VME [%c]\n"		\
			"Debugging Extension                                            DE [%c]\n"		\
			"Page Size Extension                                           PSE [%c]\n"		\
			"Time Stamp Counter                                [%9s] TSC [%c]\n"			\
			"Model Specific Registers                                      MSR [%c]   [%3s]\n"	\
			"Physical Address Extension                                    PAE [%c]\n"		\
			"Advanced Programmable Interrupt Controller                   APIC [%c]\n"		\
			"Memory Type Range Registers                                  MTRR [%c]   [%3s]\n"	\
			"Page Global Enable                                            PGE [%c]\n"		\
			"Machine-Check Architecture                                    MCA [%c]\n"		\
			"Page Attribute Table                                          PAT [%c]\n"		\
			"36-bit Page Size Extension                                  PSE36 [%c]\n"		\
			"Processor Serial Number                                       PSN [%c]\n"		\
			"Debug Store & Precise Event Based Sampling               DS, PEBS [%c]   [%3s]\n"	\
			"Advanced Configuration & Power Interface                     ACPI [%c]\n"		\
			"Self-Snoop                                                     SS [%c]\n"		\
			"Hyper-Threading                                               HTT [%c]   [%3s]\n"	\
			"Thermal Monitor                        TM#1 [%c]  [%3s]       TM#2 [%c]   [%3s]\n"	\
			"Pending Break Enable                                          PBE [%c]\n"		\
			"64-Bit Debug Store                                         DTES64 [%c]\n"		\
			"CPL Qualified Debug Store                                  DS-CPL [%c]\n"		\
			"Virtual Machine Extensions                                    VMX [%c]\n"		\
			"Safer Mode Extensions                                         SMX [%c]\n"		\
			"SpeedStep                              C1E [%3s]             EIST [%c]   [%3s]\n"	\
			"L1 Data Cache Context ID                                  CNXT-ID [%c]\n"		\
			"Fused Multiply Add                                            FMA [%c]\n"		\
			"xTPR Update Control                                          xTPR [%c]   [%3s]\n"	\
			"Perfmon and Debug Capability                                 PDCM [%c]\n"		\
			"Process Context Identifiers                                  PCID [%c]\n"		\
			"Direct Cache Access                                           DCA [%c]\n"		\
			"Extended xAPIC Support                                     x2APIC [%c]\n"		\
			"Time Stamp Counter Deadline                          TSC-DEADLINE [%c]\n"		\
			"XSAVE/XSTOR States                                          XSAVE [%c]\n"		\
			"OS-Enabled Ext. State Management                          OSXSAVE [%c]\n"		\
			"Execution Disable Bit Support                              XD-Bit [%c]   [%3s]\n"	\
			"1 GB Pages Support                                      1GB-PAGES [%c]\n"		\
			"Hardware Lock Elision                                         HLE [%c]\n"		\
			"Restricted Transactional Memory                               RTM [%c]\n"		\
			"Fast-Strings                                      REP MOVSB/STOSB [%c]   [%3s]\n"	\
			"Digital Thermal Sensor                                        DTS [%c]\n"		\
			"Automatic Thermal Control Circuit Enable                      TCC       [%3s]\n"	\
			"Performance Monitoring Available                               PM       [%3s]\n"	\
			"Branch Trace Storage Unavailable                              BTS       [%3s]\n"	\
			"Limit CPUID Maxval                                    Limit-CPUID       [%3s]\n"	\
			"Turbo Boost Technology/Dynamic Acceleration             TURBO/IDA [%c]   [%3s]\n"	\
			"\n"											\
			"Ratio Boost:   Min   Max    8C    7C    6C    5C    4C    3C    2C    1C\n"		\
			"               %3d   %3d   %3d   %3d   %3d   %3d   %3d   %3d   %3d   %3d\n"		\
			"\n"											\
			"Instruction set:\n"									\
			"FPU       [%c]           CX8 [%c]          SEP [%c]    CMOV [%c]        CLFSH [%c]\n"	\
			"MMX       [%c]          FXSR [%c]          SSE [%c]    SSE2 [%c]         SSE3 [%c]\n"	\
			"SSSE3     [%c]        SSE4.1 [%c]       SSE4.2 [%c]                 PCLMULDQ [%c]\n"	\
			"MONITOR   [%c][%3s]     CX16 [%c]        MOVBE [%c]                   POPCNT [%c]\n"	\
			"AES       [%c]      AVX/AVX2 [%c/%c]       F16C [%c]                   RDRAND [%c]\n"	\
			"LAHF/SAHF [%c]       SYSCALL [%c][%3s]  RDTSCP [%c]    IA64 [%c]    BM1/BM2 [%c/%c]\n"	\
			"\n"

#define	TOPOLOGY_SECTION "Processor topology:                                       %-3ux CPU Online\n"		\
			"CPU#    APIC    Core  Thread   State\n"
#define	TOPOLOGY_FORMAT	"%03u %8u%8u%8u   [%3s]\n"

#define	PERF_SECTION	"\n"											\
			"Performance:\n"									\
			"Monitoring Counters                                       %-3ux%3u bits\n"		\
			"Fixed Counters                                            %-3ux%3u bits\n"		\
			"\n"											\
			"CPU         Counter#0                Counter#1                Counter#2\n"		\
			" #      OS  User  AnyThread      OS  User  AnyThread      OS  User  AnyThread\n"
#define	PERF_FORMAT	"%03u      %1d     %1d     %1d            %1d     %1d     %1d            %1d     %1d     %1d\n"

#define	RAM_SECTION	"\n"											\
			"Memory Controler:\n"
#define	CHA_FORMAT	"Channel   tCL   tRCD  tRP   tRAS  tRRD  tRFC  tWR   tRTPr tWTPr tFAW  B2B\n"
#define	CAS_FORMAT	"   #%1i   |%4d%6d%6d%6d%6d%6d%6d%6d%6d%6d%6d\n"

#define	SMBIOS_SECTION	"\n"											\
			"System Management BIOS:\n"
#define	SMBIOS4_FORMAT	"Processor [%s]\n"									\
			"        |- socket %s\n"								\
			"        |- tension %.1f V\n"
#define	SMBIOS7_FORMAT	"        |- %s [%4lld]%s\n"
#define	SMBIOS2_FORMAT	"    Board [%s]\n"									\
			"        |- version %s\n"								\
			"        |- manufactured by %s\n"							\
			"        |- serial [%s]\n"
#define	SMBIOS0_FORMAT	"    BIOS  [%s]\n"									\
			"        |- version %s\n"								\
			"        |- released date %s\n"								\
			"        |- revision %lld.%lld\n"							\
			"        |- ROM Size %lld KB at 0x%04llX\n"
#define	SMBIOS16_FORMAT	"    RAM   [%lld/%lld MB]\n"
#define	SMBIOS17_FORMAT	"        |- %s:%s  %lld MB @ %lld MHz\n"

#define	SYSINFO_SECTION	"System Information"
//                       ## 12345 123456789012345678901234[1234 1234 1234 1234 1234 1234 1234 1234 1234 1234 1234 1234 1234 1234 1234 1234]
#define	DUMP_SECTION	"#  Addr.     Register               60   56   52   48   44   40   36   32   28   24   20   16   12    8    4    0 Core"
#define	REG_HEXVAL	"%016llX"
#define	REG_FORMAT_BOL	"%02d %05X %s%%%zdc["
#define	REG_FORMAT_EOL	"] "CORE_NUM"\n"

#define	TASK_SECTION	"Task Scheduling"

#define	TITLE_MDI_FMT		_APPNAME" %.0fMHz %dC"
#define	TITLE_MAIN_FMT		_APPNAME" %s.%s-%s"
#define	TITLE_CORES_FMT		"Core#%d @ %.0f MHz"
#define	TITLE_CSTATES_FMT	"C-States [%.2f%%] [%.2f%%]"
#define	TITLE_TEMPS_FMT		"Core#%d @ %dC"
#define	TITLE_SYSINFO_FMT	"Clock @ %5.2f MHz"

#define	SIG_EMERGENCY_FMT	"\nShutdown(%02d)"

#define	SCROLLED_ROWS_PER_ONCE	1
#define	SCROLLED_ROWS_PER_PAGE	(MAIN_TEXT_HEIGHT >> 1)
#define	SCROLLED_COLS_PER_ONCE	1

#define	SetHScrolling(N, col)	A->L.Page[N].hScroll=col
#define	SetVScrolling(N, row)	A->L.Page[N].vScroll=row
#define	GetHScrolling(N)	A->L.Page[N].hScroll
#define	GetVScrolling(N)	A->L.Page[N].vScroll

#define	SetHViewport(N, col)	A->L.Page[N].Visible.cols=col
#define	SetVViewport(N, row)	A->L.Page[N].Visible.rows=row
#define	GetHViewport(N)		A->L.Page[N].Visible.cols
#define	GetVViewport(N)		A->L.Page[N].Visible.rows

#define	SetHListing(N, col)	A->L.Page[N].Listing.cols=col
#define	SetVListing(N, row)	A->L.Page[N].Listing.rows=row
#define	GetHListing(N)		A->L.Page[N].Listing.cols
#define	GetVListing(N)		A->L.Page[N].Listing.rows

#define	SetHFrame(N, col)	A->L.Page[N].FrameSize.cols=col
#define	SetVFrame(N, row)	A->L.Page[N].FrameSize.rows=row
#define	GetHFrame(N)		A->L.Page[N].FrameSize.cols
#define	GetVFrame(N)		A->L.Page[N].FrameSize.rows

#define	MAIN_FRAME_VIEW_HSHIFT		1
#define	MAIN_FRAME_VIEW_VSHIFT		4
#define	SYSINFO_FRAME_VIEW_HSHIFT	1
#define	SYSINFO_FRAME_VIEW_VSHIFT	3
#define	DUMP_FRAME_VIEW_HSHIFT		1
#define	DUMP_FRAME_VIEW_VSHIFT		1

#define	KEYINPUT_DEPTH		256
#define	HISTORY_DEPTH		100

typedef struct
{
	int	cols,
		rows;
} MaxText;

typedef struct
{
	unsigned int		UnMapBitmask;
	struct	{
		Bool32		Pageable;
		MaxText		Geometry,
				Visible,
				Listing,
				FrameSize;
		int		hScroll,
				vScroll;
		Pixmap		Pixmap;
		int		width,
				height;
		char		*Title;
	} Page[WIDGETS];
	struct {
		Bool32		fillGraphics,
				freqHertz,
				cycleValues,
				ratioValues,
				showSchedule,
				cStatePercent,
				*showTemp,
				wallboard,
				flashCursor,
				alwaysOnTop,
				noDecorations,
				skipTaskbar,
				cursorShape;
	} Play;
	struct {;
		int		Scroll,
				Length;
		char		*String;
	} WB;
	struct {
		XRectangle	*C0,
				*C3,
				*C6;
	} Usage;
	struct NXSEGMENT {;
		int		N;
		XSegment	*Segment;
	} Axes[WIDGETS], *Temps;
	XPoint			TextCursor[3];
	struct {
		char		*KeyBuffer;
		int		KeyLength, KeyInsert, Recent, Browse, Top, Cmd;
		struct {
			char	*KeyBuffer;
			int	KeyLength;
		} History[HISTORY_DEPTH], Expand;
	} Input;
	char			*Output;
	unsigned long int	globalBackground,
				globalForeground;
	COLORS			Colors[COLOR_COUNT];
} LAYOUT;

#define	_IS_MDI_		(A->MDI != FALSE)

#define	SPLASH_HIDDEN_FLAG	((A.Splash.attributes & 0x1000) >> 12)
#define	SPLASH_DEFERRED_TIME	(__useconds_t) (A.Splash.attributes & 0xFFF)

#define	XDB_SETTINGS_FILE	".xfreq"
#define	XDB_CLASS_MAIN		"Main"
#define	XDB_CLASS_CORES		"Cores"
#define	XDB_CLASS_CSTATES	"CStates"
#define	XDB_CLASS_TEMPS		"Temps"
#define	XDB_CLASS_SYSINFO	"SysInfo"
#define	XDB_CLASS_DUMP		"Dump"
#define	XDB_KEY_FONT		"Font"
#define	XDB_KEY_LEFT		"Left"
#define	XDB_KEY_TOP		"Top"
#define	XDB_KEY_BACKGROUND	"Background"
#define	XDB_KEY_FOREGROUND	"Foreground"
#define	XDB_KEY_CLOCK_SOURCE	"ClockSource"
#define	XDB_KEY_ROM_ADDRESS	"ClockRomAddr"
#define	XDB_KEY_CURSOR_SHAPE	"CursorShape"
#define	XDB_KEY_PLAY_GRAPHICS	"FillGraphics"
#define	XDB_KEY_PLAY_FREQ	"PlayFrequency"
#define	XDB_KEY_PLAY_CYCLES	"PlayCycles"
#define	XDB_KEY_PLAY_RATIOS	"PlayRatios"
#define	XDB_KEY_PLAY_SCHEDULE	"PlaySchedule"
#define	XDB_KEY_PLAY_CSTATES	"PlayCStates"
#define	XDB_KEY_PLAY_WALLBOARD	"PlayBrand"

#define	OPTIONS_COUNT	19
typedef struct
{
	char		*argument;
	char		*format;
	void		*pointer;
	char		*manual;
	char		*xrmName;
} OPTIONS;


#define	COMMANDS_COUNT	15
typedef	struct
{
	char	*Inst,
		*Spec;
	void	(*Proc)();
} COMMANDS;

#define	COMMANDS_LIST					\
{							\
	{"help", NULL, Proc_Help},			\
	{"menu", NULL, Proc_Menu},			\
	{"quit", NULL, Proc_Quit},			\
	{"clear", NULL, ClearMsg},			\
	{"restart", NULL, Proc_Restart},		\
	{"version", NULL, Proc_Release},		\
	{"history", NULL, Proc_History},		\
	{"get color ", "%d", Get_Color},		\
	{"set color ", "%d %x", Set_Color},		\
	{"set font ", "%s", Set_Font},			\
	{"dump msr ", "%x %hu %hhu", Svr_Dump_MSR},	\
	{"read msr ", "%x %hu", Svr_Read_MSR},		\
	{"write msr ", "%x %hu %llx", Svr_Write_MSR},	\
	{"enable ", "%ms", Svr_Enable_Feature},		\
	{"disable ", "%ms", Svr_Disable_Feature}	\
}

typedef	struct
{
	char		*Inst;
	unsigned int	ID;
} CTL_FEATURES;

#define	FEATURES_LIST		\
{				\
	{"turbo", CTL_TURBO},	\
	{"eist", CTL_EIST},	\
	{"c1e", CTL_C1E},	\
	{"tcc",	CTL_TCC},	\
	{NULL, CTL_NOP}		\
}

typedef struct
{
	struct
	{
		int	Shm,
			SmBIOS;
	} FD;

	SHM_STRUCT	*SHM;

	SMBIOS_TREE	*SmBIOS;

	Display		*display;
	Screen		*screen;
	char		*Geometries;
	char		*fontName;
	XFontStruct	*xfont;
	Atom		atom[5];
	Cursor		MouseCursor[MC_COUNT];
	XSPLASH		Splash;
	XWINDOW		W[WIDGETS];
	XTARGET		T;
	LAYOUT		L;
	sigset_t	Signal;
	pthread_t	TID_SigHandler,
			TID_Draw;
	Bool32		MDI,
			LOOP,
			RESTART,
			PAUSE[WIDGETS];

	unsigned int	Room;

	char		*configFile;
	OPTIONS		Options[OPTIONS_COUNT];
	COMMANDS	Commands[COMMANDS_COUNT];
	char		xACL;
} uARG;

// Definition of the Buttons management functions (CallBack).
Bool32	Button_State(uARG *A, WBUTTON *wButton);
Bool32	SCHED_State(uARG *A, WBUTTON *wButton);
Bool32	TSC_State(uARG *A, WBUTTON *wButton);
Bool32	BIOS_State(uARG *A, WBUTTON *wButton);
Bool32	SPEC_State(uARG *A, WBUTTON *wButton);
Bool32	ROM_State(uARG *A, WBUTTON *wButton);

void	CallBackSave(uARG *A, WBUTTON *wButton) ;
void	CallBackQuit(uARG *A, WBUTTON *wButton) ;
void	CallBackButton(uARG *A, WBUTTON *wButton) ;
void	CallBackTemps(uARG *A, WBUTTON *wButton) ;
void	CallBackMinimizeWidget(uARG *A, WBUTTON *wButton) ;
void	CallBackRestoreWidget(uARG *A, WBUTTON *wButton) ;

// Definition of the Widgets drawing functions.
// The triple buffering is as the following sequence:
// step 1 : draw the static graphics into the background pixmap.
void	BuildLayout(uARG *A, int G) ;
// step 2 : copy the background into the foreground pixmap.
void	MapLayout(uARG *A, int G) ;
// step 3 : add the animated graphics into the foreground pixmap.
void	DrawLayout(uARG *A, int G) ;
// step 4 : copy the foreground into the display window (taking care of the scrolling pixmap).
void	FlushLayout(uARG *A, int G) ;
// loop to step 2 to avoid the execution of the building process.

// All-in-One macro.
#define	fDraw(N, DoBuild, DoDraw) {		\
	if(DoBuild)  BuildLayout(A, N);		\
	MapLayout(A, N);			\
	if(DoDraw)   DrawLayout(A, N);		\
	FlushLayout(A, N);			\
}


/* --- Splash bitmap --- */

#define splash_width 267
#define splash_height 50
static unsigned char splash_bits[] = {
   0xff, 0x3f, 0x00, 0x00, 0xf8, 0xff, 0x01, 0x00, 0x00, 0x00, 0xf0, 0xff,
   0xff, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xff, 0xff, 0x0f, 0x00, 0xff, 0xff,
   0xff, 0xff, 0x0f, 0xf0, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0xfe, 0x3f,
   0x00, 0x00, 0xfc, 0xff, 0x00, 0x00, 0x00, 0x00, 0xfc, 0xff, 0xff, 0xff,
   0xff, 0xf0, 0xff, 0xff, 0xff, 0xff, 0x1f, 0xc0, 0xff, 0xff, 0xff, 0xff,
   0x0f, 0xfc, 0xff, 0xff, 0xff, 0xff, 0x01, 0x00, 0xfe, 0x7f, 0x00, 0x00,
   0xfc, 0x7f, 0x00, 0x00, 0x00, 0x00, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xf0,
   0xff, 0xff, 0xff, 0xff, 0x3f, 0xe0, 0xff, 0xff, 0xff, 0xff, 0x0f, 0xfe,
   0xff, 0xff, 0xff, 0xff, 0x03, 0x00, 0xfc, 0xff, 0x00, 0x00, 0xfe, 0x7f,
   0x00, 0x00, 0x00, 0x00, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xf0, 0xff, 0xff,
   0xff, 0xff, 0x7f, 0xe0, 0xff, 0xff, 0xff, 0xff, 0x0f, 0xfe, 0xff, 0xff,
   0xff, 0xff, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0xf8, 0xff, 0x01, 0x00, 0xff, 0x1f, 0x00, 0x00, 0x00, 0x00,
   0xff, 0xff, 0xff, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xff, 0xff, 0x7f, 0xf0,
   0xff, 0xff, 0xff, 0xff, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xff, 0x07, 0x00,
   0xf0, 0xff, 0x03, 0x80, 0xff, 0x1f, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff,
   0xff, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xff, 0xff, 0x7f, 0xf0, 0xff, 0xff,
   0xff, 0xff, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xff, 0x07, 0x00, 0xe0, 0xff,
   0x07, 0xc0, 0xff, 0x0f, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff,
   0xff, 0xf0, 0xff, 0xff, 0xff, 0xff, 0x7f, 0xf0, 0xff, 0xff, 0xff, 0xff,
   0x0f, 0xff, 0xff, 0xff, 0xff, 0xff, 0x07, 0x00, 0xc0, 0xff, 0x07, 0xe0,
   0xff, 0x07, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf0,
   0xff, 0xff, 0xff, 0xff, 0x7f, 0xf0, 0xff, 0xff, 0xff, 0xff, 0x0f, 0xff,
   0xff, 0xff, 0xff, 0xff, 0x07, 0x00, 0xc0, 0xff, 0x0f, 0xe0, 0xff, 0x03,
   0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf0, 0xff, 0xff,
   0xff, 0xff, 0x7f, 0xf0, 0xff, 0xff, 0xff, 0xff, 0x0f, 0xff, 0xff, 0xff,
   0xff, 0xff, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0xff, 0x3f, 0xf8, 0xff, 0x01, 0x00, 0x00, 0x00, 0x00,
   0xff, 0x07, 0x00, 0x00, 0x00, 0xf0, 0x7f, 0x00, 0x00, 0xe0, 0x7f, 0xf0,
   0x7f, 0x00, 0x00, 0x00, 0x00, 0xff, 0x07, 0x00, 0x00, 0xfe, 0x07, 0x00,
   0x00, 0xfe, 0x3f, 0xfc, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0x07,
   0x00, 0x00, 0x00, 0xf0, 0x7f, 0x00, 0x00, 0xe0, 0x7f, 0xf0, 0x7f, 0x00,
   0x00, 0x00, 0x00, 0xff, 0x07, 0x00, 0x00, 0xfe, 0x07, 0x00, 0x00, 0xfe,
   0x7f, 0xfc, 0x7f, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0x07, 0x00, 0x00,
   0x00, 0xf0, 0x7f, 0x00, 0x00, 0xe0, 0x7f, 0xf0, 0x7f, 0x00, 0x00, 0x00,
   0x00, 0xff, 0x07, 0x00, 0x00, 0xfe, 0x07, 0x00, 0x00, 0xfc, 0xff, 0xfe,
   0x7f, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0x07, 0x00, 0x00, 0x00, 0xf0,
   0x7f, 0x00, 0x00, 0xe0, 0x7f, 0xf0, 0x7f, 0x00, 0x00, 0x00, 0x00, 0xff,
   0x07, 0x00, 0x00, 0xfe, 0x07, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0xf0, 0xff, 0xff, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00,
   0xff, 0xff, 0xff, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xff, 0xff, 0x7f, 0xf0,
   0xff, 0xff, 0xff, 0xff, 0x0f, 0xff, 0x07, 0x00, 0x00, 0xfe, 0x07, 0x00,
   0x00, 0xe0, 0xff, 0xff, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff,
   0xff, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xff, 0xff, 0x3f, 0xf0, 0xff, 0xff,
   0xff, 0xff, 0x0f, 0xff, 0x07, 0x00, 0x00, 0xfe, 0x07, 0x00, 0x00, 0xc0,
   0xff, 0xff, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff,
   0xff, 0xf0, 0xff, 0xff, 0xff, 0xff, 0x1f, 0xf0, 0xff, 0xff, 0xff, 0xff,
   0x0f, 0xff, 0x07, 0x00, 0x00, 0xfe, 0x07, 0x00, 0x00, 0xc0, 0xff, 0xff,
   0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf0,
   0xff, 0xff, 0xff, 0xff, 0x0f, 0xf0, 0xff, 0xff, 0xff, 0xff, 0x0f, 0xff,
   0x07, 0x00, 0x00, 0xfe, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0xff, 0xff, 0xff, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xff, 0xff, 0x0f, 0xf0,
   0xff, 0xff, 0xff, 0xff, 0x0f, 0xff, 0x07, 0x00, 0x00, 0xfe, 0x07, 0x00,
   0x00, 0x00, 0xfe, 0x7f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff,
   0xff, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xff, 0xff, 0x1f, 0xf0, 0xff, 0xff,
   0xff, 0xff, 0x0f, 0xff, 0x07, 0x00, 0x00, 0xfe, 0x07, 0x00, 0x00, 0x00,
   0xfe, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff,
   0xff, 0xf0, 0xff, 0xff, 0xff, 0xff, 0x3f, 0xf0, 0xff, 0xff, 0xff, 0xff,
   0x0f, 0xff, 0x07, 0x00, 0x00, 0xfe, 0x07, 0x00, 0x00, 0x00, 0xff, 0xff,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf0,
   0xff, 0xff, 0xff, 0xff, 0x7f, 0xf0, 0xff, 0xff, 0xff, 0xff, 0x0f, 0xff,
   0x07, 0x00, 0x00, 0xfe, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0xff, 0xff, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xff, 0xff, 0x03, 0x00, 0x00, 0xff,
   0xff, 0x03, 0xff, 0x07, 0x00, 0x00, 0x00, 0xf0, 0x7f, 0x00, 0x00, 0xe0,
   0x7f, 0xf0, 0x7f, 0x00, 0x00, 0x00, 0x00, 0xff, 0x07, 0x00, 0x00, 0xfe,
   0x07, 0x00, 0x00, 0xc0, 0xff, 0xff, 0x07, 0x00, 0x00, 0xff, 0xff, 0x03,
   0xff, 0x07, 0x00, 0x00, 0x00, 0xf0, 0x7f, 0x00, 0x00, 0xe0, 0x7f, 0xf0,
   0x7f, 0x00, 0x00, 0x00, 0x00, 0xff, 0x07, 0x00, 0x00, 0xfe, 0x07, 0x00,
   0x00, 0xe0, 0xff, 0xff, 0x07, 0x00, 0x00, 0xff, 0xff, 0x03, 0xff, 0x07,
   0x00, 0x00, 0x00, 0xf0, 0x7f, 0x00, 0x00, 0xe0, 0x7f, 0xf0, 0x7f, 0x00,
   0x00, 0x00, 0x00, 0xff, 0x07, 0x00, 0x00, 0xfe, 0x07, 0x00, 0x00, 0xe0,
   0xff, 0xff, 0x0f, 0x00, 0x00, 0xff, 0xff, 0x03, 0xff, 0x07, 0x00, 0x00,
   0x00, 0xf0, 0x7f, 0x00, 0x00, 0xe0, 0x7f, 0xf0, 0x7f, 0x00, 0x00, 0x00,
   0x00, 0xff, 0x07, 0x00, 0x00, 0xfe, 0x07, 0x00, 0x00, 0xf0, 0xff, 0xff,
   0x1f, 0x00, 0x00, 0xff, 0xff, 0x03, 0xff, 0x07, 0x00, 0x00, 0x00, 0xf0,
   0x7f, 0x00, 0x00, 0xe0, 0x7f, 0xf0, 0x7f, 0x00, 0x00, 0x00, 0x00, 0xff,
   0x07, 0x00, 0x00, 0xfe, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0xfc, 0xff, 0xff, 0x3f, 0x00, 0x00, 0x00,
   0x00, 0x00, 0xff, 0x07, 0x00, 0x00, 0x00, 0xf0, 0x7f, 0x00, 0x00, 0xe0,
   0x7f, 0xf0, 0x7f, 0x00, 0x00, 0x00, 0x00, 0xff, 0x07, 0x00, 0x00, 0xfe,
   0x07, 0x00, 0x00, 0xfc, 0x7f, 0xfe, 0x7f, 0x00, 0x00, 0x00, 0x00, 0x00,
   0xff, 0x07, 0x00, 0x00, 0x00, 0xf0, 0x7f, 0x00, 0x00, 0xe0, 0x7f, 0xf0,
   0x7f, 0x00, 0x00, 0x00, 0x00, 0xff, 0x07, 0x00, 0x00, 0xfe, 0x07, 0x00,
   0x00, 0xfe, 0x7f, 0xfc, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0x07,
   0x00, 0x00, 0x00, 0xf0, 0x7f, 0x00, 0x00, 0xe0, 0x7f, 0xf0, 0x7f, 0x00,
   0x00, 0x00, 0x00, 0xff, 0x07, 0x00, 0x00, 0xfe, 0x07, 0x00, 0x00, 0xff,
   0x3f, 0xf8, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0x07, 0x00, 0x00,
   0x00, 0xf0, 0x7f, 0x00, 0x00, 0xe0, 0x7f, 0xf0, 0x7f, 0x00, 0x00, 0x00,
   0x00, 0xff, 0x07, 0x00, 0x00, 0xfe, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0xc0, 0xff, 0x0f, 0xe0, 0xff, 0x07, 0x00, 0x00,
   0x00, 0x00, 0xff, 0x07, 0x00, 0x00, 0x00, 0xf0, 0x7f, 0x00, 0x00, 0xe0,
   0x7f, 0xf0, 0xff, 0xff, 0xff, 0xff, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xff,
   0xff, 0x07, 0xe0, 0xff, 0x07, 0xc0, 0xff, 0x07, 0x00, 0x00, 0x00, 0x00,
   0xff, 0x07, 0x00, 0x00, 0x00, 0xf0, 0x7f, 0x00, 0x00, 0xe0, 0x7f, 0xf0,
   0xff, 0xff, 0xff, 0xff, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x07,
   0xe0, 0xff, 0x03, 0xc0, 0xff, 0x0f, 0x00, 0x00, 0x00, 0x00, 0xff, 0x07,
   0x00, 0x00, 0x00, 0xf0, 0x7f, 0x00, 0x00, 0xe0, 0x7f, 0xf0, 0xff, 0xff,
   0xff, 0xff, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x07, 0xf0, 0xff,
   0x03, 0x80, 0xff, 0x1f, 0x00, 0x00, 0x00, 0x00, 0xff, 0x07, 0x00, 0x00,
   0x00, 0xf0, 0x7f, 0x00, 0x00, 0xe0, 0x7f, 0xf0, 0xff, 0xff, 0xff, 0xff,
   0x0f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x07, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0xfc, 0xff, 0x00, 0x00, 0xfe, 0x7f, 0x00, 0x00,
   0x00, 0x00, 0xff, 0x07, 0x00, 0x00, 0x00, 0xf0, 0x7f, 0x00, 0x00, 0xe0,
   0x7f, 0xe0, 0xff, 0xff, 0xff, 0xff, 0x0f, 0xfe, 0xff, 0xff, 0xff, 0xff,
   0xff, 0x07, 0xfe, 0x7f, 0x00, 0x00, 0xfc, 0xff, 0x00, 0x00, 0x00, 0x00,
   0xff, 0x07, 0x00, 0x00, 0x00, 0xf0, 0x7f, 0x00, 0x00, 0xe0, 0x7f, 0xc0,
   0xff, 0xff, 0xff, 0xff, 0x0f, 0xfc, 0xff, 0xff, 0xff, 0xff, 0xff, 0x07,
   0xff, 0x3f, 0x00, 0x00, 0xf8, 0xff, 0x00, 0x00, 0x00, 0x00, 0xff, 0x07,
   0x00, 0x00, 0x00, 0xf0, 0x7f, 0x00, 0x00, 0xe0, 0x7f, 0x80, 0xff, 0xff,
   0xff, 0xff, 0x0f, 0xf8, 0xff, 0xff, 0xff, 0xff, 0xff, 0x07, 0xff, 0x1f,
   0x00, 0x00, 0xf0, 0xff, 0x01, 0x00, 0x00, 0x00, 0xff, 0x07, 0x00, 0x00,
   0x00, 0xf0, 0x7f, 0x00, 0x00, 0xe0, 0x7f, 0x00, 0xff, 0xff, 0xff, 0xff,
   0x0f, 0xf0, 0xff, 0xff, 0xff, 0xff, 0xff, 0x07 };
