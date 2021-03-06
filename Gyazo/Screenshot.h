#pragma once
#include <Windows.h>
#include <string>
#include <GdiPlus.h>
#pragma comment(lib, "gdiplus.lib")
#include "Util.h"

#include "png.h"
#pragma comment(lib, "libpng15.lib")

#include "pngconf.h"
#include "pngdebug.h"
#include "pnginfo.h"
#include "pnglibconf.h"
#include "pngstruct.h"

#include <map>
#include <math.h>

#pragma warning(push)
#pragma warning(disable : 4251)
#include <Magick++.h>
#pragma warning(pop)
#pragma comment(lib, "CORE_RL_Magick++_.lib")

using namespace ::std;
using namespace ::Gdiplus;

typedef unsigned int uint;

class Screenshot
{
public:
	Screenshot();
	~Screenshot();

	// 指定されたウインドウのビットマップ情報を取得して返却します
	static HBITMAP Screenshot::GetBitmapFromWindow(HWND window, BITMAPINFO *pbmi, void **pbits, RECT *rect);

	// MIME-TYPEをもとにEncoderを取得します
	static BOOL Screenshot::GetClsidEncoderFromMimeType(LPCTSTR format, LPCLSID lpClsid);

	// ファイル名をもとに、Enocderを取得します
	static BOOL Screenshot::GetClsidEncoderFromFileName(LPCTSTR fileName, LPCLSID lpClsid);

	// 指定されたファイル名で、hBitmapを保存します
	static BOOL Screenshot::SaveToFileAutoDetectFormat(HBITMAP hBitmap, LPCTSTR fileName);

  	// 指定されたファイル名で、hBitmapを保存します
	static BOOL Screenshot::SaveToPngFile(HBITMAP hBitmap, LPCTSTR fileName);
  static BOOL Screenshot::SaveToFileMagick(HBITMAP hBitmap, LPCTSTR fileName);

	// 指定のウインドウの、指定の範囲をスクリーンショットします
	static BOOL Screenshot::ScreenshotWindow(LPCTSTR fileName, HWND window, RECT *rect);

	// ファイルに保存せず、HBITMAP形式で返却します
	static HBITMAP Screenshot::ScreenshotInMemory(HWND window, RECT *rect);

	// Desktopのスクリーンショットを撮影してファイルに保存します
	static BOOL Screenshot::ScreenshotDesktop(LPCTSTR fileName, RECT *rect);
};


