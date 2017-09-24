#pragma once

#if defined(_WIN32)
    #define CBK_PLATFORM_WINDOWS 1
    #define CBK_SUPPORTS_DIRECT3D 1
    #define CBK_SUPPORTS_DIRECT3D11 1
    #define CBK_SUPPORTS_OPENGL 1
    #define CBK_OPENGL_INTERFACE_WGL 1
    #define CBK_SUPPORTS_DIRECTSOUND 1
    #if defined(_MSC_VER)
        #define CBK_SUPPORTS_XAUDIO2 1
    #endif
    #define CBK_MULTITHREADED 1

    #if defined(_M_X64)
        #define CBK_64BITS 1
    #elif defined(_M_IX86)
        #define CBK_32BITS 1
    #endif
#elif defined(__APPLE__)
    #define CBK_SUPPORTS_OPENGL 1
    #define CBK_SUPPORTS_METAL 1
    #define CBK_SUPPORTS_OPENAL 1
    #define CBK_SUPPORTS_COREAUDIO 1

    #if TARGET_OS_IOS
        #define CBK_PLATFORM_IOS 1
        #define CBK_SUPPORTS_OPENGLES 1
        #define CBK_OPENGL_INTERFACE_EAGL 1
    #elif TARGET_OS_TV
        #define CBK_PLATFORM_TVOS 1
        #define CBK_SUPPORTS_OPENGLES 1
        #define CBK_OPENGL_INTERFACE_EAGL 1

    #elif TARGET_OS_MAC
        #define CBK_PLATFORM_MACOS 1
        #define CBK_OPENGL_INTERFACE_CGL 1
    #endif

    #define CBK_MULTITHREADED 1

    #if defined(__x86_64__)
        #define CBK_64BITS 1
    #elif defined(__i386__)
        #define CBK_32BITS 1
    #elif defined(__ARM_NEON__)
        #if defined(__arm64__)
            #define CBK_SUPPORTS_NEON64 1
            #define CBK_64BITS 1
        #elif defined(__arm__)
            #define CBK_SUPPORTS_NEON 1
            #define CBK_32BITS 1
        #endif
    #endif
#elif defined(__ANDROID__)
    #define CBK_PLATFORM_ANDROID 1
    #define CBK_SUPPORTS_OPENGL 1
    #define CBK_SUPPORTS_OPENGLES 1
    #define CBK_OPENGL_INTERFACE_EGL 1
    #define CBK_SUPPORTS_OPENSL 1
    #define CBK_SUPPORTS_OPENSLES 1
    #define CBK_MULTITHREADED 1

    #if defined(__x86_64__)
        #define CBK_64BITS 1
    #elif defined(__i386__)
        #define CBK_32BITS 1
    #elif defined(__ARM_NEON__)
        #if defined(__arm64__) || defined(__aarch64__)
            #define CBK_SUPPORTS_NEON64 1
            #define CBK_64BITS 1
        #elif defined(__arm__)
            #define CBK_SUPPORTS_NEON 1
            #define CBK_SUPPORTS_NEON_CHECK 1
            #define CBK_32BITS 1
        #endif
    #endif
#elif defined(RASPBIAN)
    #define CBK_PLATFORM_RASPBIAN 1
    #define CBK_SUPPORTS_OPENGL 1
    #define CBK_SUPPORTS_OPENGLES 1
    #define CBK_OPENGL_INTERFACE_EGL 1
    #define CBK_SUPPORTS_OPENAL 1
    #define CBK_SUPPORTS_ALSA 1
    #define CBK_MULTITHREADED 1

    #if defined(__x86_64__)
        #define CBK_64BITS 1
    #elif defined(__i386__)
        #define CBK_32BITS 1
    #elif defined(__ARM_NEON__)
        #if defined(__arm64__) || defined(__aarch64__)
            #define CBK_SUPPORTS_NEON64 1
            #define CBK_64BITS 1
        #else defined(__arm__)
            #define CBK_SUPPORTS_NEON 1
            #define CBK_32BITS 1
        #endif
    #endif
#elif defined(__linux__)
    #define CBK_PLATFORM_LINUX 1
    #define CBK_SUPPORTS_OPENGL 1
    #if defined(__arm__) || defined(__aarch64__)
        #define CBK_SUPPORTS_OPENGLES 1
    #endif
    #define CBK_OPENGL_INTERFACE_GLX 1
    #define CBK_SUPPORTS_OPENAL 1
    #define CBK_SUPPORTS_ALSA 1
    #define CBK_MULTITHREADED 1

    #if defined(__x86_64__)
        #define CBK_64BITS 1
    #elif defined(__i386__)
        #define CBK_32BITS 1
    #elif defined(__ARM_NEON__)
        #if defined(__arm64__) || defined(__aarch64__)
            #define CBK_SUPPORTS_NEON64 1
            #define CBK_64BITS 1
        #else defined(__arm__)
            #define CBK_SUPPORTS_NEON 1
            #define CBK_32BITS 1
        #endif
    #endif
#elif defined(EMSCRIPTEN)
    #define CBK_PLATFORM_EMSCRIPTEN 1
    #define CBK_SUPPORTS_OPENGL 1
    #define CBK_SUPPORTS_OPENGLES 1
    #define CBK_OPENGL_INTERFACE_EGL 1
    #define CBK_SUPPORTS_OPENAL 1
#endif

#if defined(__SSE__)
    #define CBK_SUPPORTS_SSE 1
#endif
