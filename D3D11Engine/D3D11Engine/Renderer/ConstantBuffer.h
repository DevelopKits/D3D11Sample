#pragma once
#include "HpD3D9Type.h"

class ConstantBuffer
{
public:
	ConstantBuffer(UINT StartSlot_);
	~ConstantBuffer();

	void Release();
	void SetSize(int size_);
	void* Map();
	void Apply();
private:
	/// Direct3D object.
	ID3D11Buffer* pConstantBuffer;
private:
	bool bMap;
	void* dataPtr;
	UINT StartSlot;
};
typedef std::shared_ptr<ConstantBuffer>ConstantBufferPtr;
