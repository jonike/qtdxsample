/*!
	@brief DirectX common header
	@author Shintaro Takemura
*/

#pragma once

#define _BOOL
#define WIN32_LEAN_AND_MEAN
#define NOMINMAX
#define _USE_MATH_DEFINES

#include <vector>
#include <valarray>
#include <utility>
#include <memory>
#include <numeric>
#include <algorithm>
#include <functional>

#include <stack>
#include <list>
#include <map>
#include <cassert>
#include <cmath>

#include <sstream>
#include <string>
#include <iostream>

#include <windows.h>

#include <DxErr.h>
#pragma comment(lib,"DxErr.lib")

#ifdef USE_D2D
	#include <d2d1.h>
	#include <d2d1helper.h>
	#include <dwrite.h>
	#include <wincodec.h>

	#pragma comment(lib,"d2d1.lib")
	#pragma comment(lib,"dwrite.lib")
	#pragma comment(lib,"windowscodecs.lib")
	#pragma comment(lib,"dxgi.lib")
#endif

#if USE_D3D==11
	#include <d3d11.h>
	#include <d3dx11.h>

	#pragma comment(lib,"d3d11.lib")
	#ifdef _DEBUG
		#pragma comment(lib,"d3dx11d.lib")
	#else
		#pragma comment(lib,"d3dx11.lib")
	#endif
#endif

#if USE_D3D==10
	#include <d3d10_1.h>
	#include <d3dx10.h>

	#pragma comment(lib,"d3d10_1.lib")
	#ifdef _DEBUG
		#pragma comment(lib,"d3dx10d.lib")
	#else
		#pragma comment(lib,"d3dx10.lib")
	#endif
#endif

#if USE_D3D==9
	#include <d3d9.h>
	#include <d3dx9.h>

	#pragma comment(lib,"d3d9.lib")
	#ifdef _DEBUG
		#pragma comment(lib,"d3dx9d.lib")
	#else
		#pragma comment(lib,"d3dx9.lib")
	#endif
#endif


#ifndef V
#define V(x)           { hr = (x); }
#endif
#ifndef V_RETURN
#define V_RETURN(x)    { hr = (x); if( FAILED(hr) ) { return hr; } }
#endif

#ifndef SAFE_DELETE
#define SAFE_DELETE(p)       { if (p) { delete (p);     (p)=NULL; } }
#endif    
#ifndef SAFE_DELETE_ARRAY
#define SAFE_DELETE_ARRAY(p) { if (p) { delete[] (p);   (p)=NULL; } }
#endif    
#ifndef SAFE_RELEASE
#define SAFE_RELEASE(p)      { if (p) { (p)->Release(); (p)=NULL; } }
#endif

#ifndef DIRECT3D_VERSION
#define DIRECT3D_VERSION ((D3D_VERSION << 8) + D3D_MINOR_VERSION)
#endif
