bool CallHook(const char* name){
		ILuaObject *hookT = gLua->GetGlobal("hook");
			ILuaObject *callM = hookT->GetMember("Call");
				gLua->Push(callM);

				gLua->Push("ProcessNetMsg");
				gLua->PushNil();
				gLua->PushNil();
			callM->UnReference();
		hookT->UnReference();

		gLua->Call(3, 1);

		ILuaObject *retL = gLua->GetReturn(0);

		bool bState = retL->isNil();

		retL->UnReference();

		return bState;
}