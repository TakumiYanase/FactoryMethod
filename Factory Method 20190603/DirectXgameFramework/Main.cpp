#include "MyGame.h"

// ウィンドウ幅
constexpr int width = 800;
// ウィンドウ高
constexpr int height = 600;

// エントリポイント Entry point
int WINAPI wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPWSTR lpCmdLine, _In_ int nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    if (!DirectX::XMVerifyCPUSupport())
        return 1;
	// COMライブラリを初期化する
    if (FAILED(CoInitializeEx(nullptr, COINITBASE_MULTITHREADED)))
        return 1;

	// MyGameオブジェクトを生成する
	MyGame myGame(width, height);
	// ゲームを実行する
	MSG msg = myGame.Run();

	// COMライブラリの終了処理をする
    CoUninitialize();
    return (int) msg.wParam;
}
