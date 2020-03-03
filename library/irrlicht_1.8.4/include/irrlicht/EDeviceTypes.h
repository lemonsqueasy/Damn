// Copyright (C) 2002-2012 Nikolaus Gebhardt
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in irrlicht.h

#ifndef __E_DEVICE_TYPES_H_INCLUDED__
#define __E_DEVICE_TYPES_H_INCLUDED__

namespace irr
{

	//! An enum for the different irrlichtDevice types supported by the Irrlicht Engine.
	enum E_DEVICE_TYPE
	{

		//! A irrlichtDevice native to Microsoft Windows
		/** This irrlichtDevice uses the Win32 API and works in all versions of Windows. */
		EIDT_WIN32,

		//! A irrlichtDevice native to Windows CE devices
		/** This irrlichtDevice works on Windows Mobile, Pocket PC and Microsoft SmartPhone devices */
		EIDT_WINCE,

		//! A irrlichtDevice native to Unix style operating systems.
		/** This irrlichtDevice uses the X11 windowing system and works in Linux, Solaris, FreeBSD, OSX and
		other operating systems which support X11. */
		EIDT_X11,

		//! A irrlichtDevice native to Mac OSX
		/** This irrlichtDevice uses Apple's Cocoa API and works in Mac OSX 10.2 and above. */
		EIDT_OSX,

		//! A irrlichtDevice which uses Simple DirectMedia Layer
		/** The SDL irrlichtDevice works under all platforms supported by SDL but first must be compiled
		in by defining the IRR_USE_SDL_DEVICE macro in IrrCompileConfig.h */
		EIDT_SDL,

		//! A irrlichtDevice for raw framebuffer access
		/** Best used with embedded devices and mobile systems.
		Does not need X11 or other graphical subsystems.
		May support hw-acceleration via opengl-ES for FBDirect */
		EIDT_FRAMEBUFFER,

		//! A simple text only irrlichtDevice supported by all platforms.
		/** This irrlichtDevice allows applications to run from the command line without opening a window.
		It can render the output of the software drivers to the console as ASCII. It only supports
		mouse and keyboard in Windows operating systems. */
		EIDT_CONSOLE,

		//! This selection allows Irrlicht to choose the best irrlichtDevice from the ones available.
		/** If this selection is chosen then Irrlicht will try to use the IrrlichtDevice native
		to your operating system. If this is unavailable then the X11, SDL and then console irrlichtDevice
		will be tried. This ensures that Irrlicht will run even if your platform is unsupported,
		although it may not be able to render anything. */
		EIDT_BEST
	};

} // end namespace irr

#endif // __E_DEVICE_TYPES_H_INCLUDED__

