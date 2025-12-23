#include "FileDialog.h"
#include <windows.h>

std::string openFileDialog() {
	OPENFILENAMEA ofn;
	char file[260] = { 0 };

	ZeroMemory(&ofn, sizeof(ofn));
	ofn.lStructSize = sizeof(ofn);
	ofn.lpstrFilter = "All Files\0*.*\0";
	ofn.lpstrFile = file;
	ofn.nMaxFile = sizeof(file);
	ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;

	if (GetOpenFileNameA(&ofn))
		return file;

	return "";
}