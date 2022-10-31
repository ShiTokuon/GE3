#pragma once
#include <windows.h>
#include <wrl.h>

#define DIRECTINPUT_VERSION     0x0800   // DirectInput�̃o�[�W�����w��
#include <dinput.h>

// ����
class Input
{
public:
	// namespace�ȗ�
	template <class T> using ComPtr = Microsoft::WRL::ComPtr<T>;

public: // �����o�֐�
	// �����o�֐�
	void Initialize(HINSTANCE hInstance,HWND hwnd);

	// �X�V
	void Update();

/// <summary>
/// �L�[�̉������`�F�b�N
/// </summary>
/// <param name=*keyNumber>�L�[�ԍ�(DIK_0 ��)</param>
/// <returns>������Ă��邩</returns>
	bool Pushkey(BYTE keyNumber);

	/// <summary>
/// �L�[�̃g���K�[���`�F�b�N
/// </summary>
/// <param name=*keyNumber>�L�[�ԍ�(DIK_0 ��)</param>
/// <returns>������Ă��邩</returns>
	bool TriggerKey(BYTE keyNumber);

private: // �����o�ϐ�

	// �L�[�{�[�h�̃f�o�C�X
	ComPtr<IDirectInputDevice8> keyboard;

	//DirectInput�̏�����
	ComPtr<IDirectInput8> directInput;

	// �S�L�[�̏��
	BYTE key[256] = {};

	// �O��̑S�L�[�̏��
	BYTE keyPre[256] = {};

};