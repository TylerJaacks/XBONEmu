// ReSharper disable CppInconsistentNaming
// ReSharper disable CppClassCanBeFinal
// ReSharper disable CppPolymorphicClassWithNonVirtualPublicDestructor
#pragma once
#include <wrl/client.h>

#include "ICoreWindowX.h"

class CoreWindowX : public ICoreWindowX
{
public:
	HRESULT GetIids(ULONG* iidCount, IID** iids) override;
	HRESULT GetRuntimeClassName(HSTRING* className) override;
	HRESULT GetTrustLevel(TrustLevel* trustLevel) override;
	INT32 _abi_get_Bounds(Rect* rect) override;
	INT32 _abi_get_Dispatcher(ICoreDispatcher** dispatcher) override;
	INT32 _abi_get_IsInputEnabled(boolean* value) override;
	INT32 _abi_set_IsInputEnabled(boolean value) override;
	INT32 _abi_get_Visible(boolean* value) override;
	INT32 _abi_Activate() override;
	INT32 _abi_Close() override;
	INT32 _abi_get_AsyncKeyState(VirtualKey key, CoreVirtualKeyStates* value) override;
	INT32 _abi_get_KeyState(VirtualKey key, CoreVirtualKeyStates* value) override;
	INT32 _abi_add_Activated(ITypedEventHandler<CoreWindow*, WindowActivatedEventArgs*>* handler,
		EventRegistrationToken* token) override;
	INT32 _abi_remove_Activated(EventRegistrationToken token) override;
	INT32 _abi_add_CharacterRecieved(ITypedEventHandler<CoreWindow*, CharacterReceivedEventArgs*>* handler,
		EventRegistrationToken* token) override;
	INT32 _abi_remove_CharacterRecieved(EventRegistrationToken token) override;
	INT32 _abi_add_Closed(ITypedEventHandler<CoreWindow*, CoreWindowEventArgs*>* handler,
		EventRegistrationToken* token) override;
	INT32 _abi_remove_Closed(EventRegistrationToken token) override;
	INT32 _abi_add_InputEnabled(ITypedEventHandler<CoreWindow*, InputEnabledEventArgs*>* handler,
		EventRegistrationToken* token) override;
	INT32 _abi_remove_InputEnabled(EventRegistrationToken token) override;
	INT32 _abi_add_KeyDown(ITypedEventHandler<CoreWindow*, KeyEventArgs*>* handler,
		EventRegistrationToken* token) override;
	INT32 _abi_remove_KeyDown(EventRegistrationToken token) override;
	INT32 _abi_add_KeyUp(ITypedEventHandler<CoreWindow*, KeyEventArgs*>* handler,
		EventRegistrationToken* token) override;
	INT32 _abi_remove_KeyUp(EventRegistrationToken token) override;
	INT32 _abi_add_PointerMoved(ITypedEventHandler<CoreWindow*, PointerEventArgs*>* handler,
		EventRegistrationToken* token) override;
	INT32 _abi_remove_PointerMoved(EventRegistrationToken token) override;
	INT32 _abi_add_PointerEntered(ITypedEventHandler<CoreWindow*, PointerEventArgs*>* handler,
		EventRegistrationToken* token) override;
	INT32 _abi_remove_PointerEntered(EventRegistrationToken token) override;
	INT32 _abi_add_PointerExited(ITypedEventHandler<CoreWindow*, PointerEventArgs*>* handler,
		EventRegistrationToken* token) override;
	INT32 _abi_remove_PointerExited(EventRegistrationToken token) override;
	INT32 _abi_add_SizeChanged(ITypedEventHandler<CoreWindow*, WindowSizeChangedEventArgs*>* handler,
		EventRegistrationToken* token) override;
	INT32 _abi_remove_SizeChanged(EventRegistrationToken token) override;
	INT32 _abi_add_VisibilityChanged(ITypedEventHandler<CoreWindow*, VisibilityChangedEventArgs*>* handler,
		EventRegistrationToken* token) override;
	INT32 _abi_remove_VisibilityChanged(EventRegistrationToken token) override;
	HRESULT QueryInterface(const IID& riid, void** ppvObject) override;
	ULONG AddRef() override;
	ULONG Release() override;

private:
	Microsoft::WRL::ComPtr<ICoreWindow> m_coreWindow;
};