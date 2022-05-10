#pragma once

#ifdef _WIN64
	typedef __int64             PmLong;
	typedef unsigned __int64    PmULong;
	typedef __int64             PmInt;
	typedef unsigned __int64    PmUInt;	
#else
// Using __w64 let's us catch potential errors at compile time
// when /Wp64 is enabled.  Also, we use long, instead of int,
// in the 32-bit build.  That's for compatibility with the Int32
// and UInt32 types.
//
	typedef __w64 long          PmLong;
	typedef __w64 unsigned long PmULong;
	//
	typedef __w64 int           PmInt;
	typedef __w64 unsigned int  PmUInt;
#endif

typedef PmUInt	PmSize_t;

typedef unsigned char			PmUInt8;
typedef unsigned short			PmUInt16;
typedef unsigned long			PmUInt32;
typedef unsigned __int64		PmUInt64;

typedef signed char				PmInt8 ;
typedef short					PmInt16;
typedef long					PmInt32;
typedef __int64					PmInt64;