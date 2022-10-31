#include "Input.h"
#include <cassert>
//#include <wrl.h>
//#define DIRECTINPUT_VERSION     0x0800   // DirectInput�̃o�[�W�����w��
//#include <dinput.h>

//using namespace Microsoft::WRL;

#pragma comment(lib, "dinput8.lib")
#pragma comment(lib, "dxguid.lib")

void Input::Initialize(HINSTANCE hInstance, HWND hwnd)
{
    HRESULT result;

    // DirectInput�̏�����
    //ComPtr<IDirectInput8> directInput;
    result = DirectInput8Create(
        hInstance, DIRECTINPUT_VERSION, IID_IDirectInput8, (void**)&directInput, nullptr);
    assert(SUCCEEDED(result));

    // �L�[�{�[�h�f�o�C�X�̐���
   /* ComPtr<IDirectInputDevice8> keyboard;*/
    result = directInput->CreateDevice(GUID_SysKeyboard, &keyboard, NULL);
    // ���̓f�[�^�`���̃Z�b�g
    result = keyboard->SetDataFormat(&c_dfDIKeyboard); // �W���`��
    assert(SUCCEEDED(result));
    // �r�����䃌�x���̃Z�b�g
    result = keyboard->SetCooperativeLevel(
        hwnd, DISCL_FOREGROUND | DISCL_NONEXCLUSIVE | DISCL_NOWINKEY);
    assert(SUCCEEDED(result));
}

void Input::Update()
{
    // �L�[�{�[�h���̎擾�J�n
    keyboard->Acquire();

    //�O��̃L�[���͂�ۑ�
    memcpy(keyPre, key, sizeof(key));

    // �S�L�[�̓��͏�Ԃ��擾����
    /*BYTE key[256] = {};*/
    keyboard->GetDeviceState(sizeof(key), key);
}

bool Input::Pushkey(BYTE keyNumber)
{
    // �w��L�[�������Ă����true��Ԃ�
    if (key[keyNumber]) {
        return true;
    }
    
    // �����łȂ����false��Ԃ�
    return false;
}

bool Input::TriggerKey(BYTE keyNumber)
{
    if (keyPre[keyNumber]) {
        /*return true;*/
        return false;
    }

    return true;
    /*return false;*/
}