
#ifndef _globals_h
#define _globals_h
	// application signature
	#define APP_NAME "BYDPDict"
	#define APP_VERSION "0.7 (20050214)"
	#define APP_SIGNATURE "application/x-vnd.generic-BYDPDict"
	extern int AppReturnValue;
	// gettext-style translation helper
	#define _(x) SpTranslate(x)
	// Qt-style translation helper
	#define tr(x) SpTranslate(x)
#endif
